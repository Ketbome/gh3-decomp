#include "common.h"

typedef unsigned int u128_21D __attribute__((mode(TI)));

struct M21D {
    u128_21D r[4];
};

struct VEntry21D {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21Db {
    char pad0[0xA0];
    M21D unkA0;
    char padE0[0x20];
    M21D unk100;
};

struct S21D {
    char pad0[0xC];
    S21Db* unkC;
    char pad10[0x8];
    VEntry21D* unk18;
    int unk1C;
    char pad20[0x3C];
    int unk5C;
    S21D* unk60;
};

struct S21F748_V {
    char pad0[8];
    int unk8;
};

struct S21E208 {
    char pad0[0x5C];
    s32 unk5C;
    S21E208* unk60;
};

extern "C" {
void func_00220898(void* p);
void* func_0027AF38(int, u32, int);
void func_0021FB88(int, int, int, int, int, int, int, int, f32, f32);
void func_001D10A0(void*);
void func_0021DC50(int, int);
void func_0021DED8(int, int);
void func_0027AC90(void*);
extern int D_00372E28;
void func_00220110(void*);
void func_00289CF8(int);
void* operator_new(u32 size);
void* func_0021DDB8(void*);
void* func_0021DFB0(void*);
void func_001D0F90(void*, int);
extern u8 D_00351A30[];
void func_00276D68(u32, void*, int);
extern u8 D_00390580[];
void func_002210B8(void*);
int func_00220FE8(int, int, int);
int func_00174CE0(int);
int func_0027DF00(int, u32);
int func_002204D8(void*);
void func_0027C448(int, u32, int);
void func_00289C88(int, int);
void func_0021EBB0(int, int, int, f32);
void func_0021EDB8(int, int, int, f32);
f32 func_00275DE0(u32, int);
int* func_00289C80(int);
int func_0027D870(int, u32, int*, int);
void* func_001D0F68(void*);
extern u8 D_00351D28[];
int func_001D1CF8(void*, u32);
void func_002207F0(void*);
void Heap_Free(void*, void*);
extern void* D_00368A38;
int func_0027D400(int, u32, void*, int);
int func_0027D268(int, u32, void*, int);
int func_0027D1F8(int, u32, void*, int);
void func_0021FEF0(int, void*);
void func_0021E9A8(int, int, int, f32);
int func_001D8618(void*, int);
extern void* D_0036D3B0;
void func_0021EDB8(int, int, int, f32);
f32 func_00275DE0(u32, int);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
void func_0027C0D0(s32 a, u32 k, u32 v);
void func_0027C1F8(s32 a, u32 k, f32 v);
void func_0027C898(s32 a, u32 k, s32 v);
void func_0021E4E8(s32 a, s32 b, s32 c);
void func_00113250(void* p);
struct S21D;
void func_0021E2E0(S21D* p);
}

struct V21D {
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

struct A21D {
    s32 unk0;
    s32 unk4;
    s32 (V21D::*unk8)(int, int);
};

struct C21D {
    u8 r, g, b, a;
    C21D(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DA40);

extern "C" int func_0021DB60(int* p, int a) {
    p[0x13] = func_0027DF00(a, 0x5B6634D4);
    return 1;
}

extern "C" int func_0021DB98(void) {
    return 2;
}

extern "C" s32 func_0021DBA0(V21D* p, A21D* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_0021DC40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DC48);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DC50);

extern "C" void func_0021DD70(void) {
    func_0021DC50(1, 0xFFFF);
}

extern "C" void* func_0021DD90(void) {
    return func_0021DDB8(operator_new(0x1C));
}

extern "C" void* func_0021DDB8(void* self) {
    char* p = (char*)self;
    func_001D0F68(p);
    *(void**)(p + 0x18) = D_00351A30;
    *(u32*)(p + 4) = 0x1BBF844D;
    C21D c(0xFF, 0, 0, 0xFF);
    return p;
}

extern "C" void func_0021DE10(S21D* self, int flag) {
    self->unk18 = (VEntry21D*)D_00351A30;
    func_001D0F90(self, flag);
}

extern "C" void func_0021DE38(void) {
}

extern "C" void func_0021DE40(S21D* self, int a) {
    VEntry21D* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

inline void copy_0021DE68(M21D* d, M21D* s) {
    d->r[0] = s->r[0];
    d->r[1] = s->r[1];
    d->r[2] = s->r[2];
    d->r[3] = s->r[3];
}

extern "C" void func_0021DE68(S21D* self) {
    S21Db* p = self->unkC;
    copy_0021DE68(&p->unk100, &p->unkA0);
}

extern "C" int func_0021DE98(void) {
    return 2;
}

extern "C" void func_0021DEA0(void* self) {
    func_001D10A0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DEC0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DED8);

extern "C" void func_0021DF38(void) {
    func_0021DED8(1, 0xFFFF);
}

extern "C" void* func_0021DF58(void) {
    return func_0021DFB0(operator_new(0x70));
}

extern "C" void func_0021DF80(void) {
    func_00276D68(0x8536DBA5, D_00390580, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E038);

extern "C" void func_0021E0C8(char* p, int s) {
    int v;
    func_0027D870(s, 0x5B8C6DC2, (int*)(p + 0x30), 0);
    func_0027D870(s, 0xD88DEEAF, (int*)(p + 0x2C), 0);
    func_0027D1F8(s, 0x1DC13EB1, &v, 0);
}

extern "C" void func_0021E140(char* p) {
    *(int*)(p + 0x3C) = func_001D1CF8(*(void**)(p + 0xC), 0x222756D5);
    *(int*)(p + 0x40) = func_001D1CF8(*(void**)(p + 0xC), 0x286A8D26);
    *(int*)(p + 0x44) = func_001D1CF8(*(void**)(p + 0xC), 0xCE0CA665);
}

extern "C" void func_0021E1A0(char* p) {
    switch (*(u32*)(p + 0x5C)) {
    case 0:
        break;
    case 1:
    case 2:
        func_0021E2E0((S21D*)p);
        break;
    case 3:
    case 4:
        func_0021E2E0(*(S21D**)(p + 0x60));
        break;
    }
    func_002210B8(p);
}

extern "C" void func_0021E208(S21E208* p) {
    if (p->unk5C == 1) {
        p->unk5C = 2;
    }
    if (p->unk5C == 3) {
        p->unk5C = 4;
    }
    switch (p->unk5C) {
    case 0:
        func_00220898(p);
        break;
    case 2:
        func_00220898(p);
        if (p->unk60->unk5C == 4) {
            func_00220898(p->unk60);
        }
        break;
    case 4:
        if (p->unk60->unk5C != 2) {
            func_00220898(p);
        }
        break;
    }
}

extern "C" void func_0021E2E0(S21D* self) {
    self->unk60->unk5C = 0;
    self->unk60->unk60 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
}

extern "C" s32 func_0021E300(V21D* p, A21D* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_0021E3A0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E3A8);

extern "C" int func_0021E498(S21D* self) {
    if (!self->unk1C) {
        return 0;
    }
    func_002210B8(self);
    return 1;
}

GP_DATA(D_00372E28);
extern "C" void func_0021E4C8(void) {
    func_0027AC90(&D_00372E28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E4E8);

extern "C" int func_0021E658(int* p, int s) {
    int v = 1;
    if (func_0027DF00(s, 0xFF22F197)) v = p[8] ^ 1;
    if (v) func_002207F0(p);
    return v != 0;
}

extern "C" int func_0021E6B8(S21D* self) {
    VEntry21D* e = &self->unk18[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    return 1;
}

extern "C" int func_0021E6E8(S21D* p, int s) {
    int h;
    func_0027D870(s, 0x57525413, &h, 1);
    ((int*)p)[0x19] = func_001D8618(D_0036D3B0, h);
    VEntry21D* e = (VEntry21D*)((char*)p->unk18 + 0x40);
    ((void (*)(void*, int))e->fn)((char*)p + e->delta, 0);
    return 1;
}

extern "C" int func_0021E750(int* p, int a) {
    p[8] = func_0027DF00(a, 0xD443A2BC) ^ 1;
    return 1;
}

extern "C" int func_0021E790(void* self) {
    func_00220110(self);
    return 1;
}

extern "C" int func_0021E7B0(void* a, int b, int* c) {
    int t = c[8];
    func_0027C448(t, 0xEAE64B47, func_002204D8(a));
    return 1;
}

extern "C" int func_0021E7F0(void) {
    return 1;
}

extern "C" int func_0021E7F8(int a, int b) {
    int v;
    func_0027D870(b, 0x40C698AF, &v, 1);
    return func_00220FE8(a, v, 1) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E848);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E8C8);

extern "C" int func_0021E970(int a, int b) {
    int r = func_00220FE8(a, b, 1);
    if (r == 0) {
        return 1;
    }
    return func_00174CE0(r);
}

extern "C" void func_0021E9A8(s32 a, s32 b, s32 c, f32 f) {
    if (func_00220FE8(a, 0x55772C6E, 1) != 0) {
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xB990D003, 0x55772C6E);
        func_0027C448(t, 0x7135152B, 0x167F93A5);
        s32 u = func_0027AA70(func_001287F0(8, 1));
        func_0027C0D0(u, 0x48C1A123, 0x2AB836C4);
        func_0027C1F8(u, 0xBF237659, f);
        s32 w = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(w, 0x8D2FB72E, b);
        func_0027C898(u, 0x7031F10C, w);
        func_0027C898(t, 0x7031F10C, u);
        func_0021E4E8(a, t, c);
        if (t != 0) {
            func_0027AC90((void*)t);
            func_00113250((void*)t);
        }
    }
}

extern "C" int func_0021EB20(int p, int s, int c) {
    f32 f = 0.2f;
    int v;
    func_0027D268(s, 0xBF237659, &f, 0);
    func_0027D870(s, 0x98549BA4, &v, 1);
    func_0021E9A8(p, v, c, f);
    return 1;
}

extern "C" void func_0021EBB0(s32 a, s32 b, s32 c, f32 f) {
    if (func_00220FE8(a, 0x10CEC1FB, 1) != 0) {
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xB990D003, 0x10CEC1FB);
        func_0027C448(t, 0x7135152B, 0x167F93A5);
        s32 u = func_0027AA70(func_001287F0(8, 1));
        func_0027C0D0(u, 0x48C1A123, 0xDDF602CA);
        func_0027C1F8(u, 0xBF237659, f);
        s32 w = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(w, 0x2CACE293, b);
        func_0027C898(u, 0x7031F10C, w);
        func_0027C898(t, 0x7031F10C, u);
        func_0021E4E8(a, t, c);
        if (t != 0) {
            func_0027AC90((void*)t);
            func_00113250((void*)t);
        }
    }
}

extern "C" int func_0021ED28(int p, int s, int c) {
    f32 f = 0.2f;
    int v;
    func_0027D268(s, 0xBF237659, &f, 0);
    func_0027D870(s, 0x98549BA4, &v, 1);
    func_0021EBB0(p, v, c, f);
    return 1;
}

extern "C" void func_0021EDB8(s32 a, s32 b, s32 c, f32 f) {
    if (func_00220FE8(a, 0xE38C8A59, 1) != 0) {
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xB990D003, 0xE38C8A59);
        func_0027C448(t, 0x7135152B, 0x167F93A5);
        s32 u = func_0027AA70(func_001287F0(8, 1));
        func_0027C0D0(u, 0x48C1A123, 0xEF289149);
        func_0027C1F8(u, 0xBF237659, f);
        s32 w = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(w, 0x6D6B4A5A, b);
        func_0027C898(u, 0x7031F10C, w);
        func_0027C898(t, 0x7031F10C, u);
        func_0021E4E8(a, t, c);
        if (t != 0) {
            func_0027AC90((void*)t);
            func_00113250((void*)t);
        }
    }
}

extern "C" int func_0021EF30(int p, int s, int c) {
    f32 f = func_00275DE0(0xD70E8D50, 1);
    int v;
    func_0027D268(s, 0xBF237659, &f, 0);
    func_0027D870(s, 0x98549BA4, &v, 1);
    func_0021EDB8(p, v, c, f);
    return 1;
}

extern "C" int func_0021EFC8(void* p, int s) {
    int v = 0x9D8EED9C;
    func_0027D870(s, 0x952F21E5, &v, 0);
    return func_0021E970((int)p, v) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F020);

extern "C" int func_0021F248(int p, int a, int s) {
    if (func_0021E970(p, 0xE4F96729)) {
        int v;
        func_0027D870(*func_00289C80(s), 0x1DCC8FF2, &v, 1);
        func_0021E9A8(p, v, s, 0.2f);
        return 1;
    }
    return 0;
}

extern "C" int func_0021F2C8(void* self, int a, int b) {
    func_00289CF8(b);
    return 1;
}

extern "C" int func_0021F2E8(int a, int b, int c) {
    func_00289C88(c, 0x14);
    func_00289C80(c)[4] = 0;
    return 1;
}

extern "C" int func_0021F328(void* self, int a, int b) {
    func_00289CF8(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F348);

extern "C" int func_0021F748(char* p, int s, int d) {
    int sp0;
    int sp4;
    f32 sp8;
    f32 spC;
    int sp10;
    int sp14;
    sp0 = 0x2457F44D;
    int k = 0x01DFE901;
    func_0027D870(s, 0xB990D003, &sp0, 0);
    sp4 = 0x9D8EED9C;
    func_0027D870(s, 0x9180F777, &sp4, 0);
    S21F748_V* v = (S21F748_V*)func_0027AF38(s, 0x48C1A123, 0);
    if (v) {
        k = v->unk8;
    }
    sp8 = 0.2f;
    func_0027D268(s, 0xBF237659, &sp8, 0);
    spC = 1.0f;
    func_0027D268(s, 0xF0D90109, &spC, 0);
    sp10 = 1;
    func_0027D1F8(s, 0x1A3CDE1B, &sp10, 0);
    sp14 = 0;
    func_0027D870(s, 0x98549BA4, &sp14, 0);
    int c = *(int*)(p + 0xC);
    func_0021FB88(d, c, sp14, sp10 != 0, func_0027DF00(s, 0x4F792E6C), sp4, sp0, k, sp8, spC);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F8D8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021FA28);
