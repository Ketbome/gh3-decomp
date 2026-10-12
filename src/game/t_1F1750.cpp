// cflags: -funroll-loops
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct S1F1780_M {
    char pad0[0x50];
    u64 b0 : 1;
    u64 b1 : 1;
    u64 b2 : 1;
    bool B1() { return b1; }
    bool B2() { return b2; }
};

struct S1F1750_M {
    char pad0[0x20];
    TI128 unk20;
    char pad30[0x4];
    s32 unk34;
};

struct S1F1750 {
    char pad0[0x14];
    u32 unk14;
    char pad18[0x1F8];
    S1F1750_M* unk210;
    char pad214[0x1C];
    TI128 unk230;
    TI128 unk240;
    s32 unk250;
    f32 unk254;
    char pad258[0x98];
    s32 unk2F0;
    void Clear14(u32 m) { unk14 &= ~m; }
};

struct S1F1750_V {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3(void*);
};

struct S1F2128 {
    f32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
};

struct Col1F1 {
    u8 r, g, b, a;
};

struct S1F2368_R {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(const Col1F1& c);
};

struct Pair1F1 {
    TI128 a;
    TI128 b;
};

struct S1F36D0 {
    char pad0[0x1C];
    void* unk1C;
    Pair1F1 unk20;
    Pair1F1 unk40;
};

struct S1F1D68 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual s32 v12(int);
};

struct S1F1D68_A {
    s32 unk0;
    s32 unk4;
    s32 (S1F1D68::*unk8)(int, int);
};

struct S1F1F70 {
    S1F2128 e[6];
    s32 unk90;
};

struct S1F34A0_C {
    char pad0[0x8];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
};

struct S1F34A0 {
    char pad0[0xC];
    S1F34A0_C* unkC;
    char pad10[0xC];
    s32 unk1C;
    char pad20[0x4];
    u32 unk24;
    u32 unk28;
    void* unk2C;
};

struct Arr1F1 {
    s32 unk0;
    u32 count;
    void** data;
    void* Get(u32 i) { return count == 1 ? (void*)data : data[i]; }
    u32 GetSize() { return count; }
};

struct S1F3720_C {
    char pad0[0x2C];
    s32 unk2C;
};

struct S1F3720_B {
    char pad0[0xC];
    S1F3720_C* unkC;
    char pad10[0x8];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(int);
};

struct S1F3720 : S1F3720_B {
    s32 unk1C;
    char pad20[0x98];
    f32 unkB8;
};

struct S1F1E10_B {
    char pad0[0xC];
    S1F3720_C* unkC;
    char pad10[0x8];
    virtual void v1(); virtual void v2();
};

struct S1F1E10 : S1F1E10_B {
    char pad1C[0x1F4];
    S1F1750_M* unk210;
};

extern "C" {
void func_0027C448(void*, u32, s32);
bool func_0027DF00(void*, u32);
s32 func_0027D1F8(void*, u32, s32*, int);
void func_001F1CE8(void*, int, int);
void func_001F1CF0(void*);
void func_001F1CF8(void*, bool);
void func_001F1D00(void*, bool);
void func_001EF6D0(void*);
void func_00162178(void*);
void func_001F2468(int, int);
void* func_00113D20(u32);
char* func_001F3268(char*);
extern char D_0034ED60[];
void func_001D0F90(void*);
void func_001563B0(void*);
void func_001F2108(S1F1750*);
void* func_00155668(void*);
void func_00154608(void*);
void func_001F3C70(void*, void*);
void* func_001D1CF8(void*, u32);
void func_00207D70(void*);
void func_00161AC8(void*);
void func_001D0F68(void*);
bool func_0027D870(void*, u32, s32*, int);
s32 func_00275570();
extern s32 D_00370F40[] __attribute__((section(".sdata")));
S1F2368_R* func_001618A0(void*, int);
s32 func_0027D268(void*, u32, f32*, int);
f32 func_001F2178(S1F2128*);
void func_001F2128(S1F2128*, f32, s32, f32, f32, s32, s32, s32);
s32 func_001D0680(void*);
s32 func_0027D400(void*, u32, void**, int);
Arr1F1* func_002764E8(u32, int);
s32 func_0027CC30(void*, int, int, f32*);
void func_0027F1E0(void*, int, int);
void func_001F3C08(void*, f32, s32);
void func_001EF5E8(void*);
void* func_002763E0(u32, int);
s32 func_0027D470(void*, s32, Arr1F1**, int);
void* func_001D8618(void*, void*);
extern void* D_0036D3B0;
void func_001619B0(void*, void*);
}

extern "C" s32 func_001F1750(S1F1750* p, void* a, void** b) {
    func_0027C448(b[8], 0xC3F4169A, p->unk210->unk34);
    return 1;
}

