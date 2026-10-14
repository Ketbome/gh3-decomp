// cflags: -funroll-loops
#include "common.h"

struct S00267628 {
    char pad[0x4];
    int unk4;
};

struct S266800_A {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    int unk14;
};

struct S2668_Ent {
    char pad0[0x8];
    int unk8;
    char padC[0xC];
};

struct S2668_Src {
    int unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    int unk10;
    int unk14;
};

struct S2668_Ctx {
    int unk0;
    char pad4[0xC];
    f32 unk10;
};

struct S2668_Out {
    int unk0;
    int unk4;
    int unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    int unk30;
};

struct S2676F0_4 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S2676F0_4 *unk10;
    S2676F0_4 *unk14;
};

struct S266E90_E {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char pad10[0x38];
    int unk48;
    char pad4C[0xC];
};

struct S267A80 {
    char pad0[8];
    f32 unk8;
    f32 unkC;
};

extern "C" {
f32 func_0031B970(f32, f32);
void func_002684D8(int, int, f32);
void func_0026F828(f32, int, int);
void func_00266928(f32 *, f32);
extern S266E90_E D_003A1900E[44] asm("D_003A1900");
void func_00266C08(void);
void func_00270BD0(void *);
int func_00268388(int, int, int);
void func_002680D0(int, int, int);
int func_002670B0(int, int);
void func_00267660(int, void *, int);
int func_002681B0(int, int);
int func_002679E0_i(int) asm("func_002679E0");
void func_00267910(int, int);
void func_0026FA80(void);
void func_00266FA8(int);
int func_00267048(int, int);
void func_00269420(int, void *);
extern int D_00370B10;
extern void *D_00370B0C;
extern int D_00370AF0;
extern int D_00370B00;
extern int D_00370AF4;
extern S2668_Ent D_003A2820[128];
void func_002709C8(void);
extern int D_00370AEC;
void func_0026FA38(int);
void func_0026FA78(void);
int memset(int, int, int);
int func_00266778(void);
extern float D_00370AE8;
extern int D_00369CD8;
extern int D_00369A64;
extern f32 D_00370B04;
extern f32 D_00370B08;
extern f32 D_00368764;
void func_00275EE8(u32, int);
void func_0026F580(f32);
void func_0026D688(f32);
void func_0026F5A8(f32);
void func_0026D6B0(f32);
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void *);
extern int D_00370AE0;
extern int D_00370AE4;
void func_00266F50(int, int);
int func_00113DF0(int, int, int);
int func_00266E90(int);
}

GP_DATA(D_00370AE0);
GP_DATA(D_00370AE4);
extern "C" int func_00266800(int a) {
    if (D_00370AE0 == 0 && a != 0) {
        D_00370AE0 = func_00266E90(func_00113DF0(0xC, 0, 1));
    }
    D_00370AE4++;
    return D_00370AE0;
}

extern "C" void func_00266850(void) {
    if ((u32)D_00370AE4 >= 2) {
        D_00370AE4--;
    } else {
        if (D_00370AE0 != 0) {
            func_00266F50(D_00370AE0, 3);
        }
        D_00370AE0 = 0;
        D_00370AE4 = 0;
    }
}

struct S266898_O {
    char pad0[0x14];
    int unk14;
};
extern "C" S266898_O *func_00266898(S266898_O *p) {
    if (D_00370AE0 != 0) {
        p->unk14 = ((int *)D_00370AE0)[2];
    } else {
        p->unk14 = 0;
    }
    memset((int)p, 0, 0x14);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002668E8);

