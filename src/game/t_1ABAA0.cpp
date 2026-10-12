#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct Q64 {
    TI128 q[4];
};

struct S001ACCC0 {
    char pad0[0x1C];
    u32 unk1C;
    S001ACCC0* unk20;
    s32 unk24;
    S001ACCC0* unk28;
    void* unk2C;
    s32 unk30;
    char pad34[0x8];
    s32 unk3C;
    s8 unk40;
    char pad41[0x2];
    u8 unk43;
    Q64* unk44;
};

struct F4 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct H8 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" {
void func_001ACDC0(S001ACCC0* p, s32 v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ABAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AC840);

extern "C" void func_001ACCC0(S001ACCC0* p, Q64* src) {
    s32 i;

    if (p->unk44 != 0) {
        for (i = 0; i < p->unk40; i++) {
            p->unk44[i] = src[i];
        }
    }
}

extern "C" s32 func_001ACD28(S001ACCC0* p) {
    return ((s32)p->unk1C >> 1) & 1;
}

extern "C" s32 func_001ACD38(S001ACCC0* p) {
    return ((s32)p->unk1C >> 2) & 1;
}

extern "C" s32 func_001ACD48(S001ACCC0* p) {
    return p->unk1C & 1;
}

extern "C" s32 func_001ACD58(S001ACCC0* p) {
    return ((s32)p->unk1C >> 3) & 1;
}

extern "C" s32 func_001ACD68(S001ACCC0* p) {
    return ((s32)p->unk1C >> 4) & 1;
}

extern "C" s32 func_001ACD78(S001ACCC0* p) {
    return ((s32)p->unk1C >> 9) & 1;
}

extern "C" s32 func_001ACD88(S001ACCC0* p) {
    return ((s32)p->unk1C >> 21) & 1;
}

extern "C" void func_001ACD98(S001ACCC0* p, s32 v) {
    p->unk1C = v ? p->unk1C | 1 : p->unk1C & ~1;
}

extern "C" void func_001ACDC0(S001ACCC0* p, s32 v) {
    p->unk1C = v ? p->unk1C | 8 : p->unk1C & ~8;
}

extern "C" void func_001ACDE8(void) {
}

extern "C" void func_001ACDF0(S001ACCC0* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x20 : p->unk1C & ~0x20;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACE18);

extern "C" void func_001ACE28(S001ACCC0* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x2000 : p->unk1C & ~0x2000;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACE50);

extern "C" void func_001ACE58(S001ACCC0* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x10 : p->unk1C & ~0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACE80);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACEA8);

extern "C" s32 func_001ACF30(S001ACCC0* p) {
    return p->unk30;
}

extern "C" void func_001ACF38(S001ACCC0* p, s32 v) {
    p->unk30 = v;
}

extern "C" void func_001ACF40(F4* p, f32 a, f32 b, f32 c, f32 d) {
    p->unk0 = a;
    p->unk4 = b;
    p->unk8 = c;
    p->unkC = d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACF58);

extern "C" S001ACCC0* func_001ACF70(S001ACCC0* p) {
    S001ACCC0* r = 0;

    if (!(p->unk1C & 2)) {
        r = p->unk20;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACF90);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ACF98);

extern "C" S001ACCC0* func_001AD008(S001ACCC0* p) {
    return p->unk28;
}

extern "C" void* func_001AD010(S001ACCC0* p) {
    return p->unk2C;
}

extern "C" s32 func_001AD018(S001ACCC0* p) {
    return p->unk24;
}

extern "C" void func_001AD020(S001ACCC0* p, s32 v) {
    p->unk24 = v;
    func_001ACDC0(p, v != 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD048);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD090);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD0C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD128);

extern "C" void func_001AD158(S001ACCC0* p, u8 v) {
    p->unk43 = v;
}

extern "C" u8 func_001AD160(S001ACCC0* p) {
    return p->unk43;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD168);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD228);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD230);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD2B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD360);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD400);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD4C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD4C8);

extern "C" char* func_001AD568(H8* p, s32* out) {
    s32 off = p->unk4;
    s32 n = p->unk8;
    char* r = 0;

    *out = n;
    if (n) {
        r = (char*)p + off;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD588);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD7B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD7F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD9D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001ADA68);
