#include "common.h"

extern "C" {
void func_0010D818(int, int);
}

struct S_00110170 { char pad0[0x10]; float* unk10; };

struct S_0010EBD8 { int unk0; int unk4; int unk8; int unkC; };

struct S_00110150 { char pad0[0x4]; int unk4; };

extern "C" void func_0010EBD8(S_0010EBD8* self, int a, int b, int c, int d) {
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = c;
    self->unkC = d;
}

extern "C" void func_0010EBF0(void) {
    func_0010D818(1, 0xFFFF);
}
TEXT_PAD(8);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010EC18);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010EC88);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F300);

extern "C" void* func_0010F690(void* p) {
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F698);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6C0);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6F0);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F708);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F720);

extern "C" void* func_0010F748(void* p) {
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F750);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F970);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FC88);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FC90);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FE60);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FED0);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FF48);

extern "C" int func_00110150(S_00110150* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110158);

extern "C" void func_00110170(S_00110170* self, int i, float v) {
    float* p = self->unk10;
    p += i;
    *p = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110188);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110318);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110A00);
