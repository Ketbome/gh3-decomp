#include "common.h"

struct S_0011C0B8 { char pad0[0x4]; int unk4; };

struct S_0011C2E8_b { struct S_0011C2E8_b* unk0; };
struct S_0011C2E8 { char pad0[0x10]; int unk10; S_0011C2E8_b* unk14; };

struct S_0011C090 { char pad0[0x4]; int unk4; int unk8; };

struct SA11A_N {
    SA11A_N* unk0;
};

struct SA11A_P {
    char pad0[0x10];
    int unk10;
    SA11A_N* unk14;
    char pad18[0x40];
    int unk58;
};

struct SA11A_B {
    int unk0;
    int unk4;
    u16 unk8;
    char padA[0x6];
    u8 unk10[1];
};

struct SA11A_L {
    char pad0[0xC];
    SA11A_L* unkC;
    SA11A_L* unk10;
    void* unk14;
};

extern "C" {
extern int D_00368A98;
unsigned int func_0011A8A8(int, void*);
int func_0011A8A8_1(int) __asm__("func_0011A8A8");
void func_0011B468_v(void) __asm__("func_0011B468");
int func_0030AA88();
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00338968[];
extern u8 D_003388C0[];
void func_00119400(int, void*);
void* func_00118F20(int, int, int, int);
int func_0011C470(u32);
int func_0011C130(int, int, int, void*, int, int);
extern u8 D_00338A78[];
extern int D_00368A94;
extern int D_00368B40[2];
void func_0011AB60(void);
extern int D_0032A4A0[];
}

struct S_0011AF08 { char pad0[0xC]; int unkC; };

GP_DATA(D_00368A94);
extern "C" void func_0011AEB0(void) {
    D_00368A94--;
}

extern "C" int func_0011AEC0(void) {
    return D_0032A4A0[D_00368A94];
}

extern "C" void func_0011AEE0(void) {
}

extern "C" void func_0011AEE8(void) {
}

extern "C" int func_0011AEF0(void) {
    return 0;
}

extern "C" int func_0011AEF8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011AF00);

extern "C" int func_0011AF08(S_0011AF08* self) {
    return self->unkC;
}

extern "C" int func_0011AF10(void) {
    return 0;
}

extern "C" int func_0011AF18(void) {
    return 0;
}

extern "C" int func_0011AF20(void) {
    return 0;
}

extern "C" int func_0011AF28(void) {
    return 0;
}

extern "C" void func_0011AF30(SA11A_L* self, int flags) {
    self->unk14 = D_00338968;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_0011AF90(SA11A_L* self, int flags) {
    self->unk14 = D_00338968;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_0011AFF0(void* self, int flags) {
    ((void**)self)[2] = D_003388C0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011B030);

struct N11B468 { N11B468* unk0; char pad4[4]; unsigned int unk8; };
struct L11B468 { char pad0[0x1C]; N11B468* unk1C; };
struct S11B468 { char pad0[0x34]; int unk34; char pad38[8]; L11B468* unk40; };

extern "C" unsigned int func_0011B468(S11B468* self) {
    N11B468* n = self->unk40->unk1C;
    unsigned int m = 0;
    if (n) {
        do {
            unsigned int v = n->unk8;
            n = n->unk0;
            m = (v >= m) ? v : m;
        } while (n);
    }
    unsigned int r = func_0011A8A8(self->unk34, n);
    return (m >= r) ? m : r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011B4C0);

extern "C" void func_0011BA28(void) {
    func_0011B468_v();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BA48);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BB28);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BC38);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BD30);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011BD98);

struct N_0011BF98 { N_0011BF98* unk0; int unk4; int unk8; int unkC; };
struct H_0011BF98 { char pad0[0x1C]; N_0011BF98* unk1C; };
struct S_0011BF98 { char pad0[0x40]; H_0011BF98* unk40; };

extern "C" void func_0011BF98(S_0011BF98* self, int m) {
    int again;
    do {
        again = 0;
        for (N_0011BF98* n = self->unk40->unk1C; n; n = n->unk0) {
            int t = D_00368A98 + n->unk8 + n->unkC;
            if (t % m) {
                char* p = (char*)n + t;
                int g = D_00368A38[0];
                func_00119400(g, p + (D_00368A98 + *(int*)(p + 0xC)));
                again = 1;
                break;
            }
        }
    } while (again);
}

extern "C" int func_0011C030(S11B468* self) {
    int r = func_0011A8A8_1(self->unk34);
    N11B468* n = self->unk40->unk1C;
    if (n) {
        do {
            int v = n->unk8;
            n = n->unk0;
            r += D_00368A98 + v;
        } while (n);
    }
    return r;
}

extern "C" S_0011C090* func_0011C090(S_0011C090* self, int n) {
    int v = self->unk4 + n;
    self->unk4 = v;
    if (self->unk8 < v) self->unk8 = v;
    return self;
}

extern "C" S_0011C0B8* func_0011C0B8(S_0011C0B8* self, int v) {
    self->unk4 -= v;
    return self;
}

extern "C" void func_0011C0D0(void) {
    func_0011AB60();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C0F0);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C130);

struct S11C248 { void* unk0; char pad4[0x68]; int unk6C; };

extern "C" void func_0011C248(S11C248* self, int flags) {
    if (self->unk6C) {
        void* p = self->unk0;
        if (p) func_00119400(D_00368A38[0], p);
    }
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" SA11A_N* func_0011C2A8(SA11A_P* self, int unused) {
    if (self->unk14) {
        SA11A_N* n;
        self->unk10++;
        if (self->unk58 < self->unk10) {
            self->unk58 = self->unk10;
        }
        n = self->unk14;
        self->unk14 = n->unk0;
        return n;
    }
    return 0;
}

extern "C" void func_0011C2E8(S_0011C2E8* self, S_0011C2E8_b* n) {
    self->unk10--;
    n->unk0 = self->unk14;
    self->unk14 = n;
}

extern "C" void func_0011C308(void) {
}

GP_DATA(D_00368B40);
extern "C" void func_0011C310(u32 idx, int b) {
    if (idx < 2) {
        int* slot = &D_00368B40[idx];
        int o = (int)func_00118F20(D_00368A38[0], 0x70, 1, 0);
        *slot = func_0011C130(o, func_0011C470(idx), b, D_00338A78, 1, 0);
    }
}

GP_DATA(D_00368B40);
extern "C" void* func_0011C3A8(int i) {
    SA11A_P* q = (SA11A_P*)D_00368B40[i];
    if (q) {
        return func_0011C2A8(q, 1);
    }
    return func_00118F20(D_00368A38[0], func_0011C470(i), 1, 0);
}

extern "C" void func_0011C408(int i, S_0011C2E8_b* p) {
    if (D_00368B40[i]) {
        func_0011C2E8((S_0011C2E8*)D_00368B40[i], p);
    } else if (p) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" int func_0011C458(int i) {
    return D_00368B40[i];
}

extern "C" int func_0011C470(u32 v) {
    if (v < 2) return 12;
    return 0;
}

extern "C" u8* func_0011C480(SA11A_B* self, int align) {
    int size = self->unk0;
    u8* p = self->unk10;
    if (self->unk4) {
        size = self->unk4;
    }
    p += self->unk8;
    size = (size + 3) & ~3;
    if (align) {
        p = (u8*)(((u32)p + 15) & 0xFFFFFFF0);
    }
    return p + size;
}

extern "C" int func_0011C4C0(int base) {
    return base + ((func_0030AA88() + 0x10) & ~0xF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011C4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011CCC8);

INCLUDE_ASM("asm/nonmatchings/game/t_11AEB0", func_0011CE00);
