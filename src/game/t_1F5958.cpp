// cflags: -funroll-loops
#include "common.h"

struct S1F5958_V {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int);
};

typedef int TI128 __attribute__((mode(TI)));

static inline f32 GetX(TI128 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}

static inline f32 GetY(TI128 q) {
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(f) : "0"(q));
    return f;
}

static inline f32 GetZ(TI128 q) {
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(f) : "0"(q));
    return f;
}

static inline TI128 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    TI128 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct S1F5F08_T {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" 

struct S1F5DD0 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual s32 v12(int);
};

struct S1F5DD0_A {
    s32 unk0;
    s32 unk4;
    s32 (S1F5DD0::*unk8)(int, int);
};

struct Arr1F5 {
    s32 unk0;
    u32 count;
    void** data;
    void* Get(u32 i) { return count == 1 ? (void*)data : data[i]; }
    u32 GetSize() { return count; }
};

extern "C" {
void func_001F5C30(int, int);
void func_0017B678(void*);
extern char D_0034F160[];
void func_001D0F90(void*, void*);
extern char D_0038F260[];
void func_00276D68(u32, void*, int);
void* func_001D1CF8(void*, u32);
s32 func_00133F60(void*);
void func_0027C448(void*, u32, s32);
void func_001D0F68(void*);
extern char D_0034F440[];
void func_001316B8(void*, int);
void func_0017B528(void*, s32);
void func_0013D1B8(void*, int);
void Heap_Free(s32, void*);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
bool func_0027D870(void*, u32, s32*, int);
s32 func_0027D1F8(void*, u32, s32*, int);
void func_00131FC0(void*, s32, bool);
extern s32 D_0036F658;
void func_0022B0D0(void*, s32, s32, int);
void func_001342E8(S1F5F08_T*, s32);
void* Heap_Alloc(s32, s32, s32, s32);
void* func_00131118(void*, S1F5F08_T*);
void func_00134340(void*);
void func_00131728(void*, S1F5F08_T*);
void* func_0012D208(void*);
s32 func_001317D0(void*, s32);
void func_0027C448(void*, u32, s32);
s32 func_001F7AC8(void*, s32, TI128*);
void func_0027C1F8(void*, u32, f32);
s32 func_0027D470(void*, u32, Arr1F5**, int);
void func_0017B550(void*, s32);
s32 func_001317D0_p(void*, void*) __asm__("func_001317D0");
}

struct T1F5F08 : S1F5F08_T {
    T1F5F08(s32 x) {
        unk0 = 0;
        unk4 = 0;
        unk8 = 0;
        func_001342E8(this, x);
    }
};

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5958);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5C30);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5CF8);

