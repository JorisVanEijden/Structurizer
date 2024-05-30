typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned long    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined2;
typedef unsigned long    undefined4;
typedef unsigned short    ushort;
typedef unsigned int    word;
typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[40];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef void *__gnuc_va_list;

typedef int intptr_t;

typedef struct _IO_FILE FILE;

typedef uint __mode_t;

typedef enum $FB0B2E4B11C33F202C8E57FBCC18F8B1 {
    altFormatBit=1,
    leftJustBit=2,
    notZeroBit=4,
    fillZerosBit=8,
    isLongBit=16,
    farPtrBit=32,
    alt0xBit=64,
    floatBit=128,
    LongDoubleBit=256
} $FB0B2E4B11C33F202C8E57FBCC18F8B1;

typedef struct activeSpellEffect activeSpellEffect, *PactiveSpellEffect;

struct activeSpellEffect {
    word SpellNumber?;
    word investedCost;
    word duration;
    word field_6;
    word next;
    byte field_A;
};

typedef struct actor actor, *Pactor;

typedef struct attributeValues attributeValues, *PattributeValues;

struct attributeValues {
    byte max?;
    byte current?;
    byte currentEffective?;
    byte experience;
    byte modifier;
};

struct actor {
    pointer name;
    word knownSpells1;
    word knownSpells2;
    word knownSpells3;
    struct attributeValues health;
    struct attributeValues stamina;
    struct attributeValues speed;
    struct attributeValues strength;
    struct attributeValues defense;
    struct attributeValues accuracy_crossbow;
    struct attributeValues accuracy_melee;
    struct attributeValues accuracy_casting;
    struct attributeValues assessment;
    struct attributeValues armorcraft;
    struct attributeValues weaponcraft;
    struct attributeValues barding;
    struct attributeValues haggling;
    struct attributeValues lockpick;
    struct attributeValues scouting;
    struct attributeValues stealth;
    byte actorNumber?;
    pointer32 inventory;
    pointer pCombatData;
};

typedef enum actorAttribute {
    Health=0,
    Stamina=1,
    Speed=2,
    Strength=3,
    Defense=4,
    AccuracyCrossbow=5,
    AccuracyMelee=6,
    AccuracyCasting=7,
    Assessment=8,
    ArmorCraft=9,
    WeaponCraft=10,
    Barding=11,
    Haggling=12,
    LockPicking=13,
    Scouting=14,
    Stealth=15,
    HealthStaminaCombo=16
} actorAttribute;

typedef struct actorFaces actorFaces, *PactorFaces;

struct actorFaces {
    word actorNumber;
    undefined field1_0x2;
    undefined field2_0x3;
    undefined field3_0x4;
    undefined field4_0x5;
    undefined field5_0x6;
    undefined field6_0x7;
    undefined field7_0x8;
    undefined field8_0x9;
    undefined field9_0xa;
    undefined field10_0xb;
    word pBitmap;
    undefined field12_0xe;
    undefined field13_0xf;
    undefined field14_0x10;
    undefined field15_0x11;
    undefined field16_0x12;
    undefined field17_0x13;
    undefined field18_0x14;
    undefined field19_0x15;
    undefined field20_0x16;
    undefined field21_0x17;
    dword pPalette;
    undefined field23_0x1c;
    undefined field24_0x1d;
    undefined field25_0x1e;
    undefined field26_0x1f;
    undefined field27_0x20;
    undefined field28_0x21;
    undefined field29_0x22;
    undefined field30_0x23;
    undefined field31_0x24;
    undefined field32_0x25;
    undefined field33_0x26;
    undefined field34_0x27;
    undefined field35_0x28;
    undefined field36_0x29;
    undefined field37_0x2a;
    undefined field38_0x2b;
    undefined field39_0x2c;
    undefined field40_0x2d;
    undefined field41_0x2e;
    undefined field42_0x2f;
};

typedef struct actorStatusEffects actorStatusEffects, *PactorStatusEffects;

struct actorStatusEffects {
    byte sick;
    byte plagued;
    byte poisoned;
    byte drunk;
    byte healing;
    byte starving;
    byte nearDeath;
};

typedef struct animationRecord animationRecord, *PanimationRecord;

struct animationRecord {
    word recordNumber;
    word numberOfPages;
    dword pResourceData;
    dword pEndOfResourceData;
    pointer pBitmap;
    pointer pBitmap2;
    word field_10;
    word field_12;
    word field_14;
    word pBmImage;
    word font1;
    word font2;
    word font3;
    word font4;
    word font5;
    word font6;
    dword palette;
    dword field_28;
    dword field_2C;
    dword field_30;
    dword field_34;
    dword field_38;
    dword field_3C;
    dword field_40;
    dword field_44;
    dword field_48;
    dword field_4C;
    dword field_50;
    dword field_54;
    dword field_58;
    dword field_5C;
    dword field_60;
    dword field_64;
    dword field_68;
    word field_6C;
    undefined field35_0x6e;
    undefined field36_0x6f;
    undefined field37_0x70;
    undefined field38_0x71;
    undefined field39_0x72;
    undefined field40_0x73;
    undefined field41_0x74;
    undefined field42_0x75;
    undefined field43_0x76;
    undefined field44_0x77;
    undefined field45_0x78;
    undefined field46_0x79;
    undefined field47_0x7a;
    undefined field48_0x7b;
    undefined field49_0x7c;
    undefined field50_0x7d;
    undefined field51_0x7e;
    undefined field52_0x7f;
    undefined field53_0x80;
    undefined field54_0x81;
    undefined field55_0x82;
    undefined field56_0x83;
    word field_84;
    undefined field58_0x86;
    undefined field59_0x87;
    undefined field60_0x88;
    undefined field61_0x89;
    undefined field62_0x8a;
    undefined field63_0x8b;
    undefined field64_0x8c;
    undefined field65_0x8d;
    undefined field66_0x8e;
    undefined field67_0x8f;
    undefined field68_0x90;
    undefined field69_0x91;
    undefined field70_0x92;
    undefined field71_0x93;
    undefined field72_0x94;
    undefined field73_0x95;
    undefined field74_0x96;
    undefined field75_0x97;
    undefined field76_0x98;
    undefined field77_0x99;
    undefined field78_0x9a;
    undefined field79_0x9b;
    word field_9C;
    undefined field81_0x9e;
    undefined field82_0x9f;
    undefined field83_0xa0;
    undefined field84_0xa1;
    undefined field85_0xa2;
    undefined field86_0xa3;
    undefined field87_0xa4;
    undefined field88_0xa5;
    undefined field89_0xa6;
    undefined field90_0xa7;
    undefined field91_0xa8;
    undefined field92_0xa9;
    undefined field93_0xaa;
    undefined field94_0xab;
    undefined field95_0xac;
    undefined field96_0xad;
    undefined field97_0xae;
    undefined field98_0xaf;
    undefined field99_0xb0;
    undefined field100_0xb1;
    undefined field101_0xb2;
    undefined field102_0xb3;
    word field_B4;
    undefined field104_0xb6;
    undefined field105_0xb7;
    undefined field106_0xb8;
    undefined field107_0xb9;
    undefined field108_0xba;
    undefined field109_0xbb;
    undefined field110_0xbc;
    undefined field111_0xbd;
    undefined field112_0xbe;
    undefined field113_0xbf;
    undefined field114_0xc0;
    undefined field115_0xc1;
    undefined field116_0xc2;
    undefined field117_0xc3;
    undefined field118_0xc4;
    undefined field119_0xc5;
    undefined field120_0xc6;
    undefined field121_0xc7;
    undefined field122_0xc8;
    undefined field123_0xc9;
    undefined field124_0xca;
    undefined field125_0xcb;
    dword pNextAnimationRecord;
    dword p4bytePageData;
};

typedef struct animationTag animationTag, *PanimationTag;

struct animationTag {
    word animationRecordNumber;
    word tagNumber;
    word startFrame;
    word field_6;
    word endFrame;
    word field_A;
    word field_C;
    word field_E;
    word field_10;
    word field_12;
    word field_14;
    word field_16;
    undefined field12_0x18;
    undefined field13_0x19;
    undefined field14_0x1a;
    undefined field15_0x1b;
    word field_1C;
    byte field_1E;
    byte field_1F;
    byte field_20;
    word field_21;
    word screenWidth;
    word field_25;
    word screenHeight;
    word field_29;
    word field_2B;
    word field_2D;
    word field_2F;
    word field_31;
    dword field_33;
    dword field_37;
    word nextTag;
};

typedef struct area area, *Parea;

struct area {
    word xPosition; /* X Position */
    word yPosition; /* Y position */
    word width; /* Width */
    word height; /* Height */
};

typedef char ascii;

typedef enum attributeFlags {
    Health_=1,
    Stamina_=2,
    Speed_=4,
    Strength_=8,
    Defense_=16,
    AccuracyCrossbow_=32,
    AccuracyMelee_=64,
    AccuracyCasting_=128,
    Assessment_=256,
    ArmorCraft_=512,
    WeaponCraft_=1024,
    Barding_=2048,
    Haggling_=4096,
    LockPicking_=8192,
    Scouting_=16384,
    Stealth_=32768
} attributeFlags;

typedef struct bitmap bitmap, *Pbitmap;

struct bitmap {
    word imageDataSegment_or_EMS_PageNr;
    word imageDataOffset;
    word flags;
    word Width;
    word Height;
};

typedef struct bmxHeader bmxHeader, *PbmxHeader;

struct bmxHeader {
    word magic;
    word compression;
    word amount;
    word compressedDataSize?;
    dword nrOfBytes;
};

typedef struct bNameEntry bNameEntry, *PbNameEntry;

struct bNameEntry {
    ascii name;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    byte number;
    undefined field5_0x5;
    undefined field6_0x6;
    byte colorSet?;
};

typedef struct bok_data bok_data, *Pbok_data;

typedef struct bok_paragraph bok_paragraph, *Pbok_paragraph;

typedef struct bok_fontInfo bok_fontInfo, *Pbok_fontInfo;

struct bok_fontInfo {
    word font;
    word yOffset;
    byte field_4;
    undefined field3_0x5;
    byte field_6;
    undefined field5_0x7;
    word fontFlags;
};

struct bok_paragraph {
    word x_offset;
    word width;
    word lineSpacing;
    word wordSpacing;
    word startIndent;
    word x_offset2;
    word y_offset;
    word alignment;
};

struct bok_data {
    struct bok_paragraph paragraph;
    struct bok_fontInfo fontInfo;
    word bool_field_1A;
    word x_offset2;
    word y_offset;
    word x_offset1;
    word max_x?;
    word field_24;
    word field_26;
    word field_28;
    word field_2A;
    word field_2C;
    word field_2E;
    word field_30;
    word field_32;
    pointer32 pDataItem;
    pointer32 field_38;
    dword field_3C;
    word pFonts;
    undefined field19_0x42;
    undefined field20_0x43;
    undefined field21_0x44;
    undefined field22_0x45;
    undefined field23_0x46;
    undefined field24_0x47;
    undefined field25_0x48;
    undefined field26_0x49;
    undefined field27_0x4a;
    undefined field28_0x4b;
    undefined field29_0x4c;
    undefined field30_0x4d;
    undefined field31_0x4e;
    undefined field32_0x4f;
    undefined field33_0x50;
    undefined field34_0x51;
    undefined field35_0x52;
    undefined field36_0x53;
    word pBitmapResource;
    dword pPalette;
    word field_5A;
    word field_5C;
    word field_5E;
    word EmsPageNr1;
    word EmsPageNr2;
};

typedef struct bok_dataItem bok_dataItem, *Pbok_dataItem;

struct bok_dataItem {
    byte type;
    byte data;
};

typedef struct bok_imageInfo bok_imageInfo, *Pbok_imageInfo;

struct bok_imageInfo {
    word x_offset;
    word y_offset;
    word width_or_imageNumber;
    word height_or_orientation;
};

typedef struct bok_page bok_page, *Pbok_page;

struct bok_page {
    word x_offset;
    word y_offset;
    word width;
    word height;
    word pageRelatedNumber?;
    word pageNumber;
    word previousPageNumber;
    word nextPageNumber;
    word nextPage?;
    word field_12;
    word nrOfImages;
    word nrOfReservedAreas?;
    word showPageNumber;
    dword field_1A;
    struct bok_paragraph paragraph;
    struct bok_fontInfo fontInfo;
    struct bok_imageInfo imageInfos;
};

typedef struct bok_pageList bok_pageList, *Pbok_pageList;

struct bok_pageList {
    word nrOfPages;
    pointer32 pBokPage;
};

typedef struct chapterDataPart1 chapterDataPart1, *PchapterDataPart1;

struct chapterDataPart1 {
    word ChapterNumber;
    dword field_2;
    dword field_6;
    dword field_A;
    byte field_E;
    byte field_F;
};

typedef struct color color, *Pcolor;

struct color {
    byte red;
    byte green;
    byte blue;
};

typedef struct combatData combatData, *PcombatData;

