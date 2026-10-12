#include "common.h"

extern "C" {
void func_001A9128(int, int);
int func_001A46E0(int);
extern int D_0036C660;
extern u8 D_0038C450[];
extern int D_0036C65C;
extern u8 func_001A8560[];
void func_0030CAA8(void*, int, int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A7A50);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8120);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8168);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8198);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A84E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8518);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8520);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8560);

GP_DATA(D_0036C65C);
extern "C" void func_001A85A8(void) {
    func_0030CAA8(D_0038C450, D_0036C65C, 112, func_001A8560);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A85D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8758);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8810);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A88E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8A60);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8B10);

GP_DATA(D_0036C660);
extern "C" int func_001A90D0(void) {
    int r0 = func_001A46E0(0);
    D_0036C660 = r0;
    return r0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A90F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9120);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9128);

extern "C" void func_001A9220(void) {
    func_001A9128(1, 65535);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9240);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9288);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A92D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A93F8);
