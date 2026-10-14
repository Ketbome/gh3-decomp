#include "common.h"

extern "C" {
extern void* D_00372C34[] __attribute__((section(".sdata")));
extern void* D_0036CBC0[] __attribute__((section(".sdata")));
void func_001B1EB0(void* p);
void func_001BF408(void* p);
extern s32 D_0036C7E8;
extern s32 D_0036CAC8;
extern s32 D_00372C30;
extern s32 D_0036CACC;
extern s32 D_0036CAD4;
extern char* D_00373270;
extern char* D_0037327C;
void func_0019E048(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0019E318(s32 a, s32 b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B93E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B95F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9C60);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9D78);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9E90);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA110);

extern "C" void func_001BA6D8(void) {
    char* p = D_00373270;
    D_0037327C = p;
    *(u32*)p = 0x10000005;
    *(u32*)(p + 4) = 0;
    D_00373270 = p + 8;
    *(u32*)(p + 8) = 0x11000000;
    D_00373270 = p + 0xC;
    *(u32*)(p + 0xC) = 0x50000002;
    D_00373270 = p + 0x10;
    func_0019E048(0xE, 1, 0, 0, 0, 1, 1);
    func_0019E318(0xF, 0);
    char* q = D_00373270;
    *(u32*)q = 0x13000000;
    D_00373270 = q + 4;
    *(u32*)(q + 4) = 0;
    D_00373270 = q + 8;
    *(u32*)(q + 8) = 0;
    D_00373270 = q + 0xC;
    *(u32*)(q + 0xC) = 0;
    D_00373270 = q + 0x10;
    func_0019E048(0xE, 1, 0, 0, 0, 1, 1);
    func_0019E318(0x3F, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA7E8);

GP_DATA(D_0036CAC8);
extern "C" void func_001BB050(void) {
    D_0036CAC8 = 1;
    D_00372C30 = D_0036C7E8;
}

extern "C" void func_001BB068(void) {
    D_0036CACC = 1;
}

struct N1B { char pad0[0x19C]; N1B* unk19C; };
struct M1B { char pad0[0x2C]; M1B* unk2C; };
extern "C" void func_001B1E38(void*);
extern "C" void func_001BF358(void*);

GP_DATA(D_0036CACC);
extern "C" void func_001BB078(void) {
    if (D_0036CACC) {
        func_001BB050();
        N1B* n = (N1B*)D_00372C34[0];
        if (n) {
            do {
                func_001B1E38(n);
                n = n->unk19C;
            } while (n);
        }
        M1B* m = (M1B*)D_0036CBC0[0];
        if (m) {
            do {
                func_001BF358(m);
                m = m->unk2C;
            } while (m);
        }
        D_0036CACC = 0;
        D_0036CAC8 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB100);

extern "C" void func_001BB180(void) {
    D_0036CAD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB188);
