// cflags: -funroll-loops
#include "common.h"

struct S29B510_H {
    char pad0[0x21C];
    int unk21C;
};
struct S29B510_N {
    char pad0[0xC];
    S29B510_N *unkC;
    S29B510_N *unk10;
};
struct S29B510_O {
    char pad0[0x30B0];
    S29B510_N unk30B0;
    char pad30C4[0x60];
    int unk3124;
    int unk3128;
    u16 unk312C;
    char pad312E[0x1E];
    void *unk314C;
    int unk3150;
};
struct S29B510_P {
    char pad0[0x1864];
    int unk1864;
    int unk1868;
    char pad186C[0xA70];
    S29B510_N unk22DC;
};

extern "C" {
S29B510_O *func_0029E578(int, int);
int func_00299E18(void *);
int func_0011EF10(void);
void func_001194B8(S29B510_H *);
void func_00119490(S29B510_H *, int);
extern S29B510_H *D_00368A38_p asm("D_00368A38");
extern int D_00368A38;
int Heap_Alloc(int, int, int, int);
int func_00118F20_h(S29B510_H *, int, int, int) asm("Heap_Alloc");
void func_00296DE0(int, int, int, int, int, int);
void *memset(void *, int, int);
}

struct S0029BDA0 {
    char pad[0x3138];
    u32 unk3138;
    u32 unk313C;
};

struct S29AA58 {
    int unk0;
    char unk4[0x28];
    int unk2C;
    int unk30;
    int unk34;
};
extern "C" S29AA58 *func_0029AA58(S29AA58 *p) {
    memset(p->unk4, 0, 0x28);
    p->unk0 = 0x3E8;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    return p;
}

struct S29AA_R {
    int unk0;
    int v[10];
    int unk2C;
};

extern "C" void func_0029AAA0(S29AA_R *r, int x) {
    int sum = 0;
    int n = 0;
    r->v[r->unk2C] = x;
    r->unk2C = (u32)(r->unk2C + 1) % 10;
    for (int i = 0; i < 10; i++) {
        if (r->v[i]) {
            sum += r->v[i];
            n++;
        }
    }
    if (n > 0)
        r->unk0 = sum / n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029ABB8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029AFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B258);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B468);

extern "C" S29B510_O *func_0029B510(S29B510_P *p, int a, u16 b, int c) {
    S29B510_O *o = 0;
    func_00119490(D_00368A38_p, D_00368A38_p->unk21C);
    if (p->unk1864 < p->unk1868) {
        o = func_0029E578(func_00118F20_h(D_00368A38_p, 0x3164, 1, 0), c);
        o->unk3128 = a;
        o->unk312C = b;
        o->unk3124 = func_00299E18(p);
        o->unk314C = p;
        o->unk3150 = func_0011EF10();
        S29B510_N *n = &o->unk30B0;
        S29B510_N *h = &p->unk22DC;
        n->unk10 = h->unk10;
        n->unkC = h;
        h->unk10->unkC = n;
        h->unk10 = n;
    }
    func_001194B8(D_00368A38_p);
    return o;
}

extern "C" void func_0029B5F8(int a, u8 b, u16 c, int d, u8 e, s8 f) {
    func_00296DE0(Heap_Alloc(D_00368A38, 0x14, 1, 0), b, c, d, e, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B680);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BB28);

extern "C" int func_0029BDA0(void* a, S0029BDA0* p) {
    return p->unk313C > p->unk3138;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BF58);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029C1C0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029C4C0);
