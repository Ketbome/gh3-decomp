#include "common.h"

typedef unsigned int u128_206 __attribute__((mode(TI)));

struct VEntry206 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S206b {
    char pad0[0x8];
    VEntry206* unk8;
};

struct S206 {
    char pad0[0x18];
    VEntry206* unk18;
    S206b* unk1C;
    u128_206 unk20;
};

struct S206BD0_L {
    char pad0[4];
    u32 unk4;
    s32* unk8;
};

extern "C" {
int func_0027D268_f(int, u32, f32*, int) __asm__("func_0027D268");
int func_0027D470_l(int, u32, S206BD0_L**, int) __asm__("func_0027D470");
int func_002069F8(void*, int, int, int, int, int, f32);
void func_00207DD8(void*, int);
int func_00206728(void*, int, int);
void func_00207E58(int, int);
int func_00206BD0(void*, int, int, int, int);
void* operator_new(u32 size);
void* func_00206FF8(void*);
void* func_00208038(void*);
void func_001D0F90(void*, int);
extern u8 D_00350428[];
void func_00276D48(u32, void*, int);
extern u8 D_0038FCB8[];
int func_0027D870(int, u32, int*, int);
bool func_0027D188(int, u32, int*, int);
void func_002235F0(int, u128_206*);
void func_00161FF8(void*, int);
void* func_001D0F68(void*);
void func_002074E0(void*);
void func_00207E28(S206*, u128_206*);
void func_00206668(void*, void*, int);
extern u8 D_00350288[];
char* func_001D1CF8(void*, u32);
extern void* D_0036F658;
void func_0022B0D0(void*, void*, void*, int);
void func_00134340(void*);
extern void* D_0036D410;
char* func_001D5B60(void*, int);
char* func_001D5BA0(void*, u32, int);
void func_0011BDA8(void*, int);
void func_00207D70(char*);
int func_0027DF00(int p, u32 k);
void func_002078A8_3(S206* s, int a, int b) __asm__("func_002078A8");
void func_0027C448(int, u32, int);
}

struct VE206 {
    s16 delta;
    s16 unk2;
    int (*fn)(void*);
};

struct VE206b {
    s16 delta;
    s16 unk2;
    void (*fn)(void*, void*, int);
};

static inline u128_206 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    u128_206 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct S206_PV {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 v12(int);
};

struct S206_A {
    s32 unk0;
    s32 unk4;
    s32 (S206_PV::*unk8)(int, int);
};

struct D206 {
    char pad0[0x8];
    virtual ~D206();
};

struct C206 {
    u8 r, g, b, a;
    C206(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct S206_V {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
};

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002062E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206520);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206668);

extern "C" int func_00206728(void* p, int a, int b) {
    char buf[0xA0];
    func_00206668(p, buf, a);
    return func_00206BD0(p, a, b, (int)buf, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206788);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002069F8);

extern "C" int func_00206BD0(void* self, int s, int b, int c, int d) {
    f32 sp0 = 0.0f;
    int sp4;
    S206BD0_L* l;
    if (c == 0) {
        if ((func_0027D268_f(s, 0xC48391A5, &sp0, 0) ^ 1) != 0) {
            return 0;
        }
        sp0 = sp0 * sp0;
    }
    l = 0;
    if (func_0027D870(s, 0x7321A8D6, &sp4, 0) != 0) {
        return func_002069F8(self, s, b, c, sp4, d, sp0);
    }
    if (func_0027D470_l(s, 0x7321A8D6, &l, 1) != 0) {
        u32 i = 0;
        if (l->unk4 != 0) {
            do {
                int h;
                f32 f = sp0;
                if (l->unk4 == 1) {
                    h = (int)l->unk8;
                } else {
                    h = l->unk8[i];
                }
                if (func_002069F8(self, s, b, c, h, d, f) != 0) {
                    return 1;
                }
                i++;
            } while (i < l->unk4);
            return 0;
        }
    }
    return 0;
}

extern "C" int func_00206D58(void* self, int a, int b) {
    return func_00206BD0(self, a, b, 0, 0) != 0;
}

