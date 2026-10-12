#include "common.h"

struct S_0011A8D0 { char pad0[0xC]; int unkC; };
struct S_0011A8E8 { char pad0[0x10]; int unk10; };
struct S_0011A8F0 { char pad0[0x10]; int unk10; };
struct S_0011ACF8 { char pad0[0x20]; int unk20; };
struct S_0011AD00 { char pad0[0x2C]; int unk2C; };
struct S_0011AD08 { char pad0[0x8]; int unk8; };
struct S_0011AD78 { char pad0[0x5C]; int unk5C; };

struct S_00119500 { char pad0[0x190]; int* unk190; };
struct S_00119510_b { char pad0[0x38]; int unk38; };
struct S_00119510 { char pad0[0x190]; S_00119510_b** unk190; };
struct S_0011A8D8 { char pad0[0x4]; int unk4; char pad1[0xC]; int unk14; };

struct S_0011A680_b { char pad0[0x38]; int unk38; };
struct S_0011A680 { char pad0[0x18]; int unk18[2]; };

struct S_0011A620 { char pad0[0x4]; int unk4; char pad1[0x4]; int unkC; int unk10; int unk14; int unk18; int unk1C; };

extern "C" {
extern int D_003689E0;
void func_00119730(void);
void func_001198F0(void);
void func_0011A208(void*, u32, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118E40);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118F20);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119098);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119138);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119180);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001191B0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119270);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119330);

extern "C" void func_001193F0(void) {
}

extern "C" void func_001193F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119400);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119488);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119490);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001194B8);

extern "C" int func_00119500(S_00119500* self) {
    return *self->unk190;
}

extern "C" int func_00119510(S_00119510* self) {
    return (*self->unk190)->unk38;
}

extern "C" void func_00119520(void* self) {
    func_0011A208(self, 0x08682D24 /* skaterinfoheap */, 1);
}

extern "C" void func_00119548(void* self) {
    func_0011A208(self, 0xCD4FB93F /* profilerheap */, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119570);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001195C0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119610);

extern "C" void func_00119710(void) {
    func_00119730();
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119730);

extern "C" int func_001198E8(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001198F0);

extern "C" void func_00119970(void) {
    func_001198F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119990);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119A38);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119A60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119B38);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119CC0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119D40);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119DA0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119E60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119F60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A100);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A128);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A170);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A208);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A230);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A300);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A378);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A380);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A3B0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A3E0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A410);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A440);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A470);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A498);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A520);

extern "C" void func_0011A550(int v) {
    D_003689E0 = v;
}

extern "C" void func_0011A558(void) {
}

extern "C" void func_0011A560(void) {
}

extern "C" void func_0011A568(void) {
}

extern "C" void func_0011A570(void) {
}

extern "C" void func_0011A578(void) {
}

extern "C" void func_0011A580(void) {
}

extern "C" int func_0011A588(void) {
    return 0;
}

extern "C" int func_0011A590(void) {
    return 0;
}

extern "C" void func_0011A598(void) {
}

extern "C" void func_0011A5A0(void) {
}

extern "C" void func_0011A5A8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A5B0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A5B8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A5E0);

extern "C" void func_0011A620(S_0011A620* self, int a, int b) {
    self->unk10 = 1;
    self->unk4 = a;
    self->unk14 = b;
    self->unk1C = 0;
    self->unk18 = 0;
    self->unkC = b - a;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A648);

extern "C" void func_0011A680(S_0011A680* self, S_0011A680_b* o) {
    self->unk18[(o->unk38 >> 1) & 1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A788);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A7C0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A840);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A8A8);

extern "C" int func_0011A8D0(S_0011A8D0* self) {
    return self->unkC;
}

extern "C" int func_0011A8D8(S_0011A8D8* self) {
    return self->unk14 - self->unk4;
}

extern "C" void func_0011A8E8(S_0011A8E8* self, int v) {
    self->unk10 = v;
}

extern "C" int func_0011A8F0(S_0011A8F0* self) {
    return self->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A928);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A988);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AA28);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AA58);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AB60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011ABF8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AC50);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011ACD0);

extern "C" int func_0011ACF8(S_0011ACF8* self) {
    return self->unk20;
}

extern "C" int func_0011AD00(S_0011AD00* self) {
    return self->unk2C;
}

extern "C" int func_0011AD08(S_0011AD08* self) {
    return self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AD10);

extern "C" void func_0011AD78(S_0011AD78* self, int v) {
    self->unk5C = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AD80);
