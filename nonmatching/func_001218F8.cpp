#include "common.h"

struct S_00122918 { char pad0[0x1C]; void (*unk1C)(void); };

struct S_00123018 { char pad0[0x2C]; int unk2C; char pad1[0x4]; int unk34; };

struct SA121_T {
    int unk0;
    int unk4;
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
struct E122778 { int cnt; int v[5]; };
extern E122778 D_00376E88[];
int func_00122940_d(int, int) __asm__("func_00122940");
int func_00116878(void*, int, int);
int func_0030E650(int, int);
extern u8 D_003391D0[];
int func_003205E0(void);
extern int D_00368740;
extern int D_0032A4E0[];
int func_002F7970(int, void*, int, int, int);
int func_002F82B8(int, int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern void* D_00368E48;
extern u32 D_00368E4C;
extern u8 D_00339068[];
extern u8 D_00339080[];
int func_00121B18(SA121_S*);
int func_00121A68(SA121_S*);
int func_002F7690(int, int);
long func_0011ECE8(void);
int func_002F8208(int*, int*);
int func_00121BF8(SA121_S*);
int func_00121CD8(SA121_S*);
int func_002F8230(int*, int*);
int func_001218F8(SA121_S*, int, int);
int func_002F75E0(int);
int func_002F7DA0(int, int);
int func_002F7B88(int, int);
int func_002F7850(int, void*, int, int, int);
void Heap_Free(int, void*);
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
int func_00122A10(void);
extern int D_00368F20;
extern u8 D_00339370[];
void func_001CE888(void*, void*);
void* operator_new(u32);
char* strcpy(char*, const char*);
int func_002F7A90(int, char*);
int func_002F7750(int, char*, void*);
void* func_00122460_4(void*, int, void*, int) __asm__("func_00122460");
}

struct SA121_O { char pad0[0x48]; int unk48; u8 pad4C[2]; u8 unk4E; char pad4F; int unk50; };

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
        Heap_Free(D_00368A38[0], self);
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

struct V_001218F8 { int a; int b; int c; };
struct S_001218F8 { char pad0[8]; V_001218F8* unk8; V_001218F8* unkC; int unk10; int unk14; int unk18; char pad1C[8]; int unk24; };

extern "C" int func_001218F8_x(S_001218F8* self, int b, int x) __asm__("func_001218F8");
extern "C" int func_001218F8_x(S_001218F8* self, int b, int x) {
    if (x < 0) {
        int v;
        switch (x & 0xFFFF) {
        case 0x11: v = 8; break;
        case 0x9003: self->unk24 = 0; x = -1; goto done;
        case 0x2F: v = 1; x = -2; break;
        case 0x1C: v = 2; x = -3; break;
        case 2:
        case 0x14: v = 3; x = -4; break;
        case 0x6F:
        case 0x9001: v = 5; x = -5; break;
        case 0x5A: v = 6; x = -6; break;
        case 0x17: v = 7; x = -7; break;
        case 0x13: v = 4; x = -10; break;
        default: v = 8; break;
        }
        self->unk24 = v;
    }
done:
    if (b == 2) {
        *self->unk8 = *self->unkC;
        int t = (int)func_0011ECE8();
        self->unk18 = 0;
        self->unk14 = t;
        self->unk10 = x;
    }
    return x;
}

struct S_00121A68 { char pad0[4]; int unk4; char pad8[4]; int unkC; int unk10; int unk14; int unk18; char pad1C[8]; int unk24; };

extern "C" int func_00121A68(SA121_S* arg) {
    S_00121A68* self = (S_00121A68*)arg;
    int buf[2];
    if (self->unk18 == 0) {
        int r = func_002F7690(self->unk4, self->unkC);
        if (r) {
            self->unk24 = 8;
            return r;
        }
        self->unk18 = 1;
    }
    if ((u32)((int)func_0011ECE8() - self->unk14) < 0x1E) {
        if (func_002F8208(buf, &buf[1]) == 1) {
            int b = buf[1];
            func_001218F8(arg, buf[0], b);
        }
    } else {
        func_00121B18(arg);
    }
    return self->unk10;
}

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

extern "C" int func_00121C70(SA121_S* self) {
    func_00121BF8(self);
    if (func_00121A68(self)) {
        if (self->unk24 != 1) {
            if (self->unk24 != 0) {
                self->unk24 = 8;
                return 0;
            }
        }
    }
    return self->unk8->unk4 == 1;
}

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

extern "C" SA121_O* func_00121E40(SA121_S* self, char* name, int flags) {
    SA121_O* o = 0;
    int buf[16];
    int r;
    func_00121B18(self);
    if (flags & 4) {
        r = func_002F7A90(self->unk4, name);
        buf[4] = 0;
    } else {
        r = func_002F7750(self->unk4, name, buf);
    }
    if (r) {
        self->unk24 = 8;
        return 0;
    }
    int n = func_00121B18(self);
    if (n >= 0) {
        o = (SA121_O*)func_00122460_4(operator_new(0x5C), n, self, 0);
    }
    if (o) {
        strcpy((char*)o + 0x18, name);
        o->unk4E = flags;
        o->unk50 = 0;
        o->unk48 = buf[4];
    }
    return o;
}

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
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" int func_001224F0(void) {
    return 1;
}

