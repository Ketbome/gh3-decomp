#include "common.h"

struct S1D7C28 {
    void* unk0;
};

struct S1D7EE8_N {
    char pad0[0x8];
    void* unk8;
};

struct S1D7EE8_I {
    s32 unk0;
    S1D7EE8_N* unk4;
};

struct S1D7EE8 {
    char pad0[0x8];
    S1D7EE8_N* unk8;
};

struct S1D7F00 {
    char pad0[0x20];
    void* unk20;
};

struct S1D8150_Q {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x18];
    s32 unk2C;
    char pad30[0x10];
    s32 unk40;
};

struct S1D80D8 {
    char pad0[0x20];
    u32 unk20;
    s32 unk24;
    s32 unk28;
    virtual void v1();
    virtual void v2(S1D8150_Q* q);
    virtual void v3(S1D8150_Q* q);
    virtual void v4(S1D8150_Q* q, s32 v);
};

struct S1D8058_N {
    char pad0[0xC];
    S1D8058_N* unkC;
    S1D8058_N* unk10;
};

extern "C" char D_0034BFF0[];

struct S1D7F20_N {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    S1D7F20_N* unkC;
    S1D7F20_N* unk10;
    void* unk14;
    void Init() {
        unk4 = 0xFFFFFFFF;
        unk8 = 0;
        unkC = this;
        unk10 = this;
        unk14 = D_0034BFF0;
    }
};

struct S1D7F20 {
    char pad0[0x4];
    S1D7F20_N unk4;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    void* unk2C;
};

struct S1D67C8 {
    char pad0[0x2C];
    u32 unk2C;
    char pad30[0xC];
    u32 unk3C;
};

struct S1D67C8_R {
    char pad0[0x9C];
    s32 unk9C;
};

struct S1D67C8_Q {
    char pad0[0x160];
    u32 unk160;
};

extern "C" {
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void* func_001D8180(void* p);
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BFA8[];
extern char D_0034BFF0[];
extern s32 D_0036D554[] __attribute__((section(".sdata")));
void func_001DA368(s32 a, void* q, s32 b, s32 c);
u32 func_0011C030(void* p);
void func_001194B8(s32 heap, u32 v);
s32 func_001D7710(S1D80D8* p);
void func_00119490(s32 heap, s32 v);
void* operator_new(u32 size);
void func_001D5250(void*, void*, s32, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6598);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6730);

extern "C" void func_001D6738(S1D67C8* p, void* a) {
    s32 h = D_00368A38[0];
    func_00119490(h, func_001D7710((S1D80D8*)p));
    p->unk3C = func_0011C030((void*)func_001D7710((S1D80D8*)p));
    ((S1D67C8_R*)func_001D7710((S1D80D8*)p))->unk9C = 0;
    func_001D7710((S1D80D8*)p);
    func_001D5250(operator_new(0x180), a, *(s32*)((char*)p + 0x74), 0);
}

extern "C" void func_001D67C8(S1D67C8* p, S1D67C8_Q* q) {
    func_001D7710((S1D80D8*)p);
    ((S1D67C8_R*)func_001D7710((S1D80D8*)p))->unk9C = 1;
    u32 t = func_0011C030((void*)func_001D7710((S1D80D8*)p));
    u32 d = p->unk2C;
    s32 h = D_00368A38[0];
    q->unk160 = (p->unk3C - t) / d;
    func_001194B8(h, d);
}

struct P1D68 {
    char pad0[8];
    s16 pad8;
    char pad0A[0x6A];
    s32 unk74;
};

struct VE1D68 {
    s16 delta;
    s16 pad;
    void (*fn)(void*, void*, void*);
};

struct VF1D68 {
    s16 delta;
    s16 pad;
    void (*fn)(void*);
};

struct G1D68 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[1];
};

struct Q1D68 {
    char pad0[8];
    char* unk8;
    char pad0C[0x48];
    s32 unk54;
};

struct S1D68 {
    char pad0[0x2C];
    char* unk2C;
};

extern "C" {
s32 func_001D6598_b(void* p, s32 b, s32 c, s32 d) __asm__("func_001D6598");
void* func_001D6738_r(void* p, s32 a) __asm__("func_001D6738");
void func_001D6BA0_a(void* p, s32 a) __asm__("func_001D6BA0");
void func_001D6BA8_a(void* p, s32 a) __asm__("func_001D6BA8");
void func_001CEDE0(void* p, s32 k);
void func_001D1998(void* p, s32 a);
void func_001D17B0(void* p, s32 a, s32 b);
void func_001D54D8(void* p);
void func_001D67C8_r(void* p, void* q) __asm__("func_001D67C8");
extern G1D68* D_0036F658[] __attribute__((section(".sdata")));
extern S1D68* D_0036D3B0[] __attribute__((section(".sdata")));
}

