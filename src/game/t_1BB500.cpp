#include "common.h"

extern "C" {
extern u32 D_0036CAE0;
extern s32 D_0036CAE4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BB500);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BB680);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BCD88);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD120);

extern "C" void func_001BD128(void) {
    D_0036CAE4 = 0;
    D_0036CAE0 = 0xFFFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD140);

extern "C" s32 func_001BD150(void) {
    return 0xFFFF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD158);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD178);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD438);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD458);
