#include "common.h"

struct S0026DFE8 {
    int unk0;
    int unk4;
};

struct S0026D660 {
    char pad[0xC88];
    u64 unkC88;
    u64 unkC90;
};

extern "C" {
extern int D_00370C14;
void func_00273498(void);
void func_0026E0B8(void);
extern S0026D660 D_003A66F0;
int func_002741F8(int, int);
int func_0026E1B0(int, int);
extern int D_00370C18;
void func_00273070(void);
int func_0026E5C8(int, int);
extern int D_00370CB8;
void func_0026DFE8(S0026DFE8 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D280);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D480);

extern "C" void func_0026D660(u64* a, u64* b) {
    *a = D_003A66F0.unkC88;
    *b = D_003A66F0.unkC90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D680);

extern "C" void func_0026D688(void) {
    if (D_00370C18 == 1) {
        func_00273070();
    }
}

extern "C" void func_0026D6B0(void) {
    func_00273498();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D9F8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DAB0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC20);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC60);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC68);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC98);

extern "C" int func_0026DCA0(int a) {
    return func_002741F8(a, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DD48);

extern "C" int func_0026DE20(void) {
    return D_00370C14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DE28);

extern "C" S0026DFE8 *func_0026DFC0(S0026DFE8 *p) {
    func_0026DFE8(p);
    return p;
}

extern "C" void func_0026DFE8(S0026DFE8* p) {
    p->unk0 = 0;
    p->unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DFF8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E008);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E0B8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E0E8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E138);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E158);

extern "C" void func_0026E190(void) {
    func_0026E0B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E1B0);

extern "C" void func_0026E1E8(void) {
    func_0026E1B0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E208);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E470);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E560);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E638);

extern "C" void func_0026E890(int a) {
    D_00370CB8 = func_0026E5C8(D_00370CB8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E8B8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EB08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EC08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026ED98);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EED8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026F158);
