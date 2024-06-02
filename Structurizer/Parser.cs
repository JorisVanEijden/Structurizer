namespace Structurizer;

using Structurizer.Types;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Text.RegularExpressions;

public class Parser(Configuration config) {
    private const int SizeOf8Bits = 1;
    private const int SizeOf16Bits = 2;
    private const int SizeOf32Bits = 4;
    private const int SizeOf64Bits = 8;
    private readonly Dictionary<string, EnumType> _enums = new();
    private readonly Dictionary<string, StructType> _structs = new();
    
    private readonly Dictionary<string, Variable> _typeDefs = new() {
        ["__int8"] = new Variable("__int8", "__int8", SizeOf8Bits),
        ["__int16"] = new Variable("__int16", "__int16", SizeOf16Bits),
        ["__int32"] = new Variable("__int32", "__int32", SizeOf32Bits),
        ["__int64"] = new Variable("__int64", "__int64", SizeOf64Bits),
        ["char"] = new Variable("char", "char", SizeOf8Bits),
        ["short"] = new Variable("short", "short", SizeOf16Bits),
        ["int"] = new Variable("int", "int", SizeOf16Bits),
        ["long"] = new Variable("long", "long", SizeOf32Bits),
        ["_BYTE"] = new Variable("unsigned char", "unsigned char", SizeOf8Bits),
        ["size_t"] = new Variable("size_t", "size_t", config.DefaultSizeT),
        ["pointer"] = new Variable("pointer", "pointer", SizeOf16Bits) {
            IsPointer = true,
            IsNear = true
        }
    };
    
    public ParseResult ParseFile(string headerFilePath) {
        string text = File.ReadAllText(headerFilePath);
        
        File.WriteAllText("debug.h", text);
        
        try {
            ParseResult result = ParseSource(text);
            
            return result;
        } finally {
            // Write formatted enums and structs to file
            File.WriteAllText($"{headerFilePath}_enums.json", JsonSerializer.Serialize(_enums, new JsonSerializerOptions {
                WriteIndented = true
            }));
            File.WriteAllText($"{headerFilePath}_structs.json", JsonSerializer.Serialize(_structs, new JsonSerializerOptions {
                WriteIndented = true
            }));
        }
    }
    
    public ParseResult ParseSource(string text) {
        text = PreProcess(text);
        ParseTypeDefs(text);
        ParseEnums(text);
        ParseStructs(text);
        
        return new ParseResult {
            Enums = _enums,
            Structs = _structs,
            TypeDefs = _typeDefs
        };
    }
    
    private void ParseTypeDefs(string text) {
        const string typedefPattern = @"typedef(\s+(\w+))+;";
        MatchCollection matches = Regex.Matches(text, typedefPattern);
        
        foreach (Match match in matches) {
            ParseTypeDef(match);
        }
    }
    
    private void ParseTypeDef(Match match) {
        string[] memberParts = match.Groups[2].Captures.Select(capture => capture.Value).ToArray();
        var memberSize = 0;
        if (memberParts.Length > 2) {
            switch (memberParts[0]) {
                case "long":
                    memberParts = [$"{memberParts[0]} {memberParts[1]}", memberParts[2]];
                    memberSize = GetSizeOf(memberParts[0]);
                    
                    break;
                case "unsigned":
                case "signed":
                    memberSize = GetSizeOf(memberParts[1]);
                    string sign = memberParts[0].Trim();
                    memberParts = memberParts[1..];
                    memberParts[0] = $"{sign} {memberParts[0]}";
                    
                    break;
                case "struct":
                    // Skip structs for now
                    return;
                
                default:
                    memberSize = GetSizeOf(memberParts[1]);
                    
                    break;
            }
        }
        string memberType = memberParts[0].Trim();
        string memberName = memberParts[1].Trim();
        var variable = new Variable(memberName, memberType, memberSize);
        _typeDefs[memberName] = variable;
    }
    
