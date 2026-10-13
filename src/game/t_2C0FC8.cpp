#include "common.h"

extern "C" {
int func_0027D870(int, int, int *, int);
int func_0027D1F8(int, int, int *, int);
void func_002C1390(int, int, int);
int func_00275F08(int, int);
extern int D_003E7F48[];
void func_002C25D0(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_FillInputArray);

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
