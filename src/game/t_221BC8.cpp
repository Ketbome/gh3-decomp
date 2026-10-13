// cflags: -funroll-loops
#include "common.h"

struct Big221 {
    int unk0;
    int unk4[3];
};

struct VEntry221 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S221 {
    int* unk0;
    int unk4[0x3C];
    int unkF4;
};

struct S222 {
    u32 unk0;
    int unk4;
    char pad8[0x4];
    int unkC;
    char pad10[0x8];
    VEntry221* unk18;
    int unk1C;
    int unk20;
    char pad24[0x4];
    void* unk28;
    char pad2C[0x194];
    int unk1C0;
};

struct S222b {
    char pad0[0x4];
    int unk4;
};

extern "C" {
void func_00222470(int, int);
void func_00222F10(int, int);
extern u8 D_00390830[];
void* func_00113D20(u32 size);
void func_002230D8(void*, int);
void* func_00224220(void*, int);
int func_00223420(void*);
void func_001D0F90(void*, int);
extern u8 D_003520D8[];
void func_002231A0(S221*, int, int);
int func_00224F78(int, int, int);
extern Big221 D_0036F520[] __attribute__((section(".sdata")));
void func_002226F8(void*);
void func_00223590(void*, int);
void func_00223628(void*, int);
void func_0027D470(void*, u32, void*, int);
void* func_001D0F68(void*);
void func_00223190(S221*);
S222* func_00222DE0(S222*);
void func_002230B8(S221*, int);
void* func_00223488(void*, void*);
void func_00223520(void*, void*);
void func_00119400(void*, void*);
extern void* D_00368A38;
void func_001D03D8(int, int, int, int, int);
int func_0030AA88(char*);
int func_0030A970(char*, char*);
void func_00223360(int, int, int);
u32 CrcFromPathLowercase(const char*);
int func_001D1CF8(void*, u32);
void func_002220B0(void*);
int func_00162070(int);
void func_0028C9D0(u32, int, int, int, int, int);
void func_00221DE8_p(void*) __asm__("func_00221DE8");
void func_002227F0(char*, int);
void func_0027D268(int, u32, void*, int);
void func_002226E8_f(void*, int, f32, f32) __asm__("func_002226E8");
}

struct V221 {
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

struct A221 {
    s32 unk0;
    s32 unk4;
    s32 (V221::*unk8)(int, int);
};

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00221BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00221CC8);

extern "C" void func_00221DB0(void) {
}

extern "C" void func_00221DB8(void) {
}

extern "C" void func_00221DC0(void) {
}

extern "C" void func_00221DC8(void) {
}

extern "C" void func_00221DD0(void) {
}

extern "C" void func_00221DD8(void) {
}

extern "C" void func_00221DE0(void) {
}

extern "C" void func_00221DE8(void) {
}

extern "C" void func_00221DF0(S222* p) {
    func_002220B0(p);
    if (func_001D1CF8((void*)p->unkC, 0x8536DBA5)) {
        if (*(int*)((char*)p + 0x3C)) func_0028C9D0(0xED9C1839, 0, p->unkC, 0, 0, 0);
    }
    char* t = (char*)func_001D1CF8((void*)p->unkC, 0x286A8D26);
    if (t && func_00162070(*(int*)(t + 0x210))) func_00221DE8_p(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00221E88);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002220B0);

extern "C" void func_00222388(void) {
}

extern "C" void func_00222390(S222* self, int a) {
    VEntry221* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" s32 func_002223B8(V221* p, A221* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_00222458(void) {
    return 2;
}

extern "C" void func_00222460(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222468);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222470);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222500);

extern "C" void func_00222530(S222* self) {
    ((void (*)(S222*))self->unk28)(self);
}

extern "C" void func_00222550(void) {
    func_00222470(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222570);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222590);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002226D8);

extern "C" int func_002226E8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002226F0);

