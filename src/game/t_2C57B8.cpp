#include "common.h"

extern "C" {
void func_002C5970(int, int);
int func_0027D870(int, int, int *, int);
int func_002763E0(int, int);
void func_002C5FF0(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_CrowdReset);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C5970);

extern "C" void CFunc_CrowdIncrease(int arg0, int arg1) {
    int out;
    func_0027D870(arg0, 0x1BFF0C3D, &out, 1);
    func_002C5970(arg1, func_002763E0(out, 1));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C5FF0);

extern "C" void CFunc_CrowdDecrease(int arg0, int arg1) {
    int out;
    func_0027D870(arg0, 0x1BFF0C3D, &out, 1);
    func_002C5FF0(arg1, func_002763E0(out, 1));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_GemArrayStepperCompressedBroadcastEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C6B20);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_GemStep);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_NoteFX);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C7688);
