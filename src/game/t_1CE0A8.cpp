#include "common.h"

struct N1CF1 {
    union {
        u32 unk0;
        struct {
            u32 lo : 8;
            u32 b8 : 1;
            u32 hi : 23;
        };
    };
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct S001CEDE8 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x10];
    s32 unk28;
};

struct NV {
    char pad0[4];
    s32 unk4;
    NV* unk8;
};

struct SJ1CE {
    char pad0[1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    char pad9[0xA];
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    char pad1B[0x19];
    u32 unk34;
};

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, void*);
};

struct N8 {
    char pad0[0x4];
    N8* unk4;
    N8* unk8;
};

struct L4 {
    char pad0[0x4];
    N8* unk4;
    void* unk8;
};

struct E8 {
    s32 unk0;
    s32 unk4;
};

struct S001CE670 {
    u8 unk0;
    u8 unk1[0x33];
    u32 unk34;
};

struct S001CE0A8 {
    char pad0[0x8];
    VEnt* unk8;
    u32 unkC;
    char pad10[0x8];
    N8* unk18;
    char pad1C[0x4];
    s32 unk20;
    char pad24[0x4];
    void* unk28;
    s32 unk2C;
    char pad30[0x4];
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

struct S1CFBC8_N {
    u32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" {
void* func_0027B300_n(s32 a, s32 b) __asm__("func_0027B300");
void* func_001D5BA0_p(s32 a, s32 b, s32 c) __asm__("func_001D5BA0");
char* func_001D7710_p(void* p) __asm__("func_001D7710");
s32 func_0011C030(void* p);
void func_0011BF98(void* p, s32 a);
void func_001D6450(void* p, s32 a, s32 b);
extern s32 D_0036D410;
s32 func_0028DA08(s32 a);
s32 func_0027D870_n(s32 a, s32 key, s32* v, s32 req) __asm__("func_0027D870");
s32 func_0027D400_n(s32 a, s32 key, s32* v, s32 req) __asm__("func_0027D400");
s32 func_001D03D8(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_0027DF00_k(s32 a, s32 key) __asm__("func_0027DF00");
void func_00289ED8(s32 a, s32 b);
void func_0028C200(s32 a);
s32 func_001CFBC8_d(s32 a, s32 b, s32 c, s32 d) __asm__("func_001CFBC8");
s32 func_001CF148(void* a, void* b, s32 c);
void func_001CF218(s32 a, s32 b, s32 c);
void func_001CFBC8(void* a, void* b, void* c, s32 d);
void func_001CF000(void);
void func_0028D7D8(void);
void func_0028A5A0(void* a, void* b);
void func_0027AE70(void* p);
s32 func_0027D1F8(void* p, s32 key, void* v, s32 req);
s32 func_0027D870(void* p, s32 key, void* v, s32 req);
s32 func_0027DF00(void* p);
void func_0027ABB0(void* a, void* b);
void func_001CEBE0(S001CE0A8* p);
void func_0027C448(s32 a, u32 key, s32 b);
void func_001D0798(N8* n);
extern char D_0034B4F0[];
extern E8 D_0032C320[];
void func_001CE7A0(void);
void func_001CE810(L4* p);
void func_001CE888(L4* l, N8* n);
s32 func_0027D268(void* a, s32 b);
s32 func_0027D268_4(void* p, s32 key, void* v, s32 req) __asm__("func_0027D268");
s32 func_001CFFC8(void* p);
s32 func_001D0228(void* p);
s32 func_0027ABB0_2(void* a, s32 b) __asm__("func_0027ABB0");
void func_001145D8(void* p);
void* func_001CE6D0(char* p);
void memset(char* a, s32 b, s32 c);
s32 func_00222F90(s32 a);
void func_001D02A0(void* p);
void func_001CF000_2(void* p, s32 v) __asm__("func_001CF000");
void func_001CF040(void* p, s32 v);
extern u8 D_0034B618[];
extern u8 D_0034B670[];
extern u8 D_0033B510[];
extern s32 D_00372DB0[] __attribute__((section(".sdata")));
void func_0027C898(s32 a, s32 b, s32 c);
void func_001CF120(S001CE0A8* p, void* a);
void func_0028D878(void* a, s32 b, s32 c);
void func_0028D940(void* a, s32 b, s32 c);
void func_0027ACF8(s32 a, s32 b);
void func_0027AE70_2(s32 a, s32 b) __asm__("func_0027AE70");
s32 func_0027D470_2(void* p, s32 key, s32* v, s32 req) __asm__("func_0027D470");
void func_001CEE88(S001CEDE8* p, s32 a, s32 b);
s32 func_001CFFC8_2(void* p, s32 a) __asm__("func_001CFFC8");
s32 func_001CFFC8_3(void* p, s32 a, s32 b) __asm__("func_001CFFC8");
s32 func_0027DF00_2(s32 a, s32 key) __asm__("func_0027DF00");
void* func_001D0848(s32 a, s32 b);
s32 func_0027D400(void* p, s32 key, s32* v, s32 req);
void func_001D0330(void* p, s32 a, s32 b);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
void func_0027F1E0(s32 a, s32 b, s32 c);
extern s32 D_00372DA8[] __attribute__((section(".sdata")));
void func_0028DC30(s32 a, s32 b, s32 c);
void func_0027C160(s32 a, s32 b, s32 c);
void func_0027C1F8(s32 a, s32 b, f32 c);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void func_00113250(s32 a);
void func_0028DB28(void* p);
void func_0028E278(s32 a);
void func_00289B40(s32 a, s32 b);
void func_0027AC90(s32 a);
void func_0027D470(s32 a, s32 b, s32* c, s32 d);
s32 func_0027DD88(s32 a, s32 b);
void* func_001D0900(s32 size, s32 a);
void func_00279358(void* p, s32 a, s32 b, s32 c);
void func_0027BDB0(s32 a, void* p, s32 b);
}

struct S1CE0 {
    char pad0[1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    char pad5[0x1A];
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
};

extern "C" void func_001CE0A8(S1CE0* p) {
    int d1 = p->unk1;
    d1 = 0x80 - d1;
    d1 = __builtin_abs(d1);
    p->unk1F = p->unk1;
    p->unk20 = p->unk2;
    p->unk21 = p->unk3;
    p->unk22 = p->unk4;
    if (d1 < 0x33) p->unk1 = 0x80;
    int d2 = p->unk2;
    d2 = 0x80 - d2;
    d2 = __builtin_abs(d2);
    if (d2 < 0x33) p->unk2 = 0x80;
    int d3 = p->unk3;
    d3 = 0x80 - d3;
    d3 = __builtin_abs(d3);
    if (d3 < 0x33) p->unk3 = 0x80;
    int d4 = p->unk4;
    d4 = 0x80 - d4;
    d4 = __builtin_abs(d4);
    if (d4 < 0x33) p->unk4 = 0x80;
    int d5 = p->unk1F;
    d5 = 0x80 - d5;
    d5 = __builtin_abs(d5);
    if (d5 < 0x33) {
        int d6 = p->unk20;
        d6 = 0x80 - d6;
        d6 = __builtin_abs(d6);
        if (d6 < 0x33) {
            p->unk1F = 0x80;
            p->unk20 = 0x80;
        }
    }
    int d7 = p->unk21;
    d7 = 0x80 - d7;
    d7 = __builtin_abs(d7);
    if (d7 < 0x33) {
        int d8 = p->unk22;
        d8 = 0x80 - d8;
        d8 = __builtin_abs(d8);
        if (d8 < 0x33) {
            p->unk21 = 0x80;
            p->unk22 = 0x80;
        }
    }
}

extern "C" void* func_001CE1D0(char* p) {
    func_001145D8(p + 4);
    func_001CE6D0(p + 0x50);
    *(s32*)(p + 0xA0) = 0;
    *(s32*)(p + 0xA8) = 0;
    *(s32*)(p + 0xA4) = 0;
    *(s32*)(p + 0xAC) = 0;
    return p;
}

extern "C" void func_001CE218(S001CE0A8* p, u32 m) {
    p->unk34 &= ~m;
    p->unk38 &= ~m;
    p->unk3C &= ~m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE248);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE410);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE4C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE5A0);

extern "C" void func_001CE670(S001CE670* p) {
    s32 i;

    for (i = 0; D_0032C320[i].unk0 > 0; i++) {
        if (p->unk34 & D_0032C320[i].unk0) {
            p->unk1[D_0032C320[i].unk4] = 0xFF;
        } else {
            p->unk1[D_0032C320[i].unk4] = 0;
        }
    }
}

extern "C" void* func_001CE6D0(char* p) {
    memset(p + 1, 0, 0x24);
    memset(p + 0x26, 0, 8);
    *(s32*)(p + 0x4C) = 1;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x40) = 0;
    *(s32*)(p + 0x48) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE730);

