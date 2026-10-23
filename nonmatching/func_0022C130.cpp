#include "common.h"

struct S22B {
    char pad0[0x10];
    int unk10;
    char pad14[0x8];
    int unk1C;
    u32 unk20_0 : 24;
    u32 unk20_24 : 7;
    u32 unk20_31 : 1;
};

struct VE22BF {
    s16 delta;
    s16 pad;
    s32 (*fn)(char*);
};

extern "C" {
s32 func_00119500(s32 a);
void func_0011AD80(s32 a, s32 b);
void func_0011A560(char* p, s32 a, s32 b);
s32 func_0011A380(s32 a);
void func_0011A568(void);
void func_0011AEB0(s32 a);
s32 func_0030B550_4(char* buf, void* fmt, s32 v, void* s) __asm__("func_0030B550");
extern u8 D_0036F740[];
extern u8 D_00352CA0[];
extern s32 D_00368A38;
extern u8 D_00352CB8[];
extern u8 D_00352F78[];
extern u8 D_0036F838[];
extern u8 D_003532D0[];
void func_0022C4F0(int, int);
void func_0011A470(int);
extern u8 D_00352F88[];
void* func_0022BA90(void*);
extern u8 D_00353480[];
int func_001162E8(void*);
void func_00116320(void*);
void func_00116340(void*);
extern u8 D_00372E50;
extern u8 D_00393AD8[];
void* func_0022C3C8(void);
void func_0030A2F4(void*, int, int);
extern int D_0036F748;
extern u8 D_0041ACB0[];
void func_0022C030(int*);
void func_0014E708(int, int);
void func_00150DE8(int);
void func_002886F8(int);
void func_0028D700(int);
int func_0022BCE0(void*, int, int, int, int, int);
int func_0011E008(int);
int func_0011DC18(int);
void func_0022C498(void*);
void func_0011D220(int);
int func_0014F130(void);
void func_0030B550(int, void*, int, int);
extern u8 D_0036F8D8[];
void func_0022BBB0(void*, int, int, int, int, int);
char* strcpy(char*, const char*);
void func_00152548(char*, char*, int);
struct LI22C {
    s32 unk0;
    s32* unk4;
};
struct LN22C {
    char pad0[4];
    LN22C* unk4;
    s32* unk8;
};
int func_0030E720(int, void*);
int func_0030B550_3(int, void*, int) __asm__("func_0030B550");
extern u8 D_0036F8E0[];
extern u8 D_0036F8E8[];
void func_00287EB0(int, int, int);
int func_0028DAB8(int);
int func_0022BE60_3(char*, int, int) __asm__("func_0022BE60");
int func_0014E560(int, int, int, int, int, int, int);
void func_00150EB8(int, int, int);
int func_001510D8(int, int);
void* operator_new(u32 size);
void* func_001244C8(void* p);
int func_001246F0(void* p, int a, int b, int c);
void func_00275F08(u32 a, int b);
}

struct VE22B {
    s16 delta;
    s16 unk2;
    void* fn;
};

#define VCALL22B(o, vp, off, T) ((T)((VE22B*)(*(char**)((char*)(o) + (vp)) + (off)))->fn)
#define VADJ22B(o, vp, off) ((char*)(o) + ((VE22B*)(*(char**)((char*)(o) + (vp)) + (off)))->delta)

extern "C" int func_0022BD90(char* p) {
    func_0022C030((int*)p);
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, 0);
    *(u32*)(p + 0x20) &= 0x80FFFFFF;
    return 0;
}

extern "C" void func_0022BDE8(S22B* self) {
    self->unk20_24 = 5;
}

inline int type_0022BE08(S22B* self) {
    return self->unk20_24;
}

extern "C" int func_0022BE08(S22B* self) {
    return type_0022BE08(self) == 4;
}

extern "C" int func_0022BE20(char* p) {
    struct VT {
        char pad[0x68];
        s16 delta;
        s16 pad6A;
        int (*fn)(char*, int, u32);
    };
    VT* v = *(VT**)(p + 0x34);
    return v->fn(p + v->delta, *(int*)(p + 0x14), *(u32*)(p + 0x20) & 0xFFFFFF);
}

extern "C" int func_0022BE60(char* p) {
    if (*(char**)(p + 0x18)) {
        int v = *(int*)(*(char**)(p + 0x18) + 0x8C);
        if (v) {
            func_0011E008(v);
            *(int*)(*(char**)(p + 0x18) + 0x8C) = 0;
        }
        if (*(char**)(p + 0x18)) {
            func_0022C498(*(char**)(p + 0x18));
            *(int*)(p + 0x18) = 0;
        }
    }
    *(u32*)(p + 0x20) = (*(u32*)(p + 0x20) & 0x80FFFFFF) | 0x04000000;
    return 1;
}

