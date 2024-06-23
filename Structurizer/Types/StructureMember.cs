namespace Structurizer.Types;

using System.Collections.Generic;

public class StructureMember {
    public StructureMember(string name, TypeDefinition type, byte[] data) {
        Name = name;
        Type = type;
        Data = data;
    }

    public List<StructureMember>? Members { get; set; }
    public string Name { get; }
    public TypeDefinition Type { get; }

    public byte[] Data { get; set; }

    public int Size {
        get => Data.Length;
    }
}