#include "common.h"

struct S00283EE8 {
    u8 unk0;
};

struct S00283520 {
    int unk0;
};

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282F00);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282F48);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283020);

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

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002838E8);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283930);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283978);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002839C0);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283A08);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283B48);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283DB8);

extern "C" int func_00283EE8(S00283EE8* p) {
    return p->unk0 < 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283EF8);
