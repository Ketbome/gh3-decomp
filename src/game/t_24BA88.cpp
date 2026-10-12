#include "common.h"

struct S0024C8A8 {
    char pad[0x8];
    int unk8;
};

extern "C" {
extern void* D_0036E010[] __attribute__((section(".sdata")));
int func_001573D8(void);
extern int D_00370EE0[] __attribute__((section(".sdata")));
void func_002754B0(int);
extern int D_00369A4C[] __attribute__((section(".sdata")));
void func_0016BB28(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_IsInArray);

extern "C" int CFunc_Test(void) {
    return 1;
}

extern "C" int CFunc_DetectOldGlobalReferences(void) {
    return 1;
}

extern "C" int CFunc_EnableLookUpSymbolNotInMainThreadTest(void) {
    return 1;
}

extern "C" int CFunc_SetAsianFontScale(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_EnableDuplicateSymbolWarning);

extern "C" int CFunc_DumpCompositeObjects(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ConvertPippedScriptGlobalToModifiable);

extern "C" int CFunc_DestroyAllParticles(void) {
    if (D_00369A4C[0] != 0) {
        func_0016BB28(D_00369A4C[0]);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_DestroyParticlesByGroupID);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_DestroyAllFastParticles);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Change);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_SetEventHandlerOnObject);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetNode);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetNodeName);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetTriggerNodeName);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetNodeProfileInfo);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_InitCOIM);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ReserveCOIMBlocksForPermObjects);

extern "C" int CFunc_IsCOIMInited(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024C810);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ProximCleanup);

extern "C" int CFunc_Inside(void) {
    return ((S0024C8A8*)D_0036E010[0])->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_LoadQB);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_UnloadQB);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ScreenShot);

extern "C" int CFunc_ResetEngine(void) {
    func_002754B0(D_00370EE0[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ToggleMetrics);

extern "C" int CFunc_GetMetricsMode(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_IsTextureInDictionary);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetRelativePath);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetFileNameFromPath);

extern "C" int CFunc_LoadDBG(void) {
    return 1;
}

extern "C" int CFunc_GetCCallstack(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_StringRemove);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_DisplayLoadingScreen);

extern "C" int CFunc_HideLoadingScreen(void) {
    func_001573D8();
    return 1;
}

extern "C" int CFunc_InitFileCache(void) {
    return 1;
}

extern "C" int CFunc_CachePlatFile(void) {
    return 1;
}

extern "C" int CFunc_CacheFile(void) {
    return 1;
}

extern "C" int CFunc_IsFileCached(void) {
    return 1;
}

extern "C" int CFunc_WaitForFileCache(void) {
    return 1;
}

extern "C" int CFunc_IsFileCacheFinished(void) {
    return 1;
}

extern "C" int CFunc_ResizeFileCacheStreamBuff(void) {
    return 1;
}

extern "C" int CFunc_ToggleFileCaching(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetBuildVersion);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D060);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D068);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D128);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Sin);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Cos);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Tan);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ASin);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ACos);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_ATan);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Sqrt);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Mod);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_NormalizeVector);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetVectorComponents);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_SetVectorComponents);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetAngle);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_RotateVector);
