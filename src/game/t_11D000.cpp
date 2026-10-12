#include "common.h"

struct S_0011DAA0 { char pad0[0x40]; int unk40; };
struct S_0011DB50 { char pad0[0x4]; int unk4; int unk8; int unkC; };

struct S_0011E8F8 { char pad0[0x18]; int unk18; };

struct S_0011E998 { char pad0[0x1C]; void (*unk1C)(void); };

struct VE_0011DB60 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_0011DB60 { char pad0[0x44]; VE_0011DB60* unk44; };

extern "C" {
extern long D_00368CF0;
extern float D_00368D04;
extern float D_00368D08;
extern float D_00368CE8;
extern float D_00368CEC;
extern int D_00368C04;
void func_002EA460(void);
void func_00120DF0(void);
void func_00120DF8(void);
void func_00113FB8(int);
void func_00113F38(void);
void func_0011D830(int, int);
extern int D_00368C00;
void func_00120C80(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D000);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D220);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D348);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D370);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D520);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D530);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D720);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D828);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D830);

extern "C" void func_0011D968(void) {
    func_0011D830(1, 0xFFFF);
}

extern "C" void func_0011D988(void) {
    func_002EA460();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DA60);

extern "C" int func_0011DAA0(S_0011DAA0* self) {
    return self->unk40 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DAB0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DB08);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DB40);

extern "C" void func_0011DB50(S_0011DB50* self, int a, int b, int c) {
    self->unk4 = a;
    self->unk8 = b;
    self->unkC = c;
}

extern "C" int func_0011DB60(S_0011DB60* self) {
    VE_0011DB60* e = &self->unk44[22];
    return e->unk4((char*)self + e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DB88);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DBB8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DBE8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DC18);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DC48);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DCD8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DD68);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DDA8);

extern "C" void func_0011DDF8(void) {
}

extern "C" int func_0011DE00(void) {
    return 0;
}

extern "C" int func_0011DE08(void) {
    return 0;
}

extern "C" int func_0011DE10(void) {
    return 0;
}

extern "C" int func_0011DE18(void) {
    return 0;
}

extern "C" int func_0011DE20(void) {
    return 0;
}

extern "C" void func_0011DE28(void) {
}

extern "C" void func_0011DE30(void) {
}

extern "C" void func_0011DE38(void) {
}

extern "C" void func_0011DE40(void) {
}

extern "C" void func_0011DE48(void) {
}

extern "C" int func_0011DE50(void) {
    return 0;
}

extern "C" int func_0011DE58(void) {
    return 0;
}

extern "C" int func_0011DE60(void) {
    return 0;
}

extern "C" int func_0011DE68(void) {
    return 0;
}

extern "C" int func_0011DE70(void) {
    return 0;
}

extern "C" int func_0011DE78(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DE80);

extern "C" void func_0011DEE0(void) {
    D_00368C00 = 0;
    func_00120C80();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DF00);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DF78);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E008);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E050);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E130);

extern "C" int func_0011E160(void) {
    return D_00368C04 > 0;
}

extern "C" void func_0011E170(void) {
    func_00120DF0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E190);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E4E8);

extern "C" void func_0011E540(void) {
    func_00120DF8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E560);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E730);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E780);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E7D8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E868);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E8D0);

extern "C" void func_0011E8F8(S_0011E8F8* self) {
    func_00113FB8(self->unk18);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E918);

extern "C" void func_0011E940(void) {
    func_00113F38();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E960);

extern "C" void func_0011E998(S_0011E998* self) {
    self->unk1C();
}

extern "C" void func_0011E9B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E9C0);

extern "C" void func_0011E9D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EA30);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EAD8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EB48);

extern "C" void func_0011EB98(void) {
}

extern "C" void func_0011EBA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EBA8);

extern "C" long func_0011ECE8(void) {
    return D_00368CF0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ECF0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ED00);

extern "C" float func_0011ED10(void) {
    return D_00368D04;
}

extern "C" float func_0011ED18(void) {
    return D_00368D08;
}

extern "C" float func_0011ED20(void) {
    return D_00368CE8;
}

extern "C" void func_0011ED28(float v) {
    D_00368CEC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ED30);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ED40);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ED68);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EE38);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF00);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF18);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF20);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF78);
