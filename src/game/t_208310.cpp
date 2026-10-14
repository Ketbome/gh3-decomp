#include "common.h"

struct VEntry208 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S208b {
    char pad0[0x20];
    int unk20;
    char pad24[0xAC];
    f32 unkD0;
};

struct S208 {
    char pad0[0x18];
    VEntry208* unk18;
    S208b* unk1C;
};

extern "C" {
void func_002082B0(int, int);
void func_00208778(int, int);
void* operator_new(u32 size);
void* func_00208388(void*);
void* func_00208910(void*);
void func_00276D68(u32, void*, int);
extern u8 D_0038FD28[];
extern u8 D_0038FD68[];
void func_0027C1F8(int, u32, f32);
void* func_001D0F68(void*);
void func_001D0F90(void*, int);
extern u8 D_00350800[];
void func_0015D750(S208b*);
S208b* func_00123200(void*);
int func_0027D268(int, u32, f32*, int);
void func_001234B0(S208b*);
int func_001D1CF8(void*, u32);
void func_0020BF60(void*, void*, int);
void func_00212778(void*, void*);
extern char* D_0036D3B0;
void func_001CED20(S208b*, int);
int func_0027D1F8(int, u32, int*, int);
}

struct VE208 {
    s16 delta;
    s16 unk2;
    void (*fn)(void*, void*, int);
};

struct S208_V {
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

struct S208_A {
    s32 unk0;
    s32 unk4;
    s32 (S208_V::*unk8)(int, int);
};

typedef unsigned int u128_208 __attribute__((mode(TI)));

struct M208 {
    u128_208 r[4];
    M208& operator=(const M208& o) {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct C208 {
    u8 r, g, b, a;
    C208(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" void func_00208310(void) {
    func_002082B0(1, 0xFFFF);
}

extern "C" void* func_00208330(void) {
    return func_00208388(operator_new(0x20));
}

extern "C" void func_00208358(void) {
    func_00276D68(0xC4E311FA, D_0038FD28, 0x10);
}

extern "C" void* func_00208388(void* self) {
    S208* p = (S208*)self;
    func_001D0F68(p);
    C208 c(0x80, 0, 0x80, 0xFF);
    p->unk18 = (VEntry208*)D_00350800;
    *(u32*)((char*)p + 4) = 0xC4E311FA;
    p->unk1C = func_00123200(operator_new(0x100));
    return p;
}

extern "C" void func_002083F8(S208* p, int flags) {
    p->unk18 = (VEntry208*)D_00350800;
    func_0015D750(p->unk1C);
    func_001D0F90(p, flags);
}

extern "C" void func_00208448(char* p, int a) {
    char* d = D_0036D3B0;
    VE208* vt = *(VE208**)(d + 0x2C);
    vt[5].fn(d + vt[5].delta, *(void**)(p + 0xC), -1000);
    char* o = *(char**)(p + 0x1C);
    VE208* vo = *(VE208**)(o + 0x8);
    ((void (*)(void*, int))vo[2].fn)(o + vo[2].delta, a);
    func_001CED20(*(S208b**)(p + 0x1C), *(int*)(*(char**)(p + 0xC) + 0x2C));
}

extern "C" void func_002084C8(S208* self, int a) {
    VEntry208* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_002084F0(char* p) {
    *(u128_208*)(*(char**)(p + 0x1C) + 0x80) = *(u128_208*)(*(char**)(p + 0xC) + 0x80);
    *(M208*)(*(char**)(p + 0x1C) + 0x90) = *(M208*)(*(char**)(p + 0xC) + 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208538);

extern "C" int func_002085C0(S208* self, int a, S208b* b) {
    func_0027C1F8(b->unk20, 0x3770EBFC, self->unk1C->unkD0);
    return 1;
}

extern "C" int func_002085F0(S208* p, int s) {
    f32 v;
    func_0027D268(s, 0x3770EBFC, &v, 1);
    S208b* b = p->unk1C;
    b->unkD0 = v;
    func_001234B0(b);
    return 1;
}

extern "C" int func_00208640(char* p, int s) {
    int a = 1;
    int b = 0;
    if (func_0027D1F8(s, 0x864D25B7, &a, 0)) func_0027D1F8(s, 0x4071147A, &b, 1);
    *(int*)(*(char**)(p + 0x1C) + 0xEC) = a;
    *(int*)(*(char**)(p + 0x1C) + 0xF0) = b;
    return 1;
}

extern "C" int func_002086C8(void) {
    return 2;
}

extern "C" s32 func_002086D0(S208_V* p, S208_A* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" void func_00208770(void) {
}

struct V8778 {
    int a;
    int b;
};

struct E8778 {
    u32 key;
    u32 type;
    V8778 v;
};

extern E8778 T8778[] __asm__("D_0038FD28");
extern V8778 S8778_0[] __asm__("D_0036EBC8");
extern V8778 S8778_1[] __asm__("D_0036EBD0");
extern V8778 S8778_2[] __asm__("D_0036EBD8");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_00208778(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E8778* e = T8778;
        V8778 t;
        e->key = 0x91224113;
        t = *S8778_0;
        e->type = 0xC4E311FA;
        e->v = t;
        e++;
        e->key = 0x2B3F9CE;
        t = *S8778_1;
        e->type = 0xC4E311FA;
        e->v = t;
        e++;
        e->key = 0xE8BC699B;
        t = *S8778_2;
        e->type = 0xC4E311FA;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0xC4E311FA;
        e->v = t;
    }
}

extern "C" void func_00208898(void) {
    func_00208778(1, 0xFFFF);
}

extern "C" void* func_002088B8(void) {
    return func_00208910(operator_new(0x6D0));
}

extern "C" void func_002088E0(void) {
    func_00276D68(0xEA0EEAFB, D_0038FD68, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208910);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208C50);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208DE0);

extern "C" void func_00208F80(S208* self, int a) {
    VEntry208* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00209008);
