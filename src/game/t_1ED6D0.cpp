#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct Vec {
    f32 x __attribute__((aligned(16)));
    f32 y, z, w;
};

union VecU {
    TI128 q;
    Vec v;
};

struct S1EE6F8_C {
    char pad0[0x154];
    u32 unk154;
};

struct S1EE6F8 {
    char pad0[0xC];
    S1EE6F8_C* unkC;
    char pad10[0x10];
    TI128 unk20;
    char pad30[0x1E0];
    void* unk210;
    s32 unk214;
    s32 unk218;
    char pad21C[0x4];
    TI128 unk220;
    char pad230[0x10];
    TI128 unk240;
    char pad250[0x4];
    s32 unk254;
    char pad258[0xC];
    s32 unk264;
    char pad268[0x70];
    f32 unk2D8[4];
    s32 unk2E8;
    char pad2EC[0xC];
    s32 unk2F8;
};

struct S1EF338 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int);
};

struct S1ED858 {
    char pad0[0x18];
    void* unk18;
};

struct S1ED888 {
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

struct S1ED888_A {
    s32 unk0;
    s32 unk4;
    s32 (S1ED888::*unk8)(int, int);
};

struct S1EE428_X {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

struct S1EE428_Y {
    char pad0[0x1C];
    s32 unk1C;
};

struct S1EE428_O {
    char pad0[0x80];
};

extern "C" {
extern char D_0034EA28[];
extern char D_0038EE40[];
void* func_00113D20(u32 size);
void func_00161CC8(void*);
void func_001F1E10(void*);
TI128 func_001620D8(void*);
void func_001E2B90(void*, int);
void func_001EDA50(void*);
void func_001D0F90(void*, int);
void func_00162140(void*, Vec*);
void func_00161FD8(void*);
void func_00276D68(u32, void*, int);
extern char D_0034EBB0[];
TI128 func_001EF570(S1EE6F8*);
void func_001EF548(S1EE6F8*, Vec*);
f32 func_00112CB0(Vec*);
void func_00127830(Vec*, f32);
void* func_001D1CF8(void*, u32);
void func_001F23E8(void*);
void func_0014EB28(void*);
void func_001EF3A8(S1EE6F8*, Vec*, int, int, int);
void* func_0014E1B8(void*);
void* func_00152C60(void*);
void* func_0015F070(void*, int, int);
void func_0015F2F8(void*, int);
void func_0015F4B8(void*, int);
s32 func_00160458(void*, void*, int, int);
extern s32 D_00372DD0[] __attribute__((section(".sdata")));
void func_00134DD0(S1EE428_O*, int);
void func_00134E18(S1EE428_O*, int, void*, s32, s32, int, int);
void func_00207C78(void*, int, int);
s32 func_00275F08(u32, int);
void func_001EEC68(S1EE6F8*);
void func_001CE990(S1EE428_O*, int);
}

extern "C" s32 func_001ED6D0(char* p, int a, int b) {
    func_001E2B90(p + 0x1C, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001ED6F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001ED720);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001ED7F8);

extern "C" void func_001ED858(S1ED858* p, int a) {
    p->unk18 = D_0034EA28;
    func_001D0F90(p, a);
}

extern "C" s32 func_001ED880() {
    return 2;
}

extern "C" s32 func_001ED888(S1ED888* p, S1ED888_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_001ED928(void) {
}

extern "C" void func_001ED930(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001ED938);

extern "C" void func_001ED960(S1EE6F8* p, void* a, s32* b) {
    void* x = func_0014E1B8(a);
    if (x) {
        void* y = func_00152C60(x);
        if (y) {
            void* z = func_0015F070(y, 1, 0);
            func_0015F2F8(z, 1);
            func_0015F4B8(z, *b);
            func_00160458(p->unk210, z, 0, 1);
            p->unk2F8 = 1;
        }
    }
}

extern "C" void func_001ED9F8() {
    func_001EDA50(func_00113D20(0x300));
}

extern "C" void func_001EDA20() {
    func_00276D68(0x286A8D26, D_0038EE40, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EDA50);

extern "C" void func_001EDB00(S1EE6F8* p, int a) {
    ((S1ED858*)p)->unk18 = D_0034EBB0;
    func_001F23E8(p);
    func_0014EB28(p->unk210);
    func_001D0F90(p, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EDB50);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EDD30);

extern "C" void func_001EE428(S1EE6F8* p, int a, int b, int c) {
    S1EE428_O o;
    void* m = p->unk210;
    s32 v1 = 0;
    S1EE428_Y* x = (S1EE428_Y*)func_001D1CF8(p->unkC, 0x222756D5);
    if (x) {
        v1 = x->unk1C;
    }
    s32 v2 = 0;
    S1EE428_X* y = (S1EE428_X*)func_001D1CF8(p->unkC, 0x8A897DD2);
    if (y) {
        v2 = ((S1EE428_Y*)y)->unk1C;
    }
    func_00134DD0(&o, *(int*)((char*)p->unkC + 0x54));
    if (c) {
        func_00134E18(&o, a, m, v1, v2, b, c);
    } else {
        func_00134E18(&o, a, m, v1, v2, b, D_00372DD0[0]);
    }
    if (y) {
        func_00207C78(y, 2, 0);
        y->v4();
    }
    if (p->unkC->unk154 & 0x20) {
        func_001F1E10(p);
    }
    p->unk20 = func_001620D8(m);
    if (func_00275F08(0x74FF5CB4, 0)) {
        func_001EEC68(p);
    }
    func_001CE990(&o, 2);
}

extern "C" void func_001EE5A8(S1EE6F8* p, void* m) {
    p->unk210 = m;
    if (p->unkC->unk154 & 0x20) {
        func_001F1E10(p);
    }
    p->unk20 = func_001620D8(m);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EE600);

extern "C" void func_001EE6F8(S1EE6F8* p) {
    func_00161CC8(p->unk210);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EE718);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EEC68);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EED78);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EEFB0);

extern "C" void func_001EEFE0(void* p) {
    func_001F1E10(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EF000);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EF208);

extern "C" void func_001EF2D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EF2E0);

