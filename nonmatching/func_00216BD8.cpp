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

typedef unsigned int u128_216 __attribute__((mode(TI)));

struct VE216 {
    s16 delta;
    s16 pad;
    void* fn;
};

struct Q216 {
    u128_216 q0;
    u128_216 q1;
    char pad20[0xA0];
    s32 unkC0;
    char padC4[0x1C];
};

extern "C" {
int func_0027D870_216(int, u32, void*, int) __asm__("func_0027D870");
void func_00248D50(void*);
int func_00248E88(void*, int, int, int);
f32 func_00249120(void*);
int func_001D0578(int);
void func_001CE888(int, void*);
void func_0016C8C8(void*, f32);
void func_0016C5C0(void*, int);
void func_0016C4A0(void*, int);
}

extern "C" int func_00216BD8(S215* self, u32 key, int a) {
    switch (key) {
    case 0x2299A9F2: {
        char* o = (char*)self->unk20;
        VE216* e = (VE216*)(*(char**)(o + 8) + 0x38);
        return ((s32 (*)(void*))e->fn)(o + e->delta) != 0;
    }
    case 0x96896315: {
        s32 h = 0;
        f32 f = 1.0f;
        if (func_0027D870_216(a, 0x46E55E8F, &h, 0)) {
            if (h != 0) {
                f = ((f32*)func_001D1CF8((void*)func_001D0578(h), 0x286A8D26))[0x2EC / 4];
            }
        } else {
            Q216 q;
            func_00248D50(&q);
            u128_216 v = *(u128_216*)((char*)self->unkC + 0x80);
            q.q0 = v;
            q.q1 = v;
            ((f32*)&q)[1] += 0.025f;
            ((f32*)&q)[5] -= 120.0f;
            if (func_00248E88(&q, 1, 0, 0)) {
                f = func_00249120(&q) * 2.0f;
            }
            if (q.unkC0) {
                func_001CE888(q.unkC0, &q.unkC0);
                q.unkC0 = 0;
            }
        }
        if (self->unk20) {
            func_0016C8C8(self->unk20, f);
        }
        return 1;
    }
    case 0x34757FCA:
        if (self->unk20) {
            func_0016C5C0(self->unk20, 0);
            func_0016C4A0(self->unk20, 0);
        }
        return 1;
    }
    return 2;
}

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
