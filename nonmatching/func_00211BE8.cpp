// cflags: -funroll-loops
#include "common.h"

typedef unsigned int u128_211 __attribute__((mode(TI)));

struct S211 {
    char pad0[0x24];
    u128_211* unk24;
    int unk28;
    char pad2C[0xC];
    f32* unk38;
    int unk3C;
};

extern "C" {
extern void* D_00368A38;
extern u8 D_00350AE0[];
extern u8 D_00350A50[];
void func_0013D1B8(void*, int);
void Heap_Free(void*, void*);
extern u8 D_00350A20[];
extern u8 D_003378C8[];
extern u8 D_00350A38[];
extern u8 D_003378B0[];
void func_002131A8(void*, int);
}

static inline void Free2_211(char* q, void* vt) {
    *(void**)(q + 0xC) = vt;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void Free1_211(char* q, void* vt) {
    *(void**)(q + 0xC) = vt;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorB211(char* q) {
    *(void**)(q + 0xC) = D_003378C8;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorC211(char* q) {
    *(void**)(q + 0xC) = D_00350A38;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorA211(char* q) {
    *(void**)(q + 0xC) = D_00350A38;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void Release211(char* q) {
    if (*(void**)(q + 4)) {
        Heap_Free(D_00368A38, *(void**)(q + 4));
        *(int*)(q + 4) = 0;
        *(int*)(q + 8) = 0;
        *(int*)(q + 0xC) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211050);

struct V211 {
    f32* data;
    u32 size;
    u32 cap;
};

static inline f32& At211(f32* const& d, u32 idx) {
    return d[idx];
}

struct P211 {
    char pad0[0x10];
    f32* unk10;
    char pad14[0x20];
    int unk34;
    V211 vec;
};

extern "C" {
u32 func_00210CD0(void*);
void* Heap_Alloc_211(void*, int, int, int) __asm__("Heap_Alloc");
}

extern "C" void func_00211BE8(P211* p) {
    V211* v = &p->vec;
    u32 n = func_00210CD0(p);
    u32 t = n + 6;
    int i2, i4, i3, i5;
    if (t == 0) {
        i2 = t - 4;
        i4 = t - 2;
        i3 = t - 3;
        i5 = t - 1;
        if (v->data != 0) {
            v->size = 0;
            if (v->data) {
                Heap_Free(D_00368A38, v->data);
            }
            v->data = 0;
        }
    } else {
        f32* nd = (f32*)Heap_Alloc_211(D_00368A38, t * 4, 1, 0);
        i5 = t - 1;
        u32 i = 0;
        i2 = t - 4;
        i3 = t - 3;
        i4 = t - 2;
        if (t != 0) {
            f32* d = nd;
            if (v->size != 0) {
                do {
                    *d = v->data[i];
                    i++;
                    d++;
                } while (i < t && i < v->size);
            }
        }
        if (v->data) {
            Heap_Free(D_00368A38, v->data);
        }
        v->cap = t;
        v->data = nd;
        v->size = t;
    }
    u32 j = 3;
    for (u32 i = 0; i < func_00210CD0(p); i++, j++) {
        p->vec.data[j] = p->unk10[i];
    }
    p->vec.data[0] = p->vec.data[3];
    p->vec.data[1] = p->vec.data[3];
    p->vec.data[2] = p->vec.data[3];
    p->vec.data[i3] = p->vec.data[i2];
    p->vec.data[i4] = p->vec.data[i2];
    p->vec.data[i5] = p->vec.data[i2];
    p->unk34 = 1;
}

extern "C" int func_00211DE8(S211* self) {
    return self->unk28;
}

extern "C" u128_211 func_00211DF0(S211* self, int i) {
    u128_211* p = self->unk24;
    p += i;
    return *p;
}

extern "C" int func_00211E08(S211* self) {
    return self->unk3C;
}

extern "C" f32 func_00211E10(S211* self, int i) {
    f32* p = self->unk38;
    p += i;
    return *p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211E28);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_002120B8);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212610);

extern "C" void func_00212628(char* p, int flags) {
    Release211(p + 0x74);
    Release211(p + 0x54);
    Release211(p + 0x34);
    Release211(p + 0x14);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_00212700(char* p, int flags) {
    char* q = p + 0x14;
    if (*(void**)(q + 4)) {
        Heap_Free(D_00368A38, *(void**)(q + 4));
        *(int*)(q + 4) = 0;
        *(int*)(q + 8) = 0;
        *(int*)(q + 0xC) = 0;
    }
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" S211* func_00212770(S211* self) {
    return self;
}

struct M212 {
    u128_211 r[4];
    M212& operator=(const M212& o) {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct S212 {
    s32 unk0;
    s32 unk4;
    char pad8[8];
    u128_211 unk10;
    s32 unk20;
    char pad24[0xC];
    M212 unk30;
    char pad70[0];
    s32 unk70;
    char pad74[0xC];
    M212 unk80;
    s32 unkC0;
    f32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    char padE4[0xC];
    u128_211 unkF0;
    s32 unk100;
    s32 unk104;
    char pad108[8];
    u128_211 unk110;
    f32 unk120;
    f32 unk124;
    struct { u64 v; } __attribute__((packed)) unk128;
};

extern "C" S212* func_00212778(S212* a, S212* b) {
    a->unk0 = b->unk0;
    a->unk4 = b->unk4;
    a->unk10 = b->unk10;
    a->unk20 = b->unk20;
    a->unk30 = b->unk30;
    a->unk70 = b->unk70;
    a->unk80 = b->unk80;
    a->unkC0 = b->unkC0;
    a->unkC4 = b->unkC4;
    a->unkC8 = b->unkC8;
    a->unkCC = b->unkCC;
    a->unkD0 = b->unkD0;
    a->unkD4 = b->unkD4;
    a->unkD8 = b->unkD8;
    a->unkDC = b->unkDC;
    a->unkE0 = b->unkE0;
    a->unkF0 = b->unkF0;
    a->unk100 = b->unk100;
    a->unk104 = b->unk104;
    a->unk110 = b->unk110;
    a->unk120 = b->unk120;
    a->unk124 = b->unk124;
    a->unk128 = b->unk128;
    return a;
}

extern "C" void func_00212880(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_002128D8(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_00212930(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_00212988(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_002129E0(char* p, int flags) {
    func_002131A8(p + 0x84, 2);
    char* x = p + 0x60;
    *(void**)(x + 0x20) = D_00350A20;
    Free2_211(x + 0x10, D_003378C8);
    Free1_211(x, D_00350A38);
    char* y = p + 0x3C;
    *(void**)(y + 0x20) = D_003378B0;
    Free2_211(y + 0x10, D_003378C8);
    Free1_211(y, D_003378C8);
    Free2_211(p + 0x2C, D_00350A50);
    func_0013D1B8(p + 4, 2);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_00212B58(char* p, int flags) {
    *(void**)(p + 0xC) = D_00350A50;
    if (*(void**)p) {
        *(int*)(p + 4) = 0;
        Heap_Free(D_00368A38, *(void**)p);
        *(void**)p = 0;
    }
    if (flags & 1) Heap_Free(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212BC0);

extern "C" void func_00212C30(char* p, int flags) {
    *(void**)(p + 0x20) = D_00350A20;
    char* q = p + 0x10;
    *(void**)(q + 0xC) = D_003378C8;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) Heap_Free(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
    *(void**)(p + 0xC) = D_00350A38;
    if (*(void**)p) {
        *(int*)(p + 4) = 0;
        Heap_Free(D_00368A38, *(void**)p);
        *(void**)p = 0;
    }
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_00212CD8(char* p, int flags) {
    DtorB211(p + 0x38);
    DtorC211(p + 0x24);
    DtorB211(p + 0x10);
    DtorA211(p);
    if (flags & 1) Heap_Free(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212DF0);
