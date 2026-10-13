#include "common.h"

extern "C" {
extern u8 D_00370044;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245220);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002454C8);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002454D0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245598);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002455A0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245648);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002456B0);

extern "C" void func_00246B08(void) {
}

extern "C" void func_00246B10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246B18);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246B30);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246B78);

extern "C" int func_00246BC0(int* p) {
    return *p & 0xFFFFFFFC;
}

extern "C" int func_00246BD8(int* p) {
    return *p & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246C50);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246C98);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246CC0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246D48);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246E30);

GP_DATA(D_00370044);
extern "C" int func_00246EF0(void) {
    int v = D_00370044 + 1;
    D_00370044 = v;
    return v & 0xFF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246F08);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246F48);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00247020);
