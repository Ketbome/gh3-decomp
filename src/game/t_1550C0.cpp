#include "common.h"

struct S_001563B0 { char pad0[0x60]; int unk60; };

extern "C" {
void func_001551A8(void);
void func_001561C8(int);
void func_00156878(int, int);
void* func_00113D20(u32 size);
void* func_00154670(void*);
}

struct S_00156FA8 { char pad0[0x160]; };

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001550C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155128);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155138);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155170);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001551A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155290);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001552E8);

extern "C" void func_001552F0(void) {
    func_001551A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155310);

extern "C" void* func_00155640(void) {
    return func_00154670(func_00113D20(0x90));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155668);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155788);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155D40);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001561C8);

extern "C" void func_001563B0(S_001563B0* self) {
    func_001561C8(self->unk60);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001563D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156470);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156550);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156590);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001565D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001566B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156790);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156870);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156878);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156978);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156AB0);

extern "C" void func_00156B40(void) {
    func_00156878(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156B60);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156C88);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156DF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156E00);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156F80);

extern "C" S_00156FA8* func_00156FA8(S_00156FA8* p, int n) {
    n--;
    return &p[n];
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156FC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156FD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00157098);
