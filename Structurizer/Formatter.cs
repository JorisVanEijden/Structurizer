namespace Structurizer;

using Structurizer.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;

public class Formatter {
    private readonly Dictionary<string, EnumType>? _enums;
    private readonly Dictionary<string, StructType>? _structs;
    private readonly Dictionary<string, Variable>? _typeDefs;
    
    public Formatter(StructurizerSettings config, StructureInformation? parseResult = null) {
        _structs = parseResult?.Structs;
        _enums = parseResult?.Enums;
        _typeDefs = parseResult?.TypeDefs.Any() is true ? parseResult.TypeDefs : config.TypeDefs;
    }
    
    public virtual JsonNode Format(Variable variable, ReadOnlySpan<byte> bytes) {
        if (_structs != null && _structs.TryGetValue(variable.Type, out StructType? structType)) {
            return FormatStruct(structType, bytes);
        }
        
        if (_enums != null && _enums.TryGetValue(variable.Type, out EnumType? enumType)) {
            return FormatEnum(enumType, bytes);
        }
        
        return FormatType(variable, bytes);
    }
    
    private JsonValue FormatType(Variable variable, ReadOnlySpan<byte> bytes) {
        switch (variable.Type) {
            case "short" or "int":
                return JsonValue.Create(BitConverter.ToInt16(bytes));
            case "unsigned short" or "unsigned int":
                return JsonValue.Create(BitConverter.ToUInt16(bytes));
            case "long":
                return JsonValue.Create(BitConverter.ToInt32(bytes));
            case "unsigned long":
                return JsonValue.Create(BitConverter.ToUInt32(bytes));
        }
        switch (variable) {
            case {Type: "char", Count: > 1}:
                return JsonValue.Create(Encoding.ASCII.GetString(bytes));
            case {Type: "char", Count: 1}:
                return JsonValue.Create(BitConverter.ToChar(bytes));
        }
        
        if (_typeDefs != null && _typeDefs.TryGetValue(variable.Type, out Variable? typeDef)) {
            return Format(typeDef, bytes).AsValue();
        }
        
        throw new NotSupportedException($"Type {variable.Type} not supported");
    }
    
    private static JsonValue FormatEnum(EnumType enumType, ReadOnlySpan<byte> bytes) {
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
        foreach (Variable? member in structType.Members) {
            ReadOnlySpan<byte> memberBytes = structBytes.Slice(index, member.Length);
            JsonNode memberValue = Format(member, memberBytes);
            result.Add(member.Name, memberValue);
            index += member.Length;
        }
        
        return result;
    }
}