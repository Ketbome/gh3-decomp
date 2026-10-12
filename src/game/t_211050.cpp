#include "common.h"

typedef unsigned int u128_211 __attribute__((mode(TI)));

struct S211 {
    char pad0[0x24];
    u128_211* unk24;
    int unk28;
    char pad2C[0xC];
    f32* unk38;
    int unk3C;
};

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211050);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211BE8);

extern "C" int func_00211DE8(S211* self) {
    return self->unk28;
}

extern "C" u128_211 func_00211DF0(S211* self, int i) {
    u128_211* p = self->unk24;
    p += i;
    return *p;
}

extern "C" int func_00211E08(S211* self) {
    return self->unk3C;
}

extern "C" f32 func_00211E10(S211* self, int i) {
    f32* p = self->unk38;
    p += i;
    return *p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211E28);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_002120B8);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212610);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212628);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212700);

extern "C" S211* func_00212770(S211* self) {
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212778);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212880);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_002128D8);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212930);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212988);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_002129E0);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212B58);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212C30);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212CD8);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212DF0);