    private void ParseStructs(string text) {
        const string structPattern = @"(struct|union)(?:\s*__attribute__[^\s]+)*\s+(\w+)\s*{([^}]*)}";
        MatchCollection matches = Regex.Matches(text, structPattern, RegexOptions.Multiline);
        
        foreach (Match match in matches) {
            ParseStruct(match);
        }
    }
    
    private void ParseStruct(Match match) {
        string type = match.Groups[1].Value;
        string structName = match.Groups[2].Value;
        string structMembers = match.Groups[3].Value;
        
        var structType = new StructType(structName) {
            IsUnion = type == "union"
        };
        
        var members = structMembers.Split(';', StringSplitOptions.RemoveEmptyEntries).Select(member => member.Trim()).ToList();
        
        var maxSize = 0;
        
        foreach (string? member in members) {
            if (string.IsNullOrWhiteSpace(member)) {
                continue;
            }
            maxSize = ProcessMember(member, structType, maxSize);
        }
        if (structType.IsUnion) {
            structType.Size = maxSize;
        }
        _structs[structName] = structType;
    }
    
    private int ProcessMember(string member, StructType structType, int maxSize) {
        int lastSpace = member.LastIndexOf(' ');
        if (lastSpace == -1) {
            throw new Exception($"Could not parse member '{member}'");
        }
        var isPointer = false;
        var isNear = false;
        var memberCount = 1;
        
        string fullType = member[..lastSpace].Trim();
        string memberName = member[(lastSpace + 1)..].Trim();
        if (memberName.Contains('*')) {
            isPointer = true;
            // Move the pointer symbol to the type
            memberName = memberName.Replace("*", "");
            fullType += "*";
        }
        // Handle array
        if (Regex.Match(memberName, @"\[(\d*)\]") is {Success: true} arrayMatch) {
            int.TryParse(arrayMatch.Groups[1].Value, out memberCount);
            memberName = Regex.Replace(memberName, @"\[\d*\]", string.Empty);
        }
        
        string[]? typeParts = fullType.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        for (var index = 0; index < typeParts.Length; index++) {
            string typePart = typeParts[index];
            // Handle aligned attribute
            if (Regex.Match(typePart, @"__attribute__\(\(aligned\((\d+)\)\)") is {Success: true} alignMatch) {
                var alignment = int.Parse(alignMatch.Groups[1].Value);
                // calculate the delta between the current size and the desired alignment
                int delta = alignment - structType.Size % alignment;
                // Insert a padding member of the required size
                structType.AddVariable(new Variable("", "", 1, delta));
                typeParts[index] = string.Empty;
            }
            // Remove superfluous struct, enum, union keywords
            else if (typePart is "struct" or "enum" or "union") {
                typeParts[index] = string.Empty;
            }
            // Check for near pointer
            else if (typePart == "near*") {
                // Remove the near pointer keyword from the type
                typeParts[index] = string.Empty;
                // Move the pointer symbol to the type pointed to
                typeParts[index - 1] += "*";
                isNear = true;
            }
            // Handle ghidra-style pointers
            else if (typePart == "pointer") {
                // Default to near pointer
                isPointer = true;
                isNear = true;
            } else if (typePart == "pointer32") {
                // far pointer?
                // TODO: This needs more testing with Ghidra. What is the difference between a far pointer and an array of 2 near pointers?    
                isPointer = true;
                isNear = false;
            } else if (Regex.Match(typePart, @"pointer(\d+)") is {Success: true} pointerMatch) {
                // array of near pointers? See pointer112 in ghidra.h
                isPointer = true;
                isNear = true;
                var bitCount = int.Parse(pointerMatch.Groups[1].Value);
                memberCount = bitCount / 16;
            }
        }
        string memberType = string.Join(" ", typeParts).Trim();
        
        int memberSize = isPointer ? isNear ? SizeOf16Bits : SizeOf32Bits : GetSizeOf(memberType);
        
        if (memberSize > maxSize) {
            maxSize = memberSize;
        }
        
        var variable = new Variable(memberName, memberType, memberSize) {
            Count = memberCount,
            IsPointer = isPointer,
            IsNear = isNear
        };
        structType.AddVariable(variable);
        
        return maxSize;
    }
    
