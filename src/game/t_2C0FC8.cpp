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

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C10E8);

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
