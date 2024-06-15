namespace Structurizer.Tests;

using Structurizer.Types;

public class EnumTests {
    [Fact]
    public void EnumWithoutValues_ShouldUseIndex() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            /* enum test */
                            enum testEnum
                            {
                                first,
                                second,
                                third,
                                fourth
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[2].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithTrailingComma_ShouldIgnoreExtraComma() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum
                            {
                                first,
                                second,
                                third,
                                fourth,
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[2].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithValues_ShouldUseValues() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum
                            {
                                first = 10,
                                second = 20,
                                third = 30,
                                fourth = 40
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[30].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithHexadecimalValues_ShouldUseValues() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum
                            {
                                first = 0x10,
                                second = 0x20,
                                third = 0x30,
                                fourth = 0x40
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[48].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithNegativeValues_ShouldUseValues() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum
                            {
                                first = -10,
                                second = -20,
                                third = -30,
                                fourth = -40
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[-30].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithDifferentBackingSize_ShouldRecordThatSize() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum : long
                            {
                                first = 10,
                                second = 20,
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        result.Enums["testEnum"].MemberSize.Should().Be(4);
    }
    
    [Fact]
    public void EnumWithDifferentWhiteSpace_ShouldParseNormally() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            /* enum test */ enum testEnum
                            { first=10,
                            second=20,third=30,
                            fourth=40};
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(4);
        members[30].Should().Be("third");
    }
    
    [Fact]
    public void EnumWithDuplicateMembers_ShouldUseAppendThemTogether() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = """
                            enum testEnum
                            {
                                first = 123,
                                second = 123,
                            };
                            """;
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Enums.Should().ContainKey("testEnum");
        Dictionary<long, string> members = result.Enums["testEnum"].Members;
        members.Count.Should().Be(1);
        members[123].Should().Be("first | second");
    }
}