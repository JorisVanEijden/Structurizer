namespace Structurizer.Types;

public class Variable(string name, string type, int size) {
    public string Name { get; set; } = name;
    
    public string Type { get; set; } = type;
    
    public int Size { get; set; } = size;
}