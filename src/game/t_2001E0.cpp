#include "common.h"

typedef unsigned int u128_200 __attribute__((mode(TI)));

struct VEntry200 {
    s16 delta;
    s16 unk2;
    void* (*fn)(void*, int);
};

struct S200b {
    char pad0[0x70];
    int unk70;
    int unk74;
    char pad78[0x8];
    u128_200 unk80;
    char pad90[0x20];
    union {
        f32 unkB0;
        int unkB0i;
    };
    char padB4[0x50];
    VEntry200* unk104;
};

struct S200_V {
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

struct S200_D {
    char pad0[0x104];
    virtual ~S200_D();
};

struct V200 {
    f32 f[4];
    f32& operator[](int i) { return f[i]; }
};

struct S201B50 {
    char pad0[0x160];
    f32 a160[4];
    char pad170[0x10];
    V200 m[4];
};

struct M200 {
    u128_200 r[4];
};

union U200 {
    u128_200 q;
    f32 f[4];
};

struct S200_A {
    s32 unk0;
    s32 unk4;
    s32 (S200_V::*unk8)(int, int);
};

struct S200 {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x4];
    S200b* unkC;
    char pad10[0x8];
    VEntry200* unk18;
    int unk1C;
    int unk20;
    char pad24[0x4];
    int unk28;
    int unk2C;
    int unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    char pad44[0x3C];
    int unk80;
    u8 unk84;
    char pad85[0x3];
    int unk88;
    char pad8C[0x94];
    void* unk120;
    char pad124[0xAC];
    int unk1D0;
    int unk1D4;
    int unk1D8;
    f32 unk1DC;
    int unk1E0;
    char pad1E4[0xC];
    u128_200 unk1F0;
    int unk200;
    f32 unk204;
    f32 unk208;
    void* unk20C;
    f32 unk210;
    f32 unk214;
    int unk218;
    char pad21C[0x4];
    int unk220;
    int unk224;
    S200b* unk228;
    void* unk22C;
};

extern "C" {
void func_002001E8(int, int);
void* operator_new(u32 size);
void* func_00200380(void* self);
void func_00276D48(u32 key, void* data, int size);
extern u8 D_0038F928[];
int func_00200920(S200*);
void func_00202258(S200*);
void func_002024B0(S200*, int, int, int);
int func_00204828(S200*);
void func_002028D8(S200*);
void func_00202828(S200*);
void func_00202960(S200*, int, int);
void func_00201DE8(S200*, int, u128_200*);
void func_00202D50(S200*);
void func_00203138(S200*, int, int, int);
void func_00203208(S200*);
void func_002044F8(S200*);
int func_0027D058(int, int, int*, int);
void func_00202ED0(S200*, int, int, u128_200, int);
int func_00200930(int, int*);
int func_00200958(int, int*);
void func_00204248(S200*);
S200b* func_00201A38(S200*);
void func_00201C80(S200*, int);
void func_00202C88(S200*, int, int);
void func_00289F48(int, int, void*, int);
int func_00200910(S200*);
void func_002235F0(int, u128_200*);
S200b* func_001DD8D8(void*, int);
int func_0027DF00(int, u32);
int func_00223460(int);
int func_0010C050(int);
void func_0027C160(int, u32, int);
int func_0027D870(int, u32, int*, int);
void func_00203448(S200*, int);
void func_00201BF8(S200*, int);
void func_00203058(S200*, int, S200*);
void func_002019E8(S200*, int);
void func_001DD4D0(void*, S200b*);
int func_001DD5F8(void);
void* func_001DD658(int, S200b*, int);
void func_001DE0F8(S200b*, int, u128_200*);
int func_0027D268(int, u32, float*, int);
void func_0027ACF8(int, u32);
S200* func_002042A0(S200*, float);
void func_0027C448(int, u32, int);
extern u8 D_0034FDF0[];
extern void* D_00368A38;
void Heap_Free(void*, void*);
void func_001DD118(void*, int);
void func_001D0F90(void*, int);
void func_001D0F68(void*);
void func_00205680(void*);
void func_00201AA0(S200*);
int func_0027DC58(int, int, int*, int);
int func_00224220(int, int);
void func_00223590(int, u128_200*);
S200* func_001D1CF8(S200b*, u32);
extern u32 D_00370F40;
u32 func_00275570(void);
float func_002EC100(float);
void func_00289F90(S200b*);
void func_00200980(S200*);
void func_00203C58(S200*, int, int);
int func_0027D400(int, u32, int*, int);
void func_001D03D8(S200b*, int, int, int, int);
void func_001D03B8(S200b*, int, int);
void* Heap_Alloc(void*, int, int, int);
void* func_0010F748(void*);
void func_0010F750(void*, void*, M200*);
int func_0027D2D8(int, u32, void*, int);
}

