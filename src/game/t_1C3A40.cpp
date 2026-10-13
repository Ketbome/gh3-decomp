#include "common.h"

struct V3 {
    f32 x;
    f32 y;
    f32 z;
};

struct V2 {
    f32 x;
    f32 y;
};

struct S001C4460 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    V3* unk2C;
    V3* unk30;
    s32* unk34;
    V2* unk38;
    char pad3C[0x4];
    s32 unk40;
    s32 unk44;
    u32 unk48;
    s32 unk4C;
};

struct F2C {
    char pad0[0x2C];
    f32* unk2C;
    f32* unk30;
    char pad34[0x4];
    f32* unk38;
    char pad3C[0x8];
    s32 unk44;
};

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*);
};

struct S001C50B8 {
    char pad0[0x24];
    VEnt* unk24;
    char pad28[0x4];
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

extern "C" {
void func_001C5828(void* p, s32 a);
void* func_00113DF0(s32 size, s32 a, s32 b);
void* func_001C5778(void* p);
extern u32 D_0036CD60;
extern void* D_0036CD5C;
void Heap_Free(s32 heap, void* p);
void func_0016ED28(void* p);
void* operator_new(u32 size);
void func_0016ED90(void* p, s32 a);
extern u8 D_0034A4E8[];
extern u8 D_0034A658[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0034A640[];
struct VEntX {
    s16 delta;
    s16 index;
    void* fn;
};

struct N1C56 {
    char pad0[0xC];
    N1C56* unkC;
    N1C56* unk10;
    void* unk14;
};
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C3A40);

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C3DF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C41C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C41E0);

extern "C" void func_001C41E8(void) {
}

extern "C" void func_001C41F0(void) {
}

extern "C" void func_001C41F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C4200);

extern "C" void func_001C4388(void) {
}

extern "C" void* func_001C4390(char* p) {
    func_0016ED28(p);
    *(void**)(p + 0x24) = D_0034A4E8;
    *(s32*)(p + 0x4C) = 0x80808080;
    *(s32*)(p + 4) = *(s32*)(p + 4) | 1;
    *(s32*)(p + 0x2C) = 0;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    return p;
}

extern "C" void func_001C43F8(char* p, s32 a) {
    *(void**)(p + 0x24) = D_0034A4E8;
    if (*(s32*)(p + 0xC) == 1) {
        s32 t = *(s32*)(p + 0x2C);
        if (t != 0) {
            Heap_Free(D_00368A38[0], (void*)t);
        }
    }
    func_0016ED90(p, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C4460);

extern "C" void func_001C44C0(S001C4460* p, s32 v) {
    p->unk4C = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C44C8);

extern "C" void func_001C45F0(S001C4460* p) {
    if (p->unk38 == 0 || p->unk48 != 0) {
        p->unk4 = (p->unk4 & ~2) | 4;
    }
}

extern "C" void func_001C4628(void) {
}

extern "C" void func_001C4630(void) {
}

extern "C" s32 func_001C4638(S001C4460* a, S001C4460* b) {
    s32 both = 0;

    if (a->unk48 != 0) {
        if (b->unk48 == 0) {
            return -1;
        }
        both = 1;
    } else if (b->unk48 != 0) {
        return 1;
    }
    if (a->unk40 < b->unk40) {
        return 1;
    }
    if (b->unk40 < a->unk40) {
        return -1;
    }
    if (both) {
        if (a->unk48 < b->unk48) {
            return 1;
        }
        if (b->unk48 < a->unk48) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C46B8);

extern "C" void func_001C50B8(S001C50B8* p, s32 a, s32 b, s32 c, s32 d) {
    p->unk34 = b;
    p->unk38 = c;
    p->unk30 = d;
    p->unk2C = a;
    p->unk24[9].fn((char*)p + p->unk24[9].delta);
}

extern "C" void func_001C50F0(F2C* p, s32 i, f32 x, f32 y, f32 z) {
    s32 j = i * 3;

    p->unk2C[j] = x;
    p->unk2C[j + 1] = y;
    p->unk2C[j + 2] = z;
}

extern "C" void func_001C5128(S001C4460* p, s32 i, f32 v) {
    p->unk2C[i].x = v;
}

extern "C" void func_001C5140(S001C4460* p, s32 i, f32 v) {
    p->unk2C[i].y = v;
}

extern "C" void func_001C5158(S001C4460* p, s32 i, f32 v) {
    p->unk2C[i].z = v;
}

extern "C" void func_001C5170(F2C* p, s32 i, f32 x, f32 y, f32 z) {
    s32 j = i * 3;

    p->unk30[j] = x;
    p->unk30[j + 1] = y;
    p->unk30[j + 2] = z;
}

extern "C" void func_001C51A8(S001C4460* p, s32 i, f32 v) {
    p->unk30[i].x = v;
}

extern "C" void func_001C51C0(S001C4460* p, s32 i, f32 v) {
    p->unk30[i].y = v;
}

extern "C" void func_001C51D8(S001C4460* p, s32 i, f32 v) {
    p->unk30[i].z = v;
}

extern "C" void func_001C51F0(S001C4460* p, s32 i, s32 v) {
    p->unk34[i] = v;
}

extern "C" void func_001C5208(S001C4460* p, s32 i, f32 x, f32 y) {
    p->unk38[i].x = x;
    p->unk38[i].y = y;
}

extern "C" void func_001C5228(S001C4460* p, s32 i, f32 v) {
    p->unk38[i].x = v;
}

extern "C" void func_001C5240(S001C4460* p, s32 i, f32 v) {
    p->unk38[i].y = v;
}

extern "C" f32 func_001C5258(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk2C[j];
}

extern "C" f32 func_001C5278(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk2C[j + 1];
}

extern "C" f32 func_001C5298(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk2C[j + 2];
}

extern "C" f32 func_001C52B8(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk30[j];
}

extern "C" f32 func_001C52D8(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk30[j + 1];
}

extern "C" f32 func_001C52F8(F2C* p, s32 i) {
    s32 j = i * 3;

    return p->unk30[j + 2];
}

extern "C" s32 func_001C5318(S001C4460* p, s32 i) {
    return p->unk34[i];
}

extern "C" f32 func_001C5330(S001C4460* p, s32 i) {
    return p->unk38[i].x;
}

extern "C" f32 func_001C5348(S001C4460* p, s32 i) {
    return p->unk38[i].y;
}

extern "C" void func_001C5360(F2C* p, f32 x, f32 y, f32 z) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 3) {
        p->unk2C[j] += x;
        p->unk2C[j + 1] += y;
        p->unk2C[j + 2] += z;
    }
}

