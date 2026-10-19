#include "common.h"

struct S1F79E8 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual s32 v12(int);
};

struct S1F79E8_A {
    s32 unk0;
    s32 unk4;
    s32 (S1F79E8::*unk8)(int, int);
};

struct S1F9740_R {
    char pad0[0x14];
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual s32 v4(s32, void*, void*);
    virtual void v5(void*);
};

struct S1F9860_N {
    S1F9860_N* unk0;
    S1F9860_N* unk4;
    S1F9740_R* unk8;
};

struct S1F9860_I {
    s32 unk0;
    S1F9860_N* unk4;
};

struct S1F9860 {
    char pad0[0x48];
    S1F9860_N unk48;
};

struct E1F8D90 {
    u32 key;
    char pad4[0xC];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

struct N1F8D90 {
    N1F8D90* unk0;
    N1F8D90* unk4;
    E1F8D90 e;
};

struct I1F8D90 {
    s32 unk0;
    N1F8D90* unk4;
};

struct S1F8D90 {
    char pad0[0x3C];
    N1F8D90 unk3C;
};

extern "C" {
s32 func_001F9D70(void*);
s32 func_00133CE8(void*, s32, int, void*);
s32 func_001317D0(void*, s32);
s32 func_001F7B10(void*, s32, void*);
s32 func_001F7C70(void*, s32, void*);
s32 func_001F7D70(void*, s32, void*);
s32 func_001F7E70(void*, s32, void*);
bool func_0027D870(void*, u32, s32*, int);
void func_001FA218(void*, s32);
s32 func_001F9C58(void*, s32);
s32 func_001F9D18(void*, s32);
s32 func_001F9EC8(void*, s32);
void func_0027C448(void*, int, u32);
S1F9740_R* func_001F9A50(void*, s32);
s32 func_0027D1F8(void*, u32, s32*, int);
s32 func_0027D268(void*, u32, f32*, int);
}

extern "C" void func_001F79D8(void) {
}

extern "C" s32 func_001F79E0() {
    return 2;
}

extern "C" s32 func_001F79E8(S1F79E8* p, S1F79E8_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" s32 func_001F7A88(char* p, s32 a, void* b) {
    return func_00133CE8(*(void**)(p + 0x1C), a, 3, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7AB0);

extern "C" s32 func_001F7AC8(char* p, s32 a, void* b) {
    return func_001F7B10(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7B10);

extern "C" s32 func_001F7C28(char* p, s32 a, void* b) {
    return func_001F7C70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7C70);

extern "C" s32 func_001F7D28(char* p, s32 a, void* b) {
    return func_001F7D70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7D70);

extern "C" s32 func_001F7E28(char* p, s32 a, void* b) {
    return func_001F7E70(p, func_001317D0(*(void**)(p + 0x1C), a), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7E70);

extern "C" void func_001F7F28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F7F30);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F86D0);

struct V1F86 {
    int a;
    int b;
};

struct E1F86 {
    u32 key;
    u32 type;
    V1F86 v;
};

extern E1F86 T1F86[] __asm__("D_0038F260");
extern V1F86 S1F86_0[] __asm__("D_0036E468");
extern V1F86 S1F86_1[] __asm__("D_0036E470");
extern V1F86 S1F86_2[] __asm__("D_0036E478");
extern V1F86 S1F86_3[] __asm__("D_0036E480");
extern V1F86 S1F86_4[] __asm__("D_0036E488");
extern V1F86 S1F86_5[] __asm__("D_0036E490");
extern V1F86 S1F86_6[] __asm__("D_0036E498");
extern V1F86 S1F86_7[] __asm__("D_0036E4A0");
extern V1F86 S1F86_8[] __asm__("D_0036E4A8");
extern V1F86 S1F86_9[] __asm__("D_0036E4B0");
extern V1F86 S1F86_10[] __asm__("D_0036E4B8");
extern V1F86 S1F86_11[] __asm__("D_0036E4C0");
extern V1F86 S1F86_12[] __asm__("D_0036E4C8");
extern V1F86 S1F86_13[] __asm__("D_0036E4D0");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_001F86D8(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E1F86* e = T1F86;
        V1F86 t;
        e->key = 0x20F7B992;
        t = *S1F86_0;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x613831F2;
        t = *S1F86_1;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x6E26E771;
        t = *S1F86_2;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0xBE1C58CA;
        t = *S1F86_3;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0xE3DC4090;
        t = *S1F86_4;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0xEC2F19ED;
        t = *S1F86_5;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x22D9E993;
        t = *S1F86_6;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0xB244C9CF;
        t = *S1F86_7;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0xF99F9FAF;
        t = *S1F86_8;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x7757F7F9;
        t = *S1F86_9;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x59F986B3;
        t = *S1F86_10;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x731281D5;
        t = *S1F86_11;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x36E5DAF4;
        t = *S1F86_12;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        e->key = 0x204AB493;
        t = *S1F86_13;
        e->type = 0x222756D5;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0x222756D5;
        e->v = t;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8A88);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8AB8);

extern "C" s32 func_001F8C08(void* p) {
    func_001F9D70(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8C28);

extern "C" s32 func_001F8D40(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x5CFCCF35, &v, 0);
    func_001FA218(p, v);
    return 1;
}

static inline E1F8D90* Find1F8D90(S1F8D90* p, u32 key) {
    I1F8D90 it;
    I1F8D90 e;
    it.unk4 = p->unk3C.unk4;
    e.unk4 = &p->unk3C;
    while (it.unk4 != e.unk4) {
        E1F8D90* c = &it.unk4->e;
        if (c->key == key) {
            return c;
        }
        if (key < c->key) {
            return 0;
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk3C;
    }
    return 0;
}
extern "C" s32 func_001F8D90(S1F8D90* p, void* u, void* a) {
    s32 v = 0;
    func_0027D1F8(a, 0x3D836C96, &v, 1);
    E1F8D90* f = Find1F8D90(p, v);
    if (f) {
    f32 x = 0.0f;
    f32 y = 0.0f;
    func_0027D268(a, 0x4D786F62, &x, 1);
    func_0027D268(a, 0xBF237659, &y, 0);
    f32 b = y;
    f32 c = x;
    f->unk1C = b;
    f->unk14 = c;
    f->unk18 = 0.0f;
    if (b == 0.0f) {
        f->unk10 = c;
    }
    return 1;
    }
    return 0;
}

struct N1F90 {
    N1F90* unk0;
    N1F90* unk4;
    s32 unk8;
};

struct I1F90 {
    s32 unk0;
    N1F90* unk4;
};

struct S1F90 {
    char pad0[0x3C];
    N1F90 unk3C;
};

extern "C" {
s32 func_0012CEE8(void* p, u32 k);
void func_0012C758(s32 o, f32 a, f32 b);
}

static inline s32 Find1F90(S1F90* p, u32 key) {
    I1F90 it;
    I1F90 e;
    it.unk4 = p->unk3C.unk4;
    e.unk4 = &p->unk3C;
    while (it.unk4 != e.unk4) {
        s32 r = func_0012CEE8(&it.unk4->unk8, key);
        if (r != 0) {
            return r;
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk3C;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F8EA8);

extern "C" s32 func_001F9028(void* p, void* u, void* a, void** b) {
    s32 v = 0;
    func_0027D870(a, 0x5CFCCF35, &v, 0);
    if (func_001F9EC8(p, v)) {
        func_0027C448(b[8], 0, 0xC7C6228C);
        return 1;
    }
    return 0;
}

extern "C" s32 func_001F90A0(S1F90* p, void* u, void* a) {
    s32 v1 = Find1F90(p, 0x6D8E11A8);
    s32 v2 = Find1F90(p, 0x49E0EE96);
    f32 y = 0.0f;
    func_0027D268(a, 0xBF237659, &y, 0);
    if (v1 != 0) {
        func_0012C758(v1, 1.0f, y);
    }
    if (v2 != 0) {
        func_0012C758(v2, 0.0f, y);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F91E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F9478);

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F95C8);

extern "C" s32 func_001F9740(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x7321A8D6, &v, 1);
    S1F9740_R* r = func_001F9A50(p, v);
    if (!r) {
        return 0;
    }
    r->v5(a);
    return 1;
}

extern "C" bool func_001F97C0(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x40C698AF, &v, 1);
    return func_001F9C58(p, v) != 0;
}

extern "C" bool func_001F9810(void* p, void* u, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x40C698AF, &v, 1);
    return func_001F9D18(p, v) != 0;
}

extern "C" s32 func_001F9860(S1F9860* p, void* u, void* a, void* b) {
    s32 v = 0;
    func_0027D870(a, 0x7135152B, &v, 1);
    s32 k = v;
    S1F9860_I it;
    S1F9860_I e;
    it.unk4 = p->unk48.unk4;
    e.unk4 = &p->unk48;
    while (it.unk4 != e.unk4) {
        it.unk4->unk8->v4(k, a, b);
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk48;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F79D8", func_001F9920);
