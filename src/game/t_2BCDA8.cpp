#include "common.h"

extern "C" {
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern s32 D_00371FF0;
extern s32 D_003720D0;
s32 func_00118F20(s32, int, int, int);
s32 func_002D58B0(s32, int, int);
int func_002D5B48(s32, int);
}

extern "C" s32 func_002BCDA8(void) {
    return 0;
}

extern "C" s32 func_002BCDB0(void) {
    if (D_00371FF0 == 0) {
        D_00371FF0 = func_002D58B0(func_00118F20(D_00368A38[0], 0x1C, 1, 0), 2, 0);
    }
    return 1;
}

extern "C" s32 func_002BCE00(void) {
    if (D_00371FF0 != 0) {
        func_002D5B48(D_00371FF0, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BCE28);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BCFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD108);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD1C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD360);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD550);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BD918);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDBA0);

extern "C" s32 func_002BDC40(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDC48);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDCD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE158);

extern "C" s32 func_002BE278(void) {
    D_003720D0 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE288);

extern "C" s32 func_002BE5F0(void) {
    return 1;
}

extern "C" s32 func_002BE5F8(void) {
    return 1;
}

extern "C" s32 func_002BE600(void) {
    return 1;
}

extern "C" s32 func_002BE608(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE610);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE730);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE840);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE9D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BEBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BECF0);
