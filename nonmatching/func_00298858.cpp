// cflags: -funroll-loops
#include "common.h"

struct S00297458 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00296A70 {
    int unk0;
    char pad[0x28];
    int unk2C;
    int unk30;
    u8 unk34;
    char pad1[0xB];
    int unk40;
};

struct S00296A48 {
    int unk0;
    struct S00296A48* unk4;
    int unk8;
    struct S00296A48* unkC;
    struct S00296A48* unk10;
    void* unk14;
    int unk18;
};

struct S296A10_N {
    int unk0;
    S296A10_N *unk4;
    S296A10_N *unk8;
    S296A10_N *unkC;
};

struct S296A10_L {
    int unk0;
    S296A10_L *unk4;
    int unk8;
    S296A10_L *unkC;
    S296A10_L *unk10;
    void *unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct S296A10_A {
    int unk0;
    S296A10_A *unk4;
    int unk8;
    S296A10_A *unkC;
    S296A10_A *unk10;
    void *unk14;
    u8 unk18;
    char pad19[0x1];
    u8 unk1A;
    char pad1B[0xD];
    int unk28;
    int unk2C;
};

struct S296A10_B {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    int unk4;
    int unk8;
    int unkC;
    u8 unk10;
    char pad11[0x3];
    int unk14;
    int unk18;
    int unk1C;
    u8 unk20;
};

struct S296A10_C {
    char pad0[0x18];
    void *unk18;
};

struct S296CB8 {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    int unk4;
    char pad8[4];
    int unkC;
};

extern "C" {
int func_00296B28(u8 *, u16 *, int, int);
void func_0030A2F4(int, int, int);
void operator_delete(void *);
int memset(void *, int, int);
extern char D_0035C330[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void*);
extern char D_0035C4D0[];
extern char D_0035C2E8[];
extern char D_0035C2B0[];
extern char D_0035C390[];
extern char D_0035C378[];
int Heap_Alloc(int, int, int, int);
extern char D_0035C298[];
extern char D_0035C348[];
extern char D_0035C360[];
}

extern "C" S296A10_A *func_00296A10(S296A10_A *p, int a) {
    p->unk2C = a;
    p->unk4 = p;
    p->unk14 = D_0035C2E8;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk1A = 0;
    p->unk28 = 0;
    p->unk18 = 0;
    return p;
}

extern "C" S00296A48* func_00296A48(S00296A48* p, int b) {
    p->unk18 = b;
    p->unk4 = p;
    p->unk14 = D_0035C330;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    return p;
}

extern "C" S00296A70* func_00296A70(S00296A70* p) {
    p->unk0 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk40 = 0;
    return p;
}

struct S296A90 {
    char pad0[0x2C];
    void *unk2C;
    char pad30[0x10];
    int unk40;
};
extern "C" void func_00296A90(S296A90 *p, int b) {
    if (p->unk2C != 0) {
        if (p->unk40 == 0) {
            Heap_Free(D_00368A38[0], p->unk2C);
        }
    }
    if (b & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" S296A10_B *func_00296AF0(S296A10_B *p) {
    p->unk0 = 0;
    p->unk8 = 0x80;
    p->unk1 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk20 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296B28);

extern "C" S296CB8 *func_00296CB8(S296CB8 *p, u8 a, u16 len, int src, s8 mode) {
    u8 sa = a;
    u16 sl = len;
    int x;
    p->unkC = 0;
    p->unk4 = 0;
    if (sl) {
        x = 0;
        if (mode) {
            x = func_00296B28(&sa, &sl, src, mode);
            if (x) {
                src = x;
            }
        }
        p->unk4 = Heap_Alloc(D_00368A38[0], sl, 1, 0);
        func_0030A2F4(p->unk4, src, sl);
        if (x) {
            Heap_Free(D_00368A38[0], (void *)x);
        }
    }
    p->unk0 = sa;
    p->unk2 = sl;
    return p;
}

struct Sfunc_00296D88 {
    char pad0[4];
    void *unk4;
};
extern "C" void func_00296D88(Sfunc_00296D88 *p, int b) {
    if (p->unk4 != 0) {
        Heap_Free(D_00368A38[0], p->unk4);
    }
    if (b & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

struct S296DE0 {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    int unk4;
    u8 unk8;
    char pad9[7];
    int unk10;
};
extern "C" S296DE0 *func_00296DE0(S296DE0 *p, u8 a, u16 len, int src, u8 c, s8 mode) {
    u8 sa = a;
    u16 sl = len;
    int x;
    p->unk10 = 0;
    p->unk4 = 0;
    if (sl) {
        x = 0;
        if (mode) {
            x = func_00296B28(&sa, &sl, src, mode);
            if (x) {
                src = x;
            }
        }
        p->unk4 = Heap_Alloc(D_00368A38[0], sl, 1, 0);
        func_0030A2F4(p->unk4, src, sl);
        if (x) {
            Heap_Free(D_00368A38[0], (void *)x);
        }
    }
    p->unk8 = c;
    p->unk0 = sa;
    p->unk2 = sl;
    return p;
}

struct Sfunc_00296EC0 {
    char pad0[4];
    void *unk4;
};
extern "C" void func_00296EC0(Sfunc_00296EC0 *p, int b) {
    if (p->unk4 != 0) {
        Heap_Free(D_00368A38[0], p->unk4);
    }
    if (b & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

struct S296F18 {
    int unk0;
    u8 unk4;
    char pad5[3];
    u64 unk8;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20[0x200];
    int unk220;
    int unk224;
};
extern "C" S296F18 *func_00296F18(S296F18 *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk220 = 0;
    p->unk224 = 0;
    memset(p->unk20, 0, 0x200);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296F70);

extern "C" int func_002972F8(u8 *src, int n, u8 *dst, int *limit) {
    int out = 0;
    while (n != 0) {
        u8 c = *src;
        u8 i;
        n--;
        src++;
        if (!(c & 0x80)) {
            i = 0;
            do {
                if (!(out < *limit)) {
                    return -1;
                }
                i++;
                out++;
                *dst = *src;
                src++;
                dst++;
                n--;
            } while (!(c < i));
        } else {
            u32 cnt = (c & 0x7F) + 2;
            i = 0;
            if (cnt != 0) {
                do {
                    if (!(out < *limit)) {
                        return -1;
                    }
                    i++;
                    out++;
                    *dst = *src;
                    dst++;
                } while (i < cnt);
            }
            src++;
            n--;
        }
    }
    *limit = out;
    return 0;
}

extern "C" void func_002973C0(S296A10_C *p, int flags) {
    p->unk18 = D_0035C2B0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297400);

extern "C" S00297458* func_00297458(S00297458* p) {
    p->unk0 = 0;
    p->unk4 = 5;
    p->unk8 = 0;
    return p;
}

struct S297470 {
    char pad0[8];
    S297470 *unk8;
    int unkC;
};
extern "C" void func_00297470(int a, S297470 *p) {
    S297470 *next;
    if (p != 0) {
        do {
            func_00297470(a, (S297470 *)p->unkC);
            next = p->unk8;
            if (p != 0) {
                operator_delete(p);
            }
            p = next;
        } while (p != 0);
    }
}

extern "C" void func_002974D8(S296A10_N *x, S296A10_N **root) {
    S296A10_N *y = x->unkC;
    x->unkC = y->unk8;
    if (y->unk8 != 0) {
        y->unk8->unk4 = x;
    }
    y->unk4 = x->unk4;
    if (x == *root) {
        *root = y;
    } else if (x == x->unk4->unk8) {
        x->unk4->unk8 = y;
    } else {
        x->unk4->unkC = y;
    }
    y->unk8 = x;
    x->unk4 = y;
}

extern "C" void func_00297528(S296A10_N *x, S296A10_N **root) {
    S296A10_N *y = x->unk8;
    x->unk8 = y->unkC;
    if (y->unkC != 0) {
        y->unkC->unk4 = x;
    }
    y->unk4 = x->unk4;
    if (x == *root) {
        *root = y;
    } else if (x == x->unk4->unkC) {
        x->unk4->unkC = y;
    } else {
        x->unk4->unk8 = y;
    }
    y->unkC = x;
    x->unk4 = y;
}

extern "C" void func_00297578(S296A10_N *x, S296A10_N **root) {
    x->unk0 = 0;
    while (x != *root && x->unk4->unk0 == 0) {
        if (x->unk4 == x->unk4->unk4->unk8) {
            S296A10_N *y = x->unk4->unk4->unkC;
            if (y && y->unk0 == 0) {
                x->unk4->unk0 = 1;
                y->unk0 = 1;
                x->unk4->unk4->unk0 = 0;
                x = x->unk4->unk4;
            } else {
                if (x == x->unk4->unkC) {
                    x = x->unk4;
                    func_002974D8(x, root);
                }
                x->unk4->unk0 = 1;
                x->unk4->unk4->unk0 = 0;
                func_00297528(x->unk4->unk4, root);
            }
        } else {
            S296A10_N *y = x->unk4->unk4->unk8;
            if (y && y->unk0 == 0) {
                x->unk4->unk0 = 1;
                y->unk0 = 1;
                x->unk4->unk4->unk0 = 0;
                x = x->unk4->unk4;
            } else {
                if (x == x->unk4->unk8) {
                    x = x->unk4;
                    func_00297528(x, root);
                }
                x->unk4->unk0 = 1;
                x->unk4->unk4->unk0 = 0;
                func_002974D8(x->unk4->unk4, root);
            }
        }
    }
    (*root)->unk0 = 1;
}

struct S2976_P {
    int a;
    int b;
};

struct S2976_V {
    int key;
    S2976_P second;
};

struct S2976_N {
    int unk0;
    S2976_N *unk4;
    S2976_N *unk8;
    S2976_N *unkC;
    S2976_V value;
};

struct S2976_T {
    char pad0[4];
    S2976_N *header;
    int count;
};

extern "C" int func_00297CC0(int);

extern "C" S2976_N **func_002976E8(S2976_N **ret, S2976_T *t, int x, S2976_N *y, S2976_V *v, int flag) {
    S2976_N *z;
    if (y == t->header || (flag == 0 && (x != 0 || v->key < y->value.key))) {
        S2976_N *n = (S2976_N *)func_00297CC0(0x1C);
        if (&n->value != 0) {
            n->value.key = v->key;
            n->value.second = v->second;
        }
        z = n;
        y->unk8 = z;
        if (y == t->header) {
            y->unk4 = z;
            t->header->unkC = z;
        } else if (y == t->header->unk8) {
            t->header->unk8 = z;
        }
    } else {
        S2976_N *n = (S2976_N *)func_00297CC0(0x1C);
        if (&n->value != 0) {
            n->value.key = v->key;
            n->value.second = v->second;
        }
        z = n;
        y->unkC = z;
        if (y == t->header->unkC) {
            t->header->unkC = z;
        }
    }
    z->unk4 = y;
    z->unk8 = 0;
    z->unkC = 0;
    func_00297578((S296A10_N *)z, (S296A10_N **)&t->header->unk4);
    t->count++;
    *ret = z;
    return ret;
}

extern "C" S296A10_N *RbTreeDecrement(S296A10_N *x) {
    if (x->unk0 == 0 && x->unk4->unk4 == x) {
        x = x->unkC;
    } else if (x->unk8) {
        S296A10_N *y = x->unk8;
        while (y->unkC) {
            y = y->unkC;
        }
        x = y;
    } else {
        S296A10_N *y = x->unk4;
        while (x == y->unk8) {
            x = y;
            y = y->unk4;
        }
        x = y;
    }
    return x;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002978C0);

extern "C" S296A10_N *RbTreeIncrement(S296A10_N *x) {
    if (x->unkC) {
        x = x->unkC;
        while (x->unk8) {
            x = x->unk8;
        }
    } else {
        S296A10_N *y = x->unk4;
        while (x == y->unkC) {
            x = y;
            y = y->unk4;
        }
        if (x->unkC != y) {
            x = y;
        }
    }
    return x;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297A48);

extern "C" int func_00297CC0(int a) {
    return Heap_Alloc(D_00368A38[0], a, 1, 0);
}

extern "C" void operator_delete(void* p) {
    Heap_Free(D_00368A38[0], p);
}

extern "C" void func_00297D18(S296A10_L *p, int flags) {
    p->unk14 = D_0035C390;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00297D78(S296A10_L *p, int flags) {
    p->unk14 = D_0035C378;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00297DD8(S296A10_L *p, int flags) {
    p->unk14 = D_0035C360;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00297E38(S296A10_L *p, int flags) {
    p->unk14 = D_0035C348;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

struct S297E98 {
    int unk0;
    S296A10_N *unk4;
    int unk8;
};
extern "C" void func_00297E98(S297E98 *p, int b) {
    if (p->unk8 != 0) {
        func_00297470((int)p, (S297470 *)p->unk4->unk4);
        p->unk4->unk8 = p->unk4;
        p->unk4->unk4 = 0;
        p->unk4->unkC = p->unk4;
        p->unk8 = 0;
    }
    if (p->unk4) {
        operator_delete(p->unk4);
    }
    if (b & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" int func_00297F20(void) {
    return 1;
}

extern "C" int func_00297F28(void) {
    return 1;
}

extern "C" void func_00297F30(S296A10_L *p, int flags) {
    p->unk14 = D_0035C298;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00297F90(S296A10_L *p, int flags) {
    p->unk14 = D_0035C298;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00297FF0(S296A10_L *p, int flags) {
    p->unk14 = D_0035C378;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00298050(S296A10_L *p, int flags) {
    p->unk14 = D_0035C360;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_002980B0(S296A10_L *p, int flags) {
    p->unk14 = D_0035C348;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00298110(S296A10_L *p, int flags) {
    p->unk14 = D_0035C390;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" S296A10_L *func_00298170(S296A10_L *p, int a, int b, int c, int d) {
    p->unk4 = p;
    p->unk8 = d;
    p->unkC = p;
    p->unk10 = p;
    p->unk14 = D_0035C4D0;
    p->unk18 = a;
    p->unk1C = c;
    p->unk20 = b;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002981A0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002982B8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298390);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298448);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298558);

extern "C" char D_0035C4B8[];

struct S298_Ev {
    char pad0[4];
    u8 unk4;
    char pad5[0x13];
    int unk18;
    int unk1C;
};
struct S298_El;
typedef int (*S298_Fn)(S298_Ev *, S298_El *);
struct S298_El {
    int pad0;
    S298_El *unk4;
    char pad8[0x10];
    S298_Fn unk18;
    int unk1C;
    int unk20;
};
struct S298_Lk {
    int unk0;
    S298_El *unk4;
    int unk8;
    S298_Lk *unkC;
};
struct S298_It {
    int pad0;
    S298_Lk *cur;
    char *vptr;
    S298_It(S298_Lk *l) { cur = l; vptr = D_0035C4B8; }
    ~S298_It() { vptr = D_0035C4B8; }
};

static inline void S298_Pick(S298_El *&o, S298_Lk *c) {
    if (!c) o = 0;
    else o = c->unk4;
}

static inline S298_El *S298_Get0(S298_Lk *c) {
    S298_El *r;
    S298_Pick(r, c);
    return r;
}

extern "C" int func_00298858(char *base, S298_Ev *ev) {
    S298_Lk *n0, *n1, *nn;
    S298_El *e, *nx;
    S298_It *pa;
    int r;
    S298_It it((S298_Lk *)(base + ev->unk4 * 0x18));
    n0 = it.cur->unkC;
    it.cur = (~(int)n0->unk4 == 0) ? 0 : n0;
    e = S298_Get0(it.cur);
    if (e) {
        pa = &it;
        while (e) {
            n1 = it.cur->unkC;
            nn = 0;
            if (~(int)n1->unk4 != 0) nn = n1;
            pa->cur = nn;
            nx = S298_Get0(nn);
            if ((e->unk20 & ev->unk18) == ev->unk18) {
                ev->unk1C = e->unk1C;
                r = e->unk18(ev, e);
                if (r == 0 || r == 2 || r == 5 || r == 3) return r;
                if (r == 4) break;
            }
            e = nx;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002989C8);
