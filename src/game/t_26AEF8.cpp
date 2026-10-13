#include "common.h"

extern "C" {
extern int D_00370C24;
extern char D_003A66F0[];
void func_0026AEA8(int);
extern int D_00368748;
extern int D_00370C30;
int func_0026ABA8(void);
void func_0026AE70(void);
extern int D_00370C18;
void func_00273B80(int);
int func_0026ABB0(void);
extern int D_00370C34;
extern int D_00370C28;
extern int D_00370C50;
extern f32 D_00370C1C;
extern f32 D_00370C20;
}

extern "C" void func_0026AEF8(void) {
    if (func_0026ABB0() == 0) {
        func_00273B80(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026AF28);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B150);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B158);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B1B0);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B208);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B628);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B768);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B770);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BA48);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BC98);

GP_DATA(D_00370C50);
extern "C" int func_0026BCA0(void) {
    return D_00370C50 >= 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BCB0);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BD80);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BDF8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BE00);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C110);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C120);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C250);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C3D8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C5A0);

GP_DATA(D_00370C30);
extern "C" int func_0026C5A8(void) {
    if (D_00368748 != 0) {
        if (D_00370C30 == 0) {
            return 0;
        }
        func_0026AE70();
        func_0026AEA8(-1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C5E8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C738);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C7A8);

extern "C" int func_0026C870(void) {
    return D_00370C34;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C878);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C940);

extern "C" f32 func_0026C9E0(void) {
    return D_00370C1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C9E8);

extern "C" f32 func_0026CA70(void) {
    return D_00370C20;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026CA78);

extern "C" void func_0026CBE8(int a) {
    if (func_0026ABA8() == 0) {
        char *p = D_003A66F0 + a * 0xCB0;
        *(int *)(p + 0xCA8) = 1;
        *(int *)(p + 0xC80) = 0;
        *(u64 *)(p + 0xC88) = 0;
        *(u64 *)(p + 0xC90) = 0;
        *(u64 *)(p + 0xC98) = 0;
        *(u64 *)(p + 0xCA0) = 0;
    }
}

GP_DATA(D_00370C18);
extern "C" void func_0026CC48(void) {
    if (func_0026ABA8() == 0 && D_00370C18 == 0) {
        func_0026AE70();
    }
}

GP_DATA(D_00370C24);
extern "C" void func_0026CC80(int a) {
    if (func_0026ABA8() == 0) {
        D_00370C24 = a != 0;
        char *p = D_003A66F0 + D_00370C18 * 0xCB0;
        *(u64 *)(p + 0xC98) = 0;
        *(u64 *)(p + 0xCA0) = 0;
    }
}

extern "C" void func_0026CCD8(int v) {
    D_00370C28 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026CCE0);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026CD30);
