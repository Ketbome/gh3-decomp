// cflags: -funroll-loops
#include "common.h"

struct S00187F48 {
    char pad[0x14];
    int unk14;
};

struct S00188F40 {
    char pad[0x20];
    int unk20;
};

struct S001891E0 {
    char pad[0xC];
    int unkC;
};

struct S00188F18 {
    char pad0[0xC];
    float unkC;
    char pad10[0x10];
    int unk20;
};

struct S00188730_1 {
    int unk0;
};

struct S00188730 {
    char pad[0x14];
    S00188730_1* unk14;
};

struct S00188740_1 {
    char pad[0x4];
    int unk4;
};

struct S00188740 {
    char pad[0x14];
    S00188740_1* unk14;
};

struct S00188750_1 {
    char pad[0x4];
    int unk4;
};

struct S00188750 {
    char pad[0x14];
    S00188750_1* unk14;
};

struct S00188760_1 {
    char pad[0x8];
    int unk8;
};

struct S00188760 {
    char pad[0x14];
    S00188760_1* unk14;
};

struct S00188770_1 {
    char pad[0x8];
    int unk8;
};

struct S00188770 {
    char pad[0x14];
    S00188770_1* unk14;
};

struct S001888B0_1 {
    char pad[0xC];
    float unkC;
};

struct S001888B0 {
    char pad[0x14];
    S001888B0_1* unk14;
};

struct S001888C0_1 {
    char pad[0x10];
    int unk10;
};

struct S001888C0 {
    char pad[0x14];
    S001888C0_1* unk14;
};

struct S00188920_1 {
    char pad[0x24];
    float unk24;
};

struct S00188920 {
    char pad[0x14];
    S00188920_1* unk14;
};

struct S00188930_1 {
    char pad[0x28];
    float unk28;
};

struct S00188930 {
    char pad[0x14];
    S00188930_1* unk14;
};

struct S00188958_1 {
    char pad[0x30];
    float unk30;
};

struct S00188958 {
    char pad[0x14];
    S00188958_1* unk14;
};

struct S00188968_1 {
    char pad[0x34];
    float unk34;
};

struct S00188968 {
    char pad[0x14];
    S00188968_1* unk14;
};

struct S00188978_1 {
    char pad[0x48];
    float unk48;
};

struct S00188978 {
    char pad[0x14];
    S00188978_1* unk14;
};

struct S00188988_1 {
    char pad[0x48];
    float unk48;
};

struct S00188988 {
    char pad[0x14];
    S00188988_1* unk14;
};

struct S001889B0_1 {
    char pad[0x38];
    float unk38;
};

struct S001889B0 {
    char pad[0x14];
    S001889B0_1* unk14;
};

struct S001889C0_1 {
    char pad[0x3C];
    float unk3C;
};

struct S001889C0 {
    char pad[0x14];
    S001889C0_1* unk14;
};

struct S00188A18_1 {
    char pad[0x2C];
    u16 unk2C;
};

struct S00188A18 {
    char pad[0x14];
    S00188A18_1* unk14;
};

struct S00188A28_1 {
    char pad[0x2E];
    u16 unk2E;
};

struct S00188A28 {
    char pad[0x14];
    S00188A28_1* unk14;
};

struct S00188A50_1 {
    char pad[0x50];
    int unk50;
};

struct S00188A50 {
    char pad[0x14];
    S00188A50_1* unk14;
};

struct S00188A60_1 {
    char pad[0x54];
    int unk54;
};

struct S00188A60 {
    char pad[0x14];
    S00188A60_1* unk14;
};

struct S00188B00_1 {
    char pad[0x88];
    float unk88;
};

struct S00188B00 {
    char pad[0x14];
    S00188B00_1* unk14;
};

struct S00188B50_1 {
    char pad[0x7C];
    int unk7C;
};

struct S00188B50 {
    char pad[0x14];
    S00188B50_1* unk14;
};

