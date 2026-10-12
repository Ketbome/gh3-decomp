#include "common.h"

struct S0018FE28 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_00345BE0[];
extern u8 D_00345BF8[];
void func_00169E70(void);
extern u8 D_00345D48[];
extern u8 D_00345D60[];
void func_00168170(void);
extern u8 D_00345EB0[];
extern u8 D_00345EC8[];
void func_0016ABA0(void);
}

extern "C" void func_0018FE28(S0018FE28* self) {
    self->unk20 = D_00345BE0;
    self->unk8 = D_00345BF8;
    func_00169E70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_0018FE58);

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_00190870);

extern "C" void func_001909A8(S0018FE28* self) {
    self->unk20 = D_00345D48;
    self->unk8 = D_00345D60;
    func_00168170();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_001909D8);

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_00191310);

extern "C" void func_00191460(S0018FE28* self) {
    self->unk20 = D_00345EB0;
    self->unk8 = D_00345EC8;
    func_0016ABA0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_00191490);

INCLUDE_ASM("asm/nonmatchings/game/t_18FE28", func_00191DF0);
