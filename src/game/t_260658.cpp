#include "common.h"

struct S002606A0 {
    char pad[0xA0];
    int unkA0;
};

struct S00261B58 {
    char pad[0x23C];
    int unk23C;
};

struct S00260710 {
    char pad[0x18];
    int unk18;
};

struct S00261C98_2 {
    struct S00261C98_2* unk0;
    struct S00261C98_2* unk4;
};

struct S00261C98 {
    int unk0;
    S00261C98_2 unk4;
};

extern "C" {
extern int D_00368748;
extern int D_00368750;
extern int D_003706D8;
extern void* D_0036F658[] __attribute__((section(".sdata")));
extern void* D_00368A38[] __attribute__((section(".sdata")));
extern int D_00368768[] __attribute__((section(".sdata")));
int func_00289CF8(int);
void func_00261C98(int, int);
extern u64 D_003706C8;
void func_00317298(u64);
extern int D_003717E0[] __attribute__((section(".sdata")));
void func_00296550(int);
extern int D_00372580[] __attribute__((section(".sdata")));
void func_001CA9B0(int);
u64 func_00317588(void);
extern u64 D_003706D0;
extern S00261C98 D_0039A3C8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_AllowAssetLoading);

extern "C" int CFunc_AreAssetsLocked(void) {
    return ((S002606A0*)D_0036F658[0])->unkA0 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_PushAssetContext);

extern "C" int CFunc_PopAssetContext(void) {
    ((S00260710*)D_0036F658[0])->unk18--;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetSearchAllAssetContexts);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260778);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_Randomize);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_ResetTimer);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TimeGreaterThan);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002608C0);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetStartTime);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetTrueStartTime);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetMicroseconds);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_ResetSongTimer);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_IncrementSongTimer);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetSongTime);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetSongTimeMs);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetLocalSystemTime);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetDeltaTime);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetDeltaTime);

extern "C" int CFunc_PrintTime(void) {
    return 1;
}

extern "C" void func_00260D08(void) {
    func_00317298(D_003706C8);
}

extern "C" void func_00260D28(void) {
    u64 r = func_00317588();
    D_003706D8 = 0;
    D_003706C8 = r;
    D_003706D0 = r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260D50);

extern "C" void func_00260D88(void) {
    D_003706D8 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260D98);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TimeMarkerReached_SetParams);

extern "C" int CFunc_TimeMarkerReached_ClearParams(int a, int b) {
    func_00289CF8(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TimeMarkerReached);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261090);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_OnServer);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002610C0);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetNetworkMode);

extern "C" int CFunc_UseNetworkPreferences(void) {
    func_001CA9B0(D_00372580[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TestNetSetup);

extern "C" void CFunc_NeedToTestNetSetup(void) {
    func_00296550(D_003717E0[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_LoadNetworkDrivers);

extern "C" int CFunc_InNetGame(void) {
    return 0;
}

extern "C" int CFunc_IsObserving(void) {
    return 0;
}

extern "C" int CFunc_IsSurveying(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SkatersAreReady);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetServerMode);

extern "C" int CFunc_GameIsOver(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002614E8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetConfig);

extern "C" int CFunc_PrintConfig(void) {
    return 1;
}

extern "C" int CFunc_CD(void) {
    return D_00368748;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_NotCD);

extern "C" int CFunc_Bootstrap(void) {
    return D_00368750;
}

extern "C" int CFunc_PAL(void) {
    return 0;
}

extern "C" int CFunc_IsPal(void) {
    return D_00368768[0] == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_GetTerritory);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_AddToCutsceneDestroyList);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_RemoveFromCutsceneDestroyList);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_FlushCutsceneDestroyList);

extern "C" int CFunc_CutsceneDestroyListActive(void) {
    return ((S00261B58*)D_00368A38[0])->unk23C != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261B70);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_PlayCutscene);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261C90);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261C98);

extern "C" void func_00261CC8(void) {
    func_00261C98(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_CenterCamera);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetMovementVelocity);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_SetRotateVelocity);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_LaunchViewer);
