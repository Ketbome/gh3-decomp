#include "common.h"

struct S002606A0 {
    char pad[0xA0];
    int unkA0;
};

struct S00261B58 {
    char pad[0x23C];
    int unk23C;
};

struct S00260710 {
    char pad[0x18];
    int unk18;
};

struct S00261C98_2 {
    struct S00261C98_2* unk0;
    struct S00261C98_2* unk4;
};

struct S00261C98 {
    int unk0;
    S00261C98_2 unk4;
};

extern "C" {
extern int D_00368748;
extern int D_00368750;
extern int D_003706D8;
extern void* D_0036F658[] __attribute__((section(".sdata")));
extern void* D_00368A38[] __attribute__((section(".sdata")));
extern int D_00368768[] __attribute__((section(".sdata")));
int func_00289CF8(int);
void func_00261C98(int, int);
extern u64 D_003706C8;
void func_00317298(u64);
extern int D_003717E0[] __attribute__((section(".sdata")));
void func_00296550(int);
extern int D_00372580[] __attribute__((section(".sdata")));
void func_001CA9B0(int);
u64 func_00317588(void);
extern u64 D_003706D0;
extern S00261C98 D_0039A3C8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260658);

extern "C" int func_002606A0(void) {
    return ((S002606A0*)D_0036F658[0])->unkA0 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002606B8);

extern "C" int func_00260710(void) {
    ((S00260710*)D_0036F658[0])->unk18--;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260730);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260778);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260800);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260828);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002608C0);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260910);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260950);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002609A8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002609E0);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260A18);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260A58);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260B00);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260C30);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260CA8);

extern "C" int func_00260D00(void) {
    return 1;
}

extern "C" void func_00260D08(void) {
    func_00317298(D_003706C8);
}

extern "C" void func_00260D28(void) {
    u64 r = func_00317588();
    D_003706D8 = 0;
    D_003706C8 = r;
    D_003706D0 = r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260D50);

extern "C" void func_00260D88(void) {
    D_003706D8 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260D98);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260E30);

extern "C" int func_00260F20(int a, int b) {
    func_00289CF8(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00260F40);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261090);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002610C0);

extern "C" int func_00261158(void) {
    func_001CA9B0(D_00372580[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261180);

extern "C" void func_00261348(void) {
    func_00296550(D_003717E0[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261370);

extern "C" int func_002613F0(void) {
    return 0;
}

extern "C" int func_002613F8(void) {
    return 0;
}

extern "C" int func_00261400(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261408);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002614A0);

extern "C" int func_002614E0(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002614E8);

extern "C" int func_002616C8(void) {
    return 1;
}

extern "C" int func_002616D0(void) {
    return D_00368748;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002616D8);

extern "C" int func_002616E8(void) {
    return D_00368750;
}

extern "C" int func_002616F0(void) {
    return 0;
}

extern "C" int func_002616F8(void) {
    return D_00368768[0] == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261708);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261790);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261938);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261A48);

extern "C" int func_00261B58(void) {
    return ((S00261B58*)D_00368A38[0])->unk23C != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261B70);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261C90);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261C98);

extern "C" void func_00261CC8(void) {
    func_00261C98(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00261CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00262430);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_00262570);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002625B0);

INCLUDE_ASM("asm/nonmatchings/game/t_260658", func_002625F0);