struct combatData {
    pointer targetActor?;
    word creatureType;
    byte x_on_grid;
    byte y_on_grid;
    byte target_x_on_grid?;
    byte target_y_on_grid?;
    byte combatStatus?;
    byte field_9;
    word activeSpellEffectSlot?;
    byte field_C;
    byte field_D;
    byte field_E;
    byte field_F;
    byte field_10;
    byte field_11;
    byte field_12;
    byte field_13;
    byte field_14;
    byte field_15;
};

typedef struct combatGridCell combatGridCell, *PcombatGridCell;

struct combatGridCell {
    pointer pActor;
    word grid_element;
    word value?;
};

typedef enum combatStatusFlags {
    unknown_combatStatus_1=1,
    unknown_combatStatus_2=2,
    unknown_combatStatus_4=4,
    combatStatus_defending=8,
    unknown_combatStatus_16=16,
    combatStatus_poisoned=32,
    unknown_combatStatus_64=64,
    unknown_combatStatus_128=128
} combatStatusFlags;

typedef enum conditionNumber {
    condition_sick=0,
    condition_plagued=1,
    condition_poisoned=2,
    condition_drunk=3,
    condition_healing=4,
    condition_starving=5,
    condition_nearDeath=6
} conditionNumber;

typedef struct config config, *Pconfig;

struct config {
    byte stepSize;
    byte turnSize;
    byte levelOfDetail;
    byte textSpeed;
    byte flags;
};

typedef enum configFlags {
    soundOn=1,
    musicOn=2,
    combatMusic=4,
    playIntro=8,
    cdmusic?=16
} configFlags;

typedef struct container container, *Pcontainer;

typedef struct containerMetaData containerMetaData, *PcontainerMetaData;

typedef struct inventoryItem inventoryItem, *PinventoryItem;

typedef union containerLocation containerLocation, *PcontainerLocation;

typedef struct containerLocationWorld containerLocationWorld, *PcontainerLocationWorld;

typedef struct containerLocationActor containerLocationActor, *PcontainerLocationActor;

struct containerLocationActor {
    word field_0;
    word field_2;
    word actorNr;
    word field_6;
    word field_8;
    word field_A;
};

struct containerLocationWorld {
    byte zone;
    byte minMaxChapter;
    word worldItemId?;
    dword X;
    dword Y;
};

union containerLocation {
    struct containerLocationWorld world;
    struct containerLocationActor actor;
};

struct containerMetaData { /* The 1st 12 bytes are probably a union of three types */
    union containerLocation location;
    byte containerType;
    byte numberOfItems;
    byte capacity;
    byte dataTypes;
};

struct inventoryItem {
    byte objectId;
    byte variable;
    word itemFlags;
};

struct container {
    byte field_0;
    byte field_1;
    dword offsetInSaveFile;
    struct containerMetaData metaData;
    struct inventoryItem items;
};

typedef struct containerData_dialog containerData_dialog, *PcontainerData_dialog;

struct containerData_dialog {
    byte field_0;
    byte flag_field_1;
    dword dialogId;
};

typedef struct containerData_encounter containerData_encounter, *PcontainerData_encounter;

struct containerData_encounter {
    word globalDataKey1;
    word globalDataKey2;
    byte gds_number?;
    byte gds_letter?;
    byte field_6;
    byte x;
    byte y;
};

typedef struct containerData_lock containerData_lock, *PcontainerData_lock;

struct containerData_lock {
    byte flags;
    byte difficulty;
    byte puzzleChest;
    byte trapDamage;
};

typedef struct containerData_shop containerData_shop, *PcontainerData_shop;

struct containerData_shop {
    byte field_0;
    byte markupPercentage;
    byte field_2;
    byte markDownPercentage;
    byte field_4;
    byte field_5;
    byte bardingDifficulty;
    byte bardingReward;
    byte field_8;
    byte field_9;
    byte field_A;
    byte field_B;
    byte field_C;
    byte field_D;
    word shopCategories;
};

typedef struct containerData_timestamp containerData_timestamp, *PcontainerData_timestamp;

struct containerData_timestamp {
    dword double_seconds;
};

typedef struct containerData_unknown20 containerData_unknown20, *PcontainerData_unknown20;

struct containerData_unknown20 {
    word field_0;
};

typedef enum containerDataTypes {
    dataType_Lock=1,
    dataType_Dialog=2,
    dataType_Shop=4,
    dataType_Encounter=8,
    dataType_TimeStamp=16,
    dataType_unknown20=32,
    dataTypeFlag_1=64,
    dataTypeFlag_2=128
} containerDataTypes;

typedef enum containerType {
    containerType_0=0,
    containerType_inventory=1,
    containerType_2=2,
    containerType_3=3,
    containerType_4=4,
    containerType_5=5,
    containerType_fixedWorldItem=6,
    containerType_7=7,
    containerType_8=8,
    containerType_9=9
} containerType;

typedef struct Coordinates_64k Coordinates_64k, *PCoordinates_64k;

struct Coordinates_64k {
    dword X;
    dword Y;
};

typedef enum ctypes {
    space=1,
    digit=2,
    upper=4,
    lower=8,
    hexad=16,
    cntrl=32,
    punct=64
} ctypes;

typedef enum currency {
    currency_gold_fractional=0,
    currency_gold_silver=1,
    currency_sovereigns_royals=2
} currency;

typedef struct def_bkgr def_bkgr, *Pdef_bkgr;

struct def_bkgr {
    undefined field0_0x0;
    undefined field1_0x1;
    word field_2;
    undefined field3_0x4;
    undefined field4_0x5;
    dword dialogId;
    undefined field6_0xa;
    undefined field7_0xb;
    undefined field8_0xc;
    undefined field9_0xd;
    word field_E;
    undefined field11_0x10;
    undefined field12_0x11;
    byte field_12;
    byte field_13;
    byte field_14;
};

typedef struct def_bloc def_bloc, *Pdef_bloc;

struct def_bloc {
    undefined field0_0x0;
    undefined field1_0x1;
    dword dialogId;
    undefined field3_0x6;
    byte field_7;
};

typedef struct def_comb def_comb, *Pdef_comb;

struct def_comb {
    word field_0;
    dword encounterNumber;
    dword dialogId1;
    dword dialogId2;
    undefined field4_0xe;
    word globalKey;
    undefined field6_0x11;
    word field_12;
    undefined field8_0x14;
    undefined field9_0x15;
    undefined field10_0x16;
    undefined field11_0x17;
    undefined field12_0x18;
    undefined field13_0x19;
    undefined field14_0x1a;
    undefined field15_0x1b;
    word field_1C;
    undefined field17_0x1e;
    undefined field18_0x1f;
    undefined field19_0x20;
    undefined field20_0x21;
    undefined field21_0x22;
    undefined field22_0x23;
    undefined field23_0x24;
    undefined field24_0x25;
    word field_26;
    undefined field26_0x28;
    undefined field27_0x29;
    undefined field28_0x2a;
    undefined field29_0x2b;
    undefined field30_0x2c;
    undefined field31_0x2d;
    undefined field32_0x2e;
    undefined field33_0x2f;
    word field_30;
    undefined field35_0x32;
    undefined field36_0x33;
    undefined field37_0x34;
    undefined field38_0x35;
    undefined field39_0x36;
    undefined field40_0x37;
    undefined field41_0x38;
    undefined field42_0x39;
    byte field_3A;
    word monsterNumber?;
    undefined field45_0x3d;
    undefined field46_0x3e;
    undefined field47_0x3f;
    undefined field48_0x40;
    undefined field49_0x41;
    undefined field50_0x42;
    undefined field51_0x43;
    undefined field52_0x44;
    undefined field53_0x45;
    undefined field54_0x46;
    undefined field55_0x47;
    undefined field56_0x48;
    undefined field57_0x49;
    undefined field58_0x4a;
    undefined field59_0x4b;
    undefined field60_0x4c;
    undefined field61_0x4d;
    undefined field62_0x4e;
    undefined field63_0x4f;
    undefined field64_0x50;
    undefined field65_0x51;
    undefined field66_0x52;
    undefined field67_0x53;
    undefined field68_0x54;
    undefined field69_0x55;
    undefined field70_0x56;
    undefined field71_0x57;
    undefined field72_0x58;
    undefined field73_0x59;
    undefined field74_0x5a;
    undefined field75_0x5b;
    undefined field76_0x5c;
    undefined field77_0x5d;
    undefined field78_0x5e;
    undefined field79_0x5f;
    undefined field80_0x60;
    undefined field81_0x61;
    undefined field82_0x62;
    undefined field83_0x63;
    undefined field84_0x64;
    undefined field85_0x65;
    undefined field86_0x66;
    undefined field87_0x67;
    undefined field88_0x68;
    undefined field89_0x69;
    undefined field90_0x6a;
    undefined field91_0x6b;
    undefined field92_0x6c;
    undefined field93_0x6d;
    undefined field94_0x6e;
    undefined field95_0x6f;
    undefined field96_0x70;
    undefined field97_0x71;
    undefined field98_0x72;
    undefined field99_0x73;
    undefined field100_0x74;
    undefined field101_0x75;
    undefined field102_0x76;
    undefined field103_0x77;
    undefined field104_0x78;
    undefined field105_0x79;
    undefined field106_0x7a;
    undefined field107_0x7b;
    undefined field108_0x7c;
    undefined field109_0x7d;
    undefined field110_0x7e;
    undefined field111_0x7f;
    undefined field112_0x80;
    undefined field113_0x81;
    undefined field114_0x82;
    undefined field115_0x83;
    undefined field116_0x84;
    undefined field117_0x85;
    undefined field118_0x86;
    undefined field119_0x87;
    undefined field120_0x88;
    undefined field121_0x89;
    undefined field122_0x8a;
    undefined field123_0x8b;
    undefined field124_0x8c;
    undefined field125_0x8d;
    undefined field126_0x8e;
    undefined field127_0x8f;
    undefined field128_0x90;
    undefined field129_0x91;
    undefined field130_0x92;
    undefined field131_0x93;
    undefined field132_0x94;
    undefined field133_0x95;
    undefined field134_0x96;
    undefined field135_0x97;
    undefined field136_0x98;
    undefined field137_0x99;
    undefined field138_0x9a;
    undefined field139_0x9b;
    undefined field140_0x9c;
    undefined field141_0x9d;
    undefined field142_0x9e;
    undefined field143_0x9f;
    undefined field144_0xa0;
    undefined field145_0xa1;
    undefined field146_0xa2;
    undefined field147_0xa3;
    undefined field148_0xa4;
    undefined field149_0xa5;
    undefined field150_0xa6;
    undefined field151_0xa7;
    undefined field152_0xa8;
    undefined field153_0xa9;
    undefined field154_0xaa;
    undefined field155_0xab;
    undefined field156_0xac;
    undefined field157_0xad;
    undefined field158_0xae;
    undefined field159_0xaf;
    undefined field160_0xb0;
    undefined field161_0xb1;
    undefined field162_0xb2;
    undefined field163_0xb3;
    undefined field164_0xb4;
    undefined field165_0xb5;
    undefined field166_0xb6;
    undefined field167_0xb7;
    undefined field168_0xb8;
    undefined field169_0xb9;
    undefined field170_0xba;
    undefined field171_0xbb;
    undefined field172_0xbc;
    undefined field173_0xbd;
    undefined field174_0xbe;
    undefined field175_0xbf;
    undefined field176_0xc0;
    undefined field177_0xc1;
    undefined field178_0xc2;
    undefined field179_0xc3;
    undefined field180_0xc4;
    undefined field181_0xc5;
    undefined field182_0xc6;
    undefined field183_0xc7;
    undefined field184_0xc8;
    undefined field185_0xc9;
    undefined field186_0xca;
    undefined field187_0xcb;
    undefined field188_0xcc;
    undefined field189_0xcd;
    undefined field190_0xce;
    undefined field191_0xcf;
    undefined field192_0xd0;
    undefined field193_0xd1;
    undefined field194_0xd2;
    undefined field195_0xd3;
    undefined field196_0xd4;
    undefined field197_0xd5;
    undefined field198_0xd6;
    undefined field199_0xd7;
    undefined field200_0xd8;
    undefined field201_0xd9;
    undefined field202_0xda;
    undefined field203_0xdb;
    undefined field204_0xdc;
    undefined field205_0xdd;
    undefined field206_0xde;
    undefined field207_0xdf;
    undefined field208_0xe0;
    undefined field209_0xe1;
    undefined field210_0xe2;
    undefined field211_0xe3;
    undefined field212_0xe4;
    undefined field213_0xe5;
    undefined field214_0xe6;
    undefined field215_0xe7;
    undefined field216_0xe8;
    undefined field217_0xe9;
    undefined field218_0xea;
    undefined field219_0xeb;
    undefined field220_0xec;
    undefined field221_0xed;
    undefined field222_0xee;
    undefined field223_0xef;
    undefined field224_0xf0;
    undefined field225_0xf1;
    undefined field226_0xf2;
    undefined field227_0xf3;
    undefined field228_0xf4;
    undefined field229_0xf5;
    undefined field230_0xf6;
    undefined field231_0xf7;
    undefined field232_0xf8;
    undefined field233_0xf9;
    undefined field234_0xfa;
    undefined field235_0xfb;
    undefined field236_0xfc;
    undefined field237_0xfd;
    undefined field238_0xfe;
    undefined field239_0xff;
    undefined field240_0x100;
    undefined field241_0x101;
    undefined field242_0x102;
    undefined field243_0x103;
    undefined field244_0x104;
    undefined field245_0x105;
    undefined field246_0x106;
    undefined field247_0x107;
    undefined field248_0x108;
    undefined field249_0x109;
    undefined field250_0x10a;
    undefined field251_0x10b;
    undefined field252_0x10c;
    undefined field253_0x10d;
    undefined field254_0x10e;
    undefined field255_0x10f;
    undefined field256_0x110;
    undefined field257_0x111;
    undefined field258_0x112;
    undefined field259_0x113;
    undefined field260_0x114;
    undefined field261_0x115;
    undefined field262_0x116;
    undefined field263_0x117;
    undefined field264_0x118;
    undefined field265_0x119;
    undefined field266_0x11a;
    undefined field267_0x11b;
    undefined field268_0x11c;
    undefined field269_0x11d;
    undefined field270_0x11e;
    undefined field271_0x11f;
    undefined field272_0x120;
    undefined field273_0x121;
    undefined field274_0x122;
    undefined field275_0x123;
    undefined field276_0x124;
    undefined field277_0x125;
    undefined field278_0x126;
    undefined field279_0x127;
    undefined field280_0x128;
    undefined field281_0x129;
    undefined field282_0x12a;
    undefined field283_0x12b;
    undefined field284_0x12c;
    undefined field285_0x12d;
    undefined field286_0x12e;
    undefined field287_0x12f;
    undefined field288_0x130;
    undefined field289_0x131;
    undefined field290_0x132;
    undefined field291_0x133;
    undefined field292_0x134;
    undefined field293_0x135;
    undefined field294_0x136;
    undefined field295_0x137;
    undefined field296_0x138;
    undefined field297_0x139;
    undefined field298_0x13a;
    undefined field299_0x13b;
    undefined field300_0x13c;
    undefined field301_0x13d;
    undefined field302_0x13e;
    undefined field303_0x13f;
    undefined field304_0x140;
    undefined field305_0x141;
    undefined field306_0x142;
    undefined field307_0x143;
    undefined field308_0x144;
    undefined field309_0x145;
    undefined field310_0x146;
    undefined field311_0x147;
    undefined field312_0x148;
    undefined field313_0x149;
    undefined field314_0x14a;
    undefined field315_0x14b;
    undefined field316_0x14c;
    undefined field317_0x14d;
    undefined field318_0x14e;
    undefined field319_0x14f;
    undefined field320_0x150;
    undefined field321_0x151;
    undefined field322_0x152;
    undefined field323_0x153;
    undefined field324_0x154;
    undefined field325_0x155;
    undefined field326_0x156;
    undefined field327_0x157;
    undefined field328_0x158;
    undefined field329_0x159;
    undefined field330_0x15a;
    undefined field331_0x15b;
    undefined field332_0x15c;
    undefined field333_0x15d;
    undefined field334_0x15e;
    undefined field335_0x15f;
    undefined field336_0x160;
    undefined field337_0x161;
    undefined field338_0x162;
    undefined field339_0x163;
    undefined field340_0x164;
    undefined field341_0x165;
    undefined field342_0x166;
    undefined field343_0x167;
    undefined field344_0x168;
    undefined field345_0x169;
    undefined field346_0x16a;
    undefined field347_0x16b;
    undefined field348_0x16c;
    undefined field349_0x16d;
    undefined field350_0x16e;
    undefined field351_0x16f;
    undefined field352_0x170;
    undefined field353_0x171;
    undefined field354_0x172;
    undefined field355_0x173;
    undefined field356_0x174;
    undefined field357_0x175;
    undefined field358_0x176;
    undefined field359_0x177;
    undefined field360_0x178;
    undefined field361_0x179;
    undefined field362_0x17a;
    undefined field363_0x17b;
    undefined field364_0x17c;
    undefined field365_0x17d;
    undefined field366_0x17e;
    undefined field367_0x17f;
    undefined field368_0x180;
    undefined field369_0x181;
    undefined field370_0x182;
    undefined field371_0x183;
    undefined field372_0x184;
    undefined field373_0x185;
    undefined field374_0x186;
    undefined field375_0x187;
    undefined field376_0x188;
    undefined field377_0x189;
    undefined field378_0x18a;
    undefined field379_0x18b;
    undefined field380_0x18c;
    word field_18D;
};

