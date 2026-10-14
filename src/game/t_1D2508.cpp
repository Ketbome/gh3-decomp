#include "common.h"

struct G1D44 {
    char pad0[0x18];
    s32 unk18;
};

struct O1D44 {
    char pad0[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

typedef int TI128 __attribute__((mode(TI)));

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, s32);
};

struct S001D2B08 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x130];
    s32 unk154;

    bool Test(s32 m) {
        return (unk154 & m) != 0;
    }
};

struct S0036D3B0 {
    char pad0[0x2C];
    VEnt* unk2C;
};

extern "C" {
void func_00113FB8(void* p);
void func_001D82D8(void* p, s32 v);
extern u8 D_0034BA00[];
void func_001D1418(void);
void func_001D1438(void* p, s32 v);
void func_001D14C0(void* p, s32 v);
void func_001D3818(s32 a, s32 b);
void func_0027C448(s32 a, u32 key, s32 b);
void* func_00113DF0(s32 size, s32 a, s32 b);
S0036D3B0* func_001D4260(void* p);
extern S0036D3B0* D_0036D3B0;
extern u32 D_0036D3B4;
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0034B838[];
void func_0027D2D8(void* a, s32 key, void* v, s32 req);
s32 func_0027D870(void* a, s32 key, void* v, s32 req);
s32 func_001D1CF8(void* a, s32 b);
void* operator_new(u32);
s32 func_001D10A8(void* p);
void func_001CED20(s32 a, s32 b);
void func_001CEDE0(s32 a, u32 b);
extern s32 D_00372DA8;
extern G1D44* D_0036F658[] __attribute__((section(".sdata")));
void func_001D1998(void* o, s32 b);
void func_001D17B0(void* o, s32 a, s32 b, s32 t);
char* func_001D36E8(void* p, u32 key);
s32 func_0027D268(s32 a, u32 b, void* v, s32 c);
f32 func_0010D5C8(void* a, void* v, s32 b, s32 c);
void func_0027C1F8(s32 a, u32 key, f32 v);
void* func_00224220(s32 a, s32 b);
void func_00223590(void* a, void* v);
void* func_001D0680(s32 a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2508);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2918);

extern "C" int func_001D29C8(void) {
    func_001D1418();
    return 1;
}

extern "C" s32 func_001D29E8(char* p, void* a) {
    TI128 v;
    func_0027D2D8(a, 0x0C4C809E, &v, 1);
    *(TI128*)(p + 0xE0) = v;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2A30);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2A78);

extern "C" int func_001D2AC8(void* p) {
    func_001D1438(p, 1);
    return 1;
}

extern "C" int func_001D2AE8(void* p) {
    func_001D1438(p, 0);
    return 1;
}

extern "C" bool func_001D2B08(S001D2B08* p) {
    return p->Test(4);
}

extern "C" bool func_001D2B18(S001D2B08* p) {
    return p->Test(0x20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2B28);

extern "C" int func_001D2C18(void* p) {
    func_001D14C0(p, 1);
    return 1;
}

extern "C" int func_001D2C38(void* p) {
    func_001D14C0(p, 0);
    return 1;
}

extern "C" int func_001D2C58(S001D2B08* p) {
    p->unk154 |= 1;
    return 1;
}

extern "C" int func_001D2C70(S001D2B08* p) {
    p->unk154 &= ~1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2C88);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2E60);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2F00);

extern "C" s32 func_001D3020(char* self, void* a, char* script) {
    s32 id;
    TI128 v;
    f32 d;
    s32 st;
    func_0027D870(a, 0, &id, 0);
    func_00223590(func_00224220(id, 1), &v);
    asm volatile("lqc2 $vf1, %2\n\tlqc2 $vf2, 0x80(%1)\n\tvsub.xyzw $vf2, $vf2, $vf1"
        : "=r"(st) : "r"(self), "m"(v));
    s32 sc = *(s32*)(script + 0x20);
    asm volatile("vmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni $2, $vf1\n\tmtc1 $2, %0\n\tnop\n\tnop\n\tsqrt.s %0, %0"
        : "=f"(d) : "r"(st) : "$2");
    func_0027C1F8(sc, 0x7E832F08, d);
    return 1;
}

extern "C" s32 func_001D30B8(char* self, void* a, char* script) {
    s32 id;
    func_0027D870(a, 0, &id, 1);
    char* o = (char*)func_001D0680(id);
    f32 d = 0.0f;
    if (o) {
        asm volatile("lqc2 $vf1, 0x80(%1)\n\tlqc2 $vf2, 0x80(%2)\n\tvsub.xyzw $vf2, $vf2, $vf1\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni %1, $vf1\n\tmtc1 %1, $f0\n\tnop\n\tnop\n\tsqrt.s %0, $f0"
            : "=f"(d), "+r"(o) : "r"(self) : "$f0");
    }
    func_0027C1F8(*(s32*)(script + 0x20), 0x976B04A3, d);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3150);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3298);

static inline f32 Len1D(char* self) {
    f32 len;
    asm volatile("lqc2 $vf2, 0xE0(%1)\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni $2, $vf1\n\tmtc1 $2, %0\n\tnop\n\tnop\n\tsqrt.s %0, %0"
        : "=f"(len) : "r"(self) : "$2");
    return len;
}

