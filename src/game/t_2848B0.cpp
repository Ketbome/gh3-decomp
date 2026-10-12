#include "common.h"

struct S00285A10 {
    char pad[0x5C];
    int unk5C;
    int unk60;
};

extern "C" {
extern int D_0037134C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002848B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00284F20);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002851C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285400);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002855B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285828);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002858C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285948);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285978);

extern "C" u8* func_002859B0(u8* p, u16 v) {
    *p++ = v;
    *p++ = v >> 8;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002859D0);

GP_DATA(D_0037134C);
extern "C" S00285A10* func_00285A10(S00285A10* p) {
    p->unk5C = 0;
    p->unk60 = 0;
    D_0037134C++;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285A30);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285A60);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285A90);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285C90);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286108);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286160);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002861D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286270);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286330);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286398);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002863A0);
