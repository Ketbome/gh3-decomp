#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct S2454 {
    char pad0[0xB];
    u8 unkB;
    char padC[0x4];
    TI128 unk10;
    char pad20[0x10];
    s16* unk30;
};

extern "C" {
extern u8 D_00370044;
void func_0010F690(void*);
void func_001342B0(void*);
extern u8 D_00397A50[];
extern u8 D_00354B58[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void*);
void func_0011A470(int);
void func_002454D0(S2454*, int, f32*);
void func_00248CF8(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245220);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002454C8);

extern "C" void func_002454D0(S2454* o, int i, f32* v) {
    if (o->unkB) {
        TI128 t;
        asm volatile("lqc2 $vf2, %0" : : "m"(o->unk10));
        int six = 6;
        asm volatile("lqc2 $vf1, %0" : : "m"(*(TI128*)v));
        int k = i * six;
        asm volatile("vsub.xyzw $vf1, $vf1, $vf2");
        f32 sc = 4096.0f;
        asm volatile("sqc2 $vf1, %0" : "=m"(t) : "f"(sc));
        f32* tf = (f32*)&t;
        register s32 x0 asm("$2") = (int)(tf[0] * sc);
        *(s16*)(k + (int)o->unk30) = x0;
        *(s16*)(k + (int)o->unk30 + 2) = (s16)(int)(tf[1] * sc);
        *(s16*)(k + (int)o->unk30 + 4) = (s16)(int)(tf[2] * sc);
    } else {
        int k = i * 12;
        *(f32*)(k + (int)o->unk30) = v[0];
        *(f32*)(k + (int)o->unk30 + 4) = v[1];
        *(f32*)(k + (int)o->unk30 + 8) = v[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245598);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002455A0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245648);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002456B0);

extern "C" void func_00246B08(void) {
}

extern "C" void func_00246B10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246B18);

extern "C" {
int func_00246BD8(int*);
int func_00246BC0(int*);
}

extern "C" int func_00246B30(int* p) {
    if (func_00246BD8(p)) {
        return func_00246BC0(p) + 8;
    }
    return func_00246BC0(p);
}

extern "C" int func_00246B78(int* p) {
    if (func_00246BD8(p)) {
        return func_00246BC0(p);
    }
    return func_00246BC0(p) + 8;
}

extern "C" int func_00246BC0(int* p) {
    return *p & 0xFFFFFFFC;
}

extern "C" int func_00246BD8(int* p) {
    return *p & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246BE8);

extern "C" void func_00246C50(int a, int b) {
    if (b == 0xFFFF && a) {
        u32* d = (u32*)D_00397A50;
        u32 k = 0xFFFFFFFF;
        d[5] = (u32)D_00354B58;
        d[1] = k;
        d[3] = (u32)d;
        d[4] = (u32)d;
        d[2] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246C98);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246CC0);

struct S246C {
    char pad0[0x18];
    int unk18;
    int unk1C;
};

extern "C" S246C* func_00246CC8(S246C* o) {
    func_00248CF8(o);
    o->unk18 = 0;
    o->unk1C = 0;
    return o;
}

extern "C" void func_00246CF8(char* p, int f) {
    int t = *(int*)(p + 0x1C);
    if (t) {
        func_0011A470(t);
    }
    if (f & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246D48);

extern "C" int func_00246DE0(char* p, int a, int b) {
    for (int i = 0; i < *(int*)(p + 0x18); i++) {
        int* e = (int*)(i * 4 + *(int*)(p + 0x1C));
        if (*e == a) {
            *e = b;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246E30);

GP_DATA(D_00370044);
extern "C" int func_00246EF0(void) {
    int v = D_00370044 + 1;
    D_00370044 = v;
    return v & 0xFF;
}

extern "C" void* func_00246F08(char* p) {
    func_0010F690(p);
    func_0010F690(p + 0x10);
    func_001342B0(p);
    *(int*)(p + 0x30) = 0;
    return p;
}

extern "C" void func_00246F48(char* p, int f) {
    if (*(s32*)(p + 0x30) != 0) {
        for (s32 i = 0; i < *(s32*)(p + 0x28); i++) {
            for (s32 j = 0; j < *(s32*)(p + 0x2C); j++) {
                func_00246CF8(*(char**)(*(s32*)(p + 0x30) + i * 4) + (j << 5), 2);
            }
        }
        func_0011A470(*(s32*)(p + 0x30));
        *(s32*)(p + 0x30) = 0;
    }
    if (f & 1) Heap_Free(D_00368A38[0], p);
}

struct P2470 {
    f32 x;
    f32 pad4;
    f32 z;
};

struct S2470 {
    f32 x1;
    f32 pad4;
    f32 z1;
    f32 padC;
    f32 x2;
    f32 pad14;
    f32 z2;
};

extern "C" s32 func_00247020(P2470* mn, P2470* mx, S2470* s) {
    if (mn->x <= s->x1 && mn->z <= s->z1 && s->x1 <= mx->x && s->z1 <= mx->z) {
        return 1;
    }
    if (s->x2 >= mn->x && s->z2 >= mn->z && s->x2 <= mx->x && s->z2 <= mx->z) {
        return 1;
    }
    f32 x1 = s->x1;
    f32 z1 = s->z1;
    f32 x2 = s->x2;
    f32 z2 = s->z2;
    f32 dx = x2 - x1;
    f32 dz = z2 - z1;
    if (dx == 0.0f) {
        dx = 0.000001f;
    }
    if (dz == 0.0f) {
        dz = 0.000001f;
    }
    if (mx->x < x1 && x2 < mx->x) {
        f32 y = ((mx->x - x1) * dz) / dx + z1;
        if (y < mx->z && mn->z < y) {
            return 1;
        }
    }
    if (x1 < mn->x && mn->x < x2) {
        f32 y = ((mn->x - x1) * dz) / dx + z1;
        if (y < mx->z && mn->z < y) {
            return 1;
        }
    }
    if (mx->z < z1 && z2 < mx->z) {
        f32 x = ((mx->z - z1) * dx) / dz + x1;
        if (x < mx->x && mn->x < x) {
            return 1;
        }
    }
    if (z1 < mn->z && mn->z < z2) {
        f32 x = ((mn->z - z1) * dx) / dz + x1;
        if (x < mx->x && mn->x < x) {
            return 1;
        }
    }
    return 0;
}
