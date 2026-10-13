#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247290);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247650);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248588);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248620);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002486A0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002486B0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248CF0);

extern "C" void func_00248CF8(f32* p) {
    p[2] = 1e7f;
    p[1] = 1e7f;
    p[5] = -1e7f;
    p[0] = 1e7f;
    p[4] = -1e7f;
    p[3] = -1e7f;
}
TEXT_PAD(20);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D40);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D50);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D98);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248E20);

extern "C" void func_00248E60(char* p) {
    struct O { char pad[0x20]; void (*f)(O*); };
    O* o = *(O**)(p + 0x4C);
    o->f(o);
}

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248E88);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002490E0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00249120);
