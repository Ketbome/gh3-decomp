// cflags: -funroll-loops
#include "common.h"

struct L10 {
    char pad0[0xC];
    L10* unkC;
    L10* unk10;
};

struct S001C5A68 {
    char pad0[0x8];
    L10 unk8;
    char pad1C[0x4];
    s32 unk20;
};

struct S001C5A68_B {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    L10* unk10;
};

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, s32);
};

struct S001C5CB8 {
    char pad0[0x1C];
    void (*unk1C)(void);
};

struct S0036CDB4 {
    char pad0[0x14];
    VEnt* unk14;
    char pad18[0x2E8];
    s32 unk300;
};

extern "C" {
void func_001C6F60(S0036CDB4* p, void* params);
bool func_0027DF00(void* p, u32 key);
void* func_00113DF0(s32 size, s32 a, s32 b);
S0036CDB4* func_001C5D80(void* p);
void func_0027D1F8(void* p, s32 key, s32* v, s32 req);
void func_001C7668(S0036CDB4* p, s32 v);
s32 func_001CD2C8(s32 a);
void func_001CD318(void);
void func_001CD6B0(s32 a, s32 b);
extern u8 D_0034A8D0[];
extern S0036CDB4* D_0036CDB4;
extern u32 D_0036CDB8;
void func_00113FB8(s32 a);
void func_00119400(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0034A6A0[];
extern u8 D_0034A968[];
s32 func_00117F10(s32 a);
void func_00119490(s32 a, s32 b);
void func_001194B8(s32 a);
s32 func_00119610(s32 a, s32 b);
void func_001C6188(void* p, s32 a);
}

struct N1C79 {
    char pad0[0xC];
    N1C79* unkC;
    N1C79* unk10;
    void* unk14;
};

struct P1C74 {
    char pad0[0x20];
    s32 unk20;
};

struct KV1C6 {
    s32 key;
    s32 val;
};

struct B1C6 {
    char pad0[0xF4];
    KV1C6 e[1][32];
};

extern "C" void func_001C5A68(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;
    L10* h = &p->unk8;

    L10* nx = h->unk10;

    n->unkC = h;
    n->unk10 = nx;
    h->unk10->unkC = n;
    h->unk10 = n;
}

extern "C" void func_001C5A90(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;

    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
}

extern "C" void func_001C5AB8(S001C5A68* p, S001C5A68_B* b) {
    if (b->unkC == 0) {
        b->unk8 = 1;
        p->unk20 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5AD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5AE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5C10);

extern "C" void func_001C5C78(char* p, s32 flags) {
    *(void**)(p + 8) = D_0034A6A0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001C5CB8(S001C5CB8* p) {
    p->unk1C();
}

GP_DATA(D_0036CDB4);
GP_DATA(D_0036CDB8);
extern "C" S0036CDB4* func_001C5CD8(s32 a) {
    if (D_0036CDB4 == 0 && a != 0) {
        D_0036CDB4 = func_001C5D80(func_00113DF0(0x328, 0, 1));
    }
    D_0036CDB8++;
    return D_0036CDB4;
}

extern "C" void func_001C5D28(void) {
    S0036CDB4* p;

    if (D_0036CDB8 > 1) {
        D_0036CDB8--;
    } else {
        p = D_0036CDB4;
        if (p != 0) {
            p->unk14[1].fn((char*)p + p->unk14[1].delta, 3);
        }
        D_0036CDB4 = 0;
        D_0036CDB8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5D80);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6058);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6188);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6298);

extern "C" void func_001C63B8(char* p) {
    func_00113FB8(*(s32*)(p + 0x18));
    func_00113FB8(*(s32*)(p + 0x28));
    func_00113FB8(*(s32*)(p + 0x2C));
}

extern "C" void func_001C63F0(char* p) {
    s32 h = D_00368A38[0];
    func_00119490(h, func_00119610(h, 0x3A));
    char* q = *(char**)(p + 0x20);
    func_001C6188(q, *(s32*)(q + 0xB8));
    func_001194B8(D_00368A38[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6450);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6650);

extern "C" s32 func_001C67C0(char* p, s32 key, s32 idx) {
    for (int i = 0; i < 32; i++) {
        if (((B1C6*)p)->e[idx][i].key == key) return ((B1C6*)p)->e[idx][i].val;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6868);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C68D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6F60);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C74F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C7548);

struct L1C76 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
};

extern "C" void func_001C7668(S0036CDB4* unused, s32 v) {
    L1C76 l;
    l.unkC = D_0034A8D0;
    s32 r = func_001CD2C8(0);
    L1C76* q = (L1C76*)((char*)&l + 4);
    q->unk4 = r;
    func_001CD6B0(r, v);
    l.unkC = D_0034A8D0;
    func_001CD318();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C76C0);

extern "C" s32 func_001C7760(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetMenuAutoRepeatTimes);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetMenuPadMappings);

extern "C" int CFunc_SetButtonEventMappings(void* params) {
    S0036CDB4* p = D_0036CDB4;
    func_001C6F60(p, params);
    if (func_0027DF00(params, 0xDB96E524)) {
        *(s32*)((char*)p + 0xF0) = 1;
    } else if (func_0027DF00(params, 0x4F653B0B)) {
        *(s32*)((char*)p + 0xF0) = 0;
    }
    return 1;
}

extern "C" int CFunc_SetAnalogStickActiveForMenus(void* params) {
    s32 v = 1;

    func_0027D1F8(params, 0, &v, 0);
    func_001C7668(D_0036CDB4, v != 0);
    return 1;
}

extern "C" int CFunc_SetEnableMovies(void* params) {
    s32 v = 1;

    func_0027D1F8(params, 0, &v, 0);
    D_0036CDB4->unk300 = v != 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C79B0);

extern "C" void func_001C79E0(N1C79* n, s32 flags) {
    n->unk14 = D_0034A968;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        func_00119400(D_00368A38[0], n);
    }
}

extern "C" void func_001C7A40(N1C79* n, s32 flags) {
    n->unk14 = D_0034A968;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        func_00119400(D_00368A38[0], n);
    }
}
