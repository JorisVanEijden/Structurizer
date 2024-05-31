namespace Structurizer.Types;

using System.Collections.Generic;

public class ParseResult {
    public Dictionary<string, EnumType> Enums { get; set; } = new();
    public Dictionary<string, StructType> Structs { get; set; } = new();
}