extern "C" int func_0022BEE0(char* p) {
    if (*(char**)(p + 0x18)) {
        int v = *(int*)(*(char**)(p + 0x18) + 0x8C);
        if (v) {
            func_0011DC18(v);
            func_0011E008(*(int*)(*(char**)(p + 0x18) + 0x8C));
            *(int*)(*(char**)(p + 0x18) + 0x8C) = 0;
        }
    }
    *(u32*)(p + 0x20) = (*(u32*)(p + 0x20) & 0x80FFFFFF) | 0x06000000;
    return 1;
}

extern "C" s32 func_0022BF58(char* p, s32 a, s32 n) {
    char buf[0x100];
    func_0011AD80(func_00119500(D_00368A38), 0x20);
    u8* fmt = D_0036F740;
    VE22BF* e = (VE22BF*)(*(char**)(p + 0x34) + 0x50);
    func_0030B550_4(buf, fmt, e->fn(p + e->delta), D_00352CA0);
    func_0011A560(buf, 0, 0);
    s32 m = func_0011A380(n);
    *(s32*)(p + 0x14) = m;
    func_0030A2F4((void*)m, a, n);
    func_0011A568();
    func_0011AEB0(func_00119500(D_00368A38));
    return *(s32*)(p + 0x14);
}

extern "C" void func_0022C030(int* p) {
    if (p[5]) {
        func_0011A470(p[5]);
        p[5] = 0;
    }
}

extern "C" void func_0022C068(char* p, int a) {
    void* r = func_0022C3C8();
    *(void**)(p + 0x18) = r;
    if (a) {
        func_0030A2F4(r, a, 0x80);
    }
}

extern "C" int func_0022C0B0(void) {
    return 0x90;
}

extern "C" void* func_0022C0B8(void) {
    return D_00352CB8;
}

extern "C" int func_0022C0C8(S22B* self) {
    return self->unk10;
}

extern "C" void func_0022C0D0(S22B* self, int v) {
    self->unk10 = v;
}

extern "C" void func_0022C0D8(char* p, char* q) {
    char* o = *(char**)(p + 0x1C);
    if (o) {
        o[0xC] = o[0xC] - 1;
    }
    *(char**)(p + 0x1C) = q;
    if (q) {
        q[0xC] = q[0xC] + 1;
    }
}

extern "C" int func_0022C110(S22B* self) {
    return self->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C118);

extern "C" int func_0022C120(S22B* self) {
    return self->unk20_24;
}

struct N22C1 {
    N22C1* unk0;
    N22C1* unk4;
    s32 unk8;
};

struct H22C1 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
};

struct I22C1 {
    s32 unk0;
    N22C1* unk4;
    I22C1& operator++() { unk4 = *(N22C1**)unk4; return *this; }
};

extern "C" void func_0022C130(s32 P, s32 v) {
    I22C1 it;
    I22C1 end;
    I22C1 pos;
    N22C1 t;
    func_00116320(&D_00372E50);
    s32 pool = *(s32*)(P + 0x28);
    N22C1* first = *(N22C1**)(P + 0x2C);
    N22C1* hd = (N22C1*)(P + 0x2C);
    end.unk4 = hd;
    pos.unk4 = hd;
    volatile s32* pv = &v;
    H22C1* h = (H22C1*)(pool + 2);
    u16 i0 = h->unk2;
    u16 i1 = h->unk4;
    N22C1* n = (N22C1*)(pool + 8) + i0;
    if (i1 == i0) {
        h->unk4 = i1 + 1;
        h->unk2 = i1 + 1;
    } else {
        h->unk2 = *(u16*)n;
    }
    t.unk0 = first;
    t.unk4 = hd;
    t.unk8 = *pv;
    if (n) {
        *n = t;
    }
    *(N22C1**)hd = n;
    n->unk0->unk4 = n;
    it.unk4 = (++end).unk4;
    func_00116340(&D_00372E50);
}

struct N22C2 {
    N22C2* unk0;
    N22C2* unk4;
    s32 unk8;
};

struct H22C2 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
};

struct PL22C2 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    N22C2 nodes[1];
};

struct P22C2 {
    u8 unk0;
    u8 unk1;
    char pad2[2];
    s32 unk4;
};

struct I22C2 {
    s32 unk0;
    N22C2* unk4;
};

