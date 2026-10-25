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
extern "C" {
int func_0030B550(char*, const char*, ...);
int func_001150E0(u32, char*);
int func_0027D400(int, int, int*, int);
int func_002EAC68(int, int);
extern char D_003729C0[];
extern S2EB_L *D_003729D4;
extern int D_003729D8;
}

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

GP_DATA(D_003729D4);
GP_DATA(D_003729D8);
INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB568);

GP_DATA(D_003729D8);
GP_DATA(D_003729D4);
INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB680);

struct SHI_V {
    int unk0;
    int unk4;
};
struct SHI_N {
    int key;
    SHI_V *val;
    SHI_N *next;
};
struct SHI {
    int bits;
    SHI_N *tab;
    int pad8;
    int idx;
    SHI_N *cur;
};
extern "C" SHI *D_003729D0_i asm("D_003729D0");

static inline SHI *SHI_Begin(SHI *t) {
    t->idx = -1;
    t->cur = 0;
    return t;
}

static inline int SHI_Next(SHI *t, int size) {
    if (t->cur != 0) {
        t->cur = t->cur->next;
    } else if (t->idx >= 0) {
        return 0;
    }
    if (t->cur != 0) return 1;
    for (;;) {
        int i = t->idx + 1;
        t->idx = i;
        if (!(i < size)) return 0;
        SHI_N *p = t->tab + i;
        t->cur = p;
        if (p->val != 0) return 1;
        if (p->next != 0) {
            t->cur = p->next;
            return 1;
        }
    }
}

struct S2EB7_N {
    int unk0;
    int unk4;
    char pad8[0x14];
    u32 unk1C;
    char pad20[4];
    S2EB7_N *unk24;
};
struct S2EB7_V {
    int unk0;
    int unk4;
    char pad8[0x14];
    u32 unk1C;
};
extern "C" S2EB7_N *D_003729C8_l asm("D_003729C8");

extern "C" u32 func_002EB738(int kx) {
    register int k9 asm("$9") = kx;
    register u32 best asm("$7") = 0;
    register SHI *g asm("$2") = D_003729D0_i;
    SHI *t = SHI_Begin(g);
    register int k8 asm("$8") = k9;
    int size = 1 << t->bits;
    for (;;) {
        register S2EB7_V *v asm("$6");
        if (!SHI_Next(t, size)) {
            v = 0;
        } else {
            v = t->cur ? (S2EB7_V *)t->cur->val : 0;
        }
        if (v == 0) break;
        if (v->unk4 == k8) {
            if (best < v->unk1C) best = v->unk1C;
        }
    }
    register int k4 asm("$4") = k9;
    register S2EB7_N *n asm("$6");
    for (n = D_003729C8_l; n; n = n->unk24) {
        if (n->unk4 == k4) {
            if (best < n->unk1C) best = n->unk1C;
        }
    }
    return best;
}

struct S2EB8_V {
    int unk0;
    int unk4;
    char pad8[0xC];
    f32 unk14;
};
extern "C" void func_002EBA98_v(void *) asm("func_002EBA98");

extern "C" int func_002EB858(int kx, f32 x) {
    register S2EB8_V *best asm("$4") = 0;
    register int k8 asm("$8") = kx;
    register SHI *g asm("$2") = D_003729D0_i;
    SHI *t = SHI_Begin(g);
    int size = 1 << t->bits;
    for (;;) {
        register S2EB8_V *v asm("$3");
        if (!SHI_Next(t, size)) {
            v = 0;
        } else {
            v = t->cur ? (S2EB8_V *)t->cur->val : 0;
        }
        if (v == 0) break;
        if (v->unk4 == k8) {
            if (x < v->unk14) {
                best = v;
                x = v->unk14;
            }
        }
    }
    int r = 0;
    if (best) {
        func_002EBA98_v(best);
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB970);

struct S2EBA_E {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x10];
    u32 unk1C;
    S2EB_L *unk20;
    S2EBA_E *unk24;
};

extern "C" {
void func_002EBFF8_e(void *, int *) asm("func_002EBFF8");
void func_0028A300(int *);
void func_0026A660(int *);
u32 func_0011EF10(void *);
extern S2EBA_E *D_003729C4;
extern S2EBA_E *D_003729C8;
extern int D_003729CC;
}

GP_DATA(D_003729D0);
GP_DATA(D_003729C8);
GP_DATA(D_003729C4);
GP_DATA(D_003729CC);
extern "C" void func_002EBA98(S2EBA_E *e) {
    int t = e->unk0;
    func_002EBFF8_e(D_003729D0, &t);
    S2EB_L *it = e->unk20;
    S2EBA_E *cur = D_003729C8;
    if (it) {
        do {
            S2EB_L *p = it;
            it = it->next;
            switch (p->type) {
            case 0:
                func_0028A300(p->unk4);
                break;
            case 1:
                func_0026A660(p->unk4);
                break;
            case 2:
                func_002EB680(e->unk0, p->unk4);
                break;
            }
            p->next = D_003729D4;
            D_003729D4 = p;
            D_003729D8 -= 1;
        } while (it);
        cur = D_003729C8;
    }
    int found = 0;
    while (cur) {
        if (cur->unk4 == e->unk4) {
            u32 ec = e->unk1C;
            found = 1;
            if (cur->unk1C < ec) {
                cur->unk1C = ec;
            }
        }
        cur = cur->unk24;
    }
    u32 now = func_0011EF10(cur);
    if (found == 0 && now < e->unk1C + e->unk8) {
        e->unk24 = D_003729C8;
        D_003729C8 = e;
    } else {
        e->unk24 = D_003729C4;
        D_003729C4 = e;
    }
    D_003729CC -= 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBC18);

extern "C" int func_002EBCF8(int key) {
    int n = 0;
    register SHI *g asm("$2") = D_003729D0_i;
    SHI *t = SHI_Begin(g);
    int size = 1 << t->bits;
    for (;;) {
        SHI_V *v;
        if (!SHI_Next(t, size)) {
            v = 0;
        } else {
            v = t->cur ? t->cur->val : 0;
        }
        if (v == 0) break;
        if (v->unk4 == key) n++;
    }
    return n;
}

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
