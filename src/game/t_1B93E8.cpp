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

struct O1B9E {
    char pad0[8];
    s32 unk8;
    s32 unkC;
    char pad10[0x14];
    s32 unk24;
    char pad28[4];
    O1B9E* unk2C;
    char pad30[0x1C];
    u16 unk4C;
    u16 unk4E;
    s16 unk50;
    s16 unk52;
};

extern "C" {
extern s32 D_00372D24;
extern char* D_00373324;
void func_0019E380(s32 a, void* b, s32 c, s32 d, s32 e);
}

extern "C" void func_001B9E90(void) {
    s32 n = 0;
    s32 idx = D_00372D24;
    char* base = D_00373324;
    s32 off = idx * 4;
    *(char**)(base + off + 0x10) = D_00373270;
    *(u8*)(base + idx + 0x20) = 1;
    s32 acc = *(volatile s32*)&D_0036C7E8;
    O1B9E* m = (O1B9E*)*(volatile int*)&D_0036CBC0[0];
    char* p = D_00373270;
    if (m) {
        do {
            if ((m->unk8 >> 11) & 1) {
                m->unk50 = acc;
                acc += m->unk4C;
                m->unk52 = acc;
                acc += m->unk4E;
                func_0019E380(6, (char*)m + 0x30, m->unk50, m->unk52, -1);
                if ((m->unk8 >> 9) & 1) {
                    *(u32*)p = 0x50000000;
                    *(u32*)(p + 4) = m->unkC;
                    *(u32*)(p + 8) = 0;
                    *(u32*)(p + 0xC) = 0;
                } else {
                    *(u32*)p = ((u32)(m->unk24 + 0xF) >> 4) + 0x30000000;
                    *(u32*)(p + 4) = m->unkC;
                    *(u32*)(p + 8) = 0;
                    *(u32*)(p + 0xC) = ((u32)(m->unk24 + 0xF) >> 4) | 0x50000000;
                }
                p += 0x10;
                n++;
            }
            m = m->unk2C;
        } while (m);
    }
    D_00373270 = p;
    if (n == 0) {
        s32 i2 = D_00372D24;
        char* b2 = D_00373324;
        s32 off2 = i2 * 4;
        *(s32*)(b2 + off2 + 0x10) = 0;
        *(s16*)(b2 + 0x30) = 0x7FFF;
        *(s16*)(b2 + 0x32) = 0;
    } else {
        char* b3 = D_00373324;
        *(u16*)(b3 + 0x30) = D_0036C7E8;
        *(s16*)(b3 + 0x32) = acc;
        D_0037327C = p;
        *(u32*)p = 0x60000000;
        *(u32*)(p + 4) = 0;
        D_00373270 = p + 8;
        *(u32*)(p + 8) = 0;
        D_00373270 = p + 0xC;
        *(u32*)(p + 0xC) = 0x50000002;
        D_00373270 = p + 0x10;
        func_0019E048(0xE, 1, 0, 0, 0, 1, 1);
        func_0019E318(0x3F, 0);
        u32 k = (*(u32*)D_0037327C >> 28) & 7;
        while (((u32)D_00373270 & 0xF) != 0) {
            *(u32*)D_00373270 = 0;
            D_00373270 += 4;
        }
        if (k != 3 && k != 0 && k != 4) {
            *(u16*)D_0037327C = (D_00373270 - D_0037327C - 8) >> 4;
        }
    }
}

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

extern "C" void func_001BB100(void) {
    if (D_0036CAC8) {
        N1B* n = (N1B*)D_00372C34[0];
        if (n) {
            do {
                func_001B1EB0(n);
                n = n->unk19C;
            } while (n);
        }
        M1B* m = (M1B*)D_0036CBC0[0];
        if (m) {
            do {
                func_001BF408(m);
                m = m->unk2C;
            } while (m);
        }
        D_0036CAC8 = 0;
    }
}

extern "C" void func_001BB180(void) {
    D_0036CAD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB188);
