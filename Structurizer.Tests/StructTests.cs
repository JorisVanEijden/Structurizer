namespace Structurizer.Tests;

using Structurizer.Types;

public class StructTests {
    [Fact]
    public void Struct_CanBeParsed() {
        // Arrange
        var parser = new Parser(new Configuration());
        const string text = """
                            /* struct test */
                            #pragma pack(push, 2)
                            struct testStruct
                            {
                              short testMember;
                            };
                            #pragma pack(pop)
                            """;
        
        // Act
        ParseResult result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(2);
        resultStruct.Name.Should().Be("testStruct");
        resultStruct.IsUnion.Should().BeFalse();
        List<Variable> members = resultStruct.Members;
        members.Count.Should().Be(1);
        members[0].Name.Should().Be("testMember");
        members[0].Type.Should().Be("short");
    }
    
    [Fact]
    public void StructWithDifferentSizedMembers_ShouldBeSizeOfAllMembersCombined() {
        // Arrange
        var parser = new Parser(new Configuration());
        const string text = """
                            /* struct test */
                            #pragma pack(push, 2)
                            struct testStruct
                            {
                              __int8 charMember;
                              __int16 shortMember;
                              __int32 longMember;
                              __int64 longLongMember;
                            };
                            #pragma pack(pop)
                            """;
        
        // Act
        ParseResult result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(15);
        resultStruct.Members[0].Size.Should().Be(1);
    }
    
    [Fact]
    public void StructAlignedAttributeOf2_ShouldBeRespected() {
        // Arrange
        var parser = new Parser(new Configuration());
        const string text = """
                            /* struct test */
                            #pragma pack(push, 2)
                            struct testStruct
                            {
                              __int8 charMember;
                              __attribute__((aligned(2))) __int16 shortMember;
                              __int32 longMember;
                              __int64 longLongMember;
                            };
                            #pragma pack(pop)
                            """;
        
        // Act
        ParseResult result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(16);
        resultStruct.Members[0].Size.Should().Be(2);
    }
}