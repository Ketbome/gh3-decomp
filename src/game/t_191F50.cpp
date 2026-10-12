#include "common.h"

struct S00191F50 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_00346018[];
extern u8 D_00346030[];
void func_0016A6A8(void);
extern u8 D_00346180[];
extern u8 D_00346198[];
void func_00168C60(void);
extern u8 D_003462E8[];
extern u8 D_00346300[];
void func_00168F28(void);
extern u8 D_00346450[];
extern u8 D_00346468[];
void func_00169338(void);
}

extern "C" void func_00191F50(S00191F50* self) {
    self->unk20 = D_00346018;
    self->unk8 = D_00346030;
    func_0016A6A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_00191F80);

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_001928E0);

extern "C" void func_00192A00(S00191F50* self) {
    self->unk20 = D_00346180;
    self->unk8 = D_00346198;
    func_00168C60();
}

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_00192A30);

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_00192EE0);

extern "C" void func_00193000(S00191F50* self) {
    self->unk20 = D_003462E8;
    self->unk8 = D_00346300;
    func_00168F28();
}

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_00193030);

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_001935F8);

extern "C" void func_00193718(S00191F50* self) {
    self->unk20 = D_00346450;
    self->unk8 = D_00346468;
    func_00169338();
}

INCLUDE_ASM("asm/nonmatchings/game/t_191F50", func_00193748);
