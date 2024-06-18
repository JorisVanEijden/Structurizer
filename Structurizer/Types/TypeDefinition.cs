namespace Structurizer.Types;

using System.Text.Json.Serialization;

public class TypeDefinition(string name, string type) {
    public TypeDefinition(string name, string type, int size) : this(name, type) {
        Size = size;
    }
    
    public string Name { get; } = name;
    public string Type { get; } = type;
    public int Size { get; set; }
    public int Count { get; set; } = 1;
    public bool IsPointer { get; set; }
    public bool IsNear { get; set; }
    public int Alignment { get; set; }
    public bool IsArray {
        get => Count > 1;
    }
    
    [JsonIgnore]
    public int Length {
        get => Size * Count;
    }
}