extern "C" void func_001EF2E8(void) {
}

extern "C" void func_001EF2F0(S1EE6F8* p) {
    p->unk214 = (s32)func_001D1CF8(p->unkC, 0x222756D5);
    p->unk218 = (s32)func_001D1CF8(p->unkC, 0xCE0CA665);
}

extern "C" void func_001EF338(S1EF338* p) {
    p->v9(1);
}

extern "C" void func_001EF368(S1EE6F8* p, s32 i, f32 x) {
    if (p->unk210) {
        s32 n = p->unk2E8;
        if (i > 0 && i <= n) {
            p->unk2D8[i - 1] = x;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EF3A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ED6D0", func_001EF3A8);

extern "C" void func_001EF548(S1EE6F8* p, Vec* v) {
    if (p->unk210) {
        func_00162140(p->unk210, v);
    }
}

extern "C" TI128 func_001EF570(S1EE6F8* p) {
    return func_001620D8(p->unk210);
}

extern "C" void func_001EF590(S1EE6F8* p, f32 x) {
    VecU u;
    u.q = func_001EF570(p);
    func_00127830(&u.v, func_00112CB0(&u.v) * x);
    func_001EF548(p, &u.v);
}

extern "C" void func_001EF5E8(void) {
}

extern "C" void func_001EF5F0(S1EE6F8* p) {
    if (p->unk210) {
        func_00161FD8(p->unk210);
    }
}

extern "C" void func_001EF618(S1EE6F8* p, int a, TI128 v) {
    if (!a) {
        p->unk264 = 1;
    }
    func_001EF3A8(p, (Vec*)&v, 0, 0, 0);
    if (!a) {
        p->unk254 = 0;
        p->unk240 = v;
        p->unk220 = v;
    }
}

extern "C" void func_001EF688(S1EE6F8* p, f32 x) {
    VecU u;
    u.q = func_001EF570(p);
    u.v.w = x;
    func_001EF548(p, &u.v);
}
