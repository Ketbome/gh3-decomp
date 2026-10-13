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

struct T_18B9C0 { char pad0[0x60]; int unk60; char pad64[0x5C]; int unkC0; };
struct S_18B9C0 { char pad0[8]; int unk8; int unkC; char pad10[0xC]; T_18B9C0* unk1C; T_18B9C0* unk20; void* unk24; int unk28; };
struct VE_0018D780 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_0018D780 { char pad0[4]; VE_0018D780* unk4; };

typedef unsigned int u128_18B __attribute__((mode(TI)));
struct M3_18B { u128_18B a; u128_18B b; u128_18B c; };
struct M4_18B { u128_18B a; u128_18B b; u128_18B c; u128_18B d; };
struct S_0018D6A0 { char pad0[4]; void* unk4; int unk8; };
struct T_0018D0D0 { char pad0[0x2C]; void* unk2C; };
struct VE_0018BA88 { s16 unk0; s16 unk2; void (*unk4)(void*, void*); };
struct S_0018BA88 { char pad0[0x18]; VE_0018BA88* unk18; char pad1C[8]; void* unk24; };
struct C_0018BA88 { u8 r; u8 g; u8 b; u8 a; };
struct S_0018BF10 { char pad0[8]; int unk8; char padC[0x1C]; M3_18B* unk28; };
struct S_0018C150 { char pad0[8]; int unk8; char padC[0x1C]; M4_18B* unk28; };
struct T_0018D588 { char pad0[0x74]; float unk74; };
struct S_0018D588 { char pad0[0xC]; int unkC; char pad10[4]; T_0018D588* unk14; };
struct R_0018D118 { char pad0[0x98]; int unk98; };

struct T_0018CC08 { char pad0[0x80]; void* unk80; };
struct P_0018D050 { char pad0[0x1C]; int unk1C; };

struct VE_0018D350 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct O_0018D350 { char pad0[0x34]; VE_0018D350* unk34; };
struct H_0018D350 { O_0018D350* unk0; int unk4; int unk8; };
struct S_0018D3F0 { char pad0[8]; void* unk8; int unkC; int unk10; T_18B9C0* unk14; };

struct M2_18B { u128_18B a; u128_18B b; };
struct S_0018BCD0 { char pad0[0xC]; int unkC; char pad10[0x14]; void* unk24; };

struct E_0018D4B8 { char pad0[0x1C]; T_18B9C0* unk1C; char pad20[4]; T_18B9C0* unk24; };
struct S_0018D4B8 { char pad0[4]; void* unk4; char pad8[4]; int unkC; char pad10[4]; T_18B9C0* unk14; };

