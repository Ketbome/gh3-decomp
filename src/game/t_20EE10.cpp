// cflags: -funroll-loops
#include "common.h"

struct E2105 {
    char pad0[4];
    s32 unk4;
};

struct N2105 {
    N2105* unk0;
    N2105* unk4;
    E2105* unk8;
};

struct I2105 {
    s32 unk0;
    N2105* unk4;
};

typedef unsigned int u128_20E __attribute__((mode(TI)));

struct S20Eb {
    char pad0[0x8];
    int unk8;
    int unkC;
};

struct S20E {
    u128_20E* unk0;
    int unk4;
    char pad8[0x8];
    f32* unk10;
    char pad14[0x10];
    int unk24;
    char pad28[0x70];
    int unk98;
};

struct S210 {
    char pad0[0x20];
    int unk20;
    int unk24;
    char pad28[0x268];
    S20Eb unk290;
    char pad2A0[0x18];
    int unk2B8;
    char unk2BC[0x4];
    char pad2C0[0xE8];
    char unk3A8[0x2C8];
    int unk670;
};

extern "C" {
void func_0020CE80(void*);
void func_0020C0D8(void*);
void func_0020AEC8(void*);
void func_0020F1B8(void*);
int func_00210558(void*);
f32 func_002EC100(f32);
void func_0020CD08(void*);
void func_001E2B90(void*, int);
int func_001E2968(void*, int);
void func_0020EE10(void*);
void func_0020EA48(void*);
void func_0020BF60(void*, void*, int);
void func_00212778(void*, void*);
void func_0020C2B8(void*, void*);
void func_0020B9D0(void*, int);
void func_001E29F0(void*, int);
void func_001D1418(void*);
void func_0027AA98(void*);
void func_0027C160(void*, u32, int);
void func_0027AC90(void*);
int func_0027D870(int, u32, int*, int);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(s32 h, void* p);
}

struct N20E {
    N20E* unk0;
    N20E* unk4;
    f32 unk8;
};

struct P20E {
    int unk0;
    int unk4;
    N20E* unk8;
};

static inline N20E* First20E(P20E* s) {
    return s->unk4 == 1 ? s->unk8 : s->unk8->unk0;
}

static inline N20E* Second20E(P20E* s) {
    return s->unk4 == 1 ? s->unk8 : s->unk8->unk4;
}

struct VE20E {
    s16 delta;
    s16 unk2;
    void (*fn)(void*);
};

struct E20E {
    int unk0;
    char pad4[0x40];
    VE20E* unk44;
    char pad48[0x8];
};

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EE10);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EEF0);

extern "C" f32 func_002EC100(f32);

extern "C" f32 func_0020EF70(f32 a, f32 b) {
    return func_002EC100(b * a) / b;
}

extern "C" void func_0020EFA8(f32* d, P20E* s) {
    d[0] = ((f32*)First20E(s))[1];
    d[1] = ((f32*)First20E(s))[2];
    d[2] = ((f32*)Second20E(s))[1];
    d[3] = ((f32*)Second20E(s))[2];
}

extern "C" f32 func_0020F040(f32* p, f32 x) {
    f32 c = p[3], b = p[2], d = p[1], a = p[0];
    if (c == b) return a;
    f32 t = (x - b) / (c - b);
    if (t < 0.0f) t = 0.0f;
    f32 u;
    if (1.0f < t) u = 1.0f;
    else u = t;
    return a + (d - a) * u;
}

extern "C" f32 func_0020F0C0(f32* p, f32 x) {
    f32 sign = -1.0f;
    if (0.0f <= x) sign = 1.0f;
    x = __builtin_fabsf(x);
    f32 hi = p[3];
    f32 lo = p[2];
    f32 b = p[1];
    f32 a = p[0];
    f32 r;
    if (hi == lo) {
        r = a;
    } else {
        f32 t = (x - lo) / (hi - lo);
        if (t < 0.0f) t = 0.0f;
        f32 c = 1.0f < t ? 1.0f : t;
        r = a + (b - a) * c;
    }
    return sign * r;
}

extern "C" void* func_0020F158(char* p) {
    func_0020EA48(p + 0x8);
    func_0020EA48(p + 0x28);
    func_0020EA48(p + 0x48);
    func_0020EA48(p + 0x68);
    func_0020EA48(p + 0x9C);
    *(int*)(p + 0x48) = 0;
    *(int*)(p + 0x68) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x98) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F1B8);

