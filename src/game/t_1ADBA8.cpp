#include "common.h"

extern "C" {
s32 func_0019BF20(void* p);
void func_0019CCF8(void* p, s32 d);
s32 func_001ACD28(void* p);
extern s32 D_00372C1C;
void func_0019CD18(void* p, s32 d);
extern s32 D_00372C20;
}

struct T1AEF {
    char pad0[0x20];
    T1AEF* unk20;
    char pad24[4];
    T1AEF* unk28;
};

struct S001AFAC8 {
    char pad0[0x1C];
    u32 unk1C;
    char pad20[0x14];
    f32* unk34;
};

struct T1ADB {
    char pad0[0x20];
    T1ADB* unk20;
    char pad24[4];
    T1ADB* unk28;
    char pad2C[0xC];
    void* unk38;
    char pad3C[0x10];
    s32 unk4C;
};

extern "C" {
void func_0019ECE8(void);
s32 func_001A9A98(void* p, char* q);
void func_001A9B08(void* p, char* q);
void func_001A0380(s32 p, s32 f);
void Heap_Free(s32 h, void* p);
extern char D_0038C9A0[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

extern "C" void func_001ADBA8(T1ADB* p, s32 a) {
    func_0019ECE8();
    if (a != 0) {
        if (func_001A9A98(p, D_0038C9A0) == 0) {
            func_001A9B08(p, D_0038C9A0);
        }
    }
    if (func_001ACD28(p) != 0) {
        if (p->unk20 != 0) {
            Heap_Free(D_00368A38[0], p->unk20);
        }
        if (p->unk38 != 0) {
            Heap_Free(D_00368A38[0], p->unk38);
        }
    } else {
        T1ADB* c = p->unk20;
        while (c != 0) {
            T1ADB* n = c;
            c = c->unk28;
            func_001ADBA8(n, 0);
        }
    }
    if (p != 0) {
        if (p->unk4C != 0) {
            func_001A0380(p->unk4C, 3);
        }
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADC90);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADF60);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE1D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE520);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE7A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AEB80);

GP_DATA(D_00372C1C);
extern "C" void func_001AEFF0(T1AEF* p, s32 dst, s32 first) {
    if (first != 0) {
        D_00372C1C = 0;
    }
    if (func_001ACD28(p) != 0) {
        s32 n = func_0019BF20(p->unk20);
        func_0019CCF8(p->unk20, dst + D_00372C1C * 4);
        D_00372C1C += n;
    } else {
        T1AEF* c = p->unk20;
        if (c != 0) {
            do {
                func_001AEFF0(c, dst, 0);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

GP_DATA(D_00372C20);
extern "C" void func_001AF090(T1AEF* p, s32 dst, s32 first) {
    if (first != 0) {
        D_00372C20 = 0;
    }
    if (func_001ACD28(p) != 0) {
        s32 n = func_0019BF20(p->unk20);
        func_0019CD18(p->unk20, dst + D_00372C20 * 4);
        D_00372C20 += n;
    } else {
        T1AEF* c = p->unk20;
        if (c != 0) {
            do {
                func_001AF090(c, dst, 0);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF130);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF608);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF7C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF990);

extern "C" void func_001AFAC8(S001AFAC8* p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    p->unk34[0] = a;
    p->unk34[1] = e;
    p->unk34[2] = c;
    p->unk34[3] = g;
    p->unk34[4] = b;
    p->unk34[5] = f;
    p->unk34[6] = d;
    p->unk34[7] = h;
}

extern "C" void func_001AFB10(S001AFAC8* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x10000 : p->unk1C & ~0x10000;
}

extern "C" void func_001AFB40(S001AFAC8* p, f32 a, f32 b) {
    p->unk34[8] = a;
    p->unk34[9] = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AFB58);
