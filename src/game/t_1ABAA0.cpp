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

struct BF1AD {
    u64 pad : 34;
    u64 b34 : 1;
    u64 pad2 : 20;
    u64 b55 : 1;
    u64 pad3 : 8;

    bool Test() {
        return b34 && !b55;
    }
};

struct C1AD {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

struct H8 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" {
void func_001ACDC0(S001ACCC0* p, s32 v);
s32 func_001ACD28(S001ACCC0* p);
s32 func_001ACD38(S001ACCC0* p);
s32 func_0019BF10(void* p);
void func_0019C208(void* a, s32 b);
void func_001AF3C8(void* a, void* b);
s32 func_001AD2B8(S001ACCC0* p, s32 m, s32 v);
s32 func_001A9A98_2(void* a, void* b) __asm__("func_001A9A98");
void func_001A9B08(void* a, void* b);
void func_001A0380(s32 a, s32 b);
void func_0027C160(s32 a, s32 b, s32 c);
extern s32 D_0036C6B8;
extern s32 D_0036C6BC;
extern s32 D_0036C6C0;
extern s32 D_0036C6C4;
extern s32 D_0036C6C8;
extern s32 D_0036C6CC;
extern s32 D_0036C6D0;
extern s32 D_0036C6D4;
extern s32 D_0036C6D8;
extern s32 D_0036C6DC;
extern s32 D_0036C6E0;
extern s32 D_0036C6E4;
extern s32 D_0036C6E8;
extern s32 D_0036C6EC;
extern s32 D_0036C6F0;
extern s32 D_0036C6F4;
extern s32 D_0036C6F8;
extern s32 D_0036C6FC;
extern s32 D_0036C700;
extern s32 D_0036C704;
extern s32 D_0036C708;
extern s32 D_0036C70C;
extern s32 D_0036C71C;
extern s32 D_0036C720;
extern s32 D_0036C724;
extern s32 D_0036C728;
void func_00119400(s32 a, void* b);
s32 func_0019BF20(void* p);
s32 func_001A93F8(void* a, s32* b, s32 c, s32 d);
void func_001A9A60(void* a, void* b);
void func_001ACDE8_2(void* a, s32 b) __asm__("func_001ACDE8");
void* func_001A9CF0(s32 a, s32 b);
s32 func_00118F20(s32 a, s32 b, s32 c, s32 d);
extern s32 D_00368A38;
s32 func_0019BFC8(void* p);
s32 func_001ACD68(S001ACCC0* p);
void func_001ACE58(S001ACCC0* p, s32 v);
void func_001A9A98(void* a, void* b);
s32 func_001550C0(s32 a);
s32 func_00157260(s32 a);
extern u8 D_0038C9A0[];
extern u8 D_0038C9F0[];
extern u8 D_00378220[];
}

struct N1ACF {
    char pad0[0x28];
    N1ACF* next;
};

struct S1ACF {
    char pad0[0x1C];
    u32 flags;
    N1ACF* head;
};

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

