#include "common.h"

struct S_00141670 { char pad0[0x248]; int unk248; };
struct S_00141690 { char pad0[0x248]; int unk248; };
struct S_00141968 { char pad0[0x248]; int unk248; };
struct S_00141B50 { char pad0[0x244]; int unk244; };

extern "C" {
void func_00141428(void);
void func_0015E228(int);
void func_0015E2A8(int);
void func_0015E648(int);
void func_0015EA48(int);
extern int D_003696B8;
void func_0011C2A8(int, int);
void func_0011C2E8(int, int);
}

struct S_00141608 { char pad0[0x248]; int* unk248; };

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_0013FEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_0013FF78);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140270);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140408);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140558);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001406D8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001407D8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140930);

extern "C" void func_001409B8(void) {
    func_0011C2A8(D_003696B8, 1);
}

extern "C" void func_001409D8(int a) {
    func_0011C2E8(D_003696B8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140A00);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140A60);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140F80);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001413A0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141428);

extern "C" int func_00141608(S_00141608* self) {
    return *self->unk248;
}

extern "C" void func_00141618(void) {
    func_00141428();
}

extern "C" void func_00141638(void) {
    func_00141428();
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141658);

extern "C" void func_00141660(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141668);

extern "C" void func_00141670(S_00141670* self) {
    func_0015E228(self->unk248);
}

extern "C" void func_00141690(S_00141690* self) {
    func_0015E2A8(self->unk248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001416B0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141920);

extern "C" void func_00141968(S_00141968* self) {
    func_0015E648(self->unk248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141988);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001419E8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141A40);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141AF8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141B00);

extern "C" void func_00141B50(S_00141B50* self) {
    func_0015EA48(self->unk244);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141B70);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141C28);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141DC8);
