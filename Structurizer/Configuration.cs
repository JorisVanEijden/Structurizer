namespace Structurizer;

public class Configuration {
    public string DefaultEnumBackingType { get; set; } = "short";
    public int DefaultPointerSize { get; set; } = 4;
    public int DefaultSizeT { get; set; } = 2;
    public int IntSize { get; set; } = 4;
}