struct S00188B60_1 {
    char pad[0x78];
    float unk78;
};

struct S00188B60 {
    char pad[0x14];
    S00188B60_1* unk14;
};

struct S001889D0_1 {
    char pad[0x4C];
    int unk4C;
};

struct S001889D0 {
    char pad[0x14];
    S001889D0_1* unk14;
};

struct S001889D0_2 {
    int unk0;
};

struct SA187_1 {
    char pad0[0x24];
    float unk24;
    float unk28;
    u16 unk2C;
    u16 unk2E;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    char pad40[0x10];
    int unk50;
    int unk54;
    char pad58[0xC];
    int unk64;
    int unk68;
    char pad6C[0x20];
    u32 unk8C;
    int unk90;
    char pad94[0x8];
    float unk9C;
    float unkA0;
    float unkA4;
    float unkA8;
};

struct SA187 {
    char pad[0x14];
    SA187_1* unk14;
};

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct VObj {
    char pad0[0x8];
    VEntry* unk8;
    char padC[0x4];
    VEntry* unk10;
    char pad14[0x4];
    int unk18;
    char pad1C[0x4];
    VEntry* unk20;
};

struct SA187_3 {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x4];
    SA187_3* unk10;
};

struct B4 {
    char c[4];
};

struct SA187_4 {
    char pad0[0x4C];
    B4 unk4C;
    char pad50[0x8];
    long unk58;
};

struct SA187_6 {
    char pad0[0x158];
    s16 unk158;
    s16 unk15A;
};

struct SA187_7 {
    char pad0[0x6];
    u16 unk6;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    int unk18;
};

struct SA187_8 {
    char pad0[0x8];
    int unk8;
    SA187_6* unkC;
    char pad10[0x10];
    VObj* unk20;
};

struct SA187_9 {
    char pad0[0x28];
    float unk28;
    char pad2C[0x4];
    int unk30;
    char pad34[0x18];
    int unk4C;
    int unk50;
    VObj* unk54;
    char pad58[0x8];
    VObj* unk60;
};

struct SA187_10 {
    char pad0[0xC];
    VObj* unkC;
    char pad10[0x4];
    VObj* unk14;
};

struct SA187_11 {
    char pad0[0x94];
    float unk94;
    float unk98;
    char pad9C[0x8];
    float unkA4;
    float unkA8;
};

struct SA187_12 {
    char pad0[0x10];
    VEntry* unk10;
    SA187_11* unk14;
};

