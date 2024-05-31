namespace Structurizer.Types;

using System.Collections.Generic;

public class StructType(string name) {
    public string Name { get; set; } = name;
    public int Size { get; set; }
    public List<Variable> Members { get; set; } = [];
    public bool IsUnion { get; set; }
}