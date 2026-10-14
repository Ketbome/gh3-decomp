#include "common.h"

struct S204 {
    char pad0[0x4];
    void* unk4;
    char pad8[0x4];
    void* unkC;
    char pad10[0x8];
    void* unk18;
    int unk1C;
    f32 unk20;
    f32 unk24;
    char pad28[0x4];
    int unk2C;
    int unk30;
    int unk34;
    char pad38[0x4];
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    char pad48[0x4];
    int unk4C;
};

struct C204 {
    u8 r, g, b, a;
    C204(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct S204_V {
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

struct S204_A {
    s32 unk0;
    s32 unk4;
    s32 (S204_V::*unk8)(int, int);
};

struct S204_O {
    char pad0[0x18];
    void* unk18;
    void* unk1C;
    void* unk20;
};

extern "C" {
int func_0015D5A0(int);
void func_001D1068(S204*, int);
void func_00113F38(void*);
void func_002060A0(int, int);
void* operator_new(u32 size);
void* func_00205748(void*);
void func_001D0F90(void*, int);
extern u8 D_0034FFA0[];
int func_001D1CF8(void*, u32);
void func_00205A40(S204*);
void func_001D14C0(void*, int);
void func_00276D68(u32, void*, int);
extern u8 D_0038FC38[];
extern void* D_0036E99C;
void* func_00205F00(void*);
int func_00222F90(u32);
void func_00205E50(S204*, int);
void func_001DD190(void*);
void func_001DD260(void*, void*, void*);
void* func_001D0F68(void*);
float func_00275DE0(u32, int);
void* func_00113EA8(void*, int);
void func_00205F98(void);
extern u8 D_00350018[];
extern int D_00370EE0;
void func_00114958(int, void*);
int func_0027D1F8(int, u32, int*, int);
}

typedef unsigned int u128_204 __attribute__((mode(TI)));

static inline u128_204 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    u128_204 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

extern "C" void func_00204298(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002042A0);

extern "C" void func_00204498(char* p) {
    func_001DD190(*(void**)(p + 0x22C));
    char* b = *(char**)(p + 0xC);
    f32 f = *(f32*)(b + 0x84);
    func_001DD260(*(void**)(p + 0x22C), b + 0x80, b + 0xA0);
    if (*(int*)(p + 0x230)) *(f32*)(*(char**)(p + 0xC) + 0x84) = f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002044F8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204688);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204828);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204A50);

extern "C" int func_00204A78(S204* p) {
    int r = 0;
    if (*(u32*)((char*)p + 0x2A0) != 0xB9C81736 || func_00222F90(0xB9C81736)) r = 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204AD8);

extern "C" void func_00205680(u128_204* p) {
    u128_204 v = MakeVec(0.0f, 0.0f, 0.0f, 1.0f);
    p[0] = v;
    p[1] = v;
    p[2] = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002056B0);

extern "C" void* func_002056D8(void) {
    return func_00205748(operator_new(0x54));
}

extern "C" void func_00205700(void) {
    func_00276D68(0xCE0CA665, D_0038FC38, 0x10);
    D_0036E99C = func_00205F00(operator_new(8));
}

extern "C" void* func_00205748(void* self) {
    S204* p = (S204*)self;
    func_001D0F68(p);
    p->unk18 = D_0034FFA0;
    p->unk4 = (void*)0xCE0CA665;
    C204 c(0, 0x80, 0x80, 0xFF);
    float f = func_00275DE0(0xAD501995, 0);
    p->unk2C = 10;
    p->unk4C = 3;
    p->unk24 = f * f;
    p->unk20 = f;
    p->unk1C = 0;
    return p;
}

extern "C" void func_002057D0(S204* self, int flag) {
    self->unk18 = D_0034FFA0;
    func_001D0F90(self, flag);
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002057F8);

extern "C" void func_002059E8(S204* p) {
    p->unk30 = func_001D1CF8(p->unkC, 0x286A8D26);
}

extern "C" void func_00205A20(S204* self) {
    func_001D1068(self, 1);
}

extern "C" void func_00205A40(S204* self) {
    self->unk4C = 10;
    self->unk2C = 10;
}

extern "C" s32 func_00205A50(S204_V* p, S204_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_00205AF0(void) {
    return 2;
}

extern "C" void func_00205AF8(void) {
}

extern "C" void func_00205B00(S204* p) {
    p->unk3C = 300000.0f;
    p->unk40 = 300001.0f;
    p->unk44 = 300002.0f;
}

extern "C" int func_00205B38(S204* self) {
    return self->unk34;
}

extern "C" void func_00205B40(void) {
}

struct S205B {
    char pad0[0xC];
    char* unkC;
    char pad10[0xC];
    int unk1C;
    char pad20[8];
    f32 unk28;
    char pad2C[4];
    char* unk30;
    char pad34[0x14];
    f32 unk48;
    int unk4C;
};

union V205 {
    u128_204 q;
    struct { f32 x __attribute__((aligned(16))); f32 y, z, w; } v;
};

extern "C" u128_204 func_001EF570(void*);
extern "C" int func_0015D6F0();
extern "C" int func_001B9D78(void*, f32);
extern int D_0036E994;

GP_DATA(D_0036E994);
extern "C" int func_00205B48(S205B* p, f32* out) {
    if (p->unk1C != 0) return 1;
    {
        int r = 1;
        f32 d = p->unk28;
        f32 sq = p->unk48 * p->unk48;
        if (out) *out = d;
        char* o = p->unk30;
        if (o && *(int*)(o + 0x210)) {
            V205 u;
            u128_204 q = func_001EF570(o);
            u.q = q;
            register u32 t asm("$2");
            f32 w;
            asm volatile("qmtc2.ni %0, $vf1" : : "r"(q));
            asm("pcpyud %0, %1, %1" : "=r"(t) : "0"(q));
            asm("dsrl32 %0, %0, 0" : "+r"(t));
            asm("mtc1 %1, %0" : "=f"(w) : "r"(t));
            asm volatile("lqc2 $vf2, 0x80(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&u), "r"(p->unkC) : "memory");
            u.v.w = w;
            f32 w2;
            if (func_0015D6F0() == r && func_0015D5A0(0)) {
                asm("pcpyud %0, %1, %1" : "=r"(w2) : "0"(u.q));
                asm("dsrl32 %0, %0, 0" : "+r"(w2));
                if (!func_001B9D78(&u, w2)) return p->unk4C ? r : 0;
            }
        }
        if (sq < d) {
            D_0036E994++;
            if (D_0036E994 & 1) r = 0;
        }
        return p->unk4C ? 1 : r;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205C60);

extern "C" f32 func_00205DF0(S204* p) {
    register char* t asm("$3") = (char*)func_0015D5A0(0);
    if (t != 0) {
    register s32 i asm("$2");
    asm("lqc2 $vf2, 0x80(%1)\n\tlqc2 $vf1, 0x80(%2)\n\tvsub.xyzw $vf2, $vf2, $vf1\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni %0, $vf1"
        : "=r"(i)
        : "r"(t), "r"(p->unkC));
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(i));
    return f;
    }
    return 0.0f;
}

extern "C" void func_00205E50(S204* self, int v) {
    self->unk1C = v;
}

extern "C" int func_00205E58(S204* p) {
    func_00205A40(p);
    func_001D14C0(p->unkC, 0);
    return 1;
}

extern "C" int func_00205E90(S204* self) {
    return self->unk1C == 0;
}

extern "C" int func_00205EA0(S204* p, int s) {
    int v = 1;
    func_0027D1F8(s, 0xF649D637, &v, 0);
    func_00205E50(p, v != 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205EF8);

static inline void InitTask204(S204_O* o, void* fn, void* data, int pri) {
    func_00113EA8(o, pri);
    o->unk1C = fn;
    o->unk20 = data;
    o->unk18 = D_00350018;
}

extern "C" void* func_00205F00(void* self) {
    S204* p = (S204*)self;
    S204_O* o = (S204_O*)operator_new(0x24);
    InitTask204(o, (void*)func_00205F98, p, -0x44C);
    p->unk4 = o;
    C204 c(0xFF, 0, 0, 0xFF);
    func_00114958(D_00370EE0 + 8, o);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205F98);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00206098);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002060A0);

extern "C" void func_002061C0(void* p) {
    func_00113F38(p);
}

extern "C" void func_002061E0(S204* self) {
    ((void (*)(S204*))self->unk1C)(self);
}

extern "C" void func_00206200(void) {
    func_002060A0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00206220);