extern "C" void func_001ACEA8(S001ACCC0* p, s32 v) {
    u32 f;
    if (v != 0) {
        f = p->unk1C | 0x10000000;
    } else {
        f = p->unk1C & 0xEFFFFFFF;
    }
    p->unk1C = f;
    if (!(f & 2)) {
        S001ACCC0* c = p->unk20;
        if (c != 0) {
            do {
                func_001ACEA8(c, v);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

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

extern "C" void func_001ACF98(S1ACF* p, N1ACF* n) {
    if (p->flags & 2) {
        p->head = n;
    } else if (p->head) {
        N1ACF* c = p->head;
        while (c->next) c = c->next;
        c->next = n;
    } else {
        p->head = n;
    }
    p->flags &= ~2;
}

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

extern "C" void func_001AD048(S001ACCC0* p, s32 v) {
    if (v == 0x80808080) {
        func_001ACE58(p, 0);
    }
    p->unk3C = v;
}

extern "C" s32 func_001AD090(S001ACCC0* p) {
    if (func_001ACD68(p) != 0) {
        return p->unk3C;
    }
    return 0x80808080;
}

extern "C" void func_001AD0C8(S001ACCC0* p, s32 v) {
    if (func_001ACD28(p) == 0) {
        p->unk2C = D_00378220 + func_001550C0(func_00157260(v)) * 0xB0;
    }
}

extern "C" void* func_001AD128(S001ACCC0* p) {
    if (func_001ACD28(p) != 0) return 0;
    return p->unk2C;
}

extern "C" void func_001AD158(S001ACCC0* p, u8 v) {
    p->unk43 = v;
}

extern "C" u8 func_001AD160(S001ACCC0* p) {
    return p->unk43;
}

extern "C" void func_001AD168(S001ACCC0* p, C1AD* c) {
    c->unk4 = c->unk4 + 1;
    if (func_001ACD38(p) != 0) {
        c->unkC = c->unkC + 1;
    }
    if (func_001ACD28(p) != 0) {
        c->unk8 = c->unk8 + 1;
        c->unk10 = c->unk10 + func_0019BF20(p->unk20);
        c->unk14 = c->unk14 + func_0019BFC8(p->unk20);
    } else {
        S001ACCC0* n = p->unk20;
        if (n != 0) {
            do {
                func_001AD168(n, c);
                n = n->unk28;
            } while (n != 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD228);

extern "C" s32 func_001AD230(S001ACCC0* p, s32 v) {
    s32 sum = 0;
    if (v == 0 || ((s32)p->unk1C >> 12 & 1) == 0) {
        if (func_001ACD28(p) != 0) {
            sum = func_0019BF20(p->unk20);
        } else {
            S001ACCC0* c = p->unk20;
            if (c != 0) {
                do {
                    sum += func_001AD230(c, 0);
                    c = c->unk28;
                } while (c != 0);
            }
        }
        return sum;
    }
    return 0;
}

extern "C" s32 func_001AD2B8(S001ACCC0* p, s32 m, s32 v) {
    s32 sum = 0;
    if (v == 0 || ((s32)p->unk1C >> 12 & 1) == 0) {
        if (func_001ACD28(p) != 0) {
            if ((m & p->unk1C) == m) {
                sum = func_0019BFC8(p->unk20);
            }
        } else {
            S001ACCC0* c = p->unk20;
            if (c != 0) {
                do {
                    sum += func_001AD2B8(c, m, 0);
                    c = c->unk28;
                } while (c != 0);
            }
        }
        return sum;
    }
    return 0;
}

extern "C" s32 func_001AD360(S001ACCC0* p, s32 v) {
    s32 sum = 0;
    if (v == 0 || ((s32)p->unk1C >> 12 & 1) == 0) {
        if (func_001ACD28(p) != 0) {
            if (!(p->unk1C & 0x600C0)) {
                sum = func_0019BFC8(p->unk20);
            }
        } else {
            S001ACCC0* c = p->unk20;
            if (c != 0) {
                do {
                    sum += func_001AD360(c, 0);
                    c = c->unk28;
                } while (c != 0);
            }
        }
        return sum;
    }
    return 0;
}

extern "C" s32 func_001AD400(S001ACCC0* p) {
    s32 sum = 0;
    S001ACCC0* c;
    if (func_001ACD28(p) != 0) {
        if (((s32)p->unk1C >> 12) & 1) {
            sum = func_0019BFC8(p->unk20);
        }
    } else {
        c = p->unk20;
        if (((s32)p->unk1C >> 12) & 1) {
            if (c != 0) {
                do {
                    sum += func_001AD2B8(c, 0, 0);
                    c = c->unk28;
                } while (c != 0);
            }
        } else {
            if (c != 0) {
                do {
                    sum += func_001AD400(c);
                    c = c->unk28;
                } while (c != 0);
            }
        }
    }
    return sum;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD4C0);

extern "C" void* func_001AD4C8(s32* a, s32 b, s32 c, s32* d) {
    s32* t = (s32*)((char*)a + *a);
    void* o = (char*)t + *t;
    s32 r = func_001A93F8(o, t, b, c);
    if (d != 0) {
        *d = r;
    }
    func_001A9A60(o, (c & 1) ? (void*)D_0038C9A0 : (void*)D_0038C9F0);
    if (c & 2) {
        func_001ACDE8_2(o, 1);
    }
    return o;
}

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

GP_DATA(D_0036C6B8);
GP_DATA(D_0036C6BC);
GP_DATA(D_0036C6C0);
GP_DATA(D_0036C6C4);
GP_DATA(D_0036C6C8);
GP_DATA(D_0036C6CC);
GP_DATA(D_0036C6D0);
GP_DATA(D_0036C6D4);
GP_DATA(D_0036C6D8);
GP_DATA(D_0036C6DC);
GP_DATA(D_0036C6E0);
GP_DATA(D_0036C6E4);
GP_DATA(D_0036C6E8);
GP_DATA(D_0036C6EC);
GP_DATA(D_0036C6F0);
GP_DATA(D_0036C6F4);
GP_DATA(D_0036C6F8);
GP_DATA(D_0036C6FC);
GP_DATA(D_0036C700);
GP_DATA(D_0036C704);
GP_DATA(D_0036C708);
GP_DATA(D_0036C70C);
GP_DATA(D_0036C71C);
GP_DATA(D_0036C720);
GP_DATA(D_0036C724);
GP_DATA(D_0036C728);
extern "C" void func_001AD588(s32 unused, char* p) {
    func_0027C160(*(s32*)(p + 0x20), 0xA40903F8, D_0036C6B8);
    func_0027C160(*(s32*)(p + 0x20), 0x1722E2D5, D_0036C6BC);
    func_0027C160(*(s32*)(p + 0x20), 0xD52C7FF5, D_0036C6C0);
    func_0027C160(*(s32*)(p + 0x20), 0x770AAE63, D_0036C6C4);
    func_0027C160(*(s32*)(p + 0x20), 0x31A409BD, D_0036C6C8);
    func_0027C160(*(s32*)(p + 0x20), 0x0A3E33E8, D_0036C6CC);
    func_0027C160(*(s32*)(p + 0x20), 0xCB6DF746, D_0036C6D0);
    func_0027C160(*(s32*)(p + 0x20), 0x81293C06, D_0036C6D4);
    func_0027C160(*(s32*)(p + 0x20), 0xB62C0D2A, D_0036C6D8);
    func_0027C160(*(s32*)(p + 0x20), 0x0B3E7C34, D_0036C6DC);
    func_0027C160(*(s32*)(p + 0x20), 0xE17B0654, D_0036C6E0);
    func_0027C160(*(s32*)(p + 0x20), 0xE329CBD1, D_0036C6E4);
    func_0027C160(*(s32*)(p + 0x20), 0xF215B2F1, D_0036C6E8);
    func_0027C160(*(s32*)(p + 0x20), 0xD8888078, D_0036C6EC);
    func_0027C160(*(s32*)(p + 0x20), 0x13B723EF, D_0036C6F0);
    func_0027C160(*(s32*)(p + 0x20), 0xE92C1C1B, D_0036C6F4);
    func_0027C160(*(s32*)(p + 0x20), 0x2F894B2B, D_0036C6F8);
    func_0027C160(*(s32*)(p + 0x20), 0x33643055, D_0036C6FC);
    func_0027C160(*(s32*)(p + 0x20), 0x7594877D, D_0036C700);
    func_0027C160(*(s32*)(p + 0x20), 0x6B05D0C1, D_0036C704);
    func_0027C160(*(s32*)(p + 0x20), 0x43AAED89, D_0036C708);
    func_0027C160(*(s32*)(p + 0x20), 0x612864C2, D_0036C70C);
    func_0027C160(*(s32*)(p + 0x20), 0x0A5C63DA, D_0036C71C);
    func_0027C160(*(s32*)(p + 0x20), 0x98A74D9F, D_0036C720);
    func_0027C160(*(s32*)(p + 0x20), 0x7241E9B4, D_0036C724);
    func_0027C160(*(s32*)(p + 0x20), 0xDEC15DEB, D_0036C728);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD7B0);

extern "C" void func_001AD7B8(void* p) {
    func_001A9A98(p, D_0038C9A0);
    func_001A9A98(p, D_0038C9F0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ABAA0", func_001AD7F8);

extern "C" void* func_001AD8F8(s32 a, s32 b, s32 c, H8* d, void* e) {
    S001ACCC0* o = (S001ACCC0*)func_001A9CF0(func_00118F20(D_00368A38, 0x50, 1, 0), a);
    o->unk1C = o->unk1C | 0x1800;
    func_001AD020(o, b);
    o->unk40 = c;
    *(s32*)&o->unk44 = d->unk4;
    *(u8*)((char*)o + 0x42) = 0;
    if (e != 0) {
        func_001A9A60(o, e);
    } else {
        func_001A9A60(o, D_0038C9A0);
    }
    func_001ACD98(o, 1);
    return o;
}

extern "C" void func_001AD9D0(S001ACCC0* p) {
    if (p->unk1C & 0x01000000) {
        (*(S001ACCC0**)((char*)p + 0x38))->unk28 = p->unk28;
    } else if (func_001A9A98_2(p, D_0038C9A0) == 0) {
        func_001A9B08(p, D_0038C9A0);
    }
    if (p != 0) {
        s32 t = *(s32*)((char*)p + 0x4C);
        if (t != 0) {
            func_001A0380(t, 3);
        }
        func_00119400(D_00368A38, p);
    }
}

extern "C" void* func_001ADA68(S001ACCC0* a, void* b, s32 c) {
    S001ACCC0* o = (S001ACCC0*)func_001A9CF0(func_00118F20(D_00368A38, 0x50, 1, 0), (s32)a);
    o->unk28 = 0;
    if (c != 0) {
        if (b != 0) {
            func_001A9A60(o, b);
        } else {
            func_001A9A60(o, D_0038C9A0);
        }
    }
    func_001ACD98(o, 1);
    if (func_001ACD28(a) != 0) {
        s32 t = func_00118F20(D_00368A38, func_0019BF10(a->unk20), 1, 0);
        o->unk20 = (S001ACCC0*)t;
        func_0019C208(a->unk20, t);
        if (*(s32*)((char*)a + 0x38) != 0) {
            func_001AF3C8(o, a);
        }
    } else {
        o->unk20 = 0;
        S001ACCC0* n = a->unk20;
        if (n != 0) {
            do {
                func_001ACF98((S1ACF*)o, (N1ACF*)func_001ADA68(n, 0, 0));
                n = n->unk28;
            } while (n != 0);
        }
    }
    return o;
}
