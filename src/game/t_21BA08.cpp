#include "common.h"

struct VEntry21B {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21B {
    char pad0[0xC];
    void* unkC;
    char pad10[0x8];
    VEntry21B* unk18;
    char pad1C[0xC];
    int unk28;
    int unk2C;
    int unk30;
};

extern "C" {
void* operator_new(u32 size);
void* func_0021C318(void*);
void func_00276D68(u32, void*, int);
extern u8 D_00390530[];
int func_001D1CF8(void*, u32);
void* func_001D0F68(void*);
f32 func_0011ED10(void);
extern u8 D_00351888[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BA08);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB38);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB40);

struct E21B {
    char pad0[0x18];
    int unk18;
};

extern "C" void func_0021C250(char* p) {
    u32 i;
    char* q;
    i = 1;
    if (i < *(u32*)(p + 0x38)) {
        q = p + 0x8C;
        do {
            i++;
            (*(E21B**)q)->unk18 = 0;
            q += 0x50;
        } while (i < *(u32*)(p + 0x38));
    }
    i = 0;
    if (*(u32*)(p + 0x870)) {
        q = p + 0x680;
        do {
            i++;
            (*(E21B**)q)->unk18 = 0;
            q += 4;
        } while (i < *(u32*)(p + 0x870));
    }
}

extern "C" void* func_0021C2C0(void) {
    return func_0021C318(operator_new(0x54));
}

extern "C" void func_0021C2E8(void) {
    func_00276D68(0x6DCFEC46, D_00390530, 0x10);
}

struct C21B {
    u8 r, g, b, a;
    C21B(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" void* func_0021C318(void* self) {
    char* p = (char*)self;
    func_001D0F68(p);
    char** n = (char**)(p + 0x20);
    n[0] = p + 0x20;
    *(void**)(p + 0x18) = D_00351888;
    n[1] = p + 0x20;
    *(u32*)(p + 4) = 0x6DCFEC46;
    *(int*)(p + 0x28) = 0;
    *(int*)(p + 0x2C) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x3C) = 0;
    *(int*)(p + 0x38) = 0;
    C21B c(0, 0xFF, 0, 0xFF);
    *(f32*)(p + 0x34) = func_0011ED10();
    *(int*)(p + 0x40) = 0;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x48) = 0;
    *(int*)(p + 0x4C) = 0;
    return p;
}

struct N21C { N21C* prev; N21C* next; void* obj; };
struct It21C { s32 pad; N21C* n; };

extern "C" {
void Heap_Free(s32 h, void* p);
void func_001D0F90(void* p, s32 a);
void func_0021BA08(void* p, s32 a);
extern s32 D_00368A38;
}

extern "C" void func_0021C3A8(char* p, s32 a) {
    It21C cur, end, nxt, c34, c44;
    N21C* s = (N21C*)(p + 0x20);
    s32 n = 0;
    *(void**)(p + 0x18) = D_00351888;
    cur.n = *(N21C**)(p + 0x24);
    end.n = s;
    nxt.n = cur.n;
    if (cur.n != s) {
        do {
            n++;
            nxt.n = nxt.n->next;
        } while (nxt.n != s);
    }
    char* h = p + 0x1C;
    N21C* s2 = (N21C*)(h + 4);
    if (n != 0) {
        cur.n = *(N21C**)(h + 8);
        end.n = s2;
        if (cur.n != s2) {
            N21C* e = (N21C*)(p + 0x20);
            asm("" : "+r"(e));
            do {
                if (cur.n->obj != 0) {
                    func_0021BA08(cur.n->obj, 3);
                    cur.n->obj = 0;
                }
                N21C* x = cur.n;
                nxt.n = x;
                c44.n = x;
                nxt.n = x->next;
                c34.n = x;
                x->prev->next = x->next;
                x->next->prev = x->prev;
                Heap_Free(D_00368A38, x);
                end.n = e;
                cur.n = nxt.n;
            } while (nxt.n != e);
        }
        N21C* q = *(N21C**)(h + 8);
        *(N21C**)(h + 8) = s2;
        *(N21C**)(h + 4) = s2;
        if (q != s2) {
            do {
                N21C* t = q->next;
                Heap_Free(D_00368A38, q);
                q = t;
            } while (q != (N21C*)(h + 4));
        }
    }
    N21C* q = *(N21C**)(h + 8);
    *(N21C**)(h + 8) = s2;
    *(N21C**)(h + 4) = s2;
    if (q != s2) {
        do {
            N21C* t = q->next;
            Heap_Free(D_00368A38, q);
            q = t;
        } while (q != (N21C*)(h + 4));
    }
    func_001D0F90(p, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C530);

extern "C" void func_0021CDB0(S21B* p) {
    p->unk28 = (int)func_001D1CF8(p->unkC, 0xCE0CA665);
    p->unk2C = (int)func_001D1CF8(p->unkC, 0x222756D5);
    p->unk30 = (int)func_001D1CF8(p->unkC, 0x286A8D26);
}

extern "C" void func_0021CE10(S21B* self, int a) {
    VEntry21B* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021CE38);

typedef int TI21B __attribute__((mode(TI)));

struct O21D {
    s32 unk0;
    char pad4[0x34];
    s32 unk38;
    char pad3C[4];
    TI21B unk40;
};

struct N21D {
    N21D* unk0;
    N21D* unk4;
    O21D* unk8;
};

struct I21D {
    s32 unk0;
    N21D* unk4;
};

struct S21D {
    char pad0[0x20];
    N21D unk20;
};

extern "C" {
void func_0027D870_d(void* a, u32 k, s32* v, s32 r) __asm__("func_0027D870");
void func_0027D2D8_d(void* a, u32 k, TI21B* v, s32 r) __asm__("func_0027D2D8");
s32 func_0027D1F8_d(void* a, u32 k, s32* v, s32 r) __asm__("func_0027D1F8");
s32 func_0027DF00_d(void* a, u32 k) __asm__("func_0027DF00");
}

extern "C" s32 func_0021D8F8(S21D* p, void* a) {
    s32 key = 0;
    func_0027D870_d(a, 0x62BF8E3F, &key, 1);
    s32 k = key;
    TI21B vec;
    func_0027D2D8_d(a, 0xEC13B28C, &vec, 1);
    I21D it;
    I21D e;
    it.unk4 = p->unk20.unk4;
    e.unk4 = &p->unk20;
    while (it.unk4 != e.unk4) {
        if (it.unk4->unk8->unk0 == k) {
            s32 idx = 0;
            if ((func_0027D1F8_d(a, 0xD037C420, &idx, 0) ^ 1) != 0) {
                if (func_0027DF00_d(a, 0x3EA1D93A)) {
                    idx = 0;
                } else if ((func_0027DF00_d(a, 0x5F78A252) ^ 1) != 0) {
                    idx = it.unk4->unk8->unk38 - 1;
                }
            }
            O21D* o = (O21D*)(idx * 0x50 + (s32)it.unk4->unk8);
            o->unk40 = vec;
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk20;
    }
    return 1;
}
