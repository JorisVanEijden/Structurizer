namespace Structurizer.Types;

using System.Text.Json.Serialization;

public record struct TypeDefinition(string Name, string Type) {
    public TypeDefinition(string name, string type, int size) : this(name, type) {
        Size = size;
    }

    public int Size { get; set; }
    public int Count { get; set; } = 1;
    public bool IsPointer { get; set; }
    public bool IsNear { get; set; }
    public int Alignment { get; set; }
    public bool Unsigned { get; set; }
    public EnumType? EnumType { get; set; }

    public bool IsArray {
        get => Count > 1;
    }

    [JsonIgnore]
    public int Length {
        get => Size * Count;
    }
}