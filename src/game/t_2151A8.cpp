#include "common.h"

struct S215 {
    char pad0[0xC];
    void* unkC;
    char pad10[0x10];
    void* unk20;
    char pad24[0x8];
    int unk2C;
};

extern "C" {
void func_0016C638(void*);
void func_0016C620(void*);
int func_001D1CF8(void*, u32);
int func_0027D0B0(int, int, void*, int);
void func_0016C798(int, int, void*);
int func_0027D058(int, int, void*, int);
void func_0016C650(int, f32);
void func_0016C6D0(int, int, void*);
void func_0016C4F8(int);
int func_0027DC58(int, int, void*, int);
void func_0016C7B8(int, int, int);
void func_0016C6A8(int, f32);
void func_0016C6B0(int, f32);
}

struct VP215 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 v12(int);
};

struct AP215 {
    s32 unk0;
    s32 unk4;
    s32 (VP215::*unk8)(int, int);
};

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_002151A8);

extern "C" void func_002167D8(void) {
}

extern "C" void func_002167E0(S215* p) {
    p->unk2C = func_001D1CF8(p->unkC, 0xCE0CA665);
}

extern "C" void func_00216818(S215* self) {
    if (self->unk20) {
        func_0016C638(self->unk20);
    }
}

extern "C" void func_00216840(S215* self) {
    if (self->unk20) {
        func_0016C620(self->unk20);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216868);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216BD8);

extern "C" s32 func_00216D78(VP215* p, AP215* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

struct VE215 {
    s16 delta;
    s16 unk2;
    void* fn;
};

extern "C" int func_00216E18(S215* self, int a) {
    char* o = (char*)self->unkC;
    if (*(u32*)(o + 0xC) & 1) return 0;
    char* p = (char*)self->unk20;
    if (!p) return 0;
    if (*(int*)(p + 0x1C) != a) return 0;
    VE215* e = (VE215*)(*(char**)(o + 8) + 0x40);
    ((void (*)(void*, int))e->fn)(o + e->delta, a);
    return 1;
}

extern "C" void func_00216E70(void) {
}

extern "C" int func_00216E78(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C6D0(p[8], 0, v);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00216ED0(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C6D0(p[8], 1, v);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00216F28(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C6D0(p[8], 2, v);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00216F80(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 0, v);
    }
    return 1;
}

extern "C" int func_00216FD0(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 1, v);
    }
    return 1;
}

extern "C" int func_00217020(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 2, v);
    }
    return 1;
}

extern "C" int func_00217070(char* p, int a) {
    func_0027DC58(a, 0, p + 0x1C, 1);
    if (*(int*)(p + 0x20)) {
        func_0016C7B8(*(int*)(p + 0x20), *(int*)(p + 0x1C), *(int*)(*(char**)(p + 0xC) + 0x2C));
    }
    return 1;
}

extern "C" int func_002170C8(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C650(p[8], v[0]);
    }
    return 1;
}

extern "C" int func_00217118(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6A8(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217170(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6B0(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}
