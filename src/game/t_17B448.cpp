#include "common.h"

struct S0017B460 {
    char pad[0x14];
    void* unk14;
};

extern "C" {
extern u8 D_00342B38[];
void func_00172A00(void*);
extern u8 D_00342CB8[];
extern u8 D_00342E28[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B448);

extern "C" void func_0017B460(S0017B460* self) {
    self->unk14 = D_00342B38;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B488);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B528);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B548);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B678);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B810);

extern "C" void func_0017BAE8(void) {
}

extern "C" u32 func_0017BAF0(void) {
    return 0x1BF9C2D5 /* applydifference */;
}

extern "C" void func_0017BB00(S0017B460* self) {
    self->unk14 = D_00342CB8;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017BB28);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017BD50);

extern "C" void func_0017C1C0(void) {
}

extern "C" u32 func_0017C1C8(void) {
    return 0x02E58C18 /* ADD */;
}

extern "C" void func_0017C1D8(S0017B460* self) {
    self->unk14 = D_00342E28;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017C200);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017C800);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017CA00);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017CFB8);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017D0E0);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017D2B0);
