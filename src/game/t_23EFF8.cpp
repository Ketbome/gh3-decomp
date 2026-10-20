#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern "C" {
void func_00244B68(void* a, void* b);
f32 func_0010F698(s32 a);
f32 func_0010F6A8(s32 a);
f32 func_0010F6C0(s32 a);
void func_00244C40(void*);
void func_0023F240_2(void*, int) __asm__("func_0023F240");
void func_0023F0D0_2(void*, int) __asm__("func_0023F0D0");
void func_00245220(void*);
void func_00244930(void*);
void func_00246B08(void*);
void func_002456B0(void*);
extern int D_0036FE9C;
void func_0023E678(void);
extern int D_0036FEA0;
void func_0023F310(void*);
extern u8 D_00354E30[];
void func_0023DC88(void*);
extern u8 D_00354D48[];
void* func_0023DC68(void*);
extern u8 D_00354C70[];
void func_0011A470(int);
extern u8 D_00354B88[];
void* func_0023F1A0(void*);
void func_0010F690(void*);
void func_001342B0(void*);
}

GP_DATA(D_0036FE9C);
extern "C" void func_0023EFF8(void) {
    D_0036FE9C = 1;
    func_0023E678();
    D_0036FE9C = 0;
}

GP_DATA(D_0036FEA0);
extern "C" void func_0023F020(void) {
    D_0036FEA0 = 1;
    func_0023E678();
    D_0036FEA0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F048);

extern "C" void* func_0023F098(void** p) {
    func_0023DC68(p);
    p[3] = D_00354E30;
    return p;
}

extern "C" void func_0023F0D0(void** p) {
    p[3] = D_00354E30;
    func_0023DC88(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F1A0);

extern "C" void func_0023F240(void** p) {
    p[3] = D_00354D48;
    func_0023F0D0(p);
}

extern "C" void func_0023F268(int* p, int v) {
    *p = v;
}

extern "C" void func_0023F270(char* p, TI128* q) {
    *(TI128*)(p + 0x50) = *q;
    func_0023F310(p);
}

extern "C" char* func_0023F298(char* p) {
    return p + 0x50;
}

extern "C" void func_0023F2A0(char* p, char* q) {
    *(TI128*)(p + 0x20) = *(TI128*)q;
    *(TI128*)(p + 0x30) = *(TI128*)(q + 0x10);
    *(TI128*)(p + 0x40) = *(TI128*)(q + 0x20);
    func_0023F310(p);
}

extern "C" char* func_0023F2D8(char* p) {
    return p + 0x20;
}

extern "C" void func_0023F2E0(char* p, TI128* q) {
    *(TI128*)(p + 0x10) = *q;
    func_0023F310(p);
}

extern "C" char* func_0023F308(char* p) {
    return p + 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F310);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F408);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F558);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F608);

extern "C" void* func_0023F628(char* p) {
    func_0023F098((void**)p);
    *(int*)(p + 0x10) = 0;
    *(u8**)(p + 0xC) = D_00354C70;
    *(int*)(p + 0x14) = 0;
    return p;
}

extern "C" void func_0023F668(char* p, int flags) {
    *(void**)(p + 0xC) = D_00354C70;
    if (*(u16*)(p + 4) & 0x8000) {
        int t = *(int*)(p + 0x10);
        if (t) {
            func_0011A470(t);
            *(int*)(p + 0x10) = 0;
        }
    }
    func_0023F0D0_2(p, flags);
}

extern "C" int func_0023F6D0(char* p, int a, char* q) {
    *(f32*)(p + 0x14) = *(f32*)(q + 0x3C);
    if (*(u8*)(q + 0xA) != 0) {
        return a;
    }
    *(int*)(p + 0x10) = a;
    return a + *(u16*)(q + 8);
}

struct Tab23F {
    char pad0[0xA];
    u8 unkA;
    char padB;
    char* unkC;
};

struct Own23F {
    char pad0[8];
    Tab23F* unk8;
};

