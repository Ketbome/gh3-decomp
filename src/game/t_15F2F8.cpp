#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0015F320 {
    char pad[0x18];
    VEntry* unk18;
};

struct S0015FA10 {
    char pad[0x4];
    VEntry* unk4;
};

struct S0015FDE8 {
    char pad[0x58];
    VEntry* unk58;
};

struct S0015F940 {
    char pad[0x8];
    VEntry* unk8;
};

struct S0015F488 {
    char pad[0xC];
    int unkC;
};

struct S0015F838 {
    char pad[0x14];
    u8 unk14;
};

struct S0015F8E8 {
    char pad[0x4];
    int unk4;
    void* unk8;
};

struct S0015F9B8 {
    int unk0;
    void* unk4;
};

extern "C" {
extern u8 D_0033DAC0[];
extern u8 D_0033DA98[];
void func_0018D668(void);
void func_0018D718(void);
void func_0018D780(void);
}

extern "C" void func_0015F2F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[20];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F320(S0015F320* self) {
    VEntry* e = &self->unk18[21];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F348(S0015F320* self) {
    VEntry* e = &self->unk18[25];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F370(S0015F320* self) {
    VEntry* e = &self->unk18[27];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F398(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[26];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F3C0(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[28];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F3E8(S0015F320* self) {
    VEntry* e = &self->unk18[29];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F410(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[30];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F438(S0015F320* self) {
    VEntry* e = &self->unk18[34];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F460(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[35];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F488(S0015F488* self, int v) {
    self->unkC = v;
}

extern "C" void func_0015F490(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[37];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F4B8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[38];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F4E0);

extern "C" void func_0015F508(S0015F320* self, int a1, int a2) {
    VEntry* e = &self->unk18[41];
    ((void (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" int func_0015F530(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[43];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F558(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[44];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F580(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[49];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F5A8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[50];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F5D0(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[51];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F5F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[45];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F620(S0015F320* self) {
    VEntry* e = &self->unk18[46];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F648(S0015F320* self) {
    VEntry* e = &self->unk18[47];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F670(S0015F320* self) {
    VEntry* e = &self->unk18[48];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F698);

extern "C" void func_0015F6F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[53];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F720(S0015F320* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk18[54];
    ((void (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" void func_0015F748(S0015F320* self) {
    VEntry* e = &self->unk18[55];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F770(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[56];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F798(S0015F320* self) {
    VEntry* e = &self->unk18[57];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F7C0(S0015F320* self, int a1, int a2, float f0) {
    VEntry* e = &self->unk18[58];
    return ((int (*)(void*, int, int, float))e->fn)((char*)self + e->delta, a1, a2, f0);
}

extern "C" int func_0015F7E8(S0015F320* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk18[59];
    return ((int (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" int func_0015F810(S0015F320* self, int a1, int a2) {
    VEntry* e = &self->unk18[60];
    return ((int (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" bool func_0015F838(S0015F838* self) {
    return self->unk14 != 0;
}

extern "C" void func_0015F848(S0015F320* self) {
    VEntry* e = &self->unk18[63];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F870(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[64];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F898(S0015F320* self) {
    VEntry* e = &self->unk18[65];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F8C0);

extern "C" void func_0015F8C8(void) {
    func_0018D668();
}

extern "C" S0015F8E8* func_0015F8E8(S0015F8E8* self) {
    self->unk4 = 0;
    self->unk8 = D_0033DAC0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F900);

extern "C" void func_0015F940(S0015F940* self) {
    VEntry* e = &self->unk8[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F968(S0015F940* self) {
    VEntry* e = &self->unk8[3];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F990(S0015F940* self, int a1) {
    VEntry* e = &self->unk8[4];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" S0015F9B8* func_0015F9B8(S0015F9B8* self, int a1) {
    self->unk0 = a1;
    self->unk4 = D_0033DA98;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F9D0);

extern "C" int func_0015FA10(S0015FA10* self) {
    VEntry* e = &self->unk4[3];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015FA38(void) {
    func_0018D718();
}

extern "C" void func_0015FA58(void) {
    func_0018D780();
}

extern "C" int func_0015FA78(void) {
    return 0;
}

extern "C" void func_0015FA80(void) {
}

extern "C" void func_0015FA88(void) {
}

extern "C" void func_0015FA90(void) {
}

extern "C" void func_0015FA98(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FAA0);

extern "C" int func_0015FB08(void) {
    return 1;
}

extern "C" void func_0015FB10(void) {
}

extern "C" int func_0015FB18(void) {
    return 0;
}

extern "C" int func_0015FB20(void) {
    return 1;
}

extern "C" int func_0015FB28(void) {
    return 1;
}

extern "C" int func_0015FB30(void) {
    return 1;
}

extern "C" int func_0015FB38(void) {
    return 1;
}

extern "C" int func_0015FB40(void) {
    return 1;
}

extern "C" int func_0015FB48(void) {
    return 1;
}

extern "C" int func_0015FB50(void) {
    return 1;
}

extern "C" int func_0015FB58(void) {
    return 1;
}

extern "C" int func_0015FB60(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FB68);

extern "C" void func_0015FBD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FC88);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FD88);

extern "C" int func_0015FDE8(S0015FDE8* self, int a1) {
    VEntry* e = &self->unk58[3];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FE10);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160100);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160168);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160170);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160458);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160610);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160658);

extern "C" int func_00160688(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160690);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160730);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160768);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001607F0);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160850);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001608C8);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001608D0);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160930);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160970);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160A40);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160A90);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160C58);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160E80);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001610A0);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00161138);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001611C0);
