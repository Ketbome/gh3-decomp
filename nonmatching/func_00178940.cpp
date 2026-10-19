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

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001778D0);

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

struct A178 { char pad0[0x18]; float unk18; };
struct P178 { int unk0; int unk4; int unk8; };
extern "C" {
int func_0027D268_b(int, u32, void*, int) __asm__("func_0027D268");
int func_0027D870_b(int, u32, int*, int) __asm__("func_0027D870");
}

extern "C" void func_00178940(A178* self, P178* p) {
    int sp0, sp4;
    int* ps = &sp0;
    self->unk18 = 3.1415927f;
    float* pf = &self->unk18;
    int ok;
    if (func_0027D268_b(p->unk0, 0xFF7EBAF6, pf, 0) != 0) {
        ok = 1;
    } else {
        int found;
        if ((func_0027D870_b(p->unk0, 0xFF7EBAF6, ps, 0) ^ 1) != 0) {
            found = 0;
        } else {
            for (;;) {
                int t = p->unk8;
                if (t && (func_0027D870_b(t, *ps, &sp4, 0) ^ 1) == 0) {
                    *ps = sp4;
                    continue;
                }
                int t2 = p->unk4;
                if (t2 && (func_0027D870_b(t2, *ps, &sp4, 0) ^ 1) == 0) {
                    *ps = sp4;
                    continue;
                }
                found = 1;
                break;
            }
        }
        ok = 0;
        if ((found ^ 1) == 0) {
            int r = 0;
            int t3 = p->unk8;
            if (t3 && func_0027D268_b(t3, sp0, pf, 0) != 0) {
                r = 1;
            } else {
                int t4 = p->unk4;
                if (t4 && func_0027D268_b(t4, sp0, pf, 0) != 0) r = 1;
            }
            ok = r;
        }
    }
    if (ok) self->unk18 = self->unk18 * 0.017453294f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178AB0);