extern "C" void func_0020F3F0(S20E* self, int a, int b) {
    self->unk4 = a;
    self->unk98 = b;
}

extern "C" void func_0020F400(char* p, f32 f) {
    *(f32*)p = f;
    func_0020EE10(p + 0x8);
    func_0020EE10(p + 0x28);
    func_0020EE10(p + 0x48);
    func_0020EE10(p + 0x68);
    func_0020EE10(p + 0x9C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F450);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F6A8);

extern "C" int func_002102F8(char* p, int s) {
    char* q = p + 0x160;
    func_0020C0D8(p);
    char* r = p + 0x290;
    func_0020C2B8(p + 0x30, q);
    func_0020B9D0(q, s);
    *(int*)(r + 4) = 1;
    func_001E29F0(r, s);
    if (!*(int*)(r + 0xC)) func_001D1418(*(void**)(p + 0xC));
    return 1;
}

extern "C" int func_00210388(S210* self, int a, int b) {
    if (self->unk2B8) {
        func_001E2B90(self->unk2BC, b);
    } else {
        func_001E2B90(&self->unk290, b);
    }
    return 1;
}

extern "C" int func_002103C8(S210* p) {
    S20Eb* q = &p->unk290;
    q->unk8 = func_001E2968(q, 0) - q->unkC;
    return 1;
}

