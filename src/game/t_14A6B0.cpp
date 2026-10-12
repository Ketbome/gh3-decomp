#include "common.h"

extern "C" {
void func_0011A380(void);
void func_0011A470(void);
void func_0014B168(int, int);
}

struct S_0014C470 { int unk0; int unk4; int unk8; };

struct S_0014ABF8 { char pad0[0x50]; };

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A6B0);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A6F8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A728);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A770);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A7A0);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A7A8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A910);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A940);

extern "C" S_0014ABF8* func_0014ABF8(S_0014ABF8* p, int i) {
    return &p[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AC08);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AC58);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014ACB8);

extern "C" void func_0014ADF0(void) {
    func_0011A380();
}

extern "C" void func_0014AE10(void) {
    func_0011A470();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AE30);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AE80);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AEF8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B168);

extern "C" void func_0014B190(void) {
    func_0014B168(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B1B0);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B260);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B368);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B410);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014BCB8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C348);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C390);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C418);

extern "C" void func_0014C470(S_0014C470* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C480);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C4A8);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C560);
