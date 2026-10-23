#include "common.h"

struct S0017A620 {
    char pad[0x18];
    int unk18;
    int unk1C;
};

struct S001794F8 {
    char pad0[0x1C];
    int unk1C;
    char pad20[0xC];
    int unk2C;
};

struct S00179148 {
    char pad[0x14];
    void* unk14;
};

struct S00179BB0 {
    char pad[0x18];
    void* unk18;
};

extern "C" {
int func_00172CC0(void*, u32, int);
void func_0017D658(void*, int, int);
int func_0027D268(int, int, void*, int);
int func_0027D870(int, int, void*, int);
void func_0017D580(void*, int);
extern u8 D_003424C8[];
extern u8 D_00342638[];
void func_00179518(int, int);
extern u8 D_00341B18[];
void func_00172A00(void*);
void func_00172A00_2(void*, int) __asm__("func_00172A00");
extern u8 D_00341AB8[];
extern u8 D_00341A58[];
extern u8 D_00341FB8[];
extern u8 D_00342338[];
extern u8 D_00342398[];
void func_00113F38(void*);
extern u8 D_003427A8[];
}

extern "C" void func_00178FE8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00178FF0);

struct S179110 { char pad0[0x18]; float unk18; };

extern "C" void func_00179110(S179110* self, float* p) {
    *p *= self->unk18;
}

extern "C" void func_00179128(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179130);

extern "C" void func_00179148(S00179148* self) {
    self->unk14 = D_00341B18;
    func_00172A00(self);
}

extern "C" u32 func_00179170(void) {
    return 0xC876ADF3 /* ROTATE */;
}

extern "C" void func_00179180(S00179148* self) {
    self->unk14 = D_00341AB8;
    func_00172A00(self);
}

extern "C" u32 func_001791A8(void) {
    return 0x74E4BBA5 /* adjustspeed */;
}

extern "C" void func_001791B8(S00179148* self) {
    self->unk14 = D_00341A58;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_001791E0);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179360);

extern "C" u32 func_001793D8(void) {
    return 0x3267C5D6 /* framefactoroffset */;
}

extern "C" void func_001793E8(S00179148* self) {
    self->unk14 = D_00341FB8;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179410);

extern "C" void func_001794F0(void) {
}

extern "C" void func_001794F8(S001794F8* self) {
    func_00179518(self->unk2C, self->unk1C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179518);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179590);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179818);

extern "C" void func_00179AF8(S00179148* self) {
    self->unk14 = D_00342338;
    func_00172A00(self);
}

extern "C" u32 func_00179B20(void) {
    return 0xED05B9D3 /* blenddebugtwo */;
}

extern "C" void func_00179B30(S00179148* self) {
    self->unk14 = D_00342338;
    func_00172A00(self);
}

extern "C" u32 func_00179B58(void) {
    return 0x217E0D2E /* blenddebugthree */;
}

extern "C" void func_00179B68(S00179148* self) {
    self->unk14 = D_00342338;
    func_00172A00(self);
}

struct S001CC050 {
    char pad0[0x1C];
    void (*unk1C)(void);
    char pad20[0x8];
    void (*unk28)(void);
};

extern "C" void func_00179B90(S001CC050* p) {
    p->unk28();
}

extern "C" void func_00179BB0(S00179BB0* self) {
    self->unk18 = D_00342398;
    func_00113F38(self);
}

extern "C" void func_00179BD8(S00179BB0* self) {
    self->unk18 = D_00342398;
    func_00113F38(self);
}

struct P_00179C00 { int unk0; int unk4; int unk8; };
struct S_00179C00 { char pad0[0xC]; int unkC; char pad10[8]; char unk18[0x1C]; int unk34; float unk38; };
extern "C" {
int func_0027D268_g(int, int, float*, int) __asm__("func_0027D268");
int func_0027D870_g(int, int, int*, int) __asm__("func_0027D870");
}

static inline void Follow179(P_00179C00* p, int* k) {
    int t;
    while ((p->unk8 && (func_0027D870_g(p->unk8, *k, &t, 0) ^ 1) == 0) ||
           (p->unk4 && (func_0027D870_g(p->unk4, *k, &t, 0) ^ 1) == 0)) {
        *k = t;
    }
}