extern "C" bool func_001F1780(S1F1750* p) {
    S1F1780_M* m = (S1F1780_M*)p->unk210;
    return m->B1() && !m->B2();
}

extern "C" s32 func_001F17B8(void* p) {
    func_001F1CE8(p, 1, 0);
    return 1;
}

extern "C" s32 func_001F17E0(void* p) {
    func_001F1CF0(p);
    return 1;
}

extern "C" s32 func_001F1800(void* p, void* a) {
    func_001F1CF8(p, func_0027DF00(a, 0xF649D637));
    return 1;
}

extern "C" s32 func_001F1840(S1F1750* p, void* a) {
    if (p->unk210) {
        s32 v;
        func_0027D1F8(a, 0x7F8C98FE, &v, 0);
    }
    return 1;
}

extern "C" s32 func_001F1878(void* p, void* a) {
    func_001F1D00(p, func_0027DF00(a, 0xF649D637));
    return 1;
}

extern "C" s32 func_001F18B8(void* p) {
    func_001EF6D0(p);
    return 1;
}

extern "C" s32 func_001F18D8(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x83418A6A, &v, 0);
    s32 k = 0xC4E78E22;
    func_0027D870(a, 0xE7308C1F, &k, 0);
    s32 m = 0x179A6A85;
    func_0027D870(a, 0x5FDC2EDB, &m, 0);
    void* s = 0;
    f32 r = 0.0f;
    f32 g = 0.0f;
    f32 b = 0.0f;
    f32 al = 1.0f;
    if (func_0027D400(a, 0x99A9B716, &s, 1)) {
        func_0027D268(s, 0x93F60062, &r, 0);
        func_0027D268(s, 0xFE2BE489, &g, 0);
        func_0027D268(s, 0x8E411006, &b, 0);
        func_0027D268(s, 0x174841BC, &al, 0);
    }
    func_0027D268(a, 0x2F1FC695, &al, 0);
    return 1;
}

extern "C" s32 func_001F1A20(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x83418A6A, &v, 1);
    s32 k = 0xC4E78E22;
    func_0027D870(a, 0xE7308C1F, &k, 0);
    s32 m = 0x179A6A85;
    func_0027D870(a, 0x5FDC2EDB, &m, 0);
    return 0;
}

extern "C" s32 func_001F1AA8(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x83418A6A, &v, 0);
    s32 k = 0xC4E78E22;
    func_0027D870(a, 0xE7308C1F, &k, 0);
    s32 m = 0x179A6A85;
    func_0027D870(a, 0x5FDC2EDB, &m, 0);
    f32 f = 1.0f;
    func_0027D268(a, 0, &f, 0);
    return 0;
}

extern "C" s32 func_001F1B50(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x83418A6A, &v, 0);
    s32 k = 0xC4E78E22;
    func_0027D870(a, 0xE7308C1F, &k, 0);
    return 1;
}

extern "C" void func_001F1BB8(char* p, void* a) {
    f32 f;
    func_0027D268(a, 0, &f, 1);
    *(f32*)(p + 0x2BC) = 0.5f;
    *(f32*)(p + 0x2B8) = f * f;
    func_0027D268(a, 0xF99D5A06, (f32*)(p + 0x2BC), 0);
    *(s32*)(p + 0x2B0) = 1;
    *(f32*)(p + 0x2B4) = -1.0f;
    *(s32*)(p + 0x2C4) = 0;
    *(s32*)(p + 0x2C8) = 0;
}

extern "C" s32 func_001F1C48(char* p, void* a) {
    if (func_0027DF00(a, 0x00F08F03)) {
        *(s32*)(p + 0x258) = 1;
    } else {
        *(s32*)(p + 0x258) = 0;
    }
    if (func_0027DF00(a, 0x77F7BF95)) {
        *(s32*)(p + 0x25C) = 1;
    } else {
        *(s32*)(p + 0x25C) = 0;
    }
    if (func_0027DF00(a, 0xEEFEEE2F)) {
        *(s32*)(p + 0x260) = 1;
    } else {
        *(s32*)(p + 0x260) = 0;
    }
    return 1;
}

extern "C" void func_001F1CE8(void*, int, int) {
}

extern "C" void func_001F1CF0(void*) {
}

extern "C" void func_001F1CF8(void*, bool) {
}

extern "C" void func_001F1D00(void*, bool) {
}

extern "C" void func_001F1D08(S1F1750* p) {
    if (p->unk210) {
        func_00162178(p->unk210);
    }
}

extern "C" s32 func_001F1D30(S1F1750_V* p) {
    p->v2();
    return 1;
}

extern "C" s32 func_001F1D60() {
    return 2;
}