typedef struct def_comm def_comm, *Pdef_comm;

struct def_comm {
    byte field_0;
    byte field_1;
    byte field_2;
    byte field_3;
    byte field_4;
    byte field_5;
    byte field_6;
    byte field_7;
    byte field_8;
    byte field_9;
};

typedef struct def_dial def_dial, *Pdef_dial;

struct def_dial {
    byte field_0;
    byte field_1;
    dword dialogId;
    byte field_6;
};

typedef struct def_disa def_disa, *Pdef_disa;

struct def_disa {
    byte field_0;
    byte field_1;
    byte chance;
    word global_key;
    byte field_5;
    byte field_6;
};

typedef struct def_enab def_enab, *Pdef_enab;

struct def_enab {
    byte field_0;
    byte field_1;
    byte chance;
    word global_key;
    byte field_5;
    byte field_6;
};

typedef struct def_file_entry_header def_file_entry_header, *Pdef_file_entry_header;

struct def_file_entry_header {
    word field_0;
    dword field_2;
    dword dialogId;
};

typedef struct def_file_struct def_file_struct, *Pdef_file_struct;

struct def_file_struct {
    word type;
    byte start_x?;
    byte end_y?;
    byte end_x?;
    byte start_y?;
    dword entryNumber;
    byte field_A;
    word global_key1;
    word global_key2;
    word global_key3;
    word field_11;
};

typedef enum def_files {
    def_bkgr.dat=0,
    def_comb.dat=1,
    def_comm.dat=2,
    def_dial.dat=3,
    def_heal.dat=4,
    def_soun.dat=5,
    def_town.dat=6,
    def_trap.dat=7,
    def_zone.dat=8,
    def_disa.dat=9,
    def_enab.dat=10,
    def_bloc.dat=11
} def_files;

typedef struct def_soun def_soun, *Pdef_soun;

struct def_soun {
    byte field_0;
    byte field_1;
    byte chance;
    word aoudioId?;
    byte field_5;
    byte field_6;
};

typedef struct def_town def_town, *Pdef_town;

struct def_town {
    undefined field0_0x0;
    undefined field1_0x1;
    word field_2;
    undefined field3_0x4;
    undefined field4_0x5;
    dword dialogId;
    undefined field6_0xa;
    undefined field7_0xb;
    undefined field8_0xc;
    undefined field9_0xd;
    word field_E;
    undefined field11_0x10;
    undefined field12_0x11;
    byte field_12;
    undefined field14_0x13;
    byte field_14;
};

typedef struct def_trap def_trap, *Pdef_trap;

typedef struct unknownStruct339 unknownStruct339, *PunknownStruct339;

struct unknownStruct339 {
    undefined field0_0x0;
    word field_1;
    undefined field2_0x3;
    undefined field3_0x4;
    undefined field4_0x5;
    undefined field5_0x6;
    undefined field6_0x7;
    undefined field7_0x8;
    undefined field8_0x9;
    undefined field9_0xa;
    undefined field10_0xb;
    undefined field11_0xc;
    undefined field12_0xd;
    undefined field13_0xe;
    undefined field14_0xf;
    undefined field15_0x10;
    undefined field16_0x11;
    undefined field17_0x12;
    undefined field18_0x13;
    undefined field19_0x14;
    undefined field20_0x15;
    undefined field21_0x16;
    undefined field22_0x17;
    undefined field23_0x18;
    undefined field24_0x19;
    undefined field25_0x1a;
    undefined field26_0x1b;
    undefined field27_0x1c;
    undefined field28_0x1d;
    undefined field29_0x1e;
    undefined field30_0x1f;
    undefined field31_0x20;
    undefined field32_0x21;
    undefined field33_0x22;
    undefined field34_0x23;
    undefined field35_0x24;
    undefined field36_0x25;
    undefined field37_0x26;
    undefined field38_0x27;
    undefined field39_0x28;
    undefined field40_0x29;
    undefined field41_0x2a;
    undefined field42_0x2b;
    undefined field43_0x2c;
    undefined field44_0x2d;
    undefined field45_0x2e;
    undefined field46_0x2f;
    undefined field47_0x30;
    undefined field48_0x31;
    undefined field49_0x32;
    undefined field50_0x33;
    undefined field51_0x34;
    undefined field52_0x35;
    undefined field53_0x36;
    undefined field54_0x37;
    undefined field55_0x38;
    undefined field56_0x39;
    undefined field57_0x3a;
    undefined field58_0x3b;
    undefined field59_0x3c;
    undefined field60_0x3d;
    undefined field61_0x3e;
    undefined field62_0x3f;
    undefined field63_0x40;
    undefined field64_0x41;
    undefined field65_0x42;
    undefined field66_0x43;
    undefined field67_0x44;
    undefined field68_0x45;
    undefined field69_0x46;
    undefined field70_0x47;
    undefined field71_0x48;
    undefined field72_0x49;
    undefined field73_0x4a;
    undefined field74_0x4b;
    undefined field75_0x4c;
    undefined field76_0x4d;
    undefined field77_0x4e;
    undefined field78_0x4f;
    undefined field79_0x50;
    undefined field80_0x51;
    undefined field81_0x52;
    undefined field82_0x53;
    undefined field83_0x54;
    undefined field84_0x55;
    undefined field85_0x56;
    undefined field86_0x57;
    undefined field87_0x58;
    undefined field88_0x59;
    undefined field89_0x5a;
    undefined field90_0x5b;
    undefined field91_0x5c;
    undefined field92_0x5d;
    undefined field93_0x5e;
    undefined field94_0x5f;
    undefined field95_0x60;
    undefined field96_0x61;
    undefined field97_0x62;
    undefined field98_0x63;
    undefined field99_0x64;
    undefined field100_0x65;
    undefined field101_0x66;
    undefined field102_0x67;
    undefined field103_0x68;
    undefined field104_0x69;
    undefined field105_0x6a;
    undefined field106_0x6b;
    undefined field107_0x6c;
    undefined field108_0x6d;
    undefined field109_0x6e;
    undefined field110_0x6f;
    undefined field111_0x70;
    undefined field112_0x71;
    undefined field113_0x72;
    undefined field114_0x73;
    undefined field115_0x74;
    undefined field116_0x75;
    undefined field117_0x76;
    undefined field118_0x77;
    undefined field119_0x78;
    undefined field120_0x79;
    undefined field121_0x7a;
    undefined field122_0x7b;
    undefined field123_0x7c;
    undefined field124_0x7d;
    undefined field125_0x7e;
    undefined field126_0x7f;
    undefined field127_0x80;
    undefined field128_0x81;
    undefined field129_0x82;
    undefined field130_0x83;
    undefined field131_0x84;
    undefined field132_0x85;
    undefined field133_0x86;
    undefined field134_0x87;
    undefined field135_0x88;
    undefined field136_0x89;
    undefined field137_0x8a;
    undefined field138_0x8b;
    undefined field139_0x8c;
    undefined field140_0x8d;
    undefined field141_0x8e;
    undefined field142_0x8f;
    undefined field143_0x90;
    undefined field144_0x91;
    undefined field145_0x92;
    undefined field146_0x93;
    undefined field147_0x94;
    undefined field148_0x95;
    undefined field149_0x96;
    undefined field150_0x97;
    undefined field151_0x98;
    undefined field152_0x99;
    undefined field153_0x9a;
    undefined field154_0x9b;
    undefined field155_0x9c;
    undefined field156_0x9d;
    undefined field157_0x9e;
    undefined field158_0x9f;
    undefined field159_0xa0;
    undefined field160_0xa1;
    undefined field161_0xa2;
    undefined field162_0xa3;
    undefined field163_0xa4;
    undefined field164_0xa5;
    undefined field165_0xa6;
    undefined field166_0xa7;
    undefined field167_0xa8;
    undefined field168_0xa9;
    undefined field169_0xaa;
    undefined field170_0xab;
    undefined field171_0xac;
    undefined field172_0xad;
    undefined field173_0xae;
    undefined field174_0xaf;
    undefined field175_0xb0;
    undefined field176_0xb1;
    undefined field177_0xb2;
    undefined field178_0xb3;
    undefined field179_0xb4;
    undefined field180_0xb5;
    undefined field181_0xb6;
    undefined field182_0xb7;
    undefined field183_0xb8;
    undefined field184_0xb9;
    undefined field185_0xba;
    undefined field186_0xbb;
    undefined field187_0xbc;
    undefined field188_0xbd;
    undefined field189_0xbe;
    undefined field190_0xbf;
    undefined field191_0xc0;
    undefined field192_0xc1;
    undefined field193_0xc2;
    undefined field194_0xc3;
    undefined field195_0xc4;
    undefined field196_0xc5;
    undefined field197_0xc6;
    undefined field198_0xc7;
    undefined field199_0xc8;
    undefined field200_0xc9;
    undefined field201_0xca;
    undefined field202_0xcb;
    undefined field203_0xcc;
    undefined field204_0xcd;
    undefined field205_0xce;
    undefined field206_0xcf;
    undefined field207_0xd0;
    undefined field208_0xd1;
    undefined field209_0xd2;
    undefined field210_0xd3;
    undefined field211_0xd4;
    undefined field212_0xd5;
    undefined field213_0xd6;
    undefined field214_0xd7;
    undefined field215_0xd8;
    undefined field216_0xd9;
    undefined field217_0xda;
    undefined field218_0xdb;
    undefined field219_0xdc;
    undefined field220_0xdd;
    undefined field221_0xde;
    undefined field222_0xdf;
    undefined field223_0xe0;
    undefined field224_0xe1;
    undefined field225_0xe2;
    undefined field226_0xe3;
    undefined field227_0xe4;
    undefined field228_0xe5;
    undefined field229_0xe6;
    undefined field230_0xe7;
    undefined field231_0xe8;
    undefined field232_0xe9;
    undefined field233_0xea;
    undefined field234_0xeb;
    undefined field235_0xec;
    undefined field236_0xed;
    undefined field237_0xee;
    undefined field238_0xef;
    undefined field239_0xf0;
    undefined field240_0xf1;
    undefined field241_0xf2;
    undefined field242_0xf3;
    undefined field243_0xf4;
    undefined field244_0xf5;
    undefined field245_0xf6;
    undefined field246_0xf7;
    undefined field247_0xf8;
    undefined field248_0xf9;
    undefined field249_0xfa;
    undefined field250_0xfb;
    undefined field251_0xfc;
    undefined field252_0xfd;
    undefined field253_0xfe;
    undefined field254_0xff;
    undefined field255_0x100;
    undefined field256_0x101;
    undefined field257_0x102;
    undefined field258_0x103;
    undefined field259_0x104;
    undefined field260_0x105;
    undefined field261_0x106;
    undefined field262_0x107;
    undefined field263_0x108;
    undefined field264_0x109;
    undefined field265_0x10a;
    undefined field266_0x10b;
    undefined field267_0x10c;
    undefined field268_0x10d;
    undefined field269_0x10e;
    undefined field270_0x10f;
    undefined field271_0x110;
    undefined field272_0x111;
    undefined field273_0x112;
    undefined field274_0x113;
    undefined field275_0x114;
    undefined field276_0x115;
    undefined field277_0x116;
    undefined field278_0x117;
    undefined field279_0x118;
    undefined field280_0x119;
    undefined field281_0x11a;
    undefined field282_0x11b;
    undefined field283_0x11c;
    undefined field284_0x11d;
    undefined field285_0x11e;
    undefined field286_0x11f;
    undefined field287_0x120;
    undefined field288_0x121;
    undefined field289_0x122;
    undefined field290_0x123;
    undefined field291_0x124;
    undefined field292_0x125;
    undefined field293_0x126;
    undefined field294_0x127;
    undefined field295_0x128;
    undefined field296_0x129;
    undefined field297_0x12a;
    undefined field298_0x12b;
    undefined field299_0x12c;
    undefined field300_0x12d;
    undefined field301_0x12e;
    undefined field302_0x12f;
    undefined field303_0x130;
    undefined field304_0x131;
    undefined field305_0x132;
    undefined field306_0x133;
    undefined field307_0x134;
    undefined field308_0x135;
    undefined field309_0x136;
    undefined field310_0x137;
    undefined field311_0x138;
    undefined field312_0x139;
    undefined field313_0x13a;
    undefined field314_0x13b;
    undefined field315_0x13c;
    undefined field316_0x13d;
    undefined field317_0x13e;
    undefined field318_0x13f;
    undefined field319_0x140;
    undefined field320_0x141;
    undefined field321_0x142;
    undefined field322_0x143;
    undefined field323_0x144;
    undefined field324_0x145;
    undefined field325_0x146;
    undefined field326_0x147;
    undefined field327_0x148;
    undefined field328_0x149;
    undefined field329_0x14a;
    undefined field330_0x14b;
    undefined field331_0x14c;
    undefined field332_0x14d;
    undefined field333_0x14e;
    undefined field334_0x14f;
    undefined field335_0x150;
    undefined field336_0x151;
    byte field_152;
};

