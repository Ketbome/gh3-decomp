#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0016C8C8 {
    char pad0[0x8];
    VEntry* unk8;
    char padC[0x40];
    float unk4C;
};

struct S0016CA18 {
    char pad0[0x8];
    VEntry* unk8;
    char padC[0x144];
    float unk150;
};

struct S0016C4E8 {
    char pad[0x10];
    char unk10;
};

struct S0016C6A8 {
    char pad[0x40];
    float unk40;
};

struct S0016C6B0 {
    char pad[0x44];
    float unk44;
};

struct S0016C6B8 {
    char pad[0x48];
    float unk48;
};

typedef unsigned int u128_16C __attribute__((mode(TI)));
struct S_0016C6C0 { char pad0[0x20]; float unk20[1]; };
struct Z_0016D0F8 { int unk0; int unk4; int unk8; };
struct S_0016C620 { char pad0[0x198]; int unk198; int unk19C; };
struct S_0016C6D0 { char pad0[0xC0]; u128_16C unkC0[3]; u128_16C unkF0[1]; };

struct CP_16C { u8 r; u8 g; u8 b; u8 a; };
struct C_16C {
    CP_16C c;
    C_16C(const C_16C& o) : c(o.c) {}
    C_16C& operator=(const C_16C& o) { *(u32*)this = *(const u32*)&o; return *this; }
};
struct P_16C {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};
struct S_0016C878 { char pad0[0x154]; C_16C unk154[1]; };
struct S_16C { char pad0[8]; VEntry* unk8; char padC[0x30]; float unk3C; char pad40[0x10]; float unk50; float unk54; float unk58; float unk5C; void* unk60; char pad64[0x140]; int unk1A4; int unk1A8; };

struct S2_16C { char pad0[0x74]; void* unk74; char pad78[0x120]; int unk198; int unk19C; char pad1A0[8]; int unk1A8; };

extern "C" {
void func_0016C650(S_16C*, float);
void func_0016C5C0(S_16C*, int);
int func_001D0578(void*);
extern int D_00369A50[] __attribute__((section(".sdata")));
void func_0016CF48(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
void* func_00118F20(int, int, int, int);
void* func_0016DDD8(void*, int, int);
void* func_0016E490(void*, int, int);
extern void* D_0036A6F4;
extern void* D_0036A740;
void func_0016CA80(void*);
void func_0016C180(void*);
void func_0028D700(void*);
extern u8 D_00372BA8;
extern u8 D_00372BA9[] __attribute__((section(".sdata")));
extern u8 D_00372BAA[] __attribute__((section(".sdata")));
extern u8 D_00372BAB[] __attribute__((section(".sdata")));
extern u8 D_00372BB0;
extern u8 D_00372BB1[] __attribute__((section(".sdata")));
extern u8 D_00372BB2[] __attribute__((section(".sdata")));
extern u8 D_00372BB3[] __attribute__((section(".sdata")));
void func_0016D138(void*, int, int);
extern char D_0037DBB0[];
void func_0016D0F8(Z_0016D0F8*);
void func_0016DDA0(Z_0016D0F8*);
void func_0016E458(Z_0016D0F8*);
void func_0016D318(int, int);
void func_0016D3E8(int, int);
void func_00119400(int, void*);
extern int D_0036A6F0;
extern P_16C* D_0036A6E0[2];
void func_0011C2E8(P_16C*, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C498);

extern "C" int func_0016C4A0(S_16C* s, int a) {
    if (a) func_0016CA80((char*)s + 0x10);
    func_0016C180(s);
    VEntry* e = &s->unk8[2];
    return ((int (*)(void*))e->fn)((char*)s + e->delta);
}

extern "C" void* func_0016C4E8(S0016C4E8* self) {
    return &self->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C4F0);

extern "C" void func_0016C4F8(S_16C* s) {
    S2_16C* t = (S2_16C*)s;
    if (t->unk74 && !t->unk1A8 && !func_001D0578(t->unk74)) {
        func_0016C650(s, 0.0f);
        func_0016C5C0(s, 1);
    }
    if (t->unk1A8) {
        VEntry* e = &s->unk8[7];
        if (!((int (*)(void*))e->fn)((char*)s + e->delta)) {
            func_0016CF48(D_00369A50[0], s);
            return;
        }
    }
    if (!t->unk198 && !t->unk19C) {
        VEntry* e = &s->unk8[5];
        ((void (*)(void*))e->fn)((char*)s + e->delta);
    }
}

extern "C" void func_0016C5C0(S_16C* s, int a) {
    if (a) {
        s->unk1A8 = 1;
        return;
    }
    if (s->unk60) {
        func_0028D700(s->unk60);
        s->unk60 = 0;
    }
    VEntry* e = &s->unk8[3];
    ((void (*)(void*))e->fn)((char*)s + e->delta);
}

extern "C" void func_0016C620(S_0016C620* s, int v) {
    if (s->unk198 != v) s->unk198 = v;
}

extern "C" void func_0016C638(S_0016C620* s, int v) {
    if (s->unk19C != v) s->unk19C = v;
}

extern "C" void func_0016C650(S_16C* s, float v) {
    if (s->unk3C == 0.0f) {
        VEntry* e = &s->unk8[6];
        ((void (*)(void*))e->fn)((char*)s + e->delta);
    }
    s->unk3C = v;
}

extern "C" void func_0016C6A8(S0016C6A8* self, float v) {
    self->unk40 = v;
}

extern "C" void func_0016C6B0(S0016C6B0* self, float v) {
    self->unk44 = v;
}

extern "C" void func_0016C6B8(S0016C6B8* self, float v) {
    self->unk48 = v;
}

extern "C" void func_0016C6C0(S_0016C6C0* s, int i, float v) {
    s->unk20[i] = v;
}

extern "C" void func_0016C6D0(S_0016C6D0* s, int i, u128_16C* v) {
    *(u128_16C*)(i * 0x10 + (char*)s + 0xC0) = *v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C6E8);

extern "C" void func_0016C798(S_0016C6D0* s, int i, u128_16C* v) {
    *(u128_16C*)(i * 0x10 + (char*)s + 0xF0) = *v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C878);

extern "C" void func_0016C8C8(S0016C8C8* self, float f0) {
    self->unk4C = f0;
    VEntry* e = &self->unk8[6];
    ((void (*)(void*, float))e->fn)((char*)self + e->delta, f0);
}

struct VE_16C8F8 { s16 unk0; s16 unk2; void (*unk4)(void*); };
struct V_16C8F8 { char pad0[0x30]; VE_16C8F8 unk30; };
struct S_16C8F8 { char pad0[8]; V_16C8F8* unk8; char padC[0x44]; float unk50; float unk54; float unk58; float unk5C; char pad60[0x144]; int unk1A4; };

extern "C" void func_0016C8F8(S_16C8F8* self, u8* c) {
    if (!c) {
        V_16C8F8* v = self->unk8;
        v->unk30.unk4((char*)self + v->unk30.unk0);
    } else if (self->unk1A4) {
        V_16C8F8* v = self->unk8;
        self->unk50 = c[0] * 0.003921569f;
        self->unk54 = c[1] * 0.003921569f;
        self->unk58 = c[2] * 0.003921569f;
        self->unk5C = c[3] * 0.003921569f;
        v->unk30.unk4((char*)self + v->unk30.unk0);
    }
}

extern "C" void func_0016C9C0(S_16C* s, float* v) {
    if (s->unk1A4) {
        s->unk50 = v[0];
        s->unk54 = v[1];
        s->unk58 = v[2];
        s->unk5C = v[3];
        VEntry* e = &s->unk8[6];
        ((void (*)(void*))e->fn)((char*)s + e->delta);
    }
}

extern "C" void func_0016CA18(S0016CA18* self, float f0) {
    self->unk150 = f0;
    VEntry* e = &self->unk8[6];
    ((void (*)(void*, float))e->fn)((char*)self + e->delta, f0);
}

extern "C" void func_0016CA48(void) {
}

extern "C" void func_0016CA50(void) {
}

extern "C" void func_0016CA58(void) {
}

extern "C" int func_0016CA60(void) {
    return 1;
}

extern "C" int func_0016CA68(void) {
    return 0;
}

extern "C" void func_0016CA70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CA78);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CA80);

