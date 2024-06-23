namespace Structurizer.Tests;

using Structurizer.Types;

public class RealFilesTests {
    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void TestFileParsing(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Should().NotBeNull();
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test2(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Enums.Should().ContainKey("WhichValue");
        result.Enums["spellNames"].Members[44].Should().Be("Evil_Seek");
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test3(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("worldTile");
        result.Structs["worldTile"].Size.Should().Be(10);
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test5(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("resourceFileHandler");
        result.Structs["resourceFileHandler"].Members.Should().Contain(item => item.Name == "ReadMethod" && item.Size == 2);
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test7(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Enums.Should().ContainKey("DisplayCombination");
        result.Enums["DisplayCombination"].Members.Count.Should().Be(14);
    }

    [Theory]
    [MemberData(nameof(GetTestFiles))]
    public void Test8(string filename) {
        // Arrange
        var parser = new Parser(new StructurizerSettings());

        // Act
        StructureInformation result = parser.ParseFile(Path.Join("Fixtures", filename));

        // Assert
        result.Structs.Should().ContainKey("enemyParty");
        result.Structs["enemyParty"].Members.Should().Contain(item => item.Name == "pEnemyActor" && item.Size == 2 && item.Count == 7);
    }

    public static IEnumerable<object[]> GetTestFiles() {
        yield return ["ida.h.sample"];
        yield return ["ghidra.h.sample"];
    }
}