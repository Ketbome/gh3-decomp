#include "common.h"

struct VE_001230D0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int, int); };
struct S_001230D0 { char pad0[0x44]; VE_001230D0* unk44; };

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct SA123_B {
    char pad0[0xC];
    u8 unkC;
};

struct SA123_A {
    char pad0[0x4];
    int unk4;
    void* unk8;
    void* unkC;
    float unk10;
    float unk14;
};

struct SA123_N {
    int unk0;
    SA123_N* unk4;
};

struct SA123_C {
    char pad0[0x4];
    int unk4;
    void* unk8;
    SA123_B* unkC;
    int unk10;
    SA123_N unk14;
    int unk1C;
    int unk20;
};

struct SA123_V {
    char pad0[0x44];
    VEntry* unk44;
    char pad48[0x88];
    float unkD0;
    float unkD4;
};

extern "C" {
float func_0015DCB8(void);
float func_0015DCC8(void);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003396F8[];
extern u8 D_003394E0[];
extern u8 D_00339760[];
extern u8 D_00339648[];
extern u8 D_003396A0[];
extern u8 D_00376F70[];
extern u8 D_00377770[];
void Heap_Free(int, void*);
void func_001CE990(void*, int);
void func_001234B0(void*);
void func_001CF470(void*, int);
void func_001233A8(void*);
float func_0015DDA8();
float func_0031B118(float);
float func_0031B5C8(float);
void func_00160970(void*, int);
void func_001CE7A8(void*);
void func_00124558(void*);
void* func_00124628(void*);
void func_001CE7C0(void*, int);
void func_0014EB28(void*);
void* func_0014EB08(int);
void memset(void*, int, int);
void func_0014E098(int, char*);
u32 CrcFromPathLowercase(const char*);
void func_00160170(void*, u32, int, int, int, int);
int func_00129390(void);
void func_001294C0(int, void*);
void func_0011A470(void*);
void func_00129710(int, void*);
void func_001297B8(int, void*, int);
void* func_0011DF78(int, int, int, int);
int func_00123E68(void*, void*);
int func_0011DBB8(void*, void*, int, int);
void func_0011E008(void*);
void func_0016F820(int, int, int);
int func_001CFF58(void*, u32, int);
void func_0027D268(int, int, float*, int);
void func_00123F80(void);
}

struct S_00124490 { u8 unk0; u8 unk1; };

struct S_001244B0_b { char pad0[0x4]; int unk4; };
struct S_001244B0 { char pad0[0xC]; S_001244B0_b* unkC; };

extern "C" void func_001230D0(S_001230D0* self, int a1, int a2, int a3, int a4, int a5) {
    VE_001230D0* e = &self->unk44[5];
    e->unk4((char*)self + e->unk0, a1, a2, a3, a4, a5);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_001230F8);

extern "C" void func_00123138(SA123_V* self) {
    VEntry* e = &self->unk44[10];
    if (((int (*)(void*))e->fn)((char*)self + e->delta)) {
        e = &self->unk44[10];
        func_0016F820(((int (*)(void*))e->fn)((char*)self + e->delta), 0, 0);
    }
    e = &self->unk44[3];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" float func_001231B0(void) {
    return -1.0f;
}

extern "C" int func_001231C0(void) {
    return 0;
}

extern "C" int func_001231C8(void) {
    return 0;
}

extern "C" int func_001231D0(void) {
    return 0;
}

extern "C" int func_001231D8(void) {
    return 1;
}

extern "C" void func_001231E0(void) {
}

extern "C" void func_001231E8(void) {
}

extern "C" int func_001231F0(void) {
    return 0;
}

extern "C" int func_001231F8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123200);

extern "C" void func_001232E8(SA123_A* self, int flags) {
    self->unk8 = D_003394E0;
    func_001CE990(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123310);

struct S1233A8 { char pad0[0xD4]; float unkD4; float unkD8; };

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_001233A8);

struct S_001234B0 { char pad0[0xD0]; float unkD0; float unkD4; char padD8[0x10]; float unkE8; };

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_001234B0);

extern "C" float func_00123540(SA123_V* self) {
    func_001234B0(self);
    return self->unkD4;
}

extern "C" int func_00123568(SA123_V* self, u32 key, int params) {
    float v;
    if (key == 0x44EA2B6D) {
        func_0027D268(params, 0, &v, 1);
        self->unkD0 = v * 57.2957763671875f;
        func_001234B0(self);
        return 1;
    }
    return func_001CFF58(self, key, params);
}

struct S_001235E0 { char pad0[0xDC]; float unkDC; float unkE0; };

extern "C" void func_001235E0(S_001235E0* self, int a) {
    float v[2];
    v[0] = 0.3f;
    v[1] = 300.0f;
    func_0027D268(a, 0x48506742, v, 0);
    func_0027D268(a, 0xD155F150, v + 1, 0);
    self->unkDC = v[0];
    self->unkE0 = v[1];
    func_001CF470(self, a);
}

