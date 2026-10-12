#include "common.h"

struct S00297458 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00296A70 {
    int unk0;
    char pad[0x28];
    int unk2C;
    int unk30;
    u8 unk34;
    char pad1[0xB];
    int unk40;
};

struct S00296A48 {
    int unk0;
    struct S00296A48* unk4;
    int unk8;
    struct S00296A48* unkC;
    struct S00296A48* unk10;
    void* unk14;
    int unk18;
};

extern "C" {
extern char D_0035C330[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296A10);

extern "C" S00296A48* func_00296A48(S00296A48* p, int b) {
    p->unk18 = b;
    p->unk4 = p;
    p->unk14 = D_0035C330;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    return p;
}

extern "C" S00296A70* func_00296A70(S00296A70* p) {
    p->unk0 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk40 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296A90);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296AF0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296B28);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296D88);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296EC0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296F18);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296F70);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002972F8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002973C0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297400);

extern "C" S00297458* func_00297458(S00297458* p) {
    p->unk0 = 0;
    p->unk4 = 5;
    p->unk8 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297470);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002974D8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297528);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297578);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002976E8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297838);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002978C0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002979D8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297A48);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297CC0);

extern "C" void func_00297CF0(void* p) {
    func_00119400(D_00368A38[0], p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297D18);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297D78);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297E38);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297E98);

extern "C" int func_00297F20(void) {
    return 1;
}

extern "C" int func_00297F28(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297F30);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297F90);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297FF0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298050);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002980B0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298110);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298170);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002981A0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002982B8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298390);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298448);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298558);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298858);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002989C8);
