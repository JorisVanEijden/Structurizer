#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct $7B3C5D519F2E4A5BE311CA6A6DE1B2A0;
struct uiElement;
struct bitmap;
struct container;
struct combatData;
struct bok_page;

/* 1 */
#pragma pack(push, 2)
struct overlayStub
{
    char trap[2];
    int memorySwap;
    __int32 fileBase;
    int codeSize;
    int relSize;
    int nentries;
    int probation_;
    int heapPointer;
    int codeList_;
    int heapOrg_;
    int heapEnd;
    int __ReadOvrDisk;
    char flag_field_1A;
    char loadList_;
    int nextStubSegemnt2_;
    int nextStubSegment_;
};
#pragma pack(pop)

/* 2 */
struct ffblk
{
    char ff_reserved[21];
    char ff_attrib;
    unsigned int ff_ftime;
    unsigned int ff_fdate;
    __int32 ff_fsize;
    char ff_name[13];
};

/* 3 */
struct filebuf;

/* 4 */
#pragma pack(push, 2)
struct SE
{
    char calltype;
    char priority;
    int addrlow;
    int addrhigh;
};
#pragma pack(pop)

/* 7 */
typedef $7B3C5D519F2E4A5BE311CA6A6DE1B2A0 FILE;

/* 19 */
enum FileFlags : __int16
{
    _F_READ = 0x1,
    _F_WRIT = 0x2,
    _F_BUF = 0x4,
    _F_LBUF = 0x8,
    _F_ERR = 0x10,
    _F_EOF = 0x20,
    _F_BIN = 0x40,
    _F_IN = 0x80,
    _F_OUT = 0x100,
    _F_TERM = 0x200,
};

/* 8 */
#pragma pack(push, 2)
struct __attribute__((aligned(2))) $7B3C5D519F2E4A5BE311CA6A6DE1B2A0
{
    int level;
    FileFlags flags;
    char fd;
    unsigned __int8 hold;
    int bsize;
    unsigned __int8 near* buffer;
    unsigned __int8 near* curp;
    unsigned int isTemp;
    int token;
};
#pragma pack(pop)

/* 9 */
enum $FB0B2E4B11C33F202C8E57FBCC18F8B1
{
    altFormatBit = 0x1,
    leftJustBit = 0x2,
    notZeroBit = 0x4,
    fillZerosBit = 0x8,
    isLongBit = 0x10,
    farPtrBit = 0x20,
    alt0xBit = 0x40,
    floatBit = 0x80,
    LongDoubleBit = 0x100,
};

/* 10 */
typedef enum $FB0B2E4B11C33F202C8E57FBCC18F8B1 flagBits;

/* 13 */
typedef unsigned int pascal;

/* 14 */
typedef unsigned int __cdecl __near putnF(const void* ptr, unsigned int n, void* fp);

/* 15 */
enum DisplayCombination : __int8
{
    noDisplay = 0x0,
    monochromeAdapterWithMonochromeDisplay = 0x1,
    CGAWithColorDisplay = 0x2,
    Reserved = 0x3,
    EGAWithColorDisplay = 0x4,
    EGAWithMonochromeDisplay = 0x5,
    PGAWithColorDisplay = 0x6,
    VGAWithMonochromeAnalogDisplay = 0x7,
    VGAWithColorAnalogDisplay = 0x8,
    Reserved2 = 0x9,
    MCGAWithDigitalColorDisplay = 0xA,
    MCGAWithMonochromeAnalogDisplay = 0xB,
    MCGAWithColorAnalogDisplay = 0xC,
    UnknownDisplay = 0xFF,
};

/* 16 */
enum DOSerrorList
{
    e_badFunction = 0x1,
    e_fileNotFound = 0x2,
    e_pathNotFound = 0x3,
    e_tooManyOpen = 0x4,
    e_accessDenied = 0x5,
    e_badHandle = 0x6,
    e_mcbDestroyed = 0x7,
    e_outOfMemory = 0x8,
    e_badBlock = 0x9,
    e_badEnviron = 0xA,
    e_badFormat = 0xB,
    e_badAccess = 0xC,
    e_badData = 0xD,
    e_badDrive = 0xF,
    e_isCurrentDir = 0x10,
    e_notSameDevice = 0x11,
    e_noMoreFiles = 0x12,
    e_readOnly = 0x13,
    e_unknownUnit = 0x14,
    e_notReady = 0x15,
    e_unknownCommand = 0x16,
    e_dataError = 0x17,
    e_badRequestLength = 0x18,
    e_seekError = 0x19,
    e_unknownMedia = 0x1A,
    e_sectorNotFound = 0x1B,
    e_outOfPaper = 0x1C,
    e_writeFault = 0x1D,
    e_readFault = 0x1E,
    e_generalFault = 0x1F,
    e_sharing = 0x20,
    e_lock = 0x21,
    e_diskChange = 0x22,
    e_FCBunavailable = 0x23,
    e_sharingOverflow = 0x24,
    e_networkUnsupported = 0x32,
    e_notListening = 0x33,
    e_dupNameOnNet = 0x34,
    e_nameNotOnNet = 0x35,
    e_netBusy = 0x36,
    e_netDeviceGone = 0x37,
    e_netCommandLimit = 0x38,
    e_netHardError = 0x39,
    e_wrongNetResponse = 0x3A,
    e_netError = 0x3B,
    e_remoteIncompatible = 0x3C,
    e_printQueueFull = 0x3D,
    e_printFileSpace = 0x3E,
    e_printFileDeleted = 0x3F,
    e_netNameDeleted = 0x40,
    e_netAccessDenied = 0x41,
    e_netDeviceWrong = 0x42,
    e_netNameNotFound = 0x43,
    e_netNameLimit = 0x44,
    e_netBIOSlimit = 0x45,
    e_paused = 0x46,
    e_netRequestRefused = 0x47,
    e_redirectionPaused = 0x48,
    e_fileExists = 0x50,
    e_cannotMake = 0x52,
    e_failInt24 = 0x53,
    e_redirectionLimit = 0x54,
    e_dupRedirection = 0x55,
    e_password = 0x56,
    e_parameter = 0x57,
    e_netDevice = 0x58,
    e_dosFinalError = 0x58,
};

/* 17 */
enum FnctlFlags : __int32
{
    O_RDONLY = 0x1,
    O_WRONLY = 0x2,
    O_RDWR = 0x4,
    O_CREAT = 0x100,
    O_TRUNC = 0x200,
    O_EXCL = 0x400,
    _O_RUNFLAGS = 0x700,
    _O_EOF = 0x200,
    O_APPEND = 0x800,
    O_CHANGED = 0x1000,
    O_DEVICE = 0x2000,
    O_TEXT = 0x4000,
    O_BINARY = 0x8000,
    O_NOINHERIT = 0x80,
    O_DENYALL = 0x10,
    O_DENYWRITE = 0x20,
    O_DENYREAD = 0x30,
    O_DENYNONE = 0x40,
};

/* 18 */
enum ioConstants : __int32
{
    _IOFBF = 0x0,
    _IOLBF = 0x1,
    _IONBF = 0x2,
    EOF = 0xFFFF,
    OPEN_MAX = 0x14,
    SYS_OPEN = 0x14,
    BUFSIZ = 0x200,
    L_ctermid = 0x5,
    L_tmpnam = 0xD,
    SEEK_CUR = 0x1,
    SEEK_END = 0x2,
    SEEK_SET = 0x0,
    TMP_MAX = 0xFFFF,
};

