namespace Structurizer.Types;

using System.Collections.Generic;

public class EnumType(string name) {
    public string Name { get; set; } = name;
    public int MemberSize { get; set; }
    public Dictionary<long, string> Members { get; set; } = new();
}