#include "common.h"

struct VE_00130600 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_00130600 { char pad0[0x14]; VE_00130600* unk14; };

extern "C" {
void func_00131018(void);
}

struct E_00130CA8 { char pad0[0x50]; int unk50; char pad1[0x2C]; };
struct S_00130CA8 { char pad0[0x40]; E_00130CA8 unk40[1]; };

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012F9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012F9B0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012F9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012F9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FA98);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FAC8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FD20);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FD48);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FD78);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001305B8);

extern "C" void func_00130600(S_00130600* self, int a1) {
    VE_00130600* e = &self->unk14[5];
    e->unk4((char*)self + e->unk0, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130628);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001306E0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001309A8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130C58);

extern "C" void func_00130CA8(S_00130CA8* self, int i) {
    self->unk40[i].unk50 = 1;
}

extern "C" void func_00130CC0(S_00130CA8* self, int i) {
    self->unk40[i].unk50 = 0;
}

extern "C" int func_00130CD0(S_00130CA8* self, int i) {
    return self->unk40[i].unk50;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130CE0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130D10);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130E50);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130F70);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131008);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131018);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001310E8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131118);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131338);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001313E8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001315F8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001316B8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131728);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001317D0);

extern "C" void func_001318B0(void) {
    func_00131018();
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001318D0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131970);
