#include "common.h"

struct S0018D710 {
    char pad[0x8];
    int unk8;
};

struct S0018BF00 {
    char pad[0x28];
    int unk28;
};

struct S0018B9C0 {
    char pad[0x24];
    int unk24;
};

struct S0018D6E8 {
    char pad[0x4];
    void* unk4;
};

extern "C" {
void func_001ACF30(int);
void func_001AD230(int);
void func_001AD400(int);
void func_001B05B8(int);
void func_001AE520(int, int, int);
void func_001AD360(int, int);
void func_001AEFF0(int, int, int);
void func_001AE7A0(int, int, int);
void func_001AF090(int, int, int);
void func_001AD2B8(int, int, int);
extern u8 D_00345258[];
void func_0015F9D0(void*);
}

extern "C" void func_0018B9C0(S0018B9C0* self) {
    func_001ACF30(self->unk24);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018B9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BA88);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BAE8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BB28);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BBD0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BC08);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BC30);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BCA8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BCD0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BD68);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BE00);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BE88);

extern "C" int func_0018BF00(S0018BF00* self) {
    return self->unk28 + 48;
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BF10);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BF68);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BFB8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C150);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C368);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C3F8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C428);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C658);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C7B8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C948);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CB98);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CC08);

extern "C" void func_0018CC78(S0018B9C0* self) {
    func_001AD230(self->unk24);
}

extern "C" void func_0018CC98(S0018B9C0* self, int a1) {
    func_001AE520(self->unk24, a1, 1);
}

extern "C" void func_0018CCB8(S0018B9C0* self, int a1) {
    func_001AD2B8(self->unk24, 0, a1);
}

extern "C" void func_0018CCE0(S0018B9C0* self) {
    func_001AD360(self->unk24, 1);
}

extern "C" void func_0018CD00(S0018B9C0* self) {
    func_001AD2B8(self->unk24, 16384, 0);
}

extern "C" void func_0018CD28(S0018B9C0* self) {
    func_001AD400(self->unk24);
}

extern "C" void func_0018CD48(S0018B9C0* self, int a1) {
    func_001AEFF0(self->unk24, a1, 1);
}

extern "C" void func_0018CD68(S0018B9C0* self, int a1) {
    func_001AE7A0(self->unk24, a1, 1);
}

extern "C" void func_0018CD88(S0018B9C0* self, int a1) {
    func_001AF090(self->unk24, a1, 1);
}

extern "C" void func_0018CDA8(S0018B9C0* self) {
    func_001B05B8(self->unk24);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CDC8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CEC0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CF48);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D020);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D050);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D118);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D178);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D200);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D280);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D350);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D480);

extern "C" void func_0018D4B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D4B8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D588);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D5E0);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D668);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D6A0);

extern "C" void func_0018D6E8(S0018D6E8* self) {
    self->unk4 = D_00345258;
    func_0015F9D0(self);
}

extern "C" int func_0018D710(S0018D710* self) {
    return self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D718);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D780);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D7B8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D7C0);