struct SA187_13 {
    char pad0[0x24];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct SA187_14 {
    char pad0[0xC];
    int unkC;
};

struct SA187_15 {
    SA187_14* unk0;
    int unk4;
    int unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    char pad28[0xC];
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    char pad48[0x18];
    SA187_13* unk60;
};

struct SA187_X {
    char pad0[0x10];
    VEntry* unk10;
    VObj* unk14;
};

struct SA187_Y {
    char pad0[0x14];
    u32 unk14;
    char pad18[0x4];
    VEntry* unk1C;
    VObj* unk20;
};

struct SA187_Z {
    char pad0[0x5C];
    VEntry* unk5C;
    VObj* unk60;
};

struct S_001891A0 { char pad0[0xC]; int unkC; };

extern "C" {
void func_001C25F8(void*, void*);
void func_001BF5F8(int, int, int, int, int);
extern float D_0036CBC4;
extern float D_0036CBC8;
extern float D_0036CBCC;
extern float D_0036CBD0;
int func_00317588(float);
int func_0031B650(int, u64);
float func_00317298(int);
int func_00188060(void*, int, int, int, int, int, int, int);
void func_0015E0F8(void*);
void func_0015E128(void*, int);
void func_0015EA78(void*);
void func_0015EAC0(void*, int);
void func_00153810(void*);
void func_00153898(void*, int);
VObj* func_001BFEA0(int, float);
VObj* func_001C2508(int, float);
VObj* func_001B21E0(int, float);
void func_00188680(SA187_X*);
void func_00188DD0(SA187_Y*);
void func_00189360(SA187_Z*);
void func_00153498(void*, int, int, int);
void* func_00183840(int, int);
void func_001575C0(void*, int, int, int);
void func_001576E0(void*, int, int, int, int, int, int);
extern u8 D_00344030[];
extern u8 D_00343FD0[];
extern u8 D_003442D0[];
void func_001BF8F8(void*, int);
int func_00188100(S00187F48*);
void func_001BF9C8(void*, int);
int func_001B1C80(int);
int func_001B1D18(int, int, int);
long func_001A4770(int, int);
void* func_001838B0(int, int);
int Heap_Alloc(int, int, int, int);
void Heap_Free(int, void*);
void func_0019ECE8(void*);
void func_00153410(void*);
void func_0015A7F8(void*, int);
void* func_0015A7B8(void*, int, int);
void func_0015B0B8(void*, int);
void* func_001C3240(int, void*);
void* func_001C3278(int, int);
void func_001891A0(void*);
void func_001B1D60(int);
void func_00153430(void*, int);
void func_0015B9E8(void*, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern int D_0036C7EC[] __attribute__((section(".sdata")));
SA187_7* func_00187E08(SA187_7*, int, int);
extern u8 D_00343BF8[];
extern u8 D_00344310[];
extern u8 D_003445A0[];
void func_001C1468(int);
void func_001C14E0(int);
void func_001C2C20(int);
void func_001C2C30(int);
void func_001B1F08(int);
void func_001B1F10(int);
void func_001B1F18(int);
void func_00153588(void);
void func_001C32A0(int);
void func_001BF838(int, float);
void func_001B2168(int, int);
void func_001B21A0(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187930);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187E08);

struct S187E58 { char pad0[0x10]; void* unk10; };

extern "C" S187E58* func_00187E58(S187E58* self, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    func_0015A7B8(self, a1, a7);
    self->unk10 = D_00343BF8;
    func_00188060(self, 0, a2, a3, a4, a5, a6, a7);
    return self;
}

extern "C" void func_00187F00(SA187_7* self, int a) {
    self->unk10 = D_00343BF8;
    func_00188100((S00187F48*)self);
    func_0015A7F8(self, a);
}

extern "C" int func_00187F48(S00187F48* self) {
    return self->unk14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187F50);

struct O_00188060 { char pad0[4]; int unk4; };
struct S_00188060 { char pad0[6]; u16 unk6; char pad8[4]; int unkC; char pad10[4]; O_00188060* unk14; };
extern "C" void func_00187F50(S_00188060*);

extern "C" int func_00188060(void* p, int a, int b, int c, int d, int e, int g, int h) {
    S_00188060* self = (S_00188060*)p;
    int fl = h;
    if (g) {
        fl = 1;
        self->unk6 |= 1;
    }
    if (a != 0) {
        self->unk14 = (O_00188060*)func_001C3240(a, &self->unkC);
    } else {
        self->unkC = c;
        self->unk14 = (O_00188060*)func_001C3278(b, c);
    }
    if (self->unk6 & 1) func_0015B0B8(self, self->unk14->unk4);
    if (fl) func_00187F50(self);
    return 0;
}

extern "C" int func_00188100(S00187F48* self) {
    func_001C32A0(self->unk14);
    return 0;
}

extern "C" void* func_00188120(int x, int a, int b, int c) {
    void* p = func_00183840(Heap_Alloc(D_00368A38[0], 0x14, 1, 0), 0);
    func_001575C0(p, a, b, c);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001881A0);

extern "C" void* func_001882A8(int x, int a, int b, int c, int d, int e, int f) {
    void* p = func_00183840(Heap_Alloc(D_00368A38[0], 0x14, 1, 0), 0);
    func_001576E0(p, a, b, c, d, e, f);
    return p;
}

extern "C" int func_00188358(void) {
    return 0;
}

extern "C" int func_00188360(VObj* o) {
    if (o) {
        VEntry* e = &o->unk8[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
    return 1;
}

extern "C" void func_00188398(void) {
}

extern "C" int func_001883A0(void) {
    return 0;
}

extern "C" void* func_001883A8(int a, int b, int c) {
    return func_001838B0(Heap_Alloc(D_00368A38[0], 0x14, 1, 0), c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001883F0);

extern "C" int func_00188420(SA187_3* self) {
    if ((self->unk4 >> 2) & 1) {
        return self->unk10->unk8;
    }
    return 0;
}

extern "C" int func_00188448(SA187_3* self) {
    if ((self->unk4 >> 2) & 1) {
        return self->unk10->unk8;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188470);

extern "C" void func_00188478(int a, int b, int c, int d, int e, int f, int g) {
    func_00187E58((S187E58*)Heap_Alloc(D_00368A38[0], 0x18, 1, 0), a, b, c, d, e, f, g);
}

extern "C" void* func_00188520(int a) {
    return func_00187E08((SA187_7*)Heap_Alloc(D_00368A38[0], 0x18, 1, 0), a, 1);
}

extern "C" int func_00188568(VObj* o) {
    func_0019ECE8(o);
    if (o) {
        VEntry* e = &o->unk10[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001885B0);

extern "C" void func_00188618(SA187_X* self, int flags) {
    self->unk10 = (VEntry*)D_00344030;
    if (self->unk14) {
        VObj* o = self->unk14;
        VEntry* e = &o->unk20[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
    func_0015E128(self, flags);
}

extern "C" void func_00188680(SA187_X* self) {
    VEntry* e;
    e = &self->unk10[9];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk10[10];
    ((void (*)(void*, int, float))e->fn)((char*)self + e->delta, 0, 0.0f);
    e = &self->unk10[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
    e = &self->unk10[13];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00188700(SA187_10* self, int a) {
    VObj* o = self->unk14;
    VEntry* e = &o->unk20[2];
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, a);
}

extern "C" int func_00188730(S00188730* self) {
    return self->unk14->unk0;
}

extern "C" S00188740_1* func_00188740(S00188740* self, int a1) {
    S00188740_1* t1 = self->unk14;
    t1->unk4 = a1;
    return t1;
}

extern "C" int func_00188750(S00188750* self) {
    return self->unk14->unk4;
}

extern "C" S00188760_1* func_00188760(S00188760* self, int a1) {
    S00188760_1* t1 = self->unk14;
    t1->unk8 = a1;
    return t1;
}

extern "C" int func_00188770(S00188770* self) {
    return self->unk14->unk8;
}

struct D188 { int unk0; char pad4[8]; int unkC; };
struct O188 { char pad0[4]; int unk4; char pad8[8]; D188* unk10; };
struct T188 { char pad0[0x2C]; u16 unk2C; u16 unk2E; char pad30[0x10]; float unk40; float unk44; };
struct S188 { O188* unk0; float unk4; float unk8; char padC[8]; T188* unk14; };

extern "C" void func_001C0040_s(T188*, int) __asm__("func_001C0040");

static inline int GetA188(O188* o) {
    if ((o->unk4 >> 2) & 1) {
        return o->unk10->unk0;
    }
    if (o->unk4 & 1) {
        return (int)o->unk10;
    }
    return 0;
}

static inline int GetB188(O188* o) {
    if (((o->unk4 >> 2) & 1) && o->unk10->unkC) {
        return o->unk10->unkC;
    }
    return GetA188(o);
}

extern "C" void func_00188780(S188* self) {
    O188* o = self->unk0;
    if (o) {
        func_001C0040_s(self->unk14, GetB188(o));
    } else {
        func_001C0040_s(self->unk14, 0);
    }
    self->unk14->unk40 = (self->unk4 + 1.0f) * ((float)self->unk14->unk2C * 0.5f);
    self->unk14->unk44 = (self->unk8 + 1.0f) * ((float)self->unk14->unk2E * 0.5f);
}

extern "C" void func_00188870(SA187_10* self, int a, float f) {
    SA187_3* p = (SA187_3*)self->unk14;
    if (p->unk4) {
        func_001BF8F8(p, a);
    } else {
        func_001BF838((int)p, f);
    }
}

extern "C" float func_001888B0(S001888B0* self) {
    return self->unk14->unkC;
}

extern "C" int func_001888C0(S001888C0* self) {
    return self->unk14->unk10;
}

extern "C" void func_001888D0(SA187_10* self) {
    if (self->unkC) {
        func_001BF9C8(self->unk14, self->unkC->unk18);
    } else {
        func_001BF9C8(self->unk14, 0);
    }
}

extern "C" void func_00188908(SA187* self, float a, float b) {
    self->unk14->unk24 = a;
    self->unk14->unk28 = b;
}

extern "C" float func_00188920(S00188920* self) {
    return self->unk14->unk24;
}

extern "C" float func_00188930(S00188930* self) {
    return self->unk14->unk28;
}

extern "C" void func_00188940(SA187* self, float a, float b) {
    self->unk14->unk30 = a;
    self->unk14->unk34 = b;
}

extern "C" float func_00188958(S00188958* self) {
    return self->unk14->unk30;
}

extern "C" float func_00188968(S00188968* self) {
    return self->unk14->unk34;
}

extern "C" S00188978_1* func_00188978(S00188978* self, float f0) {
    S00188978_1* t1 = self->unk14;
    t1->unk48 = f0;
    return t1;
}

extern "C" float func_00188988(S00188988* self) {
    return self->unk14->unk48;
}

extern "C" void func_00188998(SA187* self, float a, float b) {
    self->unk14->unk38 = a;
    self->unk14->unk3C = b;
}

extern "C" float func_001889B0(S001889B0* self) {
    return self->unk14->unk38;
}

extern "C" float func_001889C0(S001889C0* self) {
    return self->unk14->unk3C;
}

extern "C" void func_001889D0(S001889D0* self, S001889D0_2* a1) {
    self->unk14->unk4C = a1->unk0;
}

extern "C" B4* func_001889E0(B4* out, SA187* self) {
    *out = ((SA187_4*)self->unk14)->unk4C;
    return out;
}

extern "C" void func_00188A00(SA187* self, u16 a, u16 b) {
    self->unk14->unk2C = a;
    self->unk14->unk2E = b;
}

extern "C" u16 func_00188A18(S00188A18* self) {
    return self->unk14->unk2C;
}

extern "C" u16 func_00188A28(S00188A28* self) {
    return self->unk14->unk2E;
}

extern "C" void func_00188A38(SA187* self, int a, int b) {
    self->unk14->unk50 = a;
    self->unk14->unk54 = b;
}

extern "C" int func_00188A50(S00188A50* self) {
    return self->unk14->unk50;
}

extern "C" int func_00188A60(S00188A60* self) {
    return self->unk14->unk54;
}

extern "C" void func_00188A70(SA187* self, int a) {
    ((SA187_4*)self->unk14)->unk58 = func_001A4770(a, 0x80);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188AA8);

extern "C" void func_00188AD0(SA187* self, int a, int b) {
    self->unk14->unk64 = a;
    self->unk14->unk68 = b;
}

extern "C" void func_00188AE8(SA187* self) {
    self->unk14->unk8C |= 1;
}

extern "C" S00188B00_1* func_00188B00(S00188B00* self, float f0) {
    S00188B00_1* t1 = self->unk14;
    t1->unk88 = f0;
    return t1;
}

extern "C" void func_00188B10(S00187F48* self) {
    func_001C1468(self->unk14);
}

extern "C" void func_00188B30(S00187F48* self) {
    func_001C14E0(self->unk14);
}

extern "C" S00188B50_1* func_00188B50(S00188B50* self, int a1) {
    S00188B50_1* t1 = self->unk14;
    t1->unk7C = a1;
    return t1;
}

extern "C" S00188B60_1* func_00188B60(S00188B60* self, float f0) {
    S00188B60_1* t1 = self->unk14;
    t1->unk78 = f0;
    return t1;
}

extern "C" void func_00188B70(SA187* self, int a) {
    self->unk14->unk8C |= 2;
    if (a == 2) {
        self->unk14->unk8C &= ~4;
    }
}

extern "C" void func_00188BB0(void) {
}

struct S_00188BB8_b { char pad0[0x90]; int unk90; float unk94; float unk98; };
struct S_00188BB8 { char pad0[0x14]; S_00188BB8_b* unk14; };

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188BB8);

extern "C" void func_00188C50(SA187* self, float a, float b) {
    self->unk14->unk9C = a;
    self->unk14->unkA0 = b;
    self->unk14->unk90 = 1;
}

extern "C" void func_00188C70(SA187* self, float a, float b) {
    self->unk14->unkA4 = a;
    self->unk14->unkA8 = b;
}

extern "C" void func_00188C88(SA187_12* self, float t) {
    SA187_11* p = self->unk14;
    if (p->unkA4 != 0.0f || p->unkA8 != 0.0f) {
        VEntry* e = &self->unk10[45];
        ((void (*)(void*, float, float))e->fn)((char*)self + e->delta, p->unk94 + p->unkA4 * t, p->unk98 + p->unkA8 * t);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188D00);

extern "C" void func_00188D68(SA187_Y* self, int flags) {
    self->unk1C = (VEntry*)D_00343FD0;
    if (self->unk20) {
        VObj* o = self->unk20;
        VEntry* e = &o->unk20[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
    func_0015EAC0(self, flags);
}

extern "C" void func_00188DD0(SA187_Y* self) {
    VEntry* e;
    self->unk14 = 0x54628ED7;
    e = &self->unk1C[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk1C[7];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk1C[5];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_00188E38(SA187_8* self) {
    VObj* o = self->unk20;
    VEntry* e = &o->unk20[2];
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, self->unk8);
}

struct N188E68b { int unk0; char pad4[8]; void* unkC; };
struct N188E68 { char pad0[4]; int unk4; char pad8[8]; N188E68b* unk10; };
struct S188E68c { char pad0[0x24]; int unk24; long unk28; };
struct S188E68 { char pad0[4]; N188E68* unk4; char pad8[0xC]; int unk14; int unk18; int unk1C; S188E68c* unk20; };

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188E68);

extern "C" void func_00188F18(S00188F18* self) {
    func_001BF838(self->unk20, self->unkC);
}

extern "C" void func_00188F38(void) {
}

extern "C" void func_00188F40(S00188F40* self) {
    func_001C2C20(self->unk20);
}

extern "C" void func_00188F60(S00188F40* self) {
    func_001C2C30(self->unk20);
}

extern "C" SA187_7* func_00188F80(SA187_7* self) {
    func_00153410(self);
    self->unk8 = D_00344310;
    self->unkC = 0;
    return self;
}

extern "C" void func_00188FB8(SA187_7* self, int a) {
    self->unk8 = D_00344310;
    if (self->unkC) {
        func_001891A0(self);
    }
    func_00153430(self, a);
}

extern "C" int func_00189010(SA187_8* self, int a) {
    int r = func_001B1C80(a);
    self->unkC = (SA187_6*)r;
    return r != 0;
}

extern "C" int func_00189040(SA187_8* self, int a, int b, int c) {
    int r = func_001B1D18(a, b, c);
    self->unkC = (SA187_6*)r;
    return r != 0;
}

extern "C" void func_00189078(SA187_8* self, int a, int b) {
    self->unkC->unk158 = a;
    if (b > 0) {
        self->unkC->unk15A = b;
    }
}

struct T_00189098 { char pad0[0x15C]; int unk15C[16]; };
struct S_00189098 { char pad0[0xC]; T_00189098* unkC; };
extern "C" void func_00189098(S_00189098* self, int* src) {
    int i;
    for (i = 0; i < 16; i++) {
        self->unkC->unk15C[i] = src[i];
    }
}

extern "C" void func_00189180(SA187_8* self, int a) {
    if (a) {
        D_0036C7EC[0] = (int)self->unkC;
    }
}

extern "C" void func_001891A0(void* p) {
    S_001891A0* self = (S_001891A0*)p;
    int c = self->unkC;
    if (D_0036C7EC[0] == c) {
        D_0036C7EC[0] = 0;
    }
    func_001B1D60(c);
    self->unkC = 0;
}

extern "C" void func_001891E0(S001891E0* self) {
    func_001B1F08(self->unkC);
}

extern "C" void func_00189200(S001891E0* self) {
    func_001B1F10(self->unkC);
}

extern "C" void func_00189220(S001891E0* self) {
    func_001B1F18(self->unkC);
}

extern "C" void func_00189240(S001891E0* self, int a1) {
    func_001B2168(self->unkC, ((a1 << 24) >> 24));
}

extern "C" void func_00189268(S001891E0* self, int a1) {
    func_001B21A0(self->unkC, ((a1 << 24) >> 24));
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189290);

extern "C" void func_001892F8(SA187_Z* self, int flags) {
    self->unk5C = (VEntry*)D_003442D0;
    if (self->unk60) {
        VObj* o = self->unk60;
        VEntry* e = &o->unk20[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
    func_00153898(self, flags);
}

extern "C" void func_00189360(SA187_Z* self) {
    VEntry* e;
    e = &self->unk5C[4];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk5C[5];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk5C[3];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    e = &self->unk5C[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_001893D0(SA187_9* self) {
    VObj* o = self->unk60;
    VEntry* e = &o->unk20[2];
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, self->unk4C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189400);

extern "C" void func_001894C8(SA187_9* self) {
    if (self->unk50) {
        func_001BF8F8(self->unk60, self->unk30);
    } else {
        func_001BF838((int)self->unk60, self->unk28);
    }
}

extern "C" void func_00189508(SA187_9* self) {
    if (self->unk54) {
        func_001BF9C8(self->unk60, self->unk54->unk18);
    } else {
        func_001BF9C8(self->unk60, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189540);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189710);

extern "C" SA187_7* func_00189718(int a, int b, int c) {
    SA187_7* p = func_00188F80((SA187_7*)Heap_Alloc(D_00368A38[0], 0x10, 1, 0));
    func_00153498(p, a, b, c);
    return p;
}

extern "C" void func_00189798(void) {
    func_00153588();
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001897B8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001897C0);

extern "C" void func_00189818(SA187_7* self, int a) {
    self->unk14 = D_003445A0;
    if (self->unk18) {
        Heap_Free(D_00368A38[0], (void*)self->unk18);
    }
    func_0015B9E8(self, a);
}

struct S189878 { int unk0; int unk4; int unk8; int unkC; char pad10[8]; int unk18; };

extern "C" void func_00189878(S189878* self) {
    int x = (int)(((float)self->unk0 + D_0036CBCC) * D_0036CBC4);
    int y = (int)(((float)self->unk4 + D_0036CBD0) * D_0036CBC8);
    int w = (int)(((float)self->unk8 + D_0036CBCC) * D_0036CBC4);
    int h = (int)(((float)self->unkC + D_0036CBD0) * D_0036CBC8);
    func_001BF5F8(self->unk18, x & 0xFFFF, y & 0xFFFF, (x + w - 1) & 0xFFFF, (y + h - 1) & 0xFFFF);
}