struct def_trap {
    undefined field0_0x0;
    undefined field1_0x1;
    dword encounterNumber;
    dword dialogId1;
    dword dialogId2;
    undefined field5_0xe;
    undefined field6_0xf;
    undefined field7_0x10;
    undefined field8_0x11;
    byte field_12;
    undefined field10_0x13;
    undefined field11_0x14;
    undefined field12_0x15;
    undefined field13_0x16;
    undefined field14_0x17;
    undefined field15_0x18;
    undefined field16_0x19;
    undefined field17_0x1a;
    undefined field18_0x1b;
    byte field_1C;
    undefined field20_0x1d;
    undefined field21_0x1e;
    undefined field22_0x1f;
    undefined field23_0x20;
    undefined field24_0x21;
    undefined field25_0x22;
    undefined field26_0x23;
    undefined field27_0x24;
    undefined field28_0x25;
    byte field_26;
    undefined field30_0x27;
    undefined field31_0x28;
    undefined field32_0x29;
    undefined field33_0x2a;
    undefined field34_0x2b;
    undefined field35_0x2c;
    undefined field36_0x2d;
    undefined field37_0x2e;
    undefined field38_0x2f;
    byte field_30;
    undefined field40_0x31;
    undefined field41_0x32;
    undefined field42_0x33;
    undefined field43_0x34;
    undefined field44_0x35;
    undefined field45_0x36;
    undefined field46_0x37;
    undefined field47_0x38;
    undefined field48_0x39;
    struct Coordinates_64k coordinates;
    word field_42;
    struct unknownStruct339 struct339;
    word field_197;
};

typedef struct def_zone def_zone, *Pdef_zone;

typedef struct location location, *Plocation;

struct location {
    byte zoneNumber?;
    byte tileX;
    byte tileY;
    byte tileXoffset;
    byte tileYoffset;
    word zRotation;
};

struct def_zone {
    undefined field0_0x0;
    undefined field1_0x1;
    struct location location;
    dword dialogId1;
    dword dialogId2;
    undefined field5_0x11;
    byte field_12;
};

typedef struct dialogAction dialogAction, *PdialogAction;

typedef union dialogActionData dialogActionData, *PdialogActionData;

typedef struct dialogAction_SetTemporaryFlag dialogAction_SetTemporaryFlag, *PdialogAction_SetTemporaryFlag;

typedef struct dialogAction_SetTimer dialogAction_SetTimer, *PdialogAction_SetTimer;

typedef struct dialogAction_LearnSpell dialogAction_LearnSpell, *PdialogAction_LearnSpell;

typedef struct dialogAction_GiveItem dialogAction_GiveItem, *PdialogAction_GiveItem;

typedef struct dialogAction_RemoveItem dialogAction_RemoveItem, *PdialogAction_RemoveItem;

typedef struct dialogAction_UseItem dialogAction_UseItem, *PdialogAction_UseItem;

typedef struct dialogAction_SetGlobalValue dialogAction_SetGlobalValue, *PdialogAction_SetGlobalValue;

typedef struct dialogAction_ChangeParty dialogAction_ChangeParty, *PdialogAction_ChangeParty;

typedef struct dialogAction_GetAttribute dialogAction_GetAttribute, *PdialogAction_GetAttribute;

typedef struct dialogAction_ChangeAttribute dialogAction_ChangeAttribute, *PdialogAction_ChangeAttribute;

typedef struct dialogAction_ApplyCondition dialogAction_ApplyCondition, *PdialogAction_ApplyCondition;

typedef struct dialogAction_Heal dialogAction_Heal, *PdialogAction_Heal;

typedef struct dialogAction_PlayAudio dialogAction_PlayAudio, *PdialogAction_PlayAudio;

typedef struct dialogAction_PlaySound dialogAction_PlaySound, *PdialogAction_PlaySound;

typedef struct dialogAction_AdvanceTime dialogAction_AdvanceTime, *PdialogAction_AdvanceTime;

typedef struct dialogAction_Teleport dialogAction_Teleport, *PdialogAction_Teleport;

typedef struct dialogAction_SubAction dialogAction_SubAction, *PdialogAction_SubAction;

typedef struct dialogAction_PushDialogEntry dialogAction_PushDialogEntry, *PdialogAction_PushDialogEntry;

typedef struct dialogAction_SetReturnValue dialogAction_SetReturnValue, *PdialogAction_SetReturnValue;

typedef struct dialogAction_ResizeDialog dialogAction_ResizeDialog, *PdialogAction_ResizeDialog;

struct dialogAction_Teleport {
    word destinationId;
    word field_2;
    word field_4;
    word field_6;
};

struct dialogAction_ResizeDialog {
    word x;
    word y;
    word width;
    word height;
};

struct dialogAction_SubAction {
    word type;
    word field_2;
    word field_4;
    word field_6;
};

struct dialogAction_GiveItem {
    byte objectId;
    byte actor;
    word amount;
    word cost;
    word unused;
};

struct dialogAction_UseItem {
    word objectId;
    word amount;
    word field_4;
    word field_6;
};

struct dialogAction_Heal {
    word target;
    word amount;
    word field_4;
    word field_6;
};

struct dialogAction_SetTemporaryFlag {
    dword globalKey;
    dword time;
};

struct dialogAction_ChangeAttribute {
    byte target;
    byte type;
    word attribute;
    word minValue;
    word maxValue;
};

struct dialogAction_SetTimer {
    byte type;
    byte flag;
    word key;
    dword time;
};

struct dialogAction_LearnSpell {
    word actor;
    word spellNumber;
    word field_4;
    word field_6;
};

struct dialogAction_GetAttribute {
    word target; /* 1 = max from whole party, 2+ = actor from corresponding variable slot */
    word attribute;
    dword field_4;
};

struct dialogAction_ApplyCondition {
    word target;
    word condition;
    word minValue;
    word maxValue;
};

struct dialogAction_SetGlobalValue {
    word key;
    byte andMask;
    byte orMask;
    byte xorMask;
    undefined field4_0x5;
    word value;
};

struct dialogAction_PlaySound {
    word audioId;
    word field_2;
    word field_4;
    word field_6;
};

struct dialogAction_PushDialogEntry {
    dword offset;
    word field_4;
    word field_6;
};

struct dialogAction_RemoveItem {
    word objectId;
    word amount;
    word field_4;
    word field_6;
};

struct dialogAction_ChangeParty {
    word partySize;
    word Actor1;
    word Actor2;
    word Actor3;
};

struct dialogAction_AdvanceTime {
    word amount;
    word field_2;
    word field_4;
    word field_6;
};

struct dialogAction_PlayAudio {
    word audioId;
    word shouldPlay;
    word field_4;
    word field_6;
};

struct dialogAction_SetReturnValue {
    word value;
    word field_2;
    word field_4;
    word field_6;
};

union dialogActionData {
    struct dialogAction_SetTemporaryFlag setTemporaryFlag;
    struct dialogAction_SetTimer setTimer;
    struct dialogAction_LearnSpell learnSpell;
    struct dialogAction_GiveItem giveItem;
    struct dialogAction_RemoveItem removeItem;
    struct dialogAction_UseItem useItem;
    struct dialogAction_SetGlobalValue setGlobalValue;
    struct dialogAction_ChangeParty changeParty;
    struct dialogAction_GetAttribute getAttribute;
    struct dialogAction_ChangeAttribute changeAttribute;
    struct dialogAction_ApplyCondition applyCondition;
    struct dialogAction_Heal heal;
    struct dialogAction_PlayAudio playAudio;
    struct dialogAction_PlaySound playSound;
    struct dialogAction_AdvanceTime advanceTime;
    struct dialogAction_Teleport teleport;
    struct dialogAction_SubAction subAction;
    struct dialogAction_PushDialogEntry pushDialogEntry;
    struct dialogAction_SetReturnValue setReturnValue;
    struct dialogAction_ResizeDialog resizeDialog;
};

struct dialogAction {
    word type?;
    union dialogActionData action;
};

typedef enum dialogActionType {
    unknownAction=0,
    SetTextVariable=1,
    GiveItem=2,
    RemoveItem=3,
    SetGlobalValue=4,
    ResizeDialog=6,
    ApplyCondition=8,
    ChangeAttribute=9,
    GetPartyAttribute=10,
    PlayAudio=12,
    AdvanceTime=13,
    PushDialogEntry=16,
    SetReturnValue=21
} dialogActionType;

