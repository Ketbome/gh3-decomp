#include "common.h"

struct S_00122918 { char pad0[0x1C]; void (*unk1C)(void); };

struct S_00123018 { char pad0[0x2C]; int unk2C; char pad1[0x4]; int unk34; };

struct SA121_T {
    int unk0;
    char pad4[0x4];
    int unk8;
};

struct SA121_S {
    char pad0[0x4];
    int unk4;
    SA121_T* unk8;
    char padC[0x18];
    int unk24;
};

struct SA121_A {
    char pad0[0x4];
    SA121_S unk4[1];
};

struct SA121_C {
    char pad0[0x4];
    void* unk4;
    int unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    char pad18[0x30];
    int unk48;
    char pad4C[0x4];
    int unk50;
    int unk54;
    SA121_S* unk58;
};

struct SA121_D {
    char pad0[0x34];
    void* unk34;
    char pad38[0xC];
    void* unk44;
};

struct SA121_L {
    char pad0[0xC];
    SA121_L* unkC;
    SA121_L* unk10;
    void* unk14;
};

extern "C" {
int func_002F82B8(int, int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern void* D_00368E48;
extern u32 D_00368E4C;
extern u8 D_00339068[];
extern u8 D_00339080[];
int func_00121B18(SA121_S*);
int func_00121A68(SA121_S*);
int func_00121BF8(SA121_S*);
int func_00121CD8(SA121_S*);
int func_002F8230(int*, int*);
int func_001218F8(SA121_S*, int, int);
int func_002F75E0(int);
int func_002F7DA0(int, int);
int func_002F7B88(int, int);
int func_002F7850(int, void*, int, int, int);
void func_00119400(int, void*);
int func_00113DF0(int, int, int);
void* func_001216B0(int);
void func_00121870(void*, int);
extern int D_00372AC0;
int func_00121DD0(SA121_S*, int);
void func_00113F38(void);
extern u32 D_00368738;
extern int D_00368768;
int func_00122940(void);
int func_001170D0(void);
void func_00122A10(void);
extern int D_00368F20;
extern u8 D_00339370[];
void func_001CE888(void*, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001210C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121240);

GP_DATA(D_00368E48);
GP_DATA(D_00368E4C);
extern "C" void* func_00121618(int a) {
    if (D_00368E48 == 0 && a) {
        D_00368E48 = func_001216B0(func_00113DF0(0x54, 0, 1));
    }
    D_00368E4C++;
    return D_00368E48;
}

extern "C" void func_00121668(void) {
    if (D_00368E4C >= 2) {
        D_00368E4C--;
    } else {
        if (D_00368E48) {
            func_00121870(D_00368E48, 3);
        }
        D_00368E48 = 0;
        D_00368E4C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001216B0);

extern "C" void func_00121870(void* self, int flags) {
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" SA121_S* func_001218A0(SA121_A* self, int i, int j) {
    SA121_S* p = &self->unk4[i] + j;
    int r;
    func_00121BF8(p);
    r = func_00121CD8(p);
    if (r == 1 || r == 2) {
        return p;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001218F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121A68);

extern "C" int func_00121B18(SA121_S* self) {
    int a;
    int b;
    if (func_002F8230(&a, &b) == 1) {
        b = func_001218F8(self, a, b);
    }
    return b;
}

extern "C" int func_00121B68(SA121_S* self, int a) {
    int r;
    func_00121B18(self);
    if (func_002F7DA0(self->unk4, a) != 0) {
        self->unk24 = 8;
        return 0;
    }
    r = func_00121B18(self);
    if (r == -4) {
        r = 0;
    }
    return r == 0;
}

extern "C" int func_00121BD0(SA121_S* self, int a) {
    return func_00121DD0(self, a);
}

extern "C" int func_00121BF0(void) {
    return 0;
}

extern "C" int func_00121BF8(SA121_S* self) {
    return func_00121B18(self);
}

extern "C" int func_00121C18(SA121_S* self) {
    func_00121B18(self);
    if (func_002F75E0(self->unk4) != 0) {
        self->unk24 = 8;
        return 0;
    }
    return func_00121B18(self) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121C68);

extern "C" int func_00121CD8(SA121_S* self) {
    if (func_00121A68(self)) {
        if (self->unk24 != 1) {
            if (self->unk24 != 0) {
                self->unk24 = 8;
                return 0;
            }
        }
    }
    switch (self->unk8->unk0) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    return 0;
}

extern "C" int func_00121D78(SA121_S* self) {
    if (func_00121A68(self) && self->unk24) {
        self->unk24 = 8;
        return 0;
    }
    return self->unk8->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121DC8);

extern "C" int func_00121DD0(SA121_S* self, int a) {
    int r;
    func_00121B18(self);
    if (func_002F7B88(self->unk4, a) != 0) {
        self->unk24 = 8;
        return 0;
    }
    r = func_00121B18(self);
    if (r == -4) {
        r = 0;
    }
    return r == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121E38);

extern "C" int func_00121F28(SA121_S* self, int a) {
    char buf[0x40];
    func_00121B18(self);
    return (func_002F82B8(self->unk4, a, buf) & 0xFFFF) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00121F70);

extern "C" SA121_C* func_00122460(SA121_C* self, int a, SA121_S* b) {
    self->unk14 = D_00339068;
    self->unk54 = a;
    self->unk58 = b;
    self->unk4 = self;
    self->unk8 = 0;
    self->unkC = self;
    self->unk10 = self;
    return self;
}

extern "C" void func_00122490(SA121_L* self, int flags) {
    self->unk14 = D_00339080;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" int func_001224F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_001224F8);

extern "C" int func_00122550(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122558);

extern "C" int func_00122608(SA121_C* self, int a, int b) {
    int r;
    func_00121B18(self->unk58);
    if (func_002F7850(self->unk58->unk4, (char*)self + 0x18, a, self->unk50, b)) {
        self->unk58->unk24 = 8;
        return 0;
    }
    r = func_00121B18(self->unk58);
    if (r > 0) {
        self->unk50 += r;
    }
    return r;
}

extern "C" void func_001226A0(SA121_L* self, int flags) {
    self->unk14 = D_00339080;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122700);

extern "C" void func_00122770(void) {
    D_00372AC0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122778);

extern "C" void func_001228F8(void) {
    func_00113F38();
}

extern "C" void func_00122918(S_00122918* self) {
    self->unk1C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122938);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122940);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122A10);

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122AC8);

extern "C" void func_00122DE0(void) {
    D_00368738 = 0xC743B45A;
    if (func_00122940() == 0) {
        if (D_00368768 != 1) {
            if (D_00368768 != 0) {
                return;
            }
            if (func_001170D0()) {
                func_00122A10();
                return;
            }
        }
        D_00368738 = 0x77B12AAB;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122E58);

GP_DATA(D_00368F20);
extern "C" void func_00122F88(SA121_D* self, int flags) {
    self->unk44 = D_00339370;
    void** r = &self->unk34;
    void* p = *r;
    D_00368F20--;
    if (p) {
        func_001CE888(p, r);
        *r = 0;
    }
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122FF8);

extern "C" int func_00123018(S_00123018* self, int v) {
    if (self->unk34 == v) {
        self->unk2C |= 1;
        return 1;
    }
    return 0;
}

struct VE_123040 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_123040 { char pad0[8]; VE_123040 unk8; };
struct O_123040 { char pad0[8]; V_123040* unk8; };
struct S_123040 { char pad0[0x2C]; unsigned int unk2C; char pad30[4]; O_123040* unk34; };

extern "C" void func_00123040(S_123040* self) {
    if (self->unk2C & 1) {
        O_123040** pc = &self->unk34;
        O_123040* o = self->unk34;
        if (o) {
            V_123040* v = o->unk8;
            v->unk8.unk4((char*)o + v->unk8.unk0, 3);
        }
        if (self->unk34) {
            func_001CE888(self->unk34, pc);
            self->unk34 = 0;
        }
        self->unk34 = 0;
        self->unk2C = self->unk2C & 0xFFFFFFFE;
    }
}
