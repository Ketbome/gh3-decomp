#include "common.h"

struct SB12_V {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x4];
    SB12_V* unkC;
    char pad10[0x4];
    virtual ~SB12_V();
    SB12_V* Get() { return unk4 == 0xFFFFFFFF ? 0 : this; }
};

struct SB12_O {
    char pad0[0x18];
    void* unk18;
    char pad1C[0x20];
    int unk3C;
    SB12_V* unk40[6];
    int unk58;
    float unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};

struct SB12_Node {
    char pad0[0x4];
    int unk4;
};

struct SB12_Item {
    char pad0[0x28];
    float unk28;
    char pad2C[0x4];
    int unk30;
    char pad34[0x40];
    int unk74;
};

struct SB12_Self {
    char pad0[0xC];
    SB12_Node* unkC;
    char pad10[0x8];
    int unk18;
    char pad1C[0x20];
    int unk3C;
    char pad40[0x4];
    char* unk44;
    u32 unk48;
    char pad4C[0xC];
    int unk58;
    char pad5C[0x4];
    int unk60;
};

struct SB12_Link {
    SB12_Link* unk0;
    SB12_Link* unk4;
};

struct SB12_List {
    int unk0;
    char pad4[0x4];
    SB12_Link unk8;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

static inline SB12_Item* SB12_First(SB12_Self* self) {
    SB12_Node* n = self->unkC;
    if (n->unk4 == -1) {
        n = 0;
    }
    return n ? (SB12_Item*)((char*)n - 4) : 0;
}

struct S_0012BC90_c { char pad0[0x8]; float unk8; };
struct S_0012BC90_b { char pad0[0xC]; S_0012BC90_c* unkC; };

extern "C" {
void func_0027C448(int, u32, int);
void func_0027C1F8(int, u32, float);
void func_0012A478(void*, float*, float*, float*);
extern int D_00372AD0;
extern u32 D_00377F70[];

void func_0012BE38(void*, int, int, int, int, float, float, float, float);
void func_0012D630(SB12_O*);
void func_0012DF30(SB12_O*);
void func_0012A3E8(void*, int);
void* func_0012A3A0(void*);
void func_0012D0E8(void*);
extern u8 D_00339C30[];
int func_0015FAA0(char*, int, int);
int func_0012A538(void*);
int func_001D1CF8(int, u32);
void func_0012D1A0(int, int);
int func_0012BD10(SB12_Self*, int);
float func_0012BC90(SB12_Self*, int);
}

struct SB12_Pool {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};

extern "C" {
extern int D_00368A38;
extern int D_00371480;
extern SB12_Pool* D_00371470[2];
extern int D_00369208;
extern SB12_Pool* D_003691F8[2];
void Heap_Free(int, void*);
void func_0011C2E8(SB12_Pool*, void*);
void* func_0011C2A8(SB12_Pool*);
int func_00119610(int, int);
void func_00119490(int, int);
void* Heap_Alloc(int, u32, int, int);
void func_001194B8(int);
}

struct S_0012C1F8 { char pad0[0x38]; int unk38; };
struct S_0012D208 { char pad0[0x8]; int unk8; };

GP_DATA(D_00372AD0);
extern "C" void func_0012B970(int unused, char* self, int p) {
    char* b = self + 4;
    float x;
    float y;
    float z;
    func_0027C448(p, 0x98549BA4, *(int*)(b + 0x34));
    func_0027C1F8(p, 0xF0D90109, *(float*)(self + 0x28));
    if (D_00372AD0 == 0) {
        u32* d = D_00377F70;
        D_00377F70[0] = 0xE035F2F8;
        d += 1;
        *d = 0x4F792E6C;
        d += 1;
        d[0] = 0x3153E314;
        d[1] = 0x6D941203;
        D_00372AD0 = 1;
    }
    func_0027C448(p, 0x6B888E80, D_00377F70[*(int*)(b + 0x2C)]);
    func_0012A478(b, &x, &y, &z);
    func_0027C1F8(p, 0xD16B61E6, x);
    func_0027C1F8(p, 0xD4FC8176, y);
    func_0027C1F8(p, 0xAB81BB3D, z);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BA98);

extern "C" float func_0012BC90(SB12_Self* self, int n) {
    return ((S_0012BC90_b*)func_0012BD10(self, n))->unkC->unk8;
}

extern "C" int func_0012BCB8(SB12_Self* self, int n) {
    return func_0012BD10(self, n) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BCD8);

extern "C" int func_0012BD10(SB12_Self* self, int n) {
    return func_0015FAA0(self->unk44 + n, 0, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BD38);

extern "C" int func_0012BD58(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return func_0012A538((char*)it + 4);
    }
    return 0;
}

extern "C" int func_0012BD98(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return it->unk30 == 1 || it->unk30 == 2;
    }
    return 0;
}

