#include "common.h"

struct S002998C0 {
    char pad[0x10];
    int unk10;
    int unk14;
    int unk18;
    char pad1[0x208];
    int unk224;
};

extern "C" {
void func_0029DBA0(void);
void func_0029D730(int, int);
void func_0029D630(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298A30);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298A70);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299260);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299418);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299640);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_002996C0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_002997D0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299838);

extern "C" int func_002998C0(S002998C0* p) {
    int f = p->unk18;
    p->unk224 = 1;
    if (f & 1) {
        p->unk18 = f ^ 1;
    }
    return 1;
}

extern "C" int func_002998E8(S002998C0* p) {
    func_0029D630(p->unk10, p->unk14);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299910);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_002999C8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299A08);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299A48);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299A88);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299D20);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299E18);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A0E8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A218);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A590);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A5F0);

extern "C" void func_0029A640(void) {
    func_0029DBA0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A660);

extern "C" void func_0029A688(int a) {
    func_0029D730(a, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A740);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A778);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A7B8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A8E8);