    private void ParseEnums(string text) {
        const string enumPattern = @"enum\s+(\w+)\s*:?\s*([^{;]*)?\s*{([^}]*)}";
        MatchCollection matches = Regex.Matches(text, enumPattern, RegexOptions.Multiline);
        
        foreach (Match match in matches) {
            ParseEnum(match);
        }
    }
    
    private void ParseEnum(Match match) {
        string enumName = match.Groups[1].Value.Trim();
        string backingType = match.Groups[2].Value.Trim();
        if (string.IsNullOrWhiteSpace(backingType)) {
            backingType = config.DefaultEnumBackingType;
        }
        string enumMembers = match.Groups[3].Value;
        
        var enumType = new EnumType(enumName) {
            MemberSize = GetSizeOf(backingType)
        };
        
        string[]? members = enumMembers.Split(',', StringSplitOptions.RemoveEmptyEntries);
        
        for (var i = 0; i < members.Length; i++) {
            ParseEnumMember(members, i, enumType, enumName);
        }
        
        _enums[enumName] = enumType;
    }
    
    private static void ParseEnumMember(string[] members, int i, EnumType enumType, string enumName) {
        string member = members[i].Trim();
        if (string.IsNullOrWhiteSpace(member)) {
            return;
        }
        string memberName = member;
        long memberValue = i;
        try {
            string[]? memberParts = member.Split('=');
            if (memberParts.Length == 2) {
                memberName = memberParts[0].Trim();
                memberValue = IntParse(memberParts[1].Trim());
            }
            enumType.Members.TryAdd(memberValue, memberName);
        } catch (Exception e) {
            throw new Exception($"Could not parse enum member '{member}' in enum '{enumName}'", e);
        }
    }
    
    private int GetSizeOf(string type) {
        var multiplier = 1;
        type = type.Replace("unsigned", "")
            .Replace("signed", "")
            .Trim();
        if (type.StartsWith("long ")) {
            type = type[(type.LastIndexOf(" ", StringComparison.Ordinal) + 1)..];
            multiplier = 2;
        }
        
        int size = GetDynamicSizeOf(type);
        
        return size * multiplier;
    }
    
    private int GetDynamicSizeOf(string type) {
        if (_typeDefs.TryGetValue(type, out Variable? variable)) {
            return variable.Size;
        }
        
        if (_enums.TryGetValue(type, out EnumType? enumType)) {
            return enumType.MemberSize;
        }
        
        if (_structs.TryGetValue(type, out StructType? structType)) {
            return structType.Size;
        }
        
        if (type.StartsWith("pointer") && int.TryParse(type[7..], out int sizeInBits)) {
            return sizeInBits / 8;
        }
        
        throw new ArgumentException($"Could not determine size of type '{type}'", nameof(type));
    }
    
    private static long IntParse(string input) {
        if (string.IsNullOrWhiteSpace(input)) {
            return 0;
        }
        long result;
        try {
            result = input.StartsWith("0x")
                ? long.Parse(input[2..], NumberStyles.HexNumber)
                : long.Parse(input);
        } catch (Exception e) {
            throw new Exception($"Could not parse int from '{input}'", e);
        }
        
        return result;
    }
    
    private static string PreProcess(string text) {
        return StripComments(text);
    }
    
    private static string StripComments(string text) {
        // from https://stackoverflow.com/questions/36454069/how-to-remove-c-style-comments-from-code
        const string comments = """/(?:\/\/(?:\\\n|[^\n])*\n)|(?:\/\*[\s\S]*?\*\/)|((?:R"([^(\\\s]{0,16})\([^)]*\)\2")|(?:@"[^"]*?")|(?:"(?:\?\?'|\\\\|\\"|\\\n|[^"])*?")|(?:'(?:\\\\|\\'|\\\n|[^'])*?'))/g""";
        
        return Regex.Replace(text, comments, string.Empty, RegexOptions.Multiline);
    }
}