typedef struct dialogBranchData dialogBranchData, *PdialogBranchData;

struct dialogBranchData {
    word globalKey;
    word unknown3;
    word unknown4;
    dword offset;
};

typedef struct dialogEntry dialogEntry, *PdialogEntry;

struct dialogEntry {
    byte dialogType;
    word actorNr;
    word flag_field_3;
    byte branchCount;
    byte dialogActionCount;
    word stringLength;
};

typedef struct dialogTypeData dialogTypeData, *PdialogTypeData;

struct dialogTypeData {
    byte field_0;
    byte field_1;
    byte field_2;
    byte field_3;
    byte field_4;
    byte field_5;
    byte field_6;
    byte field_7;
    byte field_8;
    byte field_9;
    byte field_A;
    byte field_B;
    union dialogActionData actionData;
};

typedef enum DisplayCombination {
    noDisplay=0,
    monochromeAdapterWithMonochromeDisplay=1,
    CGAWithColorDisplay=2,
    Reserved=3,
    EGAWithColorDisplay=4,
    EGAWithMonochromeDisplay=5,
    PGAWithColorDisplay=6,
    VGAWithMonochromeAnalogDisplay=7,
    VGAWithColorAnalogDisplay=8,
    Reserved2=9,
    MCGAWithDigitalColorDisplay=10,
    MCGAWithMonochromeAnalogDisplay=11,
    MCGAWithColorAnalogDisplay=12,
    UnknownDisplay=255
} DisplayCombination;

typedef struct enemyParty enemyParty, *PenemyParty;

struct enemyParty {
    pointer112 pEnemyActor;
};

typedef struct enemyStruct6 enemyStruct6, *PenemyStruct6;

struct enemyStruct6 {
    word field_0;
    word field_2;
    word field_4;
};

typedef struct expiry_timer expiry_timer, *Pexpiry_timer;

struct expiry_timer {
    byte type;
    byte flag;
    word key;
    dword time;
};

typedef struct ffblk ffblk, *Pffblk;

struct ffblk {
    byte ff_reserved;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    byte ff_attrib;
    word ff_ftime;
    word ff_fdate;
    dword ff_fsize;
    byte ff_name;
    undefined field26_0x1f;
    undefined field27_0x20;
    undefined field28_0x21;
    undefined field29_0x22;
    undefined field30_0x23;
    undefined field31_0x24;
    undefined field32_0x25;
    undefined field33_0x26;
    undefined field34_0x27;
    undefined field35_0x28;
    undefined field36_0x29;
    undefined field37_0x2a;
    undefined field38_0x2b;
};


/* WARNING! conflicting data type names: /FILE - /stdio.h/FILE */

typedef enum FileFlags {
    _F_READ=1,
    _F_WRIT=2,
    _F_BUF=4,
    _F_LBUF=8,
    _F_ERR=16,
    _F_EOF=32,
    _F_BIN=64,
    _F_IN=128,
    _F_OUT=256,
    _F_TERM=512
} FileFlags;

typedef enum flagBits {
} flagBits;

typedef enum gameDataOffset {
    gameDataOffset_Actors=2775,
    gameDataOffset_GoldPerChapter=4855,
    gameDataOffset_Encounter7EnemyPointers=4895
} gameDataOffset;

typedef enum gameObjectType {
    gameObjectType_0=0,
    gameObjectType_1=1,
    gameObjectType_actor=2,
    gameObjectType_combatData=3,
    gameObjectType_container=4,
    gameObjectType_none=4294967295
} gameObjectType;

typedef struct gds gds, *Pgds;

typedef struct gds_struct36 gds_struct36, *Pgds_struct36;

struct gds_struct36 {
    word xPos;
    word yPos;
    word width;
    word height;
    word field_8_flag;
    word field_A;
    byte field_C;
    byte field_D;
    word field_E;
    word field_10;
    dword dialogId1;
    dword dialogId2;
    dword pDialogEntry;
    word globalKey;
    word minGlobalValue?;
    word maxGlobalValue?;
};

struct gds {
    ascii label;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    word field_D_flag;
    word field_F;
    word song;
    word field_13;
    word field_15;
    word field_17;
    word field_19;
    word num_something;
    dword dialogId;
    dword pDialogEntry;
    pointer pContainer;
    undefined field24_0x27;
    undefined field25_0x28;
    struct gds_struct36 field_29;
};

typedef enum gridElementType {
    grid_element_damaging?=1,
    grid_element_out_of_bounds?=2,
    grid_element_trap_crystal=3,
    grid_element_unknown_4=4,
    grid_element_trap_diamond=5,
    grid_element_exit=6,
    grid_element_unknown_7=7,
    grid_element_unknown_8=8,
    grid_element_unknown_9=9,
    grid_element_cannon_west=10,
    grid_element_cannon_east=11,
    grid_element_cannon_north=12,
    grid_element_cannon_south=13,
    grid_element_actor_2=15,
    grid_element_actor_1=16,
    grid_element_actor_0=17
} gridElementType;

typedef struct heapHeader heapHeader, *PheapHeader;

struct heapHeader {
    word bsize;
    word prev_real;
    word prev_free;
    word next_free;
};

typedef enum interactable {
    interactable_bush_food=26,
    interactable_bush_poison=27,
    interactable_bush_healing=28
} interactable;

typedef enum itemFlags {
    item_lit=1,
    itemFlag_unknown2=2,
    itemFlag_unknown4=4,
    item_broken=16,
    item_repairable=32,
    item_equipped=64,
    item_poisoned=128,
    item_flaming=256,
    item_steelfired=512,
    item_frosted=1024,
    item_enhanced1=2048,
    item_enhanced2=4096,
    item_blessed1=8192,
    item_blessed2=16384,
    item_blessed3=32768
} itemFlags;

typedef enum itemShopCategories {
    Miscellaneous=1,
    Rations_=2,
    Jewelry=4,
    Keys=8,
    NotForSale=32,
    CombatItems=64,
    Swords=128,
    RangedWeapons=256,
    Armors=512,
    MagicItems=1024,
    Staves=2048,
    Spells=4096,
    Books=8192,
    Potions=16384,
    Modifiers=32768
} itemShopCategories;

typedef enum keyboard {
    keyboard_escape=1,
    keyboard_backspace=14,
    keyboard_tab=15,
    keyboard_P=25,
    keyboard_enter=28,
    keyboard_left_control=29,
    keyboard_backtick=41,
    keyboard_left_shift=42,
    keyboard_N=49,
    keyboard_right_shift=54,
    keyboard_left_alt=56,
    keyboard_space=57,
    keyboard_numlock=69,
    keyboard_scrollock=70,
    keyboard_numpad_7=71,
    keyboard_numpad_8=72,
    keyboard_numpad_4=75,
    keyboard_numpad_5=76,
    keyboard_numpad_6=77,
    keyboard_numpad_plus=78,
    keyboard_numpad_1=79,
    keyboard_numpad_2=80,
    keyboard_numpad_0=82,
    keyboard_numpad_dot=83
} keyboard;

typedef struct keyword keyword, *Pkeyword;

struct keyword {
    word number;
    pointer pString;
};

typedef struct labelData labelData, *PlabelData;

struct labelData {
    word pString;
    word xPosition;
    word yPosition;
    word attributes;
    byte color?;
    byte shadowColor?;
};

typedef enum lockFlags {
    lock_trapped=4
} lockFlags;

typedef enum MACRO_FA {
    FA_NORMAL=0,
    FA_RDONLY=1,
    FA_HIDDEN=2,
    FA_SYSTEM=4,
    FA_LABEL=8,
    FA_DIREC=16,
    FA_ARCH=32
} MACRO_FA;

typedef enum MagicConstants {
    BmxFileSignature=4198,
    ScxFileSignature=10166
} MagicConstants;

typedef enum mainCharacter {
    Character_Locklear=0,
    Character_Gorath=1,
    Character_Owyn=2,
    Character_Pug=3,
    Character_James=4,
    Character_Patrus=5
} mainCharacter;

typedef enum memoryLocations {
    pStream1STDOUT=14306
} memoryLocations;

typedef struct menuData menuData, *PmenuData;

struct menuData {
    word field_0;
    word IsModal;
    word field_4;
    word xPosition;
    word yPosition;
    word width;
    word height;
    word numElements;
    pointer pUiElements;
    word pLabel;
    word xOffset;
    word yOffset;
    dword pBitmapData;
};

typedef enum mouseButton {
    mouseButton_left=0,
    mouseButton_right=1
} mouseButton;

typedef struct mousePointer mousePointer, *PmousePointer;

struct mousePointer {
    word x;
    word y;
    word xOffset?;
    word yOffset?;
    word CursorImageWidth;
    word CursorImageHeight;
    word imageNumber?;
};

typedef struct negativeStatusEffect negativeStatusEffect, *PnegativeStatusEffect;

struct negativeStatusEffect {
    ascii Name;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    byte field_A;
    word field_B;
    word field_D;
    word bitMaskForAffectedAttributes1;
    word effectOnAttributes1;
    word bitMaskForAffectedAttributes2;
    word effectOnAttributes2;
};

typedef enum objectFlags {
    objectFlags_1h=1,
    NotEquipable=2,
    objectFlags_8h=8,
    objectFlags_10h=16,
    objectFlags_20h=32,
    OnlyUsableInCombat=64,
    Magical=128,
    NotUsableInCombat=256,
    ArchersOnly=512,
    Stackable=2048,
    Degradable=4096,
    LimitedUses=8192,
    objectFlags_8000h=32768
} objectFlags;

typedef struct objectInfo objectInfo, *PobjectInfo;

struct objectInfo {
    ascii name;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    word field_1E;
    word objectFlags;
    word wordWrap;
    word chapterNumber;
    word basePrice;
    word swingBase?;
    word thrustBase?;
    word swingAccuracy_armorMod;
    word thrustAccuracy;
    word icon;
    word inventorySlots;
    word soundId_nrOfTimes;
    byte maxAmount;
    byte field_37;
    word racialMod;
    word shopCategories;
    word objectType;
    word attributesMask?;
    word effectStrength;
    word field_42;
    word durationInHours?;
    word affectedAttributes;
    word affectedAmount;
    word chanceToDegrade;
    word maxWearAmount;
    word minimumQuality;
};

typedef enum objectNames {
    Crystal_Staff=1,
    Lightning_Staff=2,
    Staff_of_Macros=4,
    Amulet_of_the_Upright_Man=5,
    Ring_of_Prandur=6,
    Brass_Spyglass=7,
    Cup_of_Rlnn_Skr=8,
    Eliaems_Heart=9,
    Glory_Hand=10,
    Horn_of_Algon_Kokoon=11,
    Idol_of_Lassur=12,
    Infinity_Pool=13,
    Raw_Manna=14,
    Rorics_Seal=15,
    Shell=16,
    Wyverns_Egg=17,
    Guarda_Revanche=22,
    Exotic_sword=23,
    Bessy_Mauler=32,
    Tsurani_Heavy_Crossbow=34,
    Quarrels=36,
    Elven_Quarrels=37,
    Tsurani_Quarrels=38,
    Poisoned_Quarrels=39,
    Poisoned_Elven_Quarrels=40,
    Poisoned_Tsurani_Quarrels=41,
    Flaming_Quarrels=42,
    Enchanted_Quarrels=43,
    Standard_Kingdom_Armor=48,
    Gold_Sovereigns=53,
    Silver_Royals=54,
    Bag_of_Grain=60,
    Rations=72,
    Rations_Poisoned=73,
    Rations_Spoiled=74,
    Light_Bowstring=77,
    Picklocks=80,
    Practice_Lute=81,
    Rope=82,
    Shovel=83,
    Torch=84,
    Ring_of_the_Golden_Way=88,
    Vapor_Mask=89,
    Weedwalkers=90,
    Waani=101,
    Wooden_Chest=102,
    Coltari_Poison=105,
    Silverthorn_Anti_Venom=113,
    Restoratives=119,
    Note_=120,
    Abbots_Journal=124,
    Magical_Scroll=133,
    Days_Rations=134,
    Quegian_Brandy=135,
    Keshian_Ale=137
} objectNames;

typedef enum objectTypes {
    Misc=0,
    Sword=1,
    Crossbow=2,
    Staff=3,
    Armor=4,
    Key=7,
    Repair=8,
    Poison=9,
    Enhancer=10,
    ClericalEnhancer=11,
    BowString=12,
    MagicalScroll=13,
    Note=16,
    Book=17,
    Potion=18,
    Restorative=19,
    MassRestorative=20,
    LightSource=21,
    CombatItem=22,
    Food=23,
    Drink=24,
    Usable=25
} objectTypes;

typedef struct overlayStub overlayStub, *PoverlayStub;

