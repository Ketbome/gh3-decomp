#include "common.h"

struct S2C9_Script {
    char pad0[0x20];
    int unk20;
};

struct S2C9_Var {
    char pad0[0x8];
    int unk8;
};

asm(".set D_0036CA50_lui, D_0036CA50");
asm(".set D_0036CA80_lui, D_0036CA80");
asm(".set D_0036CA5C_lui, D_0036CA5C");

struct S2CA618_Arr {
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

extern "C" {
int func_00275F08(int, int);
int func_0030B550(void *, char *, int);
int CrcFromPathLowercase(void *);
int func_0027DF00(int, int);
extern char D_00362BD0[];
extern char D_00362BE0[];
extern char D_00362BF8[];
extern char D_00362C18[];
S2CA618_Arr *func_002764E8(int, int);
extern s32 D_0036C378[] __attribute__((section(".sdata")));
extern s32 D_0036CA50;
extern s32 D_0036CA5C;
extern s32 D_0036CA80;
extern s32 D_00370E40;
extern int D_0038C9A0[];
extern int D_0038C9F0[];
int func_0019EE38(int, int, int, int);
int func_001A9E88(void *);
int func_00289CF8(s32);
extern s32 D_0036CA50_lui[] asm("D_0036CA50_lui") __attribute__((section(".sdata")));
extern s32 D_0036CA80_lui[] asm("D_0036CA80_lui") __attribute__((section(".sdata")));
extern s32 D_0036CA5C_lui[] asm("D_0036CA5C_lui") __attribute__((section(".sdata")));
void func_00289C88(void *, int);
int *func_00289C80(void *);
bool func_0027D870(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
S2C9_Var *func_0027AF38(int, u32, int);
extern int D_00373188[];
extern int D_00373180[];
extern int D_00372180[2];
int func_002763E0(u32, int);
void func_0027D400(int, u32, void *, int);
int func_0027D828(int, u32);
extern char D_00372188[];
u32 func_001150E0(u32, char *);
void func_0027AC90(int);
void func_00113250(int);
int func_0027AA70(int);
int func_001287F0(int, int);
void func_0027C448(int, u32, int);
void func_0027C1F8(int, u32, f32);
void func_0027C160(int, u32, int);
void func_0027C5B0(int, u32, f32, f32);
void func_0027C028(int, u32, int);
void func_0027C898(int, u32, int);
void CFunc_SpawnScriptNow(int, int);
}

struct S2CA888 {
    char pad0[0x18];
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    char pad28[4];
    int unk2C;
    char pad30[0x14];
    int unk44;
    char pad48[4];
    int unk4C;
    char pad50[0xC];
    f32 unk5C;
    char pad60[4];
    int unk64;
    int unk68;
    f32 unk6C;
    f32 unk70;
};

GP_DATA(D_00372180);
extern "C" int CFunc_SetLastGuitarVolume(int params) {
    int i;
    if (func_0027D1F8(params, 0x67E6859A, &i, 0)) {
        i--;
        int v;
        if (func_0027D1F8(params, 0xFF7E8B7E, &v, 0)) {
            D_00372180[i] = v;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_UpdateNixie);

struct S2C9K_H {
    int p;
    int unk4;
    int unk8;
    int unkC;
};
struct S2C9K_L {
    S2C9K_H a;
    S2C9K_H b;
    S2C9K_H c;
    int idx;
    f32 f;
};

extern "C" {
void func_00139CE8(int, int, f32);
void func_00145310(S2C9K_H *, int, int, int);
void func_001CE888(int, S2C9K_H *);
void func_001CEFB0(int, u32, f32 *);
extern int D_00369798[] __attribute__((section(".sdata")));
extern int D_003AC948[][6];
extern int D_003AC978[][6];
extern int D_003AC9A8[][6];
extern int D_00372F50[];
}

extern "C" int CFunc_KillPulsateStarPowerBulbs(int params) {
    S2C9K_L l;
    int i = 0;
    func_0027D1F8(params, 0x67E6859A, &l.idx, 1);
    l.idx = l.idx - 1;
    int heap = D_00369798[0];
    l.f = 1.0f;
    do {
        func_00145310(&l.a, heap, D_003AC948[l.idx][i], 0);
        if (l.a.p) {
            func_00145310(&l.b, heap, D_003AC978[l.idx][i], 0);
            func_001CEFB0(l.b.p, 0x898B0C73, &l.f);
            func_00139CE8(l.b.p, 1, l.f);
            func_00145310(&l.c, heap, D_003AC9A8[l.idx][i], 0);
            func_001CEFB0(l.c.p, 0x898B0C73, &l.f);
            func_00139CE8(l.c.p, 1, l.f);
            if (l.c.p) {
                func_001CE888(l.c.p, &l.c);
                l.c.p = 0;
            }
            if (l.b.p) {
                func_001CE888(l.b.p, &l.b);
                l.b.p = 0;
            }
        }
        if (l.a.p) {
            func_001CE888(l.a.p, &l.a);
            l.a.p = 0;
        }
        i++;
    } while (i < 6);
    func_00145310(&l.a, heap, D_00372F50[l.idx], 0);
    if (l.a.p) {
        func_00139CE8(l.a.p, 0, 0.0f);
        if (l.a.p) {
            func_001CE888(l.a.p, &l.a);
            l.a.p = 0;
        }
    }
    return 1;
}

extern "C" s32 CFunc_ClearSceneGraph(void) {
    func_001A9E88(D_0038C9A0);
    func_001A9E88(D_0038C9F0);
    return 1;
}

extern "C" s32 CFunc_ShowStencilShadow(void) {
    D_0036CA50 = 1;
    return 1;
}

extern "C" s32 CFunc_HideStencilShadow(void) {
    D_0036CA50_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_SetMasterBloom(void) {
    D_0036CA80 = 1;
    return 1;
}

extern "C" s32 CFunc_ClearMasterBloom(void) {
    D_0036CA80_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_ShowDOF(void) {
    D_0036CA5C = 1;
    return 1;
}

extern "C" s32 CFunc_HideDOF(void) {
    D_0036CA5C_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_MoviePlayerAllowController2(void) {
    D_00370E40 = 1;
    return 1;
}

extern "C" s32 CFunc_BlankScreen(void) {
    func_0019EE38(0, 0, 0, 0);
    D_0036C378[0] = 2;
    return 1;
}

extern "C" int CFunc_StarPowerFastTest_Initialise(int params, void *script) {
    func_00289C88(script, 4);
    int *p = func_00289C80(script);
    u32 k;
    func_0027D870(params, 0x1BFF0C3D, &k, 1);
    *p = func_002763E0(k, 0);
    return 1;
}

extern "C" s32 CFunc_StarPowerFastTest_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_StarPowerFastTest);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_GuitarEvent_HitNotes_CFunc);

extern "C" int CFunc_handle_hit_note_CFunc(int params, S2C9_Script *script) {
    u32 k;
    func_0027D870(script->unk20, 0x0830ECAF, &k, 1);
    S2C9_Var *v = func_0027AF38(func_002763E0(func_001150E0(k, D_00372188), 1), 0x5D2258D2, 0);
    if (v->unk8 == 0x0203B372) {
        v->unk8 = 0xD43297CF;
    }
    return 1;
}

extern "C" int CFunc_Increment(int params, S2C9_Script *script) {
    u32 k;
    func_0027D870(params, 0, &k, 1);
    S2C9_Var *v = func_0027AF38(script->unk20, k, 0);
    v->unk8++;
    return 1;
}

extern "C" void func_002CA618(int a, int *p) {
    int v = 2;
    S2CA618_Arr *t = func_002764E8(a, 0);
    if (t) {
        int n = t->size;
        if (n) {
            int i = n - func_00275F08(0xF0F1A160, 1);
            int x = t->Get(i);
            int y = t->Get(i + 1);
            v = x + y;
        }
    }
    if (*p < v) {
        *p = v;
    }
}

extern "C" void func_002CA6E8(int a, int *p) {
    char buf[0x70];
    int n = func_0027D828(a, 0xA1DC81F9);
    func_0030B550(buf, D_00362BD0, n);
    int h1 = CrcFromPathLowercase(buf);
    func_0030B550(buf, D_00362BE0, n);
    int h2 = CrcFromPathLowercase(buf);
    *p = 2;
    func_002CA618(h1, p);
    func_002CA618(h2, p);
    if (func_0027DF00(a, 0xC6EFF9C1)) {
        func_0030B550(buf, D_00362BF8, n);
        int h3 = CrcFromPathLowercase(buf);
        func_0030B550(buf, D_00362C18, n);
        int h4 = CrcFromPathLowercase(buf);
        *p = 2;
        func_002CA618(h3, p);
        func_002CA618(h4, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA818);

extern "C" void func_002CA888(S2CA888 *p, int a) {
    int s = func_0027AA70(func_001287F0(8, 1));
    func_0027C448(s, 0, p->unk18);
    int t = func_0027AA70(func_001287F0(8, 1));
    if (p->unk18 != 0x45E568EE) {
        func_0027C1F8(t, 0x906B67BA, p->unk5C);
        func_0027C160(t, 0x7D30DF01, p->unk64);
        func_0027C5B0(t, 0x13B9DA7B, p->unk6C, p->unk70);
        func_0027C448(t, 0x8A521CB3, p->unk68);
        func_0027C160(t, 0x67E6859A, p->unk20);
        func_0027C448(t, 0x1BFF0C3D, p->unk24);
        func_0027C028(t, 0x666E080B, p->unk2C);
        func_0027C160(t, 0x5CA15C8F, p->unk4C);
        func_0027C160(t, 0x7FF8E6DA, p->unk44);
    }
    func_0027C898(s, 0x7031F10C, t);
    CFunc_SpawnScriptNow(s, a);
    if (s) {
        func_0027AC90(s);
        func_00113250(s);
    }
}

extern "C" int CFunc_fretbar_iterator_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x74);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_iterator_CFunc);

extern "C" int CFunc_fretbar_update_hammer_on_tolerance_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x30);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_update_hammer_on_tolerance_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_hammer_on_tolerance_CFunc);

extern "C" int CFunc_fretbar_update_tempo_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x34);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_update_tempo_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_tempo_CFunc);