extern "C" void func_001CE778(void) {
    func_001CE7A0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE798);

extern "C" void func_001CE7A0(void) {
}

extern "C" L4* func_001CE7A8(L4* p) {
    p->unk4 = 0;
    p->unk8 = D_0034B4F0;
    return p;
}

extern "C" void func_001CE7C0(L4* p, s32 flags) {
    p->unk8 = D_0034B4F0;
    func_001CE810(p);
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001CE810(L4* p) {
    N8* n = p->unk4;
    if (n != 0) {
        do {
            L4* l = *(L4**)n;
            N8* next = n->unk8;
            if (l != 0) {
                func_001CE888(l, n);
                *(L4**)n = 0;
            }
            *(L4**)n = 0;
            n = next;
        } while (n != 0);
    }
}

extern "C" void func_001CE868(L4* l, N8* n) {
    n->unk8 = l->unk4;
    if (l->unk4 != 0) {
        l->unk4->unk4 = n;
    }
    l->unk4 = n;
}

extern "C" void func_001CE888(L4* l, N8* n) {
    if (n->unk4 != 0) {
        n->unk4->unk8 = n->unk8;
    } else {
        l->unk4 = n->unk8;
    }
    if (n->unk8 != 0) {
        n->unk8->unk4 = n->unk4;
    }
    n->unk4 = 0;
    n->unk8 = 0;
}

extern "C" L4* func_001CE8C0(L4* p) {
    p->unk4 = 0;
    p->unk8 = 0;
    return p;
}

extern "C" void* func_001CE8D0(char* p) {
    func_001CE7A8((L4*)p);
    char* a = p + 0x5C;
    char* b = p + 0x38;
    *(void**)(p + 8) = D_0034B618;
    *(void**)(b + 0x14) = D_0033B510;
    *(void**)(b + 4) = p;
    *(s32*)(b + 8) = 0;
    *(void**)(b + 0xC) = b;
    *(void**)(b + 0x10) = b;
    func_001CE7A8((L4*)a);
    *(void**)(a + 0xC) = p;
    *(void**)(a + 8) = D_0034B670;
    *(s32*)(p + 0x1C) = 0;
    *(s32*)(p + 0x2C) = D_00372DA8[0];
    *(s32*)(p + 0x20) = D_00372DB0[0];
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0xC) = 0;
    *(s32*)(p + 0x58) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x34) = 0;
    return p;
}