static inline u128_200 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    u128_200 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

#define F200(p, o) (*(f32*)((char*)(p) + (o)))
#define Q200(p, o) (*(u128_200*)((char*)(p) + (o)))
#define I200(p, o) (*(int*)((char*)(p) + (o)))

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002001E0);

struct V01E8 {
    int a;
    int b;
};

struct E01E8 {
    u32 key;
    u32 type;
    V01E8 v;
};

extern E01E8 T01E8[] __asm__("D_0038F8E8");
extern V01E8 S01E8_0[] __asm__("D_0036E768");
extern V01E8 S01E8_1[] __asm__("D_0036E770");
extern V01E8 S01E8_2[] __asm__("D_0036E778");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_002001E8(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E01E8* e = T01E8;
        V01E8 t;
        e->key = 0x785E57C7;
        t = *S01E8_0;
        e->type = 0x5CB5CB7E;
        e->v = t;
        e++;
        e->key = 0xC49D01C6;
        t = *S01E8_1;
        e->type = 0x5CB5CB7E;
        e->v = t;
        e++;
        e->key = 0xD40CD91D;
        t = *S01E8_2;
        e->type = 0x5CB5CB7E;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0x5CB5CB7E;
        e->v = t;
    }
}

extern "C" void func_00200308(void) {
    func_002001E8(1, 0xFFFF);
}

extern "C" void* func_00200328(void) {
    return func_00200380(operator_new(0x2B0));
}

