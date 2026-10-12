#include "common.h"

struct S001CBCC8 {
    char pad0[0x81B8];
    s32 unk81B8;
    char pad81BC[0x1C];
    s32 unk81D8;
};

struct S001CBD30 {
    char pad0[0x34];
    s32 unk34;
    char pad38[0xA8];
    s32 unkE0;
};

struct S001CBFE8 {
    char pad0[0x18];
    void* unk18;
};

struct S001CC050 {
    char pad0[0x1C];
    void (*unk1C)(void);
    char pad20[0x8];
    void (*unk28)(void);
};

struct S001CC090 {
    char pad0[0x38];
    union {
        u32 unk38;
        struct {
            u64 b0 : 7;
            u64 b7 : 1;
        };
    };

    bool Test(u32 m) {
        return (unk38 & m) != 0;
    }
};

struct S001CC170_18 {
    char pad0[0x3124];
    s32 unk3124;
};

struct S001CC170 {
    char pad0[0x18];
    S001CC170_18* unk18;
};

struct S001CC2D8 {
    s8* unk0;
    char pad4[0x10];
    s32 unk14;
};

struct S001CD640 {
    char pad0[0x8];
    void* unk8;
    char padC[0xA4];
};

struct S001CD6B0 {
    char pad0[0x168];
    s32 unk168;
    char pad16C[0x8];
    s32 unk174[1];
};

extern "C" {
void func_00113F38(void* p);
void func_001184C0(void* p);
void func_00118570(void* p);
void func_0029F500(s32 a, s32 b);
void func_001CD6E0(s32 a, s32 b);
extern char D_00342398[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBB50);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBBB0);

extern "C" void func_001CBC10(void* p) {
    func_00113F38(p);
}

extern "C" void func_001CBC30(void) {
}

extern "C" void func_001CBC38(void) {
}

extern "C" void func_001CBC40(void) {
}

extern "C" void func_001CBC48(void) {
}

extern "C" void func_001CBC50(void) {
}

extern "C" int func_001CBC58(void) {
    return 0;
}

extern "C" int func_001CBC60(void) {
    return 0;
}

extern "C" void func_001CBC68(void) {
}

extern "C" int func_001CBC70(void) {
    return 0;
}

extern "C" int func_001CBC78(void) {
    return 0;
}

extern "C" void func_001CBC80(void) {
}

extern "C" void func_001CBC88(void) {
}

extern "C" void func_001CBC90(void) {
}

extern "C" int func_001CBC98(void) {
    return -1;
}

extern "C" void func_001CBCA0(void) {
}

extern "C" void func_001CBCA8(void) {
}

extern "C" void func_001CBCB0(void) {
}

extern "C" void func_001CBCB8(void) {
}

extern "C" int func_001CBCC0(void) {
    return 0;
}

extern "C" void func_001CBCC8(S001CBCC8* p, s32 v) {
    p->unk81B8 = v;
}

extern "C" s32 func_001CBCD8(S001CBCC8* p) {
    return p->unk81B8;
}

extern "C" void func_001CBCE8(void) {
}

extern "C" int func_001CBCF0(void) {
    return 0;
}

extern "C" void func_001CBCF8(S001CBCC8* p) {
    p->unk81D8 ^= 1;
}

extern "C" int func_001CBD10(void) {
    return 0;
}

extern "C" void func_001CBD18(void) {
}

extern "C" int func_001CBD20(void) {
    return -1;
}

extern "C" int func_001CBD28(void) {
    return -1;
}

extern "C" void func_001CBD30(S001CBD30* p, s32 v) {
    p->unk34 = v;
}

extern "C" void func_001CBD38(void) {
}

extern "C" void func_001CBD40(void) {
}

extern "C" int func_001CBD48(void) {
    return 0;
}

extern "C" void func_001CBD50(void) {
}

extern "C" void func_001CBD58(void) {
}

extern "C" void func_001CBD60(void) {
}

extern "C" void func_001CBD68(void) {
}

extern "C" int func_001CBD70(void) {
    return -1;
}

extern "C" int func_001CBD78(void) {
    return -1;
}

