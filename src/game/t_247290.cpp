#include "common.h"

struct N2485 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    N2485* unkC;
    N2485* unk10;
    void* unk14;
};

struct A2485 {
    char pad0[0x18];
    s32 unk18;
    s32* unk1C;
};

extern "C" {
void func_0010F690(void*);
void func_00248E20(void*);
extern u8 D_0033C4F8[];
void* operator_new(u32 size);
}

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247290);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247650);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00247DC8);

extern "C" s32 func_00248588(s32 self, s32 v, A2485* a, N2485* list, s32 i) {
    if (i < 0) {
        a->unk1C[a->unk18 + i] = v;
    } else {
        N2485* n = (N2485*)operator_new(0x18);
        n->unkC = n;
        n->unk10 = n;
        n->unk4 = v;
        n->unk14 = D_0033C4F8;
        n->unk8 = 0;
        N2485* t = list->unk10;
        n->unkC = list;
        n->unk10 = t;
        list->unk10->unkC = n;
        list->unk10 = n;
    }
    return i + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248620);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002486A0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002486B0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248CF0);

extern "C" void func_00248CF8(f32* p) {
    p[2] = 1e7f;
    p[1] = 1e7f;
    p[5] = -1e7f;
    p[0] = 1e7f;
    p[4] = -1e7f;
    p[3] = -1e7f;
}
TEXT_PAD(20);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D40);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D50);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248D98);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248E20);

extern "C" void func_00248E60(char* p) {
    struct O { char pad[0x20]; void (*f)(O*); };
    O* o = *(O**)(p + 0x4C);
    o->f(o);
}

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00248E88);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_002490E0);

INCLUDE_ASM("asm/nonmatchings/game/t_247290", func_00249120);
