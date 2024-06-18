namespace Structurizer.Types;

using System.Collections.Generic;

public class StructureInformation {
    public Dictionary<string, EnumType> Enums { get; set; } = new();
    public Dictionary<string, StructType> Structs { get; set; } = new();
    public Dictionary<string, TypeDefinition> TypeDefs { get; set; } = new();
}