extern "C" void func_002668F8(void *p, int flags) {
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_00266928(f32 *a, f32 f) {
    int n = (((int *)a)[5] == 2) ? 5 : 2;
    u32 i;
    for (i = 0; i < (u32)n; i++) {
        a[i] = a[i] * f * 0.01f;
    }
}

extern "C" f32 func_00266A20(f32 *v) {
    u32 n = ((int *)v)[5] == 2 ? 5 : 2;
    f32 m = __builtin_fabsf(v[0]);
    for (u32 i = 1; i < n; i++) {
        f32 a = __builtin_fabsf(v[i]);
        if (m < a) m = a;
    }
    return m;
}

extern "C" int func_00266B60(S266800_A *p) {
    if (p->unk0 != 0.0f || p->unk4 != 0.0f) {
        return 0;
    }
    if (p->unk14 == 2) {
        if (p->unk8 != 0.0f || p->unkC != 0.0f || p->unk10 != 0.0f) {
            return 0;
        }
    }
    return 1;
}

extern "C" void func_00266BE8(int a) {
    memset(a, 0, 20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266C08);

struct S266CE0 {
    char pad0[0x10];
    void *unk10;
};
GP_DATA(D_00370B10);
GP_DATA(D_00370B0C);
extern "C" int func_00266CE0(S266CE0 *p) {
    func_00269420(D_00370B10, p);
    p->unk10 = D_00370B0C;
    D_00370B0C = p;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266D20);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266E08);

extern "C" int func_00266E90(int arg0) {
    if (func_00266778() == 0) {
        int i;
        ((int *)arg0)[2] = 0;
        func_00270BD0((void *)arg0);
        func_00266C08();
        for (i = 0; i < 44; i++) {
            D_003A1900E[i].unk0 = 0;
            D_003A1900E[i].unk4 = 0;
            D_003A1900E[i].unk8 = 0;
            D_003A1900E[i].unkC = 0;
            D_003A1900E[i].unk48 = 0;
        }
    }
    return arg0;
}

extern "C" void func_00266F50(int a, int b) {
    if (func_00266778() == 0) {
        func_00266FA8(a);
    }
    if (b & 1) {
        Heap_Free(D_00368A38[0], (void *)a);
    }
}

GP_DATA(D_00370AF0);
GP_DATA(D_00370B00);
GP_DATA(D_00370AF4);
GP_DATA(D_00370AE8);
extern "C" void func_00266FA8(int) {
    if (func_00266778() == 0) {
        D_00370AF0 = 0;
        D_00370B00 = 0;
        for (int i = 127; i >= 0; i--) {
            D_003A2820[i].unk8 = 0;
        }
        func_002709C8();
        D_00370AF4 = 0;
        D_00370AE8 = 25.0f;
    }
}

struct S267_L {
    int unk0;
    char pad4[0xC];
    S267_L *unk10;
};

extern "C" int func_00267048(int a, int b) {
    if (func_00268388(a, b, 0) != 0)
        return 0;
    S267_L *p = (S267_L *)D_00370AF0;
    int r = 1;
    if (p) {
        for (; p; p = p->unk10) {
            if (p->unk0 == b)
                return 0;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002670B0);

extern "C" int func_002672C0(int a, int b) {
    while (func_00267048(a, b) == 0) {
        b++;
    }
    return b;
}

extern "C" void func_00267310(float v) {
    if (func_00266778() == 0) {
        D_00370AE8 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267340);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267348);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267610);

extern "C" int func_00267628(S00267628* p) {
    if (p->unk4 != 0) {
        return 0;
    }
    if (D_00369CD8 != 0) {
        return 1;
    }
    return D_00369A64 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267658);

extern "C" void func_00267660(int a, void *np, int c) {
    S2676F0_4 *n = (S2676F0_4 *)np;
    n->unk8 = 0;
    if (c != 0 && func_00268388(a, n->unk0, 0) != 0) {
        func_002681B0(a, n->unk0);
    }
    if (n->unk10 != 0) {
        n->unk10->unk14 = n->unk14;
    }
    if (n->unk14 != 0) {
        n->unk14->unk10 = n->unk10;
    } else {
        D_00370AF0 = (int)n->unk10;
    }
    D_00370B00 -= 1;
}

struct S2676F0 {
    char pad0[0xC];
    int unkC;
    S2676F0 *unk10;
};
extern "C" void func_002676F0(int a, int b) {
    S2676F0 *p = (S2676F0 *)D_00370AF0;
    S2676F0 *q;
    if (p != 0) {
        q = p;
        do {
            p = p->unk10;
            if (q->unkC == b) {
                func_00267660(a, q, 1);
            }
            q = p;
        } while (p != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267750);

extern "C" void func_00267758(void* p, int v) {
    D_00370AEC = v;
}

extern "C" void func_00267760(int a, int b, int c) {
    S2676F0_4 *p = (S2676F0_4 *)D_00370AF0;
    S2676F0_4 *q;
    if (p != 0) {
        do {
            q = p;
            p = p->unk10;
            if (q->unkC == b && (c == 0 || q->unk4 == c)) {
                func_00267660(a, q, 1);
            }
        } while (p != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002677E0);

extern "C" void func_002678F0(int a, int b) {
    func_0026FA38(b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267910);

extern "C" void func_002679E0(void) {
    func_0026FA78();
}

extern "C" void func_00267A00(int a) {
    int i = 0;
    while (i < func_002679E0_i(a)) {
        func_00267910(a, i);
        i++;
    }
    func_0026FA80();
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267A60);

extern "C" void func_00267A80(int a, int b, f32 *p, S267A80 *q) {
    if (func_00266778() != 0) {
        return;
    }
    func_00266928((f32 *)b, 50.0f);
    if (q->unkC != 100.0f) {
        func_00266928((f32 *)b, q->unkC);
    }
    if (q->unk8 != 100.0f) {
        *p = *p * q->unk8 * 0.01f;
    }
}

extern "C" void func_00267B30(int unused, S2668_Out *out, S2668_Ctx *ctx, S2668_Src *src) {
    if (src) {
        out->unk0 = src->unk0;
        f32 x = src->unk4;
        out->unk10 = x;
        f32 y = src->unk8;
        out->unk14 = y;
        f32 z = src->unkC;
        if (z == 0.0f) {
            z = ctx->unk10;
        }
        out->unkC = z;
        out->unk20 = x;
        out->unk24 = y;
        out->unk28 = 0.0f;
        out->unk18 = x;
        out->unk1C = y;
        out->unk2C = 0.0f;
        out->unk30 = src->unk10;
        out->unk8 = src->unk14;
    } else {
        out->unk0 = 0;
        out->unk14 = out->unk10 = 100.0f;
        out->unkC = 0.0f;
        out->unk30 = 0;
        out->unk8 = 0;
    }
    out->unk4 = ctx->unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267BC8);

extern "C" int func_00267F00(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267F08);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002680D0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268130);

extern "C" int func_002681B0(int a, int b) {
    if (func_00266778() == 0) {
        int r = func_002670B0(a, b);
        if (r < 0) {
            return 0;
        }
        func_00275EE8(0xD7BB618D, 0);
        func_002680D0(a, r, 0);
    }
    return 1;
}

GP_DATA(D_00370B04);
extern "C" void func_00268228(f32 f) {
    if (func_00266778() == 0) {
        func_00275EE8(0xD7BB618D, 0);
        D_00370B04 = f;
        f = f * D_00368764 * 0.01f;
        if (f < 0.1f) {
            f = 0.0f;
        }
        func_0026F580(f);
        func_0026D688(f);
    }
}

extern "C" void func_002682B8(f32 f) {
    if (func_00266778() == 0) {
        func_00275EE8(0xD7BB618D, 0);
        if (f <= 0.01f) {
            f = 0.01f;
        }
        D_00370B08 = f;
        func_0026F5A8(f);
        func_0026D6B0(f);
    }
}

extern "C" f32 func_00268328(void) {
    return D_00370B04;
}

extern "C" void func_00268330(int, int a, int b, f32 f) {
    if (func_00266778() == 0) {
        func_0026F828(f, a, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268388);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268468);

extern "C" void func_00268480(int a, f32 *v, int b) {
    func_002684D8(a, b, func_0031B970(v[0], -v[2]) * 57.295776f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002684D8);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002687F0);
