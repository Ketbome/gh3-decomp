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

struct S1E4780_O {
    char pad0[0x20];
    s32 unk20;
};

struct S1E4780_L {
    char pad0[4];
    u32 unk4;
    s32 unk8;
    S1E4780_L* unkC;
    S1E4780_L* unk10;
    void* unk14;
};

struct S1E4780 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    S1E4780_L unk18;
    char pad30[0x50];
    S1E4780_O* unk80;
};

extern "C" {
void func_00289FB0(void* p, s32 a);
void func_0027ACF8(s32 a, u32 key);
s32 func_0027DF00(s32 a, u32 key);
s32 func_0027D870(s32 a, u32 key, s32* v, s32 req);
s32 func_001218A0(s32 a, s32 b, s32 c);
void func_00121F70(s32 a, void* b, void* c);
extern s32 D_00368E48[] __attribute__((section(".sdata")));
extern u8 D_0036DA78[];
extern u8 D_0034D2D0[];
void func_001E75A8(S1E32D8* out, void* p);
void func_00289F90(void* q);
extern s32 D_00372DB8[] __attribute__((section(".sdata")));
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void func_001194B8(s32 heap);
void Heap_Free(s32 heap, void* p);
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

extern "C" void func_001E3048(void* p, int flags) {
    if (D_00372DB8[0]) {
        func_001194B8(D_00368A38[0]);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

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

extern "C" S1E4780* func_001E4780(S1E4780* p, s32 a, S1E4780_O* o) {
    S1E4780_L* l = &p->unk18;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unk14 = 0;
    l->unk4 = 0xFFFFFFFF;
    l->unk14 = D_0034D2D0;
    l->unk8 = 0;
    l->unkC = l;
    l->unk10 = l;
    p->unk80 = o;
    func_00289FB0(o, 0);
    func_0027ACF8(p->unk80->unk20, 0xD8580FB5);
    func_0027ACF8(p->unk80->unk20, 0x4EEC27B5);
    func_0027ACF8(p->unk80->unk20, 0x56B7A7F6);
    p->unk10 = func_0027DF00(a, 0xEAB375BF);
    s32 sp0;
    func_0027D870(a, 0x11093FB5, &sp0, 1);
    p->unk14 = sp0;
    s32 r = func_0027DF00(a, 0x712B3542);
    s32 h = D_00368E48[0];
    p->unkC = r;
    s32 t = func_001218A0(h, 0, 0);
    if (t != 0) {
        func_00121F70(t, D_0036DA78, l);
        p->unk0 = 0;
    } else {
        p->unk0 = 1;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E2B90", func_001E48C0);
