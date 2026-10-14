#include "common.h"

struct S001A9D98 {
    char pad[0x1C];
    int unk1C;
};

typedef unsigned int u128_1A9 __attribute__((mode(TI)));
struct S_1A9 { u128_1A9 unk0; char pad10[0xC]; int unk1C; void* unk20; char pad24[4]; void* unk28; char pad2C[8]; int unk34; };
struct Q50_1A9 { u128_1A9 v[5]; };

extern "C" {
int func_001ACD28(void*);
int func_001AD010(void*);
void func_0019D0B0(void*, int, int);
u128_1A9 func_001AF7C0(S_1A9*);
}

extern "C" void func_001A9A60(S_1A9* self, S_1A9* owner) {
    u32 f = self->unk1C;
    if (f & 2) {
        self->unk28 = 0;
        self->unk1C = f & ~2u;
    } else {
        self->unk28 = owner->unk20;
    }
    owner->unk20 = self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9A98);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9B08);

struct N_1A9 { char pad0[0x30]; int unk30; };

extern "C" {
int func_001ACD38(void*);
void func_001ACE28(void*, int);
N_1A9* func_001ACF70(N_1A9*);
N_1A9* func_001AD008(N_1A9*);
}

extern "C" int func_001A9B80(N_1A9* n, int key) {
    int r = 0;
    while (!func_001ACD28(n)) {
        if (n->unk30 == key) {
            func_001ACE28(n, 1);
            r = 1;
        }
        if (func_001AD008(n) && func_001ACD38(n)) {
            r |= func_001A9B80(func_001AD008(n), key) != 0;
        }
        n = func_001ACF70(n);
    }
    if (n) {
        do {
            if (n->unk30 == key) {
                func_001ACE28(n, 1);
                r = 1;
            }
            n = func_001AD008(n);
        } while (n);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9C68);

extern "C" Q50_1A9* func_001A9CF0(Q50_1A9* dst, Q50_1A9* src) {
    *dst = *src;
    return dst;
}

extern "C" void func_001A9D28(S_1A9* self, int x) {
    if (!(self->unk1C & 0x200)) {
        self->unk34 = x;
        self->unk0 = func_001AF7C0(self);
    }
}

extern "C" void func_001A9D68(S_1A9* self, int b) {
    if (b) {
        self->unk1C |= 0x4000000;
    } else {
        self->unk1C &= ~0x4000000;
    }
}

extern "C" int func_001A9D98(S001A9D98* self) {
    return ((self->unk1C >> 26) & 1);
}

struct N1A9DA8 { char pad0[0x20]; void* unk20; char pad24[4]; N1A9DA8* unk28; };

extern "C" void func_001A9DA8(N1A9DA8* self, int a, int b, int c, int d) {
    N1A9DA8* p = (N1A9DA8*)self->unk20;
    if (p) {
        do {
            if (func_001ACD28(p)) {
                if (func_001AD010(p) == a) {
                    func_0019D0B0(p->unk20, 6, b);
                    func_0019D0B0(p->unk20, 0x34, c);
                    func_0019D0B0(p->unk20, 0x36, d);
                }
            } else {
                func_001A9DA8(p, a, b, c, d);
            }
            p = p->unk28;
        } while (p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9E78);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9F70);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AA448);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AAB00);
