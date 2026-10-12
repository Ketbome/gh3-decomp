#include "common.h"

struct S001B08F0_44 {
    char pad0[0xA];
    u16 unkA;
};

struct S001B08F0 {
    char pad0[0x1C];
    u32 unk1C;
    char pad20[0x24];
    S001B08F0_44* unk44;
};

struct L001B1818 {
    s32 unk0;
    struct S001B1818* unk4;
    L001B1818* unk8;
};

struct S001B1818_7C {
    char pad0[0x18];
    L001B1818* unk18;
    char pad1C[0xC];
    s32 unk28;
    char pad2C[0x4];
    struct E50* unk30;
};

struct E50 {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
    char pad4C[0x4];
};

struct S001B1818 {
    char pad0[0x60];
    u32 unk60;
    char pad64[0x4];
    s32* unk68;
    char pad6C[0x4];
    s32 unk70;
    char pad74[0x4];
    S001B1818* unk78;
    S001B1818_7C* unk7C;
};

struct S001B1F08 {
    s32 unk0;
    s32 unk4;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B00D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B01D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B02F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0410);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B05B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0850);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0898);

extern "C" void func_001B08F0(S001B08F0* p) {
    if (p->unk1C & 0x100000) {
        p->unk44->unkA &= ~1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0920);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1380);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B13E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B13E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1408);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1418);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1428);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1478);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1498);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B15E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1728);

extern "C" s32 func_001B1818(S001B1818* p) {
    L001B1818* l = p->unk7C->unk18;
    S001B1818* q;

    while (l != 0) {
        q = l->unk4;
        while (q != 0) {
            if (q == p) {
                return l->unk0;
            }
            q = q->unk78;
        }
        l = l->unk8;
    }
    return 0;
}

extern "C" void func_001B1868(S001B1818* p, s32 v) {
    if (v) {
        p->unk60 |= 1;
    } else {
        p->unk60 &= ~1;
    }
}

extern "C" void func_001B1898(S001B1818* p, s32 v) {
    if (v) {
        p->unk60 |= 2;
    } else {
        p->unk60 &= ~2;
    }
}

extern "C" void func_001B18C8(S001B1818* p, s32 v) {
    if (v) {
        if (p->unk70 == 0) {
            p->unk70 = v;
            p->unk60 |= 0x20;
        }
    } else {
        p->unk70 = 0;
        p->unk60 &= ~0x20;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1910);

extern "C" void func_001B1948(S001B1818* p, s32 v) {
    p->unk70 = v;
    p->unk60 &= ~0x20;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1968);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1990);

extern "C" void func_001B1A30(S001B1818* p, s32* v) {
    p->unk68 = v;
}

extern "C" s32* func_001B1A38(S001B1818* p) {
    return p->unk68;
}

extern "C" void func_001B1A40(S001B1818* p, s32 a, s32 b, s32 c) {
    s32 i;
    E50* e = p->unk7C->unk30;

    for (i = 0; i < p->unk7C->unk28; i++, e++) {
        if (e->unk48 == a && e->unk44 == b) {
            p->unk68[i] = c;
        }
    }
}

extern "C" void func_001B1AA0(S001B1818* p, s32 i, s32 v) {
    p->unk68[i] = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1AB8);

extern "C" s32 func_001B1C20(S001B1818* p, s32 i) {
    return p->unk68[i];
}

extern "C" void func_001B1C38(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1C40);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1C60);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1C80);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1D18);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1D60);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1E38);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1EB0);

extern "C" s32 func_001B1F08(S001B1F08* p) {
    return p->unk0;
}

extern "C" s32 func_001B1F10(S001B1F08* p) {
    return p->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1F18);
