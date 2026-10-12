#include "common.h"

struct S1E2D18 {
    char pad0[0xC];
    u32 unkC;
    u32 unk10;
};

struct S1E32D8 {
    s32 unk0;
    char pad4[0x1C];
};

struct S1E2E40_V {
    virtual void v1();
    virtual void v2();
    virtual void v3(void* q);
};

struct S1E2E40 : S1E2E40_V {
    void* unk4;
};

extern "C" {
void func_001E75A8(S1E32D8* out, void* p);
void func_00289F90(void* q);
extern s32 D_00372DB8[] __attribute__((section(".sdata")));
extern s32 D_00368A38[] __attribute__((section(".sdata")));
s32 func_00119730(s32 h, s32 a, s32 b);
void func_00119490(s32 h, s32 a);
extern s32 D_00368740[] __attribute__((section(".sdata")));
s32 func_001E32D0(void);
s32 func_001E3280(s32 v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E2B90);

extern "C" s32 func_001E2D18(S1E2D18* p) {
    if (p->unkC == 0) {
        return 1;
    }
    return p->unk10 >= p->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E2D40);

extern "C" void func_001E2E40(S1E2E40* p, void* q) {
    if (p->unk4 == 0) {
        func_00289F90(q);
    } else {
        p->v3(q);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E2E90);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E2EE8);

extern "C" void* func_001E2FF0(void* p) {
    if (D_00372DB8[0] != 0) {
        s32 h = D_00368A38[0];
        func_00119490(h, func_00119730(h, D_00372DB8[0], 1));
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E3048);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E30A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E3220);

extern "C" s32 func_001E3280(s32 v) {
    s32 s = func_001E32D0();
    s32 q = v / s;
    if (v % s != 0) {
        return q * s + s;
    }
    return v;
}

extern "C" s32 func_001E32C8(void) {
    return 1;
}

extern "C" s32 func_001E32D0(void) {
    return 0x400;
}

extern "C" s32 func_001E32D8(void* p) {
    S1E32D8 r;
    func_001E75A8(&r, p);
    s32 n = r.unk0;
    if (n >= 0) {
        n = func_001E3280(n + 0x1C);
    }
    return n;
}

extern "C" s32 func_001E3310(void* p, s32 v) {
    s32 t = func_001E3280(v) / func_001E32D0();
    switch (D_00368740[0]) {
    case 6:
        t += 7;
        break;
    case 7:
    case 8:
        t += 6;
        break;
    }
    return t;
}

extern "C" void func_001E3380(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E3388);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E35C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E3B60);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E40C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E4448);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E45C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E45C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E46B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E4780);

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E48C0);
