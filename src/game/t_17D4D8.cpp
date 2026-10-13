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
void func_0017D580(void*, int);
void func_00119400(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_0017E658(void*, float);
void func_0017D658_2(void*, void*) __asm__("func_0017D658");
void func_0017E4B8(void*, int);
void func_00172A00(void*, int);
extern u8 D_00343328[];
int func_00124630(int);
void func_0017DC80(void);
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

struct S17D680 { char pad0[0xC]; int unkC; char pad10[8]; int unk18; };

extern "C" void func_0017D680(S17D680* self) {
    func_0017DC80();
    self->unk18 = func_00124630(self->unkC);
}

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

struct S17E468 { char pad0[0x14]; void* unk14; char pad18[8]; char unk20[1]; };

extern "C" void func_0017E468(S17E468* self, int a) {
    self->unk14 = D_00343328;
    func_0017E4B8(self->unk20, 2);
    func_00172A00(self, a);
}

struct O17E4B8 { char pad0[0x58]; int unk58; };
struct S17E4B8 { char pad0[0x1C]; O17E4B8* unk1C; };

extern "C" void func_0017E4B8(void* p, int flags) {
    S17E4B8* self = (S17E4B8*)p;
    O17E4B8* o = self->unk1C;
    if (o) o->unk58 = o->unk58 - 1;
    func_0017D580(self, 2);
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

typedef unsigned int u128_17D __attribute__((mode(TI)));
struct O17E518 { char pad0[0x58]; int unk58; };
struct S17E518 { char pad0[0x1C]; O17E518* unk1C; char pad20[0x10]; u128_17D unk30; u128_17D unk40; u128_17D unk50; u128_17D unk60; };

extern "C" void func_0017E518(S17E518* self, O17E518* o) {
    self->unk1C = o;
    o->unk58 = o->unk58 + 1;
    func_0017D658_2(self, self->unk1C);
    func_0017E658(self, 0.0f);
    self->unk50 = self->unk30;
    self->unk60 = self->unk40;
}

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
