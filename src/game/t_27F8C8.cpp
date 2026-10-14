#include "common.h"

extern "C" {
extern int D_00368A38;
int func_0027FAC8(int, int, int, int, int);
int func_0027F1E8(int, int, int);
void func_0011A470(int);
int func_0011A380(int);
int func_00119610(int, int);
void func_001194B8(int);
void func_00119490(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F8C8);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F938);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F9B0);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FA40);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FAC8);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FCD8);

extern "C" int func_0027FDF8(int a, int n) {
    int h = D_00368A38;
    int buf;
    int r;
    func_00119490(h, func_00119610(h, 0));
    buf = func_0011A380(n);
    r = func_0027FAC8(a, buf, n, 1, 0);
    func_0011A470(buf);
    func_001194B8(D_00368A38);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FE88);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_00280380);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_00280D08);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_002811F0);
