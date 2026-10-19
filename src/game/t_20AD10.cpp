#include "common.h"

typedef unsigned int TI20A __attribute__((mode(TI)));

struct S20A {
    char pad0[0x490];
    int unk490;
    char pad494[0x4C];
    int unk4E0;
    char pad4E4[0x4C];
    int unk530;
    char pad534[0x4C];
    int unk580;
    char pad584[0x4C];
    int unk5D0;
    char pad5D4[0x4C];
    int unk620;
    char pad624[0x4C];
    int unk670;
};

extern "C" {
f32 func_0010F698(void*);
f32 func_0010F6C0(void*);
void func_00127818(void*, f32);
void func_00127828(void*, f32);
void func_0020C540(char*, int);
int func_0027D268(int, u32, void*, int);
void func_001E29F0(void*);
int func_0027D1F8(int, u32, int*, int);
int func_0027D870(int, u32, u32*, int);
void func_0020AE18(char*, int);
f32 func_0011ED10(void);
f32 func_0031BD50(f32, f32);
f32 func_0020AD10(f32, f32);
bool func_0027DF00(int, u32);
}

struct S20A_V {
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

struct S20A_A {
    s32 unk0;
    s32 unk4;
    s32 (S20A_V::*unk8)(int, int);
};

static inline void Init20C(char* q) {
    *(int*)(q + 4) = 1;
    func_001E29F0(q);
}

extern int D_0036876C;

extern "C" f32 func_0020AD10(f32 a, f32 b) {
    f32 t = b * (f32)D_0036876C * a;
    return t / ((1.0f - a) + t);
}

extern "C" f32 func_0020AD50(char* p, f32 t) {
    f32 r = func_0031BD50(__builtin_fabsf(t + t - 1.0f), *(f32*)(p + 0xC));
    if (1.0f < r || r < 0.0f) r = 0.0f;
    f32 lo = *(f32*)(p + 4);
    f32 v = 1.0f - (lo + (*(f32*)(p + 8) - lo) * r);
    return func_0011ED10() == 0.0f ? v : func_0020AD10(v, func_0011ED10());
}

extern "C" void func_0020AE18(char* p, int s) {
    int v = 1;
    if (func_0027D1F8(s, 0xF649D637, &v, 0)) *(int*)p = v != 0;
    func_0027D268(s, 0x2762BECD, p + 4, 0);
    func_0027D268(s, 0xB69FEEC6, p + 8, 0);
    func_0027D268(s, 0x9B5B5514, p + 0xC, 0);
    *(f32*)(p + 0xC) = __builtin_fabsf(*(f32*)(p + 0xC));
}

extern "C" void func_0020AEC8(char* p, int s) {
    u32 kk;
    func_0027D870(s, 0x7321A8D6, &kk, 1);
    u32 k = kk;
    bool a = k == 0xC4E78E22 || k == 0xB9D31B0A;
    if (a) func_0020AE18(p + 0x388, s);
    bool b = k == 0xC4E78E22 || k == 0xC97F3AA9;
    if (b) func_0020AE18(p + 0x398, s);
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AF80);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B148);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B570);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B8B8);

extern "C" s32 func_0020B920(S20A_V* p, S20A_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_0020B9C0(void) {
    return 2;
}

extern "C" void func_0020B9C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B9D0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020BF60);

extern "C" void func_0020C0D8(S20A* self) {
    self->unk580 = 0;
    self->unk4E0 = 0;
    self->unk5D0 = 0;
    self->unk530 = 0;
    self->unk620 = 0;
    self->unk670 = 0;
    self->unk490 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C0F8);

extern "C" void func_0020C1F0(TI20A* p) {
    register TI20A v1 asm("vf1") = p[0];
    register TI20A v3 asm("vf3");
    f32 k = -1.0f;
    asm("qmtc2.ni %1, %0" : "=j"(v3) : "r"(k));
    register TI20A v2 asm("vf2") = p[2];
    asm("vmulx.xyzw %0, %0, %1x" : "+j"(v1) : "j"(v3));
    asm("vmulx.xyzw %0, %0, %1x" : "+j"(v2) : "j"(v3));
    p[0] = v1;
    p[2] = v2;
}

extern "C" void func_0020C220(void* p) {
    func_00127818(p, -func_0010F698(p));
    func_00127828(p, -func_0010F6C0(p));
}

extern "C" void func_0020C268(char* p) {
    *(int*)(p + 0x0) = 1;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x20) = 0;
    *(int*)(p + 0x70) = 0;
    *(int*)(p + 0xC0) = 0;
    *(int*)(p + 0xC8) = 0;
    *(int*)(p + 0xD0) = 0;
    *(int*)(p + 0xCC) = 0;
    *(int*)(p + 0xD4) = 0;
    *(int*)(p + 0xDC) = 0;
    *(int*)(p + 0xD8) = 0;
    *(int*)(p + 0xE0) = 0;
    *(int*)(p + 0x100) = 0;
    *(int*)(p + 0x104) = 0;
    *(int*)(p + 0x120) = 0;
    *(int*)(p + 0x128) = 0;
    *(int*)(p + 0x12C) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C2B8);

extern "C" void func_0020C428(char* p, s32 a, TI20A v, f32 f) {
    register TI20A v2 asm("vf2") = v;
    *(s32*)(p + 0x104) = a;
    register TI20A v3 asm("vf3");
    register TI20A v1 asm("vf1");
    asm("vmul.xyzw %0, %2, %2" : "=j"(v3) : "j"(v3), "j"(v2));
    *(TI20A*)(p + 0x110) = v2;
    *(f32*)(p + 0x124) = f;
    asm("vaddy.x %0, %1, %1y" : "=j"(v1) : "j"(v3));
    asm("vaddz.x %0, %0, %1z\n\tnop\n\tnop\n\tvrsqrt $Q, $vf0w, %0x\n\tvwaitq\n\tvmulq.xyz %2, %2, $Q" : "+j"(v1), "+j"(v3), "+j"(v2));
    *(TI20A*)(p + 0x110) = v2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C460);

extern "C" void func_0020C540(char* p, int s) {
    *(int*)p = 1;
    Init20C(p + 4);
    *(int*)(p + 0x40) = !func_0027DF00(s, 0x57EDECCA);
}

extern "C" void func_0020C5A0(char* p, char* q) {
    char* t = p + 4;
    u32 a = *(u32*)(t + 0xC);
    bool ok;
    if (a == 0) {
        ok = true;
    } else {
        ok = !(*(u32*)(t + 0x10) < a);
    }
    if (ok) *(int*)p = 0;
    asm volatile("vmove.xyzw $vf1, $vf0");
    *(int*)(q + 0x1C) = 0;
    asm volatile("sqc2 $vf1, 0x60(%0)" : : "r"(q) : "memory");
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C5D8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C690);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020CAE8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020CB78);

extern "C" void func_0020CD08(char* p, int s) {
    func_0020C540(p, s);
    func_0027D268(s, 0, p + 0x2C, 0);
}