extern "C" s32 func_001D32D8(char* self, s32 s0) {
    f32 sp0 = 0.0f;
    f32 len;
    func_0027D268(s0, 0, &sp0, 0);
    asm volatile("lqc2 $vf2, 0xE0(%1)\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni $2, $vf1\n\tmtc1 $2, %0\n\tnop\n\tnop\n\tsqrt.s %0, %0"
        : "=f"(len) : "r"(self) : "$2");
    return __builtin_fabsf(len - sp0) < 0.1f;
}

extern "C" s32 func_001D3360(char* self, s32 s0) {
    f32 sp0 = 0.0f;
    func_0027D268(s0, 0, &sp0, 0);
    f32 len = Len1D(self);
    f32 t = sp0;
    asm("" : "+f"(len));
    return t < len;
}

extern "C" s32 func_001D33D8(char* self, s32 s0) {
    f32 sp0 = 0.0f;
    func_0027D268(s0, 0, &sp0, 0);
    f32 len = Len1D(self);
    f32 t = sp0;
    asm("" : "+f"(len));
    return len < t;
}

extern "C" s32 func_001D3450(char* self, s32 s0) {
    register s32 s asm("$17") = s0;
    char* o = func_001D36E8(self, 0xBAF9B341);
    f32 sp0;
    TI128 v;
    register f32* b2 asm("$6") = &sp0;
    if (o) {
        register s32 p0 asm("$4") = s;
        register s32 z asm("$5") = 0;
        func_0027D268(p0, z, b2, 1);
        f32 t = sp0;
        f32 k = 0.017453294f;
        register char* a0 asm("$4") = self + 0xA0;
        register TI128* a1 asm("$5") = &v;
        asm volatile("lqc2 $vf2, 0x80(%0)" : : "r"(self) : "memory");
        register s32 a2 asm("$6") = 2;
        asm("" : "+f"(t));
        register s32 a3 asm("$7") = 1;
        f32 u = t * k;
        sp0 = u;
        asm volatile("lqc2 $vf1, 0x80(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(v) : "r"(o));
        f32 d = func_0010D5C8(a0, a1, a2, a3);
        if (sp0 < __builtin_fabsf(d)) return 1;
    }
    return 0;
}

extern "C" int func_001D3508(S001D2B08* a, void* b, S001D2B08* c) {
    s32 v = a->unk20;

    func_0027C448(c->unk20, 0x24495505 /* objtype */, v);
    return 1;
}

extern "C" s32 func_001D3538(void* p, void* a) {
    s32 v;
    func_0027D870(a, 0, &v, 1);
    return func_001D1CF8(p, v) != 0;
}

struct Q1D35 {
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(int);
};

struct A1D35 {
    s32 unk0;
    s32 unk4;
    s32 (Q1D35::*unk8)(int, int);
};

extern "C" s32 func_001D3580(Q1D35* p, A1D35* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v4(a->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3620);

extern "C" void func_001D36D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D36E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D36E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3810);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3818);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D40F8);

extern "C" void func_001D4110(void) {
}

extern "C" void func_001D4118(char* p, s32 flags) {
    *(void**)(p + 8) = D_0034B838;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D4158(char* p, s32 flags) {
    *(void**)(p + 8) = D_0034B838;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D4198(void) {
    func_001D3818(1, 0xFFFF);
}

GP_DATA(D_0036D3B0);
GP_DATA(D_0036D3B4);
extern "C" S0036D3B0* func_001D41B8(s32 a) {
    if (D_0036D3B0 == 0 && a != 0) {
        D_0036D3B0 = func_001D4260(func_00113DF0(0x458, 0, 1));
    }
    D_0036D3B4++;
    return D_0036D3B0;
}

extern "C" void func_001D4208(void) {
    S0036D3B0* p;

    if (D_0036D3B4 > 1) {
        D_0036D3B4--;
    } else {
        p = D_0036D3B0;
        if (p != 0) {
            p->unk2C[1].fn((char*)p + p->unk2C[1].delta, 3);
        }
        D_0036D3B0 = 0;
        D_0036D3B4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4260);

extern "C" void func_001D4380(char* p, s32 flags) {
    *(void**)(p + 0x2C) = D_0034BA00;
    if (*(char**)(p + 0x4C) != 0) {
        func_00113FB8(*(char**)(p + 0x4C));
        char* q = *(char**)(p + 0x4C);
        if (q != 0) {
            VEnt* e = (VEnt*)(*(char**)(q + 0x18) + 0x10);
            e->fn(q + e->delta, 3);
        }
    }
    func_001D82D8(p, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D43F8);

extern "C" s32 func_001D4400(S0036D3B0* o) {
    s32 g = D_00372DA8;
    s32 n = func_001D10A8(operator_new(0x160));
    func_001CED20(n, g);
    func_001CEDE0(n, 0xCDEB9229);
    VEnt* v = o->unk2C + 2;
    v->fn((char*)o + v->delta, n);
    return n;
}

extern "C" O1D44* func_001D4480(S0036D3B0* self, s32 a, s32 b, s32 c) {
    O1D44* o = (O1D44*)func_001D4400(self);
    if (b != 0) {
        func_001D1998(o, b);
    }
    register G1D44* g asm("$17") = D_0036F658[0];
    register s32 t asm("$7") = *(s32*)((char*)o + 0x54);
    s32 n = g->unk18 + 1;
    g->unk18 = n;
    *(s32*)(n * 4 + (s32)g + 0x1C) = t;
    func_001D17B0(o, a, b, t);
    if (c != 0) {
        o->v9();
    }
    g->unk18 = g->unk18 - 1;
    return o;
}
