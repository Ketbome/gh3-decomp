#include "common.h"

typedef unsigned int u128_20E __attribute__((mode(TI)));

struct S20Eb {
    char pad0[0x8];
    int unk8;
    int unkC;
};

struct S20E {
    u128_20E* unk0;
    int unk4;
    char pad8[0x8];
    f32* unk10;
    char pad14[0x10];
    int unk24;
    char pad28[0x70];
    int unk98;
};

struct S210 {
    char pad0[0x20];
    int unk20;
    int unk24;
    char pad28[0x268];
    S20Eb unk290;
    char pad2A0[0x18];
    int unk2B8;
    char unk2BC[0x4];
    char pad2C0[0xE8];
    char unk3A8[0x2C8];
    int unk670;
};

extern "C" {
void func_0020CE80(void*);
void func_0020C0D8(void*);
void func_0020AEC8(void*);
void func_0020F1B8(void*);
void func_00210558(void*);
f32 func_002EC100(f32);
void func_0020CD08(void*);
void func_001E2B90(void*, int);
int func_001E2968(void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EE10);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EEF0);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EF70);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020EFA8);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F040);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F0C0);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F158);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F1B8);

extern "C" void func_0020F3F0(S20E* self, int a, int b) {
    self->unk4 = a;
    self->unk98 = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F400);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F450);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_0020F6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_002102F8);

extern "C" int func_00210388(S210* self, int a, int b) {
    if (self->unk2B8) {
        func_001E2B90(self->unk2BC, b);
    } else {
        func_001E2B90(&self->unk290, b);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_002103C8);

extern "C" int func_00210408(S210* self) {
    func_0020CE80(&self->unk2B8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210428);

extern "C" int func_002104E0(S210* self) {
    self->unk24 = 1;
    func_00210558(self);
    return 1;
}

extern "C" int func_00210508(S20E* self) {
    self->unk24 = 0;
    return 1;
}

extern "C" int func_00210518(S210* self) {
    if (self->unk20) {
        return 0;
    }
    self->unk20 = 1;
    return 1;
}

extern "C" int func_00210538(S210* self) {
    if (!self->unk20) {
        return 0;
    }
    self->unk20 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210558);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_002105A8);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210678);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210720);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_002107C8);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210870);

extern "C" int func_002108D0(S210* self) {
    int* p = &self->unk670;
    if (*p == 0) {
        func_0020CD08(p);
        return 1;
    }
    return 0;
}

extern "C" int func_00210908(S210* self) {
    func_0020C0D8(self);
    return 1;
}

extern "C" int func_00210928(S210* self) {
    func_0020AEC8(self);
    return 1;
}

extern "C" int func_00210948(S210* self) {
    func_0020F1B8(self->unk3A8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210968);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210A18);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210A88);

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210C90);

extern "C" void func_00210CA0(S20E* self, int i, f32* v) {
    f32* p = self->unk10;
    p += i;
    *p = *v;
}

extern "C" void func_00210CB8(S20E* self, int i, u128_20E* v) {
    u128_20E* p = self->unk0;
    p += i;
    *p = *v;
}

extern "C" int func_00210CD0(S20E* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20EE10", func_00210CD8);
