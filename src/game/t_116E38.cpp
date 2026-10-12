#include "common.h"

struct S_00117F10 { char pad0[0xF8]; int unkF8; };
struct S_00118570 { char pad0[0xD4]; int unkD4; };

struct S_00117D20 { char pad0[0x1C]; void (*unk1C)(void); };

extern "C" {
extern int D_00368778;
extern u8 D_00375308[];
void func_00122DE0(void);
void func_00113F38(void);
extern int D_00368750;
extern u8 D_003687C0[];
extern u8 D_003686F0[];
void func_0030A970(u8*, int);
extern int D_003689E0;
extern int D_00373248;
void func_002EE6A0(int);
void func_002EE680(int);
}

extern "C" u8* func_00116E38(void) {
    return D_00375308;
}

extern "C" void func_00116E48(int a) {
    func_0030A970(D_00375308, a);
}

extern "C" u8* func_00116E70(void) {
    if (D_00368750) return D_003687C0;
    return D_003686F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00116E90);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00116F90);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117030);

extern "C" void func_001170A8(void) {
    func_00122DE0();
}

extern "C" void func_001170C8(int v) {
    D_00368778 = v;
}

extern "C" int func_001170D0(void) {
    return D_00368778;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001170D8);

extern "C" void func_00117108(void) {
}

extern "C" int CFunc_CreatePlatformMessageBox(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117118);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117168);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001171C0);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117270);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001172C8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117520);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001177D8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117940);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001179F8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117B50);

extern "C" void func_00117C00(void) {
    func_00113F38();
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117C20);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117C60);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117CC0);

extern "C" void func_00117D20(S_00117D20* self) {
    self->unk1C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117D40);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117E10);

extern "C" int func_00117F10(S_00117F10* self) {
    return self->unkF8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117F18);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117F50);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001180D8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118168);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118290);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118308);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118388);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001183C8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001184C0);

extern "C" void func_00118570(S_00118570* self) {
    self->unkD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118578);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118580);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118640);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118700);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118790);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118798);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001187D0);

extern "C" void func_001187F8(void) {
    if (D_003689E0) func_002EE6A0(D_00373248);
}

extern "C" void func_00118820(void) {
    if (D_003689E0) func_002EE680(D_00373248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118848);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118BD8);
