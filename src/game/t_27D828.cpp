// cflags: -funroll-loops
#include "common.h"

struct S0027E410 {
    char pad0[4];
    void *unk4;
    char pad8[0xE];
    u8 unk16;
};

struct S27E358_N {
    char pad0[8];
    S27E358_N *unk8;
};
struct S27E358 {
    u32 unk0;
    S27E358_N *unk4;
    int unk8;
};

extern "C" {
void func_0011C408(int, void *);
int func_0027D188(int, int, int *, int);
extern int D_00368A38;
void Heap_Free(int, void *);
void func_0027E358_v(void) asm("func_0027E358");
void func_0027E358(S27E358 *);
void func_0027E1E8(void *, int);
void func_0027F008(int, int);
int func_0027D870(int, int, int *, int);
int func_001150B8(int);
int func_0027CC30(int, int, int, int *);
void func_0027F1E0(int, int, int);
void func_002798B8(int);
void func_0013D100(int);
}

struct S0027EB70 {
    char pad[0x2];
    u8 unk2;
};

struct S0027E348 {
    int unk0;
    int unk4;
    int unk8;
};

struct S0027E698 {
    char pad[0x1];
    u8 unk1;
    u8 unk2;
    char pad1[0x1];
    int unk4;
    int unk8;
};

struct S0027EDB8 {
    char pad[0x4];
    int unk4;
    union {
        int v;
        int* a;
        float f;
        float* fa;
    } unk8;
};

struct S27EF20 {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    int unk4;
    int *unk8;
};

extern "C" int func_0027D828(int a, int b) {
    int out;
    int r;
    if (func_0027CC30(a, b, 3, &out) != 0) {
        r = out;
    } else {
        func_0027F1E0(a, 0, 1);
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027D870);

extern "C" void func_0027DC58(int a, int b, int *c, int d) {
    int out;
    int k = func_001150B8(b);
    out = 0;
    func_0027D870(a, k, &out, d);
    *c = out;
}

extern "C" int func_0027DCB8(int a, int b, int *c, int d) {
    if (func_0027D870(a, b, c, d) == 0) {
        int x = 0;
        if (func_0027D188(a, b, &x, d)) {
            *c = func_001150B8(x);
            return 1;
        }
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DD38);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DD88);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DF00);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E090);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E160);

struct S27E180_N {
    char pad0[0xC];
    S27E180_N *unkC;
};
struct S27E180 {
    char pad0[4];
    char *unk4;
};
extern "C" void func_0027E180(S27E180 *p, int n) {
    if (p->unk4 != 0) {
        p->unk4 = p->unk4 + n;
    }
    S27E180_N *c = (S27E180_N *)p->unk4;
    if (c != 0) {
        do {
            func_0027E1E8(c, n);
            c = c->unkC;
        } while (c != 0);
    }
}

struct S27E1E8 {
    u32 unk0;
    char pad4[4];
    int unk8;
    int unkC;
};
extern "C" void func_0027E1E8(void *q, int n) {
    S27E1E8 *p = (S27E1E8 *)q;
    if (p->unkC != 0) {
        p->unkC += n;
    }
    switch ((p->unk0 >> 9) & 0x7F) {
    case 3:
    case 5:
    case 6:
    case 7:
        p->unk8 += n;
        break;
    case 10:
        p->unk8 += n;
        func_0027E180((S27E180 *)p->unk8, n);
        break;
    case 12:
        p->unk8 += n;
        func_0027F008(p->unk8, n);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E288);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E300);

extern "C" void func_0027E348(S0027E348* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" void func_0027E358(S27E358 *p) {
    char *h = (char *)p->unk4;
    char *n;
    if (h) {
        u32 cnt;
        u32 i;
        n = h;
        cnt = 1 << p->unk0;
        for (i = 0; i < cnt; i++) {
            S27E358_N *m = ((S27E358_N *)n)->unk8;
            while (m) {
                S27E358_N *k = m;
                m = m->unk8;
                func_0011C408(0, k);
            }
            func_0027E348((S0027E348 *)n);
            n += 0xC;
        }
        p->unk8 = 0;
    }
}

