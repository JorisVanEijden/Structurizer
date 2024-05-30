namespace Structurizer.Tests;

using Xunit.Abstractions;

public class UnitTest1 {
    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test1(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Should().NotBeNull();
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test2(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Enums.Should().ContainKey("WhichValue");
        result.Enums["spellNames"].Members[44].Should().Be("Evil_Seek");
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test3(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("worldTile");
        result.Structs["worldTile"].Size.Should().Be(10);
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test4(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("overlayStub");
        result.Structs["overlayStub"].Members.Should().Contain(item => item.Name == "trap" && item.Size == 2);
    }
    
    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test5(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("resourceFileHandler");
        result.Structs["resourceFileHandler"].Members.Should().Contain(item => item.Name == "ReadMethod" && item.Size == 2);
    }
        
    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test6(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("bok_dataItem");
        result.Structs["bok_dataItem"].Members.Should().Contain(item => item.Name == "data" && item.Size == 0);
    }
            
    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test7(string filename) {
        // Arrange
        var parser = new Parser();

        // Act
        var result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Enums.Should().ContainKey("DisplayCombination");
        result.Enums["DisplayCombination"].Members.Count.Should().Be(14);
    }
    
    

    public static IEnumerable<object[]> GetTestFiles() {
        yield return ["ida.h"];
        yield return ["ghidra.h"];
    }
}