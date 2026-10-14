#include "common.h"

struct S2ABB00 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct S2ABB00_B {
    char padB4[0xB4];
    int unkB4;
};

struct S2AAD58_L {
    char pad0[8];
    int unk8;
    char padC[4];
    int unk10;
    f32 unk14;
    char pad18[0x10];
    f32 unk28;
};

extern "C" {
int func_001E2968(S2AAD58_L *, int);
f32 func_001E2850(S2AAD58_L *, int);
extern S2AAD58_L D_003AC770;
extern int D_00371EF0;
void func_0027AC90(int);
void func_0027ABB0(int, int);
int func_0027DF00(int, int);
extern int D_00371EEC;
extern s32 D_00371EF8;
extern s32 D_003AC7C0[];
extern int D_00372F28;
int func_002A7EF0(int);
S2ABB00 *func_002A7EA8(void);
int func_0027D870(int, u32, int *, int);
void func_002AE9F8(S2ABB00 *);
void func_0028C9F0(int, int, int, int, int, int);
S2ABB00_B *func_0028D1D8(int, int, int, int, int, u32, int, int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_BeginProcessBlock);

GP_DATA(D_00371EF8);
extern "C" s32 CFunc_LightShow_EndProcessBlock(void) {
    D_00371EF8 = 0;
    D_003AC7C0[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_PassEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_WaitForNextEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB738);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB848);

GP_DATA(D_00371EF0);
extern "C" void func_002ABB00(void) {
    if (D_00371EF0) {
        int v = 0;
        int h = func_002A7EF0(0);
        if (h) {
            int out;
            func_0027D870(h, 0xD63FB9AF, &out, 1);
            v = out;
        }
        if (v != D_00372F28) {
            if (D_00372F28) {
                S2ABB00 *p = func_002A7EA8();
                if (p->unkC) {
                    func_002AE9F8(p);
                    func_0028C9F0(p->unk8, 0, 0, 0, 0, 0);
                }
            }
            D_00372F28 = v;
            if (v) {
                S2ABB00 *p = func_002A7EA8();
                func_0028C9F0(p->unk0, 0, 0, 0, 0, 0);
                int q = p->unk4;
                p->unkC = func_0028D1D8(q, 0, 0, 0, 0, 0xD9AB9D3F, 0, 0, 0, 0)->unkB4;
            }
        }
    }
}

struct S2AB_Arr {
    int unk0;
    u32 unk4;
    int unk8;
};

extern "C" {
void func_0027AA70(void *);
void func_0027C448(void *, u32, int);
int func_0027D400(int, u32, int *, int);
int func_0027D470(int, u32, S2AB_Arr **, int);
extern int D_00372F18;
}

GP_DATA(D_00371EEC);
extern "C" int func_002ABC18(int a) {
    if (D_00372F18 == a) return 0;
    int sp10 = 0;
    if (func_0027D400(D_00371EEC, 0x6FB89DB9, &sp10, 0)) {
        S2AB_Arr *arr = 0;
        if (func_0027D470(sp10, 0x7D28697E, &arr, 0)) {
            char buf[16];
            u32 i = 0;
            func_0027AA70(buf);
            func_0027C448(buf, 0x7D28697E, a);
            func_0027C448(buf, 0x6963DBBF, D_00372F18);
            if (arr->unk4 != 0) {
                do {
                    int v;
                    if (arr->unk4 == 1) v = arr->unk8;
                    else v = ((int *)arr->unk8)[i];
                    i++;
                    func_0028C9F0(v, (int)buf, 0, 0, 0, 0);
                } while (i < arr->unk4);
            }
            func_0027AC90((int)buf);
        } else {
            D_00372F18 = a;
            return 1;
        }
    }
    D_00372F18 = a;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABD58);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetActive);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetProcessors);

extern "C" s32 CFunc_LightShow_SetMapping(int arg0) {
    func_0027AC90(D_00371EEC);
    if ((func_0027DF00(arg0, 0x1A4E0EF9) ^ 1) != 0 && arg0 != 0) {
        func_0027ABB0(D_00371EEC, arg0);
    }
    return 1;
}

extern "C" {
extern int D_00371EE8;
void func_0027ABB0(int, int);
int func_0027DD88(int, u32);
void func_002A79A8(void);
int func_002ABC18(int);
int func_002ABD58(int);
void func_002AB848(void);
}

extern "C" int CFunc_LightShow_SetParams(int params) {
    int v;
    int dirty = 0;
    int h = D_00371EE8;
    if (params)
        func_0027ABB0(h, params);
    if (func_0027DD88(params, 0xFD75CB86))
        func_002A79A8();
    if (func_0027D870(params, 0x7D28697E, &v, 0))
        dirty = func_002ABC18(v) != 0;
    if (func_0027D870(params, 0xFCC65109, &v, 0)) {
        int r = func_002ABD58(v);
        dirty = dirty || r;
    }
    if (dirty) {
        func_002ABB00();
        func_002AB848();
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_GetParams);

GP_DATA(D_00371EF0);
extern "C" int CFunc_LightShow_Update(void) {
    if (!D_00371EF0) {
        return 0;
    }
    int t = func_001E2968(&D_003AC770, D_003AC770.unk8);
    f32 f = func_001E2850(&D_003AC770, t);
    f32 d = f - func_001E2850(&D_003AC770, D_003AC770.unk10);
    D_003AC770.unk28 = f;
    D_003AC770.unk10 = t;
    D_003AC770.unk14 = d;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ACA48);
