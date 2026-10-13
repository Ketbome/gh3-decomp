#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct VEntry219 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S219c {
    char pad0[0xC0];
    int unkC0;
    char padC4[0x21C];
    u64 unk2E0_0 : 14;
    u64 unk2E0_14 : 1;
    u64 unk2E0_15 : 3;
    u64 unk2E0_18 : 1;
};

struct S219b {
    char pad0[0x8];
    VEntry219* unk8;
};

struct S219 {
    char pad0[0xC];
    S219b* unkC;
    char pad10[0x8];
    VEntry219* unk18;
    S219c* unk1C;
    char pad20[0x2C];
    int unk4C;
    char pad50[0x4];
    void* unk54;
    char pad58[0x20];
    f32 unk78;
};

extern "C" {
void func_0021A750(int, int);
void func_0021B0F8(int, int);
void func_0021B290(S219*, int);
void func_0021B6B8(int, int);
void func_00163B00(void*, int);
int func_00163B50(void*);
int func_00163B50_k(void*, u32) __asm__("func_00163B50");
int func_001D1CF8(void*, u32);
void func_00205B00(void*);
int func_0027D268(int, int, void*, int);
int func_0027D470(int, int, void*, int);
void func_0021B368(void*, int);
int func_0027D2D8(int, u32, void*, int);
extern void* D_00368A38;
void Heap_Free(void*, void*);
void* func_001287F0(int, int);
void* func_0027AA70(void*);
void func_0027C1F8(void*, u32, f32);
void func_0027C898(int, u32, void*);
int func_0027D1F8(int, u32, void*, int);
int func_0027D400(int, u32, void*, int);
int func_0027D870(int, u32, void*, int);
void func_00163868(void*, int, int, void*);
void func_00163938(void*, int, int, void*);
void func_0027C448(void*, u32, int);
void func_0027C160(void*, u32, u32);
void func_002A2BE0(int, void*);
void func_0027AC90(void*);
void func_00113250(void*);
}

struct V219P {
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
    virtual s32 v12(int, int, int);
};

struct A219P {
    s32 unk0;
    s32 unk4;
    s32 (V219P::*unk8)(int, int, int);
};

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_00219920);

extern "C" void func_00219C50(S219* self, int a) {
    VEntry219* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_00219C78(char* p) {
    void* r = (void*)func_001D1CF8(*(void**)(p + 0xC), 0xCE0CA665);
    *(void**)(p + 0x54) = r;
    if (r) {
        func_00205B00(r);
    }
}

extern "C" void func_00219CB8(S219* self) {
    if (self->unk1C) {
        func_00163B00(self->unk1C, 0);
    }
}

extern "C" int func_00219CE0(S219* self, int a) {
    S219b* o = self->unkC;
    if (*(u32*)((char*)o + 0xC) & 1) return 0;
    S219c* p = self->unk1C;
    if (!p) return 0;
    if (*(int*)((char*)p + 0x1D8) != a) return 0;
    VEntry219* e = (VEntry219*)((char*)o->unk8 + 0x40);
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, a);
    return 1;
}

extern "C" void func_00219D38(S219* self, int v) {
    S219c* p = self->unk1C;
    if (p) {
        p->unk2E0_18 = v;
    }
}

extern "C" void func_00219D68(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_00219D70);

extern "C" int func_0021A100(S219* self, u32 key) {
    switch (key) {
    case 0x2299A9F2: {
        S219c* p = self->unk1C;
        int r = 0;
        if (p->unk2E0_14 || *(f32*)((char*)p + 0xA8) > 0.0f) r = 1;
        return r;
    }
    case 0x96896315: {
        S219c* p = self->unk1C;
        int r = 0;
        if (p) r = func_00163B50_k(p, key);
        return r;
    }
    default:
        return 2;
    }
}

extern "C" s32 func_0021A198(V219P* p, A219P* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(a->unk0, x, y);
    }
    return p->v12(a->unk0, x, y);
}

extern "C" void func_0021A230(void) {
}

extern "C" int func_0021A238(S219* self) {
    if (self->unk1C) {
        return func_00163B50(self->unk1C);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A260);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A298);

extern "C" int func_0021A320(S219* self) {
    if (self->unk1C) {
        self->unk1C->unkC0 = 0;
    }
    return 1;
}