struct S1224F8 { char pad0[0x48]; int unk48; int pad4C; int unk50; };

extern "C" int func_001224F8(S1224F8* self, int a, int op) {
    switch (op) {
    case 0:
        self->unk50 = a;
        break;
    case 1:
        self->unk50 += a;
        break;
    case 2:
        self->unk50 = self->unk48 - a;
        break;
    }
    return self->unk50;
}

extern "C" int func_00122550(void) {
    return 1;
}

struct T122558 { char pad0[4]; int unk4; char pad8[0x1C]; int unk24; };
struct S122558 { char pad0[0x18]; char unk18[1]; char pad19[0x2F]; int unk48; char pad4C[4]; int unk50; char pad54[4]; T122558* unk58; };

extern "C" int func_00122558(S122558* self, int a, int b) {
    func_00121B18((SA121_S*)self->unk58);
    if (func_002F7970(self->unk58->unk4, self->unk18, a, self->unk50, b)) {
        self->unk58->unk24 = 8;
        return 0;
    }
    int t = func_00121B18((SA121_S*)self->unk58);
    if (t > 0) self->unk50 = self->unk50 + t;
    int u = self->unk50;
    if (self->unk48 < u) self->unk48 = u;
    return t;
}

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
        Heap_Free(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1210C8", func_00122700);

extern "C" void func_00122770(void) {
    D_00372AC0 = 0;
}

extern "C" int func_00122778(int n, char* out) {
    int k = 0;
    int i;
    for (i = 0; i < D_00376E88[n].cnt; i++) {
        int v = D_00376E88[n].v[i];
        int c = v & 0xFFFF;
        if (v < 0) {
            switch (c) {
            case 0x3A:
                out[k] = 0x1B;
                break;
            case 0x3B:
                out[k] = 0x1C;
                break;
            case 0x3C:
                out[k] = 0x1D;
                break;
            case 0x3D:
                out[k] = 0x1E;
                break;
            case 0x4F:
                out[k] = 0x15;
                break;
            case 0x50:
                out[k] = 0x14;
                break;
            case 0x51:
                out[k] = 0x17;
                break;
            case 0x52:
                out[k] = 0x16;
                break;
            case 0x3E:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
            case 0x4D:
            case 0x4E:
            default:
                continue;
            }
        } else {
            if (c == 10) {
                out[k] = 0x19;
            } else if (c == 9) {
                continue;
            } else if (c == 8) {
                out[k] = 0x18;
            } else if (c == 0x1B) {
                out[k] = 0x1A;
            } else {
                out[k] = c;
            }
        }
        k++;
    }
    return k;
}

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
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" float func_00122FF8(char* p) {
    float* q = (float*)(p + 4);
    return q[3] / q[4];
}

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