extern "C" void func_001F5D28(char* p, int flags) {
    func_0013D1B8(p + 0x144, 2);
    char* v = p + 0x14;
    if (*(void**)(v + 4)) {
        Heap_Free(D_00368A38[0], *(void**)(v + 4));
        *(s32*)(v + 0x4) = 0;
        *(s32*)(v + 0x8) = 0;
        *(s32*)(v + 0xC) = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001F5DA0(char* p, void* a) {
    *(char**)(p + 0x18) = D_0034F160;
    func_001D0F90(p, a);
}

extern "C" s32 func_001F5DC8() {
    return 2;
}

extern "C" s32 func_001F5DD0(S1F5DD0* p, S1F5DD0_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001F5E70(void) {
}

extern "C" void func_001F5E78(void) {
}

extern "C" void func_001F5E80() {
    func_001F5C30(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5EA0);

extern "C" void func_001F5ED8() {
    func_00276D68(0x222756D5, D_0038F260, 0x10);
}

extern "C" void func_001F5F08(char* p, s32 a) {
    s32 buf[4];
    func_0022B0D0(buf, D_0036F658, a, 1);
    T1F5F08 t(buf[0]);
    *(void**)(p + 0x1C) = func_00131118(Heap_Alloc(D_00368A38[0], 0x234, 1, 0), &t);
    func_00134340(buf);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F5F88);

extern "C" void func_001F5FE0(char* p, void* a) {
    *(char**)(p + 0x18) = D_0034F440;
    if (*(void**)(p + 0x1C)) {
        func_001316B8(*(void**)(p + 0x1C), 3);
        *(void**)(p + 0x1C) = 0;
    }
    func_001D0F90(p, a);
}

extern "C" {
extern f32 D_0032C6D0[];
extern s32 D_0036D3B0;
s32 func_002764E8(u32, s32);
f32 func_0027EFA0(s32, u32);
s32 func_001D8618(s32, s32);
bool func_0027DF00(void*, u32);
void* func_001313E8(void*, s32);
}

extern "C" void func_001F6038(char* p, void* a) {
    s32 sp4 = 0;
    s32 sp0 = 0;
    if (D_0032C6D0[0] == 0.0f) {
        s32 h = func_002764E8(0xD7405ABF, 0);
        u32 i;
        for (i = 0; i < 11; i++) {
            f32 v = func_0027EFA0(h, i);
            D_0032C6D0[i] = v * v;
        }
    }
    *(s32*)(p + 0x24) = 10;
    func_0027D1F8(a, 0xBE22694E, (s32*)(p + 0x24), 0);
    *(s32*)(p + 0x28) = 0;
    func_0027D1F8(a, 0x99990E7F, (s32*)(p + 0x28), 0);
    if (func_0027D870(a, 0xA81F615C, &sp0, 0)) {
        char* q = (char*)func_001D1CF8((void*)func_001D8618(D_0036D3B0, sp0), 0x222756D5);
        *(void**)(p + 0x1C) = func_001313E8(Heap_Alloc(D_00368A38[0], 0x234, 1, 0), *(s32*)(q + 0x1C));
    } else {
        func_0027D870(a, 0x09794932, &sp4, 1);
        func_001F5F08(p, sp4);
        s32 r = -1;
        if (func_0027DF00(a, 0x7594231C)) {
            s32* t = *(s32**)(p + 0x1C);
            *t &= 0xFDFFFFFF;
        }
        *(s32*)(p + 0x2C) = r;
    }
}

extern "C" void func_001F6268(char* p) {
    *(void**)(p + 0x20) = func_001D1CF8(*(void**)(p + 0xC), 0xCE0CA665);
}

extern "C" void func_001F62A0(S1F5958_V* p) {
    p->v8(1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F62D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F6440);

extern "C" s32 func_001F64B0(char* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0xCAB94088, &v, 1);
    s32 w;
    func_0027D1F8(a, 0xB4E103FD, &w, 1);
    func_00131FC0(*(void**)(p + 0x1C), v, w != 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F6528);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F65B0);

extern "C" bool func_001F6778(char* p, void* a, void** b) {
    TI128 v;
    TI128* pv = &v;
    *pv = MakeVec(0.0f, 0.0f, 0.0f, 1.0f);
    s32 n = 0;
    func_0027D870(a, 0xCAB94088, &n, 1);
    s32 r = func_001F7AC8(p, n, pv);
    func_0027C1F8(b[8], 0x7323E97C, GetX(v));
    func_0027C1F8(b[8], 0x0424D9EA, GetY(v));
    func_0027C1F8(b[8], 0x9D2D8850, GetZ(v));
    return r != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F6848);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F6DA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F6ED8);

extern "C" s32 func_001F6F68(char* p, void* a, void** b) {
    s32 v = 0;
    func_0027D870(a, 0xCAB94088, &v, 1);
    void* s = b[8];
    char* r = (char*)func_0012D208(*(void**)(p + 0x1C));
    s32 i = func_001317D0(*(void**)(p + 0x1C), v);
    func_0027C448(s, 0xF75A763C, (*(s32**)(*(char**)(r + 4) + 0x14))[i]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F7000);

INCLUDE_ASM("asm/nonmatchings/game/t_1F5958", func_001F7580);

extern "C" s32 func_001F77E8(char* p, void* a, void** b) {
    void* s = b[8];
    func_0027C448(s, 0x09794932, func_00133F60(*(void**)(p + 0x1C)));
    return 1;
}

extern "C" s32 func_001F7828(char* p, void* a) {
    s32 buf[4];
    s32 v;
    func_0027D870(a, 0x09794932, &v, 1);
    func_0022B0D0(buf, D_0036F658, v, 1);
    T1F5F08 t(buf[0]);
    func_00131728(*(void**)(p + 0x1C), &t);
    func_00134340(buf);
    return 1;
}

extern "C" s32 func_001F78A8(char* p) {
    func_0017B678(*(char**)(p + 0x1C) + 0xC);
    return 1;
}

extern "C" s32 func_001F78D0(char* p, void* a) {
    Arr1F5* arr;
    *(s32*)(p + 0x2C) = -2;
    func_0027D470(a, 0, &arr, 1);
    char* q = *(char**)(p + 0x1C) + 0xC;
    *(s32*)(q + 0x208) = 0;
    for (s32 i = 0; i < *(s32*)(*(char**)(p + 0x1C) + 0x220); i++) {
        func_0017B528(q, i);
    }
    for (u32 j = 0; j < arr->GetSize(); j++) {
        void* o = *(void**)(p + 0x1C);
        func_0017B550(q, func_001317D0_p(o, arr->Get(j)));
    }
    return 1;
}
