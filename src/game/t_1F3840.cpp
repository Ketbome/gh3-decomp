#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

static inline f32 GetX(TI128 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}

static inline f32 GetY(TI128 q) {
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(f) : "0"(q));
    return f;
}

static inline f32 GetZ(TI128 q) {
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(f) : "0"(q));
    return f;
}

static inline TI128 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    TI128 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct S1F3840_V {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int);
};

struct S1F3C70_A {
    char pad0[0x40];
    f32 unk40;
    char pad44[0xC];
    TI128 unk50;
};

struct S1F3C70 {
    TI128 unk0;
    f32 unk10;
};

struct S1F56A8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    char pad14[0xC];
    TI128 unk20;
    TI128 unk30;
};

struct S1F4AF8_C {
    char pad0[0x80];
    TI128 unk80;
    char pad90[0x30];
    TI128 unkC0;
};

struct S1F4AF8_R {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x4];
    TI128 unk40;
    TI128 unk50;
};

struct S1F41D8 {
    char pad0[0xC];
    S1F4AF8_C* unkC;
    char pad10[0xC];
    s32 unk1C;
    char pad20[0x4];
    s32 unk24;
    void* unk28;
    char* unk2C;
    s32 unk30;
};

struct S1F4B38_B {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int);
};

struct S1F4B38;
struct S1F4B38 : S1F4B38_B {
    char pad1C[0x110];
    char* unk12C;
};

struct S1F3F98 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual s32 v12(int);
};

struct S1F3F98_A {
    s32 unk0;
    s32 unk4;
    s32 (S1F3F98::*unk8)(int, int);
};

struct S1F5718 {
    char pad0[0xC0];
    f32 unkC0;
    char padC4[0x1C];
    TI128 unkE0;
};

struct Comp1F3 {
    u32 flags;
    u32 key;
    union {
        s32 i;
        f32 f;
    } v;
    f32 GetF() { return (flags & 0xFE00) == 0x200 ? (f32)v.i : v.f; }
};

struct S1F3C88 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0x4];
    f32 unk10;
};

extern "C" {
struct S1F3C88;
struct Comp1F3;
void func_001F3C88(S1F3C88*, Comp1F3*);
void* func_001618A0(void*, int);
extern char D_0034EF60[];
void func_001D0F90(void*, void*);
extern void* D_00369A54;
void func_00156F80(void*, s32);
S1F4AF8_R* func_00156FA8(void*, s32);
void func_001F4ED0(void*, void*);
void func_001F4BE0(void*, void*);
S1F4AF8_R* func_001F4748(S1F41D8*);
void func_001F4B38(struct S1F4B38*);
extern s32 D_00372E18[] __attribute__((section(".sdata")));
void func_0015EF48(void*, s32);
void func_0015EF78(void*);
void* func_001F4780(S1F41D8*);
void func_0013D1B8(void*, int);
void func_001548F8(void*);
void func_00154640(void*, f32);
bool func_0027DD88(void*, u32);
bool func_0027D870(void*, u32, s32*, int);
extern char D_0034F0E8[];
extern char D_0034F160[];
void func_001F5D28(void*, int);
void func_0027C1F8(void*, u32, f32);
void* func_002763E0(u32, int);
s32 func_0027CC30(void*, u32, int, s32*);
void func_0027F1E0(void*, int, int);
void func_0020EAC0(void*, s32);
void func_0020EFA8(void*, s32);
s32 func_00276008(u32, int);
f32 func_00275DE0(u32, int);
extern f32 D_0036E3B0;
extern f32 D_0036E3B4;
extern f32 D_0036E3B8;
void* func_001D1CF8(void*, u32);
void func_001F4B90(S1F41D8*);
void func_0020EA48(void*);
extern s32 D_00372E10[] __attribute__((section(".sdata")));
void func_001D0F68(void*);
void func_001F56A8(S1F56A8*);
void func_001F4880(char*);
}

struct N1F38 {
    char pad0[8];
    u32 unk8;
    u32 unkC;
    u32 unk10;
    f32 unk14;
    char pad18[0x10];
    f32 unk28;
};

struct VE1F38 {
    s16 delta;
    s16 pad;
    void (*fn)(char*, s32);
};

extern "C" {
f32 func_001E2850(N1F38*, u32);
u32 func_001E2968(N1F38*, u32);
void func_001F3DE0(S1F3C70*, char*, char*, char*, f32);
void func_001F3C08(S1F3C70*, S1F3C70_A*, f32);
}

