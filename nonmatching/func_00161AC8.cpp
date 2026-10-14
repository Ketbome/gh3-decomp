#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S001628F0 {
    char pad[0xBC];
    VEntry* unkBC;
};

struct S001619B0 {
    char pad[0x58];
    VEntry* unk58;
};

struct S00162918 {
    char pad[0xB8];
    int unkB8;
};

struct B50_161 {
    u64 f0 : 1;
    u64 f1 : 2;
    u64 f3 : 1;
    u64 f4 : 1;
    u64 f5 : 1;
    u64 f6 : 58;
};
struct S50_161 { char pad0[0x50]; B50_161 unk50; VEntry* unk58; };
struct I3_161 {
    int unk0;
    int unk4;
    int unk8;
};
struct C_161 {
    int unk0;
    int unk4;
    int unk8;
    I3_161 unkC;
    int unk18;
};
struct S8_161 { char pad0[0x8]; s8 unk8; };
struct N_161 { int unk0; N_161* unk4; int* unk8; };
struct It_161 {
    int unk0;
    N_161* cur;
    It_161(N_161* n) : cur(n) {}
    bool operator!=(const It_161& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct L_161 { char pad0[0x14]; N_161 unk14; };
struct SBC_161 { char pad0[0xBC]; void* unkBC; };
struct S1E0_161 { char pad0[0x1E0]; int unk1E0; };

typedef unsigned int u128_161 __attribute__((mode(TI)));
struct S2A4_161 { char pad0[0x2A4]; int unk2A4[9]; int unk2C8; };
struct SBC2_161 { char pad0[0x8]; s8 unk8; char pad9[0x87]; char unk90[0x10]; char unkA0[0x10]; int unkB0; int unkB4; int unkB8; void* unkBC; };
struct O34_161 { char pad0[0x34]; VEntry* unk34; };
struct D8_161 { char pad0[0xC]; O34_161* unkC; };
struct N2_161 { int unk0; N2_161* unk4; D8_161* unk8; };
struct L54_161 { char pad0[0x18]; N2_161* unk18; char pad1C[0x38]; s16 unk54; };
struct S40_161 { char pad0[0xC]; int unkC; char pad10[0x30]; u128_161 unk40; B50_161 unk50; VEntry* unk58; };

struct B6_162920 { char c[6]; };

extern "C" {
void strcpy(int);
B6_162920* func_0030E720(int, void*);
void func_0030A554(int, void*);
void* func_0014F130(void);
extern u8 D_0036A048[];
extern B6_162920 D_0036A050;
void memset(void*, int, int);
void func_0030A2F4(void*, void*, int);
int func_0015F2D0(int);
void func_0015F2A8(int, int);
void func_0010F690(void*);
void func_001342B0(void*);
int func_00162918(S00162918*);
void func_0011D348(void*);
void func_001628B8(S8_161*);
void func_0015F1A0(int);
extern u8 D_0033DED0[];
extern int D_00368A38;
void Heap_Free(int, void*);
int func_0028C200(int);
void func_00289B40(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161580);

extern "C" int func_001618A0(L_161* self, int idx) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    int i = 0;
    for (; it != end; ++it) {
        if (idx == i) {
            return it.cur->unk8[0];
        }
        i++;
    }
    return 0;
}

extern "C" int func_001618F8(L_161* self, int idx) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    int i = 0;
    for (; it != end; ++it) {
        if (idx == i) {
            return it.cur->unk8[2];
        }
        i++;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161950);

extern "C" void func_00161960(L_161* self) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) func_0015F1A0(*it.cur->unk8);
}

extern "C" void func_001619B0(S001619B0* self, int a1) {
    VEntry* e = &self->unk58[16];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001619D8);

struct O_00161AC8 { int unk0; char pad4[8]; char unkC[1]; };
struct N_00161AC8 { int unk0; N_161* unk4; O_00161AC8* unk8; };
struct L_00161AC8 { char pad0[0x14]; N_161 unk14; char pad20[0x32]; s16 unk52; s16 unk54; };

extern "C" {
int func_0014EB78(int);
void func_00134340(void*);
}

extern "C" void func_00161AC8(L_00161AC8* self) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) {
        func_0014EB78(((N_00161AC8*)it.cur)->unk8->unk0);
        O_00161AC8* o = ((N_00161AC8*)it.cur)->unk8;
        if (o) {
            func_00134340(o->unkC);
            Heap_Free(D_00368A38, o);
        }
    }
    N_161* h = (N_161*)((char*)self + 0x10);
    N_161* n = (N_161*)h->unk8;
    h->unk4 = &self->unk14;
    h->unk8 = (int*)&self->unk14;
    for (; n != &self->unk14;) {
        N_161* next = n->unk4;
        Heap_Free(D_00368A38, n);
        n = next;
    }
    self->unk54 = 0;
    self->unk52 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161BA0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161CC8);

struct B4_161 { char c[4]; };
struct VE_00161D40 { char pad0[0x50]; s16 unk50; s16 unk52; void (*unk54)(void*, B4_161*); };
struct O_00161D40 { char pad0[0x18]; VE_00161D40* unk18; };
struct N_00161D40 { int unk0; N_161* unk4; O_00161D40** unk8; };

extern "C" int func_00161D40(L_161* self, B4_161* a) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) {
        O_00161D40** pp = ((N_00161D40*)it.cur)->unk8;
        B4_161 t1 = *a;
        O_00161D40* o = *pp;
        B4_161 t2 = t1;
        VE_00161D40* e = o->unk18;
        e->unk54((char*)o + e->unk50, &t2);
    }
    return 1;
}

