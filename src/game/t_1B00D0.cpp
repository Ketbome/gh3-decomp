// cflags: -funroll-loops
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

extern "C" {
void func_001B1380(s32 a, s32 b);
void func_001BD608(S001B1818_7C* p);
void func_001BD6E0(S001B1818_7C* p);
void func_0011A470(void);
void func_001BB068(void);
void func_001B1DD8_1(void* p) __asm__("func_001B1DD8");
void func_001B0850(S001B08F0* p);
void func_0019E380(s32 a, s32 b, s32 c, s32 d, s32 e);
void func_00119400(s32 heap, void* p);
extern s32 D_00368A38;
void func_001A9288(void);
extern u8 D_00348E30[];
s32 func_001A9240(s32 a);
void func_001A9C68(void* p);
extern u8 D_0038C9A0[];
extern u8 D_0038C9F0[];
extern s32 D_00370F40;
s32 func_00275570(void);
void func_001B1E38(void* p, s32 a, s32 b, s32 c);
void func_001B1EB0(char* p);
}

struct S1B13 {
    char pad0[8];
    s32 unk8;
    void* unkC;
};

extern "C" S1B13 D_0038C990;

struct E1B0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct N1B1D {
    char pad0[0x8];
    void* unk8;
    char padC[0x190];
    N1B1D* next;
};

extern "C" N1B1D* D_00372C34;

extern "C" int func_001B00D0(char* p, u32 idx) {
    u32* q = *(u32**)(p + 0x38);
    u32 count = *q++;
    for (u32 i = 0; i < count; i++) {
        if (i == idx) return *(int*)q[0];
        q += 2;
        u32 n = *q++;
        q += n;
    }
    return 0;
}

extern "C" int func_001B01D8(char* p, u32 idx, int j) {
    u32* q = *(u32**)(p + 0x38);
    u32 count = *q++;
    for (u32 i = 0; i < count; i++) {
        if (i == idx) {
            E1B0* e = (E1B0*)q[0] + j;
            return e->unk8;
        }
        q += 2;
        u32 n = *q++;
        q += n;
    }
    return 0;
}

extern "C" void func_001B02F0(char* p, u32 idx, int j, int v) {
    u32* q = *(u32**)(p + 0x38);
    u32 count = *q++;
    for (u32 i = 0; i < count; i++) {
        if (i == idx) {
            E1B0* e = (E1B0*)q[0] + j;
            e->unk8 = v;
            return;
        }
        q += 2;
        u32 n = *q++;
        q += n;
    }
}
TEXT_PAD(8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0410);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B05B8);

extern "C" void func_001B0850(S001B08F0* p) {
    if (p->unk1C & 0x100000) {
        S001B08F0_44* q = p->unk44;
        *(s32*)((char*)q + 0xC) = D_00370F40 + func_00275570();
    }
}

extern "C" void func_001B0898(S001B08F0* p, s32 v) {
    if (p->unk1C & 0x100000) {
        if (v != 0) {
            func_001B0850(p);
        }
        S001B08F0_44* q = p->unk44;
        q->unkA = q->unkA | 1;
    }
}

extern "C" void func_001B08F0(S001B08F0* p) {
    if (p->unk1C & 0x100000) {
        p->unk44->unkA &= ~1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B0920);

extern "C" void func_001B1380(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        D_0038C990.unkC = D_00348E30;
        D_0038C990.unk8 = func_001A9240(1);
        func_001A9C68(D_0038C9A0);
        func_001A9C68(D_0038C9F0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B13E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B13E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1408);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1418);

extern "C" void func_001B1428(char* p, s32 flags) {
    *(void**)(p + 0xC) = D_00348E30;
    func_001A9288();
    if (flags & 1) {
        func_00119400(D_00368A38, p);
    }
}

extern "C" void func_001B1478(void) {
    func_001B1380(1, 0xFFFF);
}

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

extern "C" void func_001B1C40(S001B1818* p) {
    func_001BD608(p->unk7C);
}

extern "C" void func_001B1C60(S001B1818* p) {
    func_001BD6E0(p->unk7C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1C80);

extern "C" N1B1D* func_001B1D18(void* unused, N1B1D* p) {
    func_001B1DD8_1(p);
    p->unk8 = 0;
    p->next = D_00372C34;
    D_00372C34 = p;
    return p;
}

extern "C" void func_001B1D60(N1B1D* n) {
    if (D_00372C34 == n) {
        D_00372C34 = n->next;
    } else {
        for (N1B1D* c = D_00372C34; c->next; c = c->next) {
            if (c->next == n) {
                c->next = n->next;
                break;
            }
        }
    }
    if (n->unk8) func_0011A470();
    func_001BB068();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1E38);

extern "C" void func_001B1EB0(char* p) {
    func_0019E380(0x50, *(s32*)(p + 0x148), *(s16*)(p + 0x154), -1, -1);
    s32 t = *(s32*)(p + 0x14C);
    if (t != 0) {
        func_0019E380(0x50, t, *(s16*)(p + 0x156), -1, -1);
    }
}

extern "C" s32 func_001B1F08(S001B1F08* p) {
    return p->unk0;
}

extern "C" s32 func_001B1F10(S001B1F08* p) {
    return p->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B00D0", func_001B1F18);
