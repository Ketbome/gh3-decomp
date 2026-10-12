#include "common.h"

typedef unsigned int u128_131 __attribute__((mode(TI)));

struct S131_E {
    char pad0[0x8];
    u32 unk8;
    char padC[0x4];
    u128_131 unk10;
};

extern "C" {
int func_001317D0(void*, int);
S131_E* func_00134378(void*);
int func_00132000(void*, int, int);
int func_00132438(void*, int, u128_131*);
int func_001324D0(void*, int, u128_131*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_001319D0);

extern "C" int func_00131FC0(void* self, int a, int b) {
    return func_00132000(self, func_001317D0(self, a), b);
}

extern "C" int func_00132000(void* self, int i, int flag) {
    S131_E* e = func_00134378(self) + i;
    if (e) {
        u32 v;
        e->unk8 &= ~0x40000000;
        v = e->unk8;
        if (!flag) {
            v |= 0x40000000;
        }
        e->unk8 = v;
    }
    return e != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_00132070);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_00132390);

extern "C" int func_001323F8(void* self, int a, u128_131* b) {
    return func_00132438(self, func_001317D0(self, a), b);
}

extern "C" int func_00132438(void* self, int i, u128_131* out) {
    S131_E* e = func_00134378(self) + i;
    if (e) {
        *out = e->unk10;
    }
    return e != 0;
}

extern "C" int func_00132480(void* self, int a, u128_131* b, int c) {
    return func_001324D0(self, func_001317D0(self, a), b, c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_001324D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_001325B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_00132F50);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_00132F58);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_00133178);

INCLUDE_ASM("asm/nonmatchings/game/t_1319D0", func_001334F8);
