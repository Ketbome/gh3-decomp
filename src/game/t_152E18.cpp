#include "common.h"

struct S_00154180 { char pad0[0x58]; struct S_00154180* unk58; };
struct S_001537C0 { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; };

struct VE_001530D8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001530D8 { char pad0[0x18]; VE_001530D8* unk18; };

struct VE_00153498 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int, int); };
struct S_00153498 { char pad0[0x8]; VE_00153498* unk8; };

struct VE_001534C0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct S_001534C0 { char pad0[0x8]; VE_001534C0* unk8; };

struct VE_001534E8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001534E8 { char pad0[0x8]; VE_001534E8* unk8; };

struct VE_001535C0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int); };
struct S_001535C0 { char pad0[0x8]; VE_001535C0* unk8; };

extern "C" {
void func_00189540(void);
extern S_00154180* D_00369B8C;
}

struct S_00153268 { char pad0[0x4]; int unk4; };
struct S_00154420 { int unk0; };

struct S_00153140 { char pad0[0x14]; int unk14; };
struct S_00153148 { char pad0[0x4]; int unk4; };

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152E18);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152E88);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152F48);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152F78);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153010);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153078);

extern "C" void func_001530D8(S_001530D8* self, int a1) {
    VE_001530D8* e = &self->unk18[3];
    e->unk4((char*)self + e->unk0, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153100);

extern "C" int func_00153140(S_00153140* self) {
    return self->unk14;
}

extern "C" int func_00153148(S_00153148* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153150);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153178);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001531A0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001531C8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001531F0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153218);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153240);

extern "C" void func_00153268(S_00153268* self, int v) {
    self->unk4 |= v;
}

extern "C" void func_00153278(S_00153268* self, int v) {
    self->unk4 &= ~v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153290);

extern "C" void func_001533F0(void) {
}

extern "C" void func_001533F8(void) {
}

extern "C" int func_00153400(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153408);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153430);

extern "C" void func_00153478(S_00153268* self) {
    self->unk4++;
}

extern "C" void func_00153488(S_00153268* self) {
    self->unk4--;
}

extern "C" int func_00153498(S_00153498* self, int a1, int a2, int a3) {
    VE_00153498* e = &self->unk8[3];
    return e->unk4((char*)self + e->unk0, a1, a2, a3);
}

extern "C" void func_001534C0(S_001534C0* self, int a1, int a2) {
    VE_001534C0* e = &self->unk8[4];
    e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" void func_001534E8(S_001534E8* self, int a1) {
    VE_001534E8* e = &self->unk8[5];
    e->unk4((char*)self + e->unk0, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153510);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153588);

extern "C" void func_001535C0(S_001535C0* self, int a1, int a2, int a3, int a4) {
    VE_001535C0* e = &self->unk8[10];
    e->unk4((char*)self + e->unk0, a1, a2, a3, a4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001535E8);

extern "C" int func_00153760(void) {
    return 0;
}

extern "C" int func_00153768(void) {
    return 0;
}

extern "C" void func_00153770(void) {
}

extern "C" void func_00153778(void) {
}

extern "C" void func_00153780(void) {
}

extern "C" void func_00153788(void) {
}

extern "C" int func_00153790(void) {
    return 0;
}

extern "C" int func_00153798(void) {
    return 0;
}

extern "C" void func_001537A0(void) {
}

extern "C" void func_001537A8(void) {
}

extern "C" float func_001537B0(void) {
    return 0.0f;
}

extern "C" S_001537C0* func_001537C0(S_001537C0* self) {
    self->unk0 = 0;
    self->unk2 = 0;
    self->unk4 = 0x4000;
    self->unk6 = 0x4000;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001537E0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153810);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153898);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153958);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153AB0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153C28);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153D80);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153DB0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153E70);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153F08);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153F38);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153F68);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153F98);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153FC8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154030);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154078);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001540A8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001540D8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154108);

extern "C" void func_00154138(void) {
}

extern "C" void func_00154140(void) {
}

extern "C" void func_00154148(void) {
}

extern "C" void func_00154150(void) {
}

extern "C" void func_00154158(void) {
}

extern "C" void func_00154160(void) {
    func_00189540();
}

extern "C" S_00154180* func_00154180(void) {
    S_00154180* p = D_00369B8C;
    if (p) D_00369B8C = p->unk58;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001541A0);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", CFunc_LightShow_UpdateLightingTweaks);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154380);

extern "C" S_00154420* func_00154420(S_00154420* self) {
    self->unk0 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154430);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001544B8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154510);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154540);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154608);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154640);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154670);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001546B8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154708);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154750);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001547C8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154830);

extern "C" void func_001548F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154900);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001549B0);
