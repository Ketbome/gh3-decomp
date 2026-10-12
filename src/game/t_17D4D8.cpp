#include "common.h"

struct S0017E430 {
    char pad[0x20];
    char unk20;
};

struct S0017D658 {
    int unk0;
    int unk4;
};

extern "C" {
extern int D_0036AA90;
void func_0017DC80(void);
void func_0017E570(void*);
void func_0017D5E0(void*);
}

extern "C" void func_0017D4D8(void) {
}

extern "C" u32 func_0017D4E0(void) {
    return 0x40F44B8A /* modulate */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D580);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D5E0);

extern "C" void func_0017D658(S0017D658* self, int a1, int a2) {
    self->unk0 = a2;
    self->unk4 = a1;
    func_0017D5E0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D680);

extern "C" void func_0017D6B0(void) {
    func_0017DC80();
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DB68);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DC78);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DC80);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DD68);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DFC0);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E068);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E160);

extern "C" void func_0017E430(S0017E430* self) {
    func_0017E570(&self->unk20);
}

extern "C" void func_0017E450(void) {
}

extern "C" u32 func_0017E458(void) {
    return 0x119E1C65 /* motionextractedsource */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E468);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E4B8);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E518);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E570);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E658);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E688);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E878);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017E9B8);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017F1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017F268);

extern "C" int func_0017F280(void) {
    return D_0036AA90 + 1;
}

extern "C" int func_0017F290(void) {
    return D_0036AA90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017F298);

extern "C" u32 func_0017F468(void) {
    return 0xA866A248 /* curve */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017F478);