/* 20 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) struc_stream
{
    int resourceFileNr;
    __int32 resourceFileOffset;
    __int32 fileSize;
    __int32 offsetWithinResource;
    int bool_inUse;
    int fp;
};
#pragma pack(pop)

/* 21 */
enum Stat : __int32
{
    S_IFMT = 0xF000,
    S_IFDIR = 0x4000,
    S_IFIFO = 0x1000,
    S_IFCHR = 0x2000,
    S_IFBLK = 0x3000,
    S_IFREG = 0x8000,
    S_IREAD = 0x100,
    S_IWRITE = 0x80,
    S_IEXEC = 0x40,
};

/* 22 */
#pragma pack(push, 2)
struct heapHeader
{
    int bsize;
    int prev_real;
    int prev_free;
    int next_free;
};
#pragma pack(pop)

/* 23 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) negativeStatusEffect
{
    char Name[10];
    char field_A;
    int field_B;
    int field_D;
    int bitMaskForAffectedAttributes1;
    int effectOnAttributes1;
    int bitMaskForAffectedAttributes2;
    int effectOnAttributes2;
};
#pragma pack(pop)

/* 24 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) unknownStruct13
{
    char field_0;
    char field_1;
    char field_2;
    char field_3;
    char field_4;
    char field_5;
    char field_6;
    int field_7;
    int field_9;
    char field_B;
    char field_C;
};
#pragma pack(pop)

/* 25 */
#pragma pack(push, 2)
struct SegDef
{
    int segment;
    int size;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 26 */
#pragma pack(push, 2)
struct RmfEntry
{
    char fileName[13];
    char field_D;
    int index;
    int fp;
    int fileOffset;
    int field_14;
    int field_16;
    void* dictionaryP;
};
#pragma pack(pop)

/* 27 */
#pragma pack(push, 2)
struct rmfDictEntry
{
    __int32 hashKey;
    __int32 fileOffset;
};
#pragma pack(pop)

/* 28 */
enum resolution
{
    _320x150 = 0x140,
    _320x200 = 0x140,
    _640x350 = 0x280,
};

/* 29 */
enum memoryLocations
{
    pStream1STDOUT = 0x37E2,
};

/* 30 */
enum MACRO_FA
{
    FA_NORMAL = 0x0,
    FA_RDONLY = 0x1,
    FA_HIDDEN = 0x2,
    FA_SYSTEM = 0x4,
    FA_LABEL = 0x8,
    FA_DIREC = 0x10,
    FA_ARCH = 0x20,
};

/* 31 */
enum MagicConstants
{
    BmxFileSignature = 0x1066,
    ScxFileSignature = 0x27B6,
};

/* 32 */
#pragma pack(push, 2)
struct bmxHeader
{
    int magic;
    int compression;
    size_t amount;
    int compressedDataSize_;
    __int32 nrOfBytes;
};
#pragma pack(pop)

/* 33 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) resourceFileHandlerData
{
    int pBuffer128bytes_;
    __int32 buffer;
    __int32 pStream;
    __int32 amountProcessed_;
    __int32 sizeInBytes_;
    __int32 decompressedSize_;
    __int32 field_16;
    char field_1A;
    char field_1B;
    __int32 offsetInStream;
    char compressionTypeAndFlags_;
};
#pragma pack(pop)

/* 34 */
#pragma pack(push, 2)
struct resourceFileHandler
{
    int size;
    int readBuffer_;
    int writeBuffer_;
    void near* ReadMethod;
    void near* WriteMethod;
    void near* Method3;
    void near* Method4;
};
#pragma pack(pop)

/* 35 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) streamInfo
{
    int stream;
    char tagString[25];
    __int32 fileSize;
    char field_1F;
    char field_20;
    char field_21;
    char field_22;
    char field_23;
    char field_24;
    char field_25;
    char field_26;
    char field_27;
    char field_28;
    char field_29;
    char field_2A;
    char field_2B;
    char field_2C;
    char field_2D;
    char field_2E;
    char field_2F;
    char field_30;
    char field_31;
    char field_32;
    char field_33;
    char field_34;
    char field_35;
    char field_36;
    int tagLength_;
    int field_39;
    __int32 currentOffset;
    __int32 compressedSize_;
};
#pragma pack(pop)

/* 36 */
#pragma pack(push, 2)
struct menuData
{
    int type;
    int isModal;
    int colors_;
    int xPosition;
    int yPosition;
    int width;
    int height;
    int numElements;
    uiElement near* pUiElements[1];
    int pLabel;
    int xOffset;
    int yOffset;
    __int32 pBitmapData;
};
#pragma pack(pop)

/* 189 */
enum uiElementType
{
    uiElementType_ClickArea = 0x0,
    uiElementType_InputField = 0x1,
    uiElementType_FilePicker = 0x2,
    uiElementType_ImageButton = 0x3,
    uiElementType_Toggle = 0x4,
    uiElementType_TextLink = 0x5,
    uiElementType_TextButton = 0x6,
    uiElementType_7 = 0x7,
    uiElementType_8 = 0x8,
};

/* 37 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) uiElement
{
    uiElementType elementType;
    int actionId;
    char visible;
    int colors_;
    int field_7;
    int field_9;
    int xPosition;
    int yPosition;
    int width;
    int height;
    int field_13;
    char near* label;
    int teleport;
    int icon_;
    int cursor_;
    int field_1D_flag;
    int sound;
};
#pragma pack(pop)

/* 38 */
#pragma pack(push, 2)
struct animationRecord
{
    int recordNumber;
    int numberOfPages;
    __int32 pResourceData;
    __int32 pEndOfResourceData;
    bitmap near* pBitmap;
    bitmap near* pBitmap2;
    int field_10;
    int field_12;
    int field_14;
    int pBmImage;
    int font1;
    int font2;
    int font3;
    int font4;
    int font5;
    int font6;
    __int32 palette;
    __int32 field_28;
    __int32 field_2C;
    __int32 field_30;
    __int32 field_34;
    __int32 field_38;
    __int32 field_3C;
    __int32 field_40;
    __int32 field_44;
    __int32 field_48;
    __int32 field_4C;
    __int32 field_50;
    __int32 field_54;
    __int32 field_58;
    __int32 field_5C;
    __int32 field_60;
    __int32 field_64;
    __int32 field_68;
    int field_6C;
    _BYTE gap6E[22];
    int field_84;
    _BYTE gap86[22];
    int field_9C;
    _BYTE gap9E[22];
    int field_B4;
    _BYTE gapB6[22];
    __int32 pNextAnimationRecord;
    __int32 p4bytePageData;
};
#pragma pack(pop)

/* 44 */
#pragma pack(push, 2)
struct bitmap
{
    int imageDataSegment_or_EMS_PageNr;
    int imageDataOffset;
    int flags;
    int Width;
    int Height;
};
#pragma pack(pop)

/* 197 */
enum sceneState
{
    sceneState_0_stopped_ = 0,
    sceneState_1 = 1,
    sceneState_2 = 2,
    sceneState_3 = 3,
    sceneState_4 = 4,
    sceneState_5 = 5,
};

/* 39 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) animationScene
{
    int animationRecordNumber;
    int sceneNumber;
    int startFrame;
    int field_6;
    int endFrame;
    int field_A;
    int field_C;
    int field_E;
    int field_10;
    int field_12;
    int field_14;
    int field_16;
    _BYTE gap18[4];
    int field_1C;
    char field_1E;
    char field_1F;
    char field_20;
    int field_21;
    int screenWidth;
    int field_25;
    int screenHeight;
    int field_29;
    int field_2B;
    int played_;
    sceneState state;
    int field_31;
    __int32 timer__field_33;
    __int32 field_37;
    int nextScene;
};
#pragma pack(pop)

/* 40 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) dialogEntry
{
    char dialogType;
    int actorNr;
    int flag_field_3;
    char branchCount;
    char dialogActionCount;
    int stringLength;
};
#pragma pack(pop)

/* 100 */
enum dialogActionType
{
    unknownAction = 0,
    SetTextVariable = 1,
    GiveItem = 2,
    RemoveItem = 3,
    SetGlobalValue = 4,
    ResizeDialog = 6,
    ApplyCondition = 8,
    ChangeAttribute = 9,
    GetPartyAttribute = 10,
    PlayAudio = 12,
    AdvanceTime = 13,
    PushDialogEntry = 16,
    SetReturnValue = 21,
};

/* 160 */
#pragma pack(push, 2)
struct dialogAction_GiveItem
{
    char objectId;
    char actor;
    int amount;
    int cost;
    int unused;
};
#pragma pack(pop)

/* 161 */
#pragma pack(push, 2)
struct dialogAction_RemoveItem
{
    int objectId;
    int amount;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 162 */
#pragma pack(push, 2)
struct dialogAction_UseItem
{
    int objectId;
    int amount;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 163 */
#pragma pack(push, 2)
struct dialogAction_SetGlobalValue
{
    int key;
    char andMask;
    char orMask;
    char xorMask;
    int value;
};
#pragma pack(pop)

/* 164 */
#pragma pack(push, 2)
struct dialogAction_ChangeParty
{
    int partySize;
    int Actor1;
    int Actor2;
    int Actor3;
};
#pragma pack(pop)

/* 68 */
enum actorAttribute
{
    Health = 0x0,
    Stamina = 0x1,
    Speed = 0x2,
    Strength = 0x3,
    Defense = 0x4,
    AccuracyCrossbow = 0x5,
    AccuracyMelee = 0x6,
    AccuracyCasting = 0x7,
    Assessment = 0x8,
    ArmorCraft = 0x9,
    WeaponCraft = 0xA,
    Barding = 0xB,
    Haggling = 0xC,
    LockPicking = 0xD,
    Scouting = 0xE,
    Stealth = 0xF,
    HealthStaminaCombo = 0x10,
};

/* 165 */
#pragma pack(push, 2)
struct dialogAction_GetAttribute
{
    int target;
    actorAttribute attribute;
    __int32 field_4;
};
#pragma pack(pop)

/* 166 */
#pragma pack(push, 2)
struct dialogAction_ChangeAttribute
{
    char target;
    char type;
    int attribute;
    int minValue;
    int maxValue;
};
#pragma pack(pop)

/* 101 */
enum conditionNumber
{
    condition_sick = 0,
    condition_plagued = 1,
    condition_poisoned = 2,
    condition_drunk = 3,
    condition_healing = 4,
    condition_starving = 5,
    condition_nearDeath = 6,
};

/* 167 */
#pragma pack(push, 2)
struct dialogAction_ApplyCondition
{
    int target;
    conditionNumber condition;
    int minValue;
    int maxValue;
};
#pragma pack(pop)

/* 168 */
#pragma pack(push, 2)
struct dialogAction_Heal
{
    int target;
    int amount;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 169 */
#pragma pack(push, 2)
struct dialogAction_PlayAudio
{
    int audioId;
    int shouldPlay;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 170 */
#pragma pack(push, 2)
struct dialogAction_PlaySound
{
    int audioId;
    int field_2;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 171 */
#pragma pack(push, 2)
struct dialogAction_AdvanceTime
{
    int amount;
    int field_2;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 178 */
#pragma pack(push, 2)
struct dialogAction_SetTemporaryFlag
{
    __int32 globalKey;
    __int32 time;
};
#pragma pack(pop)

/* 174 */
enum timerType : __int8
{
    timerType_Light = 1,
    timerType_Spell = 2,
    timerType_SetFlag = 3,
    timerType_ClearFlag = 4,
};

/* 175 */
enum timerFlags : __int8
{
    timerFlags_1 = 0x1,
    timerFlags_2 = 0x2,
    timerFlags_4 = 0x4,
    timerFlags_8 = 0x8,
    timerFlags_10 = 0x10,
    timerFlags_20 = 0x20,
    timerFlags_40 = 0x40,
    timerFlags_Reset = 0x80,
};

/* 179 */
#pragma pack(push, 2)
struct dialogAction_SetTimer
{
    timerType type;
    timerFlags flag;
    int key;
    __int32 time;
};
#pragma pack(pop)

/* 180 */
#pragma pack(push, 2)
struct dialogAction_LearnSpell
{
    int actor;
    int spellNumber;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 182 */
#pragma pack(push, 2)
struct dialogAction_Teleport
{
    int destinationId;
    int field_2;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 183 */
#pragma pack(push, 2)
struct dialogAction_SubAction
{
    int type;
    int field_2;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 184 */
#pragma pack(push, 2)
struct dialogAction_PushDialogEntry
{
    __int32 offset;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 185 */
#pragma pack(push, 2)
struct dialogAction_SetReturnValue
{
    int value;
    int field_2;
    int field_4;
    int field_6;
};
#pragma pack(pop)

/* 186 */
#pragma pack(push, 2)
struct dialogAction_ResizeDialog
{
    int x;
    int y;
    int width;
    int height;
};
#pragma pack(pop)

/* 159 */
#pragma pack(push, 2)
union dialogActionData
{
    dialogAction_GiveItem giveItem;
    dialogAction_RemoveItem removeItem;
    dialogAction_UseItem useItem;
    dialogAction_SetGlobalValue setGlobalValue;
    dialogAction_ChangeParty changeParty;
    dialogAction_GetAttribute getAttribute;
    dialogAction_ChangeAttribute changeAttribute;
    dialogAction_ApplyCondition applyCondition;
    dialogAction_Heal heal;
    dialogAction_PlayAudio playAudio;
    dialogAction_PlaySound playSound;
    dialogAction_AdvanceTime advanceTime;
    dialogAction_SetTemporaryFlag setTemporaryFlag;
    dialogAction_SetTimer setTimer;
    dialogAction_LearnSpell learnSpell;
    dialogAction_Teleport teleport;
    dialogAction_SubAction subAction;
    dialogAction_PushDialogEntry pushDialogEntry;
    dialogAction_SetReturnValue setReturnValue;
    dialogAction_ResizeDialog resizeDialog;
};
#pragma pack(pop)

/* 41 */
#pragma pack(push, 2)
struct dialogAction
{
    dialogActionType type_;
    dialogActionData action;
};
#pragma pack(pop)

/* 146 */
#pragma pack(push, 2)
struct position3d
{
    __int32 x;
    __int32 y;
    __int32 z;
};
#pragma pack(pop)

/* 145 */
#pragma pack(push, 2)
struct rotation3d
{
    int x;
    int y;
    int z;
};
#pragma pack(pop)

/* 147 */
#pragma pack(push, 2)
struct worldItem
{
    int id;
    position3d position3d;
    rotation3d rotation3d;
    int p350bytes__;
};
#pragma pack(pop)

/* 42 */
#pragma pack(push, 2)
struct unknownStruct36
{
    worldItem worldItem;
    int field_16;
    int field_18;
    int field_1A;
    int field_1C;
    int field_1E;
    int field_20;
    int field_22;
};
#pragma pack(pop)

/* 43 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) dialogBranchData
{
    int globalKey;
    int unknown3;
    int unknown4;
    __int32 offset;
};
#pragma pack(pop)

/* 45 */
#pragma pack(push, 2)
struct labelData
{
    int pString;
    int xPosition;
    int yPosition;
    int attributes;
    char color_;
    char shadowColor_;
};
#pragma pack(pop)

/* 128 */
#pragma pack(push, 2)
struct bok_paragraph
{
    int x_offset;
    int width;
    int lineSpacing;
    int wordSpacing;
    int startIndent;
    int x_offset2;
    int y_offset;
    int alignment;
};
#pragma pack(pop)

/* 129 */
#pragma pack(push, 2)
struct bok_fontInfo
{
    int font;
    int yOffset;
    char field_4;
    __attribute__((aligned(2))) char field_6;
    int fontFlags;
};
#pragma pack(pop)

/* 46 */
#pragma pack(push, 2)
struct bok_data
{
    bok_paragraph paragraph;
    bok_fontInfo fontInfo;
    int bool_field_1A;
    int x_offset2;
    int y_offset;
    int x_offset1;
    int max_x_;
    int field_24;
    int field_26;
    int field_28;
    int field_2A;
    int field_2C;
    int field_2E;
    int field_30;
    int field_32;
    bok_fontInfo* pDataItem;
    bok_fontInfo* field_38;
    __int32 field_3C;
    int pFonts[10];
    int pBitmapResource;
    __int32 pPalette;
    int field_5A;
    int field_5C;
    int field_5E;
    int EmsPageNr1;
    int EmsPageNr2;
};
#pragma pack(pop)

/* 47 */
#pragma pack(push, 2)
struct bNameEntry
{
    char name[4];
    char number;
    _BYTE gap5[2];
    char colorSet_;
};
#pragma pack(pop)

/* 48 */
#pragma pack(push, 2)
struct spellData
{
    int pSpellName;
    int minimumCost;
    int maximumCost;
    int field_6;
    int field_8;
    int field_A;
    int field_C;
    int objectId;
    int calculation;
    int effect;
    int duration;
};
#pragma pack(pop)

/* 50 */
enum configFlags : __int8
{
    soundOn = 0x1,
    musicOn = 0x2,
    combatMusic = 0x4,
    playIntro = 0x8,
    cdmusic_ = 0x10,
};

/* 49 */
#pragma pack(push, 2)
struct config
{
    char stepSize;
    char turnSize;
    char levelOfDetail;
    char textSpeed;
    configFlags flags;
};
#pragma pack(pop)

/* 51 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) location
{
    char zoneNumber_;
    char tileX;
    char tileY;
    char tileXoffset;
    char tileYoffset;
    int zRotation;
};
#pragma pack(pop)

/* 52 */
#pragma pack(push, 2)
struct chapterDataPart1
{
    int ChapterNumber;
    __int32 field_2;
    __int32 field_6;
    __int32 field_A;
    char field_E;
    char field_F;
};
#pragma pack(pop)

/* 53 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) zoneDataFromSaveGame
{
    int zoneNumber;
    __int32 field_2;
    __int32 tempGam_fileOffset;
    __int32 objFixed_fileOffset;
    __int32 field_E;
    __int32 field_12;
};
#pragma pack(pop)

/* 54 */
enum ctypes : __int8
{
    space = 1,
    digit = 2,
    upper = 4,
    lower = 8,
    hexad = 16,
    cntrl = 32,
    punct = 64,
};

/* 56 */
enum ovrResult : __int16
{
    ovrOk = 0,
    ovrNoEMSMemory = -6,
    ovrNoEMSDriver = -5,
    ovrIOError = -4,
    ovrNoMemory = -3,
    ovrNotFound = -2,
    ovrError = -1,
};

/* 58 */
#pragma pack(push, 2)
struct area
{
    int xPosition;
    int yPosition;
    int width;
    int height;
};
#pragma pack(pop)

/* 59 */
#pragma pack(push, 2)
struct dialogTypeData
{
    char field_0;
    char field_1;
    char field_2;
    char field_3;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    char field_8;
    char field_9;
    char field_A;
    char field_B;
    dialogActionData actionData;
};
#pragma pack(pop)

/* 73 */
enum objectFlags : __int16
{
    objectFlags_1h = 0x1,
    NotEquipable = 0x2,
    objectFlags_8h = 0x8,
    objectFlags_10h = 0x10,
    objectFlags_20h = 0x20,
    OnlyUsableInCombat = 0x40,
    Magical = 0x80,
    NotUsableInCombat = 0x100,
    ArchersOnly = 0x200,
    Stackable = 0x800,
    Degradable = 0x1000,
    LimitedUses = 0x2000,
    objectFlags_8000h = 0x8000,
};

/* 61 */
enum race
{
    None = 0x0,
    Tsurani = 0x1,
    Elf = 0x2,
    Human = 0x3,
    Dwarf = 0x4,
};

/* 77 */
enum itemShopCategories
{
    Miscellaneous = 0x1,
    Rations_ = 0x2,
    Jewelry = 0x4,
    Keys = 0x8,
    NotForSale = 0x20,
    CombatItems = 0x40,
    Swords = 0x80,
    RangedWeapons = 0x100,
    Armors = 0x200,
    MagicItems = 0x400,
    Staves = 0x800,
    Spells = 0x1000,
    Books = 0x2000,
    Potions = 0x4000,
    Modifiers = 0x8000,
};

/* 65 */
enum objectTypes
{
    Misc = 0x0,
    Sword = 0x1,
    Crossbow = 0x2,
    Staff = 0x3,
    Armor = 0x4,
    Key = 0x7,
    Repair = 0x8,
    Poison = 0x9,
    Enhancer = 0xA,
    ClericalEnhancer = 0xB,
    BowString = 0xC,
    MagicalScroll = 0xD,
    Note = 0x10,
    Book = 0x11,
    Potion = 0x12,
    Restorative = 0x13,
    MassRestorative = 0x14,
    LightSource = 0x15,
    CombatItem = 0x16,
    Food = 0x17,
    Drink = 0x18,
    Usable = 0x19,
};

/* 60 */
#pragma pack(push, 2)
struct objectInfo
{
    char name[30];
    int field_1E;
    objectFlags objectFlags;
    int wordWrap;
    int chapterNumber;
    int basePrice;
    int swingBase_;
    int thrustBase_;
    int swingAccuracy_armorMod;
    int thrustAccuracy;
    int icon;
    int inventorySlots;
    int soundId_nrOfTimes;
    char maxAmount;
    char field_37;
    race racialMod;
    itemShopCategories shopCategories;
    objectTypes objectType;
    int attributesMask_;
    int effectStrength;
    int field_42;
    int durationInHours_;
    int affectedAttributes;
    int affectedAmount;
    int chanceToDegrade;
    int maxWearAmount;
    int minimumQuality;
};
#pragma pack(pop)

/* 62 */
enum objectNames
{
    Crystal_Staff = 1,
    Lightning_Staff = 2,
    Staff_of_Macros = 4,
    Amulet_of_the_Upright_Man = 5,
    Ring_of_Prandur = 6,
    Brass_Spyglass = 7,
    Cup_of_Rlnn_Skr = 8,
    Eliaems_Heart = 9,
    Glory_Hand = 10,
    Horn_of_Algon_Kokoon = 11,
    Idol_of_Lassur = 12,
    Infinity_Pool = 13,
    Raw_Manna = 14,
    Rorics_Seal = 15,
    Shell = 16,
    Wyverns_Egg = 17,
    Guarda_Revanche = 22,
    Exotic_sword = 23,
    Bessy_Mauler = 32,
    Tsurani_Heavy_Crossbow = 34,
    Quarrels = 36,
    Elven_Quarrels = 37,
    Tsurani_Quarrels = 38,
    Poisoned_Quarrels = 39,
    Poisoned_Elven_Quarrels = 40,
    Poisoned_Tsurani_Quarrels = 41,
    Flaming_Quarrels = 42,
    Enchanted_Quarrels = 43,
    Standard_Kingdom_Armor = 48,
    Gold_Sovereigns = 53,
    Silver_Royals = 54,
    Bag_of_Grain = 60,
    Rations = 72,
    Rations_Poisoned = 73,
    Rations_Spoiled = 74,
    Light_Bowstring = 77,
    Picklocks = 80,
    Practice_Lute = 81,
    Rope = 82,
    Shovel = 83,
    Torch = 84,
    Ring_of_the_Golden_Way = 88,
    Vapor_Mask = 89,
    Weedwalkers = 90,
    Waani = 101,
    Wooden_Chest = 102,
    Coltari_Poison = 105,
    Silverthorn_Anti_Venom = 113,
    Restoratives = 119,
    Note_ = 120,
    Abbots_Journal = 124,
    Magical_Scroll = 133,
    Days_Rations = 134,
    Quegian_Brandy = 135,
    Keshian_Ale = 137,
};

/* 64 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) unknownStruct14
{
    int field_0;
    int field_2;
    int field_4;
    __int32 startTime_;
    __int32 expiryTime_;
};
#pragma pack(pop)

/* 67 */
#pragma pack(push, 2)
struct attributeValues
{
    char max_;
    char current_;
    char currentEffective_;
    char experience;
    char modifier;
};
#pragma pack(pop)

/* 66 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) actor
{
    char near* name;
    int knownSpells1;
    int knownSpells2;
    int knownSpells3;
    attributeValues health;
    attributeValues stamina;
    attributeValues speed;
    attributeValues strength;
    attributeValues defense;
    attributeValues accuracy_crossbow;
    attributeValues accuracy_melee;
    attributeValues accuracy_casting;
    attributeValues assessment;
    attributeValues armorcraft;
    attributeValues weaponcraft;
    attributeValues barding;
    attributeValues haggling;
    attributeValues lockpick;
    attributeValues scouting;
    attributeValues stealth;
    char actorNumber_;
    container* inventory;
    combatData near* pCombatData;
};
#pragma pack(pop)

/* 151 */
#pragma pack(push, 2)
struct containerLocationWorld
{
    char zone;
    char minMaxChapter;
    int worldItemId_;
    __int32 X;
    __int32 Y;
};
#pragma pack(pop)

/* 150 */
#pragma pack(push, 2)
struct containerLocationActor
{
    int field_0;
    int field_2;
    int actorNr;
    int field_6;
    int field_8;
    int field_A;
};
#pragma pack(pop)

/* 152 */
#pragma pack(push, 2)
union containerLocation
{
    containerLocationWorld world;
    containerLocationActor actor;
};
#pragma pack(pop)

/* 153 */
enum containerType : __int8
{
    containerType_0 = 0,
    containerType_inventory = 1,
    containerType_2 = 2,
    containerType_3 = 3,
    containerType_4 = 4,
    containerType_5 = 5,
    containerType_fixedWorldItem = 6,
    containerType_7 = 7,
    containerType_8 = 8,
    containerType_9 = 9,
};

/* 106 */
enum containerDataTypes : __int8
{
    dataType_Lock = 0x1,
    dataType_Dialog = 0x2,
    dataType_Shop = 0x4,
    dataType_Encounter = 0x8,
    dataType_TimeStamp = 0x10,
    dataType_unknown20 = 0x20,
    dataTypeFlag_1 = 0x40,
    dataTypeFlag_2 = 0x80,
};

/* 121 */
#pragma pack(push, 2)
struct containerMetaData
{
    containerLocation location;
    containerType containerType;
    char numberOfItems;
    char capacity;
    containerDataTypes dataTypes;
};
#pragma pack(pop)

/* 76 */
enum itemFlags
{
    item_lit = 0x1,
    itemFlag_unknown2 = 0x2,
    itemFlag_unknown4 = 0x4,
    item_broken = 0x10,
    item_repairable = 0x20,
    item_equipped = 0x40,
    item_poisoned = 0x80,
    item_flaming = 0x100,
    item_steelfired = 0x200,
    item_frosted = 0x400,
    item_enhanced1 = 0x800,
    item_enhanced2 = 0x1000,
    item_blessed1 = 0x2000,
    item_blessed2 = 0x4000,
    item_blessed3 = 0x8000,
};

/* 75 */
#pragma pack(push, 2)
struct inventoryItem
{
    objectNames objectId;
    char variable;
    itemFlags itemFlags;
};
#pragma pack(pop)

/* 78 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) container
{
    char field_0;
    char field_1;
    __int32 offsetInSaveFile;
    containerMetaData metaData;
    inventoryItem items;
};
#pragma pack(pop)

/* 97 */
enum combatStatusFlags : __int8
{
    unknown_combatStatus_1 = 0x1,
    unknown_combatStatus_2 = 0x2,
    unknown_combatStatus_4 = 0x4,
    combatStatus_defending = 0x8,
    unknown_combatStatus_16 = 0x10,
    combatStatus_poisoned = 0x20,
    unknown_combatStatus_64 = 0x40,
    unknown_combatStatus_128 = 0x80,
};

/* 96 */
#pragma pack(push, 2)
struct combatData
{
    actor near* targetActor_;
    int creatureType;
    char x_on_grid;
    char y_on_grid;
    char target_x_on_grid_;
    char target_y_on_grid_;
    combatStatusFlags combatStatus_;
    char field_9;
    int activeSpellEffectSlot_;
    char field_C;
    char field_D;
    char field_E;
    char field_F;
    char field_10;
    char field_11;
    char field_12;
    char field_13;
    char field_14;
    char field_15;
};
#pragma pack(pop)

/* 69 */
enum WhichValue
{
    Effective = 0x0,
    Maximum = 0x1,
    CurrentBase = 0x3,
    Unknown = 0x4,
};

/* 70 */
enum spellNames
{
    Dragons_Breath = 0,
    Dannons_Delusions = 1,
    Candle_Glow = 2,
    Despair_Thy_Eyes = 3,
    Flamecast = 4,
    Skyfire = 5,
    Hochos_Haven = 6,
    Gift_of_Sung = 7,
    Scent_of_Sarig = 8,
    Bane_of_Black_Slayers = 9,
    Eagle_Wing = 10,
    Eyes_of_Ishap = 11,
    Nightfingers = 12,
    Grief_of_1000_Nights = 13,
    Mirrorwall = 14,
    Touch_of_LimsKragma = 15,
    River_Song = 16,
    The_Unseen = 17,
    Nacre_Cicatrix = 18,
    Wrath_of_Killian = 19,
    Unfortunate_Flux = 20,
    Mad_Gods_Rage = 21,
    Mind_Melt = 22,
    Skin_of_the_Dragon = 23,
    Aether_Bridge = 24,
    Steelfire = 25,
    Stardusk = 26,
    Winds_of_Eortis = 27,
    Firestorm = 28,
    Gambit_of_the_Eight = 29,
    Invitation = 30,
    Thoughts_Like_Clouds = 31,
    Final_Rest = 32,
    Dawn_of_Truth = 33,
    Union = 34,
    And_the_Light_Shall_Lie = 35,
    The_Fetters_of_Rime = 36,
    Black_Nimbus = 37,
    Arachnos = 38,
    Graves_Disquiet = 39,
    Asphyxiation = 40,
    Thy_Masters_Will = 41,
    Strength_Drain = 42,
    Summon_Riftmare = 43,
    Evil_Seek = 44,
};

/* 71 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) activeSpellEffect
{
    int SpellNumber_;
    int investedCost;
    int duration;
    int field_6;
    int next;
    char field_A;
};
#pragma pack(pop)

/* 72 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) spellSymbol
{
    int spellNumber;
    int xPosition;
    int yPosition;
    char character;
};
#pragma pack(pop)

/* 74 */
enum attributeFlags
{
    Health_ = 0x1,
    Stamina_ = 0x2,
    Speed_ = 0x4,
    Strength_ = 0x8,
    Defense_ = 0x10,
    AccuracyCrossbow_ = 0x20,
    AccuracyMelee_ = 0x40,
    AccuracyCasting_ = 0x80,
    Assessment_ = 0x100,
    ArmorCraft_ = 0x200,
    WeaponCraft_ = 0x400,
    Barding_ = 0x800,
    Haggling_ = 0x1000,
    LockPicking_ = 0x2000,
    Scouting_ = 0x4000,
    Stealth_ = 0x8000,
};

/* 79 */
#pragma pack(push, 2)
struct color
{
    char red;
    char green;
    char blue;
};
#pragma pack(pop)

/* 80 */
#pragma pack(push, 2)
struct palette
{
    color colors[256];
};
#pragma pack(pop)

/* 81 */
enum def_files : __int16
{
    def_bkgr_dat = 0,
    def_comb_dat = 1,
    def_comm_dat = 2,
    def_dial_dat = 3,
    def_heal_dat = 4,
    def_soun_dat = 5,
    def_town_dat = 6,
    def_trap_dat = 7,
    def_zone_dat = 8,
    def_disa_dat = 9,
    def_enab_dat = 10,
    def_bloc_dat = 11,
};

/* 82 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) def_file_entry_header
{
    int field_0;
    __int32 field_2;
    __int32 dialogId;
};
#pragma pack(pop)

/* 84 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_bkgr
{
    _BYTE gap0[2];
    int field_2;
    _BYTE gap4[2];
    __int32 dialogId;
    _BYTE gapA[4];
    int field_E;
    _BYTE gap10[2];
    char field_12;
    char field_13;
    char field_14;
};
#pragma pack(pop)

/* 85 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_file_struct
{
    def_files type;
    char start_x_;
    char end_y_;
    char end_x_;
    char start_y_;
    __int32 entryNumber;
    char field_A;
    int global_key1;
    int global_key2;
    int global_key3;
    int field_11;
};
#pragma pack(pop)

/* 86 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_dial
{
    char field_0;
    char field_1;
    __int32 dialogId;
    char field_6;
};
#pragma pack(pop)

/* 87 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_town
{
    _BYTE gap0[2];
    int field_2;
    _BYTE gap4[2];
    __int32 dialogId;
    _BYTE gapA[4];
    int field_E;
    _BYTE gap10[2];
    char field_12;
    _BYTE gap13;
    char field_14;
};
#pragma pack(pop)

/* 124 */
#pragma pack(push, 2)
struct Coordinates_64k
{
    __int32 X;
    __int32 Y;
};
#pragma pack(pop)

/* 190 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) unknownStruct339
{
    _BYTE gap0;
    int field_1;
    _BYTE gap3[335];
    char field_152;
};
#pragma pack(pop)

/* 88 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_trap
{
    _BYTE gap0[2];
    __int32 encounterNumber;
    __int32 dialogId1;
    __int32 dialogId2;
    _BYTE gapE[4];
    char field_12;
    _BYTE gap13[9];
    char field_1C;
    _BYTE gap1D[9];
    char field_26;
    _BYTE gap27[9];
    char field_30;
    _BYTE gap31[9];
    Coordinates_64k coordinates;
    int field_42;
    unknownStruct339 struct339;
    int field_197;
};
#pragma pack(pop)

/* 89 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_zone
{
    _BYTE gap0[2];
    location location;
    __int32 dialogId1;
    __int32 dialogId2;
    _BYTE gap11;
    char field_12;
};
#pragma pack(pop)

/* 90 */
#pragma pack(push, 2)
struct def_bloc
{
    _BYTE gap0[2];
    __int32 dialogId;
    _BYTE gap6;
    char field_7;
};
#pragma pack(pop)

/* 91 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_enab
{
    char field_0;
    char field_1;
    char chance;
    int global_key;
    char field_5;
    char field_6;
};
#pragma pack(pop)

/* 92 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_disa
{
    char field_0;
    char field_1;
    char chance;
    int global_key;
    char field_5;
    char field_6;
};
#pragma pack(pop)

/* 93 */
#pragma pack(push, 2)
struct unknownStruct22
{
    int field_0;
    worldItem near* worldItem_;
    int field_4;
    int field_6;
    int field_8;
    area area;
    int field_12;
    int field_14;
};
#pragma pack(pop)

/* 94 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_soun
{
    char field_0;
    char field_1;
    char chance;
    int aoudioId_;
    char field_5;
    char field_6;
};
#pragma pack(pop)

/* 95 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) def_comb
{
    int field_0;
    __int32 encounterNumber;
    __int32 dialogId1;
    __int32 dialogId2;
    _BYTE gapE;
    int globalKey;
    _BYTE gap11;
    int field_12;
    _BYTE gap14[8];
    int field_1C;
    _BYTE gap1E[8];
    int field_26;
    _BYTE gap28[8];
    int field_30;
    _BYTE gap32[8];
    char field_3A;
    int monsterNumber_;
    _BYTE gap3D[336];
    int field_18D;
};
#pragma pack(pop)

/* 98 */
enum mnames : __int16
{
    Gorath = 0xF,
    Owyn = 0x10,
    Locklear = 0x11,
    moredhel_warrior = 0x12,
    Brak_Nurr = 0x13,
    moredhel_spellcaster = 0x15,
    Black_Slayer = 0x16,
    Nighthawk = 0x17,
    rogue = 0x18,
    Pantathian = 0x19,
    Panth_Tiandn = 0x1A,
    Spellweaver = 0x1B,
    Servitor_of_LimsKragma = 0x1C,
    Tor_Giant = 0x1D,
    Rogue_Mage = 0x1E,
    Deep_Giant = 0x1F,
    Cave_Giant = 0x20,
    Rime_Giant = 0x21,
    Sentinel_Ogre = 0x22,
    Highland_Ogre = 0x25,
    scorpion = 0x27,
    Bulldrake_Wyvern = 0x29,
    Grandsire_Wyvern = 0x2A,
    Hatchling_Wyvern = 0x2B,
    spider = 0x2C,
    Pug = 0x2D,
    beasthound = 0x2E,
    Patrus = 0x2F,
    troll = 0x30,
    Dread = 0x31,
    James = 0x33,
    Witch_Hag = 0x34,
    goblin = 0x35,
    Wind_Elemental = 0x36,
    Quegian_pirate = 0x37,
    Rusalki = 0x38,
    Shade = 0x39,
    Nethermander = 0x3A,
    Great_One = 0x3D,
    moredhel_spellcaster2 = 0x3F,
    no_creature = 0xFFFF,
};

/* 99 */
enum direction : __int16
{
    N = 0,
    NE = 1,
    E = 2,
    SE_ = 3,
    S = 4,
    SW = 5,
    W = 6,
    NW = 7,
    X_0 = -1,
    X = -1,
};

/* 102 */
#pragma pack(push, 2)
struct actorStatusEffects
{
    char sick;
    char plagued;
    char poisoned;
    char drunk;
    char healing;
    char starving;
    char nearDeath;
};
#pragma pack(pop)

/* 103 */
enum currency
{
    currency_gold_fractional = 0,
    currency_gold_silver = 1,
    currency_sovereigns_royals = 2,
};

/* 104 */
#pragma pack(push, 2)
struct textSlot
{
    char string[32];
};
#pragma pack(pop)

/* 105 */
enum mainCharacter : __int8
{
    Character_Locklear = 0,
    Character_Gorath = 1,
    Character_Owyn = 2,
    Character_Pug = 3,
    Character_James = 4,
    Character_Patrus = 5,
};

/* 107 */
#pragma pack(push, 2)
struct containerData_shop
{
    char field_0;
    char markupPercentage;
    char field_2;
    char markDownPercentage;
    char field_4;
    char field_5;
    char bardingDifficulty;
    char bardingReward;
    char field_8;
    char field_9;
    char field_A;
    char field_B;
    char field_C;
    char field_D;
    itemShopCategories shopCategories;
};
#pragma pack(pop)

/* 108 */
#pragma pack(push, 2)
struct containerData_lock
{
    char flags;
    char difficulty;
    char puzzleChest;
    char trapDamage;
};
#pragma pack(pop)

/* 109 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) containerData_encounter
{
    int globalDataKey1;
    int globalDataKey2;
    char gds_number_;
    char gds_letter_;
    char field_6;
    char x;
    char y;
};
#pragma pack(pop)

/* 110 */
#pragma pack(push, 2)
struct mousePointer
{
    int x;
    int y;
    int xOffset_;
    int yOffset_;
    int CursorImageWidth;
    int CursorImageHeight;
    int imageNumber_;
};
#pragma pack(pop)

/* 111 */
enum swingOrThrust
{
    swingAttack = 0x0,
    thrustAttack = 0x1,
};

/* 112 */
enum soundEffects
{
    sound_crossbow_broken = 0x43,
};

/* 114 */
#pragma pack(push, 2)
struct def_comm
{
    char field_0;
    char field_1;
    char field_2;
    char field_3;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    char field_8;
    char field_9;
};
#pragma pack(pop)

/* 115 */
enum gameObjectType
{
    gameObjectType_0 = 0x0,
    gameObjectType_1 = 0x1,
    gameObjectType_actor = 0x2,
    gameObjectType_combatData = 0x3,
    gameObjectType_container = 0x4,
    gameObjectType_none = 0xFFFF,
};

/* 116 */
#pragma pack(push, 2)
struct enemyParty
{
    void near* pEnemyActor[7];
};
#pragma pack(pop)

/* 117 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) worldTile
{
    char zoneNumber;
    char xCoordinate;
    char yCoordinate;
    char currentTileNr_;
    int nrOfItems;
    __int32 p300worldItems;
};
#pragma pack(pop)

/* 118 */
#pragma pack(push, 2)
struct unknownStruct12
{
    __int32 xPosition;
    __int32 yPosition;
    int zRotation;
    int field_A;
};
#pragma pack(pop)

/* 119 */
#pragma pack(push, 2)
struct worldItemFileEntry
{
    int id;
    rotation3d rotation;
    position3d position;
};
#pragma pack(pop)

/* 120 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) containerData_dialog
{
    char field_0;
    char flag_field_1;
    __int32 dialogId;
};
#pragma pack(pop)

/* 122 */
#pragma pack(push, 2)
struct unknownStruct16
{
    worldItem* pWorldItem;
    __int32 GlobalKey_;
    int x;
    int y;
    int width;
    int height;
};
#pragma pack(pop)

/* 123 */
#pragma pack(push, 2)
struct tile
{
    __int32 field_0;
    int field_4;
    int field_6;
    int field_8;
    int field_A;
};
#pragma pack(pop)

/* 125 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) bok_pageList
{
    int nrOfPages;
    bok_page* pBokPage;
};
#pragma pack(pop)

/* 127 */
#pragma pack(push, 2)
struct __attribute__((aligned(2))) bok_imageInfo
{
    int x_offset;
    int y_offset;
    int width_or_imageNumber;
    int height_or_orientation;
};
#pragma pack(pop)

/* 126 */
#pragma pack(push, 2)
struct bok_page
{
    int x_offset;
    int y_offset;
    int width;
    int height;
    int pageRelatedNumber_;
    int pageNumber;
    int previousPageNumber;
    int nextPageNumber;
    int nextPage_;
    int field_12;
    int nrOfImages;
    int nrOfReservedAreas_;
    int showPageNumber;
    __int32 field_1A;
    bok_paragraph paragraph;
    bok_fontInfo fontInfo;
    bok_imageInfo imageInfos;
};
#pragma pack(pop)

/* 132 */
#pragma pack(push, 2)
struct bok_dataItem
{
    char type;
    char data[];
};
#pragma pack(pop)

/* 133 */
enum zoneType
{
    zoneType_above_ground = 0x0,
    zoneType_unknown = 0x1,
    zoneType_underground = 0x2,
};

/* 134 */
enum times : __int32
{
    time_1_minute = 30,
    time_1_hour = 1800,
    time_6_hours = 10800,
    time_12_hours = 21600,
    time_1_day = 43200,
};

/* 136 */
#pragma pack(push, 2)
struct gds_struct36
{
    int xPos;
    int yPos;
    int width;
    int height;
    int field_8_flag;
    int field_A;
    char field_C;
    char field_D;
    int field_E;
    int field_10;
    __int32 dialogId1;
    __int32 dialogId2;
    __int32 pDialogEntry;
    int globalKey;
    int minGlobalValue_;
    int maxGlobalValue_;
};
#pragma pack(pop)

/* 135 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) gds
{
    char label[13];
    int field_D_flag;
    int field_F;
    int song;
    int field_13;
    int field_15;
    int field_17;
    int field_19;
    int num_something;
    __int32 dialogId;
    __int32 pDialogEntry;
    container* pContainer;
    gds_struct36 field_29;
};
#pragma pack(pop)

/* 137 */
#pragma pack(push, 2)
struct unknown_ui_struct_8
{
    int pEntries;
    int num_entries;
    int current_entry_;
    int field_6;
};
#pragma pack(pop)

/* 138 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) unknown_ui_struct_33
{
    void near* pSomethings;
    int pLabelString;
    int num_something;
    int field_6;
    int field_8;
    int field_A;
    int x_;
    int y_;
    int width_;
    int height_;
    int field_14;
    int field_16;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    char field_1C;
    __int32 pBitmapData_;
};
#pragma pack(pop)

/* 139 */
#pragma pack(push, 2)
struct unknown_ui_struct_xx
{
    char field_0;
    int field_2;
    int field_4;
    int field_6;
    int field_8;
    int field_A;
};
#pragma pack(pop)

/* 140 */
#pragma pack(push, 2)
struct keyword
{
    int number;
    char near* pString;
};
#pragma pack(pop)

/* 141 */
#pragma pack(push, 2)
struct combatGridCell
{
    actor near* pActor;
    int grid_element;
    int value_;
};
#pragma pack(pop)

/* 142 */
#pragma pack(push, 2)
struct trap_element
{
    int field_0;
    int type;
    char grid_x;
    char grid_y;
};
#pragma pack(pop)

/* 143 */
enum gridElementType
{
    grid_element_damaging_ = 0x1,
    grid_element_out_of_bounds_ = 0x2,
    grid_element_trap_crystal = 0x3,
    grid_element_unknown_4 = 0x4,
    grid_element_trap_diamond = 0x5,
    grid_element_exit = 0x6,
    grid_element_unknown_7 = 0x7,
    grid_element_unknown_8 = 0x8,
    grid_element_unknown_9 = 0x9,
    grid_element_cannon_west = 0xA,
    grid_element_cannon_east = 0xB,
    grid_element_cannon_north = 0xC,
    grid_element_cannon_south = 0xD,
    grid_element_actor_2 = 0xF,
    grid_element_actor_1 = 0x10,
    grid_element_actor_0 = 0x11,
};

/* 144 */
enum trapElementType
{
    trap_element_red_crystal = 0x7,
    trap_element_green_crystal = 0x8,
    trap_element_solid_diamond = 0x9,
    trap_element_passthrough_diamond = 0xA,
    trap_element_cannon = 0xB,
    trap_element_40 = 0x28,
};

/* 148 */
#pragma pack(push, 2)
struct containerData_timestamp
{
    __int32 double_seconds;
};
#pragma pack(pop)

/* 149 */
#pragma pack(push, 2)
struct containerData_unknown20
{
    int field_0;
};
#pragma pack(pop)

/* 154 */
enum interactable
{
    interactable_bush_food = 26,
    interactable_bush_poison = 27,
    interactable_bush_healing = 28,
};

/* 155 */
enum lockFlags
{
    lock_trapped = 0x4,
};

/* 156 */
#pragma pack(push, 2)
struct unknown_ui_struct_26
{
    int xOffset;
    int yOffset;
    int width_;
    int height;
    int field_8;
    int parentX;
    int parentY;
    int field_E;
    int field_10;
    int field_12;
    int field_14;
    int field_16;
    int field_18;
};
#pragma pack(pop)

/* 157 */
enum gameDataOffset
{
    gameDataOffset_Actors = 0xAD7,
    gameDataOffset_GoldPerChapter = 0x12F7,
    gameDataOffset_Encounter7EnemyPointers = 0x131F,
};

/* 172 */
#pragma pack(push, 2)
struct actorFaces
{
    int actorNumber[6];
    int pBitmap[6];
    __int32 pPalette[6];
};
#pragma pack(pop)

/* 173 */
#pragma pack(push, 2)
struct expiry_timer
{
    timerType type;
    char flag;
    int key;
    __int32 time;
};
#pragma pack(pop)

/* 176 */
enum timerKeySpell
{
    timerKeySpell_DragonsBreath = 0x0,
    timerKeySpell_CandleGlow = 0x1,
    timerKeySpell_Stardusk = 0x2,
    timerKeySpell_AndTheLightShallLie = 0x3,
    timerKeySpell_Union = 0x4,
    timerKeySpell_ScentOfSarig = 0x5,
};

/* 177 */
enum timerKeyLight
{
    timerKeyLight_Torch = 0x0,
    timerKeyLight_DragonsBreath = 0x1,
    timerKeyLight_CandleGlow = 0x2,
    timerKeyLight_Stardusk = 0x3,
};

/* 181 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(1))) teleportation
{
    location location;
    int gds_number;
    int gds_letter;
};
#pragma pack(pop)

/* 187 */
enum keyboard
{
    keyboard_escape = 0x1,
    keyboard_backspace = 0xE,
    keyboard_tab = 0xF,
    keyboard_P = 0x19,
    keyboard_enter = 0x1C,
    keyboard_left_control = 0x1D,
    keyboard_backtick = 0x29,
    keyboard_left_shift = 0x2A,
    keyboard_N = 0x31,
    keyboard_right_shift = 0x36,
    keyboard_left_alt = 0x38,
    keyboard_space = 0x39,
    keyboard_numlock = 0x45,
    keyboard_scrollock = 0x46,
    keyboard_numpad_7 = 0x47,
    keyboard_numpad_8 = 0x48,
    keyboard_numpad_4 = 0x4B,
    keyboard_numpad_5 = 0x4C,
    keyboard_numpad_6 = 0x4D,
    keyboard_numpad_plus = 0x4E,
    keyboard_numpad_1 = 0x4F,
    keyboard_numpad_2 = 0x50,
    keyboard_numpad_0 = 0x52,
    keyboard_numpad_dot = 0x53,
};

/* 188 */
enum mouseButton
{
    mouseButton_left = 0,
    mouseButton_right = 1,
};

/* 191 */
#pragma pack(push, 2)
struct unknownStruct48
{
    mnames creatureNumber;
    __attribute__((aligned(4))) __int32 field_4;
    __int32 field_8;
    int field_C;
    __int32 field_E[4];
    __int32 field_1E[4];
    _BYTE gap2E;
    char field_2F;
};
#pragma pack(pop)

/* 192 */
#pragma pack(push, 2)
struct shpDat
{
    mnames creatureNumbers[4];
};
#pragma pack(pop)

/* 193 */
#pragma pack(push, 2)
struct enemyStruct6
{
    int field_0;
    int field_2;
    int field_4;
};
#pragma pack(pop)

/* 194 */
#pragma pack(push, 2)
struct __attribute__((packed)) __attribute__((aligned(2))) animBigStruct
{
    int initialized_;
    int amount_field_2;
    __int32 pSCRBuffer;
    __int32 pEndOfSCRBuffer;
    __int32 pAnimationRecordLinkedList;
    int pAnimationSceneLinkedList;
    int array_80_words_field_12[80];
    int array_80_words_field_B2[80];
    __int32 array_80_pAdsCommand[80];
    __int32 array_80_dwords_field_292[80];
    int array_80_words_scene_list[80];
};
#pragma pack(pop)

/* 195 */
enum adsCommand
{
    adsCommand_0001 = 0x1,
    adsCommand_0005 = 0x5,
    adsCommand_1010 = 0x1010,
    adsCommand_1020 = 0x1020,
    adsCommand_1030 = 0x1030,
    adsCommand_1040 = 0x1040,
    adsCommand_1050 = 0x1050,
    adsCommand_1060 = 0x1060,
    adsCommand_1070 = 0x1070,
    adsCommand_1080 = 0x1080,
    adsCommand_1310 = 0x1310,
    adsCommand_1320 = 0x1320,
    adsCommand_1330 = 0x1330,
    adsCommand_1340 = 0x1340,
    adsCommand_1350 = 0x1350,
    adsCommand_1360 = 0x1360,
    adsCommand_1370 = 0x1370,
    ads_variable_LE_param1 = 0x1380,
    ads_variable_GE_param1 = 0x1390,
    ads_chapter_LE_param1 = 0x13A0,
    ads_var2_LE_param1 = 0x13A1,
    ads_chapter_GE_param1 = 0x13B0,
    ads_var2_GE_param1 = 0x13B1,
    ads_chapter_EQ_param1 = 0x13C0,
    ads_var2_EQ_param1 = 0x13C1,
    adsCommand_1420 = 0x1420,
    adsCommand_1430 = 0x1430,
    adsCommand_1500 = 0x1500,
    adsCommand_1510 = 0x1510,
    adsCommand_1520 = 0x1520,
    adsCommand_2000 = 0x2000,
    adsCommand_2005 = 0x2005,
    adsCommand_2010 = 0x2010,
    adsCommand_2015 = 0x2015,
    adsCommand_2020 = 0x2020,
    adsCommand_3010 = 0x3010,
    adsCommand_3020 = 0x3020,
    adsCommand_30FF = 0x30FF,
    adsCommand_4000 = 0x4000,
    adsCommand_4010 = 0x4010,
    adsCommand_F000 = 0xF000,
    adsCommand_F010 = 0xF010,
    adsCommand_F200 = 0xF200,
    adsCommand_F210 = 0xF210,
    adsCommand_FFFF = 0xFFFF,
};

/* 196 */
#pragma pack(push, 2)
struct ads_command
{
    int function;
    int param1;
    int param2;
    int param3;
    int param4;
};
#pragma pack(pop)