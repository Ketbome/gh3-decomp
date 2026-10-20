#include "common.h"

extern "C" {
f32 func_0010F698(s32 a);
f32 func_0010F6A8(s32 a);
f32 func_0010F6C0(s32 a);
void func_0023F270(void*);
void func_002411D0(void*);
void func_0023F2A0(void*);
void func_0023F2E0(void*);
s32 Heap_Alloc(s32 a, s32 b, s32 c, s32 d);
s32 func_002433A8(s32 a, void* b);
void func_00241640(char* p, char* q);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

typedef int TI128 __attribute__((mode(TI)));

struct T2410 {
    char pad0[0xA];
    u8 unkA;
    char padB;
    char* unkC;
};

struct O2410 {
    char pad0[8];
    T2410* unk8;
};

static inline u16 Get2410(T2410& t, s32 i) {
    if (t.unkA != 0) {
        return *(u16*)(t.unkC + i * 8);
    }
    return *(u16*)(t.unkC + i * 10);
}

extern "C" u16 func_00241040(O2410* o, s32 i) {
    return Get2410(*o->unk8, i);
}

static inline u16 Get2410b(T2410& t, s32 i) {
    if (t.unkA != 0) {
        return *(u16*)(t.unkC + i * 8 + 2);
    }
    return *(u16*)(t.unkC + i * 10 + 2);
}

extern "C" u16 func_00241078(O2410* o, s32 i) {
    return Get2410b(*o->unk8, i);
}

extern "C" void func_002410B0(void* p) {
    func_0023F270(p);
    func_002411D0(p);
}

extern "C" void func_002410E0(void* p) {
    func_0023F2A0(p);
    func_002411D0(p);
}

extern "C" void func_00241110(void* p) {
    func_0023F2E0(p);
    func_002411D0(p);
}

extern "C" void func_00241140(void) {
}

struct V241148 {
    char pad0[0xC];
    virtual void v0();
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v26(void* a);
};

struct O241148 : V241148 {
    f32 unk10[0x10];
    f32 unk50;
    f32 unk54;
    f32 unk58;
};

extern "C" void func_00241148(O241148* o, f32* a, TI128* b) {
    if (a[0] == o->unk50 && a[1] == o->unk54 && a[2] == o->unk58) {
        TI128 t;
        register TI128* tp asm("$5") = &t;
        asm volatile("lqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0x10(%2)\n\tvmul.xyzw $vf1, $vf2, $vf1\n\tsqc2 $vf2, %0\n\tsqc2 $vf1, %0"
            : "=m"(t) : "r"(b), "r"(o));
        o->v26(tp);
    }
}


INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_002411D0);

extern "C" s32 func_002414B8(s32 a, s32 b) {
    s32 p18 = a + 0xB0;
    s32 p19 = a + 0xA0;
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

extern "C" s32 func_002415E0(char* p) {
    s32 t = func_002433A8(Heap_Alloc(D_00368A38[0], 0xD0, 1, 0), p);
    func_00241640((char*)t, *(char**)(p + 8));
    return t;
}

extern "C" void func_00241640(char* p, char* q) {
    *(int*)(p + 8) = (int)q;
    *(u16*)(p + 4) |= 0xC000;
    *(TI128*)(p + 0xA0) = *(TI128*)(q + 0x10);
    *(TI128*)(p + 0xB0) = *(TI128*)(q + 0x20);
    *(int*)(p + 0xC0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241668);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241D88);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_002428C0);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00242D80);
