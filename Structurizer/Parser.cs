namespace Structurizer;

using Structurizer.Types;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

public class Parser(StructurizerSettings config) {
    private readonly Dictionary<string, EnumType> _enums = new();
    private readonly Dictionary<string, StructType> _structs = new();
    private Dictionary<string, TypeDefinition> _typeDefs = config.TypeDefs;

    public StructureInformation ParseFile(string headerFilePath) {
        string text = File.ReadAllText(headerFilePath);

        return ParseSource(text);
    }

    public void Clear() {
        _typeDefs = config.TypeDefs;
        _enums.Clear();
        _structs.Clear();
    }

    public StructureInformation ParseSource(string text) {
        Clear();
        // Preprocess the text to make it more suitable for regex matching
        text = PreProcess(text);
        // TypeDefs need to be parsed first, so we can determine the size of other types
        ParseTypeDefs(text);
        // Enums need to be parsed before structs, as they can be used as member types
        ParseEnums(text);
        // Structs need to be parsed last, as they can contain members of other types
        ParseStructs(text);

        return new StructureInformation {
            Enums = _enums,
            Structs = _structs,
            TypeDefs = _typeDefs
        };
    }

    private bool TryParseTypeDef(Match match, out TypeDefinition variable) {
        try {
            variable = ParseMember(match.Groups[1].Value.Trim());

            return true;
        } catch (ArgumentException) {
            variable = default;

            return false;
        }
    }

    private void ParseTypeDefs(string text) {
        const string typedefPattern = @"typedef\s+(.+);";
        MatchCollection matches = Regex.Matches(text, typedefPattern);

        foreach (Match match in matches) {
            if (TryParseTypeDef(match, out TypeDefinition variable)) {
                _typeDefs[variable.Name] = variable;
            }
        }
    }

