// cflags: -funroll-loops
#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S00199370 {
    char pad[0x14];
    VEntry* unk14;
};

struct S00199BF0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    s8 unk18;
};

typedef unsigned int u128_199 __attribute__((mode(TI)));
struct S199_V { char pad0[0x14]; void* unk14; };
struct S199_A { u128_199 d[0x4D2]; };
struct S199_B { u128_199 d[0x8]; };
struct S199_C { u128_199 d[0x7]; };
struct S199_M { int m[16]; };
struct S199_K { u8 c[4]; };
struct S199_F { float unk0; float unk4; float unk8; float unkC; float unk10; float unk14; char pad18[0x8]; };

struct N199 { N199* c[16]; };


extern "C" {
extern int D_00368A38;
extern u8 D_003403C0[];
void Heap_Free(int, void*);
void* Heap_Alloc(int, int, int, int);
S199_A* func_001707C0(void*);
S199_B* func_00171540(void*);
S199_C* func_00171E60(void*);
extern s16 D_0036C0CE;
extern s16 D_0036C0CC;
extern char* D_0036C0C8;
extern int* D_0036C0C4;
void* func_0011A520(int, int);
void func_0019A088(int, S199_K*, int, int, int);
void func_0019A320(int, S199_K*, int, int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001992F8);

extern "C" int func_00199368(void) {
    return 1;
}

extern "C" int func_00199370(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199398(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001993D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001994A0);

extern "C" S199_A* func_00199960(S199_A* self) {
    S199_A* p = func_001707C0(Heap_Alloc(D_00368A38, 0x4D20, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_001999C8(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_001999F0(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" S199_B* func_00199A30(S199_B* self) {
    S199_B* p = func_00171540(Heap_Alloc(D_00368A38, 0x80, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_00199A98(void) {
    return 1;
}

extern "C" int func_00199AA0(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199AC8(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" S199_C* func_00199B08(S199_C* self) {
    S199_C* p = func_00171E60(Heap_Alloc(D_00368A38, 0x70, 1, 0));
    *p = *self;
    return p;
}

extern "C" int func_00199B78(void) {
    return 1;
}

extern "C" int func_00199B80(void) {
    return 1;
}

extern "C" int func_00199B88(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00199BB0(S199_V* self, int flags) {
    self->unk14 = D_003403C0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" S00199BF0* func_00199BF0(S00199BF0* self) {
    self->unk18 = 0;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

extern "C" S199_M* func_00199C18(S199_M* self) {
    for (int i = 0; i < 16; i++) {
        self->m[i] = 0;
    }
    return self;
}

GP_DATA(D_0036C0CE);
GP_DATA(D_0036C0CC);
GP_DATA(D_0036C0C8);
extern "C" void* func_00199C60(void) {
    if (D_0036C0CE) {
        if (D_0036C0CC < D_0036C0CE) {
            return D_0036C0C8 + D_0036C0CC++ * 64;
        }
        return 0;
    }
    return func_0011A520(1, 0x40);
}

GP_DATA(D_0036C0C4);
INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199CB8);

extern "C" int func_00199D28(int i) {
    return (i + 1) & 0xF;
}

extern "C" int func_00199D38(S199_M* tbl, int start) {
    int i = start;
    do {
        i = func_00199D28(i);
        if (tbl->m[i]) {
            return i;
        }
    } while (i != start);
    return -1;
}

extern "C" int func_00199D90(int root, S199_M* node, u32 key, int depth) {
    if (depth == 0) return (int)node;
    int idx = key & 0xF;
    int* slot = &node->m[idx];
    if (*slot == 0) {
        int n = (int)func_00199C60();
        if (n != 0) {
            *slot = n;
            if (depth == 1) {
                func_00199BF0((S00199BF0*)n);
            } else {
                func_00199C18((S199_M*)n);
            }
        } else {
            idx = func_00199D38(node, idx);
            if (idx < 0) return 0;
        }
    }
    key >>= 4;
    depth--;
    int start = idx;
    for (;;) {
        int r = func_00199D90(root, (S199_M*)node->m[idx], key, depth);
        if (r != 0) return r;
        idx = func_00199D38(node, idx);
        if (start == idx) return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199EA8);

struct Q_0019A088 { u8 a[4]; u8 b[4]; };

extern "C" void func_0019A088(int node, S199_K* box, int lvl, int qaddr, int val) {
    Q_0019A088* q = (Q_0019A088*)qaddr;
    if (node == 0) return;
    int sz = 1 << lvl;
    int d0 = box->c[0] - q->b[0];
    int d1 = box->c[1] - q->b[1];
    int d2 = box->c[2] - q->b[2];
    int d3 = box->c[3] - q->b[3];
    if (d0 < 0 && d1 < 0 && d2 < 0 && d3 < 0) {
        int e0 = q->a[0] - box->c[0];
        int e1 = q->a[1] - box->c[1];
        int e2 = q->a[2] - box->c[2];
        int e3 = q->a[3] - box->c[3];
        if (e0 < sz && e1 < sz && e2 < sz && e3 < sz) {
            int nsz = -sz;
            if (nsz >= d0 && nsz >= d1 && nsz >= d2 && nsz >= d3 && e0 <= 0 && e1 <= 0 && e2 <= 0 && e3 <= 0) {
                if (lvl == 0) {
                    *((u8*)node + 0x18) = val;
                    return;
                }
            }
            lvl--;
            int i = 0;
            int* p = (int*)node;
            do {
                {
                    S199_K nb;
                    nb.c[0] = box->c[0] + ((((i) >> 3) & 1) << lvl);
                    nb.c[1] = box->c[1] + ((((i) >> 2) & 1) << lvl);
                    nb.c[2] = box->c[2] + ((((i) >> 1) & 1) << lvl);
                    nb.c[3] = box->c[3] + (((i) & 1) << lvl);
                    func_0019A088(p[0], &nb, lvl, qaddr, val);
                }
                {
                    S199_K nb;
                    nb.c[0] = box->c[0] + ((((i + 1) >> 3) & 1) << lvl);
                    nb.c[1] = box->c[1] + ((((i + 1) >> 2) & 1) << lvl);
                    nb.c[2] = box->c[2] + ((((i + 1) >> 1) & 1) << lvl);
                    nb.c[3] = box->c[3] + (((i + 1) & 1) << lvl);
                    func_0019A088(p[1], &nb, lvl, qaddr, val);
                }
                i += 2;
                p += 2;
            } while (i < 16);
        }
    }
}

extern "C" void func_0019A2E0(int a, int b, int c) {
    S199_K k;
    k.c[0] = 0;
    k.c[1] = 0;
    k.c[2] = 0;
    k.c[3] = 0;
    func_0019A088(b, &k, 5, c, a);
}

extern "C" void func_0019A320(int node, S199_K* box, int lvl, int qaddr, void* outp) {
    Q_0019A088* q = (Q_0019A088*)qaddr;
    float* out = (float*)outp;
    if (node == 0) return;
    int sz = 1 << lvl;
    int d0 = box->c[0] - q->b[0];
    int d1 = box->c[1] - q->b[1];
    int d2 = box->c[2] - q->b[2];
    int d3 = box->c[3] - q->b[3];
    if (d0 < 0 && d1 < 0 && d2 < 0 && d3 < 0) {
        int e0 = q->a[0] - box->c[0];
        int e1 = q->a[1] - box->c[1];
        int e2 = q->a[2] - box->c[2];
        int e3 = q->a[3] - box->c[3];
        if (e0 < sz && e1 < sz && e2 < sz && e3 < sz) {
            int nsz = -sz;
            if (nsz >= d0 && nsz >= d1 && nsz >= d2 && nsz >= d3 && e0 <= 0 && e1 <= 0 && e2 <= 0 && e3 <= 0) {
                if (lvl == 0) {
                    float* n = (float*)node;
                    out[0] = out[0] + n[0];
                    out[1] = out[1] + n[1];
                    out[2] = out[2] + n[2];
                    out[3] = out[3] + n[3];
                    out[4] = out[4] + n[4];
                    out[5] = out[5] + n[5];
                    return;
                }
            }
            lvl--;
            int i = 0;
            int* p = (int*)node;
            do {
                {
                    S199_K nb;
                    nb.c[0] = box->c[0] + ((((i) >> 3) & 1) << lvl);
                    nb.c[1] = box->c[1] + ((((i) >> 2) & 1) << lvl);
                    nb.c[2] = box->c[2] + ((((i) >> 1) & 1) << lvl);
                    nb.c[3] = box->c[3] + (((i) & 1) << lvl);
                    func_0019A320(p[0], &nb, lvl, qaddr, out);
                }
                {
                    S199_K nb;
                    nb.c[0] = box->c[0] + ((((i + 1) >> 3) & 1) << lvl);
                    nb.c[1] = box->c[1] + ((((i + 1) >> 2) & 1) << lvl);
                    nb.c[2] = box->c[2] + ((((i + 1) >> 1) & 1) << lvl);
                    nb.c[3] = box->c[3] + (((i + 1) & 1) << lvl);
                    func_0019A320(p[1], &nb, lvl, qaddr, out);
                }
                i += 2;
                p += 2;
            } while (i < 16);
        }
    }
}

extern "C" S00199BF0* func_0019A5D8(S00199BF0* self, int a, int b) {
    S199_K k;
    k.c[0] = 0;
    k.c[1] = 0;
    k.c[2] = 0;
    k.c[3] = 0;
    func_00199BF0(self);
    func_0019A320(a, &k, 5, b, self);
    return self;
}

extern "C" float func_0019A640(int a, int b) {
    S199_F f;
    func_0019A5D8((S00199BF0*)&f, a, b);
    return f.unk14 - (f.unk4 * f.unk4 + f.unk8 * f.unk8 + f.unkC * f.unkC + f.unk10 * f.unk10) / f.unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AC40);

extern "C" int func_0019AE30(N199* n, int depth) {
    int c = 0;
    if (n) {
        if (depth > 0) {
            for (int i = 0; i < 16; i++) {
                c += func_0019AE30(n->c[i], depth - 1);
            }
        } else {
            c = 1;
        }
    }
    return c;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AF18);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AF20);