extern "C" void func_00179C00(S_00179C00* self, P_00179C00* p) {
    int key;
    int key2;
    float* f = &self->unk38;
    *f = 1.0f;
    if (func_0027D268_g(p->unk0, 0x64242046, f, 0) == 0) {
        int ok;
        if ((func_0027D870_g(p->unk0, 0x64242046, &key, 0) ^ 1) != 0) {
            ok = 0;
        } else {
            Follow179(p, &key);
            ok = 1;
        }
        if ((ok ^ 1) == 0) {
            if (!p->unk8 || func_0027D268_g(p->unk8, key, f, 0) == 0) {
                if (p->unk4) {
                    func_0027D268_g(p->unk4, key, f, 0);
                }
            }
        }
    }
    int ok2;
    if ((func_0027D870_g(p->unk0, 0x98549BA4, &key2, 0) ^ 1) != 0) {
        ok2 = 0;
    } else {
        Follow179(p, &key2);
        ok2 = 1;
    }
    if (ok2 != 0) {
        func_0017D658(self->unk18, self->unkC, key2);
        self->unk34 = 0;
        return;
    }
    self->unk34 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_00179DE0);

struct S17A060 { char pad0[0xC]; int unkC; char pad10[8]; char unk18[0x1C]; int unk34; float unk38; };

extern "C" int func_0017A060(S17A060* self, u32 key, int p) {
    int b;
    int a;
    int k;
    void* d;
    int fl;
    int pp;
    switch (key) {
    case 0x4779AF46:
        func_0027D870(p, 0, &a, 1);
        {
            u32 kk = 0xF649D637;
            self->unk34 = a != kk;
        }
        return 1;
    case 0x8C73A2F1:
        func_0027D870(p, 0x98549BA4, &b, 1);
        func_0017D658(self->unk18, self->unkC, b);
        d = &self->unk38;
        self->unk38 = 1.0f;
        k = 0x54628ED7;
        pp = p;
        asm("" : "+r"(pp));
        fl = 0;
        goto call;
    case 0x4F770C95:
        d = &self->unk38;
        k = 0;
        fl = 1;
        pp = p;
        asm("" : "+r"(pp));
    call:
        func_0027D268(pp, k, d, fl);
        return 1;
    default:
        return func_00172CC0(self, key, p);
    }
}

extern "C" void func_0017A178(void) {
}

extern "C" u32 func_0017A180(void) {
    return 0x4600C341 /* overlay */;
}

struct S17A190 { char pad0[0x14]; void* unk14; char unk18[1]; };

extern "C" void func_0017A190(S17A190* self, int a) {
    self->unk14 = D_003424C8;
    func_0017D580(self->unk18, 2);
    func_00172A00_2(self, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_0017A1E0);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_0017A358);

extern "C" void func_0017A5B8(void) {
}

extern "C" u32 func_0017A5C0(void) {
    return 0xBA560054 /* mappedmappedoverlay */;
}

extern "C" void func_0017A5D0(S17A190* self, int a) {
    self->unk14 = D_00342638;
    func_0017D580(self->unk18, 2);
    func_00172A00_2(self, a);
}

extern "C" int func_0017A620(S0017A620* self) {
    self->unk1C = 0;
    self->unk18 = 1;
    return 1;
}

extern "C" int func_0027DF00(int, u32);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_0017A630);

extern "C" void func_0017A6D8(S0017A620* self, float* out) {
    switch (self->unk1C) {
    case 1:
        *out = 0.016666668f;
        self->unk1C = 2;
        break;
    case 2:
        *out = 0.0f;
        self->unk18 = 1;
        break;
    }
    if (self->unk18 == 0) *out = -*out;
}

extern "C" u32 func_0017A738(void) {
    return 0x48D89FC1 /* modelviewer */;
}

extern "C" void func_0017A748(S00179148* self) {
    self->unk14 = D_003427A8;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_0017A770);

INCLUDE_ASM("asm/nonmatchings/game/t_178FE8", func_0017AA10);
