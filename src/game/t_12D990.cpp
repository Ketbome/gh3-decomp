#include "common.h"

struct S_0012E600 { char pad0[0x4]; int unk4; int unk8; int unkC; int unk10; void* unk14; };

extern "C" {
void func_0012E668(void);
extern u8 D_00339D88[];
}

struct S_0012DA38 { char pad0[0x3C]; int unk3C; };
struct S_0012DA40 { char pad0[0x3C]; int unk3C; };
struct S_0012E5F0 { char pad0[0x68]; int unk68; };

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012D990);

extern "C" void func_0012D9F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DA00);

extern "C" int func_0012DA38(S_0012DA38* self) {
    return self->unk3C;
}

extern "C" void func_0012DA40(S_0012DA40* self, int v) {
    self->unk3C = v;
}

extern "C" int func_0012DA48(S_0012DA38* self) {
    return func_0012DA38(self) == 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DA70);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DF30);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E228);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E290);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E410);

extern "C" int func_0012E5F0(S_0012E5F0* self) {
    return self->unk68;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E5F8);

extern "C" S_0012E600* func_0012E600(S_0012E600* self, int a) {
    self->unk4 = a;
    self->unk10 = 0;
    self->unk14 = D_00339D88;
    self->unk8 = 0;
    self->unkC = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E628);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E668);

extern "C" void func_0012E6B0(void) {
}

extern "C" int func_0012E6B8(void) {
    return 0;
}

extern "C" void func_0012E6C0(void) {
}

extern "C" int func_0012E6C8(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E6F0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E728);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E790);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E818);

extern "C" void func_0012E870(void) {
    func_0012E668();
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E890);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EA80);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EB68);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EC20);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012ED80);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EE08);

extern "C" void func_0012EE68(void) {
    func_0012E668();
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EE88);

extern "C" void func_0012EF48(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EF50);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EFE0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F040);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F228);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F258);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F2E0);

extern "C" void func_0012F348(void) {
    func_0012E668();
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F368);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F3E0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F5B0);

extern "C" void func_0012F618(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F620);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F958);

extern "C" void func_0012F980(void) {
    func_0012E668();
}