extern "C" int func_00161DD8(L_161* self, char r, u8 g, u8 b, u8 a) {
    B4_161 c;
    c.c[0] = r;
    c.c[1] = g;
    c.c[2] = b;
    c.c[3] = a;
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) {
        O_00161D40** pp = ((N_00161D40*)it.cur)->unk8;
        B4_161 t1 = c;
        O_00161D40* o = *pp;
        B4_161 t2 = t1;
        VE_00161D40* e = o->unk18;
        e->unk54((char*)o + e->unk50, &t2);
    }
    return 1;
}

extern "C" int func_00161E78(L_161* self) {
    int r = 0;
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) r |= func_0015F2D0(*it.cur->unk8);
    return r;
}

extern "C" int func_00161EE0(L_161* self, int x) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) func_0015F2A8(*it.cur->unk8, x);
    return 1;
}

struct S20_161 { char pad0[0x20]; u128_161 unk20; char pad30[0x20]; B50_161 unk50; };

static inline f32 GetX161(u128_161 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}
static inline f32 GetY161(u128_161 q) {
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(f) : "r"(q));
    return f;
}
static inline f32 GetZ161(u128_161 q) {
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(f) : "r"(q));
    return f;
}

extern "C" int func_00161F48(S20_161* self, u128_161* v) {
    int b = 0;
    self->unk20 = *v;
    u128_161 q = *v;
    if (GetX161(q) != 1.0f || GetY161(q) != 1.0f || GetZ161(q) != 1.0f) b = 1;
    self->unk50.f3 = b;
    return 1;
}

extern "C" void func_00161FD8(S50_161* self, int v) {
    self->unk50.f3 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161FF8);

extern "C" int func_00162070(L54_161* self) {
    if (self->unk54 != 1) {
        return 0;
    }
    It_161 it((N_161*)self->unk18);
    O34_161* o = ((N2_161*)it.cur)->unk8->unkC;
    void* v;
    if (o) {
        VEntry* e = &o->unk34[2];
        v = ((void* (*)(void*))e->fn)((char*)o + e->delta);
    } else {
        v = 0;
    }
    return v ? func_00162918((S00162918*)v) : 0;
}

extern "C" u128_161 func_001620D8(S40_161* self) {
    if (((u32)*(u64*)&self->unk50 & 1) && !self->unkC) {
        return self->unk40;
    }
    VEntry* e = &self->unk58[13];
    self->unk40 = ((u128_161 (*)(void*))e->fn)((char*)self + e->delta);
    *(u64*)&self->unk50 |= 1;
    return self->unk40;
}

extern "C" void func_00162140(S50_161* self, int a) {
    self->unk50.f0 = 0;
    VEntry* e = &self->unk58[14];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_00162178(S001619B0* self) {
    VEntry* e = &self->unk58[15];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001621A0);

extern "C" void func_00162358(S50_161* self, int v) {
    self->unk50.f5 = v;
}

extern "C" C_161* func_00162378(C_161* self) {
    I3_161* p = &self->unkC;
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk18 = 0;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623A0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623B8);

extern "C" void func_00162420(SBC_161* self, int flags) {
    self->unkBC = D_0033DED0;
    func_001628B8((S8_161*)self);
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162470);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162478);

extern "C" void func_001628B8(S8_161* self) {
    if (self->unk8) {
        func_0011D348(&self->unk8);
        self->unk8 = 0;
    }
}

extern "C" int func_001628F0(S001628F0* self, int a1, int a2, int a3) {
    VEntry* e = &self->unkBC[4];
    return ((int (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" int func_00162918(S00162918* self) {
    return self->unkB8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162920);

extern "C" int func_001629B0(void) {
    return 0;
}

extern "C" int func_001629B8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001629C0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001629E0);

extern "C" void func_00162B98(void) {
}

extern "C" int func_00162BA0(void) {
    return 0;
}

extern "C" int func_00162BA8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162E08);

extern "C" void func_00162EE8(S2A4_161* self, void* src, int n) {
    if (n >= 10) {
        n = 9;
    }
    if (!src) {
        memset(self->unk2A4, 0xFF, n * 4);
    } else {
        func_0030A2F4(self->unk2A4, src, n * 4);
    }
    self->unk2C8 = n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162F48);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163128);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163320);

extern "C" void func_00163328(S1E0_161* self) {
    if (self->unk1E0 && !func_0028C200(self->unk1E0)) {
        if (self->unk1E0) {
            func_00289B40(self->unk1E0, 3);
        }
        self->unk1E0 = 0;
    }
}

struct VE_00163380 { char pad0[0x28]; s16 unk28; s16 unk2A; void (*unk2C)(void*); };
struct S_00163380 { char pad0[0x8]; VE_00163380* unk8; char pad0C[0xB4]; int unkC0; char padC4[0x214]; int unk2D8; char pad2DC[4]; u64 unk2E0; };
extern int D_00372D3C[] __attribute__((section(".sdata")));

extern "C" void func_00163380(S_00163380* self, int a) {
    if ((self->unk2E0 & 0xC0000) == 0xC0000 || a) {
        VE_00163380* e = self->unk8;
        e->unk2C((char*)self + e->unk28);
        int d = D_00372D3C[0] + self->unkC0;
        int f = self->unk2D8 & ~1;
        u64 g = self->unk2E0 & ~0x40000;
        D_00372D3C[0] = d;
        self->unk2D8 = f;
        self->unk2E0 = g;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163410);
