#include "common.h"

struct S2A74C0_A {
    char pad0[0x4];
    int *unk4;
};

extern "C" {
extern s32 D_00371EF4;
extern s32 D_00372F30[] __attribute__((section(".sdata")));
extern s32 D_00372F38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A74C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7540);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A75F0);

extern "C" int func_002A7638(S2A74C0_A *p, int i) {
    return p->unk4[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7650);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A77E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A79A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7A40);

GP_DATA(D_00371EF4);
extern "C" void func_002A7D40(void) {
    D_00371EF4 = 0;
    D_00372F30[0] = 0;
    D_00372F38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7D58);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7EF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7F78);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", CFunc_LightShow_Init);