struct LH1CE {
    char pad0[0xC];
    LH1CE* unkC;
    LH1CE* unk10;
    void* unk14;
};

struct VE1CE9 {
    s16 delta;
    s16 pad;
    void (*fn)(void*, void*);
};

struct O1CE9 {
    char pad0[0x2C];
    char* unk2C;
};

struct L1CE9 {
    char pad0[8];
    L1CE9* unk8;
};

struct N1CE9 {
    char pad0[0xC];
    N1CE9* unkC;
    N1CE9* unk10;
    void* unk14;
};

struct T1CE9 {
    char pad0[8];
    void* unk8;
    char padC[4];
    O1CE9* unk10;
    s32 unk14;
    L1CE9* unk18;
    char pad1C[0xC];
    s32 unk28;
    char pad2C[0xC];
    N1CE9 unk38;
};

extern "C" void func_001CE990(T1CE9* p, s32 flags) {
    p->unk8 = (void*)D_0034B618;
    func_0028DB28(p);
    s32 m = p->unk28;
    if (m != 0) {
        func_0027AC90(m);
        func_00113250(m);
        p->unk28 = 0;
    }
    func_001CE810((L4*)((char*)p + 0x5C));
    O1CE9* o = p->unk10;
    if (o != 0) {
        VE1CE9* e = (VE1CE9*)(o->unk2C + 0x18);
        e->fn((char*)o + e->delta, p);
    }
    s32 k = p->unk14;
    if (k != 0) {
        func_0028E278(k);
        s32 k2 = p->unk14;
        if (k2 != 0) {
            func_00289B40(k2, 3);
        }
        p->unk14 = 0;
    }
    L1CE9* n = p->unk18;
    N1CE9* nd = &p->unk38;
    if (n != 0) {
        do {
            L1CE9* c = n;
            n = n->unk8;
            func_001D0798((N8*)c);
        } while (n != 0);
    }
    p->unk18 = 0;
    func_001CE7C0((L4*)((char*)p + 0x5C), 2);
    nd->unk14 = (void*)D_0033B510;
    nd->unk10->unkC = nd->unkC;
    nd->unkC->unk10 = nd->unk10;
    nd->unkC = nd;
    nd->unk10 = nd;
    func_001CE7C0((L4*)p, flags);
}

