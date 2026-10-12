#include "common.h"

struct S00259228 {
    char pad[0x20];
    int unk20;
};

extern "C" {
int func_0028A010(int);
int func_0028A018(int);
void func_00258E28(int, int);
int func_0027DF00(int, u32);
extern int D_00368428[] __attribute__((section(".sdata")));
void func_002592E0(void*, int, int, int);
int func_0027D470(int, int, void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258420);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258618);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258930);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258978);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258A00);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258E28);

extern "C" int func_00259228(int a, S00259228* b) {
    func_00258E28(b->unk20, a);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259250);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002592E0);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002594A0);

extern "C" int func_002594E0(void) {
    return 1;
}

extern "C" int func_002594E8(int a) {
    D_00368428[0] = func_0027DF00(a, 0x203B372);
    return 1;
}

extern "C" int func_00259518(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259520);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002596A0);

extern "C" int func_002596F8(int a, int b) {
    char buf[0x400];
    func_002592E0(buf, 0x400, a, b);
    return 1;
}

extern "C" int func_00259728(void) {
    return 1;
}

extern "C" int func_00259730(void) {
    return 1;
}

extern "C" int func_00259738(int a, int b) {
    func_0028A010(b);
    return 1;
}

extern "C" int func_00259758(int a, int b) {
    func_0028A018(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259778);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259880);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259978);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002599F8);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259A88);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259B18);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259B68);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259C88);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259DA8);

extern "C" int func_00259E10(int a) {
    int x = 0;
    return func_0027D470(a, 0, &x, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259E40);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259E88);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259F90);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259FC0);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A008);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A090);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A298);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A328);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A368);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_0025A3E0);
