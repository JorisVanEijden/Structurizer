namespace Structurizer;

using Structurizer.Types;
using System;
using System.Collections.Generic;
using System.Linq;

public class Hydrator {
    protected readonly Dictionary<string, EnumType>? Enums;
    protected readonly Dictionary<string, StructType>? Structs;
    protected readonly Dictionary<string, TypeDefinition>? TypeDefs;

    public Hydrator(StructurizerSettings config, StructureInformation? parseResult = null) {
        Structs = parseResult?.Structs;
        Enums = parseResult?.Enums;
        TypeDefs = parseResult?.TypeDefs.Any() is true ? parseResult.TypeDefs : config.TypeDefs;
    }

    public virtual Variable Hydrate(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        if (typeDefinition.IsArray && typeDefinition.Type != "char") {
            return HydrateArray(typeDefinition, bytes);
        }

        if (Structs != null && Structs.TryGetValue(typeDefinition.Type, out StructType? structType)) {
            return HydrateStruct(typeDefinition, structType, bytes);
        }

        if (Enums != null && Enums.TryGetValue(typeDefinition.Type, out EnumType? enumType)) {
            return HydrateEnum(typeDefinition, enumType, bytes);
        }

        return HydrateType(typeDefinition, bytes);
    }

    protected virtual ArrayMember HydrateArray(TypeDefinition typeDefinition, ReadOnlySpan<byte> data) {
        var singleVariable = new TypeDefinition(typeDefinition.Name, typeDefinition.Type, typeDefinition.Size) {
            Count = 1,
            IsPointer = typeDefinition.IsPointer,
            IsNear = typeDefinition.IsNear,
            Alignment = typeDefinition.Alignment
        };

        int numberOfItems = data.Length / singleVariable.Size;
        var items = new List<Variable>(numberOfItems);

        for (var index = 0; index < typeDefinition.Length; index += singleVariable.Size) {
            byte[]? slice = data.Slice(index, singleVariable.Size).ToArray();
            var item = Hydrate(singleVariable, slice);
            items.Add(item);
        }

        return new ArrayMember(typeDefinition, data, items);
    }

    protected virtual Variable HydrateType(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        switch (typeDefinition.Type) {
            case "short" or "int":
                return new ShortMember(typeDefinition, bytes);
            case "unsigned short" or "unsigned int":
                return new UnsignedShortMember(typeDefinition, bytes);
            case "long":
                return new LongMember(typeDefinition, bytes);
            case "unsigned long":
                return new UnsignedLongMember(typeDefinition, bytes);
        }
        switch (typeDefinition) {
            case {Type: "char", IsArray: true}:
                return new StringMember(typeDefinition, bytes);
            case {Type: "char", IsArray: false}:
                return new CharMember(typeDefinition, bytes);
        }

        if (TypeDefs != null && TypeDefs.TryGetValue(typeDefinition.Type, out TypeDefinition? knownTypeDef)) {
            return Hydrate(knownTypeDef, bytes);
        }

        if (typeDefinition.IsPointer) {
            return new PointerMember(typeDefinition, bytes);
        }

        throw new NotSupportedException($"Type {typeDefinition.Type} not supported");
    }

    protected virtual EnumMember HydrateEnum(TypeDefinition typeDefinition, EnumType enumType, ReadOnlySpan<byte> bytes) {
        uint value = enumType.MemberSize switch {
            1 => bytes[0],
            2 => BitConverter.ToUInt16(bytes),
            4 => BitConverter.ToUInt32(bytes),
            _ => throw new NotSupportedException($"Enum member size {enumType.MemberSize} not supported")
        };

        if (enumType.Members.TryGetValue(value, out string name)) {
            return new EnumMember(typeDefinition, bytes, enumType, name);
        }

        throw new ArgumentOutOfRangeException(nameof(bytes), $"Enum value {value} not found in enum");
    }

    public virtual StructMember HydrateStruct(TypeDefinition typeDefinition, StructType structType, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < structType.Size) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the struct");
        }

        var members = new List<Variable>();

        ReadOnlySpan<byte> structBytes = bytes[..structType.Size];
        var index = 0;
        foreach (TypeDefinition? member in structType.Members) {
            ReadOnlySpan<byte> memberBytes = structBytes.Slice(index, member.Length);
            var memberValue = Hydrate(member, memberBytes);
            members.Add(memberValue);
            index += member.Length;
        }

        return new StructMember(typeDefinition, bytes, structType, members);
    }
}