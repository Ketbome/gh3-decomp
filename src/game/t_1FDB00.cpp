#include "common.h"

struct VEntry1FD {
    s16 delta;
    s16 unk2;
    void (*fn)(void*);
};

struct S1FD {
    char pad0[0x18];
    VEntry1FD* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    char pad28[0x4];
    int unk2C;
    char unk30[0x10];
    char unk40[0x10];
    char pad50[0x2C];
    u32 unk7C;
    u32 unk80;
    char pad84[0xC];
    char unk90[4];
};

typedef int TI128 __attribute__((mode(TI)));

struct S1FD_V {
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

struct S1FD_A {
    s32 unk0;
    s32 unk4;
    s32 (S1FD_V::*unk8)(int, int);
};

extern "C" {
void* operator_new(u32 size);
void* func_001FDDC0(void*);
void func_00276D68(u32, void*, int);
extern u8 D_0038F8E8[];
S1FD* func_001FEE90(S1FD*);
void func_0027C448(void*, u32, int);
void func_001CE888(void*, void*);
void func_001CE868(void*, void*);
void func_001D0F90(void*, int);
extern u8 D_0034FC68[];
extern void* D_0036D3B0;
S1FD* func_001D8618(void*, void*);
extern u32 D_00370F40;
u32 func_00275570(void);
void func_0010F970(void*, void*, float);
bool func_0027D2D8(int, u32, void*, int);
}

static inline void Release1FD(void** pp) {
    if (*pp) {
        func_001CE888(*pp, pp);
        *pp = 0;
    }
}

static inline void Set1FD(void** pp, void* v) {
    Release1FD(pp);
    *pp = v;
    if (v) func_001CE868(v, pp);
}

extern "C" void func_001FDB00(S1FD* self) {
    self->unk7C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDB08);

typedef unsigned int TI1FD __attribute__((mode(TI)));

static inline f32 Get1FDX(TI1FD q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}

static inline f32 Get1FDY(TI1FD q) {
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(f) : "r"(q));
    return f;
}

static inline f32 Get1FDZ(TI1FD q) {
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(f) : "r"(q));
    return f;
}

struct M1FD {
    TI1FD r0, r1, r2, r3;
};

struct S1FDb {
    char pad0[0x210];
    TI1FD* unk210;
};

struct S1FDa {
    char pad0[0x70];
    int unk70;
    struct { char pad0[0x1C]; int unk1C; }* unk74;
    S1FDb* unk78;
};

extern "C" int func_00133A98(int, int, void*);

extern "C" void func_001FDC60(S1FDa* p0, M1FD* m0) {
    M1FD* m = m0;
    S1FDa* p = p0;
    if (func_00133A98(p->unk74->unk1C, p->unk70, m) == 0) {
        m->r0 = 0x3F800000;
        m->r1 = (u64)0xFE00 << 46;
        m->r2 = (TI1FD)0x3F800000 << 64;
        m->r3 = (TI1FD)((u64)0xFE00 << 46) << 64;
        p->unk70 = 0;
    }
    S1FDb* o = p->unk78;
    if (o) {
        TI1FD q = o->unk210[2];
        if (Get1FDX(q) != 1.0f || Get1FDY(q) != 1.0f || Get1FDZ(q) != 1.0f) {
            register TI1FD v asm("vf1") = m->r3;
            register TI1FD w asm("vf2") = q;
            asm("vmul.xyzw %0, %0, %1" : "+j"(v) : "j"(w));
            m->r3 = v;
        }
    }
}

extern "C" void* func_001FDD68(void) {
    return func_001FDDC0(operator_new(0xF0));
}

extern "C" void func_001FDD90(void) {
    func_00276D68(0x5CB5CB7E, D_0038F8E8, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDDC0);

extern "C" void func_001FDE48(S1FD* p, int flags) {
    p->unk18 = (VEntry1FD*)D_0034FC68;
    Release1FD(&p->unk24);
    func_001D0F90(p, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEB08);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEB48);

extern "C" void func_001FEC40(void) {
}

extern "C" void func_001FEC48(S1FD* p) {
    S1FD* r = func_001FEE90(p);
    Set1FD(&p->unk24, r ? (char*)r + 0x5C : 0);
}

extern "C" int func_001FECB8(S1FD* p) {
    p->unk18[3].fn((char*)p + p->unk18[3].delta);
    p->unk18[4].fn((char*)p + p->unk18[4].delta);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FED08);

extern "C" int func_001FED90(S1FD* p, void* a, S1FD* q) {
    S1FD* r = func_001FEE90(p);
    if (r) func_0027C448(q->unk20, 0xC2719FB0, r->unk2C);
    return r != 0;
}

extern "C" int func_001FEDE0(void) {
    return 2;
}

extern "C" s32 func_001FEDE8(S1FD_V* p, S1FD_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001FEE88(void) {
}

extern "C" S1FD* func_001FEE90(S1FD* p) {
    S1FD* r = func_001D8618(D_0036D3B0, p->unk20);
    if (!r && p->unk1C) r = func_001D8618(D_0036D3B0, p->unk1C);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEEE0);
