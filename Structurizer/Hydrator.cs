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

    public StructureMember Hydrate(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        if (typeDefinition.IsArray) {
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

    protected virtual StructureMember HydrateArray(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < typeDefinition.Length) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the array");
        }
        var result = new StructureMember(typeDefinition.Name, typeDefinition, bytes.ToArray()) {
            Members = new List<StructureMember>()
        };
        TypeDefinition singleVariable = typeDefinition with {
            Count = 1
        };

        for (var index = 0; index < typeDefinition.Length; index += singleVariable.Size) {
            ReadOnlySpan<byte> slice = bytes.Slice(index, singleVariable.Size);
            StructureMember member = Hydrate(singleVariable, slice);
            result.Members.Add(member);
        }

        return result;
    }

    protected virtual StructureMember HydrateType(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < typeDefinition.Length) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the type");
        }

        return new StructureMember(typeDefinition.Name, typeDefinition, bytes.ToArray());
    }

    protected virtual StructureMember HydrateEnum(TypeDefinition typeDefinition, EnumType enumType, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < enumType.MemberSize) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the enum");
        }
        TypeDefinition type = typeDefinition with {
            EnumType = enumType
        };

        return new StructureMember(typeDefinition.Name, type, bytes.ToArray());
    }

    protected virtual StructureMember HydrateStruct(TypeDefinition typeDefinition, StructType structType, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < structType.Size) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the struct");
        }

        var result = new StructureMember(typeDefinition.Name, typeDefinition, bytes.ToArray()) {
            Members = []
        };

        ReadOnlySpan<byte> structBytes = bytes[..structType.Size];
        var index = 0;
        foreach (TypeDefinition member in structType.Members) {
            ReadOnlySpan<byte> memberBytes = structBytes.Slice(index, member.Length);
            result.Members.Add(Hydrate(member, memberBytes));
            index += member.Length;
        }

        return result;
    }
}