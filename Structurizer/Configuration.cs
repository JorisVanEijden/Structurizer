namespace Structurizer;

public class Configuration {
    public string DefaultEnumBackingType { get; set; } = "__int16";
    public int DefaultPointerSize { get; set; } = 4;
    public int DefaultSizeT { get; set; } = 2;
}