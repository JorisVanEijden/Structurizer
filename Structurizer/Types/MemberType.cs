namespace Structurizer.Types;

using System;
using System.Collections.Generic;
using System.Text;

public class StringMember : Variable {
    public StringMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
        StringValue = '"' + Encoding.ASCII.GetString(bytes) + '"';
    }

    public string StringValue { get; set; }
}

public abstract class NumberMember : Variable {
    protected NumberMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public abstract string Text {
        get;
    }
}

public class ShortMember : NumberMember {
    public ShortMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public short Value {
        get => BitConverter.ToInt16(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X4}]";
    }
}

public class UnsignedShortMember : NumberMember {
    public UnsignedShortMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public ushort Value {
        get => BitConverter.ToUInt16(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X4}]";
    }
}

public class IntMember : NumberMember {
    public IntMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public int Value {
        get => BitConverter.ToInt16(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X4}]";
    }
}

public class UnsignedIntMember : NumberMember {
    public UnsignedIntMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public uint Value {
        get => BitConverter.ToUInt16(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X4}]";
    }
}

public class LongMember : NumberMember {
    public LongMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public int Value {
        get => BitConverter.ToInt32(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X8}]";
    }
}

public class UnsignedLongMember : NumberMember {
    public UnsignedLongMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public uint Value {
        get => BitConverter.ToUInt32(Bytes);
    }

    public override string Text {
        get => $"{Value} [0x{Value:X8}]";
    }
}

public class CharMember : NumberMember {
    public CharMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
    }

    public byte Value {
        get => Bytes[0];
    }

    public override string Text {
        get => $"{Value} [0x{Value:X2}] ['{(char)Value}']";
    }
}

public class PointerMember : Variable {
    public PointerMember(TypeDefinition type, ReadOnlySpan<byte> bytes) : base(type, bytes) {
        IsNear = type.IsNear;
        TargetType = type.Type;
        if (IsNear && bytes.Length == 2) {
            TargetSegment = null;
            TargetOffset = BitConverter.ToUInt16(bytes);
        } else if (bytes.Length == 4) {
            TargetSegment = BitConverter.ToUInt16(bytes[..2]);
            TargetOffset = BitConverter.ToUInt16(bytes[2..]);
        } else {
            throw new ArgumentException($"Invalid pointer size: {bytes.Length * 8}");
        }
    }

    public string TargetType { get; set; }
    public ushort? TargetSegment { get; set; }
    public ushort TargetOffset { get; set; }
    public bool IsNear { get; set; }
}

public class EnumMember : Variable {
    public EnumMember(TypeDefinition type, ReadOnlySpan<byte> bytes, EnumType enumType, string value) : base(type, bytes) {
        EnumType = enumType;
        Value = '"' + value + '"';
    }

    public EnumType EnumType { get; set; }
    public string Value { get; set; }
}

public class StructMember : Variable {
    public StructMember(TypeDefinition type, ReadOnlySpan<byte> bytes, StructType structType, List<Variable> members) : base(type, bytes) {
        StructType = structType;
        Members = members;
    }

    public StructType StructType { get; set; }
    public List<Variable> Members { get; set; }
}

public class ArrayMember : Variable {
    public ArrayMember(TypeDefinition type, ReadOnlySpan<byte> bytes, IEnumerable<Variable> members) : base(type, bytes) {
        Members = members;
    }

    public IEnumerable<Variable> Members { get; set; }
}

public abstract class Variable {
    protected Variable(TypeDefinition type, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < type.Length) {
            throw new ArgumentException($"Not enough bytes for type {type.Type}: {bytes.Length} < {type.Length}");
        }
        Type = type;
        Bytes = bytes[..type.Length].ToArray();
    }

    public string Name {
        get => Type.Name;
    }

    public TypeDefinition Type { get; set; }
    public byte[] Bytes { get; set; }
}