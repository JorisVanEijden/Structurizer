namespace Structurizer;

using Structurizer.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;

public class Formatter {
    protected readonly Dictionary<string, EnumType>? Enums;
    protected readonly Dictionary<string, StructType>? Structs;
    protected readonly Dictionary<string, TypeDefinition>? TypeDefs;

    public Formatter(StructurizerSettings config, StructureInformation? parseResult = null) {
        Structs = parseResult?.Structs;
        Enums = parseResult?.Enums;
        TypeDefs = parseResult?.TypeDefs.Any() is true ? parseResult.TypeDefs : config.TypeDefs;
    }

    public virtual JsonNode Format(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        if (Structs != null && Structs.TryGetValue(typeDefinition.Type, out StructType? structType)) {
            return typeDefinition.IsArray ? FormatStructArray(structType, bytes) : FormatStruct(structType, bytes);
        }

        if (Enums != null && Enums.TryGetValue(typeDefinition.Type, out EnumType? enumType)) {
            return typeDefinition.IsArray ? FormatEnumArray(enumType, bytes) : FormatEnum(enumType, bytes);
        }

        return typeDefinition.IsArray ? FormatTypeArray(typeDefinition, bytes) : FormatType(typeDefinition, bytes);
    }

    protected virtual JsonNode FormatTypeArray(TypeDefinition typeDefinition, ReadOnlySpan<byte> data) {
        var singleVariable = new TypeDefinition(typeDefinition.Name, typeDefinition.Type, typeDefinition.Size) {
            Count = 1,
            IsPointer = typeDefinition.IsPointer,
            IsNear = typeDefinition.IsNear,
            Alignment = typeDefinition.Alignment
        };

        int numberOfItems = data.Length / singleVariable.Size;
        var items = new List<JsonNode>(numberOfItems);

        for (var index = 0; index < numberOfItems; index += singleVariable.Size) {
            byte[]? slice = data.Slice(index, singleVariable.Size).ToArray();
            JsonValue item = FormatType(singleVariable, slice);
            items.Add(item);
        }

        return new JsonArray(items.ToArray());
    }

    protected virtual JsonArray FormatEnumArray(EnumType enumType, ReadOnlySpan<byte> data) {
        int numberOfItems = data.Length / enumType.MemberSize;
        var items = new List<JsonNode>(numberOfItems);

        for (var index = 0; index < numberOfItems; index += enumType.MemberSize) {
            byte[]? slice = data.Slice(index, enumType.MemberSize).ToArray();
            JsonValue item = FormatEnum(enumType, slice);
            items.Add(item);
        }

        return new JsonArray(items.ToArray());
    }

    protected virtual JsonArray FormatStructArray(StructType structType, ReadOnlySpan<byte> data) {
        int numberOfItems = data.Length / structType.Size;
        var items = new List<JsonNode>(numberOfItems);

        for (var index = 0; index < numberOfItems; index += structType.Size) {
            byte[]? slice = data.Slice(index, structType.Size).ToArray();
            JsonObject item = FormatStruct(structType, slice);
            items.Add(item);
        }

        return new JsonArray(items.ToArray());
    }

    protected virtual JsonValue FormatType(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        switch (typeDefinition.Type) {
            case "short" or "int":
                return FormatShort(bytes);
            case "unsigned short" or "unsigned int":
                return FormatUnsignedShort(bytes);
            case "long":
                return FormatLong(bytes);
            case "unsigned long":
                return FormatUnsignedLong(bytes);
        }
        switch (typeDefinition) {
            case {Type: "char", IsArray: true}:
                return FormatCharArray(bytes);
            case {Type: "char", IsArray: false}:
                return FormatChar(bytes);
        }

        if (TypeDefs != null && TypeDefs.TryGetValue(typeDefinition.Type, out TypeDefinition? knownTypeDef)) {
            return Format(knownTypeDef, bytes).AsValue();
        }

        if (typeDefinition.IsPointer) {
            return FormatPointer(typeDefinition, bytes);
        }

        throw new NotSupportedException($"Type {typeDefinition.Type} not supported");
    }

    protected virtual JsonValue FormatPointer(TypeDefinition typeDefinition, ReadOnlySpan<byte> bytes) {
        return typeDefinition.IsNear ? FormatNearPointer(bytes) : FormatPointer(bytes);
    }

    protected virtual JsonValue FormatPointer(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToUInt32(bytes));
    }

    protected virtual JsonValue FormatNearPointer(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToUInt16(bytes));
    }

    protected virtual JsonValue FormatChar(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(bytes[0]);
    }

    protected virtual JsonValue FormatCharArray(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(Encoding.ASCII.GetString(bytes));
    }

    protected virtual JsonValue FormatUnsignedLong(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToUInt32(bytes));
    }

    protected virtual JsonValue FormatLong(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToInt32(bytes));
    }

    protected virtual JsonValue FormatUnsignedShort(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToUInt16(bytes));
    }

    protected virtual JsonValue FormatShort(ReadOnlySpan<byte> bytes) {
        return JsonValue.Create(BitConverter.ToInt16(bytes));
    }

    protected virtual JsonValue FormatEnum(EnumType enumType, ReadOnlySpan<byte> bytes) {
        uint value = enumType.MemberSize switch {
            1 => bytes[0],
            2 => BitConverter.ToUInt16(bytes),
            4 => BitConverter.ToUInt32(bytes),
            _ => throw new NotSupportedException($"Enum member size {enumType.MemberSize} not supported")
        };

        if (enumType.Members.TryGetValue(value, out string name)) {
            return JsonValue.Create(name);
        }

        throw new ArgumentOutOfRangeException(nameof(bytes), $"Enum value {value} not found in enum");
    }

    public virtual JsonObject FormatStruct(StructType structType, ReadOnlySpan<byte> bytes) {
        if (bytes.Length < structType.Size) {
            throw new ArgumentOutOfRangeException(nameof(bytes), "Byte array is too small for the struct");
        }

        var result = new JsonObject();

        ReadOnlySpan<byte> structBytes = bytes[..structType.Size];
        var index = 0;
        foreach (TypeDefinition? member in structType.Members) {
            ReadOnlySpan<byte> memberBytes = structBytes.Slice(index, member.Length);
            JsonNode memberValue = Format(member, memberBytes);
            result.Add(member.Name, memberValue);
            index += member.Length;
        }

        return result;
    }
}