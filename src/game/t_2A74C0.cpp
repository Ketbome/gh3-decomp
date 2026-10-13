#include "common.h"

struct S2A74C0_A {
    char pad0[0x4];
    int *unk4;
};

extern "C" {
int func_0027D400(int, int, int *, int);
extern int D_00371EEC;
extern int D_00372F18;
extern int D_00372F20;
int func_002A7D58(void *, int);
extern int D_00372F28;
extern char D_003AB260[];
extern char D_003AB4B0[];
int func_002A7A40(int);
extern s32 D_00371EF4;
extern s32 D_00372F30[] __attribute__((section(".sdata")));
extern s32 D_00372F38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A74C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7540);

struct S2A75F0 {
    char pad0[4];
    int *unk4;
};
extern "C" void func_002A75F0(S2A75F0 *p, int i, int v) {
    p->unk4[i] = func_002A7A40(v);
}

extern "C" int func_002A7638(S2A74C0_A *p, int i) {
    return p->unk4[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7650);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A77E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A79A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7A40);

GP_DATA(D_00371EF4);
extern "C" void func_002A7D40(void) {
    D_00371EF4 = 0;
    D_00372F30[0] = 0;
    D_00372F38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7D58);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7EA8);

GP_DATA(D_00371EEC);
extern "C" int func_002A7EF0(void) {
    int a = 0;
    int b;
    if (func_0027D400(D_00371EEC, D_00372F20, &a, 0)) {
        b = 0;
        if (func_0027D400(a, D_00372F18, &b, 0) || func_0027D400(a, 0x1CA1FF20, &b, 0)) {
            return b;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7F78);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", CFunc_LightShow_Init);
