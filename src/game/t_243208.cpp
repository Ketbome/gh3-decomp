// cflags: -funroll-loops
#include "common.h"

extern "C" {
void func_00244930_1(void*) __asm__("func_00244930");
extern u16 D_0032C7F8[];
extern u8 D_00397A40[];
extern u8 D_00397A00[];
void func_002432F8(int, int);
void Heap_Free(int, void*);
extern int D_0036FF08;
int func_002443C0(void*, int, int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00354B70[];
u8* func_00246B30(u8*);
u8* func_00246B78(u8*);
s32 func_00243FA8(u8* a, s32 b, s32 c);
int func_00244128_d(void*) __asm__("func_00244128");
}

extern "C" void func_00243208(void** p) {
    func_00244930_1(p[2]);
}

typedef int TI243 __attribute__((mode(TI)));

struct M243 {
    TI243 r[4];
};

struct S243 {
    char pad0[8];
    void* unk8;
    char pad0C[4];
    TI243 unk10;
    M243 unk20;
};

extern "C" void func_00246B10_m(void*, M243*, int, int, int) __asm__("func_00246B10");

static inline f32 Get243X(TI243 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}
static inline f32 Get243Y(TI243 q) {
    u32 t;
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(t) : "r"(q));
    asm("mtc1 %1, %0" : "=f"(f) : "r"(t));
    return f;
}
static inline f32 Get243Z(TI243 q) {
    u32 t;
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(t) : "r"(q));
    asm("mtc1 %1, %0" : "=f"(f) : "r"(t));
    return f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243228);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002432C0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002432F8);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243360);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243398);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002433A8);

extern "C" int func_00243470(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243478);

extern "C" int func_00243498(void) {
    return 0;
}

extern "C" void func_002434A0(void) {
}

extern "C" u8* func_002434A8(void) {
    return D_00397A40;
}

extern "C" void func_002434B8(void) {
}

extern "C" u8* func_002434C0(void) {
    return D_00397A00;
}

extern "C" char* func_002434D0(char* p) {
    return p + 0xA0;
}

extern "C" char* func_002434D8(char** p) {
    return p[2] + 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002434E8);

struct N243 {
    char pad0[0xC];
    N243* prev;
    N243* next;
    void* vt;
};

extern "C" void func_00243558(N243* p, int flags) {
    N243* t = p->next;
    p->vt = D_00354B70;
    t->prev = p->prev;
    p->prev->next = p->next;
    p->prev = p;
    p->next = p;
    if (flags & 1) Heap_Free(D_00368A38[0], p);
}

extern "C" void func_002435B8(void) {
    func_002432F8(1, 0xFFFF);
}

struct S2435 {
    char pad0[0xA];
    u8 unkA;
    char padB;
    void* unkC;
    char pad10[0x20];
    void* unk30;
    char pad34[4];
    void* unk38;
};

extern "C" void func_002435D8(S2435* p, s32 f) {
    if (p->unk30 != 0) {
        Heap_Free(D_00368A38[0], p->unk30);
    }
    if (p->unk38 != 0) {
        Heap_Free(D_00368A38[0], p->unk38);
    }
    if (p->unkC != 0) {
        if (p->unkA != 0) {
            Heap_Free(D_00368A38[0], p->unkC);
        } else {
            Heap_Free(D_00368A38[0], p->unkC);
        }
    }
    func_00244128_d(p);
    if (f & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243678);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002436D8);

extern "C" void* func_002436E0(int* p) {
    p[0] = 0;
    p[1] = 0;
    return p;
}

extern "C" int D_00368A38[] __attribute__((section(".sdata")));