extern "C" int func_00206D80(void* p, int s, int q) {
    int id;
    if (!func_0027D870(s, 0x7A8017BA, &id, 0)) return 0;
    u128_206 t;
    func_002235F0(id, &t);
    return func_00206BD0(p, s, q, 0, (int)&t) != 0;
}

extern "C" int func_00206E10(void* self, int a, int b) {
    return func_00206728(self, a, b) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206E30);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206E48);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206F70);

extern "C" void* func_00206FA0(void) {
    return func_00206FF8(operator_new(0x60));
}

extern "C" void func_00206FC8(void) {
    func_00276D48(0x8A897DD2, D_0038FCB8, 0x10);
}

extern "C" void* func_00206FF8(void* self) {
    S206* p = (S206*)self;
    func_001D0F68(p);
    p->unk18 = (VEntry206*)D_00350288;
    *(u32*)((char*)p + 0x4) = 0x8A897DD2;
    *(f32*)((char*)p + 0x44) = 30.0f;
    *(f32*)((char*)p + 0x48) = 150.0f;
    *(u128_206*)((char*)p + 0x30) = MakeVec(0.0f, 1.0f, 0.0f, 1.0f);
    *(u32*)((char*)p + 0x40) = 0x806FFF30;
    p->unk20 = MakeVec(0.0f, 0.0f, 0.0f, 1.0f);
    *(s32*)((char*)p + 0x54) = 1;
    *(s32*)((char*)p + 0x50) = 0;
    p->unk1C = 0;
    return p;
}

extern "C" void func_00207090(S206* p, int flags) {
    p->unk18 = (VEntry206*)D_00350288;
    if (p->unk1C) {
        delete (D206*)p->unk1C;
        p->unk1C = 0;
    }
    func_001D0F90(p, flags);
}

extern "C" void func_002070F8(char* p) {
    *(char**)(p + 0x4C) = func_001D1CF8(*(void**)(p + 0xC), 0x286A8D26);
    *(char**)(p + 0x50) = func_001D1CF8(*(void**)(p + 0xC), 0xCE0CA665);
    char* r[1];
    func_0022B0D0(r, D_0036F658, *(void**)(*(char**)(*(char**)(p + 0x4C) + 0x210) + 0x34), 0);
    char* x = r[0];
    int v;
    if (x) {
        VE206* vt = *(VE206**)(x + 0x34);
        v = vt[2].fn(x + vt[2].delta);
    } else {
        v = 0;
    }
    func_00134340(r);
    char* o = *(char**)(p + 0x1C);
    if (o) {
        VE206b* vt = *(VE206b**)(o + 0x8);
        vt[9].fn(o + vt[9].delta, *(void**)(*(char**)(p + 0x4C) + 0x210), v);
    }
}

extern "C" void func_002071C0(S206* self) {
    VEntry206* e = &self->unk18[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002071E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002074E0);

extern "C" void func_00207748(S206* self, int a) {
    S206b* p = self->unk1C;
    VEntry206* e = &p->unk8[8];
    ((void (*)(void*, int))e->fn)((char*)p + e->delta, a);
}

extern "C" void func_00207778(void* self, int on) {
    func_00207DD8(self, on);
}

extern "C" void func_00207798(char* p) {
    if (*(int*)(p + 0x54)) {
        u128_206 v = *(u128_206*)(*(char**)(p + 0xC) + 0x80);
        func_00207E28((S206*)p, &v);
    }
    func_002074E0(p);
}

extern "C" int func_002077E0(void* p) {
    void* m = D_0036D410;
    if (func_001D5B60(m, 0)) {
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 0;
        func_001D5B60(m, 1);
    }
    func_00207D70((char*)p);
    if (func_001D5B60(m, 0)) {
        char* o = func_001D5B60(m, 1);
        func_0011BDA8(o, *(int*)(func_001D5BA0(m, 0x69B05E2C, 1) + 0x2C));
        func_001D5B60(m, 1);
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 1;
    }
    return 1;
}

extern "C" int func_002078A8(S206* self, int params) {
    void* m = D_0036D410;
    if (func_001D5B60(m, 0)) {
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 0;
        func_001D5B60(m, 1);
    }
    int sp0 = 0;
    if ((func_0027D870(params, 0x9AC24B18, &sp0, 0) ^ 1) != 0) {
        func_0027C448(params, 0x9AC24B18, 0x3E84C2FD);
    }
    VEntry206* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, params);
    if (self->unk1C != 0 && *(int*)((char*)self->unk1C + 4) == 1) {
        f32 sp4 = 0.2f;
        func_0027D268_f(params, 0xA6F5352F, &sp4, 0);
        *(f32*)((char*)self->unk1C + 0x14) = sp4;
    }
    if (func_001D5B60(m, 0)) {
        char* o = func_001D5B60(m, 1);
        func_0011BDA8(o, *(int*)(func_001D5BA0(m, 0x69B05E2C, 1) + 0x2C));
        func_001D5B60(m, 1);
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 1;
    }
    return 1;
}