extern "C" void func_001CEAD0(S001CE0A8* p, s32 v) {
    NV* n = (NV*)p->unk18;
    if (n != 0) {
        do {
            if (n->unk4 == v) return;
            n = n->unk8;
        } while (n != 0);
    }
    NV* t = (NV*)func_001CE8C0((L4*)func_001D0848(0xC, 1));
    t->unk4 = v;
    t->unk8 = (NV*)p->unk18;
    p->unk18 = (N8*)t;
}

extern "C" void func_001CEB48(S001CE0A8* p, N8* key) {
    N8* prev = 0;
    N8* n;

    for (n = p->unk18; n != 0; n = n->unk8) {
        if (n->unk4 == key) {
            break;
        }
        prev = n;
    }
    if (n != 0) {
        if (prev != 0) {
            prev->unk8 = n->unk8;
        } else {
            p->unk18 = n->unk8;
        }
        func_001D0798(n);
    }
}

extern "C" void func_001CEBA8(S001CE0A8* p) {
    if (((s32)p->unkC >> 1) & 1) {
        return;
    }
    func_001CEBE0(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEBD8);

struct VE1CEB {
    s16 delta;
    s16 pad;
    void* fn;
};

static inline void Call1CEB(char* o, s32 vp, s32 off) {
    VE1CEB* e = (VE1CEB*)(*(char**)(o + vp) + off);
    ((void (*)(char*))e->fn)(o + e->delta);
}

static inline void Del1CEB(char* o) {
    VE1CEB* e = (VE1CEB*)(*(char**)(o + 8) + 8);
    ((void (*)(char*, s32))e->fn)(o + e->delta, 3);
}

extern "C" void func_001CEBE0(S001CE0A8* pp) {
    char* p = (char*)pp;
    if (((*(u32*)(p + 0xC) ^ 1) & 1) != 0) {
        Call1CEB(p, 8, 0x40);
    }
    if ((*(u32*)(p + 0xC) & 0x10) != 0) {
        s32 t = *(s32*)(p + 0x2C);
        char* o = (char*)func_001D5BA0_p(D_0036D410, *(s32*)(p + 0x50), 1);
        *(s32*)(func_001D7710_p(o) + 0x9C) = 0;
        if (p != 0) {
            Del1CEB(p);
        }
        s32 a = func_0011C030(func_001D7710_p(o));
        func_0011BF98(func_001D7710_p(o), *(s32*)(o + 0x2C));
        s32 b = func_0011C030(func_001D7710_p(o));
        func_001D7710_p(o);
        *(s32*)(func_001D7710_p(o) + 0x9C) = 1;
        func_001D6450(o, b - a, t);
    } else {
        if (p != 0) {
            Del1CEB(p);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CED18);

extern "C" void func_001CED20(S001CE0A8* p, s32 v) {
    if (*(s32*)((char*)p + 0x2C) != D_00372DA8[0]) {
        char* o = *(char**)((char*)p + 0x10);
        if (o != 0) {
            VEnt* e = (VEnt*)(*(char**)(o + 0x2C) + 0x20);
            ((void (*)(char*, void*, s32))e->fn)(o + e->delta, p, v);
        }
    }
    *(s32*)((char*)p + 0x2C) = v;
    func_001CEE88((S001CEDE8*)p, 0x40C698AF, v);
}

extern "C" void func_001CED98(S001CE0A8* p, s32 v) {
    if (v != 0) {
        v = ((func_00222F90(v) ^ 1) != 0) ? 0 : v;
    }
    *(s32*)((char*)p + 0x1C) = v;
}

extern "C" void func_001CEDE0(S001CE0A8* p, s32 v) {
    p->unk20 = v;
}

extern "C" void func_001CEDE8(S001CEDE8* p, s32 a, s32 b) {
    func_001D02A0(p);
    func_0028DC30(p->unk14, a, b);
}

extern "C" void func_001CEE38(S001CEDE8* p, s32 a, s32 b) {
    func_001D0228(p);
    func_0027C160(p->unk28, a, b);
}

extern "C" void func_001CEE88(S001CEDE8* p, s32 a, s32 b) {
    func_001D0228(p);
    func_0027C448(p->unk28, a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEED8);

extern "C" void func_001CEEE0(S001CE0A8* p, s32 a, f32 f) {
    func_001D0228(p);
    func_0027C1F8((s32)p->unk28, a, f);
}

extern "C" void func_001CEF30(S001CE0A8* p) {
    if (p->unk28 != 0) {
        func_0027AE70(p->unk28);
    }
}

extern "C" s32 func_001CEF58(S001CE0A8* p, s32 key, void* v) {
    if (p->unk28 != 0) {
        return func_0027D1F8(p->unk28, key, v, 0);
    }
    return 0;
}

extern "C" s32 func_001CEF80(S001CE0A8* p, s32 key, void* v) {
    if (p->unk28 != 0) {
        return func_0027D870(p->unk28, key, v, 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEFA8);

extern "C" s32 func_001CEFB0(S001CE0A8* p, s32 key, void* v) {
    if (p->unk28 != 0) {
        return func_0027D268_4(p->unk28, key, v, 0);
    }
    return 0;
}

extern "C" s32 func_001CEFD8(S001CE0A8* p) {
    if (p->unk28 != 0) {
        return func_0027DF00(p->unk28);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF000);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF040);

extern "C" void func_001CF120(S001CE0A8* p, void* a) {
    if (p->unk28 != 0) {
        func_0027ABB0(a, p->unk28);
    }
}

extern "C" s32 func_001CF148(void* ov, void* params, s32 q) {
    S001CEDE8* o = (S001CEDE8*)ov;
    s32 v;
    if (*(s32*)((char*)o + 0x28) != 0) {
        func_0027D870(params, 0, &v, 1);
        s32 t = func_0027DD88(*(s32*)((char*)o + 0x28), v);
        if (t != 0) {
            N1CF1* n = (N1CF1*)func_001D0900(0x10, 1);
            n->b8 = 0;
            n->unk0 = n->unk0 & 0xFFFF01FF;
            n->unk4 = 0;
            n->unkC = 0;
            n->unk8 = 0;
            *(u16*)((char*)n + 2) = 0;
            func_00279358(n, t, 0, 0);
            func_0027BDB0(q, n, 0);
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF218);

extern "C" void func_001CF470(S001CEDE8* o, void* params) {
    s32 a;
    s32 b;
    s32 c;
    s32 f = func_0027DF00_2((s32)params, 0x3F93A1EF);
    if (func_0027D470_2(params, 0x475BF03C, &a, 0) != 0) {
        func_001CEDE8(o, a, f);
    }
    if (func_0027D400(params, 0x90436BD9, &b, 0) != 0) {
        func_001CF000_2(o, b);
    }
    if (func_0027D470_2(params, 0x8225D629, &c, 0) != 0) {
        func_001CF040(o, c);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF538);

extern "C" void func_001CF640(void* p, s32* c) {
    if (c[1] != 0) {
        func_001CEDE8((S001CEDE8*)p, c[1], c[0]);
    }
    if (c[2] != 0) {
        func_001CF000_2(p, c[2]);
    }
    if (c[3] != 0) {
        func_001CF040(p, c[3]);
    }
}

extern "C" s32 func_001CF6A8(S001CE0A8* p, void* a, S001CE0A8* c) {
    s32 x;
    if (func_0027D870(a, 0x90FEC815, &x, 0) != 0) {
        s32 r = func_0027AA70(func_001287F0(8, 1));
        func_001CF120(p, (void*)r);
        func_0027C898(c->unk20, x, r);
    } else {
        func_001CF120(p, (void*)c->unk20);
    }
    return 1;
}

extern "C" void func_001CF748(void* a, void* b, S001CE0A8* c) {
    func_001CF148(a, b, c->unk20);
}

extern "C" void func_001CF768(s32 a, s32 b, char* c) {
    s32 v[4];
    func_0027D470(b, 0, v, 1);
    func_001CF218(a, v[0], *(s32*)(c + 0x20));
}

extern "C" int func_001CF7B8(void) {
    func_001CF000();
    return 1;
}

extern "C" s32 func_001CF7D8(S001CE0A8* p, void* a) {
    s32 x;
    s32 y;
    if (func_0027D870(a, 0, &x, 0) != 0) {
        s32 q = (s32)p->unk28;
        if (q != 0) {
            func_0027ACF8(q, x);
            func_0027AE70_2((s32)p->unk28, x);
        }
        return 1;
    }
    y = 0;
    if ((func_0027D470_2(a, 0x90436BD9, &y, 0) ^ 1) != 0) {
        func_0027D470_2(a, 0, &y, 0);
    }
    func_001CF040(p, y);
    return 1;
}

extern "C" s32 func_001CF898(S001CEDE8* p) {
    s32 q = p->unk28;
    if (q != 0) {
        func_0027AC90(q);
        func_00113250(q);
        p->unk28 = 0;
    }
    return 1;
}

extern "C" int func_001CF8E8(void* a, void* b, void* c) {
    func_0028A5A0(c, a);
    return 1;
}

extern "C" int func_001CF910(S001CE0A8* a, void* b, S001CE0A8* c) {
    s32 v = a->unk2C;

    func_0027C448(c->unk20, 0x0830ECAF /* objid */, v);
    return 1;
}

extern "C" s32 func_001CF940(S001CE0A8* p) {
    s32 m = func_001CFFC8(p);
    if (m == 0) {
        return 0;
    }
    return (*(s32*)((char*)p + 0x30) & m) == 0;
}

extern "C" s32 func_001CF980(S001CE0A8* p, s32 a, s32 b) {
    if (func_0027DF00_2(a, 0xC4E78E22) != 0) {
        *(s32*)((char*)p + 0x30) = 0;
        return 1;
    }
    s32 m = func_001CFFC8_3(p, a, b);
    if (m == 0) {
        return 0;
    }
    *(s32*)((char*)p + 0x30) = *(s32*)((char*)p + 0x30) & ~m;
    return 1;
}

extern "C" s32 func_001CFA08(S001CE0A8* p) {
    s32 m = func_001CFFC8(p);
    if (m == 0) {
        return 0;
    }
    *(s32*)((char*)p + 0x30) = *(s32*)((char*)p + 0x30) | m;
    return 1;
}

extern "C" int func_001CFA50(void) {
    func_0028D7D8();
    return 1;
}

extern "C" s32 func_001CFA70(void* a, void* b, s32 c) {
    s32 x = 0;
    s32 y;
    if (func_0027D870(b, 0xA1DC81F9, &x, 0) != 0) {
        func_0028D940(a, x, c);
        return 1;
    }
    y = 0;
    if (func_0027D870(b, 0x40C698AF, &y, 0) != 0) {
        func_0028D878(a, y, c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFB18);

extern "C" void func_001CFB88(void* a, void* b, void* c) {
    func_001CFBC8(a, b, c, 1);
}

extern "C" void func_001CFBA8(void* a, void* b, void* c) {
    func_001CFBC8(a, b, c, 0);
}

extern "C" s32 func_001CFBC8_d(s32 a, s32 b, s32 c, s32 d) {
    S1CFBC8_N* n = (S1CFBC8_N*)func_0027B300_n(b, 0);
    if (n) {
        if ((n->unk0 & 0xFE00) == 0x1A00) {
            s32 h = n->unk8;
            s32 sp0 = 0;
            s32 sp4;
            sp0 = func_0028DA08(c);
            func_0027D870_n(b, 0x40C698AF, &sp0, 0);
            sp4 = 0;
            func_0027D400_n(b, 0x7031F10C, &sp4, 0);
            s32 r = func_001D03D8(a, h, sp4, sp0, func_0027DF00_k(b, 0x8757D0BB));
            if (func_0027DF00_k(b, 0x01917DF2) == 0) {
                func_00289ED8(r, c);
            }
            if (d) {
                func_0028C200(r);
            }
        }
    }
    return 1;
}

extern "C" s32 func_001CFD00(void* a, void* b) {
    s32 x;
    s32 y;
    if (func_0027D870(b, 0, &x, 0) != 0) {
        y = 0;
        func_0027D400(b, 0x7031F10C, &y, 0);
        func_001D0330(a, x, y);
    }
    return 1;
}

extern "C" int func_001CFD78(S001CE0A8* p) {
    p->unkC &= ~4;
    return 1;
}

extern "C" int func_001CFD98(S001CE0A8* p) {
    p->unkC |= 4;
    return 1;
}

extern "C" s32 func_001CFDB0(char* p) {
    s32 r = func_0027AA70(func_001287F0(8, 1));
    VEnt* e = (VEnt*)(*(char**)(p + 8) + 0x30);
    ((void (*)(char*, s32))e->fn)(p + e->delta, r);
    func_0027F1E0(r, 0, 1);
    if (r != 0) {
        func_0027AC90(r);
        func_00113250(r);
    }
    return 1;
}

extern "C" s32 func_001CFE38(S001CE0A8* p, s32 a) {
    s32 old = *(s32*)((char*)p + 0x30);
    s32 m = func_001CFFC8_2(p, a);
    if (m == 0) {
        return 0;
    }
    if (func_0027DF00_2(a, 0x1A4E0EF9) != 0) {
        *(s32*)((char*)p + 0x30) = *(s32*)((char*)p + 0x30) & ~m;
    }
    return (old & m) != 0;
}

struct Q1CFE {
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(int);
};

struct A1CFE {
    s32 unk0;
    s32 unk4;
    s32 (Q1CFE::*unk8)(int, int);
};

extern "C" s32 func_001CFEB8(Q1CFE* p, A1CFE* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v4(a->unk0);
}

extern "C" int func_001CFF58(S001CE0A8* p, u32 key, void* a) {
    switch (key) {
    case 0xC6870028 /* Die */:
        ((void (*)(void*))p->unk8[8].fn)((char*)p + p->unk8[8].delta);
        break;
    case 0x6C63C7C5 /* SetProps */:
        p->unk8[2].fn((char*)p + p->unk8[2].delta, a);
        break;
    }
    return 1;
}

struct A1CFF {
    s32 pad0;
    u32 n;
    s32* d;
};

extern "C" {
s32 func_00275F08(s32 a, s32 b);
s32 func_0027D1F8_b(s32 p, s32 key, s32* v, s32 req) __asm__("func_0027D1F8");
void func_0027D470_b(s32 p, s32 key, A1CFF** v, s32 req) __asm__("func_0027D470");
}

extern "C" s32 func_001CFFC8_2(void* a, s32 b) {
    s32 k = 0;
    s32 mask = 0;
    A1CFF* arr = 0;
    func_0027D470_b(b, 0, &arr, 0);
    if (arr) {
        u32 i = 0;
        if (arr->n != 0) {
            do {
                s32 v;
                if (arr->n == 1) {
                    v = (s32)arr->d;
                } else {
                    v = arr->d[i];
                }
                i++;
                mask |= 1 << func_00275F08(v, 0);
            } while (i < arr->n);
        }
    } else if (func_0027D1F8_b(b, 0, &k, 0)) {
        mask = 1 << k;
    }
    return mask;
}
