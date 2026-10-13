#include "common.h"

struct S_001143E0 { char pad0[0x24]; int unk24; };
struct S_00114030 { char pad0[0x8]; struct S_00114030* unk8; char pad1[0x4]; struct S_00114030* unk10; };

struct S_00114958 { char pad0[0x40]; int unk40; };
struct S_001149B8 { char pad0[0x3C]; int unk3C; };

struct SA112_L {
    char pad0[0xC];
    SA112_L* unkC;
    SA112_L* unk10;
    void* unk14;
};

struct SA112_C {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    u32 unkC;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    int unk20;
    int unk24;
};

struct SA112_N {
    char pad0[0x4];
    u32 unk4;
    int unk8;
    SA112_N* unkC;
    SA112_N* unk10;
    void* unk14;
};

struct SA112_D {
    char pad0[0x8];
    void* unk8;
};

extern "C" {
extern u8 D_00337D80[];
extern u8 D_003378C8[];
void func_00114150(void*, int, int);
void func_001144A0(void*);
void* func_00113D20(u32);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00337EE0[];
extern u8 D_00337EC8[];
extern u8 D_00337F08[];
extern u8 D_00337F38[];
extern u8 D_00337DA0[];
void func_00119400(int, void*);
extern int D_00368390;
void func_00113D88(int, int);
void func_00114298(int);
void func_00114340(int);
void func_00114AD8(void);
extern int D_00368388[];
void func_0030ADA0(int, int, int);
}

struct S112D48 { void* unk0; int unk4; char pad8[4]; void* unkC; };

extern "C" void func_00112D48(S112D48* self, int flags) {
    self->unkC = D_003378C8;
    void* p = self->unk0;
    if (p) {
        self->unk4 = 0;
        func_00119400(D_00368A38[0], p);
        self->unk0 = 0;
    }
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112DB0);

struct Arr_00112E60 { void* p; int n; int unk8; void* vp; };
struct S_00112E60 { Arr_00112E60 a0; Arr_00112E60 a10; char pad20[4]; Arr_00112E60 a24; char pad34[4]; Arr_00112E60 a38; };

static inline void Dtor_00112E60(Arr_00112E60* a) {
    a->vp = D_003378C8;
    if (a->p) {
        a->n = 0;
        if (a->p) func_00119400(D_00368A38[0], a->p);
        a->p = 0;
    }
}

extern "C" void func_00112E60(S_00112E60* self, int flags) {
    Dtor_00112E60(&self->a38);
    Dtor_00112E60(&self->a24);
    Dtor_00112E60(&self->a10);
    Dtor_00112E60(&self->a0);
    if (flags & 1) func_00119400(D_00368A38[0], self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112F68);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113228);

struct E_func_00113308 { int key; int val; E_func_00113308* next; };
struct T_func_00113308 { int bits; E_func_00113308* buckets; int count; };

extern "C" void func_0011C408(int, E_func_00113308*);

static inline E_func_00113308* Slot_00113308(T_func_00113308* t, int k) {
    return &t->buckets[k & ((1 << t->bits) - 1)];
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113308);

extern "C" void func_001133C0(int p) {
    if (p == 0) {
        D_00368390 = (int)D_00368388;
    } else {
        D_00368390 = p;
    }
}

extern "C" int func_001133E0(void) {
    return D_00368390;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001133E8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113420);

extern "C" void func_00113528(char* s) {
    while (*s) {
        char c = *s;
        if (c >= 'A' && c <= 'Z') {
            c += 0x20;
        } else {
            switch (c) {
            case -0x40 ... -0x2A:
            case -0x28 ... -0x22:
                c += 0x20;
                break;
            }
        }
        *s = c;
        s++;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001135A0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113640);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113770);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001137E8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001138F8);

extern "C" void func_00113930(char* d, const char* s) {
    while (*s) {
        *d++ = *s++;
    }
    *d = 0;
}

extern "C" void func_00113960(int a, int b, int c) {
    func_0030ADA0(a, c, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113988);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001139E0);

extern "C" void func_00113A70(char* d, const char* s) {
    while (*d) {
        d++;
    }
    while (*s) {
        *d = *s;
        s++;
        d++;
    }
    *d = 0;
}

extern "C" void func_00113AC8(char* d, int n, const char* s) {
    while (*d) {
        d++;
    }
    while (*s) {
        *d = *s;
        s++;
        d++;
    }
    *d = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113B20);

extern "C" void func_00113B68(char* s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s -= 0x20;
        }
        s++;
    }
}

extern "C" char* func_00113BA0(char* s, char* sub) {
    char* a = s;
    char* b = sub;
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    if (*b == 0) {
        return s;
    }
    if (*a == 0) {
        return 0;
    }
    return func_00113BA0(s + 1, sub);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113BF8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D20);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D80);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D88);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113DE8);

