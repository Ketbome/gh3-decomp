#include "common.h"

extern "C" {
bool func_0027D870_b(int, int, int *, int) asm("func_0027D870");
bool func_0027D1F8_b(int, int, int *, int) asm("func_0027D1F8");
bool func_0027D268_b(int, int, float *, int) asm("func_0027D268");
int func_002763E0(int, int);
int func_002764E8(int, int);
int func_0027D268(int, int, float *, int);
int func_002C07E8(float, int, int, int, int);
int func_0027D870(int, int, int *, int);
int func_0027D1F8(int, int, int *, int);
void func_002C1390(int, int, int);
int func_00275F08(int, int);
extern int D_003E7F48[];
struct S2C0_Tbl {
    char pad0[4];
    int unk4;
};
struct S2C0_Obj {
    char pad0[0xA0];
    char unkA0[0x154];
    float unk1F4;
};
float func_00260D08(void);
float func_0031B4B8(float);
float func_0027EFA0(void *, int);
void func_001395D8(void *, int, float, float);
void func_00139AE8(void *, int, int, float, float);
float func_002D8368(void *);
float func_002EC100(float);
extern float D_00371FD0;
extern float D_003C7FC8[];
extern float D_003C3FC8[];
extern float D_003C4FC8[];
extern float D_003C5FC8[];
extern float D_003BFFC8[];
extern float D_003C0FC8[];
extern float D_003C1FC8[];
extern float D_003C2FC8[];
extern S2C0_Obj *D_003BEFC8[];
extern int D_003C9FC8[];
void func_002C25D0(int);
}

extern "C" int CFunc_FillInputArray(int a) {
    int s0;
    float f;
    int s8;
    int sC;
    int s10;
    if (func_0027D870(a, 0x1BFF0C3D, &s0, 0)) {
        int h = func_002763E0(s0, 1);
        if ((func_0027D268_b(a, 0x906B67BA, &f, 0) ^ 1) == 0 && (func_0027D870_b(a, 0xCC12115E, &s8, 0) ^ 1) == 0) {
            int o = func_002764E8(s8, 1);
            if ((func_0027D1F8_b(a, 0x5CA15C8F, &sC, 0) ^ 1) == 0 && (func_0027D870_b(a, 0xE60DD9FC, &s10, 0) ^ 1) == 0) {
                return func_002C07E8(f, h, sC, o, s10);
            }
        }
        return 0;
    }
    return 0;
}

GP_DATA(D_00371FD0);
extern "C" void func_002C10E8(int i, float a, float b) {
    float d = D_00371FD0 / D_003C7FC8[i];
    D_003C3FC8[i] = a;
    D_003C4FC8[i] = b;
    if (d < 0.0f) d = -d;
    S2C0_Tbl *p = (S2C0_Tbl *)func_002764E8(0x1BF47D6B, 1);
    int n = p->unk4;
    void *q = (void *)func_002764E8(0x472D71B8, 1);
    float x = (func_00260D08() - D_003C5FC8[i]) / d * 1024.0f;
    int k = (int)x % n;
    if (k >= 0) {
        int k2 = (int)(x + 1.0f) % n;
        float fr = x - func_0031B4B8(x);
        float e0 = func_0027EFA0(q, k);
        float e1 = func_0027EFA0(p, k2);
        float e2 = func_0027EFA0(p, k);
        float t = e0;
        t += fr * (e1 - e2);
        float x0 = D_003BFFC8[i];
        float y0 = D_003C0FC8[i];
        S2C0_Obj *o = D_003BEFC8[i];
        func_001395D8(o, 0, x0 + t * (D_003C1FC8[i] - x0), y0 + t * (D_003C2FC8[i] - y0));
        if (D_003C9FC8[i] != 0) {
            float r = 1.5707964f - func_002D8368(o->unkA0);
            float w = o->unk1F4;
            func_00139AE8(o, 0, 1, 0.6f, (1.0f / func_002EC100(r)) * (1.0f / w));
        } else {
            float f = a + t * (b - a);
            func_00139AE8(o, 0, 1, f, f);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C1390);

extern "C" int CFunc_LaunchGemEvent(int arg0) {
    int a[2];
    if (func_0027D870(arg0, 0xC451F558, &a[0], 1) != 0) {
        func_002C1390(a[0], func_0027D1F8(arg0, 0x67E6859A, &a[1], 0), a[1] - 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_ResetPulseEvents);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_AddPulseEvent);

extern "C" void func_002C25D0(int a) {
    if (func_00275F08(0xA2660D69, 1) != 1) {
        return;
    }
    int *p = &D_003E7F48[a];
    if (*p == 0) {
        *p = 3;
    }
}

extern "C" s32 CFunc_LaunchPulseEvent(void) {
    func_002C25D0(0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_RunQueuedPulseEvents);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_CameraCut_GetArraySize);
