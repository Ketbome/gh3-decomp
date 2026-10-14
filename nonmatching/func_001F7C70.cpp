#include "common.h"

struct S1F79E8 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual s32 v12(int);
};

struct S1F79E8_A {
    s32 unk0;
    s32 unk4;
    s32 (S1F79E8::*unk8)(int, int);
};

struct S1F9740_R {
    char pad0[0x14];
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual s32 v4(s32, void*, void*);
    virtual void v5(void*);
};

struct S1F9860_N {
    S1F9860_N* unk0;
    S1F9860_N* unk4;
    S1F9740_R* unk8;
};

struct S1F9860_I {
    s32 unk0;
    S1F9860_N* unk4;
};

struct S1F9860 {
    char pad0[0x48];
    S1F9860_N unk48;
};

struct E1F8D90 {
    u32 key;
    char pad4[0xC];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct N1F8D90 {
    N1F8D90* unk0;
    N1F8D90* unk4;
    E1F8D90 e;
};

struct I1F8D90 {
    s32 unk0;
    N1F8D90* unk4;
};

struct S1F8D90 {
    char pad0[0x3C];
    N1F8D90 unk3C;
};

extern "C" {
s32 func_001F9D70(void*);
s32 func_00133CE8(void*, s32, int, void*);
s32 func_001317D0(void*, s32);
s32 func_001F7B10(void*, s32, void*);
s32 func_001F7C70(void*, s32, void*);
s32 func_001F7D70(void*, s32, void*);
s32 func_001F7E70(void*, s32, void*);
bool func_0027D870(void*, u32, s32*, int);
void func_001FA218(void*, s32);
s32 func_001F9C58(void*, s32);
s32 func_001F9D18(void*, s32);
s32 func_001F9EC8(void*, s32);
void func_0027C448(void*, int, u32);
S1F9740_R* func_001F9A50(void*, s32);
s32 func_0027D1F8(void*, u32, s32*, int);
s32 func_0027D268(void*, u32, f32*, int);
}

extern "C" void func_001F79D8(void) {
}

extern "C" s32 func_001F79E0() {
    return 2;
}

extern "C" s32 func_001F79E8(S1F79E8* p, S1F79E8_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" s32 func_001F7A88(char* p, s32 a, void* b) {
    return func_00133CE8(*(void**)(p + 0x1C), a, 3, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7AB0);

extern "C" s32 func_001F7AC8(char* p, s32 a, void* b) {
    return func_001F7B10(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7B10);

extern "C" s32 func_001F7C28(char* p, s32 a, void* b) {
    return func_001F7C70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

typedef unsigned int TI1F7 __attribute__((mode(TI)));

struct L1F7 {
    TI1F7 m0, m1, m2, m3, r;
};

struct P1F7 {
    char pad0[0xC];
    char* unkC;
    char pad10[0xC];
    s32 unk1C;
};

extern "C" s32 func_00133D38(s32, s32, s32, void*);

extern "C" s32 func_001F7C70(void* pv, s32 a, void* vv) {
    P1F7* p = (P1F7*)pv;
    TI1F7* v = (TI1F7*)vv;
    L1F7 l;
    s32 ok = 1;
    if (func_00133D38(p->unk1C, a, 1, v) == 0) {
        TI1F7 lo, hi;
        f32 one = 1.0f;
        f32 zero = 0.0f;
        asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(one), "r"(zero));
        asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(one), "r"(zero));
        asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
        ok = 0;
        *v = lo;
    }
    char* base = p->unkC;
    char* m = base + 0xA0;
    int d;
    asm("lqc2 $vf3, 0xA0(%1)" : "=r"(d) : "r"(base));
    asm("lqc2 $vf1, 0(%1)" : "+r"(d) : "r"(v));
    asm("vmulax.xyzw $ACC, $vf3, $vf1x" : "+r"(d));
    asm("sqc2 $vf3, %1" : "+r"(d), "=m"(l.m0));
    asm("lqc2 $vf2, 0x10(%1)" : "+r"(d) : "r"(m));
    asm("vmadday.xyzw $ACC, $vf2, $vf1y" : "+r"(d));
    asm("sqc2 $vf2, %1" : "+r"(d), "=m"(l.m1));
    asm("lqc2 $vf3, 0x20(%1)" : "+r"(d) : "r"(m));
    asm("vmaddaz.xyzw $ACC, $vf3, $vf1z" : "+r"(d));
    asm("sqc2 $vf3, %1" : "+r"(d), "=m"(l.m2));
    asm("lqc2 $vf2, 0x30(%1)" : "+r"(d) : "r"(m));
    asm("vmaddw.xyzw $vf1, $vf2, $vf1w" : "+r"(d));
    asm("sqc2 $vf1, %1" : "+r"(d), "=m"(*v));
    asm("sqc2 $vf2, %1" : "+r"(d), "=m"(l.m3));
    asm("sqc2 $vf1, %1" : "+r"(d), "=m"(l.r));
    return ok;
}

extern "C" s32 func_001F7D28(char* p, s32 a, void* b) {
    return func_001F7D70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7D70);

extern "C" s32 func_001F7E28(char* p, s32 a, void* b) {
    return func_001F7E70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7E70);

extern "C" void func_001F7F28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7F30);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F86D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F86D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8A88);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8AB8);

