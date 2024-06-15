namespace Structurizer.Tests;

using Structurizer.Types;

public class TypeDefTests {
    [Fact]
    public void TypeDef_CanBeParsed() {
        // Arrange
        var parser = new Parser(new StructurizerSettings());
        const string text = "typedef short testTypeDef;";
        
        // Act
        StructureInformation result = parser.ParseSource(text);
        
        // Assert
        result.Should().NotBeNull();
        result.TypeDefs.Should().ContainKey("testTypeDef");
        Variable resultTypeDef = result.TypeDefs["testTypeDef"];
        resultTypeDef.Size.Should().Be(2);
        resultTypeDef.Name.Should().Be("testTypeDef");
        resultTypeDef.Type.Should().Be("short");
    }
}