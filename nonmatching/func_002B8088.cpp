#include "common.h"

extern "C" {
extern int D_00371F90[2];
extern int D_00371F94[];
extern int D_00371FF8;
extern int D_00372F78[];
extern int D_00372F7C[];
int func_0027CC30(int, u32, int, int *);
int func_0027F1E0(int, int, int);
int func_002B0370(void);
int func_002B4B98(int, u32, int);
int func_002B4A60(u32, int);
int func_0027AA70(int);
int func_001287F0(int, int);
int func_0027C448(int, u32, int);
int func_0027AC90(int);
int func_00113250(int);
}

GP_DATA(D_00371FF8);
GP_DATA(D_00371F90);
extern "C" void func_002B8088(int arg0) {
    int sp0;
    int sp4;
    int sp8;
    if (D_00371FF8 == 0 || arg0 != 1) {
        int h = D_00371F90[arg0];
        int ok = func_0027CC30(h, 0xA675A409, 1, &sp0);
        int v = sp0;
        if (ok == 0) {
            v = 0;
            func_0027F1E0(h, 0, 1);
        }
        int h2 = D_00371F90[0];
        int *slot;
        if (func_002B0370() != 0) {
            slot = &D_00371F90[arg0];
            if (h2 != 0) {
                if (D_00371F94[0] != 0) {
                    int ok2 = func_0027CC30(h2, 0xA675A409, 1, &sp4);
                    int a = sp4;
                    if (ok2 == 0) {
                        a = 0;
                        func_0027F1E0(h2, 0, 1);
                    }
                    int h3 = D_00371F94[0];
                    int ok3 = func_0027CC30(h3, 0xA675A409, 1, &sp8);
                    int b = sp8;
                    if (ok3 == 0) {
                        func_0027F1E0(h3, 0, 1);
                        b = 0;
                    }
                    v = a + b;
                    func_002B4B98(D_00371F90[0], 0xA675A409, 0);
                    func_002B4B98(D_00371F94[0], 0xA675A409, 0);
                } else {
                    goto block12;
                }
            } else {
                goto block13;
            }
        } else {
block12:
            slot = &D_00371F90[arg0];
block13:
            func_002B4B98(*slot, 0xA675A409, 0);
        }
        if (v >= 10) {
            u32 key;
            if (v >= 30) {
                key = 0x356DFC02;
            } else if (v >= 20) {
                key = 0x874D2012;
            } else {
                key = 0xBA2D09A2;
            }
            int t = func_0027AA70(func_001287F0(8, 1));
            if (func_002B0370() != 0 && D_00371F90[0] != 0 && D_00371F94[0] != 0) {
                func_0027C448(t, 0x1BFF0C3D, D_00372F78[0]);
                func_002B4A60(key, t);
                func_0027C448(t, 0x1BFF0C3D, D_00372F7C[0]);
                func_002B4A60(key, t);
            } else {
                func_0027C448(t, 0x1BFF0C3D, D_00372F78[arg0]);
                func_002B4A60(key, t);
            }
            if (t != 0) {
                func_0027AC90(t);
                func_00113250(t);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", func_002B8308);

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", CFunc_GuitarInputLogicInit);

extern "C" void func_002B8ED0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B8088", CFunc_GuitarInputLogicPerFrame);
