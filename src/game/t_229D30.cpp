#include "common.h"

struct S229 {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x10];
    void* unk1C;
    void* unk20;
    char pad24[0x84];
    void* unkA8;
    char padAC[0xC];
    int unkB8;
    char padBC[0x8];
    int unkC4;
    char padC8[0x4];
    void* unkCC;
};

extern "C" {
void func_0022B2E8(void*);
void func_00113FB8(void*);
void func_0022B320(void*);
int func_0022CB18(void*);
extern int D_0036F608;
void func_00229538(int, int);
void func_0022B3B8(S229*);
void func_0022B700(S229*);
extern int D_00370EE0[] __attribute__((section(".sdata")));
void func_00114958(int, int);
int func_0022B1B8(void*);
void func_001342E8(void*, int);
void func_0022AE78(int, void*, int);
void* func_0022B040(char*, int);
void* func_0022C768(int, int, int);
void* func_0022C850(int, int);
extern void* D_0036F658;
extern u32 D_0036F65C;
void func_0022C0D8(void*, int);
extern u8 D_00352CC8[];
extern u8 D_00393AD8[];
extern void* D_00368A38;
void func_00119400(void*, void*);
void func_0022B5D0(void*);
void func_0022B918(void*);
void func_0011E050(int, void*);
void func_0011C408(int, void*);
int func_0030AA88(char*);
int func_0030E650(char*, char*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D30);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D38);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229F38);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A1D8);

GP_DATA(D_0036F608);
extern "C" void CFunc_ParseNodeArray(int a) {
    func_00229538(D_0036F608, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A278);

struct D229 {
    char pad0[0x14];
    virtual ~D229();
};

GP_DATA(D_0036F65C);
GP_DATA(D_0036F658);
extern "C" void func_0022A2D8(void) {
    if (D_0036F65C >= 2) {
        D_0036F65C -= 1;
        return;
    }
    if (D_0036F658) delete (D229*)D_0036F658;
    D_0036F658 = 0;
    D_0036F65C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A330);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A680);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A800);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9B0);

extern "C" void func_0022A9B8(S229* self) {
    self->unkB8 = 0;
    self->unkC4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022ABE8);

extern "C" void func_0022ADD0(int a, int** b) {
    int* t = *b;
    func_001342E8(b, 0);
    func_0022AE78(a, t, t[1]);
}

extern "C" void func_0022AE18(int a, int* b, int c) {
    int t = *b;
    func_001342E8(b, 0);
    func_0022AE78(a, (void*)t, c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE78);

struct V229 {
    char pad0[0x34];
    virtual void v1();
    virtual void v2();
    virtual ~V229();
    virtual void v4();
    virtual void v5();
    virtual s32 v6();
};

extern "C" void func_0022AFC0(int a, V229* o) {
    o->v6();
    func_0022C0D8(o, 0);
    if (o) delete o;
}

extern "C" int func_0022B020(S229* self) {
    return func_0022CB18(self->unkA8) == 0;
}

extern "C" void* func_0022B040(char* p, int b) {
    void* r = func_0022C768(*(int*)(p + 0xA4), b, *(int*)(p + *(int*)(p + 0x18) * 4 + 0x1C));
    if (!r) {
        r = func_0022C768(*(int*)(p + 0xA4), b, 0);
        if (!r && *(int*)(p + 0xC8)) r = func_0022C850(*(int*)(p + 0xA4), b);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B168);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B1B8);

extern "C" void func_0022B2E8(void* a) {
    while (func_0022B1B8(a)) {
    }
}

extern "C" void func_0022B320(void* self) {
    func_0022B2E8(self);
}

extern "C" void func_0022B340(char* p) {
    int v = *(int*)(p + 0xCC);
    func_00114958(D_00370EE0[0] + 8, v);
}

extern "C" void func_0022B368(S229* self) {
    func_00113FB8(self->unkCC);
}

extern "C" void func_0022B388(S229* self) {
    func_0022B320(self->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3A8);

extern "C" void func_0022B3B8(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S229* func_0022B3C8(S229* p) {
    func_0022B3B8(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3F0);

extern "C" void func_0022B5D0(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_0022B3B8((S229*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

extern "C" void func_0022B688(char* p, int flags) {
    if (!((u8*)p)[0x16]) {
        if (*(void**)(p + 4)) {
            func_0022B5D0(p);
            if (*(void**)(p + 4)) func_00119400(D_00368A38, *(void**)(p + 4));
            *(void**)(p + 4) = 0;
        }
    }
    if (flags & 1) func_00119400(D_00368A38, p);
}

extern "C" void func_0022B700(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S229* func_0022B710(S229* p) {
    func_0022B700(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B738);

extern "C" void func_0022B918(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_0022B700((S229*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

extern "C" void func_0022B9D0(char* p, int flags) {
    if (!((u8*)p)[0x16]) {
        if (*(void**)(p + 4)) {
            func_0022B918(p);
            if (*(void**)(p + 4)) func_00119400(D_00368A38, *(void**)(p + 4));
            *(void**)(p + 4) = 0;
        }
    }
    if (flags & 1) func_00119400(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BA48);

extern "C" void func_0022BA70(S229* self) {
    ((void (*)(S229*))self->unk1C)(self);
}

extern "C" void* func_0022BA90(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x34) = D_00352CC8;
    int* q = (int*)(p + 0x24);
    *(u32*)(p + 0x20) &= 0x80FFFFFF;
    *(int*)(p + 0) = 0;
    int* n = (int*)(p + 0x2C);
    *(int*)(p + 4) = 0;
    *(int*)(p + 8) = 0;
    p[0xC] = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 0x14) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x1C) = 0;
    q[1] = 0;
    *(int**)(p + 0x2C) = n;
    n[1] = (int)n;
    q[1] = (int)D_00393AD8;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBD0);

struct X229 {
    char pad0[0x20];
    u32 flags;
    char pad24[0x10];
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
    virtual void v13(int, u32);
    virtual void v14();
    virtual void v15(int, int);
};

extern "C" int func_0022BCE0(X229* o, int x, u32 y, int z, int a, int b) {
    o->flags = (o->flags & 0x80FFFFFF) | 0x01000000;
    o->v15(a, b);
    o->flags = (o->flags & 0xFF000000) | (y & 0xFFFFFF);
    o->v13(x, o->flags & 0xFFFFFF);
    return 0;
}