extern "C" s32 func_001F1D68(S1F1D68* p, S1F1D68_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001F1E08(void) {
}

extern "C" void func_001F1E10(S1F1E10* p) {
    p->v2();
    if (p->unk210 && *(void**)((char*)p->unk210 + 0x30)) {
        func_001EF5E8(p);
    }
    void* s = func_002763E0(0x18F3427B, 1);
    Arr1F1* arr;
    if (func_0027D470(s, p->unkC->unk2C, &arr, 0)) {
        for (u32 i = 0; i < arr->GetSize(); i++) {
            void* r = func_001D8618(D_0036D3B0, arr->Get(i));
            if (r && p->unk210) {
                func_001619B0(p->unk210, r);
                return;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F1F18);

extern "C" void func_001F1F20(char* p) {
    func_001F2108((S1F1750*)p);
    func_001F2108((S1F1750*)(p + 0x18));
    func_001F2108((S1F1750*)(p + 0x30));
    func_001F2108((S1F1750*)(p + 0x48));
    func_001F2108((S1F1750*)(p + 0x60));
    func_001F2108((S1F1750*)(p + 0x78));
    *(s32*)(p + 0x90) = 0;
}

extern "C" void func_001F1F70(S1F1F70* p, f32 x, s32 a, f32 y, f32 z, s32 b, s32 c, s32 d) {
    S1F2128* e = p->e;
    for (s32 i = 0; i < 6; i++, e++) {
        if (!e->b0) {
            func_001F2128(e, x, a, y, z, b, c, d);
            p->unk90 = 1;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F2000);

extern "C" void func_001F2108(S1F1750* p) {
    p->Clear14(1);
    p->Clear14(2);
}

extern "C" void func_001F2128(S1F2128* p, f32 x, s32 a, f32 y, f32 z, s32 b, s32 c, s32 d) {
    p->unk0 = x;
    p->unk4 = a;
    p->unk8 = y;
    p->unkC = z;
    p->unk10 = b;
    p->b0 = 1;
    p->b1 = c;
    p->b2 = d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F2178);

extern "C" s32 func_001F2360(S1F1750* p) {
    return p->unk2F0;
}

extern "C" void func_001F2368(S1F1750* p, Col1F1* a) {
    if (*(s32*)((char*)p + 0x2F8)) {
        S1F2368_R* r = func_001618A0(p->unk210, 0);
        Col1F1 c = *a;
        Col1F1 d = c;
        r->v10(d);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F23D8);

extern "C" void func_001F23E8(S1F1750* p) {
    void* r = func_001D1CF8(*(void**)((char*)p + 0xC), 0x8A897DD2);
    if (r) {
        func_00207D70(r);
    }
    if (p->unk210) {
        func_00161AC8(p->unk210);
    }
}

extern "C" void func_001F2440(S1F1750* p, TI128 v, f32 f) {
    p->unk240 = v;
    p->unk254 = f;
    p->unk250 = 0;
    p->unk230 = p->unk210->unk20;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F2460);

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F2468);

extern "C" void func_001F3220() {
    func_001F2468(1, 0xFFFF);
}

extern "C" void* func_001F3240() {
    return func_001F3268((char*)func_00113D20(0x30));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F3268);

extern "C" void func_001F32C8(char* p) {
    *(char**)(p + 0x18) = D_0034ED60;
    func_001D0F90(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F32F0);

extern "C" void func_001F3478(S1F1750_V* p, void* a) {
    p->v3(a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F34A0);

extern "C" s32 func_001F3560(char* p, u32 key) {
    switch (key) {
    case 0xF7A35A2C:
        *(s32*)(p + 0x1C) = 1;
        *(s32*)(p + 0x24) = D_00370F40[0] + func_00275570();
        return 1;
    case 0x674C9C2D:
        *(s32*)(p + 0x1C) = 0;
        return 1;
    default:
        return 2;
    }
}

extern "C" void func_001F35C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F1750", func_001F35D0);

extern "C" void func_001F36A0(char* p) {
    func_001563B0(*(void**)(p + 0x1C));
    *(void**)(p + 0x1C) = 0;
}

extern "C" void func_001F36D0(S1F36D0* p, void* a) {
    p->unk1C = func_00155668(a);
    func_00154608(p->unk1C);
    func_001F3C70(&p->unk20, p->unk1C);
    p->unk40 = p->unk20;
}

extern "C" void func_001F3720(S1F3720* p) {
    Arr1F1* arr = func_002764E8(0x7AD2ACEF, 1);
    for (u32 i = 0; i < arr->GetSize(); i++) {
        void* e = arr->Get(i);
        s32 v;
        func_0027D870(e, 0, &v, 1);
        if (v == p->unkC->unk2C) {
            f32 t;
            f32 f;
            if (func_0027CC30(e, 0, 2, &t)) {
                f = t;
            } else {
                func_0027F1E0(e, 0, 1);
                f = 0.0f;
            }
            p->unkB8 = f;
            func_001F3C08((char*)p + 0x40, f, p->unk1C);
            break;
        }
    }
    p->v8(1);
}
