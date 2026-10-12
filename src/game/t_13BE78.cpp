#include "common.h"

struct S_0013DA80 { char pad0[0x240]; int unk240; };

struct S_0013D818 { char pad0[0xC]; int unkC; char pad1[0x268]; int unk278; };
struct S_0013DA60_b { int unk0; };
struct S_0013DA60 { char pad0[0x24C]; S_0013DA60_b* unk24C; };

struct S_0013CEA0 { char pad0[0x208]; u32 unk208; };

extern "C" {
void func_00113900(int);
void func_00154078(int);
}

struct S_0013CFC0 { char pad0[0x204]; int unk204; };

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013BE78);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C080);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C1B0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C1F0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C280);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C550);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C5F8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C678);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C948);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CB18);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CC28);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CC70);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CC98);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CCE8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CE58);

extern "C" bool func_0013CEA0(S_0013CEA0* self, int bit) {
    if (self->unk208 == 0) return true;
    return (self->unk208 & (1 << bit)) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CEC8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CED0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CF78);

extern "C" int func_0013CFC0(S_0013CFC0* self) {
    return self->unk204;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D000);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D048);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D100);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D1B8);

extern "C" void func_0013D2C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D2D0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D360);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D3E0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D730);

extern "C" void func_0013D818(S_0013D818* self, int v) {
    if (v >= 0) {
        self->unk278 = v;
        self->unkC |= 0x1000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D838);

extern "C" void func_0013DA60(S_0013DA60* self) {
    func_00154078(self->unk24C->unk0);
}

extern "C" void func_0013DA80(S_0013DA80* self) {
    func_00113900(self->unk240);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013DAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013DCA8);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013DD50);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013DDF8);