extern "C" int func_0016CCA8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CCB0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CD28);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CDF0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CF48);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D060);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D0D0);

extern "C" void func_0016D0F8(Z_0016D0F8* s) {
    s->unk0 = 0;
    s->unk4 = 0;
    s->unk8 = 0;
}

extern "C" Z_0016D0F8* func_0016D108(Z_0016D0F8* s) {
    func_0016D0F8(s);
    return s;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D130);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D138);

extern "C" void func_0016D318(int init, int prio) {
    if (prio == 0xFFFF && init) func_0016D138(D_0037DBB0, 1, 0);
}

extern "C" void func_0016D350(void) {
    func_0016D318(1, 65535);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D370);

GP_DATA(D_00372BA8);
GP_DATA(D_00372BB0);
extern "C" void func_0016D3E8(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_00372BA8 = 0x60;
        D_00372BA9[0] = 0x60;
        D_00372BAA[0] = 0x80;
        D_00372BAB[0] = 0x66;
        D_00372BB0 = 0x60;
        D_00372BB1[0] = 0x60;
        D_00372BB2[0] = 0x80;
        D_00372BB3[0] = 0x66;
    }
}

extern "C" void func_0016D448(void) {
    func_0016D3E8(1, 65535);
}

GP_DATA(D_0036A6F4);
extern "C" void func_0016D468(void) {
    if (!D_0036A6F4) D_0036A6F4 = func_0016DDD8(func_00118F20(D_00368A38[0], 0x1C, 1, 0), 4, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D4B8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DD90);

extern "C" void func_0016DDA0(Z_0016D0F8* s) {
    s->unk0 = 0;
    s->unk4 = 0;
    s->unk8 = 0;
}

extern "C" Z_0016D0F8* func_0016DDB0(Z_0016D0F8* s) {
    func_0016DDA0(s);
    return s;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DDD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DFB8);

GP_DATA(D_0036A6F0);
GP_DATA(D_0036A6E0);
extern "C" void func_0016E070(void* p) {
    P_16C* pool = D_0036A6E0[D_0036A6F0];
    if ((pool && pool->Has((u32)p)) || ((pool = D_0036A6E0[D_0036A6F0 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        func_00119400(D_00368A38[0], p);
    }
}

GP_DATA(D_0036A740);
extern "C" void func_0016E120(void) {
    if (!D_0036A740) D_0036A740 = func_0016E490(func_00118F20(D_00368A38[0], 0x1C, 1, 0), 4, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E168);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E170);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E448);

extern "C" void func_0016E458(Z_0016D0F8* s) {
    s->unk0 = 0;
    s->unk4 = 0;
    s->unk8 = 0;
}

extern "C" Z_0016D0F8* func_0016E468(Z_0016D0F8* s) {
    func_0016E458(s);
    return s;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E490);
