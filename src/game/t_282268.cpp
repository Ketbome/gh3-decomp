#include "common.h"

struct S00283EE8 {
    u8 unk0;
};

struct S00283520 {
    int unk0;
};

extern "C" {
int func_0027B300(int, int);
int func_002763E0(int, int);
int func_002764E8(int, int);
int func_00276200(int, int);
int func_002762F0(int, int);
void func_00119400(int, int);
extern int D_00368A38;
void func_00282F48(void *);
bool func_00282398(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282268);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282398);

extern "C" bool func_002826A0(void) {
    return !func_00282398();
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002826C0);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282838);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002829B0);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282CC8);

struct S282ED0 {
    char pad0[0x24];
    int unk24;
};
extern "C" S282ED0 *func_00282ED0(S282ED0 *p) {
    p->unk24 = 0;
    func_00282F48(p);
    return p;
}

extern "C" void func_00282F00(int a, int b) {
    func_00282F48((void *)a);
    if (b & 1) {
        func_00119400(D_00368A38, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282F48);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282FA8);

struct S283020 {
    int unk0;
    int unk4;
    int unk8;
    char padC[8];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
extern "C" void func_00283020(S283020 *p, int a, int b, int c) {
    p->unk20 = 0;
    p->unk14 = b;
    p->unk18 = b;
    p->unk1C = c;
    p->unk4 = a;
    p->unk8 = func_0027B300(a, 0);
    p->unk0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283070);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283098);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283498);

extern "C" int func_00283520(S00283520* p) {
    return (u32)(p->unk0 - 9) < 2;
}

extern "C" int func_00283530(S00283520* p) {
    return p->unk0 == 9;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283540);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283698);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002837C0);

struct S2838E8 {
    int unk0;
    int pad4;
    int unk8;
};
extern "C" int func_002838E8(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0xA00) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002762F0(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_00283930(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0xC00) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_00276200(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_00283978(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0x1800) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002764E8(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_002839C0(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0x1400) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002763E0(p->unk8, 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283A08);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283B48);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283DB8);

extern "C" int func_00283EE8(S00283EE8* p) {
    return p->unk0 < 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283EF8);