extern "C" void* func_001D6840(P1D68* p, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    if ((func_001D6598_b(p, a3, 0, 0) ^ 1) != 0) {
        if (a5 == 0) {
            if (a3 != 0) {
                return 0;
            }
            s32 t = p->unk74;
            s32 b = 0;
            if (t == 0x3B5737A6 || t == 0x69B05E2C) {
                b = 1;
            }
            if (b == 0) {
                goto out;
            }
        }
        func_001D6BA0_a(p, 0);
        func_001D6BA8_a(p, 0);
    out:
        return 0;
    }
    Q1D68* o = (Q1D68*)func_001D6738_r(p, a3);
    func_001CEDE0(o, 0xCDEB9229);
    func_001D1998(o, a2);
    G1D68* g = D_0036F658[0];
    register S1D68* sg asm("$6") = D_0036D3B0[0];
    s32 t54 = o->unk54;
    s32 n = g->unk18 + 1;
    g->unk18 = n;
    *(s32*)(n * 4 + (s32)g + 0x1C) = t54;
    VE1D68* e = (VE1D68*)(sg->unk2C + 0x10);
    e->fn((char*)sg + e->delta, o, sg);
    func_001D17B0(o, a1, a2);
    if (a4 != 0) {
        VF1D68* f = (VF1D68*)(o->unk8 + 0x50);
        f->fn((char*)o + f->delta);
        func_001D54D8(o);
        func_001D67C8_r(p, o);
    }
    g->unk18 = g->unk18 - 1;
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D69D0);

struct N1D6A {
    N1D6A* unk0;
    N1D6A* unk4;
    int unk8;
};

struct It1D6A {
    int unk0;
    N1D6A* unk4;
    int unk8;
    int unkC;
};

struct Pr1D6A {
    char unk0;
    char unk1;
    char pad2[2];
    int unk4;
};

extern "C" s32 func_00119610(s32, s32);
extern "C" s32 D_1D6A_h __asm__("D_00368A38");
extern "C" void func_001194B8_1(s32) __asm__("func_001194B8");

extern "C" void func_001D6AB0(char* list, int val) {
    Pr1D6A pr;
    It1D6A end, a, b, c, d, e;
    s32 h = D_1D6A_h;
    func_00119490(h, func_00119610(h, 1));
    N1D6A* first = *(N1D6A**)(list + 0xC);
    char* tail = list + 8;
    pr.unk4 = val;
    pr.unk1 = 0;
    end.unk4 = (N1D6A*)tail;
    a.unk4 = first;
    if (a.unk4 != end.unk4) {
        do {
            if (a.unk4->unk8 == pr.unk4) {
                N1D6A* n = a.unk4;
                c.unk4 = n;
                e.unk4 = n;
                N1D6A* nx = n->unk4;
                d.unk4 = n;
                c.unk4 = nx;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                Heap_Free(D_1D6A_h, n);
                b.unk4 = c.unk4;
                a.unk4 = c.unk4;
            } else {
                a.unk4 = a.unk4->unk4;
            }
        } while (a.unk4 != end.unk4);
    }
    func_001194B8_1(D_1D6A_h);
}

extern "C" void func_001D6BA0(void) {
}

extern "C" void func_001D6BA8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6BB8);

extern "C" s32 func_001D7710(S1D80D8* p) {
    return p->unk24;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7718);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7800);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7988);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7BD0);

extern "C" void func_001D7C28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7C68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7CA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7CE8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7D28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7D68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7DA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7DE8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7E28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7E68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D7EA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void* func_001D7EE8(S1D7EE8* p) {
    S1D7EE8_I it;
    it.unk4 = p->unk8;
    return it.unk4->unk8;
}

extern "C" void* func_001D7F00(S1D7F00* p) {
    return func_001D8180(p->unk20);
}

extern "C" S1D7F20* func_001D7F20(S1D7F20* p) {
    p->unk2C = D_0034BFA8;
    p->unk4.Init();
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk28 = 0;
    return p;
}

struct N1D7F {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    N1D7F* unkC;
    N1D7F* unk10;
    N1D7F* Get() { return unk4 == 0xFFFFFFFF ? 0 : this; }
};

