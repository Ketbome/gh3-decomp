#include "common.h"

extern "C" {
int func_0027D1F8(int, int, int *, int);
int CFunc_ControllerMake(int, int);
extern s32 D_00373008[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GetHeldPattern);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", func_002AF698);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GuitarGetAnalogueInfo);

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
