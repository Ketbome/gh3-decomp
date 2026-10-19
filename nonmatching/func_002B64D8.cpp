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

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B62C8);

struct S2B64_Arr {
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
extern int D_00372020[2];
extern int D_00372028[2];
extern int D_00372030[2];
extern int D_00373008;
extern int D_00373104;
extern int D_00371FA8;
int func_002B62C8(int, int, int *, int *);
}

GP_DATA(D_00372030);
GP_DATA(D_00372028);
GP_DATA(D_00372020);
extern "C" int func_002B64D8(int t, S2B64_Arr *arr, int ai, int params, int *p1, int *p2) {
    int flag = 0;
    if (D_00373008 == 0x2AED7570 || D_00373104 == 1 || D_00371FA8 == 1) {
        flag = 1;
    }
    if (flag) {
        return 0;
    }
    int v;
    int w;
    int ok = func_0027CC30(params, 0x67E6859A, 1, &v);
    w = v;
    if (ok == 0) {
        func_0027F1E0(params, 0, 1);
        w = 0;
    }
    int k = w - 1;
    if (func_002B62C8(k, params, p1, p2)) {
        int off = k * 4;
        int *tab = D_00372018;
        int *pl = (int *)((char *)tab + off);
        while (t >= *pl) {
            if (!func_002B6098(k)) {
                break;
            }
        }
        if (t >= D_00372010[k] && t < *pl) {
            if (t != D_00372030[k]) {
                D_00372030[k] = t;
                D_00372028[k]++;
            }
            if (p1) {
                *p1 = D_00372020[k];
            }
            if (p2) {
                S2B64_Arr *e = (S2B64_Arr *)arr->Get(ai);
                int v2 = e->Get(7);
                if (v2 < tab[k]) {
                    *p2 = 0;
                } else {
                    *p2 = 1;
                    return 1;
                }
            }
            return 1;
        }
        if (p1) {
            *p1 = D_00372020[k];
        }
        if (p2) {
            *p2 = 0;
        }
    }
    return 0;
}

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
