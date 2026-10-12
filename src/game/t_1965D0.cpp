#include "common.h"

struct S00198160 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

struct S_00197ED8 { char pad0[0x1E8]; int unk1E8; };

extern "C" {
void func_0016CD28(void);
extern u8 D_00346C78[];
extern u8 D_00346C90[];
void func_00167D70(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001965D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001966C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00196D10);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00196EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197398);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001973F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197E30);

extern "C" int func_00197ED8(S_00197ED8* self) {
    return self->unk1E8 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197FC8);

extern "C" void func_00198020(void) {
    func_0016CD28();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00198040);

extern "C" void func_00198160(S00198160* self) {
    self->unk20 = D_00346C78;
    self->unk8 = D_00346C90;
    func_00167D70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00198190);
