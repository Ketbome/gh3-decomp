#include "common.h"

struct S001682D8 {
    char pad[0x2F8];
    float unk2F8;
};

struct S00168888 {
    char pad[0x2D0];
    int unk2D0;
};

struct S00168C98 {
    char pad[0x2F0];
    int unk2F0;
};

struct S00169BD8 {
    char pad[0x2F0];
    float unk2F0;
};

struct S00168C60 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_0033E9A8[];
extern u8 D_0033E9C0[];
void func_00162FC8(void);
extern u8 D_0033EB10[];
extern u8 D_0033EB28[];
extern u8 D_0033EC78[];
extern u8 D_0033EC90[];
extern u8 D_0033EDE0[];
extern u8 D_0033EDF8[];
}

extern "C" void func_001682D8(S001682D8* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_001682E0(void) {
    return 3;
}

extern "C" int func_001682E8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_001682F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168708);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168778);

extern "C" void func_00168870(S001682D8* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_00168878(S00168888* self) {
    return self->unk2D0 + 3;
}

extern "C" int func_00168888(S00168888* self) {
    return self->unk2D0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168890);

extern "C" void func_00168C60(S00168C60* self) {
    self->unk20 = D_0033E9A8;
    self->unk8 = D_0033E9C0;
    func_00162FC8();
}

extern "C" int func_00168C90(void) {
    return 2;
}

extern "C" int func_00168C98(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168CA0);

extern "C" void func_00168F28(S00168C60* self) {
    self->unk20 = D_0033EB10;
    self->unk8 = D_0033EB28;
    func_00162FC8();
}

extern "C" int func_00168F58(void) {
    return 2;
}

extern "C" int func_00168F60(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168F68);

extern "C" void func_00169338(S00168C60* self) {
    self->unk20 = D_0033EC78;
    self->unk8 = D_0033EC90;
    func_00162FC8();
}

extern "C" int func_00169368(S00168C98* self) {
    return self->unk2F0;
}

extern "C" int func_00169370(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169378);

extern "C" void func_00169738(S00168C60* self) {
    self->unk20 = D_0033EDE0;
    self->unk8 = D_0033EDF8;
    func_00162FC8();
}

extern "C" int func_00169768(S00168888* self) {
    return self->unk2D0;
}

extern "C" int func_00169770(S00168888* self) {
    return self->unk2D0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169778);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169A70);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169AE0);

extern "C" void func_00169BD8(S00169BD8* self, float v) {
    self->unk2F0 = v;
}

extern "C" int func_00169BE0(void) {
    return 4;
}

extern "C" int func_00169BE8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169BF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169E70);

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169EE0);

extern "C" void func_00169FD8(S00169BD8* self, float v) {
    self->unk2F0 = v;
}

extern "C" int func_00169FE0(void) {
    return 2;
}

extern "C" int func_00169FE8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169FF0);
