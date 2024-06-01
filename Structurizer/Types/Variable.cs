namespace Structurizer.Types;

using System.Text.Json.Serialization;

public class Variable(string name, string type, int size, int count = 1) {
    public string Name { get; set; } = name;
    public string Type { get; set; } = type;
    public int Size { get; set; } = size;
    public int Count { get; set; } = count;
    
    [JsonIgnore]
    public int Length {
        get => Size * Count;
    }
}