extern "C" void func_001C53D8(F2C* p, f32 v) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 3) {
        p->unk2C[j] += v;
    }
}

extern "C" void func_001C5420(F2C* p, f32 v) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 3) {
        p->unk2C[j + 1] += v;
    }
}

extern "C" void func_001C5468(F2C* p, f32 v) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 3) {
        p->unk2C[j + 2] += v;
    }
}

extern "C" void func_001C54B0(F2C* p, f32 x, f32 y) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 2) {
        p->unk38[j] += x;
        p->unk38[j + 1] += y;
    }
}

extern "C" void func_001C5510(F2C* p, f32 v) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 2) {
        p->unk38[j] += v;
    }
}

extern "C" void func_001C5558(F2C* p, f32 v) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < p->unk44; i++, j += 2) {
        p->unk38[j + 1] += v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C55A0);

extern "C" void* func_001C55A8(char* p) {
    *(s32*)(p + 4) = 0;
    *(s32*)(p + 0xC) = 0;
    *(void**)(p + 0x14) = D_0034A658;
    char* t = (char*)operator_new(0x18);
    *(void**)(t + 4) = p;
    *(void**)(t + 0x14) = D_0034A640;
    *(s32*)(t + 8) = 0;
    *(void**)(t + 0xC) = t;
    *(void**)(t + 0x10) = t;
    *(void**)(p + 0x10) = t;
    return p;
}

extern "C" void func_001C5610(char* p, s32 flags) {
    *(void**)(p + 0x14) = D_0034A658;
    char* t = *(char**)(p + 0x10);
    if (t != 0) {
        VEntX* e = (VEntX*)(*(char**)(t + 0x14) + 8);
        ((void (*)(char*, s32))e->fn)(t + e->delta, 3);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001C5680(N1C56* n, s32 flags) {
    n->unk14 = D_0034A640;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

GP_DATA(D_0036CD5C);
GP_DATA(D_0036CD60);
extern "C" void* func_001C56E0(s32 a) {
    if (D_0036CD5C == 0 && a != 0) {
        D_0036CD5C = func_001C5778(func_00113DF0(0x24, 0, 1));
    }
    D_0036CD60++;
    return D_0036CD5C;
}

extern "C" void func_001C5730(void) {
    if (D_0036CD60 > 1) {
        D_0036CD60--;
    } else {
        if (D_0036CD5C != 0) {
            func_001C5828(D_0036CD5C, 3);
        }
        D_0036CD5C = 0;
        D_0036CD60 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C5778);

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C5828);

INCLUDE_ASM("asm/nonmatchings/game/t_1C3A40", func_001C58C0);
