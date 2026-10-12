#include "common.h"

struct S00173F90 {
    char pad[0x14];
    void* unk14;
};

extern "C" {
void func_00172E18(void);
extern u8 D_00340B00[];
void func_00172A00(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001727C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001728A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172940);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172960);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172970);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001729C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172A00);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172B38);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172C30);

extern "C" int func_00172CC0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172D00);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172D80);

extern "C" void func_00172E00(void) {
}

extern "C" void func_00172E08(void) {
}

extern "C" void func_00172E10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172E18);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00173C78);

extern "C" void func_00173F60(void) {
    func_00172E18();
}

extern "C" u32 func_00173F80(void) {
    return 0xDA3403B0 /* null */;
}

extern "C" void func_00173F90(S00173F90* self) {
    self->unk14 = D_00340B00;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00173FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00174058);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001746A8);
