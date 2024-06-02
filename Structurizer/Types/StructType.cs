namespace Structurizer.Types;

using System.Collections.Generic;

public class StructType(string name) {
    public string Name { get; } = name;
    public int Size { get; set; }
    public List<Variable> Members { get; } = [];
    public bool IsUnion { get; set; }
    
    public void AddVariable(Variable variable) {
        Members.Add(variable);
        Size += variable.Length;
    }
}