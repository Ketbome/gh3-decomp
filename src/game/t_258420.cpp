#include "common.h"

struct S00259228 {
    char pad[0x20];
    int unk20;
};

extern "C" {
int func_0028A010(int);
int func_0028A018(int);
void func_00258E28(int, int);
int func_0027DF00(int, u32);
extern int D_00368428[] __attribute__((section(".sdata")));
void func_002592E0(void*, int, int, int);
int func_0027D470(int, int, void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GetRandomArrayElement);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_PermuteArray);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GotParam);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_Goto);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258A00);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258E28);

extern "C" int CFunc_FormatText(int a, S00259228* b) {
    func_00258E28(b->unk20, a);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ExtendCrc);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002592E0);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_EnableScriptPrintf);

extern "C" int CFunc_Printf(void) {
    return 1;
}

extern "C" int CFunc_SetGlobalPrintfEnabledStatus(int a) {
    D_00368428[0] = func_0027DF00(a, 0x203B372);
    return 1;
}

extern "C" int CFunc_PrintStruct(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_Dump);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ScriptAssert);

extern "C" int CFunc_SoftAssert(int a, int b) {
    char buf[0x400];
    func_002592E0(buf, 0x400, a, b);
    return 1;
}

extern "C" int CFunc_ScriptUsageSoftAssert(void) {
    return 1;
}

extern "C" int CFunc_PrintScriptInfo(void) {
    return 1;
}

extern "C" int CFunc_IfDebugOn(int a, int b) {
    func_0028A010(b);
    return 1;
}

extern "C" int CFunc_IfDebugOff(int a, int b) {
    func_0028A018(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_StructureContains);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_MangleChecksums);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_AppendSuffixToChecksum);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GetUpperCaseString);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GetLowerCaseString);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GenerateUTF16FromASCII);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ScriptExists);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_SymbolIsCFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ScriptIsRunning);

extern "C" int CFunc_IsArray(int a) {
    int x = 0;
    return func_0027D470(a, 0, &x, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259E40);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_IsPair);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_IsStructure);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_Block);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_IsTrue);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_AddFlag);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_CleanUpAndRemoveSymbol);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_SetEventHandler);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_SetExceptionHandler);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ResetEventHandlersFromTable);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ClearEventHandler);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ClearEventHandlerGroup);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_OnExceptionRun);