extern "C" SA123_A* func_00123678(SA123_A* self) {
    self->unk4 = 0;
    self->unk8 = D_003396F8;
    return self;
}

extern "C" void func_00123690(SA123_A* self, int flags) {
    self->unk8 = D_003396F8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" SA123_A* func_001236D0(SA123_A* self) {
    func_00123678(self);
    self->unk8 = D_003396A0;
    self->unk4 = 1;
    self->unk10 = 1.0f;
    self->unk14 = 1.0f;
    self->unkC = 0;
    return self;
}

extern "C" void func_00123720(SA123_A* self, int flags) {
    self->unk8 = D_003396A0;
    if (self->unkC) {
        func_0014EB28(self->unkC);
        self->unkC = 0;
    }
    func_00123690(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123778);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123808);

extern "C" void func_001238F8(SA123_A* self) {
    if (self->unkC) {
        func_00160970(self->unkC, 0);
    }
}

extern "C" void func_00123920(SA123_A* self) {
    if (self->unkC) {
        func_00160970(self->unkC, 1);
    }
}

extern "C" SA123_C* func_00123948(SA123_C* self) {
    SA123_N* p;
    func_00123678((SA123_A*)self);
    p = &self->unk14;
    self->unk14.unk0 = (int)p;
    self->unk8 = D_00339648;
    p->unk4 = p;
    self->unk4 = 2;
    self->unkC = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123998);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123AB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123B68);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123C00);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123C60);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123CC0);

extern "C" void func_00123CD0(void) {
}

extern "C" void func_00123CD8(void) {
}

extern "C" void func_00123CE0(void) {
}

extern "C" void func_00123CE8(void) {
}

extern "C" void func_00123CF0(void) {
}

extern "C" void func_00123CF8(void) {
}

extern "C" void func_00123D00(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123D08);

extern "C" int func_00123E68(void* a, void* b) {
    if (!func_0011DBB8(a, b, 8, 0x100)) {
        return 0;
    }
    for (int i = 0xFF; i >= 0; i -= 0x20) {
    }
    return 1;
}

extern "C" int func_00123EB8(int a) {
    int r = 0;
    void* h = func_0011DF78(a, 1, 100, 0);
    if (h) {
        r = func_00123E68(h, D_00376F70);
    }
    func_0011E008(h);
    return r;
}

extern "C" int func_00123F18(int a) {
    int r = 0;
    void* h = func_0011DF78(a, 1, 100, 0);
    if (h) {
        r = func_00123E68(h, D_00377770);
    }
    func_0011E008(h);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123F78);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00123F80);

extern "C" void func_00124068(void) {
    func_00123F80();
}

extern "C" int func_00124088(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00124090);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00124280);

extern "C" u8 func_00124490(void* self, S_00124490* p, int i) {
    p += i;
    return p->unk0;
}

extern "C" u8 func_001244A0(void* self, S_00124490* p, int i) {
    p += i;
    return p->unk1;
}

extern "C" int func_001244B0(S_001244B0* self) {
    return (self->unkC->unk4 >> 27) & 1;
}

extern "C" SA123_C* func_001244C8(SA123_C* self) {
    func_001CE7A8(self);
    self->unk10 = 0;
    self->unk14.unk0 = 0;
    self->unk14.unk4 = 0;
    self->unk20 = 0;
    self->unk1C = 0;
    self->unk8 = D_00339760;
    return self;
}

extern "C" void func_00124510(SA123_C* self, int flags) {
    self->unk8 = D_00339760;
    func_00124558(self);
    func_001CE7C0(self, flags);
}

struct VT_00124558 { char pad0[8]; s16 unk8; s16 unkA; void (*unkC)(void*, int); };
struct O_00124558 { char pad0[0xC]; VT_00124558* unkC; };
struct H_00124558 { char pad0[0x12]; u16 unk12; O_00124558** unk14; };
struct S_00124558 { char pad0[0xC]; H_00124558* unkC; char pad10[0x10]; int unk20; };

extern "C" void func_00124558(void* p) {
    int i;
    S_00124558* self = (S_00124558*)p;
    if (self->unkC->unk14) {
        i = 0;
        if (self->unkC->unk12) {
            do {
                O_00124558* o = self->unkC->unk14[i];
                if (o) o->unkC->unkC((char*)o + o->unkC->unk8, 3);
                i++;
            } while (i < self->unkC->unk12);
        }
        func_0011A470(self->unkC->unk14);
    }
    if (self->unk20) {
        i = func_00129390();
        if (i) func_001294C0(i, func_00124628(self));
    }
}

extern "C" void* func_00124628(void* p) {
    return p;
}

extern "C" void func_00124630(SA123_C* self) {
    int r;
    self->unkC->unkC++;
    r = func_00129390();
    func_00129710(r, func_00124628(self));
}

extern "C" void func_00124688(SA123_C* self, int a) {
    u8 c = self->unkC->unkC;
    if (c) {
        int r;
        self->unkC->unkC = c - 1;
        r = func_00129390();
        func_001297B8(r, func_00124628(self), a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_001246F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1230D0", func_00124878);
