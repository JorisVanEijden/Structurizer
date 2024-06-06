namespace Structurizer.Types;

using System.Collections.Generic;

public class EnumType {
    public int MemberSize { get; set; }
    public Dictionary<long, string> Members { get; } = new();
}