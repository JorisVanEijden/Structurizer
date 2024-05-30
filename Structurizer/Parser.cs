namespace Structurizer {
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text.Json;
    using System.Text.RegularExpressions;

    public class Parser {
        private readonly Configuration _config;

        // enum definitions
        private readonly Dictionary<string, EnumType> _enums = new Dictionary<string, EnumType>();
        private readonly Dictionary<string, StructType> _structs = new Dictionary<string, StructType>();
        private readonly Dictionary<string, StructType> _unions = new Dictionary<string, StructType>();

        public Parser() : this(new Configuration()) {
        }

        public Parser(Configuration config) {
            _config = config;
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
            // ParseTypeDefs(text);
            ParseEnums(text);
            ParseStructs(text);
        }

        private void ParseTypeDefs(string text) {
            var typedefPattern = @"typedef\s+(?:struct|enum)\s+[^{;]+";
            MatchCollection matches = Regex.Matches(text, typedefPattern, RegexOptions.Multiline);

            foreach (Match match in matches) {
                string typedef = match.Value;
                string[]? typedefParts = typedef.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                if (typedefParts.Length < 3) {
                    throw new Exception($"Could not parse typedef '{typedef}'");
                }

                string? type = typedefParts[1];
                string? name = typedefParts[2];

                if (_enums.ContainsKey(name) || _structs.ContainsKey(name)) {
                    throw new Exception($"Type '{name}' already exists");
                }

                if (_enums.TryGetValue(type, out EnumType? enumType)) {
                    _enums[name] = enumType;
                } else if (_structs.TryGetValue(type, out StructType? structType)) {
                    _structs[name] = structType;
                } else {
                    throw new Exception($"Could not find type '{type}' for typedef '{typedef}'");
                }
            }
        }

        private void ParseStructs(string text) {
            var structPattern = @"(struct|union)(?:\s*__attribute__[^\s]+)*\s+(\w+)\s*{([^}]*)}";
            MatchCollection matches = Regex.Matches(text, structPattern, RegexOptions.Multiline);

            foreach (Match match in matches) {
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
                    string[]? memberParts = member.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    if (memberParts.Length < 2 || memberParts.Length > 3) {
                        throw new Exception($"Could not parse struct member '{member}' in struct '{structName}'");
                    }
                    if (Regex.Match(memberParts[0], @"__attribute__\(\(aligned\((\d+)\)\)") is {Success: true} alignMatch) {
                        var alignment = int.Parse(alignMatch.Groups[1].Value);
                        // Increase the size of the previous variable to align this one with the specified number of bytes
                        structType.Members[^1].Size += structType.Size % alignment;
                        memberParts = memberParts[1..];
                    }
                    if (memberParts[0] == "unsigned" || memberParts[0] == "signed") {
                        string sign = memberParts[0].Trim();
                        memberParts = memberParts[1..];
                        memberParts[0] = $"{sign} {memberParts[0]}";
                    }
                    if (memberParts[0] == "struct" || memberParts[0] == "enum") {
                        memberParts = memberParts[1..];
                    }
                    string memberType = memberParts[0].Trim();
                    string memberName = memberParts[1].Trim();

                    bool nearPointer;
                    if (memberName == "near") {
                        nearPointer = true;
                        memberName = memberParts[2].Trim();
                    } else {
                        nearPointer = false;
                    }

                    var memberSize = 0;
                    if (memberName.Contains('*')) {
                        memberType += "*";
                        memberName = memberName.Replace("*", "").Trim();
                        memberSize = nearPointer ? _config.DefaultPointerSize / 2 : _config.DefaultPointerSize;
                    } else {
                        memberSize = GetSizeOf(memberType);
                    }
                    if (memberName.Contains('[')) {
                        string[] arrayParts = memberName.Split('[', ']');
                        memberName = arrayParts[0].Trim();
                        memberSize *= (int)IntParse(arrayParts[1]);
                    }

                    if (memberSize > maxSize) {
                        maxSize = memberSize;
                    }

                    var variable = new Variable(memberName, memberType, memberSize);
                    structType.Members.Add(variable);
                    structType.Size += variable.Size;
                }
                if (structType.IsUnion) {
                    structType.Size = maxSize;
                }
                _structs[structName] = structType;
            }
        }

        private void ParseEnums(string text) {
            var enumPattern = @"enum\s+(\w+)\s*:?\s*([^{;]*)?\s*{([^}]*)}";
            MatchCollection matches = Regex.Matches(text, enumPattern, RegexOptions.Multiline);

            foreach (Match match in matches) {
                string enumName = match.Groups[1].Value.Trim();
                string backingType = match.Groups[2].Value.Trim();
                if (string.IsNullOrWhiteSpace(backingType)) {
                    backingType = _config.DefaultEnumBackingType;
                }
                string enumMembers = match.Groups[3].Value;

                var enumType = new EnumType(enumName) {
                    MemberSize = GetSizeOf(backingType)
                };

                string[]? members = enumMembers.Split(',', StringSplitOptions.RemoveEmptyEntries);

                for (var i = 0; i < members.Length; i++) {
                    string member = members[i].Trim();
                    if (string.IsNullOrWhiteSpace(member)) {
                        continue;
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

                _enums[enumName] = enumType;
            }
        }

        public int GetSizeOf(string type) {
            type = type.Replace("unsigned", "")
                .Replace("signed", "")
                .Trim();

            return type switch {
                "char" => 1,
                "_BYTE" => 1,
                "__int8" => 1,
                "int" => 2,
                "__int16" => 2,
                "__int32" => 4,
                "size_t" => _config.DefaultSizeT,
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

        private string PreProcess(string text) {
            return StripComments(text);
        }

        public string StripComments(string text) {
            // from https://stackoverflow.com/questions/36454069/how-to-remove-c-style-comments-from-code
            const string comments = @"/(?:\/\/(?:\\\n|[^\n])*\n)|(?:\/\*[\s\S]*?\*\/)|((?:R""([^(\\\s]{0,16})\([^)]*\)\2"")|(?:@""[^""]*?"")|(?:""(?:\?\?'|\\\\|\\""|\\\n|[^""])*?"")|(?:'(?:\\\\|\\'|\\\n|[^'])*?'))/g";

            return Regex.Replace(text, comments, string.Empty, RegexOptions.Multiline);
        }
    }

    internal class UnionType {
    }

    public class Configuration {
        public string DefaultEnumBackingType { get; set; } = "__int16";
        public int DefaultPointerSize { get; set; } = 4;
        public int DefaultSizeT { get; set; } = 2;
    }

    public class ParseResult {
        public Dictionary<string, EnumType> Enums { get; set; } = new Dictionary<string, EnumType>();
        public Dictionary<string, StructType> Structs { get; set; } = new Dictionary<string, StructType>();
    }

    public class StructType {
        public StructType(string name) {
            Name = name;
        }

        public string Name { get; set; }
        public int Size { get; set; }
        public List<Variable> Members { get; set; } = new List<Variable>();
        public bool IsUnion { get; set; }
    }

    public class Variable {
        public Variable(string name, string type, int size) {
            Name = name;
            Type = type;
            Size = size;
        }

        public string Name { get; set; }

        public string Type {
            get;
            set;
        }

        public int Size { get; set; }
    }

    public class EnumType {
        public EnumType(string name) {
            Name = name;
        }

        public string Name { get; set; }
        public int MemberSize { get; set; }
        public Dictionary<long, string> Members { get; set; } = new Dictionary<long, string>();
    }
}