extern "C" int func_00207A18(S206* self) {
    VEntry206* e = &self->unk18[4];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    return 1;
}

extern "C" int func_00207A48(S206* self, int params, int q) {
    void* m = D_0036D410;
    if (func_001D5B60(m, 0)) {
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 0;
        func_001D5B60(m, 1);
    }
    int t = func_0027DF00(params, 0x5B6634D4) ^ 1;
    if (t != 0 && *(int*)((char*)self + 0x1C) == 0) {
        func_002078A8_3(self, params, q);
    }
    VEntry206* e = &self->unk18[9];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, t ^ 1);
    if (func_001D5B60(m, 0)) {
        char* o = func_001D5B60(m, 1);
        func_0011BDA8(o, *(int*)(func_001D5BA0(m, 0x69B05E2C, 1) + 0x2C));
        func_001D5B60(m, 1);
        *(int*)(func_001D5B60(m, 1) + 0x9C) = 1;
    }
    return 1;
}

extern "C" int func_00207B78(char* p, int s) {
    int v = 0;
    func_0027D870(s, 0, &v, 0);
    u32 k = 0xF649D637;
    *(int*)(p + 0x58) = v == k;
    return 1;
}

extern "C" int func_00207BD0(void) {
    return 2;
}

extern "C" s32 func_00207BD8(S206_PV* p, S206_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207C78);

extern "C" void func_00207D70(char* p) {
    if (*(void**)(p + 0x1C)) {
        char* m = *(char**)(p + 0x4C);
        if (m) func_00161FF8(*(void**)(m + 0x210), 0);
        delete *(D206**)(p + 0x1C);
        *(void**)(p + 0x1C) = 0;
    }
}

extern "C" void func_00207DD8(void* self, int on) {
    S206b* o = ((S206*)self)->unk1C;
    if (o) {
        if (on) {
            ((void (*)(void*))o->unk8[6].fn)((char*)o + o->unk8[6].delta);
        } else {
            ((void (*)(void*))o->unk8[7].fn)((char*)o + o->unk8[7].delta);
        }
    }
}

extern "C" void func_00207E28(S206* self, u128_206* v) {
    self->unk20 = *v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207E38);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207E58);

extern "C" void func_00207FF0(void) {
    func_00207E58(1, 0xFFFF);
}

extern "C" void* func_00208010(void) {
    return func_00208038(operator_new(0x20));
}

static inline void SetId206(S206* p, u32 id) {
    *(u32*)((char*)p + 4) = id;
}

extern "C" void* func_00208038(void* self) {
    S206* p = (S206*)self;
    func_001D0F68(p);
    p->unk18 = (VEntry206*)D_00350428;
    SetId206(p, 0xC472ECC5);
    C206 c(0xFF, 0x80, 0, 0xFF);
    p->unk1C = 0;
    return p;
}

extern "C" void func_00208098(S206* self, int flag) {
    self->unk18 = (VEntry206*)D_00350428;
    func_001D0F90(self, flag);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002080C0);

extern "C" void func_002081A8(S206_V* p, int s) {
    int v = 0;
    bool missing = !func_0027D188(s, 0x286A8D26, &v, 0);
    if (!missing) p->v3(s);
}

extern "C" void func_00208218(S206* self) {
    VEntry206* e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
}

extern "C" int func_00208248(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00208250);

extern "C" S206b* func_00208260(S206* self) {
    return self->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00208268);
