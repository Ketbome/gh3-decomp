#include "common.h"

struct G10 {
    s32 unk0;
    char pad4[0xC];
};

struct S001C82D8 {
    char pad0[0x81A4];
    u32 unk81A4;
    char pad81A8[0x20];
    s32 unk81C8;
    s32 unk81CC;
};

extern "C" {
extern G10 D_00368740;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7B18);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7B38);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7B58);

extern "C" s32 func_001C7B70(void) {
    s32 v = D_00368740.unk0;

    return v != 4 && v != 6;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7B98);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8040);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8258);

extern "C" s32 func_001C82D8(S001C82D8* p) {
    u32* f = &p->unk81A4;

    return (*f & 0xC) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C82F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8370);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8470);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C84A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8568);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C85A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C86C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8718);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C88C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8A08);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8E98);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8F08);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C91D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9210);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9298);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9368);

extern "C" void func_001C93B0(S001C82D8* p, s32 v) {
    p->unk81C8 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C93C0);

extern "C" s32 func_001C9458(S001C82D8* p) {
    return p->unk81CC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9468);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C94A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C94C0);

extern "C" s32 func_001C94D8(S001C82D8* p) {
    u32* f = &p->unk81A4;

    return *f & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C94F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C95D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9658);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9778);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C97E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C98F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A20);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A80);
