// cflags: -funroll-loops
#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S00199370 {
    char pad[0x14];
    VEntry* unk14;
};

struct S00199BF0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    s8 unk18;
};

typedef unsigned int u128_199 __attribute__((mode(TI)));
struct S199_V { char pad0[0x14]; void* unk14; };
struct S199_A { u128_199 d[0x4D2]; };
struct S199_B { u128_199 d[0x8]; };
struct S199_C { u128_199 d[0x7]; };
struct S199_M { int m[16]; };
struct S199_K { u8 c[4]; };
struct S199_F { float unk0; float unk4; float unk8; float unkC; float unk10; float unk14; char pad18[0x8]; };

struct N199 { N199* c[16]; };


extern "C" {
extern int D_00368A38;
extern u8 D_003403C0[];
void func_00119400(int, void*);
void* func_00118F20(int, int, int, int);
S199_A* func_001707C0(void*);
S199_B* func_00171540(void*);
S199_C* func_00171E60(void*);
extern s16 D_0036C0CE;
extern s16 D_0036C0CC;
extern char* D_0036C0C8;
extern int* D_0036C0C4;
void* func_0011A520(int, int);
void func_0019A088(int, S199_K*, int, int, int);
void func_0019A320(int, S199_K*, int, int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001992F8);

extern "C" int func_00199368(void) {
    return 1;
}

extern "C" int func_00199370(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199398(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001993D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001994A0);

extern "C" S199_A* func_00199960(S199_A* self) {
    S199_A* p = func_001707C0(func_00118F20(D_00368A38, 0x4D20, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_001999C8(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_001999F0(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

extern "C" S199_B* func_00199A30(S199_B* self) {
    S199_B* p = func_00171540(func_00118F20(D_00368A38, 0x80, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_00199A98(void) {
    return 1;
}

extern "C" int func_00199AA0(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199AC8(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

extern "C" S199_C* func_00199B08(S199_C* self) {
    S199_C* p = func_00171E60(func_00118F20(D_00368A38, 0x70, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_00199B78(void) {
    return 1;
}

extern "C" int func_00199B80(void) {
    return 1;
}

extern "C" int func_00199B88(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199BB0(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

extern "C" S00199BF0* func_00199BF0(S00199BF0* self) {
    self->unk18 = 0;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

extern "C" S199_M* func_00199C18(S199_M* self) {
    for (int i = 0; i < 16; i++) {
        self->m[i] = 0;
    }
    return self;
}

GP_DATA(D_0036C0CE);
GP_DATA(D_0036C0CC);
GP_DATA(D_0036C0C8);
extern "C" void* func_00199C60(void) {
    if (D_0036C0CE) {
        if (D_0036C0CC < D_0036C0CE) {
            return D_0036C0C8 + D_0036C0CC++ * 64;
        }
        return 0;
    }
    return func_0011A520(1, 0x40);
}

GP_DATA(D_0036C0C4);
INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199CB8);

extern "C" int func_00199D28(int i) {
    return (i + 1) & 0xF;
}

extern "C" int func_00199D38(S199_M* tbl, int start) {
    int i = start;
    do {
        i = func_00199D28(i);
        if (tbl->m[i]) {
            return i;
        }
    } while (i != start);
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199D90);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A088);

extern "C" void func_0019A2E0(int a, int b, int c) {
    S199_K k;
    k.c[0] = 0;
    k.c[1] = 0;
    k.c[2] = 0;
    k.c[3] = 0;
    func_0019A088(b, &k, 5, c, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A320);

extern "C" S00199BF0* func_0019A5D8(S00199BF0* self, int a, int b) {
    S199_K k;
    k.c[0] = 0;
    k.c[1] = 0;
    k.c[2] = 0;
    k.c[3] = 0;
    func_00199BF0(self);
    func_0019A320(a, &k, 5, b, self);
    return self;
}

extern "C" float func_0019A640(int a, int b) {
    S199_F f;
    func_0019A5D8((S00199BF0*)&f, a, b);
    return f.unk14 - (f.unk4 * f.unk4 + f.unk8 * f.unk8 + f.unkC * f.unkC + f.unk10 * f.unk10) / f.unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AC40);

extern "C" int func_0019AE30(N199* n, int depth) {
    int c = 0;
    if (n) {
        if (depth > 0) {
            for (int i = 0; i < 16; i++) {
                c += func_0019AE30(n->c[i], depth - 1);
            }
        } else {
            c = 1;
        }
    }
    return c;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AF18);
