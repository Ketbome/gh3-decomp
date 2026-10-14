#include "common.h"

typedef unsigned int u128_244 __attribute__((mode(TI)));

extern "C" {
void func_00244930_1(void*) __asm__("func_00244930");
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
}

extern "C" void func_00243208(void** p) {
    func_00244930_1(p[2]);
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

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002435D8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244060);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244128);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002441D0);

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

struct V244 {
    f32 x, y, z;
};

struct S244 {
    char pad0[6];
    u16 unk6;
    char pad8[3];
    u8 unkB;
    char padC[4];
    u128_244 unk10;
    char pad20[0x10];
    V244* unk30;
    int unk34;
};

extern "C" void func_00244B68(S244* p, V244* v) {
    if (p->unk34) func_00243C10((u8*)p->unk34, (T243C*)v);
    char* a = (char*)p + 0x10;
    if (p->unkB == 0) {
        int i;
        for (i = 0; i < p->unk6; i++) {
            p->unk30[i].x += v->x;
            p->unk30[i].y += v->y;
            p->unk30[i].z += v->z;
        }
    }
    asm volatile("lqc2 $vf3, 0(%0)\n\tlqc2 $vf2, 0x10(%1)\n\tlqc2 $vf1, 0x10(%2)" : : "r"(v), "r"(p), "r"(a));
    asm volatile("vadd.xyzw $vf2, $vf2, $vf3\n\tsqc2 $vf2, 0x10(%0)\n\tvadd.xyzw $vf1, $vf1, $vf3" : : "r"(p));
    asm("sqc2 $vf1, %0" : "=m"(*(u128_244*)(a + 0x10)));
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244C40);
