// cflags: -funroll-loops
#include "common.h"

extern "C" {
s32 func_0019BF20(void* p);
void func_0019CCF8(void* p, s32 d);
s32 func_001ACD28(void* p);
extern s32 D_00372C1C;
void func_0019CD18(void* p, s32 d);
extern s32 D_00372C20;
}

struct T1AEF {
    char pad0[0x20];
    T1AEF* unk20;
    char pad24[4];
    T1AEF* unk28;
};

struct S001AFAC8 {
    char pad0[0x1C];
    u32 unk1C;
    char pad20[0x14];
    f32* unk34;
};

struct T1ADB {
    char pad0[0x20];
    T1ADB* unk20;
    char pad24[4];
    T1ADB* unk28;
    char pad2C[0xC];
    void* unk38;
    char pad3C[0x10];
    s32 unk4C;
};

extern "C" {
void func_0019ECE8(void);
s32 func_001A9A98(void* p, char* q);
void func_001A9B08(void* p, char* q);
void func_001A0380(s32 p, s32 f);
void Heap_Free(s32 h, void* p);
extern char D_0038C9A0[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

extern "C" void func_001ADBA8(T1ADB* p, s32 a) {
    func_0019ECE8();
    if (a != 0) {
        if (func_001A9A98(p, D_0038C9A0) == 0) {
            func_001A9B08(p, D_0038C9A0);
        }
    }
    if (func_001ACD28(p) != 0) {
        if (p->unk20 != 0) {
            Heap_Free(D_00368A38[0], p->unk20);
        }
        if (p->unk38 != 0) {
            Heap_Free(D_00368A38[0], p->unk38);
        }
    } else {
        T1ADB* c = p->unk20;
        while (c != 0) {
            T1ADB* n = c;
            c = c->unk28;
            func_001ADBA8(n, 0);
        }
    }
    if (p != 0) {
        if (p->unk4C != 0) {
            func_001A0380(p->unk4C, 3);
        }
        Heap_Free(D_00368A38[0], p);
    }
}

struct V1ADC {
    f32 x;
    f32 y;
    f32 z;
    char pad0C[0x14];
    V1ADC* unk20;
    char pad24[4];
    V1ADC* unk28;
};

struct H1ADC {
    char pad0[0x1DC];
    s32 unk1DC;
};

extern "C" {
s32 func_0019C648(void* p);
s32 func_0019BF20_c(void* p) __asm__("func_0019BF20");
void* Heap_Alloc(s32 h, s32 n, s32 a, s32 b);
void func_00119490(s32 h, s32 v);
void func_001194B8(s32 h);
void func_0019C700(void* p, void* q);
void func_0019C908(void* p, void* q, s32 z);
}

extern "C" void func_001ADC90(V1ADC* o, V1ADC* d) {
    o->x = o->x + d->x;
    o->y = o->y + d->y;
    o->z = o->z + d->z;
    if (func_001ACD28(o) != 0) {
        if (func_0019C648(o->unk20) == 0x20) {
            f32 s = 4096.0f;
            s32 ix = (s32)(d->x * s);
            s32 iy = (s32)(d->y * s);
            s32 iz = (s32)(d->z * s);
            s32 n = func_0019BF20_c(o->unk20);
            func_00119490(D_00368A38[0], ((H1ADC*)D_00368A38[0])->unk1DC);
            s32* b = (s32*)Heap_Alloc(D_00368A38[0], n * 16, 1, 0);
            func_0019C700(o->unk20, b);
            s32 i;
            for (i = 0; i < n; i++) {
                b[i * 4] += ix;
                b[i * 4 + 1] += iy;
                b[i * 4 + 2] += iz;
            }
            func_0019C908(o->unk20, b, 0);
            if (b != 0) {
                Heap_Free(D_00368A38[0], b);
            }
            func_001194B8(D_00368A38[0]);
        }
    } else {
        V1ADC* c = o->unk20;
        if (c != 0) {
            do {
                func_001ADC90(c, d);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADF60);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE1D8);

extern "C" s32 D_00372C14;

GP_DATA(D_00372C14);
extern "C" void func_001AE520(V1ADC* o, s32 out, s32 first) {
    if (first != 0) {
        D_00372C14 = 0;
    }
    if (func_001ACD28(o) != 0) {
        s32 n = func_0019BF20_c(o->unk20);
        func_00119490(D_00368A38[0], ((H1ADC*)D_00368A38[0])->unk1DC);
        s32* b = (s32*)(out + D_00372C14 * 16);
        func_0019C700(o->unk20, b);
        f32 s = 4096.0f;
        s32 off[3];
        off[0] = (s32)(o->x * s);
        off[1] = (s32)(o->y * s);
        off[2] = (s32)(o->z * s);
        s32 i;
        for (i = 0; i < n; i++) {
            f32* r = (f32*)(D_00372C14 * 16 + out);
            r[0] = (f32)(b[i * 4] + off[0]) * 0.000244140625f;
            r[1] = (f32)(b[i * 4 + 1] + off[1]) * 0.000244140625f;
            r[2] = (f32)(b[i * 4 + 2] + off[2]) * 0.000244140625f;
            r[3] = 1.0f;
            D_00372C14 += 1;
        }
        func_001194B8(D_00368A38[0]);
    } else {
        V1ADC* c = o->unk20;
        if (c != 0) {
            do {
                func_001AE520(c, out, 0);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

extern "C" s32 D_00372C18;
extern "C" void func_001AEB80(V1ADC* o, s32 out, s32 n);
extern "C" s32 func_001AD230(V1ADC* o, s32 z);

GP_DATA(D_00372C18);
extern "C" void func_001AE7A0(V1ADC* o, s32 out, s32 first) {
    if (first != 0) {
        D_00372C18 = 0;
    }
    if (func_001ACD28(o) != 0) {
        s32 n = func_0019BF20_c(o->unk20);
        func_001AEB80(o, out + D_00372C18 * 16, n);
        func_00119490(D_00368A38[0], ((H1ADC*)D_00368A38[0])->unk1DC);
        s32* b = (s32*)Heap_Alloc(D_00368A38[0], n * 16, 1, 0);
        s32 off[3];
        if (func_0019C648(o->unk20) < 0x20) {
            f32 s = 4096.0f;
            off[0] = (s32)(o->x * s);
            off[1] = (s32)(o->y * s);
            off[2] = (s32)(o->z * s);
        }
        s32 i;
        for (i = 0; i < n; i++) {
            if (func_0019C648(o->unk20) == 0x20) {
                f32* r = (f32*)(D_00372C18 * 16 + out);
                b[i * 4] = (s32)(r[0] * 4096.0f);
                b[i * 4 + 1] = (s32)(r[1] * 4096.0f);
                b[i * 4 + 2] = (s32)(r[2] * 4096.0f);
            } else {
                f32* r = (f32*)(D_00372C18 * 16 + out);
                b[i * 4] = (s32)(r[0] * 4096.0f) - off[0];
                b[i * 4 + 1] = (s32)(r[1] * 4096.0f) - off[1];
                b[i * 4 + 2] = (s32)(r[2] * 4096.0f) - off[2];
            }
            D_00372C18 += 1;
        }
        func_0019C908(o->unk20, b, 1);
        if (b != 0) {
            Heap_Free(D_00368A38[0], b);
        }
        func_001194B8(D_00368A38[0]);
    } else {
        V1ADC* c = o->unk20;
        if (c != 0) {
            do {
                func_001AE7A0(c, out, 0);
                c = c->unk28;
            } while (c != 0);
        }
        func_001AEB80(o, out, func_001AD230(o, 0));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AEB80);

GP_DATA(D_00372C1C);
extern "C" void func_001AEFF0(T1AEF* p, s32 dst, s32 first) {
    if (first != 0) {
        D_00372C1C = 0;
    }
    if (func_001ACD28(p) != 0) {
        s32 n = func_0019BF20(p->unk20);
        func_0019CCF8(p->unk20, dst + D_00372C1C * 4);
        D_00372C1C += n;
    } else {
        T1AEF* c = p->unk20;
        if (c != 0) {
            do {
                func_001AEFF0(c, dst, 0);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

GP_DATA(D_00372C20);
extern "C" void func_001AF090(T1AEF* p, s32 dst, s32 first) {
    if (first != 0) {
        D_00372C20 = 0;
    }
    if (func_001ACD28(p) != 0) {
        s32 n = func_0019BF20(p->unk20);
        func_0019CD18(p->unk20, dst + D_00372C20 * 4);
        D_00372C20 += n;
    } else {
        T1AEF* c = p->unk20;
        if (c != 0) {
            do {
                func_001AF090(c, dst, 0);
                c = c->unk28;
            } while (c != 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF130);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF3C8);

struct V1AF6 {
    char pad0[8];
    s32 unk8;
    char padC[4];
    long unk10;
    long unk18;
    long unk20;
};

struct K1AF6 {
    s32 unk0;
    V1AF6* unk4;
};

struct C1AF6 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    s32 unkC;
    K1AF6* unk10;
    s32 unk14;
    V1AF6* unk18;
};

struct O1AF6 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x20];
    C1AF6* unk44;
};

extern "C" {
s32 func_00275570(void);
void func_0019CFE8(s32 a, s32 b, long c);
extern s32 D_00370F40;
}

extern "C" void func_001AF608(O1AF6* o) {
    C1AF6* c = o->unk44;
    if (((c->unkA ^ 1) & 1) == 0) {
        if (c->unk14 != D_00370F40 + func_00275570()) {
            c->unk14 = D_00370F40 + func_00275570();
            c->unkA = c->unkA & 0xFFFD;
            s32 now = func_00275570();
            s32 cnt = c->unk0;
            K1AF6* keys = c->unk10;
            s32 lo = keys[0].unk0;
            s32 t = D_00370F40 + now - c->unkC;
            s32 span = keys[cnt - 1].unk0 - lo;
            s32 tm = lo + (t + c->unk4) % span;
            if (c->unk8 > 0) {
                if ((t - lo) / span >= c->unk8) {
                    tm = lo + (c->unk4 + span * c->unk8) % span;
                }
            }
            s32 i = cnt - 1;
            K1AF6* k2 = c->unk10;
            V1AF6* cur = c->unk18;
            if (i >= 0) {
                K1AF6* kp = k2 + i;
                while (tm < kp->unk0) {
                    i--;
                    kp--;
                    if (i < 0) break;
                }
            }
            V1AF6* nv = k2[i].unk4;
            if (c->unk18 != nv) {
                c->unk18 = nv;
                c->unkA |= 2;
            }
        }
        if (c->unkA & 2) {
            V1AF6* v = c->unk18;
            func_0019CFE8(o->unk20, 6, v->unk10);
            if (v->unk8 != 0) {
                func_0019CFE8(o->unk20, 0x34, v->unk18);
                if ((u32)v->unk8 >= 4) {
                    func_0019CFE8(o->unk20, 0x36, v->unk20);
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF7C0);

typedef unsigned int u128_1AF __attribute__((mode(TI)));
struct V1AF {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
struct N1AF {
    V1AF p;
    f32 r[3];
    u32 flags;
    N1AF* next;
};
extern "C" {
void func_0010F690(void*);
void func_0014F958(void* dst, u128_1AF a, u128_1AF b);
}

extern "C" void* func_001AF990(void* dst, N1AF* n) {
    V1AF lo, hi;
    while (!(n->flags & 2) && n->p.w >= 1e10f) n = n->next;
    lo = n->p;
    hi = n->p;
    f32* l = &lo.x;
    l[0] -= n->r[0];
    l[1] -= n->r[1];
    l[2] -= n->r[2];
    lo.w = 1.0f;
    f32* h = &hi.x;
    h[0] += n->r[0];
    h[1] += n->r[1];
    h[2] += n->r[2];
    lo.w = 1.0f;
    u128_1AF a = *(u128_1AF*)&lo;
    u128_1AF b = *(u128_1AF*)&hi;
    func_0010F690(dst);
    func_0010F690((char*)dst + 0x10);
    func_0014F958(dst, a, b);
    return dst;
}

extern "C" void func_001AFAC8(S001AFAC8* p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    p->unk34[0] = a;
    p->unk34[1] = e;
    p->unk34[2] = c;
    p->unk34[3] = g;
    p->unk34[4] = b;
    p->unk34[5] = f;
    p->unk34[6] = d;
    p->unk34[7] = h;
}

extern "C" void func_001AFB10(S001AFAC8* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x10000 : p->unk1C & ~0x10000;
}

extern "C" void func_001AFB40(S001AFAC8* p, f32 a, f32 b) {
    p->unk34[8] = a;
    p->unk34[9] = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AFB58);