extern "C" s32 func_001F8C08(void* p) {
    func_001F9D70(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8C28);

extern "C" s32 func_001F8D40(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x5CFCCF35, &v, 0);
    func_001FA218(p, v);
    return 1;
}

static inline E1F8D90* Find1F8D90(S1F8D90* p, u32 key) {
    I1F8D90 it;
    I1F8D90 e;
    it.unk4 = p->unk3C.unk4;
    e.unk4 = &p->unk3C;
    while (it.unk4 != e.unk4) {
        E1F8D90* c = &it.unk4->e;
        if (c->key == key) {
            return c;
        }
        if (key < c->key) {
            return 0;
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk3C;
    }
    return 0;
}
extern "C" s32 func_001F8D90(S1F8D90* p, void* u, void* a) {
    s32 v = 0;
    func_0027D1F8(a, 0x3D836C96, &v, 1);
    E1F8D90* f = Find1F8D90(p, v);
    if (f) {
    f32 x = 0.0f;
    f32 y = 0.0f;
    func_0027D268(a, 0x4D786F62, &x, 1);
    func_0027D268(a, 0xBF237659, &y, 0);
    f32 b = y;
    f32 c = x;
    f->unk1C = b;
    f->unk14 = c;
    f->unk18 = 0.0f;
    if (b == 0.0f) {
        f->unk10 = c;
    }
    return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8EA8);

extern "C" s32 func_001F9028(void* p, void* u, void* a, void** b) {
    s32 v = 0;
    func_0027D870(a, 0x5CFCCF35, &v, 0);
    if (func_001F9EC8(p, v)) {
        func_0027C448(b[8], 0, 0xC7C6228C);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F90A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F91E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F9478);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F95C8);

extern "C" s32 func_001F9740(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x7321A8D6, &v, 1);
    S1F9740_R* r = func_001F9A50(p, v);
    if (!r) {
        return 0;
    }
    r->v5(a);
    return 1;
}

extern "C" bool func_001F97C0(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x40C698AF, &v, 1);
    return func_001F9C58(p, v) != 0;
}

extern "C" bool func_001F9810(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x40C698AF, &v, 1);
    return func_001F9D18(p, v) != 0;
}

extern "C" s32 func_001F9860(S1F9860* p, void* u, void* a, void* b) {
    s32 v = 0;
    func_0027D870(a, 0x7135152B, &v, 1);
    s32 k = v;
    S1F9860_I it;
    S1F9860_I e;
    it.unk4 = p->unk48.unk4;
    e.unk4 = &p->unk48;
    while (it.unk4 != e.unk4) {
        it.unk4->unk8->v4(k, a, b);
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk48;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F9920);
