#include "common.h"

struct S2A74C0_A {
    char pad0[0x4];
    int *unk4;
};

extern "C" {
int func_0027D400(int, int, int *, int);
extern int D_00371EEC;
extern int D_00372F18;
extern int D_00372F20;
int func_002A7D58(void *, int);
extern int D_00372F28;
extern char D_003AB260[];
extern char D_003AB4B0[];
int func_002A7A40(int);
extern s32 D_00371EF4;
extern s32 D_00372F30[] __attribute__((section(".sdata")));
extern s32 D_00372F38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A74C0);

struct S2A7540_V {
    char pad0[0x14];
    virtual ~S2A7540_V();
};
struct S2A7540 {
    u32 unk0;
    S2A7540_V **unk4;
};
extern "C" {
extern int D_00368A38;
void Heap_Free(int, void *);
}
extern "C" void func_002A7540(S2A7540 *p, int flags) {
    for (u32 i = 0; i < p->unk0; i++) {
        delete p->unk4[i];
    }
    if (p->unk4) {
        Heap_Free(D_00368A38, p->unk4);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct S2A75F0 {
    char pad0[4];
    int *unk4;
};
extern "C" void func_002A75F0(S2A75F0 *p, int i, int v) {
    p->unk4[i] = func_002A7A40(v);
}

extern "C" int func_002A7638(S2A74C0_A *p, int i) {
    return p->unk4[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7650);

struct S2A77_Arr {
    char pad0[4];
    u32 size;
    int data;
    int GetI(u32 i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

struct S2A77_Heap {
    char pad0[0x188];
    int unk188;
};

struct S2A77_HN {
    int key;
    int val;
    S2A77_HN *next;
};

struct S2A77_HT {
    int bits;
    S2A77_HN *items;
    int count;
};

extern "C" {
extern S2A77_Heap *D_00368A38_h asm("D_00368A38");
extern S2A77_HT D_003AC7A0;
int func_00119730(S2A77_Heap *, int, int);
void func_00119490(S2A77_Heap *, int);
void func_001194B8(S2A77_Heap *);
int func_00119500(S2A77_Heap *);
void func_0011AD80(int, int);
void func_0011AEB0(int);
void *Heap_Alloc_h(S2A77_Heap *, int, int, int) asm("Heap_Alloc");
int func_002A74C0_a(void *, u32) asm("func_002A74C0");
void func_002A75F0_a(int, u32, int) asm("func_002A75F0");
void *func_0011C3A8_h(int) asm("func_0011C3A8");
S2A77_HN *func_002AE0A0(void *);
}

extern "C" void func_002A77E0(S2A77_Arr *a, int key) {
    S2A77_Heap *h = D_00368A38_h;
    u32 i = 0;
    func_00119490(h, func_00119730(h, 0x478BA755, 1));
    func_0011AD80(func_00119500(D_00368A38_h), 0x10);
    D_00368A38_h->unk188 = 0;
    int obj = func_002A74C0_a(Heap_Alloc_h(D_00368A38_h, 8, 1, 0), a->size);
    if (a->size != 0) {
        do {
            func_002A75F0_a(obj, i, a->GetI(i));
            i++;
        } while (i < a->size);
    }
    S2A77_HN *b = &D_003AC7A0.items[key & ((1 << D_003AC7A0.bits) - 1)];
    if (b->val != 0 || b->key != 0) {
        S2A77_HN *n = (S2A77_HN *)func_0011C3A8_h(0);
        if (n) {
            n = func_002AE0A0(n);
        }
        n->key = key;
        n->val = obj;
        n->next = b->next;
        b->next = n;
    } else {
        b->key = key;
        b->val = obj;
    }
    D_003AC7A0.count++;
    D_00368A38_h->unk188 = 1;
    func_0011AEB0(func_00119500(D_00368A38_h));
    func_001194B8(D_00368A38_h);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A79A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7A40);

GP_DATA(D_00371EF4);
extern "C" void func_002A7D40(void) {
    D_00371EF4 = 0;
    D_00372F30[0] = 0;
    D_00372F38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7D58);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7EA8);

GP_DATA(D_00371EEC);
extern "C" int func_002A7EF0(void) {
    int a = 0;
    int b;
    if (func_0027D400(D_00371EEC, D_00372F20, &a, 0)) {
        b = 0;
        if (func_0027D400(a, D_00372F18, &b, 0) || func_0027D400(a, 0x1CA1FF20, &b, 0)) {
            return b;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", func_002A7F78);

INCLUDE_ASM("asm/nonmatchings/game/t_2A74C0", CFunc_LightShow_Init);
