#include "common.h"

struct S2606_Arr {
    int unk0;
    int size;
    int data;
    int Get(int i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

struct S2606_Time {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct S2606_Obj {
    char pad0[0xC];
    int unkC;
};

struct S2606_TM {
    f32 unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

asm(".set D_003717E0_gp, D_003717E0");

struct S2606_Ctx {
    char pad0[0x18];
    int unk18;
    u32 unk1C[1];
};

asm(".set D_0036F658_gp, D_0036F658");
asm(".set D_00372580_gp, D_00372580");

struct S2606_M {
    char pad0[0xA0];
    int unkA0;
    char padA4[0xC8 - 0xA4];
    int unkC8;
};

struct S2606_Script {
    char pad0[0x20];
    int unk20;
};

asm(".set D_00368748_lui, D_00368748");

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
void func_0030A49C(void *, int, int);
void func_0014F248(S2606_Time *);
void func_0027C160_p(void *, u32, int) asm("func_0027C160");
void func_0027C7D0(int, u32, void *);
extern int D_00370824;
extern int D_0036CD5C;
extern int D_0036D3B0[] __attribute__((section(".sdata")));
void *func_00113D20(int);
int func_002DB580(void *);
void func_001C5A68(int, int);
void func_001C5AB8(int, int);
void *func_001287F0(int, int);
void *func_0027AA70(void *);
void func_0027AC90(void *);
void func_00113250(void *);
void func_0027C448_p(void *, u32, u32) asm("func_0027C448");
S2606_Obj *func_001D4480(int, int, void *, int);
int func_0027D000(int, u32, int *, int);
void func_001C9368(int, int);
void func_00289C88(void *, int);
S2606_TM *func_00289C80(void *);
int func_002764E8(u32, int);
int func_0027CC30(int, u32, int, void *);
void func_0027F1E0(int, int, int);
extern u32 D_00368CD0[] __attribute__((section(".sdata")));
extern int D_0036873C[] __attribute__((section(".sdata")));
extern int D_003717E0_gp asm("D_003717E0_gp");
int func_0027D870(int, u32, u32 *, int);
int func_0027D1F8(int, u32, int *, int);
f32 func_0011ED10(void);
f32 func_0011ED18(void);
void func_0011ED30(f32);
void func_0010C010(int);
int func_002760E0(u32, int);
int func_0029FF08(int, int, int, int);
void func_0027C448(int, u32, u32);
extern S2606_M *D_0036F658_gp asm("D_0036F658_gp");
extern int D_00372580_gp asm("D_00372580_gp");
extern int D_00370F40[] __attribute__((section(".sdata")));
bool func_0027DF00(int, u32);
void func_0027C160(int, u32, int);
void func_0027C1F8(int, u32, f32);
int func_00275570(void);
void func_002DB8B0(f32);
void func_002DB8B8(f32);
void func_001C9468(int, bool);
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
int func_001C94D8(int);
extern int D_003706DC;
int func_0011EF10(void);
int func_0027D268(int, u32, void *, int);
void func_00260D50(f32);
void func_00260D28_f(f32) asm("func_00260D28");
f32 func_00260D08_f(void) asm("func_00260D08");
s64 func_00316A40(s64, s64);
s64 func_00317588_f(f32) asm("func_00317588");
extern int D_00368748_lui[] asm("D_00368748_lui") __attribute__((section(".sdata")));
}

extern "C" int CFunc_AllowAssetLoading(int params) {
    S2606_M *m = D_0036F658_gp;
    if (func_0027DF00(params, 0xD443A2BC)) {
        m->unkA0 = 1;
    } else {
        m->unkA0 = 0;
    }
    return 1;
}

extern "C" int CFunc_AreAssetsLocked(void) {
    return ((S002606A0*)D_0036F658[0])->unkA0 != 0;
}

inline void Push2606(u32 v, S2606_Ctx *m) {
    int i = m->unk18 + 1;
    u32 *p = &m->unk1C[i];
    m->unk18 = i;
    *p = v;
}

extern "C" int CFunc_PushAssetContext(int params) {
    u32 ctx = 0;
    func_0027D870(params, 0x1DA27A81, &ctx, 0);
    Push2606(ctx, (S2606_Ctx *)D_0036F658[0]);
    return 1;
}

extern "C" int CFunc_PopAssetContext(void) {
    ((S00260710*)D_0036F658[0])->unk18--;
    return 1;
}

extern "C" int CFunc_SetSearchAllAssetContexts(int params) {
    S2606_M *m = D_0036F658_gp;
    if (func_0027DF00(params, 0xD443A2BC)) {
        m->unkC8 = 0;
    } else {
        m->unkC8 = 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260778);

extern "C" int CFunc_Randomize(int params, S2606_Script *script) {
    int seed = func_0011EF10();
    func_0027D1F8(params, 0, &seed, 0);
    func_0010C010(seed);
    func_0027C160(script->unk20, 0x4C8EBED3, seed);
    return 1;
}

GP_DATA(D_003706DC);
extern "C" int CFunc_ResetTimer(void) {
    D_003706DC = func_0011EF10();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TimeGreaterThan);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002608C0);

extern "C" int CFunc_GetStartTime(int params, S2606_Script *script) {
    int d = script->unk20;
    int t = func_00275570();
    func_0027C160(d, 0xD16B61E6, D_00370F40[0] + t);
    return 1;
}

extern "C" int CFunc_GetTrueStartTime(int params, S2606_Script *script) {
    int d = script->unk20;
    func_0027C160(d, 0xD16B61E6, func_0011EF10());
    return 1;
}

extern "C" int CFunc_GetMicroseconds(int params, S2606_Script *script) {
    u32 t = (D_00368CD0[0] * 15000 + *(volatile u32 *)0x10000800) / 150;
    func_0027C160(script->unk20, 0xD16B61E6, t);
    return 1;
}

extern "C" int CFunc_ResetSongTimer(int a) {
    f32 f = 0.0f;
    func_0027D268(a, 0xD16B61E6 /* starttime */, &f, 0);
    func_00260D28_f(f);
    return 1;
}

extern "C" int CFunc_IncrementSongTimer(int a) {
    f32 f;
    func_0027D268(a, 0x7AD57518 /* delta_time */, &f, 1);
    func_00260D50(f);
    return 1;
}

extern "C" int CFunc_GetSongTime(int params, S2606_Script *script) {
    int d = script->unk20;
    func_0027C1F8(d, 0x92C008C7, func_00260D08_f());
    return 1;
}

extern "C" int CFunc_GetSongTimeMs(int params, S2606_Script *script) {
    f32 off = 0.0f;
    func_0027D268(params, 0xFF037AD9, &off, 0);
    int d = script->unk20;
    func_0027C1F8(d, 0x906B67BA, func_00260D08_f() * 1000.0f + off);
    return 1;
}

extern "C" f32 func_00260AC8(f32 f) {
    return func_00260D08_f() * 1000.0f + f;
}

extern "C" int CFunc_GetLocalSystemTime(int params, S2606_Script *script) {
    S2606_Time t;
    func_0030A49C(&t, 0, 0x20);
    func_0014F248(&t);
    void *st = func_0027AA70(func_001287F0(8, 1));
    func_0027C160_p(st, 0x447D8CC8, t.unk4);
    func_0027C160_p(st, 0x7149EFF9, t.unkC - 1);
    func_0027C160_p(st, 0xE806879A, t.unk10);
    func_0027C160_p(st, 0xD7B91B8F, t.unk14);
    func_0027C160_p(st, 0x8FE1EEB1, t.unk18);
    func_0027C160_p(st, 0x913D544A, t.unk0);
    func_0027C160_p(st, 0x49E0EE96, t.unk8);
    func_0027C160_p(st, 0x062AC42E, t.unk1C);
    func_0027C7D0(script->unk20, 0xA363FADA, st);
    if (st) {
        func_0027AC90(st);
        func_00113250(st);
    }
    return 1;
}

extern "C" int CFunc_GetDeltaTime(int params, S2606_Script *script) {
    if (func_0027DF00(params, 0x4FBEEE13)) {
        int d = script->unk20;
        func_0027C1F8(d, 0x7AD57518, func_0011ED18());
    } else {
        int d = script->unk20;
        func_0027C1F8(d, 0x7AD57518, func_0011ED10());
    }
    return 1;
}

extern "C" int CFunc_SetDeltaTime(int params) {
    f32 v = func_0011ED10();
    if (func_0027D268(params, 0x7AD57518, &v, 1)) {
        func_0011ED30(v);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_PrintTime(void) {
    return 1;
}

GP_DATA(D_003706C8);
extern "C" void func_00260D08(void) {
    func_00317298(D_003706C8);
}

GP_DATA(D_003706D8);
GP_DATA(D_003706D0);
extern "C" void func_00260D28(void) {
    u64 r = func_00317588();
    D_003706D8 = 0;
    D_003706C8 = r;
    D_003706D0 = r;
}

extern "C" void func_00260D50(f32 f) {
    if (D_003706D8 == 0) {
        D_003706C8 = func_00316A40(D_003706C8, func_00317588_f(f));
    }
}

extern "C" void func_00260D88(void) {
    D_003706D8 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260D98);

extern "C" int CFunc_TimeMarkerReached_SetParams(int params, void *script) {
    func_00289C88(script, 0x14);
    S2606_TM *d = func_00289C80(script);
    u32 name;
    int v;
    int x;
    d->unk0 = 0.0f;
    func_0027D268(params, 0xFF037AD9, &d->unk0, 0);
    func_0027D870(params, 0x5EF31148, &name, 1);
    d->unk4 = func_002764E8(name, 1);
    d->unk8 = func_0027DF00(params, 0x3131DB9E);
    d->unkC = func_0027DF00(params, 0x426F7555);
    if (func_0027CC30(params, 0x5CA15C8F, 1, &v)) {
        x = v;
    } else {
        func_0027F1E0(params, 0, 1);
        x = 0;
    }
    d->unk10 = x;
    return 1;
}

extern "C" int CFunc_TimeMarkerReached_ClearParams(int a, int b) {
    func_00289CF8(b);
    return 1;
}

extern "C" int CFunc_TimeMarkerReached(int params, void *script) {
    S2606_TM *d = func_00289C80(script);
    f32 now = func_00260D08_f() * 1000.0f + d->unk0;
    int t;
    if (d->unk8) {
        t = ((S2606_Arr *)((S2606_Arr *)d->unk4)->Get(d->unk10))->Get(0);
    } else if (d->unkC) {
        int p = ((S2606_Arr *)d->unk4)->Get(d->unk10);
        int v;
        if (func_0027CC30(p, 0x906B67BA, 1, &v)) {
            t = v;
        } else {
            func_0027F1E0(p, 0, 1);
            t = 0;
        }
    } else {
        t = ((S2606_Arr *)d->unk4)->Get(d->unk10);
    }
    return (f32)t <= now;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261090);

extern "C" int CFunc_OnServer(void) {
    return func_001C94D8(D_00372580[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002610C0);

extern "C" int CFunc_SetNetworkMode(int params) {
    int d = D_00372580[0];
    int mode = 0;
    func_0027D000(params, 0, &mode, 0);
    if (mode == 0) {
        func_001C9368(d, 0);
    } else if (mode == 1) {
        func_001C9368(d, 1);
    } else if (mode == 2) {
        func_001C9368(d, 2);
    }
    return 1;
}

extern "C" int CFunc_UseNetworkPreferences(void) {
    func_001CA9B0(D_00372580[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_TestNetSetup);

extern "C" void CFunc_NeedToTestNetSetup(void) {
    func_00296550(D_003717E0[0]);
}

extern "C" int CFunc_LoadNetworkDrivers(void) {
    int d = D_003717E0_gp;
    int a = func_002760E0(0x897CECD0, 0);
    int b = func_002760E0(0x3E683519, 0);
    int c = func_002760E0(0x676BC0CB, 0);
    return func_0029FF08(d, a, c, b);
}

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

extern "C" int CFunc_SetServerMode(int params) {
    int d = D_00372580_gp;
    func_001C9468(d, !func_0027DF00(params, 0xD443A2BC));
    return 1;
}

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

extern "C" int CFunc_NotCD(void) {
    return D_00368748_lui[0] ^ 1;
}

extern "C" int CFunc_Bootstrap(void) {
    return D_00368750;
}

extern "C" int CFunc_PAL(void) {
    return 0;
}

extern "C" int CFunc_IsPal(void) {
    return D_00368768[0] == 0;
}

extern "C" int CFunc_GetTerritory(int params, S2606_Script *script) {
    u32 t;
    switch (D_0036873C[0]) {
    case 2:
        t = 0xE9AC6DB1;
        break;
    case 1:
        t = 0x226927A5;
        break;
    case 3:
        t = 0x9F2C2A58;
        break;
    case 0:
    default:
        t = 0xACF610BD;
        break;
    }
    func_0027C448(script->unk20, 0x168BC699, t);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_AddToCutsceneDestroyList);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_RemoveFromCutsceneDestroyList);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_FlushCutsceneDestroyList);

extern "C" int CFunc_CutsceneDestroyListActive(void) {
    return ((S00261B58*)D_00368A38[0])->unk23C != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261B70);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_PlayCutscene);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261C90);

extern "C" void func_00261C98(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_0039A3C8.unk4.unk0 = &D_0039A3C8.unk4;
        D_0039A3C8.unk4.unk0->unk4 = &D_0039A3C8.unk4;
    }
}

extern "C" void func_00261CC8(void) {
    func_00261C98(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", CFunc_CenterCamera);

extern "C" int CFunc_SetMovementVelocity(int params) {
    f32 v = 10.0f;
    func_0027D268(params, 0, &v, 0);
    func_002DB8B0(v);
    return 1;
}

extern "C" int CFunc_SetRotateVelocity(int params) {
    f32 v = 120.0f;
    func_0027D268(params, 0, &v, 0);
    func_002DB8B8(v);
    return 1;
}

GP_DATA(D_00370824);
extern "C" int CFunc_LaunchViewer(void) {
    int m = D_0036CD5C;
    if (D_00370824) {
        return 1;
    }
    int v = func_002DB580(func_00113D20(0x70));
    func_001C5A68(m, v);
    func_001C5AB8(m, v);
    D_00370824 = 1;
    void *st = func_0027AA70(func_001287F0(8, 1));
    func_0027C448_p(st, 0xA1DC81F9, 0xEB17151B);
    int d = D_0036D3B0[0];
    S2606_Obj *o = func_001D4480(d, func_002764E8(0xF8C09B21, 0), st, 1);
    if (st) {
        func_0027AC90(st);
        func_00113250(st);
    }
    o->unkC |= 2;
    return 1;
}
