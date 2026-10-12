#include "common.h"

struct S_0011C0B8 { char pad0[0x4]; int unk4; };

struct S_0011C2E8_b { struct S_0011C2E8_b* unk0; };
struct S_0011C2E8 { char pad0[0x10]; int unk10; S_0011C2E8_b* unk14; };

struct S_0011C090 { char pad0[0x4]; int unk4; int unk8; };

extern "C" {
extern int D_00368A94;
extern int D_00368B40[2];
void func_0011B468(void);
void func_0011AB60(void);
extern int D_0032A4A0[];
}

struct S_0011AF08 { char pad0[0xC]; int unkC; };

extern "C" void func_0011AEB0(void) {
    D_00368A94--;
}

extern "C" int func_0011AEC0(void) {
    return D_0032A4A0[D_00368A94];
}

extern "C" void func_0011AEE0(void) {
}

extern "C" void func_0011AEE8(void) {
}

extern "C" int func_0011AEF0(void) {
    return 0;
}

extern "C" int func_0011AEF8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011AF00);

extern "C" int func_0011AF08(S_0011AF08* self) {
    return self->unkC;
}

extern "C" int func_0011AF10(void) {
    return 0;
}

extern "C" int func_0011AF18(void) {
    return 0;
}

extern "C" int func_0011AF20(void) {
    return 0;
}

extern "C" int func_0011AF28(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011AF30);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011AF90);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011AFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011B030);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011B468);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011B4C0);

extern "C" void func_0011BA28(void) {
    func_0011B468();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BA48);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BB28);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BC38);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BD30);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BD98);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BF98);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C030);

extern "C" S_0011C090* func_0011C090(S_0011C090* self, int n) {
    int v = self->unk4 + n;
    self->unk4 = v;
    if (self->unk8 < v) self->unk8 = v;
    return self;
}

extern "C" S_0011C0B8* func_0011C0B8(S_0011C0B8* self, int v) {
    self->unk4 -= v;
    return self;
}

extern "C" void func_0011C0D0(void) {
    func_0011AB60();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C0F0);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C130);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C248);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C2A8);

extern "C" void func_0011C2E8(S_0011C2E8* self, S_0011C2E8_b* n) {
    self->unk10--;
    n->unk0 = self->unk14;
    self->unk14 = n;
}

extern "C" void func_0011C308(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C310);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C408);

extern "C" int func_0011C458(int i) {
    return D_00368B40[i];
}

extern "C" int func_0011C470(u32 v) {
    if (v < 2) return 12;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C480);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C4C0);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011CCC8);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011CE00);
