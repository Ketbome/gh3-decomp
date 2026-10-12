#include "common.h"

struct N1C {
    char pad0[0xC];
    f32 unkC;
    char pad10[0x8];
    N1C* unk18;
    N1C* unk1C;
};

struct S001C14E0 {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
};

extern "C" {
extern N1C* D_0036CBDC;
extern N1C* D_0036CBE0;
extern s32 D_00369A64;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF628);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF6F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF798);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF838);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF960);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFC58);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFCE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFD58);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFDD8);

extern "C" void func_001BFE40(N1C* n) {
    if (D_0036CBE0 == n) {
        D_0036CBE0 = n->unk1C;
    }
    if (D_0036CBDC == n) {
        D_0036CBDC = n->unk1C;
    }
    if (n->unk18 != 0) {
        n->unk18->unk1C = n->unk1C;
    }
    if (n->unk1C != 0) {
        n->unk1C->unk18 = n->unk18;
    }
    n->unk18 = 0;
    n->unk1C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFEA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFF98);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFFE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C0040);

extern "C" void func_001C00B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C00C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C0408);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C1318);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C1468);

extern "C" void func_001C14E0(S001C14E0* p, f32 dt) {
    if (p->unk60 != 0 && D_00369A64 == 0 && 0.0f < dt) {
        if (p->unk74 > p->unk78) {
            p->unk74 = p->unk74 - p->unk78;
            if (++p->unk6C == p->unk64) {
                p->unk6C = 0;
                if (p->unk7C != 0) {
                    if (--p->unk70 < 0) {
                        p->unk70 = p->unk70 + p->unk68;
                    }
                } else {
                    if (++p->unk70 == p->unk68) {
                        p->unk70 = 0;
                    }
                }
            }
        }
        p->unk74 = p->unk74 + dt;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C1598);