    private void ParseStructs(string text) {
        const string structPattern = @"(struct|union)(?:\s+__[^\s]+)*\s+(\w+)\s*{([^}]*)}";
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
            TypeDefinition typeDefinition = ParseMember(member);
            // Keep track of the biggest member to set the size of a union
            if (typeDefinition.Size > maxSize) {
                maxSize = typeDefinition.Size;
            }
            if (typeDefinition.Alignment > 1) {
                // calculate the delta between the current size and the desired alignment
                int delta = typeDefinition.Alignment - structType.Size % typeDefinition.Alignment;
                // Insert a padding member of the required size
                structType.Members.Add(new TypeDefinition("", "") {
                    Size = 1,
                    Count = delta
                });
            }
            structType.Members.Add(typeDefinition);
        }
        _structs[structName] = structType;
    }

    private TypeDefinition ParseMember(string member) {
        var isPointer = false;
        var isNear = false;
        var memberCount = 1;
        var alignment = 1;
        var unsigned = false;

        member = StripIdaDataRepresentationAttributes(member);
        
        int lastSpace = member.LastIndexOf(' ');
        if (lastSpace == -1) {
            throw new Exception($"Could not parse member '{member}'");
        }

        string fullType = member[..lastSpace].Trim();
        string memberName = member[(lastSpace + 1)..].Trim();

        // Handle pointers
        if (memberName.Contains('*')) {
            isPointer = true;
            // Move the pointer symbol to the type
            memberName = memberName.Replace("*", string.Empty);
            fullType += "*";
        }

        // Handle array
        if (Regex.Match(memberName, @"\[(\d*)\]") is {Success: true} arrayMatch) {
            int.TryParse(arrayMatch.Groups[1].Value, out memberCount);
            memberName = Regex.Replace(memberName, @"\[\d*\]", string.Empty);
        }

        // Loop through the type parts to handle special cases
        string[]? typeParts = fullType.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        for (var index = 0; index < typeParts.Length; index++) {
            string typePart = typeParts[index];
            // Handle aligned attribute
            if (Regex.Match(typePart, @"__attribute__\(\(aligned\((\d+)\)\)") is {Success: true} alignMatch) {
                alignment = int.Parse(alignMatch.Groups[1].Value);
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
                // Note: This needs more testing with Ghidra. What is the difference between a far pointer and an array of 2 near pointers?    
                isPointer = true;
                isNear = false;
            } else if (Regex.Match(typePart, @"pointer(\d+)") is {Success: true} pointerMatch) {
                // array of near pointers? See pointer112 in ghidra.h
                isPointer = true;
                isNear = true;
                var bitCount = int.Parse(pointerMatch.Groups[1].Value);
                memberCount = bitCount / 16;
            } else if (typePart == "unsigned") {
                // Remove the unsigned keyword from the type
                typeParts[index] = string.Empty;
                unsigned = true;
            }
        }
        string memberType = string.Join(" ", typeParts).Trim();

        int memberSize = isPointer ? isNear ? SizeInBytes.Of16Bits : SizeInBytes.Of32Bits : GetSizeOf(memberType);

        var typeDefinition = new TypeDefinition(memberName, memberType) {
            Size = memberSize,
            Count = memberCount,
            IsPointer = isPointer,
            IsNear = isNear,
            Alignment = alignment,
            Unsigned = unsigned
        };

        return typeDefinition;
    }

    private string StripIdaDataRepresentationAttributes(string member) {
        if (string.IsNullOrEmpty(member))
            return member;

        // Define patterns to match IDA data representation attributes
        string[] simpleAttributes = {
            "__bin", "__oct", "__hex", "__dec", "__sbin", "__soct", "__shex", "__udec", "__float", "__char", "__segm", "__invsign", "__invbits", "__lzero"
        };

        // Attributes with parentheses that can contain anything
        string[] attributesWithParentheses = {
            "__enum", "__off", "__offset", "__strlit", "__custom", "__tabform"
        };

        // Split the member string by spaces
        string[] parts = member.Split(' ');
        var filteredParts = new List<string>();

        foreach (string part in parts) {
            var shouldKeep = true;

            // Check for simple attributes
            foreach (string attr in simpleAttributes) {
                if (part.Equals(attr, StringComparison.OrdinalIgnoreCase)) {
                    shouldKeep = false;

                    break;
                }
            }

            // Check for attributes with parentheses
            if (shouldKeep) {
                foreach (string attr in attributesWithParentheses) {
                    var pattern = $@"{attr}\(.*?\)";
                    if (Regex.IsMatch(part, pattern, RegexOptions.IgnoreCase)) {
                        shouldKeep = false;

                        break;
                    }
                }
            }

            if (shouldKeep) {
                filteredParts.Add(part);
            }
        }

        return string.Join(" ", filteredParts);
    }

    private void ParseEnums(string text) {
        const string enumPattern = @"enum\s+(?:__\w+ )*\$?(\w+)\s*:?\s*([^{;]*)?\s*{([^}]*)}";
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

        var enumType = new EnumType {
            MemberSize = GetSizeOf(backingType)
        };

        string[]? members = enumMembers.Split(',', StringSplitOptions.RemoveEmptyEntries);

        for (var i = 0; i < members.Length; i++) {
            ParseEnumMember(members, i, enumType);
        }

        _enums[enumName] = enumType;
    }

    private static void ParseEnumMember(string[] members, int i, EnumType enumType) {
        string member = members[i].Trim();
        if (string.IsNullOrWhiteSpace(member)) {
            return;
        }
        string memberName = member;

        string[]? memberParts = member.Split('=');
        long memberValue;
        if (memberParts.Length == 2) {
            memberName = memberParts[0].Trim();
            memberValue = IntParse(memberParts[1].Trim());
        } else {
            memberValue = i;
        }
        // Add the member to the enum
        bool unique = enumType.Members.TryAdd(memberValue, memberName);
        if (!unique) {
            // group members with the same value together
            enumType.Members[memberValue] += $", {memberName}";
        }
    }

    private int GetSizeOf(string type) {
        var multiplier = 1;
        type = type.Replace("unsigned", string.Empty).Replace("signed", "").Trim();
        if (type.StartsWith("long ")) {
            type = type[(type.LastIndexOf(" ", StringComparison.Ordinal) + 1)..];
            multiplier = 2;
        }

        int size = GetDynamicSizeOf(type);

        return size * multiplier;
    }

    private int GetDynamicSizeOf(string type) {
        if (_typeDefs.TryGetValue(type, out TypeDefinition variable)) {
            return variable.Size;
        }

        if (_enums.TryGetValue(type, out EnumType? enumType)) {
            return enumType.MemberSize;
        }

        if (_structs.TryGetValue(type, out StructType? structType)) {
            return structType.Size;
        }

        throw new ArgumentException($"Could not determine size of type '{type}'", nameof(type));
    }

    private static long IntParse(string input) {
        if (string.IsNullOrWhiteSpace(input)) {
            return 0;
        }
        input = input.TrimEnd('u'); // unsigned
        int sign = input.StartsWith('-') ? -1 : 1;
        input = input.TrimStart('-');
        long result;
        try {
            if (input.StartsWith("0x")) {
                result = long.Parse(input[2..], NumberStyles.HexNumber);
            } else if (input.StartsWith("0b")) {
                result = Convert.ToInt64(input[2..], 2);
            } else {
                result = long.Parse(input);
            }
        } catch (Exception e) {
            throw new ArgumentException($"Could not parse int from '{input}'", e);
        }

        return result * sign;
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