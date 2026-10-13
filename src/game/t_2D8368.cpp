#include "common.h"

extern "C" {
int func_0028D558(int);
int func_0028D1B0(int, int, int, int, int, int, int, int, int, int);
}

struct S2D8368_0 {
    char pad0[0x44];
    f32 unk44;
};

extern "C" f32 func_002D8368(S2D8368_0 *arg0) {
    return arg0->unk44;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002D8370);

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002D8398);

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002D8450);

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002D8880);

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002D9FA0);

extern "C" int func_002D9FF0(int a) {
    if (func_0028D558(a) != 0) {
        return func_0028D1B0(a, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D8368", func_002DA050);
