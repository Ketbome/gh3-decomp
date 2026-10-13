#include "common.h"

struct S00173F90 {
    char pad[0x14];
    void* unk14;
};

struct S172940b { char pad0[0x208]; int unk208; };
struct S172940a { char pad0[0x1C]; char* unk1C; };
struct S172940 { char pad0[0x3C]; S172940a* unk3C; };

extern "C" {
void func_00172E18(void);
extern u8 D_00340B00[];
void func_00172A00(void*);
extern S172940* D_0036AA94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001727C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001728A0);

GP_DATA(D_0036AA94);
extern "C" void func_00172940(int* a, S172940b** b) {
    S172940b* p = (S172940b*)(D_0036AA94->unk3C->unk1C + 0xC);
    *a = p->unk208;
    *b = p;
}

extern "C" int func_00172960(void) {
    char buf[0x40];
    return 0;
}

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
