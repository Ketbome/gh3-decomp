#include "common.h"

asm(".set D_00368A38_lui, D_00368A38");

struct S2A1_St {
    int unk0;
    int unk4;
};

asm(".set D_0036CA58_lui, D_0036CA58");

struct S2A1_Ref {
    void *p;
    int unk4;
};


struct S2A1_Dtor {
    char pad0[0xC];
    void *unkC;
};

struct S2A1_Cmp {
    char pad0[0x2C];
    int unk2C;
};

struct S2A1758_1 {
    char pad0[0x20];
    s32 unk20;
};

struct S2A2550_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" {
extern int D_00368A38_lui[] asm("D_00368A38_lui") __attribute__((section(".sdata")));
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
int CrcFromPathLowercase(char *);
void func_0022B0D0(S2A1_Ref *, int, int, int);
void func_0022ADD0(int, S2A1_Ref *);
void func_0027AA70(S2A1_St *);
void func_0027C028(S2A1_St *, int, char *);
void func_0027AC90(S2A1_St *);
int CFunc_NodeArrayManUnload(int, int);
int CFunc_NodeArrayManLoad(int, int);
int func_002253B0(int);
void func_00225A78(int, int);
void func_002255E8(int, int, int, int, int, int);
int func_0027D268(int, u32, f32 *, int);
int func_0027D1F8(int, u32, int *, int);
int func_0027D400(int, u32, int *, int);
bool func_0027DF00(int, u32);
extern s32 D_0036CA58;
extern s32 D_0036CA58_lui[] asm("D_0036CA58_lui") __attribute__((section(".sdata")));
extern char D_003AAC98[];
extern int D_0036F658[] __attribute__((section(".sdata")));
void strcpy(char *, int);
void func_0022ABE8(S2A1_Ref *, int, int, int, int, int, int, int);
void func_00134340(S2A1_Ref *);
void func_0011A558(u32, int, int);
void func_0028CD90(void);
void func_002A6B70(int, int, u32);
void func_002242F8(void);
void func_0011A568(void);
void func_002DD3C0(int, f32, f32, f32);
int func_00289E08(void *);
int CFunc_SpawnScript(int, void *);
int func_0028DA08(void *);
int func_001D03D8(int, int, int, int, int);
void func_00289ED8(int, void *);
extern int D_00368A38;
void Heap_Free(int, void *);
extern s32 D_00369A64[] __attribute__((section(".sdata")));
int func_00224220(int, int);
int func_002299B0(s32, int, int, int);
void func_002A2108(void *, int *);
void func_0028CF18(void *);
void CFunc_FlushDeadObjects(int, int);
extern char D_0035CBE0[];
void func_0011E780(void *);
extern char D_0035CBC8[];
void func_0022A2D8(void *);
extern char D_0035CBB0[];
void func_00290CA0(void *);
extern char D_0035CB98[];
void func_00266850(void *);
extern char D_0035CB80[];
void func_00295E08(void *);
extern char D_0035CB68[];
void func_001D4208(void *);
extern char D_0035CB50[];
void func_001D4D48(void *);
extern char D_0035CB38[];
void func_001C5D28(void *);
extern char D_0035CB20[];
void func_002DBA28(void *);
extern char D_0035CB08[];
void func_002DCB40(void *);
extern char D_0035CAF0[];
void func_002DE220(void *);
extern char D_0035CAD8[];
void func_00144498(void *);
extern char D_0035CAC0[];
void func_00224468(void *);
extern f32 D_0036CA70[] __attribute__((section(".sdata")));
extern s32 D_0036F520[] __attribute__((section(".sdata")));
extern s32 D_0036F608[] __attribute__((section(".sdata")));
extern s32 D_00372318[] __attribute__((section(".sdata")));
extern s32 D_00372EF0[] __attribute__((section(".sdata")));
int func_00222F90(int);
void func_00225BF0(int, int);
int func_002297A8(s32);
int func_002297D8(s32, s32);
s32 func_002765E0(int, int);
int func_0027C1F8(s32, int, f32);
int func_0027C448(s32, int, s32);
int func_0027D188(int, int, int, int);
int func_0027D870(int, int, int, int);
int func_002A1AE0(int, int, int);
int func_002A2568(int, int, int);
int func_002DCD20(s32, int);
}

