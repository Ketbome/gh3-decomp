#include "common.h"

struct S001941E8 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_003465B8[];
extern u8 D_003465D0[];
void func_00169738(void);
extern u8 D_00346720[];
extern u8 D_00346738[];
void func_0016A2F0(void);
extern u8 D_00346888[];
extern u8 D_003468A0[];
void func_00168708(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_001940C8);

extern "C" void func_001941E8(S001941E8* self) {
    self->unk20 = D_003465B8;
    self->unk8 = D_003465D0;
    func_00169738();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194218);

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194C18);

extern "C" void func_00194D38(S001941E8* self) {
    self->unk20 = D_00346720;
    self->unk8 = D_00346738;
    func_0016A2F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194D68);

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00195388);

extern "C" void func_001954C0(S001941E8* self) {
    self->unk20 = D_00346888;
    self->unk8 = D_003468A0;
    func_00168708();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_001954F0);
