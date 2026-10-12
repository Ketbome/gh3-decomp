#include "common.h"

struct S0018DE88 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_00345910[];
extern u8 D_00345928[];
void func_00167958(void);
extern u8 D_00345A78[];
extern u8 D_00345A90[];
void func_00169A70(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DD30);

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DD68);

extern "C" void func_0018DE88(S0018DE88* self) {
    self->unk20 = D_00345910;
    self->unk8 = D_00345928;
    func_00167958();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DEB8);

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018E6C8);

extern "C" void func_0018E7F0(S0018DE88* self) {
    self->unk20 = D_00345A78;
    self->unk8 = D_00345A90;
    func_00169A70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018E820);

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018FD08);
