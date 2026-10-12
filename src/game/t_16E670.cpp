#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0016EDF0 {
    char pad[0x24];
    VEntry* unk24;
};

struct S_0016E990 { int unk0; int unk4; int unk8; };

extern "C" {
void func_001B4E70(void);
void func_00199370(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E670);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E728);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E778);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E7A8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E7E8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E810);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E850);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E900);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E958);

extern "C" void func_0016E990(S_0016E990* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EBA8);

extern "C" void func_0016EBC8(void) {
}

extern "C" void func_0016EBD0(void) {
}

extern "C" void func_0016EBD8(void) {
}

extern "C" void func_0016EBE0(void) {
}

extern "C" void func_0016EBE8(void) {
}

extern "C" void func_0016EBF0(void) {
}

extern "C" void func_0016EBF8(void) {
}

extern "C" void func_0016EC00(void) {
}

extern "C" void func_0016EC08(void) {
}

extern "C" void func_0016EC10(void) {
}

extern "C" void func_0016EC18(void) {
}

extern "C" void func_0016EC20(void) {
}

extern "C" void func_0016EC28(void) {
}

extern "C" void func_0016EC30(void) {
}

extern "C" void func_0016EC38(void) {
}

extern "C" void func_0016EC40(void) {
}

extern "C" void func_0016EC48(void) {
}

extern "C" void func_0016EC50(void) {
}

extern "C" void func_0016EC58(void) {
}

extern "C" float func_0016EC60(void) {
    return 0.0f;
}

extern "C" float func_0016EC70(void) {
    return 0.0f;
}

extern "C" float func_0016EC80(void) {
    return 0.0f;
}

extern "C" float func_0016EC90(void) {
    return 0.0f;
}

extern "C" float func_0016ECA0(void) {
    return 0.0f;
}

extern "C" float func_0016ECB0(void) {
    return 0.0f;
}

extern "C" int func_0016ECC0(void) {
    return 0;
}

extern "C" float func_0016ECC8(void) {
    return 0.0f;
}

extern "C" float func_0016ECD8(void) {
    return 0.0f;
}

extern "C" void func_0016ECE8(void) {
}

extern "C" void func_0016ECF0(void) {
}

extern "C" void func_0016ECF8(void) {
}

extern "C" void func_0016ED00(void) {
}

extern "C" void func_0016ED08(void) {
}

extern "C" void func_0016ED10(void) {
}

extern "C" void func_0016ED18(void) {
}

extern "C" int func_0016ED20(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016ED28);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016ED90);

extern "C" void func_0016EDF0(S0016EDF0* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk24[5];
    ((void (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EE18);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EE58);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EEC0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EF10);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EF20);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EF40);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EFA8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F030);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F248);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F5F0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F820);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FAD8);

extern "C" void func_0016FB78(void) {
    func_001B4E70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FB98);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FC10);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FC70);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FCD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FDC8);

extern "C" int func_0016FE00(void) {
    return 0;
}

extern "C" int func_0016FE08(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FE10);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FE50);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FEF0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FF60);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_00170180);

extern "C" void func_00170570(void) {
    func_00199370();
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_00170590);
