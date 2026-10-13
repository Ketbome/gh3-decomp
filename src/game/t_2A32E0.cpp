#include "common.h"

struct S2A34F0_1 {
    char pad0[0x20];
    s32 unk20;
};

struct S2A49_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char *vptr;
};

struct S2A3_Ent {
    char pad0[0x14];
    S2A3_Ent *next;
};

extern "C" {
int CFunc_CheckFlexibleParticleStructure(int, int);
int CFunc_CheckSplineParticleStructure(int, int);
extern int D_0036D3B0;
S2A3_Ent *func_001D4AC0(int, u32);
void func_002140D8(S2A3_Ent *, u32, f32, bool);
extern int D_00368A38_v asm("D_00368A38");
S2A49_Obj *Heap_Alloc(int, int, int, int);
void *func_001287F0(int, int);
int func_0027AA70(void *);
extern char D_00362400[];
extern char D_00363790[];
void func_002366E0(u32, void *, int);
bool func_0027D870(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
int func_002DD670(u32);
f32 func_0011ED20(void);
void func_0027C1F8(int, u32, f32);
void func_002754A0(int, int);
extern int D_00370EE0_p asm("D_00370EE0");
int func_001E65A8(void);
int func_001E65B0(void);
int func_001E65B8(void);
void func_001E6560(void);
void func_001E6578(void);
void func_001E6590(void);
void func_001E64A0(void);
void func_001E64B8(void);
void func_001E64D0(void);
int func_001E64E8(void);
int func_001E6510(void);
int func_001E6538(void);
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
int func_001150E0(int, char *);
void func_001D5C38(int, u32, int);
extern char D_00371D18[];
extern char D_00371D20[];
extern char D_00371D28[];
extern int D_0036D410;
int strcpy(void *, s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A32E0);

extern "C" int CFunc_ProfileTasks(int params) {
    int on = 1;
    int t = D_00370EE0_p;
    func_0027D1F8(params, 0, &on, 0);
    func_002754A0(t, on);
    return 1;
}

extern "C" s32 CFunc_SetSlomo(s32 arg0) {
    f32 sp0;

    sp0 = 1.0f;
    func_0027D268(arg0, 0, (s32) &sp0, 0);
    func_00275510(sp0);
    return 1;
}

extern "C" int CFunc_GetSlomo(int params, S2A34F0_1 *script) {
    int st = script->unk20;
    func_0027C1F8(st, 0xB88A3F78, func_0011ED20());
    return 1;
}

extern "C" s32 CFunc_LaunchScriptDebugger(void) {
    return D_00368744[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A33D0);

extern "C" int CFunc_Debounce(int params) {
    u32 btn = 0;
    func_0027D870(params, 0, &btn, 0);
    if (btn) {
        f32 t = 1.0f;
        func_0027D268(params, 0x906B67BA, (int)&t, 0);
        int clr = 0;
        func_0027D1F8(params, 0x1A4E0EF9, &clr, 0);
        for (S2A3_Ent *o = func_001D4AC0(D_0036D3B0, 0x27D7CD28); o; o = o->next) {
            func_002140D8(o, btn, t, clr != 0);
        }
        return 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A34A0);

extern "C" int CFunc_SetSaveZoneNameToCurrent(void) {
    func_002366E0(0x7A354E97, D_003301E0, 0);
    return 1;
}

extern "C" s32 CFunc_GetSaveZoneName(int arg0, S2A34F0_1 *arg1) {
    func_0027C028(arg1->unk20, 0x20F4889D /* save_zone */, D_003301E0);
    return 1;
}

extern "C" int CFunc_DestroyZoneEntities(int params) {
    int a;
    int b;
    a = 0;
    func_0027D870(params, 0x3324405C, &a, 1);
    func_0027D188(params, 0xB69DFDF1, (int)&b, 1);
    int x = func_001150E0(a, D_00371D18);
    int y = func_001150E0(a, D_00371D20);
    int z = func_001150E0(a, D_00371D28);
    int h = D_0036D410;
    func_001D5C38(h, 0xCD340D6C, a);
    func_001D5C38(h, 0xCD340D6C, x);
    func_001D5C38(h, 0xCD340D6C, y);
    func_001D5C38(h, 0xCD340D6C, z);
    return 1;
}

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

extern "C" int CFunc_DoesWaypointExist(int params) {
    u32 id;
    if (func_0027D870(params, 0xA1DC81F9, &id, 0)) {
        return func_002DD670(id);
    }
    return 0;
}

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
    strcpy(D_00330260, sp0);
    return 1;
}

extern "C" s32 CFunc_WasMovieAborted(void) {
    return D_00372EE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3EA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A48C0);

GP_DATA(D_00372EF8);
GP_DATA(D_00372F00);
GP_DATA(D_00372F08);
GP_DATA(D_00372F10);
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

extern "C" S2A49_Obj *func_002A4940(u32 key) {
    if (key == 0xDDFE0DB9) {
        S2A49_Obj *p = Heap_Alloc(D_00368A38_v, 0x14, 1, 0);
        p->vptr = D_00362400;
        p->unk0 = func_0027AA70(func_001287F0(8, 1));
        p->unk4 = func_0027AA70(func_001287F0(8, 1));
        p->unk8 = 0;
        p->vptr = D_00363790;
        p->unkC = 0;
        return p;
    }
    return 0;
}

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

extern "C" int func_002A4A78(void) {
    func_001E64A0();
    func_001E64B8();
    func_001E64D0();
    if (func_001E64E8() && func_001E6510() && func_001E6538()) {
        return 1;
    }
    func_001E6560();
    func_001E6578();
    func_001E6590();
    return 0;
}

extern "C" int func_002A4AF0(void) {
    if (func_001E65A8() || func_001E65B0() || func_001E65B8()) {
        func_001E6560();
        func_001E6578();
        func_001E6590();
        return 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4B50);

extern "C" u32 func_002A4D28(int a) {
    int c = (char)a;
    switch (c) {
    case 'a':
        return 0xB010F357;
    case 'b':
        return 0xFFC529F4;
    case 'f':
        return 0x61A1BC57;
    case 'c':
        return 0x3BF882CC;
    case 'e':
        return 0xCA41692D;
    case 'g':
        return 0x62896EDF;
    case 'h':
        return 0x79DAA2F9;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4DB8);
