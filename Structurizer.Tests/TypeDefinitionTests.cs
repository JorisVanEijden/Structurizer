namespace Structurizer.Tests;

using Structurizer.Types;

public class TypeDefinitionTests {
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
        TypeDefinition resultTypeDefinitionDefinition = result.TypeDefs["testTypeDef"];
        resultTypeDefinitionDefinition.Size.Should().Be(2);
        resultTypeDefinitionDefinition.Name.Should().Be("testTypeDef");
        resultTypeDefinitionDefinition.Type.Should().Be("short");
    }
}