struct overlayStub {
    byte trap; /* Overlay manager interrupt */
    undefined field1_0x1;
    word memorySwap; /* Runtime memory swap address */
    dword fileBase; /* Offset in the file to the code */
    word codesize; /* Code size */
    word relsize; /* Relocation area size */
    word nentries; /* Number of overlay entries */
    word probation?; /* Previous stub */
    word heapPointer; /* heap pointer */
    word codeList?; /* Next stub */
    word heapOrg?;
    word heapEnd;
    word __ReadOvrDisk;
    byte flag_field_1A;
    byte loadList?;
    word nextStubSegemnt2?;
    word nextStubSegment?;
};

typedef struct palette palette, *Ppalette;

struct palette {
    struct color colors;
    undefined field1_0x3;
    undefined field2_0x4;
    undefined field3_0x5;
    undefined field4_0x6;
    undefined field5_0x7;
    undefined field6_0x8;
    undefined field7_0x9;
    undefined field8_0xa;
    undefined field9_0xb;
    undefined field10_0xc;
    undefined field11_0xd;
    undefined field12_0xe;
    undefined field13_0xf;
    undefined field14_0x10;
    undefined field15_0x11;
    undefined field16_0x12;
    undefined field17_0x13;
    undefined field18_0x14;
    undefined field19_0x15;
    undefined field20_0x16;
    undefined field21_0x17;
    undefined field22_0x18;
    undefined field23_0x19;
    undefined field24_0x1a;
    undefined field25_0x1b;
    undefined field26_0x1c;
    undefined field27_0x1d;
    undefined field28_0x1e;
    undefined field29_0x1f;
    undefined field30_0x20;
    undefined field31_0x21;
    undefined field32_0x22;
    undefined field33_0x23;
    undefined field34_0x24;
    undefined field35_0x25;
    undefined field36_0x26;
    undefined field37_0x27;
    undefined field38_0x28;
    undefined field39_0x29;
    undefined field40_0x2a;
    undefined field41_0x2b;
    undefined field42_0x2c;
    undefined field43_0x2d;
    undefined field44_0x2e;
    undefined field45_0x2f;
    undefined field46_0x30;
    undefined field47_0x31;
    undefined field48_0x32;
    undefined field49_0x33;
    undefined field50_0x34;
    undefined field51_0x35;
    undefined field52_0x36;
    undefined field53_0x37;
    undefined field54_0x38;
    undefined field55_0x39;
    undefined field56_0x3a;
    undefined field57_0x3b;
    undefined field58_0x3c;
    undefined field59_0x3d;
    undefined field60_0x3e;
    undefined field61_0x3f;
    undefined field62_0x40;
    undefined field63_0x41;
    undefined field64_0x42;
    undefined field65_0x43;
    undefined field66_0x44;
    undefined field67_0x45;
    undefined field68_0x46;
    undefined field69_0x47;
    undefined field70_0x48;
    undefined field71_0x49;
    undefined field72_0x4a;
    undefined field73_0x4b;
    undefined field74_0x4c;
    undefined field75_0x4d;
    undefined field76_0x4e;
    undefined field77_0x4f;
    undefined field78_0x50;
    undefined field79_0x51;
    undefined field80_0x52;
    undefined field81_0x53;
    undefined field82_0x54;
    undefined field83_0x55;
    undefined field84_0x56;
    undefined field85_0x57;
    undefined field86_0x58;
    undefined field87_0x59;
    undefined field88_0x5a;
    undefined field89_0x5b;
    undefined field90_0x5c;
    undefined field91_0x5d;
    undefined field92_0x5e;
    undefined field93_0x5f;
    undefined field94_0x60;
    undefined field95_0x61;
    undefined field96_0x62;
    undefined field97_0x63;
    undefined field98_0x64;
    undefined field99_0x65;
    undefined field100_0x66;
    undefined field101_0x67;
    undefined field102_0x68;
    undefined field103_0x69;
    undefined field104_0x6a;
    undefined field105_0x6b;
    undefined field106_0x6c;
    undefined field107_0x6d;
    undefined field108_0x6e;
    undefined field109_0x6f;
    undefined field110_0x70;
    undefined field111_0x71;
    undefined field112_0x72;
    undefined field113_0x73;
    undefined field114_0x74;
    undefined field115_0x75;
    undefined field116_0x76;
    undefined field117_0x77;
    undefined field118_0x78;
    undefined field119_0x79;
    undefined field120_0x7a;
    undefined field121_0x7b;
    undefined field122_0x7c;
    undefined field123_0x7d;
    undefined field124_0x7e;
    undefined field125_0x7f;
    undefined field126_0x80;
    undefined field127_0x81;
    undefined field128_0x82;
    undefined field129_0x83;
    undefined field130_0x84;
    undefined field131_0x85;
    undefined field132_0x86;
    undefined field133_0x87;
    undefined field134_0x88;
    undefined field135_0x89;
    undefined field136_0x8a;
    undefined field137_0x8b;
    undefined field138_0x8c;
    undefined field139_0x8d;
    undefined field140_0x8e;
    undefined field141_0x8f;
    undefined field142_0x90;
    undefined field143_0x91;
    undefined field144_0x92;
    undefined field145_0x93;
    undefined field146_0x94;
    undefined field147_0x95;
    undefined field148_0x96;
    undefined field149_0x97;
    undefined field150_0x98;
    undefined field151_0x99;
    undefined field152_0x9a;
    undefined field153_0x9b;
    undefined field154_0x9c;
    undefined field155_0x9d;
    undefined field156_0x9e;
    undefined field157_0x9f;
    undefined field158_0xa0;
    undefined field159_0xa1;
    undefined field160_0xa2;
    undefined field161_0xa3;
    undefined field162_0xa4;
    undefined field163_0xa5;
    undefined field164_0xa6;
    undefined field165_0xa7;
    undefined field166_0xa8;
    undefined field167_0xa9;
    undefined field168_0xaa;
    undefined field169_0xab;
    undefined field170_0xac;
    undefined field171_0xad;
    undefined field172_0xae;
    undefined field173_0xaf;
    undefined field174_0xb0;
    undefined field175_0xb1;
    undefined field176_0xb2;
    undefined field177_0xb3;
    undefined field178_0xb4;
    undefined field179_0xb5;
    undefined field180_0xb6;
    undefined field181_0xb7;
    undefined field182_0xb8;
    undefined field183_0xb9;
    undefined field184_0xba;
    undefined field185_0xbb;
    undefined field186_0xbc;
    undefined field187_0xbd;
    undefined field188_0xbe;
    undefined field189_0xbf;
    undefined field190_0xc0;
    undefined field191_0xc1;
    undefined field192_0xc2;
    undefined field193_0xc3;
    undefined field194_0xc4;
    undefined field195_0xc5;
    undefined field196_0xc6;
    undefined field197_0xc7;
    undefined field198_0xc8;
    undefined field199_0xc9;
    undefined field200_0xca;
    undefined field201_0xcb;
    undefined field202_0xcc;
    undefined field203_0xcd;
    undefined field204_0xce;
    undefined field205_0xcf;
    undefined field206_0xd0;
    undefined field207_0xd1;
    undefined field208_0xd2;
    undefined field209_0xd3;
    undefined field210_0xd4;
    undefined field211_0xd5;
    undefined field212_0xd6;
    undefined field213_0xd7;
    undefined field214_0xd8;
    undefined field215_0xd9;
    undefined field216_0xda;
    undefined field217_0xdb;
    undefined field218_0xdc;
    undefined field219_0xdd;
    undefined field220_0xde;
    undefined field221_0xdf;
    undefined field222_0xe0;
    undefined field223_0xe1;
    undefined field224_0xe2;
    undefined field225_0xe3;
    undefined field226_0xe4;
    undefined field227_0xe5;
    undefined field228_0xe6;
    undefined field229_0xe7;
    undefined field230_0xe8;
    undefined field231_0xe9;
    undefined field232_0xea;
    undefined field233_0xeb;
    undefined field234_0xec;
    undefined field235_0xed;
    undefined field236_0xee;
    undefined field237_0xef;
    undefined field238_0xf0;
    undefined field239_0xf1;
    undefined field240_0xf2;
    undefined field241_0xf3;
    undefined field242_0xf4;
    undefined field243_0xf5;
    undefined field244_0xf6;
    undefined field245_0xf7;
    undefined field246_0xf8;
    undefined field247_0xf9;
    undefined field248_0xfa;
    undefined field249_0xfb;
    undefined field250_0xfc;
    undefined field251_0xfd;
    undefined field252_0xfe;
    undefined field253_0xff;
    undefined field254_0x100;
    undefined field255_0x101;
    undefined field256_0x102;
    undefined field257_0x103;
    undefined field258_0x104;
    undefined field259_0x105;
    undefined field260_0x106;
    undefined field261_0x107;
    undefined field262_0x108;
    undefined field263_0x109;
    undefined field264_0x10a;
    undefined field265_0x10b;
    undefined field266_0x10c;
    undefined field267_0x10d;
    undefined field268_0x10e;
    undefined field269_0x10f;
    undefined field270_0x110;
    undefined field271_0x111;
    undefined field272_0x112;
    undefined field273_0x113;
    undefined field274_0x114;
    undefined field275_0x115;
    undefined field276_0x116;
    undefined field277_0x117;
    undefined field278_0x118;
    undefined field279_0x119;
    undefined field280_0x11a;
    undefined field281_0x11b;
    undefined field282_0x11c;
    undefined field283_0x11d;
    undefined field284_0x11e;
    undefined field285_0x11f;
    undefined field286_0x120;
    undefined field287_0x121;
    undefined field288_0x122;
    undefined field289_0x123;
    undefined field290_0x124;
    undefined field291_0x125;
    undefined field292_0x126;
    undefined field293_0x127;
    undefined field294_0x128;
    undefined field295_0x129;
    undefined field296_0x12a;
    undefined field297_0x12b;
    undefined field298_0x12c;
    undefined field299_0x12d;
    undefined field300_0x12e;
    undefined field301_0x12f;
    undefined field302_0x130;
    undefined field303_0x131;
    undefined field304_0x132;
    undefined field305_0x133;
    undefined field306_0x134;
    undefined field307_0x135;
    undefined field308_0x136;
    undefined field309_0x137;
    undefined field310_0x138;
    undefined field311_0x139;
    undefined field312_0x13a;
    undefined field313_0x13b;
    undefined field314_0x13c;
    undefined field315_0x13d;
    undefined field316_0x13e;
    undefined field317_0x13f;
    undefined field318_0x140;
    undefined field319_0x141;
    undefined field320_0x142;
    undefined field321_0x143;
    undefined field322_0x144;
    undefined field323_0x145;
    undefined field324_0x146;
    undefined field325_0x147;
    undefined field326_0x148;
    undefined field327_0x149;
    undefined field328_0x14a;
    undefined field329_0x14b;
    undefined field330_0x14c;
    undefined field331_0x14d;
    undefined field332_0x14e;
    undefined field333_0x14f;
    undefined field334_0x150;
    undefined field335_0x151;
    undefined field336_0x152;
    undefined field337_0x153;
    undefined field338_0x154;
    undefined field339_0x155;
    undefined field340_0x156;
    undefined field341_0x157;
    undefined field342_0x158;
    undefined field343_0x159;
    undefined field344_0x15a;
    undefined field345_0x15b;
    undefined field346_0x15c;
    undefined field347_0x15d;
    undefined field348_0x15e;
    undefined field349_0x15f;
    undefined field350_0x160;
    undefined field351_0x161;
    undefined field352_0x162;
    undefined field353_0x163;
    undefined field354_0x164;
    undefined field355_0x165;
    undefined field356_0x166;
    undefined field357_0x167;
    undefined field358_0x168;
    undefined field359_0x169;
    undefined field360_0x16a;
    undefined field361_0x16b;
    undefined field362_0x16c;
    undefined field363_0x16d;
    undefined field364_0x16e;
    undefined field365_0x16f;
    undefined field366_0x170;
    undefined field367_0x171;
    undefined field368_0x172;
    undefined field369_0x173;
    undefined field370_0x174;
    undefined field371_0x175;
    undefined field372_0x176;
    undefined field373_0x177;
    undefined field374_0x178;
    undefined field375_0x179;
    undefined field376_0x17a;
    undefined field377_0x17b;
    undefined field378_0x17c;
    undefined field379_0x17d;
    undefined field380_0x17e;
    undefined field381_0x17f;
    undefined field382_0x180;
    undefined field383_0x181;
    undefined field384_0x182;
    undefined field385_0x183;
    undefined field386_0x184;
    undefined field387_0x185;
    undefined field388_0x186;
    undefined field389_0x187;
    undefined field390_0x188;
    undefined field391_0x189;
    undefined field392_0x18a;
    undefined field393_0x18b;
    undefined field394_0x18c;
    undefined field395_0x18d;
    undefined field396_0x18e;
    undefined field397_0x18f;
    undefined field398_0x190;
    undefined field399_0x191;
    undefined field400_0x192;
    undefined field401_0x193;
    undefined field402_0x194;
    undefined field403_0x195;
    undefined field404_0x196;
    undefined field405_0x197;
    undefined field406_0x198;
    undefined field407_0x199;
    undefined field408_0x19a;
    undefined field409_0x19b;
    undefined field410_0x19c;
    undefined field411_0x19d;
    undefined field412_0x19e;
    undefined field413_0x19f;
    undefined field414_0x1a0;
    undefined field415_0x1a1;
    undefined field416_0x1a2;
    undefined field417_0x1a3;
    undefined field418_0x1a4;
    undefined field419_0x1a5;
    undefined field420_0x1a6;
    undefined field421_0x1a7;
    undefined field422_0x1a8;
    undefined field423_0x1a9;
    undefined field424_0x1aa;
    undefined field425_0x1ab;
    undefined field426_0x1ac;
    undefined field427_0x1ad;
    undefined field428_0x1ae;
    undefined field429_0x1af;
    undefined field430_0x1b0;
    undefined field431_0x1b1;
    undefined field432_0x1b2;
    undefined field433_0x1b3;
    undefined field434_0x1b4;
    undefined field435_0x1b5;
    undefined field436_0x1b6;
    undefined field437_0x1b7;
    undefined field438_0x1b8;
    undefined field439_0x1b9;
    undefined field440_0x1ba;
    undefined field441_0x1bb;
    undefined field442_0x1bc;
    undefined field443_0x1bd;
    undefined field444_0x1be;
    undefined field445_0x1bf;
    undefined field446_0x1c0;
    undefined field447_0x1c1;
    undefined field448_0x1c2;
    undefined field449_0x1c3;
    undefined field450_0x1c4;
    undefined field451_0x1c5;
    undefined field452_0x1c6;
    undefined field453_0x1c7;
    undefined field454_0x1c8;
    undefined field455_0x1c9;
    undefined field456_0x1ca;
    undefined field457_0x1cb;
    undefined field458_0x1cc;
    undefined field459_0x1cd;
    undefined field460_0x1ce;
    undefined field461_0x1cf;
    undefined field462_0x1d0;
    undefined field463_0x1d1;
    undefined field464_0x1d2;
    undefined field465_0x1d3;
    undefined field466_0x1d4;
    undefined field467_0x1d5;
    undefined field468_0x1d6;
    undefined field469_0x1d7;
    undefined field470_0x1d8;
    undefined field471_0x1d9;
    undefined field472_0x1da;
    undefined field473_0x1db;
    undefined field474_0x1dc;
    undefined field475_0x1dd;
    undefined field476_0x1de;
    undefined field477_0x1df;
    undefined field478_0x1e0;
    undefined field479_0x1e1;
    undefined field480_0x1e2;
    undefined field481_0x1e3;
    undefined field482_0x1e4;
    undefined field483_0x1e5;
    undefined field484_0x1e6;
    undefined field485_0x1e7;
    undefined field486_0x1e8;
    undefined field487_0x1e9;
    undefined field488_0x1ea;
    undefined field489_0x1eb;
    undefined field490_0x1ec;
    undefined field491_0x1ed;
    undefined field492_0x1ee;
    undefined field493_0x1ef;
    undefined field494_0x1f0;
    undefined field495_0x1f1;
    undefined field496_0x1f2;
    undefined field497_0x1f3;
    undefined field498_0x1f4;
    undefined field499_0x1f5;
    undefined field500_0x1f6;
    undefined field501_0x1f7;
    undefined field502_0x1f8;
    undefined field503_0x1f9;
    undefined field504_0x1fa;
    undefined field505_0x1fb;
    undefined field506_0x1fc;
    undefined field507_0x1fd;
    undefined field508_0x1fe;
    undefined field509_0x1ff;
    undefined field510_0x200;
    undefined field511_0x201;
    undefined field512_0x202;
    undefined field513_0x203;
    undefined field514_0x204;
    undefined field515_0x205;
    undefined field516_0x206;
    undefined field517_0x207;
    undefined field518_0x208;
    undefined field519_0x209;
    undefined field520_0x20a;
    undefined field521_0x20b;
    undefined field522_0x20c;
    undefined field523_0x20d;
    undefined field524_0x20e;
    undefined field525_0x20f;
    undefined field526_0x210;
    undefined field527_0x211;
    undefined field528_0x212;
    undefined field529_0x213;
    undefined field530_0x214;
    undefined field531_0x215;
    undefined field532_0x216;
    undefined field533_0x217;
    undefined field534_0x218;
    undefined field535_0x219;
    undefined field536_0x21a;
    undefined field537_0x21b;
    undefined field538_0x21c;
    undefined field539_0x21d;
    undefined field540_0x21e;
    undefined field541_0x21f;
    undefined field542_0x220;
    undefined field543_0x221;
    undefined field544_0x222;
    undefined field545_0x223;
    undefined field546_0x224;
    undefined field547_0x225;
    undefined field548_0x226;
    undefined field549_0x227;
    undefined field550_0x228;
    undefined field551_0x229;
    undefined field552_0x22a;
    undefined field553_0x22b;
    undefined field554_0x22c;
    undefined field555_0x22d;
    undefined field556_0x22e;
    undefined field557_0x22f;
    undefined field558_0x230;
    undefined field559_0x231;
    undefined field560_0x232;
    undefined field561_0x233;
    undefined field562_0x234;
    undefined field563_0x235;
    undefined field564_0x236;
    undefined field565_0x237;
    undefined field566_0x238;
    undefined field567_0x239;
    undefined field568_0x23a;
    undefined field569_0x23b;
    undefined field570_0x23c;
    undefined field571_0x23d;
    undefined field572_0x23e;
    undefined field573_0x23f;
    undefined field574_0x240;
    undefined field575_0x241;
    undefined field576_0x242;
    undefined field577_0x243;
    undefined field578_0x244;
    undefined field579_0x245;
    undefined field580_0x246;
    undefined field581_0x247;
    undefined field582_0x248;
    undefined field583_0x249;
    undefined field584_0x24a;
    undefined field585_0x24b;
    undefined field586_0x24c;
    undefined field587_0x24d;
    undefined field588_0x24e;
    undefined field589_0x24f;
    undefined field590_0x250;
    undefined field591_0x251;
    undefined field592_0x252;
    undefined field593_0x253;
    undefined field594_0x254;
    undefined field595_0x255;
    undefined field596_0x256;
    undefined field597_0x257;
    undefined field598_0x258;
    undefined field599_0x259;
    undefined field600_0x25a;
    undefined field601_0x25b;
    undefined field602_0x25c;
    undefined field603_0x25d;
    undefined field604_0x25e;
    undefined field605_0x25f;
    undefined field606_0x260;
    undefined field607_0x261;
    undefined field608_0x262;
    undefined field609_0x263;
    undefined field610_0x264;
    undefined field611_0x265;
    undefined field612_0x266;
    undefined field613_0x267;
    undefined field614_0x268;
    undefined field615_0x269;
    undefined field616_0x26a;
    undefined field617_0x26b;
    undefined field618_0x26c;
    undefined field619_0x26d;
    undefined field620_0x26e;
    undefined field621_0x26f;
    undefined field622_0x270;
    undefined field623_0x271;
    undefined field624_0x272;
    undefined field625_0x273;
    undefined field626_0x274;
    undefined field627_0x275;
    undefined field628_0x276;
    undefined field629_0x277;
    undefined field630_0x278;
    undefined field631_0x279;
    undefined field632_0x27a;
    undefined field633_0x27b;
    undefined field634_0x27c;
    undefined field635_0x27d;
    undefined field636_0x27e;
    undefined field637_0x27f;
    undefined field638_0x280;
    undefined field639_0x281;
    undefined field640_0x282;
    undefined field641_0x283;
    undefined field642_0x284;
    undefined field643_0x285;
    undefined field644_0x286;
    undefined field645_0x287;
    undefined field646_0x288;
    undefined field647_0x289;
    undefined field648_0x28a;
    undefined field649_0x28b;
    undefined field650_0x28c;
    undefined field651_0x28d;
    undefined field652_0x28e;
    undefined field653_0x28f;
    undefined field654_0x290;
    undefined field655_0x291;
    undefined field656_0x292;
    undefined field657_0x293;
    undefined field658_0x294;
    undefined field659_0x295;
    undefined field660_0x296;
    undefined field661_0x297;
    undefined field662_0x298;
    undefined field663_0x299;
    undefined field664_0x29a;
    undefined field665_0x29b;
    undefined field666_0x29c;
    undefined field667_0x29d;
    undefined field668_0x29e;
    undefined field669_0x29f;
    undefined field670_0x2a0;
    undefined field671_0x2a1;
    undefined field672_0x2a2;
    undefined field673_0x2a3;
    undefined field674_0x2a4;
    undefined field675_0x2a5;
    undefined field676_0x2a6;
    undefined field677_0x2a7;
    undefined field678_0x2a8;
    undefined field679_0x2a9;
    undefined field680_0x2aa;
    undefined field681_0x2ab;
    undefined field682_0x2ac;
    undefined field683_0x2ad;
    undefined field684_0x2ae;
    undefined field685_0x2af;
    undefined field686_0x2b0;
    undefined field687_0x2b1;
    undefined field688_0x2b2;
    undefined field689_0x2b3;
    undefined field690_0x2b4;
    undefined field691_0x2b5;
    undefined field692_0x2b6;
    undefined field693_0x2b7;
    undefined field694_0x2b8;
    undefined field695_0x2b9;
    undefined field696_0x2ba;
    undefined field697_0x2bb;
    undefined field698_0x2bc;
    undefined field699_0x2bd;
    undefined field700_0x2be;
    undefined field701_0x2bf;
    undefined field702_0x2c0;
    undefined field703_0x2c1;
    undefined field704_0x2c2;
    undefined field705_0x2c3;
    undefined field706_0x2c4;
    undefined field707_0x2c5;
    undefined field708_0x2c6;
    undefined field709_0x2c7;
    undefined field710_0x2c8;
    undefined field711_0x2c9;
    undefined field712_0x2ca;
    undefined field713_0x2cb;
    undefined field714_0x2cc;
    undefined field715_0x2cd;
    undefined field716_0x2ce;
    undefined field717_0x2cf;
    undefined field718_0x2d0;
    undefined field719_0x2d1;
    undefined field720_0x2d2;
    undefined field721_0x2d3;
    undefined field722_0x2d4;
    undefined field723_0x2d5;
    undefined field724_0x2d6;
    undefined field725_0x2d7;
    undefined field726_0x2d8;
    undefined field727_0x2d9;
    undefined field728_0x2da;
    undefined field729_0x2db;
    undefined field730_0x2dc;
    undefined field731_0x2dd;
    undefined field732_0x2de;
    undefined field733_0x2df;
    undefined field734_0x2e0;
    undefined field735_0x2e1;
    undefined field736_0x2e2;
    undefined field737_0x2e3;
    undefined field738_0x2e4;
    undefined field739_0x2e5;
    undefined field740_0x2e6;
    undefined field741_0x2e7;
    undefined field742_0x2e8;
    undefined field743_0x2e9;
    undefined field744_0x2ea;
    undefined field745_0x2eb;
    undefined field746_0x2ec;
    undefined field747_0x2ed;
    undefined field748_0x2ee;
    undefined field749_0x2ef;
    undefined field750_0x2f0;
    undefined field751_0x2f1;
    undefined field752_0x2f2;
    undefined field753_0x2f3;
    undefined field754_0x2f4;
    undefined field755_0x2f5;
    undefined field756_0x2f6;
    undefined field757_0x2f7;
    undefined field758_0x2f8;
    undefined field759_0x2f9;
    undefined field760_0x2fa;
    undefined field761_0x2fb;
    undefined field762_0x2fc;
    undefined field763_0x2fd;
    undefined field764_0x2fe;
    undefined field765_0x2ff;
};

