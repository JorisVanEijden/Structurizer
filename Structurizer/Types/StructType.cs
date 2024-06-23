namespace Structurizer.Types;

using System.Collections.Generic;
using System.Linq;

public class StructType(string name) {
    public string Name { get; } = name;

    public int Size {
        get => IsUnion ? Members.Max(typeDefinition => typeDefinition.Length) : Members.Sum(typeDefinition => typeDefinition.Length);
    }

    public List<TypeDefinition> Members { get; set; } = [];
    public bool IsUnion { get; set; }
}