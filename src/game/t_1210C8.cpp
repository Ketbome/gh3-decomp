#include "common.h"

struct S_00122918 { char pad0[0x1C]; void (*unk1C)(void); };

struct S_00123018 { char pad0[0x2C]; int unk2C; char pad1[0x4]; int unk34; };

extern "C" {
extern int D_00372AC0;
void func_00121DD0(void);
void func_00121B18(void);
void func_00113F38(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001210C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121240);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121618);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121668);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001216B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121870);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001218A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001218F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121A68);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121B18);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121B68);

extern "C" void func_00121BD0(void) {
    func_00121DD0();
}

extern "C" int func_00121BF0(void) {
    return 0;
}

extern "C" void func_00121BF8(void) {
    func_00121B18();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121C18);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121C68);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121CD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121D78);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121E38);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121F28);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121F70);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122460);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122490);

extern "C" int func_001224F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001224F8);

extern "C" int func_00122550(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122558);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122608);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001226A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122700);

extern "C" void func_00122770(void) {
    D_00372AC0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122778);

extern "C" void func_001228F8(void) {
    func_00113F38();
}

extern "C" void func_00122918(S_00122918* self) {
    self->unk1C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122938);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122940);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122A10);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122E58);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122F88);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122FF8);

extern "C" int func_00123018(S_00123018* self, int v) {
    if (self->unk34 == v) {
        self->unk2C |= 1;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00123040);