extern "C" {
extern int D_00368A38;
void* func_00118F20(int, int, int, int);
void* func_0018D6A0_4(void*, int, int, int) __asm__("func_0018D6A0");
void func_001AFAC8(P_0018D050*, float, float, float, float, float, float, float, float);
void func_001ACE28(P_0018D050*, int);
int func_001ACD38(P_0018D050*);
void func_001A9B80(P_0018D050*, int);
void func_001B1990(T_18B9C0*, int, int, int);
void func_001ACCC0(void*, int, int);
int func_00161958(void*);
E_0018D4B8* func_001618A0(void*, int);
int func_001A9D98(T_18B9C0*);
void func_001AFB40(P_0018D050*, float, float);
extern int D_00372BC4;
extern M2_18B D_00381C30;
void func_0010F690(void*);
void func_001342B0(void*);
M2_18B func_001AF990(void*);
int func_001ACD78(P_0018D050*);
void func_001AFB10(P_0018D050*, int);
void func_001B0898(P_0018D050*, int);
void func_0018D4B8(S_0018D3F0*);
void func_001A9D68(T_18B9C0*, int);
void func_001A9D28(T_18B9C0*, int);
void func_001B1948(T_18B9C0*, int);
extern char D_00345280[];
void func_0015F900(S_0018D3F0*, int);
S_0018D3F0* func_0015F8E8(S_0018D3F0*);
int CrcFromPathLowercase(int);
extern int D_0036F658;
void func_0022B0D0(H_0018D350*, int, int, int);
void func_00134340(H_0018D350*);
int func_0015FA10(int);
void func_001AD0C8(void*, int);
int func_00157260(int);
void func_001B1868(T_18B9C0*, int);
void func_001ACD98(void*, int);
P_0018D050* func_001ACF70(void*);
P_0018D050* func_001AD008(P_0018D050*);
int func_001ACD28(void*);
void func_001B0850(P_0018D050*);
void func_001B08F0(P_0018D050*);
void func_001AD7F8(P_0018D050*, int, int);
void func_0018C3F8(S_18B9C0*);
S_0018D6A0* func_0015F9B8(S_0018D6A0*, int, int);
int func_001550C0(int);
extern char D_00378220[];
int func_001ACD58(void*);
int func_001AD018(void*);
void func_001ACE58(void*, int);
R_0018D118* func_001AD128(void*);
void func_001AD158(void*, u8);
void func_001ACEA8(void*, int);
int func_001ACD48(void*);
void func_001B1898(T_18B9C0*, int);
void func_001B1C40(T_18B9C0*);
void func_001B1C60(T_18B9C0*);
void func_0018D5E0(S_18B9C0*);
void func_001AD020(void*, int);
u32 func_001AD160(void*);
void* func_00113D20(u32);
void* func_0018D350(void*, int);
void func_0018AF58(T_18B9C0*);
void func_001B1A40(T_18B9C0*, int, int, int);
int func_001ACF30(int);
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

extern "C" void func_0018BA88(S_0018BA88* self) {
    if (self->unk24) {
        func_001ACE58(self->unk24, 0);
        return;
    }
    C_0018BA88 c;
    c.r = 0x80;
    c.g = 0x80;
    c.b = 0x80;
    c.a = 0x80;
    VE_0018BA88* e = &self->unk18[10];
    e->unk4((char*)self + e->unk0, &c);
}

extern "C" int func_0018BAE8(S_18B9C0* self, int a, int b, int* c) {
    if (self->unk1C == 0) return 0;
    if ((self->unk1C->unk60 >> 4) & 1) func_001B1A40(self->unk1C, a, b, *c);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BB28);

extern "C" void func_0018BBA8(S_18B9C0* self, int v) {
    if (self->unk24) func_001AD158(self->unk24, v);
}

extern "C" u32 func_0018BBD0(S_18B9C0* self) {
    if (self->unk24) return func_001AD160(self->unk24) | 0xFFFFFF00;
    return 0;
}

extern "C" void func_0018BC08(S_18B9C0* self) {
    if (self->unk24) func_001ACEA8(self->unk24, 1);
}

extern "C" void func_0018BC30(S_18B9C0* self, int v) {
    if (self->unk1C && v != (self->unk1C->unk60 & 1)) func_001B1868(self->unk1C, v);
    if (self->unk24 && v != func_001ACD48(self->unk24)) func_001ACD98(self->unk24, v);
}

extern "C" int func_0018BCA8(S_18B9C0* self) {
    if (self->unk24) return func_001ACD48(self->unk24);
    return 0;
}

GP_DATA(D_00372BC4);
extern "C" void* func_0018BCD0(S_0018BCD0* self) {
    M2_18B* r;
    if (self->unk24) {
        if (!D_00372BC4) {
            r = &D_00381C30;
            func_0010F690(&r->a);
            func_0010F690(&r->b);
            func_001342B0(r);
            D_00372BC4 = 1;
        }
        return &(D_00381C30 = func_001AF990(self->unk24));
    }
    return (void*)(self->unkC + 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BD68);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BE00);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BE88);

extern "C" int func_0018BF00(S0018BF00* self) {
    return self->unk28 + 48;
}