typedef struct position3d position3d, *Pposition3d;

struct position3d {
    dword x;
    dword y;
    dword z;
};

typedef enum race {
    None=0,
    Tsurani=1,
    Elf=2,
    Human=3,
    Dwarf=4
} race;

typedef enum resolution {
    _320x150=9830720,
    _320x200=13107520,
    _640x350=22938240
} resolution;

typedef struct resourceFileHandler resourceFileHandler, *PresourceFileHandler;

struct resourceFileHandler {
    word size;
    word readBuffer?;
    word writeBuffer?;
    pointer ReadMethod;
    pointer WriteMethod;
    pointer Method3;
    pointer Method4;
};

typedef struct resourceFileHandlerData resourceFileHandlerData, *PresourceFileHandlerData;

struct resourceFileHandlerData {
    word pBuffer128bytes?;
    dword buffer;
    dword pStream;
    dword amountProcessed?;
    dword sizeInBytes?;
    dword decompressedSize?;
    dword field_16;
    byte field_1A;
    byte field_1B;
    dword offsetInStream;
    byte compressionTypeAndFlags?;
};

typedef struct rmfDictEntry rmfDictEntry, *PrmfDictEntry;

struct rmfDictEntry {
    dword hashKey;
    dword fileOffset;
};

typedef struct RmfEntry RmfEntry, *PRmfEntry;

