#include "common.h"

struct O1D017 {
    char pad0[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2(void* a);
    virtual void v3();
    virtual void v4();
    virtual void v5(void* a);
};

struct X1D017 {
    char pad0[0xC];
    u32 unkC;
    O1D017* unk10;
    s32 unk14;
};

struct G1D00 {
    void* o;
    s32 a;
    s32 b;
};

struct VEnt {
    s16 delta;
    s16 index;
    void* fn;
};

struct N1548 {
    char pad0[0x10];
    N1548* next;
    char pad14[4];
    char* vt;
};

struct S001D0F68 {
    char pad0[0x4];
    s32 unk4;
    VEnt* unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    VEnt* unk18;
};

extern "C" {
s32 Heap_Alloc(s32 h, s32 size, s32 a, s32 b);
s32 func_0011C2A8(s32 a);
extern s32 D_00371028[] __attribute__((section(".sdata")));
extern s32 D_00371038;
void func_001CED20(void* p, s32 v);
void func_001CED98(void* p, s32 v);
void func_001CEDE0(void* p, s32 v);
s32 func_00222F90(s32 a);
void func_00223590(s32 a, void* b);
void func_00223628(s32 a, void* b);
s32 func_00224250(s32 a, s32 b);
s32 func_0027DF00_k(s32 a, u32 key) __asm__("func_0027DF00");
void func_001D0330_0(void) __asm__("func_001D0330");
void func_001CE7C0(void);
void func_001D12E0(void);
void func_0027D188(void* p, s32 key, void* v, s32 req);
extern s32 D_00372D90;
extern char D_0034B698[];
void func_001D09C0(s32 a, s32 b);
void func_001CEBA8(void);
void func_001DAC78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern s32 D_0036D554;
void func_001D1548(void* p);
void func_0027D2D8(void* a, s32 key, void* v, s32 req);
void func_001D1E20(void* a, f32 b);
s32 func_0027D268(void* a, s32 key, void* v, s32 req);
s32 func_0027D870(void* a, s32 key, void* v, s32 req);
s32 func_001D1CF8(void* a, s32 b);
void Heap_Free(s32 heap, void* p);
struct Pool1D07;
extern Pool1D07* D_0036D0F0[2];
extern s32 D_0036D100;
void func_0011C2E8_p(Pool1D07*, void*) __asm__("func_0011C2E8");
extern char D_0034B850[];
extern s32 D_0036D3B0_m __asm__("D_0036D3B0");
void func_001D4C08(s32 a, void* b);
void func_001CE990(void* p, s32 f);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void func_0028DBD0(void);
void func_001D0170(void* p);
void func_00289E10(s32 a, s32 b);
s32 func_0028D1D8(s32 a, s32 b, s32 c, s32 d, u32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_00119490(s32 a, s32 b);
void func_001194B8(s32 a);
s32 func_00119610(s32 a, s32 b);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
s32 func_0012D028(s32 a, s32 b);
s32 func_002899D8(s32 a);
void func_0028A2A8(s32 a, s32 b, s32 c, void* d);
void func_0028A2D0(s32 a, void* b, s32 c, void* d);
void func_0028A000(s32 a);
void func_001D1998(void* p, s32 a);
void func_001D4560(s32 a, void* b, s32 c, s32 d);
void func_001CE868(void* p, void* g);
void func_001CE888(void* p, void* g);
void func_0028E010(s32 a, s32 b);
void func_00289FB0(s32 a, s32 b);
void func_0028DB28(void* p);
void func_001CE810(void* p);
}

struct S1D1F {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[1];
};

extern "C" {
extern s32 D_0036D3B0[] __attribute__((section(".sdata")));
extern S1D1F* D_0036F658[] __attribute__((section(".sdata")));
}

struct S1D14 {
    char pad0[0x10];
    S1D14* unk10;
    VEnt* unk18;
};

struct S1D14P {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x138];
    S1D14* unk150;
    s32 unk154;

    bool Test(s32 m) {
        return (unk154 & m) != 0;
    }
};

extern "C" s32 func_001D00B0(char* p, s32 k) {
    if (*(s32*)(p + 0x14) == 0) {
        return 1;
    }
    G1D00 g;
    g.a = 0;
    g.b = 0;
    g.o = p;
    if (p != 0) {
        func_001CE868(p, &g);
    }
    func_0028E010(*(s32*)(p + 0x14), k);
    bool r = g.o != 0;
    if (g.o != 0) {
        func_001CE888(g.o, &g);
        g.o = 0;
    }
    return r;
}

extern "C" void func_001D0130(char* p, s32 a, s32 b) {
    s32 t = *(s32*)(p + 0x2C);
    func_001DAC78(D_0036D554, a, t, t, b, 0, -1.0f);
}

extern "C" void func_001D0170(void* pv) {
    X1D017* p = (X1D017*)pv;
    if ((p->unkC & 1) == 0) {
        if (p->unk14 != 0) {
            func_00289FB0(p->unk14, 0);
        }
        func_0028DB28(p);
        O1D017* o = p->unk10;
        p->unkC = p->unkC & 0xFFFFFFFD;
        if (o != 0) {
            o->v2(p);
            o->v5(p);
        }
        p->unkC = p->unkC | 1;
        func_001CE810((char*)p + 0x5C);
    }
}

extern "C" void func_001D0228(char* p) {
    if (*(s32*)(p + 0x28) == 0) {
        s32 h = D_00368A38[0];
        func_00119490(h, func_00119610(h, 0x3A));
        s32 r = func_0027AA70(func_001287F0(8, 1));
        s32 h2 = D_00368A38[0];
        *(s32*)(p + 0x28) = r;
        func_001194B8(h2);
    }
}

extern "C" void func_001D02A0(S1D14P* p) {
    if (p->unk14 == 0) {
        s32 h = D_00368A38[0];
        func_00119490(h, func_00119610(h, 5));
        p->unk14 = func_002899D8(func_0012D028(0x10C, 1));
        func_0028A2A8(p->unk14, 0x3F5CDB8A, 0, p);
        func_001194B8(D_00368A38[0]);
    }
}

extern "C" s32 func_001D0330(S1D14P* p, void* a, s32 b) {
    if (p->unk14 != 0) {
        func_0028A2D0(p->unk14, a, b, p);
    } else {
        s32 t = func_002899D8(func_0012D028(0x10C, 1));
        p->unk14 = t;
        func_0028A2D0(t, a, b, p);
    }
    func_0028A000(p->unk14);
    return p->unk14;
}

extern "C" void func_001D03B8(void) {
    func_001D0330_0();
}

extern "C" s32 func_001D03D8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r = func_0028D1D8(b, c, 0, 0, 0xFFFFFFFF, d, 0, 0, 0, e);
    if (r != 0) {
        func_00289E10(r, a);
    }
    return r;
}