extern "C" void func_0012BDD0(SB12_Self* self, int anim, float blend) {
    func_0012BE38(self, anim, 0, 0, 0, 0.0f, func_0012BC90(self, anim), blend, 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BE38);

extern "C" int func_0012BF38(int op, float x) {
    int r = 0;
    float k;
    switch (op) {
    case 0:
        if (x == 0.05f) {
            r = 0;
        } else if (x == 0.1f) {
            r = 1;
        } else if (x == 10.1f) {
            r = 2;
        }
        break;
    case 1:
        if (x == 0.04f) {
            r = 0;
            break;
        }
        k = 10.1f;
        goto tail;
    case 2:
        if (x == 0.0022f) {
            r = 0;
            break;
        }
        k = 20.0f;
        goto tail;
    case 3:
        if (x == 0.0017f) {
            r = 0;
            break;
        }
        k = 10.0f;
        goto tail;
    case 4:
        if (x == 1.5f) {
            r = 0;
            break;
        }
        k = 1.0f;
    tail:
        if (x == k) r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C0B0);

extern "C" float func_0012C1B8(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return it->unk28 * 60.0f;
    }
    return 0.0f;
}

extern "C" void func_0012C1F8(S_0012C1F8* self, int v) {
    self->unk38 = v;
}

extern "C" void func_0012C200(SB12_Self* self, int v) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        self->unk3C = v;
        it->unk74 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C238);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C750);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C780);

extern "C" void func_0012C878(SB12_Self* self, int flag) {
    u32 v;
    self->unk48 &= ~0x20000000;
    v = self->unk48;
    if (flag) {
        v |= 0x20000000;
    }
    self->unk48 = v;
}

extern "C" void func_0012C8A8(SB12_Self* self) {
    SB12_V* n = ((SB12_V*)self->unkC)->Get();
    while (n) {
        SB12_V* next = n->unkC->Get();
        delete n;
        n = next;
    }
}

extern "C" void func_0012C920(SB12_Self* self) {
    self->unk60 = func_001D1CF8(self->unk58, 0x222756D5);
}

extern "C" SB12_List* func_0012C958(SB12_List* self, int a) {
    self->unk0 = a;
    SB12_Link* l = &self->unk8;
    l->unk0 = l;
    l->unk4 = l;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    return self;
}

struct N12F { N12F* prev; N12F* next; int val; };
struct I12F { int unk0; N12F* cur; int unk8; int unkC; };
struct L12F { int unk0; int unk4; N12F* prev; N12F* next; float f10; float f14; float f18; float f1C; };

