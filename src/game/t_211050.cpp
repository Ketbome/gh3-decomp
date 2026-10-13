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
void func_00119400(void*, void*);
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
        if (*(void**)q) func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void Free1_211(char* q, void* vt) {
    *(void**)(q + 0xC) = vt;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorB211(char* q) {
    *(void**)(q + 0xC) = D_003378C8;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorC211(char* q) {
    *(void**)(q + 0xC) = D_00350A38;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void DtorA211(char* q) {
    *(void**)(q + 0xC) = D_00350A38;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
}

static inline void Release211(char* q) {
    if (*(void**)(q + 4)) {
        func_00119400(D_00368A38, *(void**)(q + 4));
        *(int*)(q + 4) = 0;
        *(int*)(q + 8) = 0;
        *(int*)(q + 0xC) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211050);

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00211BE8);

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
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_00212700(char* p, int flags) {
    char* q = p + 0x14;
    if (*(void**)(q + 4)) {
        func_00119400(D_00368A38, *(void**)(q + 4));
        *(int*)(q + 4) = 0;
        *(int*)(q + 8) = 0;
        *(int*)(q + 0xC) = 0;
    }
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" S211* func_00212770(S211* self) {
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212778);

extern "C" void func_00212880(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_002128D8(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_00212930(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_00212988(char* p, int flags) {
    *(void**)(p + 0x44) = D_00350AE0;
    func_0013D1B8(p + 4, 2);
    if (flags & 1) func_00119400(D_00368A38, p);
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
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_00212B58(char* p, int flags) {
    *(void**)(p + 0xC) = D_00350A50;
    if (*(void**)p) {
        *(int*)(p + 4) = 0;
        func_00119400(D_00368A38, *(void**)p);
        *(void**)p = 0;
    }
    if (flags & 1) func_00119400(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212BC0);

extern "C" void func_00212C30(char* p, int flags) {
    *(void**)(p + 0x20) = D_00350A20;
    char* q = p + 0x10;
    *(void**)(q + 0xC) = D_003378C8;
    if (*(void**)q) {
        *(int*)(q + 4) = 0;
        if (*(void**)q) func_00119400(D_00368A38, *(void**)q);
        *(void**)q = 0;
    }
    *(void**)(p + 0xC) = D_00350A38;
    if (*(void**)p) {
        *(int*)(p + 4) = 0;
        func_00119400(D_00368A38, *(void**)p);
        *(void**)p = 0;
    }
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_00212CD8(char* p, int flags) {
    DtorB211(p + 0x38);
    DtorC211(p + 0x24);
    DtorB211(p + 0x10);
    DtorA211(p);
    if (flags & 1) func_00119400(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_211050", func_00212DF0);