extern "C" void func_0018BF10(S_0018BF10* self, M3_18B* m) {
    self->unk28->a = m->a;
    self->unk28->b = m->b;
    self->unk28->c = m->c;
    if (self->unk8 != 2) func_0018C3F8((S_18B9C0*)self);
}

extern "C" int func_0018BF68(S_18B9C0* self) {
    if (self->unk24 && func_001ACD58(self->unk24)) return func_001AD018(self->unk24);
    return self->unk28;
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018BFB8);

extern "C" void func_0018C150(S_0018C150* self, M4_18B* m) {
    *self->unk28 = *m;
    if (self->unk8 != 2) func_0018C3F8((S_18B9C0*)self);
}

extern "C" int func_0018C1A8(S_18B9C0* self) {
    if (self->unk24 && func_001ACD58(self->unk24)) return func_001AD018(self->unk24);
    return self->unk28;
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C368);

extern "C" void func_0018C3F8(S_18B9C0* self) {
    if (self->unk8 != 2) func_001AD020(self->unk24, self->unk28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C428);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C658);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018C7B8);

extern "C" int func_0018C948(S_18B9C0* self, int key, int arg) {
    P_0018D050* p;
    for (p = func_001ACF70(self->unk24); p; p = func_001AD008(p)) {
        if (func_001ACF30((int)p) == key) {
            func_001AD7F8(p, arg, 0);
            return 1;
        }
    }
    return 0;
}

extern "C" void func_0018C9C8(S_18B9C0* self) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    int key = func_001ACF30((int)p);
    while (!func_001ACD28(p)) {
        if (func_001ACF30((int)p) == key) func_001ACE28(p, 1);
        if (func_001AD008(p) && func_001ACD38(p)) func_001A9B80(func_001AD008(p), key);
        p = func_001ACF70(p);
    }
    for (; p; p = func_001AD008(p)) {
        if (func_001ACF30((int)p) == key) func_001ACE28(p, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018CAA0);

extern "C" int func_0018CB98(S_18B9C0* self) {
    if (self->unk24 == 0) {
        T_18B9C0* t = self->unk20;
        if (t->unkC0 == 0) func_0018AF58(t);
    }
    return 1;
}

extern "C" int func_0018CBD8(S_18B9C0* self, int v) {
    if (!self->unk24) func_001B1898(self->unk1C, v);
    return 1;
}

extern "C" void func_0018CC08(S_18B9C0* self, int a) {
    if (self->unk24) {
        func_001AD0C8(self->unk24, a);
        return;
    }
    T_0018CC08* t = (T_0018CC08*)self->unk1C;
    if (t) t->unk80 = D_00378220 + func_001550C0(func_00157260(a)) * 0xB0;
}

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

extern "C" void func_0018CDC8(S_18B9C0* self, float a, float b, float c, float d, float e, float f, float g, float h) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if (func_001ACD78(p)) func_001AFAC8(p, a, b, c, d, e, f, g, h);
    }
}

extern "C" void func_0018CEC0(S_18B9C0* self, int a) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if (func_001ACD78(p)) func_001AFB10(p, a);
    }
}

extern "C" void func_0018CF48(S_18B9C0* self, float a, float b) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if (func_001ACD78(p)) {
            func_001AFB40(p, a, b);
            func_001AFB10(p, 1);
        }
    }
}

extern "C" int func_0018CFF0(S_18B9C0* self) {
    if (self->unk1C) {
        func_001B1C40(self->unk1C);
        return 1;
    }
    return 0;
}

extern "C" int func_0018D020(S_18B9C0* self) {
    if (self->unk1C) {
        func_001B1C60(self->unk1C);
        return 1;
    }
    return 0;
}

extern "C" void func_0018D050(S_18B9C0* self) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if ((p->unk1C >> 20) & 1) func_001B0850(p);
    }
}

extern "C" void func_0018D0D0(S_18B9C0* self, int a) {
    T_0018D0D0* t = (T_0018D0D0*)self->unk24;
    if (t) t->unk2C = D_00378220 + func_001550C0(a) * 0xB0;
}

