#include "common.h"

struct S002754A0 {
    char pad[0x4];
    int unk4;
    char pad1[0xF0];
    int unkF8;
    int unkFC;
};

extern "C" {
extern int D_003710A0;
extern char D_00359058[];
void func_0011A470(void);
void func_00275A40(void);
void func_00275DE0(void);
void func_00275F08(int, int);
void func_00276110(void);
void func_002762F0(void);
void func_002763E0(void);
void func_002764E8(void);
void func_00276600(int, int);
void func_00276D68(void);
}

extern "C" void func_002754A0(S002754A0* p, int v) {
    p->unkF8 = v;
    p->unkFC = 0;
}

extern "C" void func_002754B0(S002754A0* p) {
    p->unk4 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002754C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275510);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275540);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275570);

extern "C" void* func_002755E0(void) {
    return D_00359058;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002755F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275610);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275648);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275660);

extern "C" int func_00275688(void) {
    return 0;
}

extern "C" int func_00275690(void) {
    return 0;
}

extern "C" void func_00275698(void) {
}

extern "C" void func_002756A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002756A8);

extern "C" void func_00275730(void) {
    func_0011A470();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275750);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275780);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002757D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275830);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275868);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275898);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275978);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275988);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002759E8);

extern "C" void func_002759F0(int v) {
    D_003710A0 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002759F8);

extern "C" void func_00275A20(void) {
    func_00275A40();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275A40);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275A90);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275CE8);

extern "C" void func_00275DC0(void) {
    func_00275DE0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275DE0);

extern "C" void func_00275EE8(int a, int b) {
    func_00275F08(a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276008);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002760D8);

extern "C" void func_002760E0(void) {
    func_00276110();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276100);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276110);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002761F8);

extern "C" void func_002762D0(void) {
    func_002762F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002762F0);

extern "C" void func_002763C0(void) {
    func_002763E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002763E0);

extern "C" void func_002764C8(void) {
    func_002764E8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002764E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002765D0);

extern "C" void func_002765E0(int a, int b) {
    func_00276600(a, b);
}

extern "C" void func_00276600(int a, int b) {
    func_00275F08(a, b != 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276620);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276668);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276698);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276720);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002767D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002769A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276BB0);

extern "C" void func_00276D48(void) {
    func_00276D68();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276D68);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276E70);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276E88);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276F30);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276FD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277080);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277128);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002771D0);

extern "C" void func_00277208(void) {
}
TEXT_PAD(16);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277220);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277298);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277368);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277378);