extern "C" int func_0021A338(S219* self, int a, int s) {
    int v = 0;
    func_0027D400(s, 0x7031F10C, &v, 0);
    if (self->unk1C) {
        int w = 0;
        if (func_0027D870(s, 0xFC57577F, &w, 0)) {
            func_00163868(self->unk1C, w, v, self->unkC);
        }
        int x = 0;
        if (func_0027D870(s, 0x092276DB, &x, 0)) {
            func_00163938(self->unk1C, x, v, self->unkC);
        }
    }
    return 1;
}

extern "C" int func_0021A3F8(char* p) {
    char* t = *(char**)(p + 0x1C);
    if (t) {
        int r = 0;
        if ((*(u64*)(t + 0x2E0) & 0x4000) || *(f32*)(t + 0xA8) > 0.0f) {
            r = 1;
        }
        return r;
    }
    return 0;
}

inline void set_0021A448(S219c* p, int v) {
    p->unk2E0_14 = v;
}

extern "C" int func_0021A448(S219* self) {
    S219c* p = self->unk1C;
    if (p) {
        set_0021A448(p, 1);
    }
    return 1;
}

extern "C" int func_0021A470(S219* self) {
    S219c* p = self->unk1C;
    if (p) {
        p->unk2E0_14 = 0;
    }
    return 1;
}

extern "C" int func_0021A490(S219* self, int a, int b, int* c) {
    void* s = func_0027AA70(func_001287F0(8, 1));
    func_0027C1F8(s, 0x35B65BD4, *(f32*)((char*)self->unk1C + 0xA8));
    func_0027C898(c[8], 0x8A39583B, s);
    return 1;
}

extern "C" int func_0021A510(S219* self, int a, int b) {
    VEntry219* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A540);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A698);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A748);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A750);

extern "C" int func_0021AEA0(void) {
    return 0;
}

extern "C" int func_0021AEA8(void) {
    return 0;
}

extern "C" void func_0021AEB0(void) {
    func_0021A750(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021AED0);

extern "C" int func_0021AFD8(char* p, int s) {
    func_0027D268(s, 0x7323E97C, p + 0x30, 0);
    char* q = p + 0x34;
    func_0027D268(s, 0x0424D9EA, q, 0);
    func_0027D268(s, 0x9D2D8850, q, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B058);

extern "C" int func_0021B0A0(char** p, int a) {
    TI128 v;
    func_0027D2D8(a, 0xC4C809E, &v, 1);
    *(TI128*)(p[3] + 0xE0) = v;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B0E8);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B0F8);

extern "C" void func_0021B250(void) {
    func_0021B0F8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B270);

extern "C" void func_0021B290(S219* self, int a) {
    char* p = (char*)self;
    if (*(int*)(p + 0x80)) {
        if (!a) {
            void* s = func_0027AA70(func_001287F0(8, 1));
            func_0027C448(s, 0xA1DC81F9, *(int*)(*(char**)(p + 0xC) + 0x2C));
            func_0027C160(s, 0x99A9B716, 0x808080);
            func_002A2BE0(*(int*)(*(char**)(p + 0xC) + 0x2C), s);
            if (s) {
                func_0027AC90(s);
                func_00113250(s);
            }
        }
        if (*(int*)(p + 0x80) == 0) goto b6;
    } else {
    b6:
        if (a) {
            *(int*)(p + 0x7C) = 0;
            *(int*)(p + 0x74) = 0;
        }
    }
    *(int*)(p + 0x80) = a;
}

extern "C" void func_0021B360(S219* self, f32 v) {
    self->unk78 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B368);

extern "C" int func_0021B5E8(S219* self) {
    func_0021B290(self, 1);
    return 1;
}

extern "C" int func_0021B608(S219* self) {
    func_0021B290(self, 0);
    return 1;
}

extern "C" int func_0021B628(S219* self, int a) {
    f32 x;
    func_0027D268(a, 0, &x, 1);
    func_0021B360(self, x);
    return 1;
}

extern "C" int func_0021B670(S219* self, int a) {
    int x;
    func_0027D470(a, 0, &x, 1);
    func_0021B368(self, x);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B6B8);

extern "C" void func_0021B810(void) {
    func_0021B6B8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B830);

extern "C" S219* func_0021B870(S219* self) {
    self->unk4C = 0;
    return self;
}

struct D219 {
    char pad0[0x24];
    virtual ~D219();
};

extern "C" void func_0021B880(S219* self, int flags) {
    if (self->unk4C) {
        delete (D219*)self->unk4C;
        self->unk4C = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B8E8);