void func_001F3840_d(char* p) __asm__("func_001F3840");
void func_001F3840_d(char* p) {
    S1F3C70 buf;
    N1F38* n = *(N1F38**)(p + 0x8C);
    f32 f;
    if (n == (N1F38*)(p + 0x60)) {
        u32 k = func_001E2968(n, n->unk8);
        f32 a = func_001E2850(n, k);
        f32 d = a - func_001E2850(n, n->unk10);
        n->unk10 = k;
        n->unk14 = d;
        n->unk28 = a;
        f = a;
    } else {
        f = n->unk28;
    }
    func_001F3DE0(&buf, p + 0x90, p + 0x20, p + 0x40, f);
    func_001F3C08(&buf, *(S1F3C70_A**)(p + 0x1C), *(f32*)(p + 0xB8));
    N1F38* m = *(N1F38**)(p + 0x8C);
    u32 c = m->unkC;
    s32 r;
    if (c == 0) {
        r = 1;
    } else {
        r = m->unk10 >= c;
    }
    VE1F38* e = (VE1F38*)(*(char**)(p + 0x18) + 0x40);
    e->fn(p + e->delta, r);
}

extern "C" void func_001F3920(S1F3840_V* p) {
    p->v8(0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F3950);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F3A40);

extern "C" void func_001F3C08(S1F3C70* s, S1F3C70_A* d, f32 t) {
    d->unk50 = s->unk0;
    func_001548F8(d);
    d->unk40 = s->unk10;
    func_001548F8(d);
    func_00154640(d, t);
}

extern "C" void func_001F3C70(S1F3C70* p, S1F3C70_A* a) {
    p->unk0 = a->unk50;
    p->unk10 = a->unk40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F3C88);

extern "C" void func_001F3DC0(S1F3C70* p) {
    p->unk0 = MakeVec(1.0f, 1.0f, 1.0f, 1.0f);
    p->unk10 = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F3DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F3E68);

extern "C" void func_001F3EF0(void* a, void* b) {
    func_001F3C88((S1F3C88*)b, (Comp1F3*)a);
}

extern "C" void func_001F3F18(char* p, void* a) {
    func_0013D1B8(p + 0x60, 2);
    *(char**)(p + 0x18) = D_0034EF60;
    func_001D0F90(p, a);
}

extern "C" void func_001F3F68(char* p, void* a) {
    *(char**)(p + 0x18) = D_0034EF60;
    func_001D0F90(p, a);
}

extern "C" s32 func_001F3F90() {
    return 2;
}

