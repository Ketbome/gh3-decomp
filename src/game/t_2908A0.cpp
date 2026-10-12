#include "common.h"

struct S00291CF0 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00290CF8 {
    char pad[0x4];
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

struct S002920F0 {
    char pad[0x8];
    int unk8;
    char pad1[0x4];
    int unk10;
};

struct S00290A20_2 {
    int unk0;
    int unk4;
};

struct S00290A20 {
    char pad[0x14C];
    S00290A20_2 unk14C[19];
    int unk1E4;
    int unk1E8;
};

extern "C" {
int func_00290BD0(int, int);
extern S002920F0* D_003715C0[2];
extern int D_003715D0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002908A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290908);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002909A8);

extern "C" void func_00290A20(S00290A20* p) {
    p->unk14C[p->unk1E8].unk0++;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290A40);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290BD0);

extern "C" void func_00290C20(void) {
    func_00290BD0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290C40);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290CA0);

extern "C" S00290CF8* func_00290CF8(S00290CF8* p) {
    p->unk8 = 0;
    p->unkC = 0;
    p->unk4 = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290D18);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290D68);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290DD8);

extern "C" void func_00290FD8(void) {
}

extern "C" void func_00290FE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290FE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291020);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291080);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002910E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291230);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291608);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002917B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002918F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291900);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291980);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291988);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291C38);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291C40);

extern "C" void func_00291CF0(S00291CF0* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291D00);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291D28);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291FC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00292078);

extern "C" int func_002920F0(void) {
    return D_003715C0[D_003715D0]->unk10;
}

extern "C" int func_00292110(void) {
    return D_003715C0[D_003715D0]->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00292130);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002921E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00292808);