extern "C" L12F* func_0012C980(L12F* self, L12F* src) {
    I12F A, B, C, D, E, F, G;
    N12F tmp;
    self->unk0 = src->unk0;
    N12F* sent = (N12F*)&self->prev;
    self->prev = sent;
    sent->next = sent;
    N12F* ssent = (N12F*)&src->prev;
    N12F* dn = self->next;
    C.cur = ssent;
    N12F* sn = src->next;
    A.cur = dn;
    B.cur = sn;
    D.cur = dn;
    E.cur = sn;
    F.cur = ssent;
    if (sn != ssent) {
        N12F* pt = &tmp;
        do {
            N12F* d = D.cur;
            G.cur = d;
            N12F* e = E.cur;
            N12F* tail = d->prev;
            N12F* n = (N12F*)Heap_Alloc(D_00368A38, 0xC, 1, 0);
            tmp.next = d;
            tmp.prev = tail;
            pt->val = e->val;
            if (n) *n = tmp;
            d->prev = n;
            n->prev->next = n;
            E.cur = E.cur->next;
        } while (E.cur != F.cur);
    }
    self->f10 = src->f10;
    self->f14 = src->f14;
    self->f18 = src->f18;
    self->f1C = src->f1C;
    return self;
}

struct VT12E { char pad0[8]; s16 delta; s16 pad0A; void (*fn)(void*, int); };
struct O12E { char pad0[0x64]; VT12E* unk64; };
struct N12E { N12E* unk0; N12E* unk4; O12E* unk8; };
struct I12E { int unk0; N12E* cur; int unk8; int unkC; };
struct L12E { int unk0; N12E unk4; N12E* First() { return unk4.unk4; } N12E* End() { return &unk4; } };

extern "C" {
void Heap_Free_c(int, void*) __asm__("Heap_Free");
extern int D_00368A38_c __asm__("D_00368A38");
void func_0012CAA8_d(void*, int) __asm__("func_0012CAA8");
}

void func_0012CAA8_d(void* self, int flags) {
    I12E a, b, c, d, e;
    L12E* l0 = (L12E*)((char*)self + 4);
    if (l0->First() != l0->End()) {
        do {
            N12E* n = ((L12E*)((char*)self + 4))->First();
            a.cur = n;
            O12E* o = n->unk8;
            if (o) {
                o->unk64->fn((char*)o + o->unk64->delta, 3);
            }
            N12E* m = ((L12E*)((char*)self + 4))->First();
            c.cur = m;
            e.cur = m;
            N12E* nx = m->unk4;
            d.cur = m;
            c.cur = nx;
            m->unk0->unk4 = m->unk4;
            m->unk4->unk0 = m->unk0;
            Heap_Free_c(D_00368A38_c, m);
            b.cur = c.cur;
        } while (((L12E*)((char*)self + 4))->First() != ((L12E*)((char*)self + 4))->End());
    }
    L12E* l2 = (L12E*)((char*)self + 4);
    N12E* s2 = l2->End();
    N12E* p = l2->unk4.unk4;
    l2->unk4.unk4 = s2;
    l2->unk4.unk0 = s2;
    if (p != s2) {
        do {
            N12E* q = p;
            p = p->unk4;
            Heap_Free_c(D_00368A38_c, q);
        } while (p != l2->End());
    }
    if (flags & 1) {
        Heap_Free_c(D_00368A38_c, self);
    }
}