struct RmfEntry {
    byte fileName;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    byte field_D;
    word index;
    word fp;
    word fileOffset;
    word field_14;
    word field_16;
    pointer32 dictionaryP;
};

typedef struct rotation3d rotation3d, *Protation3d;

struct rotation3d {
    word x;
    word y;
    word z;
};

typedef struct SE SE, *PSE;

struct SE {
    byte calltype;
    byte priority;
    word addrlow;
    word addrhigh;
};

typedef struct SegDef SegDef, *PSegDef;

struct SegDef {
    word segment;
    word size;
    word field_4;
    word field_6;
};

typedef struct shpDat shpDat, *PshpDat;

struct shpDat {
    word creatureNumbers;
    undefined field1_0x2;
    undefined field2_0x3;
    undefined field3_0x4;
    undefined field4_0x5;
    undefined field5_0x6;
    undefined field6_0x7;
};

typedef enum soundEffects {
    sound_crossbow_broken=67
} soundEffects;

typedef struct spellData spellData, *PspellData;

struct spellData {
    word pSpellName;
    word minimumCost;
    word maximumCost;
    word field_6;
    word field_8;
    word field_A;
    word field_C;
    word objectId;
    word calculation;
    word effect;
    word duration;
};

typedef enum spellNames {
    Dragons_Breath=0,
    Dannons_Delusions=1,
    Candle_Glow=2,
    Despair_Thy_Eyes=3,
    Flamecast=4,
    Skyfire=5,
    Hochos_Haven=6,
    Gift_of_Sung=7,
    Scent_of_Sarig=8,
    Bane_of_Black_Slayers=9,
    Eagle_Wing=10,
    Eyes_of_Ishap=11,
    Nightfingers=12,
    Grief_of_1000_Nights=13,
    Mirrorwall=14,
    Touch_of_LimsKragma=15,
    River_Song=16,
    The_Unseen=17,
    Nacre_Cicatrix=18,
    Wrath_of_Killian=19,
    Unfortunate_Flux=20,
    Mad_Gods_Rage=21,
    Mind_Melt=22,
    Skin_of_the_Dragon=23,
    Aether_Bridge=24,
    Steelfire=25,
    Stardusk=26,
    Winds_of_Eortis=27,
    Firestorm=28,
    Gambit_of_the_Eight=29,
    Invitation=30,
    Thoughts_Like_Clouds=31,
    Final_Rest=32,
    Dawn_of_Truth=33,
    Union=34,
    And_the_Light_Shall_Lie=35,
    The_Fetters_of_Rime=36,
    Black_Nimbus=37,
    Arachnos=38,
    Graves_Disquiet=39,
    Asphyxiation=40,
    Thy_Masters_Will=41,
    Strength_Drain=42,
    Summon_Riftmare=43,
    Evil_Seek=44
} spellNames;

typedef struct spellSymbol spellSymbol, *PspellSymbol;

struct spellSymbol {
    word spellNumber;
    word xPosition;
    word yPosition;
    byte character;
};

typedef enum Stat {
    S_IEXEC=64,
    S_IWRITE=128,
    S_IREAD=256,
    S_IFIFO=4096,
    S_IFCHR=8192,
    S_IFBLK=12288,
    S_IFDIR=16384,
    S_IFREG=32768,
    S_IFMT=61440
} Stat;

typedef struct streamInfo streamInfo, *PstreamInfo;

struct streamInfo {
    word stream;
    byte tagString;
    undefined field2_0x3;
    undefined field3_0x4;
    undefined field4_0x5;
    undefined field5_0x6;
    undefined field6_0x7;
    undefined field7_0x8;
    undefined field8_0x9;
    undefined field9_0xa;
    undefined field10_0xb;
    undefined field11_0xc;
    undefined field12_0xd;
    undefined field13_0xe;
    undefined field14_0xf;
    undefined field15_0x10;
    undefined field16_0x11;
    undefined field17_0x12;
    undefined field18_0x13;
    undefined field19_0x14;
    undefined field20_0x15;
    undefined field21_0x16;
    undefined field22_0x17;
    undefined field23_0x18;
    undefined field24_0x19;
    undefined field25_0x1a;
    dword fileSize;
    byte field_1F;
    byte field_20;
    byte field_21;
    byte field_22;
    byte field_23;
    byte field_24;
    byte field_25;
    byte field_26;
    byte field_27;
    byte field_28;
    byte field_29;
    byte field_2A;
    byte field_2B;
    byte field_2C;
    byte field_2D;
    byte field_2E;
    byte field_2F;
    byte field_30;
    byte field_31;
    byte field_32;
    byte field_33;
    byte field_34;
    byte field_35;
    byte field_36;
    word tagLength?;
    word field_39;
    dword currentOffset;
    dword compressedSize?;
};

typedef struct struc_stream struc_stream, *Pstruc_stream;

struct struc_stream {
    word resourceFileNr;
    dword resourceFileOffset;
    dword fileSize;
    dword offsetWithinResource;
    word bool_inUse;
    word fp;
};

typedef enum swingOrThrust {
    swingAttack=0,
    thrustAttack=1
} swingOrThrust;

typedef struct teleportation teleportation, *Pteleportation;

struct teleportation {
    struct location location;
    word gds_number;
    word gds_letter;
};

typedef struct textSlot textSlot, *PtextSlot;

struct textSlot {
    ascii string;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
};

typedef struct tile tile, *Ptile;

struct tile {
    dword field_0;
    word field_4;
    word field_6;
    word field_8;
    word field_A;
};

typedef enum timerFlags {
    timerFlags_1=1,
    timerFlags_2=2,
    timerFlags_4=4,
    timerFlags_8=8,
    timerFlags_10=16,
    timerFlags_20=32,
    timerFlags_40=64,
    timerFlags_Reset=128
} timerFlags;

typedef enum timerKeyLight {
    timerKeyLight_Torch=0,
    timerKeyLight_DragonsBreath=1,
    timerKeyLight_CandleGlow=2,
    timerKeyLight_Stardusk=3
} timerKeyLight;

typedef enum timerKeySpell {
    timerKeySpell_DragonsBreath=0,
    timerKeySpell_CandleGlow=1,
    timerKeySpell_Stardusk=2,
    timerKeySpell_AndTheLightShallLie=3,
    timerKeySpell_Union=4,
    timerKeySpell_ScentOfSarig=5
} timerKeySpell;

typedef enum timerType {
    timerType_Light=1,
    timerType_Spell=2,
    timerType_SetFlag=3,
    timerType_ClearFlag=4
} timerType;

typedef enum times {
    time_1_minute=30,
    time_1_hour=1800,
    time_6_hours=10800,
    time_12_hours=21600,
    time_1_day=43200
} times;

typedef struct trap_element trap_element, *Ptrap_element;

struct trap_element {
    word field_0;
    word type;
    byte grid_x;
    byte grid_y;
};

typedef enum trapElementType {
    trap_element_red_crystal=7,
    trap_element_green_crystal=8,
    trap_element_solid_diamond=9,
    trap_element_passthrough_diamond=10,
    trap_element_cannon=11,
    trap_element_40=40
} trapElementType;

typedef struct uiElement uiElement, *PuiElement;

typedef enum uiElementType {
    uiElementType_ClickArea=0,
    uiElementType_InputField=1,
    uiElementType_FilePicker=2,
    uiElementType_ImageButton=3,
    uiElementType_Toggle=4,
    uiElementType_TextLink=5,
    uiElementType_TextButton=6,
    uiElementType_7=7,
    uiElementType_8=8
} uiElementType;

struct uiElement {
    enum uiElementType type?;
    word action?;
    bool boolVisible?;
    word field_5;
    word field_7;
    word field_9;
    word xPosition;
    word yPosition;
    word width;
    word height;
    word field_13;
    word label;
    word field_17;
    word icon?;
    word cursor?;
    word field_1D_flag;
    word sound;
};

typedef struct unknown_ui_struct_26 unknown_ui_struct_26, *Punknown_ui_struct_26;

struct unknown_ui_struct_26 {
    word xOffset;
    word yOffset;
    word width?;
    word height;
    word field_8;
    word parentX;
    word parentY;
    word field_E;
    word field_10;
    word field_12;
    word field_14;
    word field_16;
    word field_18;
};

typedef struct unknown_ui_struct_33 unknown_ui_struct_33, *Punknown_ui_struct_33;

struct unknown_ui_struct_33 {
    pointer pSomethings;
    word pLabelString;
    word num_something;
    word field_6;
    word field_8;
    word field_A;
    word x?;
    word y?;
    word width?;
    word height?;
    word field_14;
    word field_16;
    byte field_18;
    byte field_19;
    byte field_1A;
    byte field_1B;
    byte field_1C;
    dword pBitmapData?;
};

typedef struct unknown_ui_struct_8 unknown_ui_struct_8, *Punknown_ui_struct_8;

struct unknown_ui_struct_8 {
    word pEntries;
    word num_entries;
    word current_entry?;
    word field_6;
};

typedef struct unknown_ui_struct_xx unknown_ui_struct_xx, *Punknown_ui_struct_xx;

struct unknown_ui_struct_xx {
    byte field_0;
    undefined field1_0x1;
    word field_2;
    word field_4;
    word field_6;
    word field_8;
    word field_A;
};

typedef struct unknownStruct12 unknownStruct12, *PunknownStruct12;

struct unknownStruct12 {
    dword xPosition;
    dword yPosition;
    word zRotation;
    word field_A;
};

typedef struct unknownStruct13 unknownStruct13, *PunknownStruct13;

struct unknownStruct13 {
    byte field_0;
    byte field_1;
    byte field_2;
    byte field_3;
    byte field_4;
    byte field_5;
    byte field_6;
    word field_7;
    word field_9;
    byte field_B;
    byte field_C;
};

typedef struct unknownStruct14 unknownStruct14, *PunknownStruct14;

struct unknownStruct14 {
    word field_0;
    word field_2;
    word field_4;
    dword startTime?;
    dword expiryTime?;
};

typedef struct unknownStruct16 unknownStruct16, *PunknownStruct16;

struct unknownStruct16 {
    pointer32 pWorldItem;
    dword GlobalKey?;
    word x;
    word y;
    word width;
    word height;
};

typedef struct unknownStruct22 unknownStruct22, *PunknownStruct22;

struct unknownStruct22 {
    word field_0;
    pointer worldItem?;
    word field_4;
    word field_6;
    word field_8;
    struct area area;
    word field_12;
    word field_14;
};

typedef struct unknownStruct36 unknownStruct36, *PunknownStruct36;

typedef struct worldItem worldItem, *PworldItem;

struct worldItem {
    word id;
    struct position3d position3d;
    struct rotation3d rotation3d;
    word p350bytes??;
};

struct unknownStruct36 {
    struct worldItem worldItem;
    word field_16;
    word field_18;
    word field_1A;
    word field_1C;
    word field_1E;
    word field_20;
    word field_22;
};

typedef struct unknownStruct48 unknownStruct48, *PunknownStruct48;

struct unknownStruct48 {
    word creatureNumber;
    undefined field1_0x2;
    undefined field2_0x3;
    dword field_4;
    dword field_8;
    word field_C;
    dword field_E;
    undefined field7_0x12;
    undefined field8_0x13;
    undefined field9_0x14;
    undefined field10_0x15;
    undefined field11_0x16;
    undefined field12_0x17;
    undefined field13_0x18;
    undefined field14_0x19;
    undefined field15_0x1a;
    undefined field16_0x1b;
    undefined field17_0x1c;
    undefined field18_0x1d;
    dword field_1E;
    undefined field20_0x22;
    undefined field21_0x23;
    undefined field22_0x24;
    undefined field23_0x25;
    undefined field24_0x26;
    undefined field25_0x27;
    undefined field26_0x28;
    undefined field27_0x29;
    undefined field28_0x2a;
    undefined field29_0x2b;
    undefined field30_0x2c;
    undefined field31_0x2d;
    undefined field32_0x2e;
    byte field_2F;
};

typedef enum WhichValue {
    Effective=0,
    Maximum=1,
    CurrentBase=3,
    Unknown=4
} WhichValue;

typedef struct worldItemFileEntry worldItemFileEntry, *PworldItemFileEntry;

struct worldItemFileEntry {
    word id;
    struct rotation3d rotation;
    struct position3d position;
};

typedef struct worldTile worldTile, *PworldTile;

struct worldTile {
    byte zoneNumber;
    byte xCoordinate;
    byte yCoordinate;
    byte currentTileNr?;
    word nrOfItems;
    dword p300worldItems;
};

typedef struct zoneDataFromSaveGame zoneDataFromSaveGame, *PzoneDataFromSaveGame;

struct zoneDataFromSaveGame {
    word zoneNumber;
    dword field_2;
    dword tempGam_fileOffset;
    dword objFixed_fileOffset;
    dword field_E;
    dword field_12;
};

typedef enum zoneType {
    zoneType_above_ground=0,
    zoneType_unknown=1,
    zoneType_underground=2
} zoneType;

