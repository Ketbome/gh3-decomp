#include "common.h"

struct S00289C80 {
    char pad[0xEC];
    int unkEC;
};

struct S00289E08 {
    char pad[0xC8];
    int unkC8;
};

struct S0028A000 {
    char pad[0x14];
    int unk14;
};

struct S002899B0 {
    char pad[0x8];
    int unk8;
};

struct S00289608 {
    int unk0;
};

struct S00289EA0_2 {
    char pad[0xC];
    int unkC;
};

struct S00289EA0 {
    char pad[0xC8];
    S00289EA0_2* unkC8;
};

extern "C" {
extern int D_00371484;
void func_00289F90(char*);
extern int D_0037148C;
int func_00288910(void*);
int func_00288998(void*);
int func_00288888(void*);
void func_00288D20(void*, void*, int);
void func_0028A020(int, int, int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288B10);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288B88);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C00);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C48);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C90);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288D20);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288D88);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288DC0);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288DF8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288E30);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288F90);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289048);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002890C8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002891A8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289228);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002892B0);

extern "C" void func_00289608(S00289608* p, int b) {
    if (p->unk0 == b) {
        func_00288888(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289630);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002896E0);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289710);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289750);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002897E8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289868);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289898);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002898E8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289938);

extern "C" int func_002899A8(void) {
    return D_00371484;
}

extern "C" int func_002899B0(S002899B0* p) {
    if (p == 0) {
        return D_0037148C;
    }
    return p->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002899C8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002899D8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289B40);

extern "C" int func_00289C80(S00289C80* p) {
    return p->unkEC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289C88);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289D30);

extern "C" int func_00289E08(S00289E08* p) {
    return p->unkC8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289E10);

extern "C" int func_00289EA0(S00289EA0* p, int m) {
    if (p->unkC8 != 0 && (p->unkC8->unkC & m)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289EC8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289ED8);

extern "C" void func_00289F48(char* a) {
    func_00288910(a + 0xA8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289F68);

extern "C" void func_00289F70(char* a) {
    func_00288998(a + 0xA8);
}

extern "C" void func_00289F90(char* a) {
    func_00288888(a + 0xA8);
}

extern "C" void func_00289FB0(char* a, int b) {
    func_00288D20(a + 0xA8, a, b);
}

extern "C" void func_00289FD8(char* a) {
    func_00289F90(a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289FF8);

extern "C" int func_0028A000(S0028A000* p) {
    return p->unk14 != 0;
}

extern "C" void func_0028A010(void) {
}

extern "C" void func_0028A018(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A020);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A140);

extern "C" void func_0028A2A8(int a, int b, int c, int d) {
    func_0028A020(a, b, 0, c, d);
}

extern "C" void func_0028A2D0(int a, int b, int c, int d) {
    func_0028A020(a, b, 0, c, d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A2F8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A300);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A558);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A5A0);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A650);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028AAB8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028AAC0);
