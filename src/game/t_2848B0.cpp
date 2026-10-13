#include "common.h"

struct S00285A10 {
    char pad[0x5C];
    int unk5C;
    int unk60;
};

extern "C" {
extern struct S285A60 *D_00371344;
void func_00287F50(int);
extern int D_0037134C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002848B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00284F20);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002851C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285400);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002855B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285828);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002858C0);

extern "C" u8 *func_00285948(u8 *p, u32 v) {
    *p = v;
    p++;
    *p = v >> 8;
    p++;
    *p = v >> 16;
    p++;
    *p = v >> 24;
    return p + 1;
}

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

extern "C" void func_00285A30(int a, int b) {
    D_0037134C -= 1;
    if (b & 1) {
        func_00287F50(a);
    }
}

struct S285A60 {
    char pad0[4];
    int unk4;
    char pad8[0x54];
    S285A60 *unk5C;
};
GP_DATA(D_00371344);
extern "C" void func_00285A60(int a) {
    S285A60 *p = D_00371344;
    if (p) {
        do {
            if (p->unk4 == a) {
                p->unk4 = 0;
            }
            p = p->unk5C;
        } while (p);
    }
}

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