struct VT12D { char pad0[8]; s16 delta; s16 pad0A; void (*fn)(void*, int); };
struct O12D { char pad0[0x64]; VT12D* unk64; };
struct N12D { N12D* unk0; N12D* unk4; O12D* unk8; };
struct I12D {
    int unk0; N12D* cur; int unk8; int unkC;
    I12D() {}
    I12D(N12D* n) : cur(n) {}
    bool operator!=(const I12D& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct L12D { int unk0; N12D unk4; };

extern "C" {
void func_0012A778_d(void*) __asm__("func_0012A778");
}

extern "C" void func_0012CBD0(void* self) {
    L12D* l = (L12D*)((char*)self + 4);
    N12D* sent = (N12D*)((char*)self + 8);
    I12D A, B, C, R, c, x, d, e;
    I12D* px = &x;
    L12D* l2 = (L12D*)((char*)sent - 4);
    for (;;) {
        B.cur = sent;
        A.cur = l->unk4.unk4;
        C.cur = A.cur;
        unsigned cnt = 0;
        for (; C != B; ++C) cnt++;
        if (cnt < 2) break;
        A.cur = *(N12D**)((char*)self + 8);
        O12D* o = A.cur->unk8;
        if (o) o->unk64->fn((char*)o + o->unk64->delta, 3);
        x.cur = *(N12D**)((char*)self + 8);
        N12D* n = px->cur;
        c.cur = n;
        e.cur = n;
        N12D* nx = n->unk4;
        d.cur = n;
        c.cur = nx;
        n->unk0->unk4 = n->unk4;
        n->unk4->unk0 = n->unk0;
        Heap_Free(D_00368A38, n);
        R.cur = c.cur;
    }
    A.cur = l2->unk4.unk4;
    func_0012A778_d(A.cur->unk8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CCF0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CCF8);

struct N12C { N12C* prev; N12C* next; int val; };
struct It12C { int unk0; N12C* cur; int pad8[2]; };
struct L12C { char pad0[8]; N12C sent; };
extern "C" int func_0012A648_i(void*, int, int, int) __asm__("func_0012A648");

extern "C" int func_0012CDE8(L12C* self, int a1, int a2, int a3) {
    N12C* sp = &self->sent;
    int v = func_0012A648_i(Heap_Alloc(D_00368A38, 0x68, 1, 0), a1, a2, a3);
    N12C* tail = self->sent.prev;
    It12C r, end, e2;
    end.cur = sp;
    e2.cur = sp;
    N12C* n = (N12C*)Heap_Alloc(D_00368A38, 0xC, 1, 0);
    N12C t;
    t.prev = tail;
    t.next = sp;
    t.val = v;
    if (n) *n = t;
    self->sent.prev = n;
    n->prev->next = n;
    end.cur = end.cur->prev;
    r.cur = self->sent.prev;
    return r.cur->val;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CF40);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D000);

extern "C" void* func_0012D028(u32 size) {
    SB12_Pool* pool = D_00371470[D_00371480];
    if (pool) {
        void* r = func_0011C2A8(pool);
        if (!r) {
            int heap = D_00368A38;
            func_00119490(heap, func_00119610(heap, 1));
            r = Heap_Alloc(D_00368A38, size, 1, 0);
            func_001194B8(D_00368A38);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38, size, 1, 0);
}

extern "C" void func_0012D0E8(void* p) {
    SB12_Pool* pool = D_003691F8[D_00369208];
    if ((pool && pool->Has((u32)p)) || ((pool = D_003691F8[D_00369208 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_0012D1A0(int a, int b) {
    if (b == 0xFFFF && a) {
        int i;
        for (i = 0x7F; i != -1; i -= 0x20) {
        }
        for (i = 0x7F; i != -1; i -= 0x20) {
        }
    }
}

extern "C" int func_0012D208(S_0012D208* self) {
    return self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D210);

extern "C" void func_0012D278(void) {
    func_0012D1A0(1, 0xFFFF);
}

extern "C" SB12_O* func_0012D298(SB12_O* self, int a) {
    func_0012A3A0((char*)self + 4);
    self->unk18 = D_00339C30;
    self->unk3C = 2;
    self->unk58 = 0;
    self->unk5C = 0.016666668f;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = a;
    self->unk6C = 0;
    self->unk70 = 0;
    self->unk74 = 1;
    return self;
}

extern "C" void func_0012D318(SB12_O* self, int flags) {
    self->unk18 = D_00339C30;
    func_0012D630(self);
    func_0012DF30(self);
    func_0012A3E8((char*)self + 4, 0);
    if (flags & 1) {
        func_0012D0E8(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D380);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D530);

extern "C" void func_0012D630(SB12_O* self) {
    int i;
    for (i = 0; i < self->unk58; i++) {
        delete self->unk40[i];
        self->unk40[i] = 0;
    }
    self->unk58 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D6B0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D790);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D870);