extern "C" void func_002436F0(void* p, int f) {
    if (f & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00243720(int* p, int v) {
    *p = (*p & ~3) | (v & 3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243740);

extern "C" int func_00243A98(u8* n) {
    register u8* c asm("$16") = n + 4;
    int r;
    if (((*n & 3) ^ 3) != 0) {
        int a = func_00243A98(func_00246B30(c));
        int b = func_00243A98(func_00246B78(c)) + 1;
        asm("" : "+r"(b));
        r = a + b;
    } else {
        r = 1;
    }
    return r;
}

extern "C" int func_00243B08(u8* n) {
    register u8* c asm("$16") = n + 4;
    int r;
    if (((*n & 3) ^ 3) != 0) {
        register int a asm("$17") = func_00243B08(func_00246B30(c));
        r = a + func_00243B08(func_00246B78(c));
    } else {
        r = *(u16*)(n + 2);
    }
    return r;
}

extern "C" u32 func_00243B70(u8* n) {
    register u8* c asm("$16") = n + 4;
    u32 b;
    if (((*n & 3) ^ 3) != 0) {
        register u32 a asm("$17") = func_00243B70(func_00246B30(c));
        b = func_00243B70(func_00246B78(c));
        if (a < b) b = a;
    } else {
        b = *(u32*)(n + 4);
    }
    return b;
}

extern "C" void func_00243BE0(u32* p, int v) {
    if (v) {
        *p |= 1;
    } else {
        *p &= 0xFFFFFFFE;
    }
}

struct T243C {
    f32 v[4];
};

extern "C" void func_00243C10(u8* a, T243C* tbl) {
    s32 t = *a & 3;
    if ((t ^ 3) != 0) {
        s32 v = *(s32*)a >> 2;
        u8* c = a + 4;
        *(s32*)a = ((s32)(((f32)v * 0.000244140625f + tbl->v[t]) * 4096.0f) << 2) | t;
        func_00243C10(func_00246B30(c), tbl);
        func_00243C10(func_00246B78(c), tbl);
    }
}

static inline void Neg243(u8* n, int t) {
    s32 x = *(s32*)n;
    *(s32*)n = (-(x >> 2) << 2) | t;
    func_00243BE0((u32*)(n + 4), (*(u32*)(n + 4) & 1) ^ 1);
}

extern "C" void func_00243CC8(u8* n0, T243C* v, int mode, int flag) {
    T243C tmp;
    register u8* a0 asm("$4") = n0;
    u8* n = n0;
    if (flag) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvsuba.xyzw $ACC, $vf0, $vf1" : : "r"(v));
        register T243C* a1 asm("$5") = &tmp;
        asm volatile("vmsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, %0" : "=m"(tmp) : "r"(a1));
        func_00243C10(a0, a1);
    }
    s32 t = *n & 3;
    if ((t ^ 3) != 0) {
        int u = t;
        asm("" : "+r"(u));
        int one = 1;
        u8* c = n + 4;
        if (u != one) {
            int w = u ? 0 : 2;
            if (mode == 1) goto c1;
            if (mode < 2) goto rec;
            if (mode == 2) goto c2;
            if (mode == 3) goto c3;
            goto rec;
        c1:
            if (u == 0) Neg243(n, t);
            func_00243720((int*)n, w);
            goto rec;
        c2:
            Neg243(n, t);
            goto rec;
        c3:
            if (u == 2) Neg243(n, t);
            func_00243720((int*)n, w);
        }
    rec:
        func_00243CC8(func_00246B30(c), v, mode, 0);
        func_00243CC8(func_00246B78(c), v, mode, 0);
    }
    if (flag) func_00243C10(n, v);
}

extern "C" void func_00243E90(u8* n0, T243C* v, T243C* tbl, int flag) {
    T243C tmp;
    register u8* a0 asm("$4") = n0;
    u8* n = n0;
    if (flag) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvsuba.xyzw $ACC, $vf0, $vf1" : : "r"(v));
        register T243C* a1 asm("$5") = &tmp;
        asm volatile("vmsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, %0" : "=m"(tmp) : "r"(a1));
        func_00243C10(a0, a1);
    }
    s32 t = *n & 3;
    if ((t ^ 3) != 0) {
        s32 x = *(s32*)n >> 2;
        u8* c = n + 4;
        *(s32*)n = ((s32)(((f32)x * 0.000244140625f) * tbl->v[t] * 4096.0f) << 2) | t;
        func_00243E90(func_00246B30(c), v, tbl, 0);
        func_00243E90(func_00246B78(c), v, tbl, 0);
    }
    if (flag) func_00243C10(n, v);
}

extern "C" s32 func_00243FA8(u8* a, s32 b, s32 c) {
    if (((*a & 3) ^ 3) == 0) {
        *(s32*)(a + 4) = c + (*(s32*)(a + 4) << 1);
    } else {
        s32 v = *(s32*)(a + 4);
        u8* p = a + 4;
        *(s32*)(a + 4) = ((v & 0xFFFFFFFC) + b) | (v & 3);
        func_00243FA8(func_00246B30(p), b, c);
        func_00243FA8(func_00246B78(p), b, c);
    }
    return 1;
}

extern "C" s32 func_00244060(char* p) {
    if (D_0032C7F8[0] != 0) {
        for (s32 i = 0x7FF; i >= 0; i--) D_0032C7F8[i] = i;
    }
    return *(s32*)(p + 0x34) != 0;
}

extern "C" int func_00244128(char* p) {
    int r = 0;
    char* a = *(char**)(p + 0x34);
    if (a != 0) {
        u32 t = func_00243B70((u8*)a);
        if (t != 0) {
            Heap_Free(D_00368A38[0], (void*)t);
        }
        char* b = *(char**)(p + 0x34);
        if (b != 0) {
            char* q = b + *(int*)(b - 0x10) * 8;
            if (b != q) {
                do {
                    q -= 8;
                    func_002436F0(q, 0);
                } while (*(char**)(p + 0x34) != q);
            }
            Heap_Free(D_00368A38[0], *(char**)(p + 0x34) - 0x10);
        }
        *(char**)(p + 0x34) = 0;
        r = 1;
    }
    return r;
}

typedef int TI244 __attribute__((mode(TI)));

struct Box244 {
    TI244 lo;
    TI244 hi;
};

struct O244 {
    char pad0[8];
    u16 unk8;
};

extern "C" {
extern u16* D_0036FF04;
void func_002441D0_r(O244*, u8*, Box244*) __asm__("func_002441D0");
}

static inline bool Ge244(int a, int b) { return a >= b; }

GP_DATA(D_0036FF08);
GP_DATA(D_0036FF04);
extern "C" void func_002441D0(O244* self, u8* node, Box244* b) {
    int t = node[0] & 3;
    if (t == 3) {
        u32 n = *(u16*)(node + 2);
        u16* src = *(u16**)(node + 4);
        u16* dst = D_0036FF04 + D_0036FF08;
        int e = D_0036FF08 + n;
        D_0036FF08 = e;
        if ((int)self->unk8 < e) {
            D_0036FF08 = -1;
            return;
        }
        for (u32 i = 0; i < n; i++) {
            *dst++ = *src++;
        }
    } else {
        int off = t * 4;
        Box244 box;
        box.lo = b->lo;
        f32 plane = (f32)(*(int*)node >> 2) * 0.000244140625f;
        bool c = ((f32*)&box)[t] < plane;
        if (c) {
            func_002441D0_r(self, func_00246B30(node + 4), b);
        }
        box.hi = b->hi;
        bool d = 0;
        if (plane <= *(f32*)((char*)&box + off + 16)) {
            d = Ge244(D_0036FF08, 0);
        }
        if (d) {
            func_002441D0_r(self, func_00246B78(node + 4), b);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002443C0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002445A0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244898);

extern "C" int func_00244930(char* p, int b, int c) {
    int t = *(int*)(p + 0x34);
    if (!t) {
        return 0;
    }
    D_0036FF08 = 0;
    return func_002443C0(p, t, b, c) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244970);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244B68);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244C40);
