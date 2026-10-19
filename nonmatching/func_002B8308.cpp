#include "common.h"

struct S2B83_Arr {
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
void func_00113250(int);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027AC90(int);
void func_0027C160(int, u32, int);
void func_0027C1F8(int, u32, f32);
void func_0027C448(int, u32, int);
void func_002B4A18(int, int);
void func_002B6270(int, int);
int func_002B6708(int, int);
void func_002C1390(u32, int, int);
void func_002B8088(int);
extern int D_00373100;
extern int D_00373028[];
extern int D_00372F78[];
extern int D_00373128[];
extern int D_00373018[];
extern int D_00372FB0[];
extern S2B83_Arr *D_00371FB0[] __attribute__((section(".sdata")));
extern int D_00372FA8[];
extern int D_00371FC8[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", func_002B8088);

GP_DATA(D_00371FB0);
GP_DATA(D_00371FC8);
extern "C" void func_002B8308(int arg0, f32 f) {
    if (D_00373100 != 1) {
        int h = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(h, 0xDA029B2B, D_00373028[arg0]);
        func_0027C448(h, 0x1BFF0C3D, D_00372F78[arg0]);
        func_0027C160(h, 0x5CA15C8F, D_00373128[arg0]);
        func_0027C448(h, 0xCC12115E, D_00373018[arg0]);
        func_0027C1F8(h, 0x92C008C7, f);
        func_002B4A18(D_00372FB0[arg0], h);
        S2B83_Arr *t = D_00371FB0[arg0];
        if (t) {
            int i = D_00373128[arg0] - 1;
            S2B83_Arr *e = (S2B83_Arr *)t->Get(i > -1 ? i : 0);
            int v = e->Get(0);
            if (v > 0x6DDCFF) {
                v = 0;
            }
            if (func_002B6708(v, arg0) && i >= 0) {
                func_002B6270(arg0, v);
                func_002B4A18(D_00372FA8[arg0], h);
                func_002C1390(0xF9A5058C, 1, arg0);
            }
        }
        if (h) {
            func_0027AC90(h);
            func_00113250(h);
        }
        func_002B8088(arg0);
        D_00371FC8[arg0] = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", CFunc_GuitarInputLogicInit);

extern "C" void func_002B8ED0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", CFunc_GuitarInputLogicPerFrame);
