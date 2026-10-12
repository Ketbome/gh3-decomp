#include "common.h"

struct S0025D4E0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

extern "C" {
extern int D_00368744[] __attribute__((section(".sdata")));
int func_00277208(void);
int func_0025C6A0(int, int);
int func_0011A568(void);
int func_0011E9C8(void);
extern int D_003705D8;
int func_00264B70(void);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_001194B8(int);
void func_00119CC0(int);
}

extern "C" int func_0025C450(void) {
    func_00277208();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C470);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C478);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C530);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C5E8);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C6F8);

extern "C" void func_0025C790(void) {
    func_0025C6A0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C7B0);

extern "C" int func_0025C7E8(void) {
    func_0011A568();
    return 1;
}

extern "C" int func_0025C808(void) {
    return D_00368744[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C818);

extern "C" int func_0025C8B0(void) {
    func_001194B8(D_00368A38[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C8D8);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C958);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C9D0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CA18);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CA80);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CAE8);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CBF0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CD30);

extern "C" int func_0025CDB8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CDC0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D458);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D478);

extern "C" int func_0025D4B0(void) {
    return 1;
}

extern "C" int func_0025D4B8(void) {
    func_0011E9C8();
    return 1;
}

extern "C" int func_0025D4D8(void) {
    return 0;
}

extern "C" S0025D4E0* func_0025D4E0(S0025D4E0* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D500);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D680);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D740);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025DEF0);

extern "C" int func_0025DF70(void) {
    func_00119CC0(D_00368A38[0]);
    return 1;
}

extern "C" void func_0025DF98(void) {
    D_003705D8 = func_00264B70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025DFB8);

extern "C" void func_0025DFE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025DFE8);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025E168);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025E170);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025E1C8);
