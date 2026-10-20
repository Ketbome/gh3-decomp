#include "common.h"

struct V2208 {
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(f32 f);
};

struct P2208 {
    char pad0[0x1C];
    V2208* unk1C;
    char pad20[0x34];
    s32 unk54;
    s32 unk58;
};

struct G2202 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[1];
};

struct R2202 {
    char pad0[8];
    f32 unk8;
};

struct Q2202 {
    char pad0[0xC];
    R2202* unkC;
};

struct P2202 {
    char pad0[0xC];
    char* unkC;
    char pad10[0x5C];
    s32 unk6C;
};

struct VEntry21F {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21Fb {
    char pad0[0x1C];
    void* unk1C;
};

struct S21F {
    char pad0[0xC];
    int unkC;
    char pad10[0x8];
    VEntry21F* unk18;
    void* unk1C;
    char pad20[0x14];
    char unk34[0x4];
    int unk38;
    S21Fb* unk3C;
    char pad40[0x24];
    void* unk64;
};

extern "C" {
void* operator_new(u32 size);
void* func_00221A88(void*);
void func_00276D68(u32, void*, int);
extern u8 D_00390790[];
void func_001F62D0(void*);
void func_001F6440(void*);
void func_00220948(S21F*, int);
S21F* func_001D1CF8(void*, u32);
void* func_00133F60(void*);
void func_001150E0(void*, void*);
extern u8 D_00351D18[];
void func_0012FA98(void*, int);
void func_0012FAC8(void*, int, int);
int func_00205B48(int, int);
extern G2202* D_0036F658[] __attribute__((section(".sdata")));
void* func_0015FAA0(s32 a, s32 b, s32 c);
f32 func_0011ED10(void);
void func_00220A80(char* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(s32 h, void* p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_0021FB88);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_0021FDB0);

struct O21FE {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct C21FE {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

struct P21FE {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    u32 unk4;
    s32 unk8;
};

extern "C" {
bool func_0027D870_b(s32, u32, s32*, s32) __asm__("func_0027D870");
s32 func_0022B168_s(s32, s32) __asm__("func_0022B168");
C21FE* func_0027B300_c(s32, C21FE*) __asm__("func_0027B300");
s32 func_0021FEF0(s32 ctx, O21FE* o);
}

extern "C" s32 func_0021FEF0(s32 ctx, O21FE* o) {
    s32 ok = 1;
    s32 key = 0;
    s32* kp = &key;
    s32 k2;
    bool missing = !func_0027D870_b(o->unk0, 0x98549BA4, kp, 0);
    s32 r;
    if (missing) {
        r = 0;
    } else {
        for (;;) {
            if (o->unk8 != 0) {
                bool m1 = !func_0027D870_b(o->unk8, *kp, &k2, 0);
                if (!m1) goto upd;
            }
            if (o->unk4 != 0) {
                bool m2 = !func_0027D870_b(o->unk4, *kp, &k2, 0);
                if (!m2) goto upd;
            }
            break;
        upd:
            *kp = k2;
        }
        r = 1;
    }
    s32 d = (s32)D_0036F658[0];
    if (r != 0 && func_0022B168_s(d, key) == 0 && func_0022B168_s(d, key) == 0) return 0;
    C21FE* c = func_0027B300_c(o->unk0, 0);
    while (c) {
        s32 t = c->unk0 & 0xFE00;
        if (t == 0x1400) {
            O21FE n;
            n.unk0 = c->unk8;
            n.unk4 = o->unk4;
            n.unk8 = 0;
            if (func_0021FEF0(ctx, &n) == 0) ok = 0;
        } else if (t == 0x1800) {
            P21FE* pp = (P21FE*)c->unk8;
            if (pp->unk2 == 0xA) {
                u32 i = 0;
                if (pp->unk4 != 0) {
                    do {
                        s32 q = pp->unk4 == 1 ? pp->unk8 : ((s32*)pp->unk8)[i];
                        O21FE n;
                        n.unk0 = q;
                        n.unk4 = o->unk4;
                        n.unk8 = 0;
                        i++;
                        if (func_0021FEF0(ctx, &n) == 0) ok = 0;
                    } while (i < pp->unk4);
                }
            }
        }
        c = func_0027B300_c(o->unk0, c);
    }
    return ok;
}

extern "C" void func_00220108(void) {
}

extern "C" void func_00220110(void) {
}

extern "C" void func_00220118(S21F* self, void* a) {
    VEntry21F* e;
    self->unk1C = a;
    e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220148);

extern "C" f32 func_00220270(P2202* p, s32 k) {
    G2202* g = D_0036F658[0];
    s32 t = *(s32*)(p->unkC + 0x54);
    f32 r = 1.0f;
    s32 n = g->unk18 + 1;
    g->unk18 = n;
    *(s32*)(n * 4 + (s32)g + 0x1C) = t;
    Q2202* q = (Q2202*)func_0015FAA0(k, 0, 1);
    if (q != 0 || (q = (Q2202*)func_0015FAA0(p->unk6C, 0, 1), q != 0)) {
        r = q->unkC->unk8;
    }
    g->unk18 = g->unk18 - 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220318);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002204D0);

extern "C" void func_002204D8(S21F* p) {
    u8* d = D_00351D18;
    func_001150E0(func_00133F60(p->unk3C->unk1C), d);
}

extern "C" void func_00220518(char* p, int a1, int a2) {
    if (*(int*)(p + 0x38)) func_0012FA98(p + 0x34, *(int*)(p + 0xC));
    *(int*)(p + 0x38) = a2;
    func_0012FAC8(p + 0x34, a1, *(int*)(p + 0xC));
}

extern "C" void func_00220578(S21F* p, int a) {
    if (p->unk38 == a) {
        func_0012FA98(p->unk34, p->unkC);
        p->unk38 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002205B8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002206C8);

extern "C" void func_002207F0(S21F* p) {
    func_001F62D0(p->unk3C);
    func_00220948(p, 0);
}

extern "C" void func_00220828(S21F* p) {
    func_001F6440(p->unk3C);
    func_00220948(p, 1);
}

extern "C" void* func_00220860(S21F* self) {
    if (!self->unk64) {
        return self->unk1C;
    }
    return func_001D1CF8(self->unk64, 0x8536DBA5)->unk1C;
}

extern "C" void func_00220898(void* pv) {
    P2208* p = (P2208*)pv;
    if (func_0011ED10() != 0.0f) {
        func_00220A80((char*)p);
        if (p->unk1C != 0) {
            p->unk1C->v5(func_0011ED10());
        }
        if (p->unk54 != 0) {
            func_002207F0((S21F*)p);
        } else if (p->unk58 != 0) {
            func_00220828((S21F*)p);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220948);

struct BF21F {
    u64 pad : 1;
    u64 b0 : 1;
    u64 b1 : 1;
    bool B0() { return b0; }
    bool B1() { return b1; }
};

extern "C" void func_00220A80(char* p) {
    if (*(int*)(p + 0x20) == 0) {
        *(int*)(p + 0x54) = 0;
        return;
    }
    char* o = *(char**)(p + 0x40);
    if (o) {
        BF21F f = *(BF21F*)(*(char**)(o + 0x210) + 0x50);
        int v = 0;
        if (f.B0()) v = f.B1() ^ 1;
        if (!v) {
            *(int*)(p + 0x54) = 0;
            return;
        }
    }
    if (*(int*)(p + 0x44)) {
        *(int*)(p + 0x54) = func_00205B48(*(int*)(p + 0x44), 0);
    } else {
        *(int*)(p + 0x54) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220B10);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220FE8);

extern "C" void func_002210B8(char* p) {
    register char* t asm("$6") = *(char**)(p + 0x1C);
    if (t != 0) {
        VEntry21F* e = (VEntry21F*)(*(char**)(t + 0x14) + 0x10);
        ((void (*)(char*, s32, char*))e->fn)(t + e->delta, 3, t);
        *(char**)(p + 0x1C) = 0;
    }
    void* q = *(void**)(p + 0x24);
    if (q != 0) {
        Heap_Free(D_00368A38[0], q);
        *(void**)(p + 0x24) = 0;
    }
    if (*(int*)(p + 0x38)) {
        func_0012FA98(p + 0x34, *(int*)(p + 0xC));
        *(int*)(p + 0x38) = 0;
    }
    char* l = p + 0x48;
    char* e2 = p + 0x4C;
    char* c = *(char**)(l + 8);
    *(char**)(l + 8) = e2;
    *(char**)(l + 4) = e2;
    if (c != e2) {
        char* end = e2;
        asm("" : "+r"(end));
        char* x = c;
        do {
            c = *(char**)(c + 4);
            Heap_Free(D_00368A38[0], x);
            x = c;
        } while (c != end);
    }
}

struct KV2211 {
    s32 key;
    f32 val;
};

struct N2211 {
    N2211* unk0;
    N2211* unk4;
    KV2211 kv;
};

static inline KV2211& Deref2211(N2211* n) {
    return n->kv;
}

struct I2211 {
    s32 unk0;
    N2211* unk4;
};

extern "C" {
s32 func_00119610(s32, s32);
void func_00119490(s32, s32);
void func_001194B8(s32);
void* Heap_Alloc(s32, s32, s32, s32);
}

extern "C" void func_00221178(s32 obj, s32 key, f32 val) {
    I2211 a;
    s32 head = obj + 0x48;
    s32 e = obj + 0x4C;
    a.unk4 = *(N2211**)(head + 8);
    {
        I2211 end;
        N2211* f = *(N2211**)(head + 8);
        end.unk4 = (N2211*)e;
        if (f != (N2211*)e) {
            a.unk4 = f;
            do {
                N2211* n = a.unk4;
                if (Deref2211(n).key == key) {
                    Deref2211(n).val = val;
                    return;
                }
                end.unk4 = (N2211*)e;
                a.unk4 = n->unk4;
            } while (a.unk4 != end.unk4);
        }
    }
    {
        KV2211 kv;
        kv.key = key;
        kv.val = val;
        s32 g = D_00368A38[0];
        func_00119490(g, func_00119610(g, 0xA));
        I2211 d;
        I2211 b;
        I2211 c;
        N2211 elem;
        N2211* s = a.unk4;
        b.unk4 = s;
        c.unk4 = s;
        N2211* prev = s->unk0;
        N2211* node = (N2211*)Heap_Alloc(D_00368A38[0], 0x10, 1, 0);
        elem.unk0 = prev;
        elem.unk4 = s;
        elem.kv = kv;
        if (node) {
            *node = elem;
        }
        s->unk0 = node;
        node->unk0->unk4 = node;
        N2211* nx = *(N2211**)b.unk4;
        b.unk4 = nx;
        d.unk4 = nx;
        func_001194B8(D_00368A38[0]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002212B8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221310);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221318);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002219D8);

extern "C" int func_00221A00(void) {
    return 1;
}

extern "C" int func_00221A08(void) {
    return 1;
}

extern "C" int func_00221A10(void) {
    return 1;
}

extern "C" int func_00221A18(void) {
    return 1;
}

extern "C" int func_00221A20(void) {
    return 1;
}

extern "C" int func_00221A28(void) {
    return 1;
}

extern "C" void* func_00221A30(void) {
    return func_00221A88(operator_new(0x40));
}

extern "C" void func_00221A58(void) {
    func_00276D68(0xB38129F1, D_00390790, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221A88);
