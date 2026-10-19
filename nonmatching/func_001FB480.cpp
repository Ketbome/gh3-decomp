#include "common.h"
// cflags: -funroll-loops

struct F1FB6 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

struct S1F9D_N {
    s32 unk0;
    S1F9D_N* unk4;
    char* unk8;
};

struct S1F9D_I {
    s32 unk0;
    S1F9D_N* unk4;
};

typedef int TI128 __attribute__((mode(TI)));

struct S1FADE8 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
};

extern "C" {
s32 func_0012CEE8(void* a, s32 b);
void func_0027DC58(s32 a, s32 b, s32* c, s32 d);
void func_00267760(s32 a, void* b, s32 c);
s32 func_001F9AA8(void);
s32 func_001F9B80(void);
void func_001FA348(int, int);
void func_001FB028(void*);
void func_001FB6C0(s32 self, s32 params);
f32 func_0010C2E0(f32 a, f32 b, f32 c);
f32 func_0011ED10(void);
void* operator_new(u32);
void* func_001FAC90(void*);
void func_001D0F68(void*);
extern char D_0038F5B0[];
void func_00276D68(u32, void*, int);
void func_001FB480(void*, TI128);
TI128 func_001EAEA0(s32 a, s32 b);
s32 func_0027D870(s32 a, s32 key, s32* v, s32 req);
s32 func_001EB300(s32 a);
s32 func_001EB338_i(s32 a) __asm__("func_001EB338");
TI128 func_001EB638_i(s32 a, s32 b) __asm__("func_001EB638");
void func_002676F0(s32 a, void* b);
void func_001D0F90(void* a, s32 b);
extern u8 D_0034F6F0[];
extern s32 D_00370AE0;
void func_0027D1F8(s32 p, u32 key, s32* v, s32 req);
void func_001FAF90(char* self, s32 params);
void* func_00268EB8(s32 a, s32 b, s32 c, s32 d);
void* func_001FB450_o(s32 a, s32 b) __asm__("func_001FB450");
s32 func_0027D268(s32 p, u32 key, f32* v, s32 d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9A48);

extern "C" s32 func_001F9A50(s32 a, u32 k) {
    s32 r = 0;
    if (k != 0x26205DB6) {
        if (k == 0x7E1940A1) {
            r = func_001F9AA8();
        }
    } else {
        r = func_001F9B80();
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9B80);

struct N9C {
    N9C* unk0;
    N9C* unk4;
    char* unk8;
};

struct It9C {
    s32 unk0;
    N9C* unk4;
    s32 unk8;
    s32 unkC;
};

struct VE9C {
    s16 delta;
    s16 pad;
    void (*fn)(char*, s32);
};

extern "C" {
void Heap_Free(void*, void*);
extern void* D_00368A38;
}

s32 func_001F9C58_d(char* self, s32 key) __asm__("func_001F9C58");
s32 func_001F9C58_d(char* self, s32 key) {
    It9C it, end, c, d, e;
    it.unk4 = *(N9C**)(self + 0x4C);
    end.unk4 = (N9C*)(self + 0x48);
    if (it.unk4 != end.unk4) {
        do {
            char* o = it.unk4->unk8;
            if (*(s32*)(o + 0x10) == key) {
                if (o) {
                    VE9C* v = (VE9C*)(*(char**)(o + 0x14) + 8);
                    v->fn(o + v->delta, 3);
                }
                N9C* n = it.unk4;
                c.unk4 = n;
                e.unk4 = n;
                N9C* nx = n->unk4;
                d.unk4 = n;
                c.unk4 = nx;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                Heap_Free(D_00368A38, n);
                end.unk4 = c.unk4;
                return 1;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (N9C*)(self + 0x48);
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

extern "C" s32 func_001F9D18(char* p, s32 v) {
    S1F9D_I it;
    S1F9D_I end;
    it.unk4 = *(S1F9D_N**)(p + 0x4C);
    end.unk4 = (S1F9D_N*)(p + 0x48);
    if (it.unk4 != end.unk4) {
        do {
            if (*(s32*)(it.unk4->unk8 + 0x10) == v) {
                return 1;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (S1F9D_N*)(p + 0x48);
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D68);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D70);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9E80);

extern "C" s32 func_001F9EC0(char* p) {
    return *(s32*)(p + 0x2C);
}

extern "C" s32 func_001F9EC8(char* p, s32 k) {
    S1F9D_I it;
    S1F9D_I end;
    s32 r;
    it.unk4 = *(S1F9D_N**)(p + 0x40);
    end.unk4 = (S1F9D_N*)(p + 0x3C);
    if (it.unk4 != end.unk4) {
        do {
            r = func_0012CEE8((char*)it.unk4 + 8, k);
            if (r != 0) {
                goto done;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (S1F9D_N*)(p + 0x3C);
        } while (it.unk4 != end.unk4);
    }
    r = 0;
done:
    return r != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9F40);

struct I1FA2 {
    s32 unk0;
    S1F9D_N* unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" {
void func_0012CAA8(void* a, s32 b);
s32 func_0012CF40(void* a, s32 b);
void Heap_Free(void* a, void* b);
extern void* D_00368A38;
}

extern "C" s32 func_001FA218(char* p, s32 k) {
    I1FA2 it, end, c, e2, cnt, d, e;
    it.unk4 = *(S1F9D_N**)(p + 0x40);
    end.unk4 = (S1F9D_N*)(p + 0x3C);
    if (it.unk4 != end.unk4) {
        do {
            if (func_0012CF40((char*)it.unk4 + 8, k) != 0) {
                s32 count = 0;
                S1F9D_N* sub = (S1F9D_N*)((char*)it.unk4 + 0x10);
                c.unk4 = *(S1F9D_N**)((char*)it.unk4 + 0x14);
                e2.unk4 = sub;
                cnt.unk4 = c.unk4;
                if (c.unk4 != sub) {
                    do {
                        count++;
                        cnt.unk4 = cnt.unk4->unk4;
                    } while (cnt.unk4 != sub);
                }
                if (count == 0) {
                S1F9D_N* n = it.unk4;
                c.unk4 = n;
                e.unk4 = n;
                S1F9D_N* nx = n->unk4;
                d.unk4 = n;
                c.unk4 = nx;
                ((S1F9D_N*)n->unk0)->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                func_0012CAA8((char*)n + 8, 2);
                Heap_Free(D_00368A38, n);
                end.unk4 = c.unk4;
                it.unk4 = c.unk4;
                }
                return 1;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (S1F9D_N*)(p + 0x3C);
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA330);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA348);

extern "C" void func_001FAC18() {
    func_001FA348(1, 0xFFFF);
}

extern "C" void* func_001FAC38() {
    return func_001FAC90(operator_new(0xE0));
}

extern "C" void func_001FAC60() {
    func_00276D68(0x07713C7B, D_0038F5B0, 0x10);
}

static inline TI128 MakeVec1FA(f32 x, f32 y, f32 z, f32 w) {
    TI128 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(hi) : "r"(hi), "r"(lo));
    return hi;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAC90);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD10);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD68);

extern "C" void func_001FADB8(char* p) {
    TI128 a = *(TI128*)(p + 0xB0);
    *(TI128*)(p + 0xC0) = a;
    *(TI128*)(p + 0xB0) = *(TI128*)(*(char**)(p + 0xC) + 0x80);
    func_001FB480(p, a);
}

extern "C" void func_001FADE8(S1FADE8* p) {
    p->v2();
}

extern "C" s32 func_001FAE10(void* p) {
    func_001FB028(p);
    return 1;
}

extern "C" s32 func_001FAE30(void* p, s32 q) {
    func_001FB6C0((s32)p, q);
    return 1;
}

struct E1FAE {
    s32 unk0;
    char pad4[0x34];
};

struct S1FAE50 {
    char pad0[0x40];
    E1FAE unk40[2];
};

extern "C" s32 func_001FAE50(S1FAE50* p, s32 params) {
    s32 id = 0;
    func_0027DC58(params, 0, &id, 0);
    func_00267760(D_00370AE0, p, id);
    for (s32 i = 0; i < 2; i++) {
        if (p->unk40[i].unk0 == id) {
            p->unk40[i].unk0 = 0;
        }
    }
    return 1;
}

extern "C" s32 func_001FAEC0(void* p, s32 q) {
    func_001FAF90((char*)p, q);
    return 1;
}

extern "C" s32 func_001FAEE0() {
    return 2;
}

struct Q1FAE {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 v12(int);
};

struct A1FAE {
    s32 unk0;
    s32 unk4;
    s32 (Q1FAE::*unk8)(int, int);
};

extern "C" s32 func_001FAEE8(Q1FAE* p, A1FAE* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001FAF88(void) {
}

struct A1FAF {
    char pad0[0x1C];
    s32 unk1C[9];
};

extern "C" void func_001FAF90(char* self, s32 params) {
    s32 a = -1;
    s32 b = 0;
    func_0027D1F8(params, 0x7321A8D6, &a, 0);
    func_0027DC58(params, 0, &b, 0);
    if (a != -1 && b != 0) {
        if (a < 9 && a != -1) {
            ((A1FAF*)self)->unk1C[a] = b;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB028);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB390);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB3D0);

struct S1FB3 {
    char pad0[0xD4];
    s32 unkD4;
};

extern "C" s32 func_001FB3D8(S1FB3* p, s32 a, TI128* out) {
    if (a) {
        if (p->unkD4) {
            if (func_001EB338_i(p->unkD4)) {
                *out = func_001EB638_i(p->unkD4, a + 0x80);
                return 1;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB450);

struct S1FB6;
extern "C" void func_001FB618(void* self, S1FB6* p);

struct E1FB4 {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    char pad10[8];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char pad2C[4];
    s32 unk30;
    u32 unk34;
};

struct O1FB4 {
    char pad0[0x14];
    f32 unk14;
    char pad18[8];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

struct P1FB4 {
    char pad0[0x3C];
    E1FB4 e[2];
    char pad_AC[4];
    char unkB0[1];
};

extern "C" {
u32 func_0011EF10_u(void) __asm__("func_0011EF10");
s32 func_0015D5C0_i(char*, f32*) __asm__("func_0015D5C0");
s32 func_001FB938_i(s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32) __asm__("func_001FB938");
}

extern "C" void func_001FB480(void* pp, TI128 unused) {
    P1FB4* p = (P1FB4*)pp;
    register f32 zero asm("$f20");
    s32 i;
    f32 t;
    u32 now = func_0011EF10_u();
    for (i = 0; i < 2; i++) {
        s32 off = i * 0x38;
        if (*(s32*)((char*)p + off + 0x40) != 0) {
            E1FB4* q = (E1FB4*)((char*)p + (off + 0x3C));
            func_001FB618(p, (S1FB6*)q);
            if (now >= q->unk34) {
                s32 ok = func_0015D5C0_i(p->unkB0, &t);
                zero = 0.0f;
                f32 d = q->unkC;
                f32 lim = 25.0f;
                if (d != zero) lim = d;
                if (ok != 0 && t < lim + 6.0f) {
                    s32 h = func_001FB938_i((s32)p, q->unk4, q->unk8, 0, q->unk30, 0, q->unk0 & 1, 1, q->unk1C, q->unk18, d);
                    if (h != 0) {
                        O1FB4* o = (O1FB4*)func_00268EB8(D_00370AE0, (s32)p, h, 0);
                        if (o != 0) {
                            o->unk24 = q->unk24;
                            o->unk20 = q->unk20;
                            o->unk2C = q->unk24 * 0.01f;
                            o->unk28 = q->unk28;
                            o->unk14 = zero;
                        }
                        q->unk4 = 0;
                    }
                } else {
                    q->unk34 = now + (s32)((t - lim) * 66.66667f) + 0x14D;
                }
            }
        }
    }
}

struct S1FB6 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    char pad18[8];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
};

extern "C" void func_001FB618(void* self, S1FB6* p) {
    if (p->unk20 != p->unk10) {
        p->unk10 = func_0010C2E0(p->unk20, p->unk10, p->unk28 * (func_0011ED10() * 60.0f));
    }
    if (p->unk24 != p->unk14) {
        p->unk14 = func_0010C2E0(p->unk24, p->unk14, p->unk2C * (func_0011ED10() * 60.0f));
    }
}

extern "C" void func_001FB6C0(s32 self, s32 params) {
    f32 a = 100.0f;
    f32 b = 100.0f;
    s32 id;
    func_0027DC58(params, 0, &id, 0);
    F1FB6* o = (F1FB6*)func_00268EB8(D_00370AE0, self, id, 1);
    if (o != 0 || (o = (F1FB6*)func_001FB450_o(self, id), o != 0)) {
        if (func_0027D268(params, 0x330F3415, &a, 0) != 0) {
            o->unk24 = o->unk1C * a * 0.01f;
            if ((func_0027D268(params, 0xDAA9A3C2, (f32*)((char*)o + 0x2C), 0) ^ 1) != 0) {
                o->unk14 = o->unk24;
            }
        }
        if (func_0027D268(params, 0xEE616C13, &b, 0) != 0) {
            o->unk20 = o->unk18 * b * 0.01f;
            if ((func_0027D268(params, 0x7B090774, (f32*)((char*)o + 0x28), 0) ^ 1) != 0) {
                o->unk10 = o->unk20;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB820);

struct A1FB9 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00268F40(s32 heap, s32 e, A1FB9* a, s32 b, s32 c, s32 d);

extern "C" void func_001FB938(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 x, f32 y, f32 z) {
    A1FB9 l;
    l.unk8 = x;
    l.unk4 = y;
    l.unkC = z;
    l.unk10 = t0;
    l.unk14 = a2;
    l.unk18 = a3;
    s32 h = D_00370AE0;
    l.unk0 = 0;
    if (t2 != 0) {
        l.unk0 = 1;
    }
    func_00268F40(h, a1, &l, a0, t1, t3);
}

struct V1FB9 {
    int a;
    int b;
};

struct E1FB9 {
    u32 key;
    u32 type;
    V1FB9 v;
};

extern E1FB9 T1FB9[] __asm__("D_0038F5B0");
extern V1FB9 V1FB9_0[] __asm__("D_0036E5E8");
extern V1FB9 V1FB9_1[] __asm__("D_0036E5F0");
extern V1FB9 V1FB9_2[] __asm__("D_0036E5F8");
extern V1FB9 V1FB9_3[] __asm__("D_0036E600");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_001FB998(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E1FB9* e = T1FB9;
        V1FB9 t;
        e->key = 0xAFA20E18;
        t = *V1FB9_0;
        e->type = 0x07713C7B;
        e->v = t;
        e++;
        e->key = 0x3E5E8023;
        t = *V1FB9_1;
        e->type = 0x07713C7B;
        e->v = t;
        e++;
        e->key = 0x4E4132D6;
        t = *V1FB9_2;
        e->type = 0x07713C7B;
        e->v = t;
        e++;
        e->key = 0xE8347171;
        t = *V1FB9_3;
        e->type = 0x07713C7B;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0x07713C7B;
        e->v = t;
    }
}