struct T23F7 {
    char pad0[0xA];
    u8 unkA;
    char padB;
    char* unkC;
};

struct O23F7 {
    char pad0[8];
    T23F7* unk8;
};

static inline u16 Get23F7(T23F7& t, s32 i) {
    if (t.unkA != 0) {
        return *(u16*)(t.unkC + i * 8);
    }
    return *(u16*)(t.unkC + i * 10);
}

extern "C" u16 func_0023F700(O23F7* o, s32 i) {
    return Get23F7(*o->unk8, i);
}

static inline u16 Get23F7b(T23F7& t, s32 i) {
    if (t.unkA != 0) {
        return *(u16*)(t.unkC + i * 8 + 2);
    }
    return *(u16*)(t.unkC + i * 10 + 2);
}

extern "C" u16 func_0023F738(O23F7* o, s32 i) {
    return Get23F7b(*o->unk8, i);
}

extern "C" void func_0023F770(char* p, TI128* v) {
    struct VE {
        s16 delta;
        s16 pad;
        void* fn;
    };
    VE* e = (VE*)(*(char**)(p + 0xC) + 0x48);
    TI128* r = ((TI128* (*)(char*))e->fn)(p + e->delta);
    TI128 t;
    asm volatile("lqc2 $vf2, 0(%0)" : : "r"(r));
    register void* a1 asm("$5") = &t;
    asm volatile("lqc2 $vf1, 0(%0)" : : "r"(v), "r"(a1));
    register void* a0 asm("$4") = *(void**)(p + 8);
    asm volatile("vsub.xyzw $vf1, $vf1, $vf2" : : "r"(a0));
    asm volatile("sqc2 $vf1, %0" : "=m"(t));
    func_00244B68(a0, a1);
}

extern "C" void func_0023F7D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F7D8);

extern "C" void func_0023F988(void** p) {
    func_00244C40(p[2]);
}

extern "C" void func_0023F9A8(void** p) {
    func_00245220(p[2]);
}

extern "C" s32 func_0023F9C8(char* o, s32 b) {
    s32 q = *(s32*)(o + 8);
    s32 p18 = q + 0x20;
    s32 p19 = q + 0x10;
    f32 t = func_0010F698(b);
    if (func_0010F698(p18) < t) {
        return 0;
    }
    s32 p17 = b + 0x10;
    t = func_0010F698(p19);
    if (func_0010F698(p17) < t) {
        return 0;
    }
    t = func_0010F6C0(b);
    if (func_0010F6C0(p18) < t) {
        return 0;
    }
    t = func_0010F6C0(p19);
    if (func_0010F6C0(p17) < t) {
        return 0;
    }
    t = func_0010F6A8(b);
    if (func_0010F6A8(p18) < t) {
        return 0;
    }
    t = func_0010F6A8(p19);
    if (func_0010F6A8(p17) < t) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023FAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240050);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_002405D0);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240A90);

extern "C" void func_00240F18(void** p) {
    func_00244930(p[2]);
}

extern "C" void func_00240F38(void** p) {
    func_00246B08(p[2]);
}

extern "C" void func_00240F58(void** p) {
    func_002456B0(p[2]);
}

extern "C" void* func_00240F78(void* self) {
    char* p = (char*)self;
    func_0023F1A0(p);
    char* t = p + 0xA0;
    *(void**)(p + 0xC) = D_00354B88;
    func_0010F690(t);
    func_0010F690(p + 0xB0);
    func_001342B0(t);
    *(int*)(p + 0xC0) = 0;
    *(int*)(p + 0xC4) = 0;
    return p;
}

extern "C" void func_00240FD8(char* p, int flags) {
    *(void**)(p + 0xC) = D_00354B88;
    if (*(u16*)(p + 4) & 0x8000) {
        int t = *(int*)(p + 0xC0);
        if (t) {
            func_0011A470(t);
            *(int*)(p + 0xC0) = 0;
        }
    }
    func_0023F240_2(p, flags);
}
