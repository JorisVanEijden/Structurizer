namespace Structurizer;

using Structurizer.Types;
using System.Collections.Generic;

public class StructurizerSettings(Dictionary<string, TypeDefinition>? typeDefs = null) {
    public string DefaultEnumBackingType { get; set; } = "short";
    
    public Dictionary<string, TypeDefinition> TypeDefs { get; set; } = typeDefs ?? new Dictionary<string, TypeDefinition> {
        ["__int8"] = new("char", "char", SizeInBytes.Of8Bits),
        ["__int16"] = new("short", "short", SizeInBytes.Of16Bits),
        ["__int32"] = new("long", "long", SizeInBytes.Of32Bits),
        ["__int64"] = new("long long", "long long", SizeInBytes.Of64Bits),
        ["char"] = new("char", "char", SizeInBytes.Of8Bits),
        ["short"] = new("short", "short", SizeInBytes.Of16Bits),
        ["int"] = new("int", "int", SizeInBytes.Of16Bits),
        ["long"] = new("long", "long", SizeInBytes.Of32Bits),
        ["_BYTE"] = new("unsigned char", "unsigned char", SizeInBytes.Of8Bits),
        ["size_t"] = new("size_t", "size_t", SizeInBytes.Of16Bits)
    };
}