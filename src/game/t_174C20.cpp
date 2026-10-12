#include "common.h"

struct S00175A68 {
    char pad[0x18];
    char unk18;
};

struct S00175D48 {
    char pad[0x14];
    void* unk14;
};

extern "C" {
void func_0017D6D0(void*);
void func_00172810(int);
extern u8 D_00341218[];
void func_00172A00(void*);
extern u8 D_003415B8[];
extern u8 D_00341558[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174C20);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174C48);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174C90);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174CB8);

extern "C" void func_00174CD8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174CE0);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174D08);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174E38);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174E68);

extern "C" void func_00174F68(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174F70);

extern "C" u32 func_001750A0(void) {
    return 0xA1762145 /* PLAY */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001750B0);

extern "C" u32 func_001751E0(void) {
    return 0x4F792E6C /* Cycle */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001751F0);

extern "C" u32 func_00175320(void) {
    return 0x3153E314 /* pingpong */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175330);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175460);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175560);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001755B0);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175650);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175750);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001757F0);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175830);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175930);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001759F8);

extern "C" void func_00175A68(S00175A68* self) {
    func_0017D6D0(&self->unk18);
}

extern "C" void func_00175A88(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175A90);

extern "C" u32 func_00175CB0(void) {
    return 0xA075808C /* source */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175CC0);

extern "C" void func_00175D10(void) {
}

extern "C" void func_00175D18(int a0, int a1) {
    func_00172810(a1);
}

extern "C" u32 func_00175D38(void) {
    return 0xC3D43B9A /* blank */;
}

extern "C" void func_00175D48(S00175D48* self) {
    self->unk14 = D_00341218;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175D70);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175F40);

extern "C" void func_00175FB8(void) {
}

extern "C" u32 func_00175FC0(void) {
    return 0x2CC9B571 /* difference */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176020);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176108);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001761F8);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001762D0);

extern "C" void func_00176598(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001765A0);

extern "C" void func_00176878(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176880);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001769A0);

extern "C" void func_001769C0(S00175D48* self) {
    self->unk14 = D_003415B8;
    func_00172A00(self);
}

extern "C" void func_001769E8(S00175D48* self) {
    self->unk14 = D_00341558;
    func_00172A00(self);
}

extern "C" u32 func_00176A10(void) {
    return 0x54628ED7 /* blend */;
}

extern "C" void func_00176A20(S00175D48* self) {
    self->unk14 = D_00341558;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176A48);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176B58);
