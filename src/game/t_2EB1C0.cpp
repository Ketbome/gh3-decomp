#include "common.h"

struct SHT_N {
    int key;
    int val;
    SHT_N *next;
};
struct SHT {
    int bits;
    SHT_N *tab;
    char pad8[0xD];
    u8 unk15;
};
static inline int SHT_Find(SHT *t, const int &k) {
    SHT_N *n;
    if (t->tab == 0) {
        return 0;
    }
    n = &t->tab[k & ((1 << t->bits) - 1)];
    if (n == 0) {
        return 0;
    }
    do {
        if (n->key == k) {
            int v = n->val;
            if (t->unk15 != 0 || v != 0) {
                return v;
            }
        }
        n = n->next;
    } while (n);
    return 0;
}

extern "C" {
extern struct SHT *D_003729D0;
}

struct S2EBDE0_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB1C0);

struct S2EB_L {
    int type;
    int *unk4;
    S2EB_L *next;
};
struct S2EB_O {
    int unk0;
    char pad4[0x1C];
    S2EB_L *unk20;
};
extern "C" void func_002EAE80(int *, int);
extern "C" void func_002EB680(int, int *);

extern "C" void func_002EB1C8(S2EB_O *p, int b) {
    S2EB_L *n = p->unk20;
    while (n) {
        if (n->type == 2) {
            if (*n->unk4 != 0) {
                int *o = n->unk4;
                S2EB_L *next = n->next;
                func_002EB680(p->unk0, o);
                n = next;
                continue;
            }
            func_002EAE80(n->unk4, b);
            for (S2EB_L *it = p->unk20; it; it = it->next) {
            }
        }
        n = n->next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB280);

GP_DATA(D_003729D0);
extern "C" int func_002EB4C8(int arg0) {
    int k = arg0;
    return SHT_Find(D_003729D0, k);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB550);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB568);

GP_DATA(D_003729D8);
GP_DATA(D_003729D4);
INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB680);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB738);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB858);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB970);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBA98);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBC18);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBDD8);

extern "C" void func_002EBDE0(S2EBDE0_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

extern "C" S2EBDE0_0 *func_002EBDF0(S2EBDE0_0 *self) {
    func_002EBDE0(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBE18);

struct SHT_R {
    int bits;
    SHT_N *tab;
    int count;
};
extern "C" void func_0011C408(int, void *);

static inline void SHT_Remove(SHT_R *t, const int &k) {
    SHT_N *prev;
    SHT_N *n;
    if (t->tab == 0) return;
    n = &t->tab[k & ((1 << t->bits) - 1)];
    prev = 0;
    if (n == 0) return;
    do {
        SHT_N *next = n->next;
        if (n->key == k && n->val != 0) {
            if (prev != 0) {
                prev->next = next;
                func_0011C408(0, n);
            } else {
                n->key = 0;
                n->val = 0;
            }
            t->count--;
            return;
        }
        prev = n;
        n = next;
    } while (n);
}

extern "C" void func_002EBFF8(SHT_R *t, int *kp) {
    SHT_Remove(t, *kp);
}
