#include "common.h"

extern "C" {
extern u32 D_0036CAE0;
extern s32 D_0036CAE4;
void func_001BD178(void* p);
s32 func_001BD150(s32 a, s32 b);
}

typedef unsigned int u128_1BB __attribute__((mode(TI)));

extern "C" {
extern char* D_00373270;
extern char* D_0037327C;
extern u16 D_00373284;
extern s32 D_00373288;
extern s32 D_00373294;
extern s32 D_003732FC;
extern s32 D_0036CAD4;
void func_0019BE48(s32 a);
s32 func_001B1970(void* p);
void func_001BB188(void* p, u128_1BB c, s32 ls, s32 flag);
}

GP_DATA(D_0036CAD4);
extern "C" void func_001BB500(char* p, s32 prev, u128_1BB c) {
    s32 ls = *(s32*)(p + 0x70);
    if (ls != 0) {
        s32 g = D_003732FC;
        if (D_00373294 != g) {
            func_0019BE48(g);
        }
        s32 n = *(s32*)(p + 0x6C);
        if (n >= 0x47) n = 0x46;
        s32 v = func_001B1970(p);
        s32 rem = n;
        if (D_0036CAD4 != v) {
            D_0036CAD4 = v;
            if (n > 0) {
                s32 cnt = 0;
                s32 addr = v;
                s32 k = 5;
                do {
                    s32 m = rem < 0x40 ? rem : 0x3F;
                    char* pkt = D_00373270;
                    s32 m4 = m << 2;
                    cnt += 0x3F;
                    D_0037327C = pkt;
                    *(u32*)pkt = m4 | 0x30000000;
                    *(s32*)(pkt + 4) = addr;
                    D_00373270 = pkt + 8;
                    m4 &= 0xFF;
                    *(u32*)(pkt + 8) = 0x11000000;
                    D_00373270 = pkt + 0xC;
                    *(u32*)(pkt + 0xC) = (m4 << 16) | 0x6C000000 | ((D_00373284 + k) & 0x3FF);
                    rem -= m;
                    addr += 0xFC0;
                    k += 0xFC;
                    D_00373270 = pkt + 0x10;
                    D_00373288 = m4;
                } while (cnt < n);
            }
        }
        func_001BB188(p, c, ls, n != 0);
        if (D_00373294 != prev) {
            func_0019BE48(prev);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BB680);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BCD88);

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD120);

GP_DATA(D_0036CAE4);
extern "C" void func_001BD128(void) {
    D_0036CAE4 = 0;
    D_0036CAE0 = 0xFFFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD140);

extern "C" s32 func_001BD150(s32 a, s32 b) {
    return 0xFFFF;
}

extern "C" void func_001BD158(void) {
    func_001BD150(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD178);

extern "C" void func_001BD438(void* p) {
    func_001BD178(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BB500", func_001BD458);
