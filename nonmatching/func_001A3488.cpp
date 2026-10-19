#include "common.h"

extern "C" {
extern int D_0032BFC8[];
int func_001A1330(int);
extern int D_0032BE38[];
int func_001A4258(void*, int, void*);
extern int* D_00373270;
extern int D_00373284;
extern int D_00373288;
extern int D_00373298;
extern char D_3F0[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1658);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A18A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1A18);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A21A8);

extern "C" int func_001A2868(int a, int b, int c) {
    int i = func_001A1330(b) - 1;
    int j = func_001A1330(c) - 1;
    return *(int*)((i * 4 + (char*)D_0032BE38) + j * 0x28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A28C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A2D28);

extern "C" int func_001A3178(int a, int b, int c) {
    int i = func_001A1330(b) - 1;
    int j = func_001A1330(c) - 1;
    return *(int*)((i * 4 + (char*)D_0032BFC8) + j * 0x28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A31D8);

extern "C" void func_001A3488(unsigned char* a, int b) {
    D_00373284 = 0;
    int* save = D_00373270;
    D_00373270 = (int*)a;
    int* t6 = (int*)a + 2;
    int c = b | 1;
    *(int*)a = 0x20000000;
    D_00373270 = (int*)a + 1;
    *(int*)(a + 4) = 0;
    D_00373270 = t6;
    a[1] = c;
    a[0] = func_001A4258(a, c, t6);
    int* p = D_00373270;
    p[0] = 0x01000101;
    D_00373270 = p + 1;
    int* q = p + 2;
    D_00373298 = 1;
    int t3 = (a[0] + 1) & 0xFF;
    p[1] = (t3 << 16) | 0x6C000000 | ((*(unsigned short*)&D_00373284 & 0x3FF) | 0xC000);
    D_00373270 = q;
    D_00373288 = t3;
    int t2 = a[0];
    float fl = 1.1920929e-07f;
    p[2] = *(int*)&fl | t2;
    q[3] = t2;
    q[1] = ((unsigned)D_3F0 >> 3) | 0x10000000;
    q[2] = 0xF;
    D_00373270 = save;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A35B8);
