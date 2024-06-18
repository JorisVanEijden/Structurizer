namespace Structurizer.Tests;

using Structurizer.Types;
using System.Text.Json.Nodes;

public class FormatterTests {
    private readonly StructurizerSettings _config;
    
    public FormatterTests() {
        _config = new StructurizerSettings();
    }
    
    [Fact]
    public void Formatting_ShortValue_ShouldReturnShort() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "short", 2);
        var bytes = new byte[] {
            0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<short>().Should().Be(-30635);
    }
    
    [Fact]
    public void Formatting_StringValue_ShouldReturnString() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "char", 1) {
            Count = 12
        };
        byte[] bytes = "Hello world!"u8.ToArray();
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<string>().Should().Be("Hello world!");
    }
    
    [Fact]
    public void Formatting_UnsignedShortValue_ShouldReturnPositiveNumber() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "unsigned short", 2);
        var bytes = new byte[] {
            0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<ushort>().Should().Be(34901);
    }
    
    [Fact]
    public void Formatting_UnsignedIntValue_ShouldReturnPositiveNumber() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "unsigned int", 2);
        var bytes = new byte[] {
            0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<ushort>().Should().Be(34901);
    }
    
    [Fact]
    public void Formatting_SignedIntValue_ShouldReturnNegativeNumber() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "int", 2);
        var bytes = new byte[] {
            0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<short>().Should().Be(-30635);
    }
    
    [Fact]
    public void Formatting_SignedLongValue_ShouldReturnNegativeNumber() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "long", 4);
        var bytes = new byte[] {
            0x12, 0x23, 0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<int>().Should().Be(-2007686382);
    }
    
    [Fact]
    public void Formatting_UnsignedLongValue_ShouldReturnPositiveNumber() {
        // Arrange
        var formatter = new Formatter(_config);
        var variable = new TypeDefinition("testTypeDef", "unsigned long", 4);
        var bytes = new byte[] {
            0x12, 0x23, 0x55, 0x88
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<uint>().Should().Be(2287280914);
    }
    
    [Fact]
    public void Formatting_Struct_FormatsStructsRecursively() {
        // Arrange
        // A struct to embed into another.
        var parseResult = new StructureInformation {
            Structs = new Dictionary<string, StructType> {
                ["TestStruct2"] = new("TestStruct2") {
                    Members = [
                        new TypeDefinition("value1", "short", 2),
                        new TypeDefinition("value2", "char", 1) {
                            Count = 12
                        }
                    ]
                }
            }
        };
        
        // A struct containing the other struct
        var structType = new StructType("TestStruct") {
            Members = [
                new TypeDefinition("structMember", "TestStruct2", parseResult.Structs["TestStruct2"].Size),
                new TypeDefinition("member1", "short", 2),
                new TypeDefinition("member2", "char", 1) {
                    Count = 12
                }
            ]
        };
        parseResult.Structs["TestStruct"] = structType;
        
        // Set up variable and data 
        var formatter = new Formatter(_config, parseResult);
        var variable = new TypeDefinition("var", "TestStruct");
        var bytes = new byte[] {
            0x12, 0x34, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x21, 0x12, 0x34, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x21
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.ToJsonString().Should().Be("""{"structMember":{"value1":13330,"value2":"Hello world!"},"member1":13330,"member2":"Hello world!"}""");
    }
    
    [Fact]
    public void Formatting_Struct_FormatsMembersRecursively() {
        // Arrange
        var formatter = new Formatter(_config);
        var structType = new StructType("TestStruct");
        structType.Members.Add(new TypeDefinition("member1", "short", 2));
        structType.Members.Add(new TypeDefinition("member2", "char", 1) {
            Count = 12
        });
        var bytes = new byte[] {
            0x12, 0x34, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x21
        };
        
        // Act
        JsonObject result = formatter.FormatStruct(structType, bytes);
        
        // Assert
        result.ToJsonString().Should()
            .Be("""{"member1":13330,"member2":"Hello world!"}""");
    }
    
    [Fact]
    public void Formatting_EnumMember_ShowsValueName() {
        // Arrange
        var parseResult = new StructureInformation {
            Enums = new Dictionary<string, EnumType> {
                ["TestEnum"] = new() {
                    MemberSize = 2,
                    Members = {
                        [1] = "Value1",
                        [2] = "Value2"
                    }
                }
            }
        };
        
        var formatter = new Formatter(_config, parseResult);
        var variable = new TypeDefinition("var", "TestEnum", 2);
        var bytes = new byte[] {
            0x02, 0x00
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.GetValue<string>().Should().Be("Value2");
    }
    
    [Fact]
    public void Formatting_EnumMemberInStruct_ShowsValueName() {
        // Arrange
        var parseResult = new StructureInformation {
            Enums = new Dictionary<string, EnumType> {
                ["TestEnum"] = new() {
                    MemberSize = 2,
                    Members = {
                        [1] = "Value1",
                        [2] = "Value2"
                    }
                }
            },
            Structs = new Dictionary<string, StructType> {
                ["TestStruct"] = new("TestStruct") {
                    Members = [new TypeDefinition("enumMember", "TestEnum", 2)]
                }
            }
        };
        
        var formatter = new Formatter(_config, parseResult);
        var variable = new TypeDefinition("var", "TestStruct");
        var bytes = new byte[] {
            0x02, 0x00
        };
        
        // Act
        JsonNode result = formatter.Format(variable, bytes);
        
        // Assert
        result.ToJsonString().Should()
            .Be("""{"enumMember":"Value2"}""");
    }
}