#include "common.h"

struct S00198160 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

struct S_00197ED8 { char pad0[0x1E8]; int unk1E8; };

extern "C" {
void func_00196D10(void);
void func_0016CD28(void);
extern u8 D_00346C78[];
extern u8 D_00346C90[];
void func_00167D70(void);
void func_0014F150(int);
void func_00197EE8(void);
void Heap_Free(int, int);
extern int D_0036BEB0;
extern int D_0036BEB8;
extern u8 D_00381C50[];
extern int D_00368A38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001965D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001966C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00196D10);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00196EE8);

struct P197398 { char pad0[0x20]; long unk20; char pad28[8]; long unk30; };
struct Q197398 { char pad0[0x30]; long unk30; long unk38; };
struct S197398 { char pad0[0x18C]; int unk18C; char pad190[0xB0]; P197398* unk240; Q197398* unk244; };

extern "C" void func_00197398(S197398* self) {
    if (self->unk18C) func_00196D10();
    if (self->unk244) {
        self->unk240->unk20 = self->unk244->unk30;
        self->unk240->unk30 = self->unk244->unk38;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_001973F8);

struct S_00197E30 { char pad0[0x1EC]; int unk1EC; char pad1F0[0x50]; int unk240; };

GP_DATA(D_0036BEB8);
GP_DATA(D_0036BEB0);
extern "C" void func_00197E30(S_00197E30* self) {
    if (self->unk240) {
        int* base = &D_0036BEB8;
        if (base[D_0036BEB0] == 0x100) {
            func_0014F150(0x100);
            func_00197EE8();
        }
        int val = self->unk240;
        int i = D_0036BEB0;
        int* c = &base[i];
        int n = *c;
        *c = n + 1;
        *(int*)(D_00381C50 + i * 4 + n * 8) = val;
    }
    if (self->unk1EC) Heap_Free(D_00368A38, self->unk1EC);
}

extern "C" int func_00197ED8(S_00197ED8* self) {
    return self->unk1E8 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00197FC8);

extern "C" void func_00198020(void) {
    func_0016CD28();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00198040);

extern "C" void func_00198160(S00198160* self) {
    self->unk20 = D_00346C78;
    self->unk8 = D_00346C90;
    func_00167D70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1965D0", func_00198190);