extern "C" void func_002226F8(void* self) {
    int* p = (int*)self;
    if (p[0]) {
        u32 i = 0;
        if (p[4]) {
            do {
                void* e = ((void**)p[5])[i];
                if (e) func_00119400(D_00368A38, e);
                i++;
            } while (i < (u32)p[4]);
        }
        if (p[5]) func_00119400(D_00368A38, (void*)p[5]);
        if (p[6]) func_00119400(D_00368A38, (void*)p[6]);
        if (p[0x67]) func_002227F0((char*)p[0x67], 3);
        p[0] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002227B0);

extern "C" f32 func_002227B8(S222* self) {
    if (self->unk0 < 2) {
        return 0.0f;
    }
    return ((f32*)self->unk18)[self->unkC];
}

extern "C" void func_002227F0(char* p, int flags) {
    if (*(void**)(p + 8)) {
        func_00119400(D_00368A38, *(void**)(p + 8));
    }
    if (flags & 1) {
        func_00119400(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222848);

extern "C" int func_00222920(S222* p) {
    if (p->unk1C == 1) {
        int v = *(int*)((char*)p + 0x360);
        if (v) func_001D03D8(p->unkC, v, 0, 0, 0);
        p->unk1C = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222978);

extern "C" int func_00222A30(char* p) {
    func_002226F8(p + 0x20);
    func_002226F8(p + 0x1C0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222A68);

extern "C" int func_00222B30(S222* self) {
    if (self->unk20 || self->unk1C0) {
        return 1;
    }
    return 0;
}

extern "C" int func_00222B58(S222* self) {
    return self->unk1C == 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222B68);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222D88);

extern "C" S222* func_00222DB0(void) {
    return func_00222DE0((S222*)func_00113D20(0x1C));
}

extern "C" void func_00222DD8(void) {
}

extern "C" S222* func_00222DE0(S222* p) {
    func_001D0F68(p);
    *(u8**)((char*)p + 0x18) = D_003520D8;
    p->unk4 = 0x8B5D73B0;
    return p;
}

extern "C" void func_00222E20(S222* self, int flag) {
    self->unk18 = (VEntry221*)D_003520D8;
    func_001D0F90(self, flag);
}

extern "C" void func_00222E48(void) {
}

extern "C" void func_00222E50(void) {
}

extern "C" void func_00222E58(void) {
}

extern "C" s32 func_00222E60(V221* p, A221* a, int x, int y) {
    if (a->unk8) {
        return (p->*a->unk8)(x, y);
    }
    return p->v12(a->unk0);
}

extern "C" int func_00222F00(void) {
    return 2;
}

extern "C" void func_00222F08(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222F10);

extern "C" void func_00222F70(void) {
    func_00222F10(1, 0xFFFF);
}

extern "C" int func_00222F90(int a) {
    return func_00224F78(D_0036F520->unk0, a, 0) != 0;
}

extern "C" int func_00222FC0(S221* self) {
    return *self->unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00222FD0);

extern "C" S221* func_00223050(S221* p) {
    int* q = p->unk4;
    int i = 0x3B;
    do { *q++ = 0; } while (--i != -1);
    p->unkF4 = 0;
    return p;
}

extern "C" void func_002230B8(S221* self, int v) {
    int n = self->unkF4;
    self->unkF4 = n + 1;
    *(int*)(n * 4 + (char*)self + 4) = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002230D8);

extern "C" void func_00223190(S221* self) {
    self->unkF4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223198);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_002231A0);

extern "C" void func_002232F0(int a) {
    func_002230B8((S221*)D_00390830, a);
}

extern "C" void func_00223318(int a) {
    func_002230D8(D_00390830, a);
}

extern "C" void func_00223340(void) {
    func_00223190((S221*)D_00390830);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223360);

extern "C" void func_00223388(char* path, int a, int b) {
    char buf[0x70];
    int n = func_0030AA88(path);
    if (n && path[n - 1] == '_') {
        func_0030A970(buf, path);
        buf[n - 1] = 0;
        path = buf;
    }
    func_00223360(CrcFromPathLowercase(path), a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223418);

extern "C" int func_00223420(void* a) {
    S222b* p = 0;
    func_0027D470(a, 0x2E7D5EE7, &p, 0);
    if (!p) {
        return 0;
    }
    return p->unk4;
}

extern "C" int func_00223460(void* a) {
    return func_00223420(func_00224220(a, 1));
}

extern "C" void* func_00223488(void* a, void* i) {
    char* p = 0;
    func_0027D470(a, 0x2E7D5EE7, &p, 0);
    return *(int*)(p + 4) == 1 ? *(void**)(p + 8) : (void*)(*(int**)(p + 8))[(int)i];
}

extern "C" void func_002234E8(void* a, void* b) {
    func_00223488(func_00224220(a, 1), b);
}

extern "C" void func_00223520(void* a, void* b) {
    func_00224220(func_00223488(a, b), 1);
}

extern "C" void func_00223548(void* a, void* b) {
    func_00223520(func_00224220(a, 1), b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223580);

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223590);

extern "C" void func_002235F0(void* a, void* b) {
    func_00223590(func_00224220(a, 1), (int)b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223628);

extern "C" void func_00223B60(void* a, void* b) {
    func_00223628(func_00224220(a, 1), (int)b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_221BC8", func_00223B98);
