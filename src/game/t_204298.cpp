#include "common.h"

struct S204 {
    char pad0[0xC];
    void* unkC;
    char pad10[0x8];
    void* unk18;
    int unk1C;
    char pad20[0xC];
    int unk2C;
    int unk30;
    int unk34;
    char pad38[0x4];
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    char pad48[0x4];
    int unk4C;
};

extern "C" {
void func_001D1068(S204*, int);
void func_00113F38(void*);
void func_002060A0(int, int);
void* func_00113D20(u32 size);
void* func_00205748(void*);
void func_001D0F90(void*, int);
extern u8 D_0034FFA0[];
int func_001D1CF8(void*, u32);
void func_00205A40(S204*);
void func_001D14C0(void*, int);
}

extern "C" void func_00204298(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002042A0);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204498);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002044F8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204688);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204828);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204A50);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204A78);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00204AD8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205680);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002056B0);

extern "C" void* func_002056D8(void) {
    return func_00205748(func_00113D20(0x54));
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205700);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205748);

extern "C" void func_002057D0(S204* self, int flag) {
    self->unk18 = D_0034FFA0;
    func_001D0F90(self, flag);
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002057F8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002059E8);

extern "C" void func_00205A20(S204* self) {
    func_001D1068(self, 1);
}

extern "C" void func_00205A40(S204* self) {
    self->unk4C = 10;
    self->unk2C = 10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205A50);

extern "C" int func_00205AF0(void) {
    return 2;
}

extern "C" void func_00205AF8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205B00);

extern "C" int func_00205B38(S204* self) {
    return self->unk34;
}

extern "C" void func_00205B40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205B48);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205C60);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205DF0);

extern "C" void func_00205E50(S204* self, int v) {
    self->unk1C = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205E58);

extern "C" int func_00205E90(S204* self) {
    return self->unk1C == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205EA0);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205F00);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00205F98);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00206098);

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_002060A0);

extern "C" void func_002061C0(void* p) {
    func_00113F38(p);
}

extern "C" void func_002061E0(S204* self) {
    ((void (*)(S204*))self->unk1C)(self);
}

extern "C" void func_00206200(void) {
    func_002060A0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_204298", func_00206220);
