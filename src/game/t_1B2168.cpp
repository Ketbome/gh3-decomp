#include "common.h"

struct E10 {
    u16 unk0;
    char pad2[0x2];
    u16 unk4;
    char pad6[0x4];
};

struct S001B2168 {
    char pad0[0xC];
    E10* unkC;
    u8 unk10[1];
};

struct S001B2230 {
    char pad0[0x20];
    void* unk20;
};

extern "C" {
void func_001BF6A0(void* p);
void func_001B3D28(s32 a, s32 b);
int func_002EED08(s32 a);
int func_002EE390(s32 a, s32 b);
int func_002EEC38(s32 a);
int func_002EE360(s32 a, s32 b);
extern char D_00349220[];
extern s32 D_0036C850;
extern s32 D_0036C854;
extern s32 D_00372B18;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B2168);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B21A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B21E0);

extern "C" void func_001B2230(S001B2230* p) {
    p->unk20 = D_00349220;
    func_001BF6A0(p);
}

extern "C" void func_001B2258(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B2260);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B24A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3220);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3368);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3370);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3B00);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3BA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3C98);

extern "C" void func_001B3CF8(s32 v) {
    D_0036C850 = v;
}

extern "C" void func_001B3D00(s32 v) {
    D_00372B18 = v;
    D_0036C854 = v;
}

extern "C" s32 func_001B3D10(void) {
    return D_0036C850;
}

extern "C" s32 func_001B3D18(void) {
    return D_0036C854;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3D20);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3D28);

extern "C" void func_001B3DB0(void) {
    func_001B3D28(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3F48);
