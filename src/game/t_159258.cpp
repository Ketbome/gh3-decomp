#include "common.h"

struct VE_001596E8 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_001596E8 { char pad0[0x8]; VE_001596E8* unk8; };

struct VE_00159710 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_00159710 { char pad0[0x8]; VE_00159710* unk8; };

struct VE_00159768 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int); };
struct S_00159768 { char pad0[0x8]; VE_00159768* unk8; };

extern "C" {
void func_0011A558(int, int, int);
int func_001881A0(int, int, int, int, int, int);
void func_0011A568(void);
void func_0014F150(void);
int func_0015AE68_r(int) __asm__("func_0015AE68");
void func_0015B4B0(int, void*);
void* func_0015AF80();
int func_00157710(void*, int);
extern u8 D_0033CDC8[];
void func_00188360(void);
}

struct S_001596E0 { int unk0; };

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159258);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159260);

extern "C" int func_001596E0(S_001596E0* self) {
    return self->unk0;
}

extern "C" int func_001596E8(S_001596E8* self) {
    VE_001596E8* e = &self->unk8[26];
    return e->unk4((char*)self + e->unk0);
}

extern "C" int func_00159710(S_00159710* self) {
    VE_00159710* e = &self->unk8[27];
    return e->unk4((char*)self + e->unk0);
}

struct S159738 { int unk0; unsigned int unk4; };

extern "C" void func_00159738(S159738* self, int on) {
    if (on) {
        self->unk4 |= 0x10000;
    } else {
        self->unk4 &= 0xFFFEFFFF;
    }
}

extern "C" int func_00159768(S_00159768* self, int a1, int a2) {
    VE_00159768* e = &self->unk8[34];
    return e->unk4((char*)self + e->unk0, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159790);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159858);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_001598E8);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_001598F0);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159AB8);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_00159E08);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A598);

struct VG_15A5A0 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct VH_15A5A0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int); };
struct V_15A5A0 {
    char pad0[0x18]; VG_15A5A0 unk18;
    char pad20[0xB0]; VG_15A5A0 unkD0;
    char padD8[0x70]; VH_15A5A0 unk148;
};
struct S_15A5A0 { char pad0[8]; V_15A5A0* unk8; };

extern "C" void func_0015A5A0(S_15A5A0* self, int v, int a, int b) {
    int ua = a & 0xFFFF;
    int ub = b & 0xFFFF;
    if (self->unk8->unk18.unk4((char*)self + self->unk8->unk18.unk0) != 0) {
        int* p = (int*)self->unk8->unk18.unk4((char*)self + self->unk8->unk18.unk0);
        p[ub * self->unk8->unkD0.unk4((char*)self + self->unk8->unkD0.unk0) + ua] = v;
    } else {
        self->unk8->unk148.unk4((char*)self + self->unk8->unk148.unk0, v, ua, ub);
    }
}

extern "C" int func_0015A668(void) {
    return 0;
}

extern "C" int func_0015A670(void) {
    return 0;
}

extern "C" int func_0015A678(void) {
    return 0;
}

extern "C" int func_0015A680(void) {
    return 0;
}

extern "C" int func_0015A688(void) {
    return 0;
}

extern "C" int func_0015A690(void) {
    return 0;
}

extern "C" int func_0015A698(void) {
    return 0;
}

extern "C" int func_0015A6A0(void) {
    return 0;
}

extern "C" int func_0015A6A8(void) {
    return 0;
}

extern "C" int func_0015A6B0(void) {
    return 0;
}

extern "C" int func_0015A6B8(void) {
    return 0;
}

extern "C" int func_0015A6C0(void) {
    return 0;
}

extern "C" int func_0015A6C8(void) {
    return 0;
}

extern "C" int func_0015A6D0(void) {
    return 0;
}

extern "C" int func_0015A6D8(void) {
    return 0;
}

extern "C" int func_0015A6E0(void) {
    return 0;
}

extern "C" void func_0015A6E8(void) {
}

extern "C" int func_0015A6F0(void) {
    return 0;
}

extern "C" int func_0015A6F8(void) {
    return 0;
}

extern "C" int func_0015A700(void) {
    return 0;
}

extern "C" int func_0015A708(void) {
    return 0;
}

extern "C" int func_0015A710(void) {
    return 0;
}

extern "C" int func_0015A718(void) {
    return 0;
}

extern "C" int func_0015A720(void) {
    return 0;
}

extern "C" int func_0015A728(void) {
    return 0;
}

extern "C" void func_0015A730(void) {
}

extern "C" int func_0015A738(void) {
    return 0;
}

extern "C" int func_0015A740(void) {
    return 0;
}

extern "C" int func_0015A748(void) {
    return 0;
}

extern "C" int func_0015A750(void) {
    return 0;
}

extern "C" int func_0015A758(void) {
    return 0;
}

extern "C" int func_0015A760(void) {
    return 0;
}

extern "C" int func_0015A768(void) {
    return 0;
}

extern "C" void func_0015A770(void) {
}

extern "C" void func_0015A778(void) {
}

extern "C" void func_0015A780(void) {
}

extern "C" void func_0015A788(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A790);

extern "C" void func_0015A7A8(void) {
}

extern "C" void func_0015A7B0(void) {
}

struct S15A7B8 { int unk0; s16 unk4; s16 unk6; int unk8; char padC[4]; void* unk10; };

extern "C" S15A7B8* func_0015A7B8(S15A7B8* self, int a, int b) {
    self->unk0 = a;
    self->unk10 = D_0033CDC8;
    self->unk4 = 1;
    self->unk6 = 0;
    self->unk8 = 0;
    if (b) {
        int one = 1;
        self->unk6 = one;
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A7F0);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015A880);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015AAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015ABD8);

extern "C" int func_0015AD38(int a, int b, int c, int d, int e, int f, int g) {
    func_0011A558(0xC66876F6, 0, 0);
    int r = func_001881A0(a, b, c, d, e, g);
    if (r) func_00159738((S159738*)r, f);
    func_0011A568();
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015ADF0);

struct S15ADF8 { char pad0[8]; int unk8; };

extern "C" int func_0015ADF8(S15ADF8* self, int a) {
    int t[2];
    int v = func_001596E0((S_001596E0*)a);
    func_0014F150();
    if (func_0015AE68_r(a)) {
        t[0] = v;
        func_0015B4B0(self->unk8, t);
        return 1;
    }
    return 0;
}

extern "C" void func_0015AE68(void) {
    func_00188360();
}

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015AE88);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015AF80);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015B0B8);

INCLUDE_ASM("asm/nonmatchings/game/t_159258", func_0015B168);

extern "C" int func_0015B218(int a, int b, int c) {
    void* r = func_0015AF80();
    if (r) return func_00157710(r, c);
    return 0;
}
