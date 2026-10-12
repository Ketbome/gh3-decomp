#include "common.h"

extern "C" {
int func_002C25D0(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_FillInputArray);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C10E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C1390);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_LaunchGemEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_ResetPulseEvents);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_AddPulseEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", func_002C25D0);

extern "C" s32 CFunc_LaunchPulseEvent(void) {
    func_002C25D0(0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_RunQueuedPulseEvents);

INCLUDE_ASM("asm/nonmatchings/game/t_2C0FC8", CFunc_CameraCut_GetArraySize);