extern "C" void func_0022C210(s32 p, s32 key) {
    P22C2 pr;
    I22C2 end;
    I22C2 cur;
    I22C2 c1;
    I22C2 c2;
    I22C2 c3;
    I22C2 c4;
    func_00116320(&D_00372E50);
    s32 hd = p + 0x24;
    pr.unk4 = key;
    s32 e = p + 0x2C;
    pr.unk1 = 0;
    end.unk4 = (N22C2*)e;
    cur.unk4 = *(N22C2**)(hd + 0xC);
    if (cur.unk4 != end.unk4) {
        do {
            N22C2* n = cur.unk4;
            if (n->unk8 == pr.unk4) {
                c2.unk4 = n;
                c4.unk4 = n;
                c2.unk4 = n->unk4;
                c3.unk4 = n;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                s32 pool = *(s32*)(hd + 4);
                H22C2* h = (H22C2*)(pool + 2);
                N22C2* base = (N22C2*)(pool + 8);
                *(u16*)n = h->unk2;
                h->unk2 = n - base;
                c1.unk4 = c2.unk4;
                cur.unk4 = c2.unk4;
            } else {
                cur.unk4 = cur.unk4->unk4;
            }
        } while (cur.unk4 != end.unk4);
    }
    func_00116340(&D_00372E50);
}

extern "C" void func_0022C308(char* p) {
    LI22C it;
    LI22C end;
    func_00116320(&D_00372E50);
    it.unk4 = *(s32**)(p + 0x30);
    end.unk4 = (s32*)(p + 0x2C);
    if (it.unk4 != end.unk4) {
        do {
            *((LN22C*)it.unk4)->unk8 = 0;
            it.unk4 = (s32*)((LN22C*)it.unk4)->unk4;
            end.unk4 = (s32*)(p + 0x2C);
        } while (it.unk4 != end.unk4);
    }
    func_00116340(&D_00372E50);
}

extern "C" int func_0022C380(char* p) {
    int r = 0;
    if (*(char**)(p + 0x30) == p + 0x2C) {
        if (*(u8*)(p + 0xC) == 0) {
            r = func_0022C120((S22B*)p) == 5;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C498);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C4E8);

GP_DATA(D_00372E50);
extern "C" void func_0022C4F0(int a, int b) {
    if (b == 0xFFFF) {
        if (a) {
            func_001162E8(&D_00372E50);
            u16* d = (u16*)D_00393AD8;
            u16* t = d + 1;
            t[1] = 0;
            t[2] = 0;
        }
    }
}

extern "C" void func_0022C538(void) {
    func_0022C4F0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C558);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C768);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C850);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CA20);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB10);

struct HV22C {
    char pad0[8];
    s32 unk8;
};

struct HN22C {
    u32 key;
    HV22C* val;
    HN22C* next;
};

struct HT22C {
    s32 bits;
    HN22C* buckets;
    char pad8[0xD];
    u8 unk15;

    HV22C* Get(const u32& key) {
        if (!buckets) {
            return 0;
        }
        HN22C* n = &buckets[key & ((1 << bits) - 1)];
        if (!n) {
            return 0;
        }
        do {
            if (n->key == key) {
                if (unk15 || n->val) {
                    return n->val;
                }
            }
            n = n->next;
        } while (n);
        return 0;
    }
};

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB18);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CBA8);

extern "C" void func_0011C408(int, void*);

struct HI_CBC0 { u32 key; void* value; HI_CBC0* next; };
struct HT_CBC0 { int bits; HI_CBC0* items; int count; };

extern "C" void func_0022CBC0(HT_CBC0* t, int* key) {
    if (!t->items) {
        return;
    }
    HI_CBC0* e = &t->items[*key & ((1 << t->bits) - 1)];
    HI_CBC0* prev = 0;
    while (e) {
        HI_CBC0* next = e->next;
        if (e->key == (u32)*key && e->value) {
            if (prev) {
                prev->next = next;
                func_0011C408(0, e);
            } else {
                e->key = 0;
                e->value = 0;
            }
            t->count--;
            return;
        }
        prev = e;
        e = next;
    }
}

struct HI_CC78 { u32 key; void* value; HI_CC78* next; };
struct HT_CC78 { int bits; HI_CC78* items; int count; };

extern "C" void func_0022CC78(HT_CC78* t, int* key) {
    if (!t->items) {
        return;
    }
    HI_CC78* e = &t->items[*key & ((1 << t->bits) - 1)];
    HI_CC78* prev = 0;
    while (e) {
        HI_CC78* next = e->next;
        if (e->key == (u32)*key && e->value) {
            if (prev) {
                prev->next = next;
                func_0011C408(0, e);
            } else {
                e->key = 0;
                e->value = 0;
            }
            t->count--;
            return;
        }
        prev = e;
        e = next;
    }
}

extern "C" void* func_0022CD30(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00352F88;
    return p;
}

extern "C" {
extern u8 D_0036F7E0[];
void func_00113528(char*);
int func_001150B8(char*);
int func_0011D000(char*, int, int, int, int);
int func_0011D4F8(char*);
int func_0022BBB0_i(void*, char*, int, int, int, int) __asm__("func_0022BBB0");
void func_0030B550_5(char*, void*, int, int) __asm__("func_0030B550");
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CD68);

