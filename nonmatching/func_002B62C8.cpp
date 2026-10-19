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

struct S2B62_Arr {
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
extern int D_00373038[2];
extern int D_00372040[2];
extern S2B62_Arr *D_00372048[2];
extern int D_00372050[2];
extern S2B62_Arr *D_00372038[2];
extern int D_00372020[2];
extern int D_00372028[2];
extern int D_00372030[2];
int func_0027D870(int, u32, int *, int);
S2B62_Arr *func_002764E8(int, int);
}

GP_DATA(D_00372040);
GP_DATA(D_00372050);
GP_DATA(D_00372048);
GP_DATA(D_00372038);
GP_DATA(D_00372020);
GP_DATA(D_00372028);
GP_DATA(D_00372030);
extern "C" int func_002B62C8(int idx, int params, int *p1, int *p2) {
    int a0;
    int b0;
    int b;
    func_0027D870(params, 0xAC50B976, &a0, 1);
    int a = a0;
    int ok = func_0027CC30(params, 0xCACFE109, 1, &b0);
    b = b0;
    if (ok == 0) {
        func_0027F1E0(params, 0, 1);
        b = 0;
    }
    if (a != D_00373038[idx] || b != D_00372040[idx]) {
        D_00373038[idx] = a;
        D_00372040[idx] = b;
        S2B62_Arr *arr = func_002764E8(a, 1);
        D_00372048[idx] = arr;
        int n = arr->size;
        D_00372050[idx] = n;
        if (n == 0) {
            if (p1) {
                *p1 = 0;
            }
            if (p2) {
                *p2 = 0;
            }
            return 0;
        }
        S2B62_Arr *e = (S2B62_Arr *)arr->Get(D_00372040[idx]);
        D_00372038[idx] = e;
        D_00372010[idx] = ((S2B62_Arr *)D_00372038[idx])->Get(0);
        S2B62_Arr *e2 = D_00372038[idx];
        D_00372018[idx] = e2->Get(1) + D_00372010[idx];
        D_00372020[idx] = D_00372038[idx]->Get(2);
        D_00372030[idx] = -1;
        D_00372028[idx] = -1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B64D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6708);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B68E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6C10);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D90);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D98);

extern "C" float func_002B7108(float *p, float a, float b, float c, float d, float e) {
    float t = a - b * c;
    float r = (t / (d * 1000.0f)) * (e * d);
    if (p) *p = t;
    return r;
}

struct S2B7_Arr {
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
extern S2B7_Arr *D_00371FB0[] __attribute__((section(".sdata")));
extern float D_00373138[];
extern float D_003730F8;
extern float D_003730FC;
}

GP_DATA(D_00371FB0);
INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7140);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B72C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7A60);
