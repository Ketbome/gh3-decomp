#include "common.h"

struct S2A34F0_1 {
    char pad0[0x20];
    s32 unk20;
};

extern "C" {
extern int D_003301E0[];
extern int D_00330260[];
extern s32 D_00368744[] __attribute__((section(".sdata")));
extern s32 D_003723D8[] __attribute__((section(".sdata")));
extern s32 D_00372EE0;
extern s32 D_00372EF8;
extern s32 D_00372F00;
extern s32 D_00372F08;
extern s32 D_00372F10;
int func_002348A0(void);
void func_00275510(f32);
int func_0027C028(s32, int, void *);
int func_0027D188(int, int, int, int);
int func_0027D268(int, int, int, int);
void func_002A48D0(s32 arg0, s32 arg1);
int func_002A5638(void);
int func_0030A970(void *, s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A32E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_ProfileTasks);

extern "C" s32 CFunc_SetSlomo(s32 arg0) {
    f32 sp0;

    sp0 = 1.0f;
    func_0027D268(arg0, 0, (s32) &sp0, 0);
    func_00275510(sp0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_GetSlomo);

extern "C" s32 CFunc_LaunchScriptDebugger(void) {
    return D_00368744[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A33D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_Debounce);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A34A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_SetSaveZoneNameToCurrent);

extern "C" s32 CFunc_GetSaveZoneName(int arg0, S2A34F0_1 *arg1) {
    func_0027C028(arg1->unk20, 0x20F4889D /* save_zone */, D_003301E0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_DestroyZoneEntities);

extern "C" s32 CFunc_PrintInteractNodeUsers(void) {
    return 0;
}

extern "C" s32 CFunc_CleanupOrphanEntities(void) {
    func_002348A0();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_IsObjectDestructing);

extern "C" s32 CFunc_ForEachPlayer(void) {
    return 1;
}

extern "C" s32 CFunc_ToggleLOD(void) {
    return 1;
}

extern "C" s32 CFunc_ResetWaypoints(void) {
    D_003723D8[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_GetWaypointPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_GetWaypointDir);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_DoesWaypointExist);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3818);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", CFunc_CreateParticleSystem_Fast);

extern "C" s32 CFunc_StartServer(void) {
    return 0;
}

extern "C" s32 CFunc_JoinServer(void) {
    return 0;
}

extern "C" s32 CFunc_breakpoint(void) {
    return 1;
}

extern "C" s32 CFunc_DumpCameraGPU(s32 arg0) {
    s32 sp0;
    func_0027D188(arg0, 0x61414D56 /* STRING */, (s32) &sp0, 0);
    func_0030A970(D_00330260, sp0);
    return 1;
}

extern "C" s32 CFunc_WasMovieAborted(void) {
    return D_00372EE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3EA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A48C0);

extern "C" void func_002A48D0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_00372EF8 = 0x91C1EC93 /* create_model_from_appearance */;
        D_00372F00 = 0xD2C041C2;
        D_00372F08 = 0xAEE1AF7D;
        D_00372F10 = 0xB1A55798;
    }
}

extern "C" void func_002A4920(void) {
    func_002A48D0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4940);

extern "C" s32 CFunc_MC_EnumerateFolders(void) {
    return 1;
}

extern "C" s32 CFunc_MC_CreateFolder(void) {
    return 0;
}

extern "C" s32 CFunc_MC_SetActiveFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_SpaceForNewFile(void) {
    return 0;
}

extern "C" s32 CFunc_MC_SpaceForNewFolder(void) {
    return 0;
}

extern "C" s32 CFunc_MC_TestValidateDiskContents(void) {
    return 1;
}

extern "C" s32 CFunc_MC_LoadTOCInActiveFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_WaitAsyncOpsFinished(void) {
    return 1;
}

extern "C" s32 CFunc_MC_FolderExists(void) {
    return 0;
}

extern "C" s32 CFunc_MC_GetUniqueFolderName(void) {
    return 0;
}

extern "C" s32 CFunc_MC_DeleteFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_HasActiveFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_HasValidatedFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_ClearValidatedFolder(void) {
    return 1;
}

extern "C" s32 CFunc_MC_AsyncOpsFinished(void) {
    return 1;
}

extern "C" void func_002A4A58(void) {
    func_002A5638();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4AF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4D28);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4DB8);