extern "C" void func_0022CEF8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022CF80(char* p, int a1, int a2) {
    char* o = (char*)func_001244C8(operator_new(0x24));
    if (func_001246F0(o, a1, a2, 1) == 0) {
        func_00275F08(0x25DC7904, 0);
        if (o != 0) {
            VE22B* d = (VE22B*)(*(char**)(o + 8) + 8);
            ((void (*)(char*, int))d->fn)(o + d->delta, 3);
        }
        o = 0;
    }
    VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, char*))f->fn)(p + f->delta, o);
    func_0022BE60_3(p, a1, a2);
}

extern "C" void func_0022D048(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        char* o = (char*)((int (*)(char*))f->fn)(p + f->delta);
        if (o) {
            VE22B* g = (VE22B*)(*(char**)(o + 8) + 8);
            ((void (*)(char*, int))g->fn)(o + g->delta, 3);
        }
    }
    func_0022BD90(p);
}

extern "C" void func_0022D0C0(int* p) {
    if (p[14]) {
        func_0011D220(p[14]);
    } else {
        if (p[5]) func_0011A470(p[5]);
    }
    p[14] = 0;
    p[5] = 0;
}

extern "C" void* func_0022D118(void) {
    return D_00352F78;
}

extern "C" int func_0022D128(void) {
    return 6;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D130);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D160);

extern "C" void func_0022D240(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022D2C8(char* p, int a1, int a2) {
    char* o = (char*)func_0022C110((S22B*)p);
    VE22B* e = (VE22B*)(*(char**)(o + 0x34) + 0x10);
    int r = ((int (*)(char*))e->fn)(o + e->delta);
    char* q = *(char**)(p + 0x18);
    int w = func_0014E560((int)q, a1, r, *(int*)(q + 0x94), *(int*)(q + 0x98), *(int*)(q + 0x9C), *(int*)(q + 0xA0));
    VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))f->fn)(p + f->delta, w);
    func_0022BE60_3(p, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D360);

extern "C" void func_0022D538(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        func_0014E708(((int (*)(char*))f->fn)(p + f->delta), 0);
    }
    func_0022BD90(p);
}

extern "C" void* func_0022D5A0(void) {
    return D_0036F838;
}

extern "C" int func_0022D5B0(void) {
    return 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5B8);

extern "C" int func_0022D5E0(void) {
    return 0xA4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5E8);

extern "C" void func_0022D6A0(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D728);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D7E0);

extern "C" void func_0022D940(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        char* o = (char*)func_0022C110((S22B*)p);
        VE22B* f = (VE22B*)(*(char**)(o + 0x34) + 0x10);
        func_00150DE8(((int (*)(char*))f->fn)(o + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022D9A8(void) {
    return D_003532D0;
}

extern "C" int func_0022D9B8(void) {
    return 5;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D9C0);

extern "C" int func_0022D9E8(void) {
    return 0x98;
}

extern "C" void* func_0022D9F0(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00353480;
    return p;
}

extern "C" void func_0022DA28(char* p, int a1, int a2, int a3, int a4, int a5) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x78);
    ((void (*)(char*, int, int))e->fn)(p + e->delta, a4, a5);
    int t = *(int*)(p + 0x18);
    func_0030B550(t, D_0036F8D8, a1, func_0014F130());
    func_0022BBB0(p, *(int*)(p + 0x18), a2, a3, a4, a5);
}

extern "C" void func_0022DAF0(char* p, int a1, int a2) {
    int t = func_0030E720(*(int*)(p + 0x18), D_0036F8E0);
    func_0030B550_3(t, D_0036F8E8, func_0014F130());
    func_00287EB0(*(int*)(p + 0x18), a1, 1);
    *(int*)(p + 0x38) = func_0028DAB8(*(int*)(p + 0x18));
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, a1);
    func_0022BE60_3(p, a1, a2);
}

extern "C" void func_0022DBB0(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

struct T22DC {
    char b[0x90];
};

extern "C" void func_0022DDF0_p(void*) __asm__("func_0022DDF0");

extern "C" void func_0022DC38(char* self, T22DC* src) {
    T22DC* d = (T22DC*)func_0022C3C8();
    *(T22DC**)(self + 0x18) = d;
    func_0022DDF0_p(d);
    if (src) {
        **(T22DC**)(self + 0x18) = *src;
    }
}

extern "C" void func_0022DD30(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        func_002886F8(((int (*)(char*))f->fn)(p + f->delta));
        func_0028D700(*(int*)(p + 0x38));
    }
    func_0022BD90(p);
}