extern "C" void func_0027E410(S0027E410 *p, int b) {
    if (p->unk16 == 0) {
        if (p->unk4) {
            func_0027E358_v();
            if (p->unk4) {
                Heap_Free(D_00368A38, p->unk4);
            }
            p->unk4 = 0;
        }
    }
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" S0027E348 *func_0027E488(S0027E348 *p) {
    func_0027E348(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E690);

extern "C" S0027E698* func_0027E698(S0027E698* p) {
    p->unk2 = 0;
    p->unk8 = 0;
    p->unk4 = 0;
    p->unk1 = 0;
    return p;
}

extern "C" void func_0027E6B0(int a, int b) {
    func_002798B8(a);
    if (b & 1) {
        func_0013D100(a);
    }
}

extern "C" int func_0027E6F8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E700);

struct S27E9D8_A {
    u32 unk0;
    int unk4;
    int unk8;
    int *Data() {
        if (unk4 == 1) {
            return &unk8;
        }
        return (int *)unk8;
    }
};
extern "C" void func_0027E700(S27E9D8_A *);
extern "C" int func_00119610(int, int);
extern "C" void func_00119490(int, int);
extern "C" void func_001194B8(int);
extern "C" char *func_0011A380(int);

extern "C" void func_0027E760(S27E9D8_A *p, int n, int c) {
    func_0027E700(p);
    ((char *)p)[2] = c;
    p->unk4 = n;
    if (n != 0) {
        if (n != 1) {
            int h = D_00368A38;
            func_00119490(h, func_00119610(h, 5));
            p->unk8 = (int)func_0011A380(p->unk4 * 4);
            func_001194B8(D_00368A38);
            u32 i = 0;
            int *w = (int *)p->unk8;
            if (p->unk4 != 0) {
                do {
                    *w = 0;
                    i++;
                    w++;
                } while (i < (u32)p->unk4);
            }
        }
    } else {
        ((char *)p)[2] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E820);

struct S27E9D8_E {
    u32 unk0;
    S27E9D8_A *unk4;
    int unk8;
};
extern "C" {
void func_0027EB78(S27E9D8_A *, int);
void func_0027E760(S27E9D8_A *, int, int);
void func_00279F10(int *, int *, int, int, int);
void func_0027A9B8(S27E9D8_A *, S27E9D8_A *, int);
void S27E9D8_set(S27E9D8_A *, int, char *) asm("func_0027EDB8");
char *StrDupHeap5(char *);
}
extern "C" void func_0027E9D8(S27E9D8_A *a, S27E9D8_E *e) {
    switch ((e->unk0 >> 9) & 0x7F) {
    case 12:
    case 21: {
        S27E9D8_A *s = (S27E9D8_A *)e->unk8;
        int n2 = s->unk4;
        if (n2 != 0) {
            int n = a->unk4;
            if (n == 0) {
                func_0027A9B8(a, s, 0);
            } else {
                func_0027EB78(a, n + n2);
                func_00279F10(a->Data() + n, s->Data(), n2, ((u8 *)s)[2], 0);
            }
        }
        break;
    }
    case 3: {
        if (a->unk4 != 0) {
            func_0027EB78(a, a->unk4 + 1);
        } else {
            func_0027E760(a, 1, 3);
        }
        int n = a->unk4;
        S27E9D8_set(a, n - 1, StrDupHeap5((char *)e->unk8));
        break;
    }
    case 1:
    case 2:
    case 13: {
        if (a->unk4 != 0) {
            func_0027EB78(a, a->unk4 + 1);
        } else {
            func_0027E760(a, 1, (e->unk0 >> 9) & 0x7F);
        }
        int n = a->unk4;
        a->Data()[n - 1] = e->unk8;
        break;
    }
    }
}

extern "C" void func_0027EB70(S0027EB70* p, u8 v) {
    p->unk2 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027EB78);

extern "C" void func_0027EDB8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EDE0(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE08(S0027EDB8* p, int i, float v) {
    if (p->unk4 == 1) {
        p->unk8.f = v;
    } else {
        p->unk8.fa[i] = v;
    }
}

extern "C" void func_0027EE30(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE58(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE80(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EEA8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EED0(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EEF8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" int func_0027EF20(S27EF20 *p, int i) {
    if (p->unk2 == 3) {
        if (p->unk4 == 1) {
            return (int)p->unk8;
        }
        return p->unk8[i];
    }
    return 0;
}

extern "C" int func_0027EF60(S27EF20 *p, int i) {
    if (p->unk2 == 3) {
        if (p->unk4 == 1) {
            return (int)p->unk8;
        }
        return p->unk8[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027EFA0);

struct S27F008 {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    u32 unk4;
    int unk8;
    int *Data() {
        if (unk4 == 1) {
            return &unk8;
        }
        return (int *)unk8;
    }
};
extern "C" void func_0027F008(int q, int n) {
    S27F008 *p = (S27F008 *)q;
    if (p->unk4 == 1) {
        switch (p->unk2) {
        case 3:
        case 5:
        case 6:
        case 7:
            p->unk8 += n;
            break;
        case 10:
            p->unk8 += n;
            func_0027E180((S27E180 *)p->unk8, n);
            break;
        case 12:
            p->unk8 += n;
            func_0027F008(p->unk8, n);
            break;
        }
    } else {
        p->unk8 += n;
        switch (p->unk2) {
        case 3:
        case 5:
        case 6:
        case 7: {
            int *d = p->Data();
            for (u32 i = 0; i < p->unk4; i++) {
                *d++ += n;
            }
            break;
        }
        case 10: {
            int *d = p->Data();
            for (u32 i = 0; i < p->unk4; i++) {
                *d += n;
                func_0027E180((S27E180 *)*d, n);
                d++;
            }
            break;
        }
        case 12: {
            int *d = p->Data();
            for (u32 i = 0; i < p->unk4; i++) {
                *d += n;
                func_0027F008(*d, n);
                d++;
            }
            break;
        }
        }
    }
}

extern "C" void func_0027F1E0(int, int, int) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F1E8);

extern "C" {
u8 *func_0027F1E8(u8 *, u8, int);
u8 *func_00285948(u8 *, u32);
u8 *func_002859B0(u8 *, u16);
}
extern "C" int func_0027F410(int ctx, u32 v, u8 *out, u32 cap) {
    u8 buf[0x20];
    u8 *p;
    u8 *start = out;
    int t = 1;
    if (v == 0) {
        t = 0x12;
    } else if (v < 0x100) {
        t = 0x10;
    } else if (v <= 0xFFFF) {
        t = 0x11;
    } else if (v + 0x80 < 0x100) {
        t = 0xE;
    } else if (!(0xFFFF < v + 0x8000)) {
        t = 0xF;
    }
    p = buf;
    switch (t) {
    case 1:
        p = func_00285948(func_0027F1E8(buf, t, ctx), v);
        break;
    case 14:
    case 16:
        p = func_0027F1E8(buf, t, ctx);
        *p = v;
        p++;
        break;
    case 15:
    case 17:
        p = func_002859B0(func_0027F1E8(buf, t, ctx), v);
        break;
    case 18:
        p = func_0027F1E8(buf, t, ctx);
        break;
    }
    u32 len = p - buf;
    if (len > cap) {
        return 0;
    }
    u8 *src = buf;
    for (u32 i = 0; i < len; i++) {
        *out++ = *src++;
    }
    return out - start;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F610);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F6C8);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F728);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F788);
