#include "common.h"

struct SA10C {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

extern "C" {
extern int D_00372A80;
extern int D_00372A84;
extern int D_00372A88;
extern int D_00372A8C;
extern int D_00372A90;
extern int D_00372A94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C000);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C050);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C0B8);

extern "C" void func_0010C120(int* a, int* b, int* c, int* d, int* e, int* g) {
    if (a) *a = D_00372A80;
    if (b) *b = D_00372A84;
    if (c) *c = D_00372A88;
    if (d) *d = D_00372A8C;
    if (e) *e = D_00372A90;
    if (g) *g = D_00372A94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C170);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C1A0);

extern "C" float func_0010C2E0(float a, float b, float c) {
    c = __builtin_fabsf(c);
    if (a < b) {
        if (b - a > c) {
            return b - c;
        }
        return a;
    } else {
        if (a - b > c) {
            return b + c;
        }
        return a;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C330);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C428);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CA50);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CB90);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CC30);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CD50);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CEE8);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D1E8);

extern "C" SA10C* func_0010D420(SA10C* self, int a, int b, int c, int d) {
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = c;
    self->unkC = d;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D438);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D508);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D538);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D548);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D768);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D808);
