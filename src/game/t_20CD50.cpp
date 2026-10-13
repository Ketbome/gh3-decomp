#include "common.h"

extern "C" {
s32 func_0010C050(s32 n);
}

INCLUDE_ASM("asm/nonmatchings/game/t_20CD50", func_0020CD50);

INCLUDE_ASM("asm/nonmatchings/game/t_20CD50", func_0020CE80);

INCLUDE_ASM("asm/nonmatchings/game/t_20CD50", func_0020D2F0);

INCLUDE_ASM("asm/nonmatchings/game/t_20CD50", func_0020D878);

extern "C" f32* func_0020EA48(f32* p) {
    s32* q = (s32*)((char*)p + 0x10);
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    s32 r = func_0010C050(0x2710);
    register f32 k asm("$f20") = 6.2831855f;
    *p = (f32)r * k * 0.0001f;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20CD50", func_0020EAC0);
