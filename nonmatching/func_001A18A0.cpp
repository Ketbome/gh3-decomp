// cflags: -funroll-loops
#include "common.h"

extern "C" {
extern int D_0032BFC8[];
int func_001A1330(int);
extern int D_0032BE38[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A1658);

extern "C" unsigned int D_0032B638[];

extern "C" int func_001A18A0(int unused, unsigned char* src, unsigned char* dst) {
    int out = 0;
    for (int i = 0; i < 4; i++) {
        int r = (i & 1) << 7;
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 4; k++) {
                unsigned int w0 = D_0032B638[r];
                unsigned int w1 = D_0032B638[r + 1];
                r += 2;
                int a = (src[w0 >> 1] & (0xF << ((w0 & 1) * 4))) >> ((w0 & 1) * 4);
                unsigned char b = (src[w1 >> 1] & (0xF << ((w1 & 1) * 4))) >> ((w1 & 1) * 4);
                dst[out++] = a | ((b << 4) & ~0xF);
            }
        }
        src += 0x40;
    }
    return 0;
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A3488);

INCLUDE_ASM("asm/nonmatchings/game/t_1A1658", func_001A35B8);
