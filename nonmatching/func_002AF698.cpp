#include "common.h"

extern "C" {
int func_0027D1F8(int, int, int *, int);
int CFunc_ControllerMake(int, int);
extern s32 D_00373008[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GetHeldPattern);

struct S2AF6_T {
    char pad0[9];
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    char pad11[0x27];
    int unk38;
};

struct S2AF6_C {
    char pad0[0x1C];
    S2AF6_T *unk1C;
};

extern "C" {
S2AF6_C *func_002DCA08(void);
int func_002AF438(S2AF6_C *, int);
int func_002DC9D8(int);
int func_0027CC30(int, u32, int, int *);
int func_0027F1E0(int, int, int);
int func_0027D1F8_t(int, u32, int *, int) asm("func_0027D1F8");
extern int D_00371F90[];
extern int D_003730D8[];
}

GP_DATA(D_00371F90);
extern "C" int func_002AF698(int a0, int a1, int *a2, int *a3, int *a4, int a5) {
    int *sp8 = a4;
    int r17;
    int r19;
    int r20;
    S2AF6_C *c = func_002DCA08();
    r17 = 0;
    if (c->unk1C != 0) {
        r19 = 0;
        r20 = 0;
        if (func_002DC9D8(a0) != 0) {
            if (func_002AF438(c, a0) != 0) {
                S2AF6_T *t = c->unk1C;
                if (t->unk38 & 0x5000) {
                    r20 = 1;
                    r17 = 0x10000;
                    if (t->unk10 == 0) r17 = 0;
                    if (t->unkA != 0) r17 |= 0x1000;
                    if (t->unk9 != 0) r17 |= 0x100;
                    if (t->unkB != 0) r17 |= 0x10;
                    if (t->unkC != 0) r17 |= 1;
                }
            } else {
                S2AF6_T *t = c->unk1C;
                int f = t->unk38;
                r17 = 0;
                if (f & 1) r17 = 0x10000;
                if (f & 4) r17 |= 0x1000;
                if (f & 8) r17 |= 0x100;
                if (f & 2) r17 |= 0x10;
                r19 = r17;
                if (f & 0x40) r19 |= 1;
                r17 = r19;
                if (t->unkF != 0) r17 = r19 | 0x10000;
                if (t->unkD != 0) r17 |= 0x1000;
                if (t->unkE != 0) r17 |= 0x100;
                if (t->unk10 != 0) r17 |= 0x10;
                if (t->unkB != 0) r17 |= 1;
                if (r19 != 0) {
                    int r18 = 0;
                    int sp0;
                    int sp4;
                    if (func_0027D1F8_t(a5, 0x67E6859A, &sp0, 0) != 0) {
                        sp0 -= 1;
                        int k = D_00371F90[sp0];
                        if (func_0027CC30(k, 0xF0153B1D, 1, &sp4) != 0) {
                            r18 = sp4;
                        } else {
                            func_0027F1E0(k, 0, 1);
                        }
                    }
                    r20 = r18 != r17;
                } else if (r17 == 0) {
                    D_003730D8[a1] = 1;
                }
            }
        }
        if (a2 != 0) {
            *a2 = r17;
        }
        if (a3 != 0) {
            *a3 = r19;
        }
        if (sp8 != 0) {
            *sp8 = r20;
        }
        return 1;
    }
    return 0;
}

struct S2AF598_P {
    char pad0[0x23];
    u8 unk23;
    u8 unk24;
};
struct S2AF598_Q {
    char pad0[0x1C];
    S2AF598_P *unk1C;
};
struct S2AF598_M {
    char pad0[0x28];
    S2AF598_Q *unk28[2];
};
struct S2AF598_S {
    char pad0[0x20];
    int unk20;
};
extern "C" {
extern S2AF598_M *D_0036CDB4;
void func_0027C1F8(int, u32, f32);
int func_002DC9D8(int);
int CFunc_GetAnalogueInfo(int, S2AF598_S *);
}

extern "C" int CFunc_GuitarGetAnalogueInfo(int params, S2AF598_S *script) {
    int idx = 0;
    func_0027D1F8(params, 0xB30D9965, &idx, 0);
    S2AF598_M *m = D_0036CDB4;
    if (idx >= 2) {
        func_0027C1F8(script->unk20, 0x303067F1, 0.0f);
        func_0027C1F8(script->unk20, 0x47375767, 0.0f);
        func_0027C1F8(script->unk20, 0x694DF774, 0.0f);
        func_0027C1F8(script->unk20, 0x1E4AC7E2, 0.0f);
        func_0027C1F8(script->unk20, 0x7F46D589, 0.0f);
        func_0027C1F8(script->unk20, 0x8C5016D1, 0.0f);
        func_0027C1F8(script->unk20, 0x791C32BF, 0.0f);
        func_0027C1F8(script->unk20, 0x1C5FFDBA, 0.0f);
        func_0027C1F8(script->unk20, 0x7B854432, 90.0f);
        func_0027C1F8(script->unk20, 0xDACFA0C3, 0.0f);
        func_0027C1F8(script->unk20, 0x051F8920, 0.0f);
        return 1;
    }
    if (func_002DC9D8(idx)) {
        S2AF598_P *p = m->unk28[idx]->unk1C;
        func_0027C1F8(script->unk20, 0xDACFA0C3, (f32)(p->unk23 - 0x80));
        func_0027C1F8(script->unk20, 0x051F8920, (f32)(p->unk24 - 0x80));
    } else {
        func_0027C1F8(script->unk20, 0xDACFA0C3, 0.0f);
        func_0027C1F8(script->unk20, 0x051F8920, 0.0f);
    }
    return CFunc_GetAnalogueInfo(params, script);
}

extern "C" s32 CFunc_GuitarControllerMake(int arg0, int arg1) {
    int out = 0;
    func_0027D1F8(arg0, 0, &out, 0);
    if (out >= 2) {
        return 0;
    }
    return CFunc_ControllerMake(arg0, arg1);
}

extern "C" s32 CFunc_StartWildcardSearch(void) {
    return 0;
}

extern "C" s32 CFunc_GetWildcardFile(void) {
    return 0;
}

extern "C" s32 CFunc_EndWildcardSearch(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_InputArrayCreate);

struct S2AFE38 {
    char pad0[4];
    int unk4;
    int unk8;
};
extern "C" {
void func_0027EDE0(int, int, int);
}
INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", func_002AFE38);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_InputArrayAddElement);

struct S2AF598_A {
    char pad0[4];
    int unk4;
    int *unk8;
};
struct S2AF598_L {
    int key;
    int v[6];
    int idx;
};
extern "C" {
bool func_0027D870(int, u32, void *, int);
S2AF598_A *func_002764E8(int, int);
bool func_0027D1F8_b(int, u32, void *, int) asm("func_0027D1F8");
}

extern "C" int CFunc_SongArraySet(int params) {
    S2AF598_L l;
    if (func_0027D870(params, 0xA1DC81F9, &l.key, 0)) {
        S2AF598_A *a = func_002764E8(l.key, 0);
        if (a) {
            l.v[0] = 0;
            l.v[1] = 0;
            l.v[2] = 0;
            l.v[3] = 0;
            l.v[4] = 0;
            l.v[5] = 0;
            bool m0 = !func_0027D1F8_b(params, 0x906B67BA, &l.v[0], 0);
            if (m0) return 0;
            bool m1 = !func_0027D1F8_b(params, 0x2F6511DE, &l.v[1], 0);
            if (m1) return 0;
            bool m2 = !func_0027D1F8_b(params, 0x059EA070, &l.v[2], 0);
            if (m2) return 0;
            bool m3 = !func_0027D1F8_b(params, 0x2FFB1360, &l.v[3], 0);
            if (m3) return 0;
            bool m4 = !func_0027D1F8_b(params, 0x61C9354B, &l.v[4], 0);
            if (m4) return 0;
            bool m5 = !func_0027D1F8_b(params, 0xE23A4E87, &l.v[5], 0);
            if (m5) return 0;
            l.idx = 0;
            if (func_0027D1F8_b(params, 0xD4DE628F, &l.idx, 0)) {
                int h;
                int ix = l.idx;
                if (a->unk4 == 1) {
                    h = (int)a->unk8;
                } else {
                    h = a->unk8[ix];
                }
                func_0027EDE0(h, 0, l.v[0]);
                func_0027EDE0(h, 1, l.v[1]);
                func_0027EDE0(h, 2, l.v[2]);
                func_0027EDE0(h, 3, l.v[3]);
                func_0027EDE0(h, 4, l.v[4]);
                func_0027EDE0(h, 5, l.v[5]);
                return 1;
            }
        }
    }
    return 0;
}

extern "C" s32 func_002B0370(void) {
    s32 var_4;

    var_4 = 0;
    if ((D_00373008[0] == 0xF8B928FD /* p2_career */) || (D_00373008[0] == 0xA572DCB2 /* p2_coop */)) {
        var_4 = 1;
    }
    return var_4;
}

extern "C" s32 func_002B03A8(void) {
    s32 var_4;

    var_4 = 0;
    if ((D_00373008[0] == 0x4BA430F2 /* p2_faceoff */) || (D_00373008[0] == 0xC3FA2BF0 /* p2_pro_faceoff */)) {
        var_4 = 1;
    }
    return var_4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_UpdateScoreFastInit);