extern "C" void func_00113E48(int p0, int p1, int p2) {
    func_00113D88(p0, p2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113E68);

struct S_00113EA8 { char pad0[0x4]; int unk4; void* unk8; int unkC; int unk10; int unk14; void* unk18; };
struct C_00113EA8 { u8 r, g, b, a; };

extern "C" S_00113EA8* func_00113EA8(S_00113EA8* self, int v) {
    self->unk18 = D_00337D80;
    self->unk4 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    C_00113EA8 c;
    c.r = 0xFF;
    c.g = 0xFF;
    c.b = 0xFF;
    c.a = 0xFF;
    SA112_L* n = (SA112_L*)func_00113D20(0x18);
    ((int*)n)[2] = v;
    ((S_00113EA8**)n)[1] = self;
    n->unk14 = D_00337DA0;
    n->unkC = n;
    n->unk10 = n;
    self->unk8 = n;
    return self;
}

struct VE_113F38 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_113F38 { char pad0[8]; VE_113F38 unk8; };
struct O_113F38 { char pad0[0x14]; V_113F38* unk14; };
struct S_113F38 { char pad0[8]; O_113F38* unk8; int unkC; char pad10[8]; void* unk18; };
extern "C" void func_00113FB8_v(void*) __asm__("func_00113FB8");

extern "C" void func_00113F38(S_113F38* self, int flags) {
    self->unk18 = D_00337D80;
    if (self->unkC) func_00113FB8_v(self);
    O_113F38* o = self->unk8;
    if (o) {
        V_113F38* v = o->unk14;
        v->unk8.unk4((char*)o + v->unk8.unk0, 3);
    }
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_001143E0(S_001143E0*);
struct N113FB8 { char pad0[0xC]; N113FB8* unkC; N113FB8* unk10; };
struct O113FB8 { char pad0[4]; int unk4; };
struct S113FB8 { char pad0[8]; N113FB8* unk8; O113FB8* unkC; };

extern "C" void func_00113FB8(S113FB8* self) {
    if (self->unkC) {
        self->unkC->unk4 = self->unkC->unk4 + 1;
        func_001143E0((S_001143E0*)self->unkC);
        N113FB8* n = self->unk8;
        n->unk10->unkC = n->unkC;
        n->unkC->unk10 = n->unk10;
        n->unkC = n;
        n->unk10 = n;
        self->unkC->unk4 = self->unkC->unk4 - 1;
        self->unkC = 0;
    }
}

extern "C" int func_00114030(S_00114030* self) {
    return self->unk8->unk10 != self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114048);

extern "C" SA112_C* func_001140B0(SA112_C* self) {
    SA112_N* p;
    self->unk4 = 0;
    p = (SA112_N*)((char*)self + 8);
    p->unk4 = 0xFFFFFFFF;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk14 = D_00337EE0;
    self->unk20 = 0;
    self->unk24 = 0;
    return self;
}

extern "C" void func_001140F0(void* self, int flags) {
    SA112_L* p = (SA112_L*)((char*)self + 8);
    p->unk14 = D_00337DA0;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114150);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114298);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114340);

extern "C" void func_001143E0(S_001143E0* self) {
    self->unk24 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001143F0);

extern "C" void func_00114460(SA112_D* self, int flags) {
    self->unk8 = D_00337EC8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

struct It_1144A0 {
    int unk0;
    SA112_N* cur;
    u8* vp;
    It_1144A0() : cur(0), vp(D_00337F08) {}
    ~It_1144A0() { vp = D_00337F08; }
};

extern "C" void func_00114580_v(void*, int) __asm__("func_00114580");

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001144A0);

struct N114528 { char pad0[4]; void* unk4; int unk8; N114528* unkC; N114528* unk10; void* unk14; };
struct S114528 { char pad0[0x28]; N114528* unk28; };

extern "C" S114528* func_00114528(S114528* self) {
    func_001140B0((SA112_C*)self);
    N114528* n = (N114528*)func_00113D20(0x18);
    n->unk4 = self;
    n->unk14 = D_00337F38;
    n->unk8 = 0;
    n->unkC = n;
    n->unk10 = n;
    self->unk28 = n;
    return self;
}

struct VE_114580 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_114580 { char pad0[0x8]; VE_114580 unk8; };
struct O_114580 { char pad0[0x14]; V_114580* unk14; };
struct S_114580 { char pad0[0x28]; O_114580* unk28; };

extern "C" void func_00114580(S_114580* self, int flags) {
    O_114580* o = self->unk28;
    if (o) {
        V_114580* v = o->unk14;
        v->unk8.unk4((char*)o + v->unk8.unk0, 3);
    }
    func_001140F0(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001145D8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114660);

struct S114770 { char pad0[0xC]; SA112_L unkC; char pad24[0x18]; void* unk3C; char pad40[4]; int unk44; };

extern "C" void func_00114770(S114770* self) {
    S114528* o = func_00114528((S114528*)func_00113D20(0x2C));
    self->unk3C = o;
    SA112_L* p = &self->unkC;
    SA112_L* q = (SA112_L*)o->unk28;
    q->unk10 = p;
    q->unkC = p->unkC;
    p->unkC->unk10 = q;
    p->unkC = q;
    self->unk44 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001147D0);

struct S1148F8 { char pad0[4]; int unk4; int unk8; char padC[0x30]; void* unk3C; void* unk40; int unk44; int unk48; };

extern "C" void func_001148F8(S1148F8* self, int a1) {
    void* t = self->unk3C;
    self->unk40 = t;
    self->unk4 = self->unk4 + 1;
    func_00114150(t, a1, self->unk8);
    self->unk4 = self->unk4 - 1;
    func_001144A0(self);
    self->unk44 = 0;
    self->unk48 = 0;
}

extern "C" void func_00114958(S_00114958* self) {
    func_00114298(self->unk40);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114978);

extern "C" void func_001149B8(S_001149B8* self) {
    func_00114340(self->unk3C);
}

extern "C" void func_001149D8(SA112_D* self, int flags) {
    self->unk8 = D_00337F08;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00114A18(SA112_L* self, int flags) {
    self->unk14 = D_00337F38;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00114A78(SA112_L* self, int flags) {
    self->unk14 = D_00337F38;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114AD8);

extern "C" void func_00114C50(void) {
    func_00114AD8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114C70);
