#include "common.h"

extern "C" {
extern int D_00368A38;
int func_00118F20(int, int, int, int);
void func_00296DE0(int, int, int, int, int, int);
void *func_0030A49C(void *, int, int);
}

struct S0029BDA0 {
    char pad[0x3138];
    u32 unk3138;
    u32 unk313C;
};

struct S29AA58 {
    int unk0;
    char unk4[0x28];
    int unk2C;
    int unk30;
    int unk34;
};
extern "C" S29AA58 *func_0029AA58(S29AA58 *p) {
    func_0030A49C(p->unk4, 0, 0x28);
    p->unk0 = 0x3E8;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029AAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029ABB8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029AFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B258);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B468);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B510);

extern "C" void func_0029B5F8(int a, u8 b, u16 c, int d, u8 e, s8 f) {
    func_00296DE0(func_00118F20(D_00368A38, 0x14, 1, 0), b, c, d, e, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B680);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BB28);

extern "C" int func_0029BDA0(void* a, S0029BDA0* p) {
    return p->unk313C > p->unk3138;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BF58);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029C1C0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029C4C0);
