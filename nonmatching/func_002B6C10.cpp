#include "common.h"

extern "C" {
int func_002B6098(int);
extern int D_00372010[2];
extern int D_00372018[2];
void func_002B4B98(int, int, int);
extern int D_00371F90[2];
int func_0027CC30(int, u32, int, int *);
void func_0027F1E0(int, int, int);
int func_00275F08(u32, int);
void func_0027AC90(int);
void func_00113250(int);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027C160(int, u32, int);
void func_0027C448(int, u32, int);
void func_002B4A18(int, int);
void func_002C1390(u32, int, int);
int func_002B6270(int, int);
extern int D_00371FF8;
extern int D_00372FA8[];
extern int D_00373018[];
extern int D_00373128[];
int func_002B5990(int, int, u32, int, int, int, float, float);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5C08);

GP_DATA(D_00371F90);
extern "C" int func_002B5CA8(int a, int b) {
    int v;
    int w;
    int t = D_00371F90[b];
    if (func_0027CC30(t, 0x92BE3D33, 1, &v) == 0) {
        func_0027F1E0(t, 0, 1);
        w = 0;
    } else {
        w = v;
    }
    if (w == 1)
        return 0;
    if (func_00275F08(0x392E3940, 1) == 1)
        return func_002B5990(a, b, 0x55997319, 0, 0, 0, 4.0f, 0.0f);
    return func_002B5990(a, b, 0x55997319, 0, 0, 1, 4.0f, 1.0f);
}

extern "C" void func_002B5DA0(int i) {
    int *p = &D_00371F90[i];
    func_002B4B98(*p, 0x907542B6, 0);
    func_002B4B98(*p, 0xE59AA425, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5DF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6098);

GP_DATA(D_00372010);
GP_DATA(D_00372018);
extern "C" int func_002B6270(int a, int b) {
    if (b >= D_00372010[a]) {
        if (b < D_00372018[a]) {
            return func_002B6098(a);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B62C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B64D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6708);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B68E8);

GP_DATA(D_00371FF8);
extern "C" void func_002B6C10(int a, int b) {
    int v;
    int w;
    int t = D_00371F90[a];
    if (func_0027CC30(t, 0x92BE3D33, 1, &v) == 0) {
        func_0027F1E0(t, 0, 1);
        w = 0;
    } else {
        w = v;
    }
    if (D_00371FF8 == 0 || a != 1) {
        if (w == 1)
            func_002C1390(0x40A43492, 1, a);
        func_002B4B98(D_00371F90[a], 0x907542B6, 0);
        int e = func_0027AA70(func_001287F0(8, 1));
        func_0027C160(e, 0x5CA15C8F, *(int *)((char *)D_00373128 + a * 4));
        func_0027C448(e, 0xCC12115E, *(int *)((char *)D_00373018 + a * 4));
        func_002B6270(a, b);
        func_002B4A18(D_00372FA8[a], e);
        func_002C1390(0xF9A5058C, 1, a);
        if (e) {
            func_0027AC90(e);
            func_00113250(e);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D90);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D98);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7108);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7140);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B72C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7A60);
