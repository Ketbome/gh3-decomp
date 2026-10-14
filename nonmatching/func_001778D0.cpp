#include "common.h"

extern "C" {
void func_001773F8(void*, int, int, float, int, int);
int func_00172CC0(void*, u32, int);
int func_0027D268(int, u32, void*, int);
int func_0027D400(int, u32, void*, int);
int func_0027D470(int, u32, void*, int);
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003417B0[];
void func_00172CC8(void);
}


struct S176C78 { char pad0[0x20]; float unk20; char pad24[0xC]; int unk30; };

extern "C" int func_00176C78(S176C78* self, u32 key, int p) {
    int a;
    int b;
    float f;
    int c;
    float g;
    switch (key) {
    case 0x167F93A5:
        func_0027D400(p, 0x48C1A123, &a, 1);
        b = 0;
        func_0027D400(p, 0x7031F10C, &b, 0);
        f = -1.0f;
        func_0027D268(p, 0xBF237659, &f, 0);
        c = 0;
        func_0027D470(p, 0x326C4FF5, &c, 0);
        func_001773F8(self, a, b, f, c, 0);
        return 1;
    case 0x36ADB38E:
        func_0027D268(p, 0, &g, 1);
        self->unk20 = g;
        return 1;
    case 0x290D266C:
        self->unk30 = 1;
        return 1;
    default:
        return func_00172CC0(self, key, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176DC0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176FE0);

extern "C" void func_001773F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001773F8);

extern "C" u32 func_00177828(void) {
    return 0xF221474C /* linear */;
}

extern "C" void func_00177838(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" float func_00177878(float v) {
    return v;
}

extern "C" u32 func_00177880(void) {
    return 0xF1B82F5A /* degenerateblend */;
}

extern "C" void func_00177890(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

struct P1778D0 { int unk0; int unk4; int unk8; };
extern "C" int func_0027D870_c(int, int, int*, int) __asm__("func_0027D870");

extern "C" void func_001778D0(int self, P1778D0* p) {
    int v0;
    int v1;
    int ok;
    int* cur;
    int* dst = (int*)(self + 0x1C);
    if (func_0027D268(p->unk0, 0x921842C2, dst, 0) == 0) {
    cur = &v0;
    if ((func_0027D870_c(p->unk0, 0x921842C2, &v0, 0) ^ 1) != 0) {
        ok = 0;
    } else {
        for (;;) {
            if (p->unk8 != 0 && (func_0027D870_c(p->unk8, *cur, &v1, 0) ^ 1) == 0) {
                *cur = v1;
                continue;
            }
            if (p->unk4 != 0 && (func_0027D870_c(p->unk4, *cur, &v1, 0) ^ 1) == 0) {
                *cur = v1;
                continue;
            }
            ok = 1;
            break;
        }
    }
    if (!(!ok)) {
        if (p->unk8 == 0 || func_0027D268(p->unk8, v0, dst, 0) == 0) {
            if (p->unk4 != 0) func_0027D268(p->unk4, v0, dst, 0);
        }
    }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001779F0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177FB0);

extern "C" void func_001785C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001785D0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178860);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178880);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178910);

extern "C" void func_00178920(void) {
    func_00172CC8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178940);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178AB0);
