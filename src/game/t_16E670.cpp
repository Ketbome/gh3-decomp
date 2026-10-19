#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0016EDF0 {
    char pad[0x24];
    VEntry* unk24;
};

struct S_0016E990 { int unk0; int unk4; int unk8; };

struct S16E_A {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x400];
    s16 unk40C;
    char pad40E[0x2];
    int unk410;
    void* unk414;
};

struct S16E_B {
    S16E_B* unk0;
    u32 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char pad1C[0x4];
    int unk20;
    VEntry* unk24;
};

struct S16E_C { void* unk0; int unk4; };

struct S16E_D { char pad0[0x4]; int unk4; int unk8; int unkC; };

struct S16E_E { char pad0[0x14]; void* unk14; };

struct S16E_F {
    char pad0[0x18];
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    char pad28[0x2C];
    int unk54;
};

struct S16E_H { char pad0[0x10]; int unk10; VEntry* unk14; };
struct S16E_G { S16E_H* unk0; int unk4; };

struct N16E { int unk0; N16E* unk4; S16E_G unk8; char pad10[0x4]; int unk14; };
struct L16E { int unk0; N16E unk4; };
struct S16E_I { L16E* unk0; };
struct It16E {
    int unk0;
    N16E* cur;
    It16E(N16E* n) : cur(n) {}
    It16E(const It16E& o) : cur(o.cur) {}
    bool operator!=(const It16E& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};

struct HI_16E { u32 key; void* value; HI_16E* next; };
struct HT_16E { int bits; HI_16E* items; int count; };
struct Pool_16E {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};


extern "C" {
void func_001B4E70(void);
void func_00199370(void);
extern u8 D_0033FDA0[];
extern u8 D_00340018[];
extern u8 D_003403C0[];
extern int D_00368A38;
extern S16E_B* D_0036A88C;
extern S16E_B* D_0036A888;
void memset(void*, int, int);
void func_0016E850(void*);
int func_0015FAA0(int, int, int);
void* Heap_Alloc(int, int, int, int);
void* func_0016E9C8(void*, int, int);
void func_0016E990(S_0016E990*);
void func_0016EF20(S16E_B*);
void func_0016EF40(S16E_B*);
void Heap_Free(int, void*);
int func_0011EF10(void);
void func_0011C408(int, void*);
extern int D_0036A7A0;
extern Pool_16E* D_0036A790[2];
void func_0011C2E8(Pool_16E*, void*);
void func_0027D870(void*, u32, int*, int);
}

extern "C" void func_0016E670(HT_16E* t, int* key) {
    if (!t->items) {
        return;
    }
    HI_16E* e = &t->items[*key & ((1 << t->bits) - 1)];
    HI_16E* prev = 0;
    while (e) {
        HI_16E* next = e->next;
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

extern "C" S16E_A* func_0016E728(S16E_A* self) {
    self->unk414 = D_0033FDA0;
    memset(self->padC, 0, 0x408);
    self->unk410 = 0;
    self->unk40C = 0;
    self->unk4 = 0;
    return self;
}

extern "C" void func_0016E778(S16E_A* self, int flags) {
    self->unk414 = D_0033FDA0;
    if (flags & 1) {
        func_0016E850(self);
    }
}

extern "C" int func_0016E7A8(S16E_A* self, int b) {
    self->unk410 = b ^ 1;
    if (!self->unk4 || b) {
        return 0;
    }
    return func_0015FAA0(self->unk4, 1, 1);
}

extern "C" int func_0016E7E8(S16E_A* self, s16 v) {
    s16 old = self->unk40C;
    self->unk40C = v;
    return v >= old ? 1 : -1;
}

extern "C" void func_0016E810(S16E_A* self, int a, int b) {
    self->unk4 = a;
    self->unk8 = b;
    func_0016E7A8(self, 0);
    func_0015FAA0(self->unk4, 1, 1);
}

GP_DATA(D_0036A7A0);
GP_DATA(D_0036A790);
extern "C" void func_0016E850(void* p) {
    Pool_16E* pool = D_0036A790[D_0036A7A0];
    if ((pool && pool->Has((u32)p)) || ((pool = D_0036A790[D_0036A7A0 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" S16E_C* func_0016E900(S16E_C* self) {
    self->unk0 = func_0016E9C8(Heap_Alloc(D_00368A38, 0x1C, 1, 0), 8, 0);
    self->unk4 = 1;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E958);

extern "C" void func_0016E990(S_0016E990* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S_0016E990* func_0016E9A0(S_0016E990* self) {
    func_0016E990(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016E9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EBA8);

extern "C" void func_0016EBC8(void) {
}

extern "C" void func_0016EBD0(void) {
}

extern "C" void func_0016EBD8(void) {
}

extern "C" void func_0016EBE0(void) {
}

extern "C" void func_0016EBE8(void) {
}

extern "C" void func_0016EBF0(void) {
}

extern "C" void func_0016EBF8(void) {
}

extern "C" void func_0016EC00(void) {
}

extern "C" void func_0016EC08(void) {
}

extern "C" void func_0016EC10(void) {
}

extern "C" void func_0016EC18(void) {
}

extern "C" void func_0016EC20(void) {
}

extern "C" void func_0016EC28(void) {
}

extern "C" void func_0016EC30(void) {
}

extern "C" void func_0016EC38(void) {
}

extern "C" void func_0016EC40(void) {
}

extern "C" void func_0016EC48(void) {
}

extern "C" void func_0016EC50(void) {
}

extern "C" void func_0016EC58(void) {
}

extern "C" float func_0016EC60(void) {
    return 0.0f;
}

extern "C" float func_0016EC70(void) {
    return 0.0f;
}

extern "C" float func_0016EC80(void) {
    return 0.0f;
}

extern "C" float func_0016EC90(void) {
    return 0.0f;
}

extern "C" float func_0016ECA0(void) {
    return 0.0f;
}

extern "C" float func_0016ECB0(void) {
    return 0.0f;
}

extern "C" int func_0016ECC0(void) {
    return 0;
}

extern "C" float func_0016ECC8(void) {
    return 0.0f;
}

extern "C" float func_0016ECD8(void) {
    return 0.0f;
}

extern "C" void func_0016ECE8(void) {
}

extern "C" void func_0016ECF0(void) {
}

extern "C" void func_0016ECF8(void) {
}

extern "C" void func_0016ED00(void) {
}

extern "C" void func_0016ED08(void) {
}

extern "C" void func_0016ED10(void) {
}

extern "C" void func_0016ED18(void) {
}

extern "C" int func_0016ED20(void) {
    return 0;
}

extern "C" S16E_B* func_0016ED28(S16E_B* self, int a) {
    self->unk24 = (VEntry*)D_00340018;
    self->unk8 = 0x54628ED7;
    self->unk20 = 0;
    self->unk18 = 0;
    self->unk14 = 0;
    self->unk0 = 0;
    self->unk10 = 0;
    self->unk4 = 0;
    self->unkC = a;
    if (a == 1) {
        func_0016EF20(self);
    }
    return self;
}

extern "C" void func_0016ED90(S16E_B* self, int flags) {
    self->unk24 = (VEntry*)D_00340018;
    if (self->unkC == 1) {
        func_0016EF40(self);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0016EDF0(S0016EDF0* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk24[5];
    ((void (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" void func_0016EE18(S16E_B* self) {
    VEntry* e = &self->unk24[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    self->unk18 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EE58);

extern "C" int func_0016EEC0(int x) {
    switch (x) {
    case 0:
        return 2;
    case 1:
    case 3:
        return 1;
    case 2:
        return 3;
    case 4:
        return 5;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EF10);

GP_DATA(D_0036A88C);
extern "C" void func_0016EF20(S16E_B* self) {
    self->unk0 = D_0036A88C;
    D_0036A88C = self;
    self->unk4 |= 0x100;
}

GP_DATA(D_0036A888);
extern "C" void func_0016EF40(S16E_B* self) {
    S16E_B** head = &D_0036A888;
    if (self->unk4 & 0x100) head = &D_0036A88C;
    S16E_B* h = *head;
    if (h == self) {
        *head = self->unk0;
        return;
    }
    S16E_B* p = h;
    while (p) {
        S16E_B* n = *(S16E_B* volatile*)&p->unk0;
        if (!n) break;
        if (n == self) break;
        p = p->unk0;
    }
    if (p) p->unk0 = p->unk0->unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016EFA8);

extern "C" void func_0016EFC8(S16E_G* self, int a) {
    self->unk0->unk10 = a;
    S16E_H* o = self->unk0;
    VEntry* e = &o->unk14[3];
    ((void (*)(void*, int, int))e->fn)((char*)o + e->delta, func_0011EF10(), self->unk4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F030);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F248);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F5F0);

struct VT16F { char pad0[8]; s16 delta; s16 pad0A; void (*fn)(void*, int); };
struct O16F { char pad0[0x14]; VT16F* unk14; };
struct N16F { N16F* unk0; N16F* unk4; O16F* unk8; O16F* unkC; char pad10[4]; int unk14; };
struct I16F { int unk0; N16F* cur; int unk8; int unkC; };
struct L16F { char pad0[4]; char unk4[4]; N16F* unk8; };

extern "C" {
int func_0027D870_f(int, u32, int*, int) __asm__("func_0027D870");
void Heap_Free_f(int, void*) __asm__("Heap_Free");
extern int D_00368A38_f __asm__("D_00368A38");
int func_0016F6E0_d(L16F** self, int params) __asm__("func_0016F6E0");
}

int func_0016F6E0_d(L16F** self, int params) {
    int key = 0;
    int r = 0;
    I16F it, end, c, d, e;
    func_0027D870_f(params, 0xA1DC81F9, &key, 1);
    it.cur = (*self)->unk8;
    end.cur = (N16F*)(*self)->unk4;
    if (it.cur != end.cur) {
        do {
            if (it.cur->unk14 == key) {
                O16F* o = it.cur->unk8;
                if (o) {
                    o->unk14->fn((char*)o + o->unk14->delta, 3);
                }
                it.cur->unk8 = 0;
                O16F* o2 = it.cur->unkC;
                if (o2) {
                    o2->unk14->fn((char*)o2 + o2->unk14->delta, 3);
                }
                r = 1;
                it.cur->unkC = 0;
                N16F* n = it.cur;
                c.cur = n;
                e.cur = n;
                N16F* nx = n->unk4;
                d.cur = n;
                c.cur = nx;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                Heap_Free_f(D_00368A38_f, n);
                end.cur = c.cur;
                it.cur = c.cur;
            } else {
                it.cur = it.cur->unk4;
            }
            end.cur = (N16F*)(*self)->unk4;
        } while (it.cur != end.cur);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016F820);

extern "C" int func_0016FAD8(S16E_I* self, void* a) {
    if (!self->unk0) {
        return 0;
    }
    int key = 0;
    int r = 0;
    func_0027D870(a, 0xA1DC81F9, &key, 1);
    for (It16E it(self->unk0->unk4.unk4); it != It16E(&self->unk0->unk4); ++it) {
        if (it.cur->unk14 == key) {
            r = 1;
        }
    }
    return r;
}

extern "C" void func_0016FB78(void) {
    func_001B4E70();
}

extern "C" void func_0016FB98(S16E_I* self, int a) {
    if (self->unk0) {
        for (It16E it(self->unk0->unk4.unk4); it != It16E(&self->unk0->unk4); ++it) {
            func_0016EFC8(&it.cur->unk8, a);
        }
    }
}

extern "C" int func_0016FC10(S16E_I* self) {
    L16E* l = self->unk0;
    if (l) {
        It16E b(l->unk4.unk4);
        It16E e(&l->unk4);
        int n = 0;
        for (It16E it = b; it != e; ++it) {
            n++;
        }
        return n;
    }
    return 0;
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FC70);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FCD8);

extern "C" int func_0016FDC8(S16E_D* self) {
    self->unk4 = func_0011EF10();
    self->unk8 = 0;
    self->unkC = 0;
    return 1;
}

extern "C" int func_0016FE00(void) {
    return 0;
}

extern "C" int func_0016FE08(void) {
    return 0;
}

extern "C" void func_0016FE10(S16E_E* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FE50);

extern "C" int func_0016FEF0(S16E_F* self) {
    int r = 0;
    if (self->unk54 && (self->unk18 > 0.0f || self->unk1C > 0.0f) && (self->unk20 > 0.0f || self->unk24 > 0.0f)) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_0016FF60);

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_00170180);

extern "C" void func_00170570(void) {
    func_00199370();
}

INCLUDE_ASM("asm/nonmatchings/game/t_16E670", func_00170590);