extern "C" {
void func_0028D098(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_0028AB28(s32 a);
void func_0028C200(s32 a);
void func_00289B40(s32 a, s32 b);
}

extern "C" s32 func_001D0450(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    if (d != 0) func_0028D098(b, 0, c, e, 0);
    s32 r = func_0028D1D8(b, f, 0, 0, c, 0, 0, 0, 0, 0);
    if (r != 0) {
        func_00289E10(r, a);
        func_0028C200(r);
        if (func_0028AB28(r) != 0) {
            func_00289B40(r, 3);
            r = 0;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0518);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0548);

extern "C" void func_001D0570(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0578);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0680);

extern "C" s32 func_001D0788(void) {
    return D_00372D90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0790);

struct Pool1D07 {
    char* unk0;
    char* unk4;
    bool Contains(void* p) { return (char*)p >= unk0 && (char*)p < unk4; }
};

GP_DATA(D_0036D100);
GP_DATA(D_0036D0F0);
extern "C" void func_001D0798(void* p) {
    Pool1D07* a = D_0036D0F0[D_0036D100];
    if ((a && a->Contains(p)) || ((a = D_0036D0F0[D_0036D100 ^ 1]) && a->Contains(p))) {
        func_0011C2E8_p(a, p);
    } else if (p) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0848);

extern "C" s32 func_001D0900(s32 size) {
    s32 t = D_00371028[D_00371038];
    s32 r;
    if (t != 0) {
        r = func_0011C2A8(t);
        if (r == 0) {
            s32 h = D_00368A38[0];
            func_00119490(h, func_00119610(h, 1));
            r = Heap_Alloc(D_00368A38[0], size, 1, 0);
            func_001194B8(D_00368A38[0]);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38[0], size, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D09C0);

extern "C" void func_001D0F18(void) {
    func_001CE7C0();
}

extern "C" int func_001D0F38(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0F40);

extern "C" S001D0F68* func_001D0F68(S001D0F68* p) {
    p->unk4 = 0;
    p->unk18 = (VEnt*)D_0034B698;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

extern "C" void func_001D0F90(char* p, s32 flags) {
    *(void**)(p + 0x18) = D_0034B698;
    if (*(s32*)(p + 8) & 2) {
        func_0028DBD0();
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D0FF0(void) {
}

extern "C" void func_001D0FF8(void) {
}

extern "C" void func_001D1000(S001D0F68* p, void* a) {
    ((void (*)(void*, void*))p->unk18[3].fn)((char*)p + p->unk18[3].delta, a);
}

extern "C" void func_001D1028(void) {
}

extern "C" int func_001D1030(void) {
    return 2;
}

extern "C" s32 func_001D1038(S001D0F68* p, s32* q, void* a, void* b) {
    return ((s32 (*)(void*, s32, void*, void*))p->unk18[12].fn)((char*)p + p->unk18[12].delta, *q, a, b);
}

extern "C" void func_001D1068(S001D0F68* p, s32 v) {
    if (v != 0) {
        p->unk8 = (VEnt*)((s32)p->unk8 | 1);
    } else {
        p->unk8 = (VEnt*)((s32)p->unk8 & ~1);
    }
}

extern "C" void func_001D1090(void) {
}

extern "C" void func_001D1098(void) {
}

extern "C" void func_001D10A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D10A8);

struct S1D11 {
    char pad0[8];
    char* unk8;
    char pad0C[0x60];
    s32 unk6C;
    char pad70[0xE0];
    N1548* unk150;
    s32 unk154;
};

extern "C" void func_001D11B0(S1D11* p, s32 f) {
    p->unk8 = D_0034B850;
    p->unk154 |= 0x80;
    if (p->unk150 != 0) {
        do {
            N1548* n = p->unk150;
            p->unk150 = n->next;
            func_001D4C08(D_0036D3B0_m, n);
            if (n != 0) {
                VEnt* e = (VEnt*)(n->vt + 8);
                ((void (*)(char*, s32))e->fn)((char*)n + e->delta, 3);
            }
        } while (p->unk150 != 0);
    }
    if (p->unk6C != 0) {
        Heap_Free(D_00368A38[0], (void*)p->unk6C);
        p->unk6C = 0;
    }
    func_001CE990(p, f);
}

extern "C" void func_001D1270(void* q) {
    S1D14P* p = (S1D14P*)q;
    if ((*(s32*)((char*)p + 0xC) & 1) == 0) {
        N1548* n = (N1548*)p->unk150;
        if (n != 0) {
            do {
                VEnt* e = (VEnt*)(n->vt + 0x28);
                ((void (*)(char*))e->fn)((char*)n + e->delta);
                n = n->next;
            } while (n != 0);
        }
        func_001D0170(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D12E0);

extern "C" void func_001D1418(void) {
    func_001D12E0();
}

extern "C" void func_001D1438(void* q, s32 f) {
    S1D14P* p = (S1D14P*)q;
    if (f != p->Test(4)) {
        if (f) p->unk154 |= 4;
        else p->unk154 &= ~4;
        N1548* n = (N1548*)p->unk150;
        if (n != 0) {
            do {
                VEnt* e = (VEnt*)(n->vt + 0x48);
                ((void (*)(char*, s32))e->fn)((char*)n + e->delta, f);
                n = n->next;
            } while (n != 0);
        }
    }
}

extern "C" void func_001D14C0(void* q, s32 f) {
    S1D14P* p = (S1D14P*)q;
    if (f != p->Test(2)) {
        if (f) p->unk154 |= 2;
        else p->unk154 &= ~2;
        N1548* n = (N1548*)p->unk150;
        if (n != 0) {
            do {
                VEnt* e = (VEnt*)(n->vt + 0x40);
                ((void (*)(char*, s32))e->fn)((char*)n + e->delta, f);
                n = n->next;
            } while (n != 0);
        }
    }
}

extern "C" void func_001D1548(void* q) {
    S1D14P* p = (S1D14P*)q;
    N1548* n = (N1548*)p->unk150;
    if (n != 0) {
        do {
            VEnt* e = (VEnt*)(n->vt + 0x50);
            ((void (*)(char*))e->fn)((char*)n + e->delta);
            n = n->next;
        } while (n != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1598);

extern "C" s32 func_001D1610(S001D0F68* p, void* a, void* b) {
    return ((s32 (*)(void*, void*, void*))p->unk8[12].fn)((char*)p + p->unk8[12].delta, a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1638);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D17B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1910);

extern "C" void func_001D1998(void* self, s32 a) {
    char* p = (char*)self;
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    sp0 = 0;
    if (func_0027D870((void*)a, 0xA1DC81F9, &sp0, 0) != 0) {
        func_001CED20(p, sp0);
    }
    sp4 = 0;
    if ((func_0027D870((void*)a, 0xA7F6519E, &sp4, 0) ^ 1) != 0 && sp0 != 0 && func_00222F90(sp0) != 0) {
        sp4 = sp0;
    }
    sp8 = 0;
    if (func_0027D870((void*)a, 0xEE3494C5, &sp8, 0) != 0) {
        func_001CEDE0(p, sp8);
    }
    func_001CED98(p, sp4);
    if ((func_0027D870((void*)a, 0x0CBC121F, p + 0x54, 0) ^ 1) != 0) {
        s32 t = *(s32*)(p + 0x1C);
        if (t != 0) {
            *(s32*)(p + 0x54) = func_00224250(t, 1);
        } else {
            s32 u = *(s32*)(p + 0x28);
            s32* q = &spC;
            spC = 0;
            if (u != 0 && func_0027D870((void*)u, 0x63E613ED, q, 0) != 0) {
                *(s32*)(p + 0x54) = func_00224250(spC, 0);
            } else {
                *(s32*)(p + 0x54) = func_001D0788();
            }
        }
    }
    func_00223590(a, p + 0x80);
    func_00223628(a, p + 0xA0);
    if (func_0027DF00_k(a, 0x23627FD7) != 0) {
        *(s32*)(p + 0xC) |= 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1B28);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1D90);

extern "C" void func_001D1DD8(void* p, void* a) {
    f32 v = 0;
    func_0027D268(a, 0x7E832F08, &v, 1);
    func_001D1E20(p, v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1E20);

extern "C" int func_001D1EA8(void* a, void* params) {
    s32 v;

    func_0027D188(params, 0, &v, 0);
    return 1;
}

extern "C" int func_001D1ED8(S001D0F68* p, void* a) {
    ((void (*)(void*, void*, s32))p->unk8[11].fn)((char*)p + p->unk8[11].delta, a, 0);
    return 1;
}

extern "C" s32 func_001D1F08(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0xA1DC81F9, &v, 1);
    return func_001D1CF8(p, v) != 0;
}

extern "C" s32 func_001D1F58(char* p, void* a) {
    func_0027D2D8(a, 0xB9D31B0A, p + 0x80, 0);
    func_001D1548(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D2030);
