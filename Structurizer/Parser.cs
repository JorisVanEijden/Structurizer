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
    private const int SizeOfByte = 1;
    private const int SizeOfWord = 2;
    private const int SizeOfDWord = 4;
    private readonly Dictionary<string, EnumType> _enums = new();
    private readonly Dictionary<string, StructType> _structs = new();
    
    public Parser() : this(new Configuration()) {
    }
    
    public ParseResult ParseFile(string headerFilePath) {
        var result = new ParseResult();
        string text = File.ReadAllText(headerFilePath);
        text = PreProcess(text);
        
        File.WriteAllText("debug.h", text);
        
        try {
            ParseSource(text);
        } finally {
            // Write formatted enums and structs to file
            File.WriteAllText($"{headerFilePath}_enums.json", JsonSerializer.Serialize(_enums, new JsonSerializerOptions {
                WriteIndented = true
            }));
            File.WriteAllText($"{headerFilePath}_structs.json", JsonSerializer.Serialize(_structs, new JsonSerializerOptions {
                WriteIndented = true
            }));
        }
        
        result.Enums = _enums;
        result.Structs = _structs;
        
        return result;
    }
    
    private void ParseSource(string text) {
        ParseEnums(text);
        ParseStructs(text);
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
        string[]? memberParts = member.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        
        if (Regex.Match(memberParts[0], @"__attribute__\(\(aligned\((\d+)\)\)") is {Success: true} alignMatch) {
            memberParts = HandleAlignment(structType, alignMatch, memberParts);
        }
        
        if (memberParts[0] == "unsigned" || memberParts[0] == "signed") {
            memberParts = HandleSign(memberParts);
        }
        
        if (memberParts[0] == "struct" || memberParts[0] == "enum") {
            memberParts = memberParts[1..];
        }
        
        string memberType = memberParts[0].Trim();
        string memberName = memberParts[1].Trim();
        
        bool nearPointer = HandleNearPointer(memberParts, ref memberName);
        
        int memberSize = memberName.Contains('*')
            ? HandlePointer(nearPointer, ref memberType, ref memberName)
            : GetSizeOf(memberType);
        
        if (memberName.Contains('[')) {
            memberName = HandleArray(memberName, ref memberSize);
        }
        
        if (memberSize > maxSize) {
            maxSize = memberSize;
        }
        
        var variable = new Variable(memberName, memberType, memberSize);
        structType.Members.Add(variable);
        structType.Size += variable.Size;
        
        return maxSize;
    }
    
    private static string HandleArray(string memberName, ref int memberSize) {
        string[] arrayParts = memberName.Split('[', ']');
        memberName = arrayParts[0].Trim();
        memberSize *= (int)IntParse(arrayParts[1]);
        
        return memberName;
    }
    
    private int HandlePointer(bool nearPointer, ref string memberType, ref string memberName) {
        memberType += "*";
        memberName = memberName.Replace("*", "").Trim();
        int memberSize = nearPointer ? config.DefaultPointerSize / 2 : config.DefaultPointerSize;
        
        return memberSize;
    }
    
    private static bool HandleNearPointer(string[] memberParts, ref string memberName) {
        bool nearPointer;
        if (memberName == "near") {
            nearPointer = true;
            memberName = memberParts[2].Trim();
        } else {
            nearPointer = false;
        }
        
        return nearPointer;
    }
    
    private static string[] HandleSign(string[] memberParts) {
        string sign = memberParts[0].Trim();
        memberParts = memberParts[1..];
        memberParts[0] = $"{sign} {memberParts[0]}";
        
        return memberParts;
    }
    
    private static string[] HandleAlignment(StructType structType, Match alignMatch, string[] memberParts) {
        var alignment = int.Parse(alignMatch.Groups[1].Value);
        // Increase the size of the previous variable to align this one with the specified number of bytes
        structType.Members[^1].Size += structType.Size % alignment;
        memberParts = memberParts[1..];
        
        return memberParts;
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
        type = type.Replace("unsigned", "")
            .Replace("signed", "")
            .Trim();
        
        return type switch {
            "char" => SizeOfByte,
            "_BYTE" => SizeOfByte,
            "__int8" => SizeOfByte,
            "int" => SizeOfWord,
            "__int16" => SizeOfWord,
            "__int32" => SizeOfDWord,
            "size_t" => config.DefaultSizeT,
            _ => GetDynamicSizeOf(type)
        };
    }
    
    private int GetDynamicSizeOf(string type) {
        if (_enums.TryGetValue(type, out EnumType? enumType)) {
            return enumType.MemberSize;
        }
        
        if (_structs.TryGetValue(type, out StructType? structType)) {
            return structType.Size;
        }
        
        throw new Exception($"Could not determine size of type '{type}'");
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