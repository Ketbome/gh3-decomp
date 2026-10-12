#include "common.h"

struct S_00157538 { char pad0[0x4]; int unk4; void* unk8; };

struct S_00157558 { int unk0; int unk4; void* unk8; };

struct VE_001571F8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001571F8 { char pad0[0x20]; VE_001571F8* unk20; };

struct VE_00157220 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct S_00157220 { char pad0[0x20]; VE_00157220* unk20; };

struct VE_00157710 { s16 unk0; s16 unk2; int (*unk4)(void*, int); };
struct S_00157710 { char pad0[0x8]; VE_00157710* unk8; };

struct VE_00157738 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int); };
struct S_00157738 { char pad0[0x8]; VE_00157738* unk8; };

struct VE_00157760 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int); };
struct S_00157760 { char pad0[0x8]; VE_00157760* unk8; };

struct VE_00157788 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_00157788 { char pad0[0x8]; VE_00157788* unk8; };

extern "C" {
void func_00183498(void);
void func_00183678(void);
void func_00157420(int, int);
extern u8 D_0033CE40[];
}

struct S_00157248 { char pad0[0x18]; int unk18; };

struct S_001571F0 { char pad0[0x4]; int unk4; };
struct S_00157258 { int unk0; };
struct S_00157260 { int unk0; };

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157100);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157160);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157190);

extern "C" void func_001571F0(S_001571F0* self, int v) {
    self->unk4 = v;
}

extern "C" void func_001571F8(S_001571F8* self, int a1) {
    VE_001571F8* e = &self->unk20[10];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" void func_00157220(S_00157220* self, int a1, int a2) {
    VE_00157220* e = &self->unk20[11];
    e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157248(S_00157248* self, int v) {
    self->unk18 = v;
    return 1;
}

extern "C" void func_00157258(S_00157258* self, int v) {
    self->unk0 = v;
}

extern "C" int func_00157260(S_00157260* self) {
    return self->unk0;
}

extern "C" int func_00157268(void) {
    return 0;
}

extern "C" int func_00157270(void) {
    return 0;
}

extern "C" int func_00157278(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157280);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157298);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001572D0);

extern "C" void func_001572E8(void) {
}

extern "C" void func_001572F0(void) {
}

extern "C" void func_001572F8(void) {
}

extern "C" int func_00157300(void) {
    return 0;
}

extern "C" int func_00157308(void) {
    return 0;
}

extern "C" void func_00157310(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157318);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157378);

extern "C" void func_001573B8(void) {
    func_00183498();
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001573D8);

extern "C" void func_00157400(void) {
    func_00183678();
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157420);

extern "C" void func_001574A0(void) {
    func_00157420(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001574C0);

extern "C" S_00157538* func_00157538(S_00157538* self) {
    self->unk8 = D_0033CE40;
    self->unk4 = *(u16*)&self->unk4;
    return self;
}

extern "C" S_00157558* func_00157558(S_00157558* self, S_00157558* o) {
    self->unk8 = D_0033CE40;
    self->unk0 = o->unk0;
    self->unk4 = o->unk4;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157580);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001575C0);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001576A8);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001576E0);

extern "C" int func_00157710(S_00157710* self, int a1) {
    VE_00157710* e = &self->unk8[8];
    return e->unk4((char*)self + e->unk0, a1);
}

extern "C" int func_00157738(S_00157738* self, int a1, int a2) {
    VE_00157738* e = &self->unk8[12];
    return e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157760(S_00157760* self, int a1, int a2) {
    VE_00157760* e = &self->unk8[13];
    return e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157788(S_00157788* self) {
    VE_00157788* e = &self->unk8[14];
    return e->unk4((char*)self + e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001577B0);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001577B8);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157908);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157A58);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158070);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158578);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158760);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158768);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158A30);