extern "C" int func_0018D118(S_18B9C0* self, int* out) {
    void* t = self->unk24;
    if (t && func_001AD128(t)) {
        *out = func_001AD128(t)->unk98;
        return 1;
    }
    return 0;
}

extern "C" void func_0018D178(S_18B9C0* self, int a) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if ((p->unk1C >> 20) & 1) func_001B0898(p, a);
    }
}

extern "C" void func_0018D200(S_18B9C0* self) {
    P_0018D050* p = (P_0018D050*)self->unk24;
    while (!func_001ACD28(p)) p = func_001ACF70(p);
    for (; p; p = func_001AD008(p)) {
        if ((p->unk1C >> 20) & 1) func_001B08F0(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D280);

extern "C" void* func_0018D350(void* p, int a) {
    S_0018D3F0* self = (S_0018D3F0*)p;
    func_0015F8E8(self);
    self->unkC = 0;
    self->unk14 = 0;
    self->unk8 = D_00345280;
    H_0018D350 h;
    int x = D_0036F658;
    func_0022B0D0(&h, x, CrcFromPathLowercase(a), 1);
    int r;
    if (h.unk0) {
        VE_0018D350* e = &h.unk0->unk34[2];
        r = e->unk4((char*)h.unk0 + e->unk0);
    } else {
        r = 0;
    }
    func_00134340(&h);
    self->unk10 = func_0015FA10(r);
    return self;
}

extern "C" void func_0018D3F0(S_0018D3F0* s, int flag) {
    s->unk8 = D_00345280;
    if (s->unkC & 1) {
        if (s->unk14) {
            func_001A9D68(s->unk14, 0);
            s->unk14 = 0;
        }
    } else if (s->unkC & 2) {
        if (s->unk14) {
            func_001B1898(s->unk14, 0);
            s->unk14 = 0;
        }
    }
    func_0015F900(s, flag);
}

extern "C" void func_0018D480(S_18B9C0* self) {
    if (!(self->unkC & 3)) func_0018D5E0(self);
}

extern "C" void func_0018D4B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D4B8);

extern "C" void func_0018D588(S_0018D588* self, float x) {
    func_0018D5E0((S_18B9C0*)self);
    if (self->unkC & 1) return;
    if (!(self->unkC & 2)) return;
    self->unk14->unk74 = x;
}

extern "C" void func_0018D5E0(S_18B9C0* p) {
    S_0018D3F0* s = (S_0018D3F0*)p;
    if (s->unkC & 3) return;
    func_0018D4B8(s);
    if (s->unkC & 1) {
        func_001A9D68(s->unk14, 1);
        func_001A9D28(s->unk14, s->unk10);
    } else if (s->unkC & 2) {
        func_001B1898(s->unk14, 1);
        func_001B1948(s->unk14, s->unk10);
    }
}

extern "C" void* func_0018D668(int a) {
    return func_0018D350(func_00113D20(0x18), a);
}

extern "C" S_0018D6A0* func_0018D6A0(S_0018D6A0* self, int a, int b) {
    func_0015F9B8(self, a, b);
    self->unk4 = D_00345258;
    self->unk8 = b;
    return self;
}

extern "C" void func_0018D6E8(S0018D6E8* self) {
    self->unk4 = D_00345258;
    func_0015F9D0(self);
}

extern "C" int func_0018D710(S0018D710* self) {
    return self->unk8;
}

extern "C" void* func_0018D718(int a, int b, int c) {
    return func_0018D6A0_4(func_00118F20(D_00368A38, 0xC, 1, 0), a, b, c);
}

extern "C" void func_0018D780(S_0018D780* p) {
    if (p) {
        VE_0018D780* e = &p->unk4[1];
        e->unk4((char*)p + e->unk0, 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D7B8);

INCLUDE_ASM("asm/nonmatchings/game/t_18B9C0", func_0018D7C0);
