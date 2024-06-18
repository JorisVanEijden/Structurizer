namespace Structurizer.Tests;

using Structurizer.Types;

public class StructTests {
    [Fact]
    public void Struct_CanBeParsed() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
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
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(2);
        resultStruct.Name.Should().Be("testStruct");
        resultStruct.IsUnion.Should().BeFalse();
        List<TypeDefinition> members = resultStruct.Members;
        members.Count.Should().Be(1);
        members[0].Name.Should().Be("testMember");
        members[0].Type.Should().Be("short");
    }
    
    [Fact]
    public void StructWithDifferentSizedMembers_ShouldBeSizeOfAllMembersCombined() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              __int8 charMember;
                              __int16 shortMember;
                              __int32 longMember;
                              __int64 longLongMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(15);
        resultStruct.Members[0].Size.Should().Be(1);
    }
    
    [Fact]
    public void StructAlignedAttributeOf2_ShouldAlignTo2ByInsertingZero() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              __int8 charMember;
                              __attribute__((aligned(2))) __int16 shortMember;
                              __int32 longMember;
                              __int64 longLongMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(16);
        resultStruct.Members[1].Should().BeEquivalentTo(new {
            Name = "",
            Type = "",
            Size = 1,
            Count = 1
        });
    }
    
    [Fact]
    public void StructAlignedAttributeOf4_ShouldAlignTo4ByInserting3Empty() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              __int8 charMember;
                              __attribute__((aligned(4))) __int16 shortMember;
                              __int8 byteMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        StructType resultStruct = result.Structs["testStruct"];
        resultStruct.Size.Should().Be(7);
        resultStruct.Members[1].Should().BeEquivalentTo(new {
            Name = "",
            Type = "",
            Size = 1,
            Count = 3
        });
    }
    
    [Fact]
    public void StructWithPointerMember_ShouldUseSizeOfPointer() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              void *pointerMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        TypeDefinition member = result.Structs["testStruct"].Members[0];
        member.IsPointer.Should().BeTrue();
        member.IsNear.Should().BeFalse();
        member.Size.Should().Be(4);
    }
    
    [Fact]
    public void StructWithNearPointerMember_ShouldUseSizeOfNearPointer() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              void near *pointerMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        TypeDefinition member = result.Structs["testStruct"].Members[0];
        member.IsPointer.Should().BeTrue();
        member.IsNear.Should().BeTrue();
        member.Size.Should().Be(2);
    }
    
    [Fact]
    public void StructWithGhidraPointerMember_ShouldBeTreatedAsNearPointer() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct testStruct
                            {
                              pointer pointerMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("testStruct");
        TypeDefinition member = result.Structs["testStruct"].Members[0];
        member.IsPointer.Should().BeTrue();
        member.IsNear.Should().BeTrue();
        member.Size.Should().Be(2);
    }
    
    [Fact]
    public void NestedStructs_ShouldBeParsedCorrectly() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            struct innerStruct
                            {
                              __int8 charMember;
                            };
                            struct outerStruct
                            {
                                innerStruct innerMember;
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.Structs.Should().ContainKey("outerStruct");
        result.Structs[result.Structs["outerStruct"].Members[0].Type].Members[0].Type.Should().Be("__int8");
    }
}