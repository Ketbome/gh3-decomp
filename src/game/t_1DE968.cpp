#include "common.h"

struct S1DE9A8 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
};

extern "C" {
extern f32 D_0032C3B8[];
extern s32 D_0036D410[] __attribute__((section(".sdata")));
extern s32 D_0036D3B0[] __attribute__((section(".sdata")));
void* func_001D5BA0(s32 p, u32 key, s32 q);
s32 func_002764E8(u32 key, s32 v);
void func_001D5CB0(s32 p, s32 a, void* b, s32 c, u32 key, s32 d, s32 e);
void func_001D4480(s32 p, s32 a, void* b, s32 c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DE968);

extern "C" void func_001DE9A8(S1DE9A8* p) {
    p->unk14 = 0;
}

extern "C" void func_001DE9B0(S1DE9A8* p) {
    p->unk18 = 0;
}

extern "C" void func_001DE9B8(S1DE9A8* p, s32 v) {
    p->unk1C = v;
}

extern "C" void func_001DE9C0(S1DE9A8* p, f32 v) {
    p->unk20 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DE9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DEC40);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF390);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF538);

extern "C" f32 func_001DF6E8(s32 a, s32 b, s32 c, s32 d) {
    return D_0032C3B8[a + b * 2 + c * 4 + d * 8];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF718);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF890);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF900);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF9C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DFD28);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DFFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0198);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E02F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E02F8);

extern "C" void func_001E0428(void* p) {
    if (func_001D5BA0(D_0036D410[0], 0x3B5737A6, 0) != 0) {
        s32 m = D_0036D410[0];
        func_001D5CB0(m, func_002764E8(0x6003AF05, 1), p, 0, 0x3B5737A6, 1, 1);
    } else {
        s32 m = D_0036D3B0[0];
        func_001D4480(m, func_002764E8(0x6003AF05, 1), p, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E04D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0600);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0760);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E07C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0878);