extern "C" int func_00210408(S210* self) {
    func_0020CE80(&self->unk2B8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210428);

extern "C" int func_002104E0(S210* self) {
    self->unk24 = 1;
    func_00210558(self);
    return 1;
}

extern "C" int func_00210508(S20E* self) {
    self->unk24 = 0;
    return 1;
}

extern "C" int func_00210518(S210* self) {
    if (self->unk20) {
        return 0;
    }
    self->unk20 = 1;
    return 1;
}

extern "C" int func_00210538(S210* self) {
    if (!self->unk20) {
        return 0;
    }
    self->unk20 = 0;
    return 1;
}

extern "C" int func_00210558(void* self) {
    char* p = (char*)self;
    char* q = p + 0x160;
    func_0020BF60(p, q, 0);
    func_00212778(p + 0x30, q);
    func_0020C0D8(p);
    return 1;
}

extern "C" s32 func_002105A8(char* o) {
    I2105 it;
    I2105 end;
    char* s = o + 0x290;
    *(s32*)(s + 8) = func_001E2968(s, 0);
    *(s32*)(s + 0x10) = 0;
    char* b = o + 0x2A8;
    *(s32*)(s + 0x14) = 0;
    N2105* h = (N2105*)(o + 0x2B0);
    end.unk4 = h;
    it.unk4 = *(N2105**)(o + 0x2B4);
    if (it.unk4 != end.unk4) {
        N2105* h2 = h;
        asm("" : "+r"(h2));
        do {
            it.unk4->unk8->unk4 = 0;
            it.unk4 = it.unk4->unk4;
            end.unk4 = h2;
        } while (it.unk4 != end.unk4);
    }
    char* l = b + 4;
    char* e = b + 8;
    char* c = *(char**)(l + 8);
    *(char**)(l + 8) = e;
    *(char**)(l + 4) = e;
    if (c != e) {
        char* ee = e;
        asm("" : "+r"(ee));
        char* x = c;
        do {
            c = *(char**)(c + 4);
            Heap_Free(D_00368A38[0], x);
            x = c;
        } while (c != ee);
    }
    *(s32*)(o + 0x384) = 1;
    return 1;
}

extern "C" int func_00210678(char* p, int a, int x) {
    char tmp[0x10];
    func_0027AA98(tmp);
    func_0027C160(tmp, 0x7AF07905, 2);
    for (int i = 0; i < 3; i++) {
        E20E* e = &((E20E*)(p + 0x490))[i];
        if (!e->unk0) {
            ((void (*)(void*, void*, int))e->unk44[2].fn)((char*)e + e->unk44[2].delta, tmp, x);
            func_0027AC90(tmp);
            return 1;
        }
    }
    func_0027AC90(tmp);
    return 0;
}

extern "C" s32 func_00210720(char* o, s32 pad, s32 a) {
    u8 tmp[0x10];
    func_0027AA98(tmp);
    func_0027C160(tmp, 0x7AF07905, 0);
    register E20E* e asm("$7") = (E20E*)(o + 0x490);
    if (e->unk0 == 0 || (e = (E20E*)(o + 0x4E0), e->unk0 == 0) || (e = (E20E*)(o + 0x530), e->unk0 == 0)) {
        ((void (*)(void*, void*, int, void*))e->unk44[2].fn)((char*)e + e->unk44[2].delta, tmp, a, e);
        func_0027AC90(tmp);
        return 1;
    }
    func_0027AC90(tmp);
    return 0;
}

extern "C" s32 func_002107C8(char* o, s32 pad, s32 a) {
    u8 tmp[0x10];
    func_0027AA98(tmp);
    func_0027C160(tmp, 0x7AF07905, 1);
    register E20E* e asm("$7") = (E20E*)(o + 0x490);
    if (e->unk0 == 0 || (e = (E20E*)(o + 0x4E0), e->unk0 == 0) || (e = (E20E*)(o + 0x530), e->unk0 == 0)) {
        ((void (*)(void*, void*, int, void*))e->unk44[2].fn)((char*)e + e->unk44[2].delta, tmp, a, e);
        func_0027AC90(tmp);
        return 1;
    }
    func_0027AC90(tmp);
    return 0;
}

extern "C" int func_00210870(char* p, int x, int y) {
    for (int i = 0; i < 3; i++) {
        E20E* e = &((E20E*)(p + 0x580))[i];
        if (!e->unk0) {
            ((void (*)(void*, int, int))e->unk44[2].fn)((char*)e + e->unk44[2].delta, x, y);
            return 1;
        }
    }
    return 0;
}

extern "C" int func_002108D0(S210* self) {
    int* p = &self->unk670;
    if (*p == 0) {
        func_0020CD08(p);
        return 1;
    }
    return 0;
}

extern "C" int func_00210908(S210* self) {
    func_0020C0D8(self);
    return 1;
}

extern "C" int func_00210928(S210* self) {
    func_0020AEC8(self);
    return 1;
}

extern "C" int func_00210948(S210* self) {
    func_0020F1B8(self->unk3A8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210968);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210A18);

typedef unsigned int u128_20E __attribute__((mode(TI)));

struct V16_20E { u128_20E q; V16_20E() {} };
struct FA16_20E { V16_20E* unk0; u32 unk4; u32 unk8; };
struct FA4_20E { float* unk0; u32 unk4; u32 unk8; };

extern "C" {
void* Heap_Alloc_20E(int, int, int, int) __asm__("Heap_Alloc");
}

static inline void Set16_20E(FA16_20E* a, u32 n) {
    if (n == 0) {
        if (a->unk0 != 0) {
            a->unk4 = 0;
            if (a->unk0 != 0) Heap_Free(D_00368A38[0], a->unk0);
            a->unk0 = 0;
        }
    } else {
        V16_20E* t = (V16_20E*)Heap_Alloc_20E(D_00368A38[0], n * 16, 1, 0);
        for (int i = n - 1; i != -1; i--) {
        }
        for (u32 i = 0; i < n && i < a->unk4; i++) {
            t[i] = a->unk0[i];
        }
        if (a->unk0 != 0) Heap_Free(D_00368A38[0], a->unk0);
        a->unk0 = t;
        a->unk4 = n;
        a->unk8 = n;
    }
}

static inline void Set4_20E(FA4_20E* a, u32 n) {
    if (n == 0) {
        if (a->unk0 != 0) {
            a->unk4 = 0;
            if (a->unk0 != 0) Heap_Free(D_00368A38[0], a->unk0);
            a->unk0 = 0;
        }
    } else {
        float* t = (float*)Heap_Alloc_20E(D_00368A38[0], n * 4, 1, 0);
        for (u32 i = 0; i < n && i < a->unk4; i++) {
            t[i] = a->unk0[i];
        }
        if (a->unk0 != 0) Heap_Free(D_00368A38[0], a->unk0);
        a->unk0 = t;
        a->unk4 = n;
        a->unk8 = n;
    }
}

extern "C" void func_00210A88(FA16_20E* self, u32 n) {
    Set16_20E(self, n);
    Set4_20E((FA4_20E*)((char*)self + 0x10), n);
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210C90);

extern "C" void func_00210CA0(S20E* self, int i, f32* v) {
    f32* p = self->unk10;
    p += i;
    *p = *v;
}

extern "C" void func_00210CB8(S20E* self, int i, u128_20E* v) {
    u128_20E* p = self->unk0;
    p += i;
    *p = *v;
}

extern "C" int func_00210CD0(S20E* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210CD8);
