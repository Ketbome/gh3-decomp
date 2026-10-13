#include "common.h"

extern "C" {
extern int D_0032BFC8[];
int func_001A1330(int);
extern int D_0032BE38[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1658);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A18A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1A18);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A21A8);

extern "C" int func_001A2868(int a, int b, int c) {
    int i = func_001A1330(b) - 1;
    int j = func_001A1330(c) - 1;
    return *(int*)((i * 4 + (char*)D_0032BE38) + j * 0x28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A28C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A2D28);

extern "C" int func_001A3178(int a, int b, int c) {
    int i = func_001A1330(b) - 1;
    int j = func_001A1330(c) - 1;
    return *(int*)((i * 4 + (char*)D_0032BFC8) + j * 0x28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A31D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A3488);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A35B8);
