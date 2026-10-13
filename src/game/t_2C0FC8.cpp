#include "common.h"

extern "C" {
int func_00275F08(int, int);
extern int D_003E7F48[];
void func_002C25D0(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_FillInputArray);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C10E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C1390);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_LaunchGemEvent);

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