struct P1D7F {
    char pad0[4];
    N1D7F unk4;
    char pad18[8];
    u32 unk20;
};

struct Q1D7F {
    char pad0[0x10];
    P1D7F* unk10;
    char pad14[0x18];
    s32 unk2C;
    char pad30[8];
    N1D7F unk38;
};

extern "C" {
extern s32 D_00372DA8;
void func_001CED20(void* p, s32 v);
s32 func_001DAB18(s32 h, void* a, void* b, void* c, s32 d);
void func_001DA1F8(s32 h, void* p);
}

extern "C" void func_001D7F68(P1D7F* p, Q1D7F* q) {
    N1D7F* sent = &p->unk4;
    N1D7F* node = &q->unk38;
    s32 h = D_0036D554[0];
    q->unk10 = p;
    N1D7F* n = sent->unkC;
    s32 key = node->unk8;
    N1D7F* f;
    while ((f = n->Get()) != 0) {
        if (!(key < f->unk8)) {
            N1D7F* last = f->unk10;
            node->unkC = f;
            node->unk10 = last;
            f->unk10->unkC = node;
            f->unk10 = node;
            goto done;
        }
        n = f->unkC;
    }
    {
        N1D7F* last = sent->unk10;
        node->unkC = sent;
        node->unk10 = last;
        sent->unk10->unkC = node;
        sent->unk10 = node;
    }
done:
    p->unk20 = 0xFFFFFFFF;
    if (q->unk2C == D_00372DA8) {
        func_001CED20(q, func_001DAB18(h, node, sent, p, key));
    }
    func_001DA1F8(h, q);
}

extern "C" void func_001D8058(S1D80D8* p, S1D8150_Q* q) {
    func_001DA368(D_0036D554[0], q, p->unk24, p->unk28);
    S1D8058_N* n = (S1D8058_N*)((char*)q + 0x38);
    if (n->unk10 != n) {
        n->unk10->unkC = n->unkC;
        n->unkC->unk10 = n->unk10;
        n->unkC = n;
        n->unk10 = n;
        q->unk10 = 0;
        p->unk20 = 0xFFFFFFFF;
    }
}

extern "C" void func_001D80D8(S1D80D8* p, S1D8150_Q* q, s32 v) {
    p->unk28 = 1;
    p->unk24 = v;
    p->v3(q);
    q->unk2C = v;
    p->v2(q);
    p->unk28 = 0;
}

extern "C" void func_001D8150(S1D80D8* p, S1D8150_Q* q, s32 v) {
    q->unk40 = v;
    p->v4(q, q->unk2C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D8180);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D8208);

struct N1D82 {
    char pad0[0xC];
    N1D82* unkC;
    N1D82* unk10;
    void* unk14;
};

struct VE1D82 {
    s16 delta;
    s16 pad;
    void (*fn)(void*, s32);
};

struct V1D82 {
    char pad0[0x10];
    VE1D82 unk10;
};

struct O1D82 {
    char pad0[0x18];
    V1D82* unk18;
};

struct T1D82 {
    char pad0[4];
    N1D82 unk4;
    char pad1C[0x10];
    void* unk2C;
    N1D82 unk30;
    O1D82* unk48;
};

extern "C" {
extern char D_0034BF40[];
extern char D_0033B510[];
extern char func_001D0548_d[] __asm__("func_001D0548");
extern char func_001D0518_d[] __asm__("func_001D0518");
void func_001D83D0(void* a, void* b, s32 c);
}

extern "C" void func_001D82D8(T1D82* p, s32 flags) {
    p->unk2C = D_0034BF40;
    func_001D83D0(p, func_001D0548_d + 0x10, 0);
    func_001D83D0(p, func_001D0518_d + 0x10, 0);
    O1D82* o = p->unk48;
    if (o != 0) {
        VE1D82* e = &o->unk18->unk10;
        e->fn((char*)o + e->delta, 3);
    }
    N1D82* n = &p->unk30;
    n->unk14 = D_0033B510;
    n->unk10->unkC = n->unkC;
    N1D82* m = &p->unk4;
    s32 f = flags & 1;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    p->unk2C = D_0034BFA8;
    m->unk14 = D_0033B510;
    m->unk10->unkC = m->unkC;
    m->unkC->unk10 = m->unk10;
    m->unkC = m;
    m->unk10 = m;
    if (f != 0) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D83D0);
