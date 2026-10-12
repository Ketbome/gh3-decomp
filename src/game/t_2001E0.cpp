#include "common.h"

typedef unsigned int u128_200 __attribute__((mode(TI)));

struct S200b {
    char pad0[0x70];
    int unk70;
    int unk74;
    char pad78[0x8];
    u128_200 unk80;
};

struct S200 {
    char pad0[0xC];
    S200b* unkC;
    char pad10[0xC];
    int unk1C;
    int unk20;
    char pad24[0x4];
    int unk28;
    int unk2C;
    int unk30;
    char pad34[0x19C];
    int unk1D0;
    int unk1D4;
    char pad1D8[0x8];
    int unk1E0;
    char pad1E4[0xC];
    u128_200 unk1F0;
    int unk200;
    char pad204[0xC];
    f32 unk210;
    char pad214[0x14];
    S200b* unk228;
};

extern "C" {
void func_002001E8(int, int);
void* func_00113D20(u32 size);
void* func_00200380(void* self);
void func_00276D48(u32 key, void* data, int size);
extern u8 D_0038F928[];
int func_00200920(S200*);
void func_00202258(S200*);
void func_002024B0(S200*, int, int, int);
int func_00204828(S200*);
void func_002028D8(S200*);
void func_00202828(S200*);
void func_00202960(S200*, int, int);
void func_00201DE8(S200*, int, u128_200*);
void func_00202D50(S200*);
void func_00203138(S200*, int, int, int);
void func_00203208(S200*);
void func_002044F8(S200*);
int func_0027D058(int, int, int*, int);
void func_00202ED0(S200*, int, int, u128_200, int);
int func_00200930(int, int*);
int func_00200958(int, int*);
void func_00204248(S200*);
S200b* func_00201A38(S200*);
void func_00201C80(S200*, int);
void func_00202C88(S200*, int, int);
void func_00289F48(int, int, void*, int);
int func_00200910(S200*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002001E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002001E8);

extern "C" void func_00200308(void) {
    func_002001E8(1, 0xFFFF);
}

extern "C" void* func_00200328(void) {
    return func_00200380(func_00113D20(0x2B0));
}

extern "C" void func_00200350(void) {
    func_00276D48(0x0A015E17, D_0038F928, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200380);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200428);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002004C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200520);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002005E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200618);

extern "C" int func_00200910(S200* self) {
    return (self->unk1C & 0x18) != 0;
}

extern "C" int func_00200920(S200* self) {
    return (self->unk1C & 0x27) != 0;
}

extern "C" int func_00200930(int key, int* out) {
    return func_0027D058(key, 0, out, 0);
}

extern "C" int func_00200958(int key, int* out) {
    return func_0027D058(key, 0, out, 0);
}

extern "C" void func_00200980(S200* self) {
    S200b* p = self->unkC;
    union {
        u128_200 q;
        f32 f[4];
    } v;
    v.q = p->unk80;
    v.f[1] -= self->unk210;
    p->unk80 = v.q;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002009B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200A70);

extern "C" int func_00200AA0(S200* self) {
    return func_00200920(self) != 0;
}

extern "C" int func_00200AC0(S200* self) {
    self->unk1F0 = self->unkC->unk80;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200AD8);

extern "C" int func_00200B08(S200* self) {
    self->unk1C &= ~0x18;
    return 1;
}

extern "C" int func_00200B20(S200* self) {
    self->unk1C &= ~0x67;
    return 1;
}

extern "C" int func_00200B38(S200* self, int key) {
    func_00200930(key, &self->unk30);
    return 1;
}

extern "C" int func_00200B60(S200* self, int key) {
    func_00200930(key, &self->unk1E0);
    return 1;
}

extern "C" int func_00200B88(S200* self, int key) {
    func_00200958(key, &self->unk28);
    return 1;
}

extern "C" int func_00200BB0(S200* self, int key) {
    func_00200958(key, &self->unk2C);
    return 1;
}

extern "C" int func_00200BD8(S200* self) {
    func_00202258(self);
    return 1;
}

extern "C" int func_00200BF8(S200* self, int a, int b) {
    func_002024B0(self, a, b, 0);
    return 1;
}

extern "C" int func_00200C18(S200* self, int a, int b) {
    func_002024B0(self, a, b, 1);
    return 1;
}

extern "C" int func_00200C38(S200* self, int a, int b) {
    func_002024B0(self, a, b, 2);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200C58);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200D28);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200DB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200E10);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200E68);

extern "C" int func_00200EC8(S200* self, int a) {
    self->unk20 &= ~8;
    func_00201C80(self, a);
    return 1;
}

extern "C" int func_00200EF8(S200* self) {
    return func_00204828(self) != 0;
}

extern "C" int func_00200F18(S200* self) {
    func_002028D8(self);
    return 1;
}

extern "C" int func_00200F38(S200* self) {
    func_00202828(self);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200F58);

extern "C" int func_00200FA8(S200* self, int a) {
    func_00202960(self, a, 1);
    return 1;
}

extern "C" int func_00200FC8(S200* self, int a) {
    func_00201DE8(self, a, &self->unk1F0);
    return 1;
}

extern "C" int func_00200FE8(S200* self, int a) {
    func_00202960(self, a, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201008);

extern "C" int func_002010A0(S200* self) {
    self->unk20 &= ~8;
    return 1;
}

extern "C" int func_002010B8(S200* self, int a, int b) {
    self->unk20 &= ~8;
    func_00202C88(self, a, b);
    return 1;
}

extern "C" int func_002010E8(S200* self) {
    func_00202D50(self);
    return 1;
}

extern "C" int func_00201108(S200* self, int a, int b) {
    func_00202ED0(self, a, b, self->unk1F0, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201130);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002011C0);

extern "C" int func_00201250(S200* self, int a, int b) {
    func_00203138(self, a, b, 1);
    return 1;
}

extern "C" int func_00201270(S200* self, int a, int b) {
    func_00203138(self, a, b, 0);
    return 1;
}

extern "C" int func_00201290(S200* self) {
    func_00203208(self);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002012B0);

extern "C" int func_002013A0(S200* self, int a, int b) {
    func_00289F48(b, 0xA, self, 0);
    return 1;
}

extern "C" int func_002013D0(S200* self, int a, int b) {
    func_00289F48(b, 0xC, self, 0);
    return 1;
}

extern "C" int func_00201400(S200* self, int a, int b) {
    func_00289F48(b, 0x8, self, 0);
    return 1;
}

extern "C" int func_00201430(S200* self, int a, int b) {
    func_00289F48(b, 0xB, self, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201460);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201500);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002015F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201730);

extern "C" int func_002018C0(S200* self) {
    func_002044F8(self);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002018E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201980);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002019E8);

extern "C" S200b* func_00201A38(S200* self) {
    return self->unk228;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201A40);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201A70);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201BF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201C80);

extern "C" int func_00201CE0(S200* self) {
    return (self->unk20 >> 9) & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00202158);