extern "C" void func_00200350(void) {
    func_00276D48(0x0A015E17, D_0038F928, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200380);

extern "C" void func_00200428(S200* p, int flags) {
    p->unk18 = (VEntry200*)D_0034FDF0;
    if (p->unk228) {
        delete (S200_D*)p->unk228;
        p->unk228 = 0;
    }
    if (p->unk20C) {
        Heap_Free(D_00368A38, p->unk20C);
        p->unk20C = 0;
    }
    if (p->unk22C) {
        func_001DD118(p->unk22C, 3);
        p->unk22C = 0;
    }
    func_001D0F90(p, flags);
}

extern "C" void func_002004C0(S200* p, int s) {
    int v = 0;
    func_0027D870(s, 0xA1DC81F9, &v, 0);
    p->unk224 = v;
    p->unk220 = v;
    func_00203448(p, s);
}

extern "C" void func_00200520(S200* p, S200b* q) {
    switch (q->unkB0i & 0xF) {
    case 8:
        if (!func_00200910(p)) func_00289F90(q);
        break;
    case 10:
        if (!(p->unk1C & 0x100)) func_00289F90(q);
        break;
    case 12:
        if (!func_00200920(p)) func_00289F90(q);
        break;
    case 11:
        if (p->unk34 <= 0.0f) func_00289F90(q);
        break;
    }
}

extern "C" void func_002005E8(S200* p) {
    func_00204248(p);
    p->unk1D0 = 0;
    p->unk1D4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200618);

extern "C" int func_00200910(S200* self) {
    return (self->unk1C & 0x18) != 0;
}

extern "C" int func_00200920(S200* self) {
    return (self->unk1C & 0x27) != 0;
}

extern "C" int func_00200930(int key, int* out) {
    return func_0027D058(key, 0, out, 0);
}

extern "C" int func_00200958(int key, int* out) {
    return func_0027D058(key, 0, out, 0);
}

extern "C" void func_00200980(S200* self) {
    S200b* p = self->unkC;
    union {
        u128_200 q;
        f32 f[4];
    } v;
    v.q = p->unk80;
    v.f[1] -= self->unk210;
    p->unk80 = v.q;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002009B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00200A70);

extern "C" int func_00200AA0(S200* self) {
    return func_00200920(self) != 0;
}

extern "C" int func_00200AC0(S200* self) {
    self->unk1F0 = self->unkC->unk80;
    return 1;
}

extern "C" int func_00200AD8(S200* p) {
    p->unk200 = func_00201A38(p)->unk74;
    return 1;
}

extern "C" int func_00200B08(S200* self) {
    self->unk1C &= ~0x18;
    return 1;
}

extern "C" int func_00200B20(S200* self) {
    self->unk1C &= ~0x67;
    return 1;
}

extern "C" int func_00200B38(S200* self, int key) {
    func_00200930(key, &self->unk30);
    return 1;
}

extern "C" int func_00200B60(S200* self, int key) {
    func_00200930(key, &self->unk1E0);
    return 1;
}

extern "C" int func_00200B88(S200* self, int key) {
    func_00200958(key, &self->unk28);
    return 1;
}

extern "C" int func_00200BB0(S200* self, int key) {
    func_00200958(key, &self->unk2C);
    return 1;
}

extern "C" int func_00200BD8(S200* self) {
    func_00202258(self);
    return 1;
}

extern "C" int func_00200BF8(S200* self, int a, int b) {
    func_002024B0(self, a, b, 0);
    return 1;
}

extern "C" int func_00200C18(S200* self, int a, int b) {
    func_002024B0(self, a, b, 1);
    return 1;
}

extern "C" int func_00200C38(S200* self, int a, int b) {
    func_002024B0(self, a, b, 2);
    return 1;
}

extern "C" int func_00200C58(S200* p, int s) {
    if (func_0027DF00(s, 0xD443A2BC)) {
        p->unk20 |= 0x10;
    } else {
        p->unk20 &= ~0x10;
    }
    return 1;
}

extern "C" int func_00200CA8(S200* p, int s) {
    if (func_0027DF00(s, 0xD443A2BC)) {
        p->unk20 &= ~0x100;
    } else {
        p->unk20 |= 0x100;
        func_0027D058(s, 0, (int*)((char*)p->unkC + 0x84), 0);
    }
    return 1;
}

extern "C" int func_00200D28(S200* p, int s, S200* q) {
    float v = 2.5f;
    func_0027D268(s, 0x6C78A5B6, &v, 0);
    func_0027ACF8(q->unk20, 0xFFFF9A1C);
    S200* r = func_002042A0(p, v);
    if (r) func_0027C448(q->unk20, 0xFFFF9A1C, r->unk2C);
    return 1;
}

extern "C" int func_00200DB8(S200* p, int a, S200* q) {
    int r = func_00223460(p->unk224);
    if (r) {
        int h = q->unk20;
        func_0027C160(h, 0xC953660E, func_0010C050(r) + 1);
    }
    return 1;
}

extern "C" int func_00200E10(S200* p, int s) {
    if (func_0027DF00(s, 0xD443A2BC)) {
        p->unk20 &= ~0x200;
    } else {
        p->unk20 |= 0x200;
    }
    return 1;
}

extern "C" int func_00200E68(S200* p, int s) {
    f32 v;
    if (func_0027D058(s, 0, (int*)&v, 0)) {
        func_002019E8(p, (int)p->unkC);
        func_00201A38(p)->unkB0 = v;
    }
    return 1;
}

extern "C" int func_00200EC8(S200* self, int a) {
    self->unk20 &= ~8;
    func_00201C80(self, a);
    return 1;
}

extern "C" int func_00200EF8(S200* self) {
    return func_00204828(self) != 0;
}

extern "C" int func_00200F18(S200* self) {
    func_002028D8(self);
    return 1;
}

extern "C" int func_00200F38(S200* self) {
    func_00202828(self);
    return 1;
}

extern "C" int func_00200F58(S200* p, int a) {
    u128_200 v;
    func_002235F0(p->unk200, &v);
    func_00201DE8(p, a, &v);
    return 1;
}

extern "C" int func_00200FA8(S200* self, int a) {
    func_00202960(self, a, 1);
    return 1;
}

extern "C" int func_00200FC8(S200* self, int a) {
    func_00201DE8(self, a, &self->unk1F0);
    return 1;
}

extern "C" int func_00200FE8(S200* self, int a) {
    func_00202960(self, a, 0);
    return 1;
}

extern "C" int func_00201008(S200* p, int s) {
    p->unk38 = 0.0f;
    p->unk1D8 = 0;
    float d = p->unk38;
    if (*(f32*)&p->unk1E0 == d) *(f32*)&p->unk1E0 = 0.375f;
    func_0027D058(s, 0, (int*)&p->unk38, 0);
    p->unk1DC = p->unk34;
    if (p->unk38 == d) p->unk34 = d;
    p->unk20 |= 8;
    return 1;
}

extern "C" int func_002010A0(S200* self) {
    self->unk20 &= ~8;
    return 1;
}

extern "C" int func_002010B8(S200* self, int a, int b) {
    self->unk20 &= ~8;
    func_00202C88(self, a, b);
    return 1;
}

extern "C" int func_002010E8(S200* self) {
    func_00202D50(self);
    return 1;
}

extern "C" int func_00201108(S200* self, int a, int b) {
    func_00202ED0(self, a, b, self->unk1F0, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201130);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002011C0);

extern "C" int func_00201250(S200* self, int a, int b) {
    func_00203138(self, a, b, 1);
    return 1;
}

extern "C" int func_00201270(S200* self, int a, int b) {
    func_00203138(self, a, b, 0);
    return 1;
}

extern "C" int func_00201290(S200* self) {
    func_00203208(self);
    return 1;
}

extern "C" int func_002012B0(S200* p, int s) {
    func_0027D268(s, 0xA8A5A3C7, &p->unk3C, 0);
    func_0027D268(s, 0x182D87A7, &p->unk40, 0);
    if (func_0027DF00(s, 0xADA61834)) {
        p->unk88 = 1;
    } else {
        p->unk88 = 0;
    }
    if (func_0027DF00(s, 0xD443A2BC)) {
        p->unk20 &= ~4;
    } else {
        p->unk20 |= 4;
        if (p->unk3C == 0.0f && p->unk40 == 0.0f) return 0;
        func_00203C58(p, p->unk88, 3);
    }
    return 1;
}

extern "C" int func_002013A0(S200* self, int a, int b) {
    func_00289F48(b, 0xA, self, 0);
    return 1;
}

extern "C" int func_002013D0(S200* self, int a, int b) {
    func_00289F48(b, 0xC, self, 0);
    return 1;
}

extern "C" int func_00201400(S200* self, int a, int b) {
    func_00289F48(b, 0x8, self, 0);
    return 1;
}

extern "C" int func_00201430(S200* self, int a, int b) {
    func_00289F48(b, 0xB, self, 0);
    return 1;
}

extern "C" int func_00201460(S200* p, int s) {
    int v = 0;
    func_0027DC58(s, 0, &v, 0);
    int o = func_00224220(v, 1);
    u128_200 t;
    func_00223590(o, &t);
    p->unkC->unk80 = t;
    func_00203448(p, o);
    S200* x = func_001D1CF8(p->unkC, 0x286A8D26);
    ((void (*)(void*))x->unk18[2].fn)((char*)x + x->unk18[2].delta);
    return 1;
}

extern "C" int func_00201500(S200* p, int s) {
    if (func_0027DF00(s, 0xD443A2BC)) {
        func_00200980(p);
        p->unk1C &= ~0x80;
    } else {
        p->unk210 = 0.0f;
        func_0027D268(s, 0xC9FDE32C, &p->unk214, 0);
        float r = 1.0f;
        func_0027D268(s, 0xA80BEA4A, &r, 0);
        int n = (int)(1000.0f / r);
        p->unk218 = n;
        int x = func_0010C050(n * 2);
        p->unk218 += x - p->unk218 / 10;
        if (p->unk218 <= 0) p->unk218 = 1;
        p->unk1C |= 0x80;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_002015F8);

extern "C" int func_00201730(S200* p, int s) {
    F200(p, 0x234) = 3.75f;
    func_0027D268(s, 0xF0D90109, &F200(p, 0x234), 0);
    float k = 0.15f;
    F200(p, 0x270) = F200(p, 0x234);
    F200(p, 0x238) = -9.0f;
    func_0027D268(s, 0xA5E2DA58, &F200(p, 0x238), 0);
    Q200(p, 0x290) = p->unkC->unk80;
    F200(p, 0x274) = k;
    func_0027D268(s, 0xECC2C699, &F200(p, 0x274), 0);
    F200(p, 0x278) = k;
    func_0027D268(s, 0x5C4AE2F9, &F200(p, 0x278), 0);
    if (func_0027D2D8(s, 0xFD4BC03E, &Q200(p, 0x240), 0)) {
        I200(p, 0x250) = 1;
        F200(p, 0x234) *= F200(p, 0x244);
        F200(p, 0x244) = 0.0f;
    } else if (func_0027DF00(s, 0xFECFFE49)) {
        Q200(p, 0x240) = Q200(p->unkC, 0x120);
        I200(p, 0x250) = 1;
        F200(p, 0x234) *= F200(p, 0x244);
        F200(p, 0x244) = 0.0f;
    } else {
        I200(p, 0x250) = 0;
    }
    I200(p, 0x280) = 0;
    if (func_0027D268(s, 0xA1810C27, &F200(p, 0x284), 0)) I200(p, 0x280) = 1;
    p->unk1C |= 0x100;
    return 1;
}

extern "C" int func_002018C0(S200* self) {
    func_002044F8(self);
    return 1;
}

extern "C" s32 func_002018E0(S200_V* p, S200_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_00201980(S200* p, u32 key, int a, S200* q) {
    switch (key) {
    case 0x8819DD8B:
        func_00203058(p, a, q);
        return 1;
    case 0x51C6D459:
        func_0027C160(q->unk20, 0x54CF8532, p->unk84);
        return 1;
    }
    return 2;
}

extern "C" void func_002019E8(S200* p, int a) {
    if (!p->unk228) p->unk228 = func_001DD8D8(operator_new(0x110), a);
}

extern "C" S200b* func_00201A38(S200* self) {
    return self->unk228;
}

extern "C" int func_00201A40(S200* p) {
    if (!(p->unk1C & 0x10)) return 0;
    S200b* b = p->unk228;
    return b ? b->unk74 : 0;
}

extern "C" int func_00201A70(S200* p) {
    if (!(p->unk1C & 0x10)) return 0;
    S200b* b = p->unk228;
    return b ? b->unk70 : 0;
}

extern "C" void func_00201AA0(S200* p) {
    f32 z = 0.0f;
    u128_200 v = MakeVec(z, z, z, 1.0f);
    Q200(p, 0x160) = v;
    Q200(p, 0x170) = v;
    Q200(p, 0x180) = v;
    Q200(p, 0x190) = v;
    Q200(p, 0x1A0) = v;
    Q200(p, 0x1B0) = v;
    Q200(p, 0x1C0) = v;
    Q200(p, 0x130) = v;
    F200(p, 0x140) = z;
    F200(p, 0x144) = z;
    F200(p, 0x24) = z;
    F200(p, 0x148) = z;
    F200(p, 0x14C) = z;
    F200(p, 0x28) = z;
    F200(p, 0x2C) = z;
    F200(p, 0x30) = z;
    F200(p, 0x34) = z;
    F200(p, 0x38) = z;
    F200(p, 0x1D8) = z;
    F200(p, 0x1DC) = z;
    F200(p, 0x1E0) = z;
    F200(p, 0x204) = z;
    F200(p, 0x208) = z;
    *(u32*)((char*)p + 0x2A0) = 0xB9C81736;
    p->unk1C = 0;
    p->unk20 = 0;
    func_00204248(p);
}

extern "C" void func_00201B50(S201B50* p, int i) {
    f32* a = &p->m[1][i];
    f32* b = &p->m[0][i];
    f32* c = &p->m[2][i];
    f32* d = &p->m[3][i];
    *a = __builtin_fabsf(*a);
    *b = __builtin_fabsf(*b);
    *c = __builtin_fabsf(*c);
    *d = __builtin_fabsf(*d);
    if (p->a160[i] < 0.0f) {
        *a = -*a;
        *b = -*b;
        *c = -*c;
        *d = -*d;
    }
}

extern "C" void func_00201BF8(S200* p, int a) {
    if (p->unk120) func_001DD4D0(p->unk120, p->unkC);
    p->unk120 = func_001DD658(func_001DD5F8(), p->unkC, a);
    func_002019E8(p, (int)p->unkC);
    S200b* b = func_00201A38(p);
    u128_200 v = p->unkC->unk80;
    func_001DE0F8(b, a, &v);
}

extern "C" void func_00201C80(S200* p, int s) {
    int v = 0;
    if (func_0027D870(s, 0xA1DC81F9, &v, 0)) {
        func_00201BF8(p, v);
        p->unk1C = (p->unk1C | 0x10) & ~8;
    }
}

extern "C" int func_00201CE0(S200* self) {
    return (self->unk20 >> 9) & 1;
}

extern "C" void func_00201CF0(S200* p, int s) {
    int o = func_00224220(s, 0);
    p->unk224 = s;
    int a = 0;
    int ok = func_0027D870(o, 0x3AEFE377, &a, 0);
    int id = a;
    if (ok) {
        int b = 0;
        func_0027D400(o, 0x7031F10C, &b, 0);
        func_001D03D8(p->unkC, id, b, 0, 0);
    } else {
        int c = 0;
        ok = func_0027D870(o, 0x86125749, &c, 0);
        id = c;
        if (ok) {
            int d = 0;
            func_0027D400(o, 0x7031F10C, &d, 0);
            func_001D03B8(p->unkC, id, d);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00201DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2001E0", func_00202158);
