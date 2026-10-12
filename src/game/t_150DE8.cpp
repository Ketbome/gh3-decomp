#include "common.h"

struct VE_00151988 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_00151988 { char pad0[0x90]; VE_00151988* unk90; };

struct S_00152610 { u8 unk0; u8 unk1; u8 unk2; u8 unk3; };

struct S_00152638 { int unk0; int unk4; int unk8; };

struct E_001510D8 { char pad0[0x18]; };
struct S_001510D8 { char pad0[0x68]; E_001510D8* unk68; };

struct S_001510D0 { char pad0[0x64]; int unk64; };
struct S_00152C50 { int unk0; };
struct S_00152C58 { int unk0; };
struct S_00152C60 { char pad0[0x10]; int unk10; };
struct S_00152C68 { char pad0[0x10]; int unk10; };

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00150DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00150EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001510C8);

extern "C" int func_001510D0(S_001510D0* self) {
    return self->unk64;
}

extern "C" E_001510D8* func_001510D8(S_001510D8* self, int i) {
    return &self->unk68[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001510F0);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00151120);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00151940);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00151950);

extern "C" void func_00151988(S_00151988* self, int a1) {
    VE_00151988* e = &self->unk90[11];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" void func_001519B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001519B8);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152540);

extern "C" void func_001525C8(void) {
}

extern "C" void func_001525D0(void) {
}

extern "C" void func_001525D8(void) {
}

extern "C" int func_001525E0(void) {
    return 0;
}

extern "C" int func_001525E8(void) {
    return 0;
}

extern "C" int func_001525F0(void) {
    return 0;
}

extern "C" int func_001525F8(void) {
    return 0;
}

extern "C" int func_00152600(void) {
    return 0;
}

extern "C" void func_00152608(void) {
}

extern "C" S_00152610* func_00152610(S_00152610* self) {
    self->unk0 = 0x80;
    self->unk1 = 0x80;
    self->unk2 = 0x80;
    self->unk3 = 0x80;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152630);

extern "C" void func_00152638(S_00152638* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152648);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152670);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152850);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152908);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152990);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001529F0);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152A50);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152AB0);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152B10);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152B38);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152B88);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152C20);

extern "C" int func_00152C50(S_00152C50* self) {
    return self->unk0;
}

extern "C" void func_00152C58(S_00152C58* self, int v) {
    self->unk0 = v;
}

extern "C" int func_00152C60(S_00152C60* self) {
    return self->unk10;
}

extern "C" void func_00152C68(S_00152C68* self, int v) {
    self->unk10 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152C70);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152C78);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152CE0);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152D08);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152D30);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152D80);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152DC8);