extern "C" s32 func_001F3F98(S1F3F98* p, S1F3F98_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001F4038(void) {
}

extern "C" void func_001F4040(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4048);

extern "C" char* func_001F4070(char* p) {
    char* q = p + 0x100;
    char* m80 = p + 0x80;
    char* mC0 = p + 0xC0;
    func_001D0F68(p);
    *(char* volatile*)(p + 0x18) = D_0034F160;
    s32 id = D_00372E10[0];
    *(char**)(p + 0x18) = D_0034F0E8;
    *(s32*)(p + 0x4) = id;
    *(s32*)(p + 0x100) = 1;
    *(s32*)(p + 0x1C) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(q + 0x4) = 1;
    *(s32*)(q + 0x8) = 0;
    *(s32*)(q + 0xC) = 0;
    *(s32*)(q + 0x10) = 0;
    *(s32*)(q + 0x14) = 0;
    char* h = p + 0x120;
    *(char**)h = h;
    *(char**)(p + 0x118) = q;
    *(char**)(h + 4) = h;
    *(f32*)(q + 0x28) = 1.0f;
    *(s32*)(p + 0x138) = 0;
    *(s32*)(p + 0x154) = 0;
    *(s32*)(p + 0x158) = 0;
    func_001F56A8((S1F56A8*)(p + 0x40));
    func_001F56A8((S1F56A8*)m80);
    func_001F56A8((S1F56A8*)mC0);
    *(s32*)(p + 0x100) = 0;
    *(s32*)(q + 0x4) = 1;
    *(char**)(p + 0x12C) = q;
    return p;
}

extern "C" void func_001F4168(char* p, void* a) {
    *(char**)(p + 0x18) = D_0034F0E8;
    if (*(void**)(p + 0x158)) {
        func_001F5D28(*(void**)(p + 0x158), 3);
    }
    func_0013D1B8(p + 0x100, 2);
    *(char**)(p + 0x18) = D_0034F160;
    func_001D0F90(p, a);
}

extern "C" void func_001F41D8(S1F41D8* p) {
    if (p->unk1C) {
        func_00156F80(D_00369A54, p->unk24);
    }
}

extern "C" void func_001F4208(void* p, void* a) {
    func_001F4BE0(p, a);
    func_001F4ED0(p, a);
}

GP_DATA(D_0036E3B8);
extern "C" void func_001F4248(S1F41D8* p) {
    D_00372E18[0] = func_00276008(0x75596EC6, 0);
    D_0036E3B0 = func_00275DE0(0xAE64C56C, 0);
    D_0036E3B4 = func_00275DE0(0xC6EE5968, 0);
    D_0036E3B8 = func_00275DE0(0x6F0B3B87, 0);
    p->unk28 = func_001D1CF8(p->unkC, 0x4EA42EAC);
    p->unk2C = (char*)func_001D1CF8(p->unkC, 0x286A8D26);
    S1F4AF8_R* r = func_001F4748(p);
    if (r && r->unk38) {
        p->unk30 = r->unk38;
    } else {
        p->unk30 = 0;
    }
    if (p->unk2C) {
        func_001F4B90(p);
    }
    func_001F4B38((S1F4B38*)p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4320);

extern "C" void func_001F4718(S1F3840_V* p) {
    p->v8(0);
}

extern "C" S1F4AF8_R* func_001F4748(S1F41D8* p) {
    if (!p->unk1C) {
        return 0;
    }
    return func_00156FA8(D_00369A54, p->unk24);
}

extern "C" void* func_001F4780(S1F41D8* p) {
    return func_001618A0(*(void**)(p->unk2C + 0x210), 0);
}

extern "C" char* func_001F47A8(char* p, void* a) {
    char* q = p + 0x144;
    char* m80 = p + 0x80;
    char* mC0 = p + 0xC0;
    func_0020EA48(p + 4);
    *(s32*)(p + 0x144) = 1;
    *(s32*)(q + 0x4) = 1;
    *(s32*)(q + 0x8) = 0;
    *(s32*)(q + 0xC) = 0;
    *(s32*)(q + 0x10) = 0;
    *(s32*)(q + 0x14) = 0;
    char* h = p + 0x164;
    *(char**)h = h;
    *(char**)(p + 0x15C) = q;
    *(char**)(h + 4) = h;
    *(s32*)(p + 0x140) = 0;
    func_001F56A8((S1F56A8*)(p + 0x40));
    func_001F56A8((S1F56A8*)m80);
    func_001F56A8((S1F56A8*)mC0);
    *(s32*)(q + 0x4) = 3;
    *(s32*)(p + 0x4) = 0;
    func_001F4880(p);
    s32 v;
    func_0027D870(a, 0x264CD625, &v, 1);
    *(s32*)p = v;
    return p;
}

static inline s32 Get1F4880(void* s, u32 k, int t) {
    s32 r;
    if (func_0027CC30(s, k, t, &r)) {
        return r;
    }
    func_0027F1E0(s, 0, 1);
    return 0;
}
extern "C" void func_001F4880(char* p) {
    void* s = func_002763E0(0xF87C3C51, 1);
    func_0020EAC0(p + 4, Get1F4880(s, 0x8D1A67E1, 10));
    func_0020EFA8(p + 0x24, Get1F4880(s, 0xB34F15C9, 12));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4948);

extern "C" void func_001F4AF8(S1F41D8* p) {
    S1F4AF8_R* r = func_001F4748(p);
    r->unk40 = p->unkC->unk80;
    r->unk50 = p->unkC->unkC0;
}

extern "C" void func_001F4B38(S1F4B38* p) {
    if (!*(s32*)(p->unk12C + 0xC)) {
        p->v2();
    } else {
        p->v8(0);
    }
}

extern "C" void func_001F4B90(S1F41D8* p) {
    func_0015EF48(func_001F4780(p), D_00372E18[0]);
    func_0015EF78(func_001F4780(p));
    *(s32*)(p->unk2C + 0x2C0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F4ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F5100);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F5510);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F5590);

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F56A8);

extern "C" s32 func_001F56E8(void* p, void* a) {
    func_001F4ED0(p, a);
    func_001F4B38((S1F4B38*)p);
    return 1;
}

extern "C" s32 func_001F5718(S1F5718* p, void* a, void** b) {
    func_0027C1F8(b[8], 0x9211DED6, p->unkC0);
    func_0027C1F8(b[8], 0x0672BFD0, GetX(p->unkE0) * 2.0f);
    func_0027C1F8(b[8], 0x0C6AA32E, GetY(p->unkE0) * 2.0f);
    func_0027C1F8(b[8], 0xB71C7ABC, GetZ(p->unkE0) * 2.0f);
    return 1;
}

extern "C" bool func_001F57B8(void* a) {
    if (func_0027DD88(a, 0x264CD625)) {
        s32 v;
        func_0027D870(a, 0x264CD625, &v, 1);
        return v != (s32)0x806FFF30;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F3840", func_001F5820);
