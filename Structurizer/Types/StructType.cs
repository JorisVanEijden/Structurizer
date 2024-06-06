namespace Structurizer.Types;

using System.Collections.Generic;
using System.Linq;

public class StructType(string name) {
    public string Name { get; } = name;
    
    public int Size {
        get => IsUnion ? Members.Max(m => m.Length) : Members.Sum(m => m.Length);
    }
    
    public List<Variable> Members { get; set; } = [];
    public bool IsUnion { get; set; }
}