extern "C" void func_001CBD80(void) {
}

extern "C" int func_001CBD88(void) {
    return 0;
}

extern "C" int func_001CBD90(void) {
    return 0;
}

extern "C" int func_001CBD98(void) {
    return 0;
}

extern "C" int func_001CBDA0(void) {
    return 0;
}

extern "C" int func_001CBDA8(void) {
    return 0;
}

extern "C" int func_001CBDB0(void) {
    return 0;
}

extern "C" int func_001CBDB8(void) {
    return 0;
}

extern "C" void func_001CBDC0(void) {
}

extern "C" void func_001CBDC8(void) {
}

extern "C" void func_001CBDD0(void) {
}

extern "C" void func_001CBDD8(void) {
}

extern "C" void func_001CBDE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBDE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBE48);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBF08);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBF68);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CBFA8);

extern "C" void func_001CBFE8(S001CBFE8* p) {
    p->unk18 = D_00342398;
    func_00113F38(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC010);

extern "C" void func_001CC050(S001CC050* p) {
    p->unk28();
}

extern "C" void func_001CC070(S001CC050* p) {
    p->unk1C();
}

extern "C" u32 func_001CC090(S001CC090* p) {
    return p->unk38 & 1;
}

extern "C" u64 func_001CC0A0(S001CC090* p) {
    return p->b7;
}

extern "C" bool func_001CC0B0(S001CC090* p) {
    return p->Test(4);
}

extern "C" bool func_001CC0C0(S001CC090* p) {
    return p->Test(0x400);
}

extern "C" void func_001CC0D0(S001CC090* p) {
    p->unk38 |= 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC0E0);

extern "C" bool func_001CC0E8(S001CC090* p) {
    return (p->unk38 & 0x21) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC100);

extern "C" s32 func_001CC170(S001CC170* p) {
    if (p->unk18 != 0) {
        return p->unk18->unk3124;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC190);

extern "C" bool func_001CC198(S001CC090* p) {
    return p->Test(8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC1F8);

extern "C" int func_001CC258(void) {
    return 0;
}

extern "C" int func_001CC260(void) {
    return 0;
}

extern "C" void func_001CC268(void) {
}

extern "C" int func_001CC270(void) {
    return 1;
}

extern "C" void func_001CC278(void) {
}

extern "C" void func_001CC280(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC288);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC298);

extern "C" int func_001CC2D8(S001CC2D8* p) {
    func_0029F500(p->unk14, *p->unk0 * 1000);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC310);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC330);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC388);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC400);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC748);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCA20);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCA58);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCA90);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCB10);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCB60);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCC00);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCD50);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCD88);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCDC8);

extern "C" int func_001CCE00(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCE08);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD058);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD108);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD158);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD198);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD1D8);

extern "C" int func_001CD1F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD1F8);

extern "C" void func_001CD2A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD2A8);

extern "C" s32 func_001CD2B8(S001CBD30* p) {
    return p->unkE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD2C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD2C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD318);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD360);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD470);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD500);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD5C0);

extern "C" void func_001CD640(S001CD640* p, s32 i) {
    if (p[i].unk8 != 0) {
        func_001184C0(p[i].unk8);
    }
}

extern "C" void func_001CD678(S001CD640* p, s32 i) {
    if (p[i].unk8 != 0) {
        func_00118570(p[i].unk8);
    }
}

extern "C" void func_001CD6B0(S001CD6B0* p, s32 v) {
    p->unk168 = v;
}

extern "C" s32 func_001CD6B8(S001CD6B0* p) {
    return p->unk168;
}

extern "C" s32 func_001CD6C0(S001CD6B0* p, s32 i) {
    return p->unk174[i];
}

extern "C" void func_001CD6D0(S001CD6B0* p, s32 i, s32 v) {
    p->unk174[i] = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD6E0);

extern "C" void func_001CDA00(void* p) {
    func_00113F38(p);
}

extern "C" void func_001CDA20(S001CC050* p) {
    p->unk1C();
}

extern "C" void func_001CDA40(void) {
    func_001CD6E0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CDA60);
