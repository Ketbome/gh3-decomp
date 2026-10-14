#include "common.h"

struct S1E6920_L {
    S1E6920_L* unk0;
    S1E6920_L* unk4;
};

struct S1E6920 {
    s32 unk0;
    S1E6920_L unk4;
};

struct S1E5E90_S {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
};

struct S1E5E90 {
    char pad0[0x10];
    S1E5E90_S unk10;
};

extern "C" {
extern s32 D_00371038;
extern s32 D_00371238;
extern s32 D_00370FB8;
extern void (*D_0036DA4C)(void);
s32 func_001E65A8(void);
s32 func_001E65B0(void);
s32 func_001E65B8(void);
void func_001E5E90(s32 a, s32 b);
extern S1E6920 D_0038ED60;
extern u32 D_00372DC0;
extern s32 D_00372DB8;
extern S1E5E90 D_0038EC50;
void func_001E64A0(void);
void func_001E64B8(void);
void func_001E64D0(void);
s32 func_001E64E8(void);
s32 func_001E6510(void);
s32 func_001E6538(void);
void func_001E6560(void);
void func_001E6578(void);
void func_001E6590(void);
void* Heap_Alloc(s32, s32, s32, s32);
void* func_0011C130(void*, int, s32, s32, int, int);
void func_0011C248(void*, int);
extern void* D_00371028[] __attribute__((section(".sdata")));
extern s32 D_00371030[] __attribute__((section(".sdata")));
extern void* D_00371228[] __attribute__((section(".sdata")));
extern s32 D_00371230[] __attribute__((section(".sdata")));
extern void* D_00370FA8[] __attribute__((section(".sdata")));
extern s32 D_00370FB0[] __attribute__((section(".sdata")));
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E4E10);

struct S1E50 { s32 unk0; char pad4[0x10]; s32 unk14; };

extern "C" {
void func_001E2FF0(void*);
void func_001E3048(void*, int);
void* func_001E4780(void*, int, int);
void func_001E48C0(void*);
void func_001E4E10(void*, int);
void func_001E75A8(void*, int);
S1E50* func_001218A0(s32, int, int);
extern s32 D_00368E48[] __attribute__((section(".sdata")));
}

extern "C" s32 func_001E5050(int a, int b) {
    char stk[0x30];
    func_001E2FF0(stk);
    s32 r = 1;
    S1E50* o = (S1E50*)func_001E4780(Heap_Alloc(D_00368A38[0], 0x84, 1, 0), a, b);
    S1E50* h = func_001218A0(D_00368E48[0], 0, 0);
    if (h) {
        func_001E75A8(stk + 0x10, o->unk14);
        if (o->unk0 == 0) {
            do {
                func_001E48C0(o);
            } while (o->unk0 == 0);
        }
    } else {
        r = 0;
    }
    if (o) func_001E4E10(o, 3);
    func_001E3048(stk, 2);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5128);

GP_DATA(D_0036DA4C);
extern "C" void func_001E5C50(void) {
    D_0036DA4C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5C70);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5D98);

GP_DATA(D_00372DC0);
GP_DATA(D_00372DB8);
extern "C" void func_001E5E90(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        S1E5E90* o = &D_0038EC50;
        D_00372DC0 = 0xC6D10F83;
        S1E5E90_S* t = &o->unk10;
        t->unk60 = 0;
        t->unk64 = 0;
        t->unk68 = 0;
        D_00372DB8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5ED0);

extern "C" void func_001E5F38(void) {
    func_001E5E90(1, 0xFFFF);
}

extern "C" s32 func_001E5F58(void) {
    func_001E64A0();
    func_001E64B8();
    func_001E64D0();
    if (func_001E64E8() != 0 && func_001E6510() != 0 && func_001E6538() != 0) {
        return 1;
    }
    func_001E6560();
    func_001E6578();
    func_001E6590();
    return 0;
}

extern "C" s32 func_001E5FD0(void) {
    if (func_001E65A8() != 0 || func_001E65B0() != 0 || func_001E65B8() != 0) {
        func_001E6560();
        func_001E6578();
        func_001E6590();
        return 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6030);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E62A0);

extern "C" void func_001E64A0(void) {
    D_00371038++;
}

extern "C" void func_001E64B8(void) {
    D_00371238++;
}

extern "C" void func_001E64D0(void) {
    D_00370FB8++;
}

extern "C" s32 func_001E64E8(void) {
    return D_00371028[D_00371038] != 0;
}

extern "C" s32 func_001E6510(void) {
    return D_00371228[D_00371238] != 0;
}

extern "C" s32 func_001E6538(void) {
    return D_00370FA8[D_00370FB8] != 0;
}

extern "C" void func_001E6560(void) {
    D_00371038--;
}

extern "C" void func_001E6578(void) {
    D_00371238--;
}

extern "C" void func_001E6590(void) {
    D_00370FB8--;
}

extern "C" s32 func_001E65A8(void) {
    return D_00371038;
}

extern "C" s32 func_001E65B0(void) {
    return D_00371238;
}

extern "C" s32 func_001E65B8(void) {
    return D_00370FB8;
}

extern "C" void func_001E65C0(s32 a, s32 b) {
    void** slot = &D_00371028[D_00371038];
    *slot = func_0011C130(Heap_Alloc(D_00368A38[0], 0x70, 1, 0), 0x10, a, b, 1, 0);
    D_00371030[D_00371038] = 1;
}

extern "C" void func_001E6668(s32 a, s32 b) {
    void** slot = &D_00371228[D_00371238];
    *slot = func_0011C130(Heap_Alloc(D_00368A38[0], 0x70, 1, 0), 0x8, a, b, 1, 0);
    D_00371230[D_00371238] = 1;
}

extern "C" void func_001E6710(s32 a, s32 b) {
    void** slot = &D_00370FA8[D_00370FB8];
    *slot = func_0011C130(Heap_Alloc(D_00368A38[0], 0x70, 1, 0), 0x10, a, b, 1, 0);
    D_00370FB0[D_00370FB8] = 1;
}

extern "C" void func_001E67B8(void) {
    void* o = D_00371028[D_00371038];
    if (o) {
        if (D_00371030[D_00371038]) func_0011C248(o, 3);
        D_00371028[D_00371038] = 0;
    }
}

extern "C" void func_001E6830(void) {
    void* o = D_00371228[D_00371238];
    if (o) {
        if (D_00371230[D_00371238]) func_0011C248(o, 3);
        D_00371228[D_00371238] = 0;
    }
}

extern "C" void func_001E68A8(void) {
    s32 i = D_00370FB8;
    void* p = D_00370FA8[i];
    if (p != 0) {
        if (D_00370FB0[i] != 0) {
            func_0011C248(p, 3);
        }
        D_00370FA8[D_00370FB8] = 0;
    }
}

extern "C" void func_001E6920(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        S1E6920* o = &D_0038ED60;
        S1E6920_L* h = &o->unk4;
        h->unk0 = h;
        h->unk4 = h;
    }
}

extern "C" void func_001E6950(void) {
    func_001E6920(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6970);