extern "C" void func_002A12B0(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CBE0;
    func_0011E780(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1300(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CBC8;
    func_0022A2D8(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1350(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CBB0;
    func_00290CA0(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A13A0(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB98;
    func_00266850(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A13F0(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB80;
    func_00295E08(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1440(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB68;
    func_001D4208(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1490(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB50;
    func_001D4D48(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A14E0(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB38;
    func_001C5D28(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1530(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB20;
    func_002DBA28(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1580(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CB08;
    func_002DCB40(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A15D0(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CAF0;
    func_002DE220(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1620(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CAD8;
    func_00144498(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002A1670(S2A1_Dtor *p, int flags) {
    p->unkC = D_0035CAC0;
    func_00224468(p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A16C0);

extern "C" s32 CFunc_OverwriteCorruptMemcardContent(void) {
    return 0;
}

extern "C" s32 CFunc_AutoListDeleteStart(void) {
    return 0;
}

extern "C" s32 CFunc_AutoListDeleteFinished(void) {
    return 0;
}

extern "C" s32 CFunc_GetMemCardFileProp(void) {
    return 0;
}

extern "C" s32 CFunc_RegisterState(void) {
    return 0;
}

extern "C" s32 CFunc_UnregisterAllStates(void) {
    return 0;
}

extern "C" s32 CFunc_RegisterCompositeObjectDesc(void) {
    return 0;
}

extern "C" s32 CFunc_PassMgr_Init(void) {
    return 0;
}

extern "C" s32 CFunc_ProcessorMgr_Init(void) {
    return 0;
}

extern "C" s32 CFunc_RegisterPassGroupDesc(void) {
    return 0;
}

extern "C" s32 CFunc_RegisterProcessorGroupDesc(void) {
    return 0;
}

extern "C" s32 CFunc_HACK_ps2_set_saveload_successor_checksum(s32 arg0) {
    s32 sp0;
    func_0027D870(arg0, 0, (s32) &sp0, 1);
    D_00372EF0[0] = sp0;
    return 1;
}

extern "C" s32 CFunc_HACK_ps2_get_saveload_successor_checksum(int arg0, S2A1758_1 *arg1) {
    func_0027C448(arg1->unk20, 0x91652189 /* ps2_saveload_successor_checksum */, D_00372EF0[0]);
    return 1;
}

extern "C" int CFunc_DEBUG_set_DofZDepth(int params) {
    func_0027D268(params, 0x6FEC35E2, D_0036CA70, 0);
    if (D_0036CA70[0] < 1.0f) {
        D_0036CA58 = 0;
    } else {
        D_0036CA58_lui[0] = 1;
    }
    return 1;
}

extern "C" s32 CFunc_DEBUG_get_DofZDepth(int arg0, S2A1758_1 *arg1) {
    func_0027C1F8(arg1->unk20, 0x6FEC35E2, D_0036CA70[0]);
    return 1;
}

extern "C" s32 func_002A1820(void) {
    return 0x3AF;
}

extern "C" s32 func_002A1828(void) {
    return 0x43;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1830);

GP_DATA(D_00372EF0);
extern "C" void func_002A1840(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372EF0[0] = 0x806FFF30;
    }
}

extern "C" void func_002A1868(void) {
    func_002A1840(1, 0xFFFF);
}

extern "C" int func_002A1888(int a, int b) {
    int r = func_00224220(a, 1);
    if (!r) {
        return 0;
    }
    return func_002299B0(D_0036F608[0], r, a, b);
}

extern "C" int func_002A18E0(int a) {
    int r = func_00224220(a, 1);
    if (!r) {
        return 0;
    }
    return func_002297D8(D_0036F608[0], r);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1918);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1AE0);

extern "C" void CFunc_IsInNodeArray(s32 arg0) {
    s32 sp0;
    func_0027D870(arg0, 0, (s32) &sp0, 1);
    func_00222F90(sp0);
}

extern "C" void CFunc_CreateFromStructure(s32 arg0) {
    func_002297D8(D_0036F608[0], arg0);
}

extern "C" int CFunc_Create(int params, int script) {
    CFunc_FlushDeadObjects(0, 0);
    return func_002A1AE0(params, script, 0);
}

extern "C" int CFunc_CallScriptOnNode(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 8);
}

extern "C" int CFunc_SetObjectColor(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 6);
}

extern "C" int CFunc_Kill(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 1);
}

extern "C" int CFunc_Visible(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 2);
}

extern "C" int CFunc_Invisible(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1D90);

extern "C" int CFunc_SetGSIdleProcParams(int params) {
    int a;
    f32 b;
    f32 c;
    f32 d;
    func_0027D1F8(params, 0x78F39ECC, &a, 1);
    func_0027D268(params, 0x00AFE82A, &b, 1);
    func_0027D268(params, 0x5235F716, &c, 1);
    func_0027D268(params, 0xBCE1960E, &d, 1);
    func_002DD3C0(a, b, c, d);
    return 1;
}

extern "C" s32 CFunc_PrintNodeArrayParsingStatus(void) {
    return 1;
}

extern "C" void CFunc_NodeArrayBusy(void) {
    func_002297A8(D_0036F608[0]);
}

extern "C" int CFunc_LoadNodeArray(int params) {
    int name;
    func_0011A558(0xAAD6C3C7, 0, 0);
    func_0028CD90();
    name = 0;
    func_0027D188(params, 0, (int)&name, 0);
    strcpy(D_003AAC98, name);
    func_002A6B70(name, 0, 0x0C7800B0);
    func_002242F8();
    func_0011A568();
    return 1;
}

extern "C" int CFunc_ReLoadNodeArray(int params, int script) {
    S2A1_Ref ref;
    S2A1_St st;
    int h = D_00368A38_lui[0];
    func_00119490(h, func_00119610(h, 0x3B));
    int x = D_0036F520[0];
    int k = CrcFromPathLowercase(D_003AAC98);
    int m = D_0036F658[0];
    func_0022B0D0(&ref, m, k, 0);
    func_0022ADD0(m, &ref);
    func_0027AA70(&st);
    func_0027C028(&st, 0, D_003AAC98);
    CFunc_NodeArrayManUnload((int)&st, script);
    CFunc_NodeArrayManLoad((int)&st, script);
    func_002A6B70((int)D_003AAC98, 0, 0x0C7800B0);
    func_002242F8();
    int y = func_002253B0(x);
    func_00225A78(x, y);
    func_002255E8(x, y, 1, 0, 0, 0);
    func_001194B8(D_00368A38);
    func_0027AC90(&st);
    func_00134340(&ref);
    return 1;
}

extern "C" int CFunc_NodeArrayManLoad(int params, int script) {
    S2A1_Ref ref;
    int name;
    func_0027D188(params, 0, (int)&name, 1);
    strcpy(D_003AAC98, name);
    func_0022ABE8(&ref, D_0036F658[0], name, 0xD, 0, 0, 0, 0);
    func_00134340(&ref);
    return 1;
}

extern "C" s32 CFunc_NodeArrayManUnload(s32 arg0, int script) {
    s32 sp0;
    func_0027D188(arg0, 0, (s32) &sp0, 1);
    func_00225BF0(D_0036F520[0], sp0);
    return 1;
}

extern "C" s32 CFunc_DumpHavokMemStats(void) {
    return 1;
}

extern "C" s32 CFunc_SetLeakCheck(void) {
    return 1;
}

extern "C" s32 CFunc_CasArtist(void) {
    return func_002765E0(0x2A648514 /* cas_artist */, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2108);

extern "C" void func_002A2200(S2A1_Cmp *p, int *q) {
    if (p->unk2C == q[0]) {
        func_002A2108(p, q + 1);
    }
}

extern "C" void func_002A2230(S2A1_Cmp *p, int *q) {
    if (p->unk2C == q[0]) {
        func_002A2108(p, q + 1);
    }
}

extern "C" int CFunc_ClearFlag(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 1);
}

extern "C" int CFunc_SendFlag(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 0);
}

extern "C" int CFunc_QueryFlag(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 2);
}

extern "C" int CFunc_SendException(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 5);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A22E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", CFunc_IsCreated);

extern "C" void func_002A2550(S2A2550_0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unkC = 0;
    arg0->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2568);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A26F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A29A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2E68);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A3110);

extern "C" int CFunc_SpawnSound(int params, void *script) {
    if (!func_00289E08(script)) {
        return CFunc_SpawnScript(params, script);
    }
    int name;
    if (!func_0027D870(params, 0, (int)&name, 0)) {
        return 1;
    }
    int x = func_0028DA08(script);
    func_0027D870(params, 0x40C698AF, (int)&x, 0);
    int y = 0;
    func_0027D400(params, 0x7031F10C, &y, 0);
    int h = func_001D03D8(func_00289E08(script), name, y, x, 0);
    bool missing = !func_0027DF00(params, 0x01917DF2);
    if (missing) {
        func_00289ED8(h, script);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A3218);

extern "C" int CFunc_c_PauseGame(int params, void *script) {
    func_002DCD20(D_00372318[0], 1);
    func_0028CF18(script);
    return 1;
}

extern "C" s32 CFunc_c_UnPauseGame(void) {
    func_002DCD20(D_00372318[0], 0);
    return 1;
}

extern "C" int CFunc_GameIsPaused(int params, S2A1758_1 *script) {
    if (D_00369A64[0]) {
        func_0027C448(script->unk20, 0x3BA1FDB9, 0x3BA1FDB9);
        return 1;
    }
    return 0;
}
