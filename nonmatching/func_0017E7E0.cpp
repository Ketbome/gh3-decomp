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
void func_00124688(int, int);
void func_001CE888(int, void*);
void func_0014EBC8(int);
extern u8 D_003434A8[];
extern u8 D_003417B0[];
void func_0017D580(void*, int);
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_0017E658(void*, float);
void func_0017D658_2(void*, void*) __asm__("func_0017D658");
void func_0017E4B8(void*, int);
void func_00172A00(void*, int);
extern u8 D_00343328[];
int func_00124630(int);
void func_0017DC80(void);
void func_00220578(int, int);
extern int D_0036AA90;
void func_0017DC80(void);
void func_0017E570(void*);
void func_0017D5E0(void*);
}

inline void operator delete[](void* p) {
    Heap_Free(D_00368A38[0], p);
}

struct E_0017DFC0B {
    char pad0[0xC];
    virtual ~E_0017DFC0B();
};

struct E_0017DFC0 : E_0017DFC0B {
    char pad10[0xC];
};

struct S_0017DFC0 { E_0017DFC0* unk0; int unk4; int unk8; int unkC; };

extern "C" void func_0017D4D8(void) {
}

extern "C" u32 func_0017D4E0(void) {
    return 0x40F44B8A /* modulate */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017D580);

struct S17D5E0 { char pad0[8]; int unk8; int unkC; char pad10[8]; int unk18; };

extern "C" void func_0017D5E0(void* p) {
    S17D5E0* self = (S17D5E0*)p;
    int* pc = &self->unkC;
    if (self->unkC) {
        func_00124688(self->unkC, self->unk18);
        if (self->unkC) {
            func_001CE888(self->unkC, pc);
            self->unkC = 0;
        }
        self->unkC = 0;
    }
    if (self->unk8) {
        func_0014EBC8(self->unk8);
        self->unk8 = 0;
    }
    self->unk18 = -1;
}

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

struct O_0017DB68 { char pad0[0xC]; float* unkC; };
struct P_0017DB68 { char pad0[0x3C]; char* unk3C; };
struct S_0017DB68 { char pad0[4]; P_0017DB68* unk4; int unk8; O_0017DB68* unkC; char pad10[8]; int unk18; };
extern "C" {
void func_0017D6B0_p(void*) __asm__("func_0017D6B0");
int func_0016E7A8_i(int, int) __asm__("func_0016E7A8");
void func_001CE868(void*, void*);
void func_001CE888_p(void*, void*) __asm__("func_001CE888");
void func_001277C0(void*, int, int, int, int, int, float, float);
}
extern "C" void func_0017DB68(S_0017DB68* self, int x, float a, float b) {
    int f = 0;
    if (self->unk8 != 0 || self->unk18 != -1) {
        f = 1;
    }
    if (f == 0) {
        func_0017D6B0_p(self);
    }
    if (self->unk8 != 0) {
        void* pc = &self->unkC;
        O_0017DB68* n = (O_0017DB68*)func_0016E7A8_i(self->unk8, 0);
        if (self->unkC) {
            func_001CE888_p(self->unkC, pc);
            self->unkC = 0;
        }
        self->unkC = n;
        if (n) {
            func_001CE868(n, pc);
        }
    }
    O_0017DB68* o = self->unkC;
    func_001277C0(o, x, x + 0x820, *(int*)(self->unk4->unk3C + 0x1C) + 0xC, 0, self->unk8, b * o->unkC[2], a);
    if (self->unk8 != 0) {
        func_0016E7A8_i(self->unk8, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DC78);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DC80);

INCLUDE_ASM("asm/nonmatchings/game/t_17D4D8", func_0017DD68);

extern "C" void func_0017DFC0(S_0017DFC0* self) {
    if (self->unk0) {
        self->unk4 = 0;
        delete[] self->unk0;
        self->unk0 = 0;
    }
    if (self->unkC) {
        func_00220578(self->unkC, self->unk8);
    }
    self->unk8 = 0;
}

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
        Heap_Free(D_00368A38[0], self);
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

struct S17E7E0 { char pad0[0x20]; float unk20; char pad24[0xC]; u128_17D unk30; u128_17D unk40; };
extern "C" {
void func_0017F1A8(S17E7E0*, u128_17D*, u128_17D*);
void func_0017E878(S17E7E0*, u128_17D, u128_17D, u128_17D, u128_17D, int, int);
}

extern "C" void func_0017E7E0(S17E7E0* self, int a, int b, int flag, float f) {
    u128_17D sp10;
    u128_17D sp0;
    func_0017F1A8(self, &sp0, &sp10);
    if (flag != 0) func_0017E878(self, self->unk30, self->unk40, sp0, sp10, a, b);
    self->unk30 = sp0;
    self->unk40 = sp10;
    self->unk20 = f;
}

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

struct S17F478 { void* unk0; char pad4[4]; void* unk8; };

extern "C" void func_0017F478(S17F478* self, int flags) {
    self->unk0 = D_003434A8;
    void* p = self->unk8;
    if (p) Heap_Free(D_00368A38[0], p);
    self->unk0 = D_003417B0;
    if (flags & 1) Heap_Free(D_00368A38[0], self);
}
