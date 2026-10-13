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
s32 func_0027DF00(s32 p, u32 key);
s32 func_0027D870(s32 p, u32 key, s32* out, s32 d);
void func_001DFFB0(s32 p);
void func_001E0198(u32 a, s32 p);
void func_001E02F8(s32 p);
s32 func_0027D400(s32 p, u32 key, s32* out, s32 d);
s32 func_0027D1F8(s32 p, u32 key, s32* out, s32 d);
void func_001D0330(s32 self, s32 a, s32 b);
s32 func_00223BF0(s32 p);
s32 func_0027AA70(s32 a);
s32 func_001287F0(s32 a, s32 b);
void func_0027C448(s32 a, u32 k, s32 v);
void func_0027C160(s32 a, u32 k, s32 v);
void func_0028C9D0(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_0027AC90(void* p);
void func_00113250(void* p);
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

extern "C" void func_001DF900(s32 p) {
    u32 v = 0;
    u32 t;
    if (func_0027DF00(p, 0x69C257E9) != 0) {
        t = 0x9EBA4BA8;
        goto set;
    }
    if ((func_0027D870(p, 0xCE05BD37, (s32*)&v, 0) ^ 1) != 0) {
        t = 0xAD1C652B;
set:
        v = t;
    }
    if (v == 0x9EBA4BA8) goto ca;
    if (v != 0xAD1C652B) goto cc;
    func_001DFFB0(p);
    return;
ca:
    func_001E02F8(p);
    return;
cc:
    func_001E0198(v, p);
}

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

extern "C" void func_001E04D8(s32 self, s32 params) {
    s32 a = 0;
    s32 b;
    s32 c;
    if (func_0027D870(params, 0x2CA8A299, &a, 0) != 0) {
        b = 0;
        func_0027D400(params, 0x7031F10C, &b, 0);
        func_001D0330(self, a, b);
    }
    if (func_0027D1F8(params, 0x99A9B716, &c, 0) != 0) {
        s32 h = func_00223BF0(params);
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xA1DC81F9, h);
        func_0027C160(t, 0x99A9B716, c);
        func_0028C9D0(0x413B766D, t, self, 0, 0, 0);
        if (t != 0) {
            func_0027AC90((void*)t);
            func_00113250((void*)t);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0600);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0760);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E07C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0878);
