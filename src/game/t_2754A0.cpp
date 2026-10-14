// cflags: -funroll-loops
#include "common.h"

struct S002754A0 {
    char pad[0x4];
    int unk4;
    char pad1[0xF0];
    int unkF8;
    int unkFC;
};

struct S2754A0_A {
    char pad0[0x1];
    u8 unk1;
    char pad2[0x2];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct S2754A0_B {
    char pad0[0x4];
    int unk4;
    char pad8[0x8];
    S2754A0_B *unk10;
};

struct S2754A0_C {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 6;
    u32 b16 : 8;
    u32 b24 : 8;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct S2754A0_D {
    u32 unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    S2754A0_D *unk14;
};

struct S2754A0_E {
    u32 lo : 9;
    u32 f : 7;
    u32 hi : 16;
};
struct S2754A0_F {
    int unk0;
    int unk4;
    int unk8;
    int *unkC;
};

extern "C" {
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
char *func_0011A380(int);
void func_0030A2F4(char *, char *, int);
unsigned int strlen(const char *);
void memset(void *, int, int);
extern int D_00368744;
extern char D_7000100[];
extern char *D_00371170;
extern char *D_00371178;
extern char *D_0037117C;
extern char *D_00371180;
extern int D_00368A38;
void *Heap_Alloc(int, int, int, int);
void *func_0011C130(void *, int, int, int, int, int);
extern void *D_003715C0[] __attribute__((section(".sdata")));
extern int D_003715C8[] __attribute__((section(".sdata")));
extern int D_003715D0;
extern void *D_00370FC0[] __attribute__((section(".sdata")));
extern int D_00370FC8[] __attribute__((section(".sdata")));
extern int D_00370FD0;
extern void *D_00371288[] __attribute__((section(".sdata")));
extern int D_00371290[] __attribute__((section(".sdata")));
extern int D_00371298;
extern void *D_00371088[] __attribute__((section(".sdata")));
extern int D_00371090[] __attribute__((section(".sdata")));
extern int D_00371098;
extern void *D_00371470[] __attribute__((section(".sdata")));
extern int D_00371478[] __attribute__((section(".sdata")));
extern int D_00371480;
extern void *D_00371330[] __attribute__((section(".sdata")));
extern int D_00371338[] __attribute__((section(".sdata")));
extern int D_00371340;
extern int D_003710A0;
extern char D_00359058[];
void func_0011A470(void);
S2754A0_F *func_00275A40(int);
int func_001150B8(int);
void func_00277378(int, int);
void func_00275DE0(void);
void func_00275F08(int, int);
void func_00276110(void);
void func_002762F0(void);
void func_002763E0(void);
void func_002764E8(void);
void func_00276600(int, int);
void func_00276D68(int, int *, int);
void func_00275868(S2754A0_C *);
S2754A0_B *func_002759F8(S2754A0_B *);
extern S2754A0_B **D_003710A4;
extern S2754A0_D *D_003710B4;
extern f32 D_00370F48;
extern int D_00370F40;
extern int D_00370F44;
void func_00275540(void);
int func_00275570(void);
void func_0011ED28(f32);
int func_0011EF10(void);
int func_003174C0(f32);
S2754A0_F *func_00276720(int, int);
}

extern "C" void func_002754A0(S002754A0* p, int v) {
    p->unkF8 = v;
    p->unkFC = 0;
}

extern "C" void func_002754B0(S002754A0* p) {
    p->unk4 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002754C0);

extern "C" void func_00275510(f32 f) {
    func_00275540();
    D_00370F48 = f;
    func_0011ED28(f);
}

GP_DATA(D_00370F40);
GP_DATA(D_00370F44);
extern "C" void func_00275540(void) {
    D_00370F40 += func_00275570();
    D_00370F44 = func_0011EF10();
}

GP_DATA(D_00370F48);
extern "C" int func_00275570(void) {
    u32 start = D_00370F44;
    return func_003174C0(D_00370F48 * (f32)(u32)(func_0011EF10() - start));
}

extern "C" void* func_002755E0(void) {
    return D_00359058;
}

extern "C" S2754A0_A *func_002755F0(S2754A0_A *p) {
    p->unk1 = 0;
    p->unk4 = p->unk8 = p->unkC = 0.0f;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275610);

extern "C" S2754A0_A *func_00275648(S2754A0_A *p) {
    p->unk1 = 0;
    p->unk4 = p->unk8 = 0.0f;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275660);

extern "C" int func_00275688(void) {
    return 0;
}

extern "C" int func_00275690(void) {
    return 0;
}

extern "C" void func_00275698(void) {
}

extern "C" void func_002756A0(void) {
}

extern "C" char *StrDupHeap5(char *s) {
    int h = D_00368A38;
    func_00119490(h, func_00119610(h, 5));
    int n = strlen(s) + 1;
    char *d = func_0011A380(n);
    func_0030A2F4(d, s, n);
    func_001194B8(D_00368A38);
    return d;
}

extern "C" void func_00275730(void) {
    func_0011A470();
}

extern "C" int func_00275750(u32 *p) {
    u32 v = *p & 0xFE00;
    if (v == 0x2800 || v == 0x2A00) {
        return 1;
    }
    return 0;
}

extern "C" void func_00275780(S2754A0_E *p) {
    switch (p->f) {
    case 10:
        p->f = 20;
        break;
    case 12:
        p->f = 21;
        break;
    }
}

extern "C" void func_002757D8(S2754A0_E *p) {
    switch (p->f) {
    case 20:
        p->f = 10;
        break;
    case 21:
        p->f = 12;
        break;
    }
}

extern "C" S2754A0_F *func_00275830(S2754A0_F *p) {
    p->unk0 &= ~0x400;
    func_00275868((S2754A0_C *)p);
    return p;
}

extern "C" void func_00275868(S2754A0_C *p) {
    p->unk8 = 0;
    p->unk4 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->b8 = 0;
    p->b9 = 0;
    p->b16 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275898);

GP_DATA(D_003710A4);
extern "C" void func_002758A0(void) {
    D_003710A4 = (S2754A0_B **)func_0011A380(0x20000);
    for (int i = 0; i < 0x8000; i++) D_003710A4[i] = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275978);

GP_DATA(D_003710A4);
extern "C" void func_00275988(S2754A0_B *p) {
    S2754A0_B **t = D_003710A4;
    int i = p->unk4 & 0x7FFF;
    S2754A0_B *prev = 0;
    S2754A0_B *n;
    for (n = t[i]; n != 0; n = n->unk10) {
        if (n == p) {
            if (prev) {
                prev->unk10 = n->unk10;
            } else {
                t[i] = n->unk10;
            }
            n->unk10 = 0;
            return;
        }
        prev = n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002759E8);

extern "C" void func_002759F0(int v) {
    D_003710A0 = v;
}

extern "C" S2754A0_B *func_002759F8(S2754A0_B *p) {
    S2754A0_B **t = D_003710A4;
    int i = p->unk4 & 0x7FFF;
    p->unk10 = t[i];
    t[i] = p;
    return p;
}

extern "C" S2754A0_F *func_00275A20(int a) {
    return func_00275A40(a);
}

extern "C" S2754A0_F *func_00275A40(int a) {
    S2754A0_F *p = func_00275830(func_00276720(0x14, 1));
    p->unk4 = a;
    p->unk0 |= 0x100;
    return (S2754A0_F *)func_002759F8((S2754A0_B *)p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275A90);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275CE8);

extern "C" void func_00275DC0(void) {
    func_00275DE0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275DE0);

extern "C" void func_00275EE8(int a, int b) {
    func_00275F08(a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276008);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002760D8);

extern "C" void func_002760E0(void) {
    func_00276110();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276100);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276110);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002761F8);

extern "C" void func_002762D0(void) {
    func_002762F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002762F0);

extern "C" void func_002763C0(void) {
    func_002763E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002763E0);

extern "C" void func_002764C8(void) {
    func_002764E8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002764E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002765D0);

extern "C" void func_002765E0(int a, int b) {
    func_00276600(a, b);
}

extern "C" void func_00276600(int a, int b) {
    func_00275F08(a, b != 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276620);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276668);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276698);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276720);

extern "C" {
void func_0011A558(u32, int, int);
void func_0011A568(void);
void func_001E65C0(int, void *);
void func_001E6668(int, void *);
void func_001E6710(int, void *);
void func_00276E88(int, int);
void func_00276F30(int, int);
void func_00276FD8(int, int);
void func_00277080(int, int);
void func_00277128(int, int);
void func_00276DC8(int, int);
void func_00277298(void);
void func_00292BB0(void);
extern char D_003590E0[];
extern char D_003590F8[];
extern char D_00359108[];
extern char D_00359120[];
extern char D_00371100[];
extern char D_00371108[];
extern char D_00371110[];
extern char D_00371118[];
extern char D_00371120[];
}

extern "C" void func_002767D8(void) {
    func_0011A558(0x9C2B6C4B, 0, 0);
    func_00277298();
    func_0011A568();
    func_00292BB0();
    func_0011A558(0x799B56A8, 0, 0);
    func_00276DC8(0x12C, (int)D_003590E0);
    func_0011A568();
    func_0011A558(0x74943260, 0, 0);
    func_001E65C0(0x9C40, D_003590F8);
    func_0011A568();
    func_0011A558(0xD39D0074, 0, 0);
    func_001E6668(0x2AF8, D_00371100);
    func_0011A568();
    func_0011A558(0x72619F01, 0, 0);
    func_001E6710(0x1F4, D_00371108);
    func_0011A568();
    func_0011A558(0xCF51C40A, 0, 0);
    func_00276E88(0x1F4, (int)D_00371110);
    func_0011A568();
    func_0011A558(0xA7733A02, 0, 0);
    func_00276F30(0x32C8, (int)D_00371118);
    func_0011A568();
    func_0011A558(0x1A376AD7, 0, 0);
    func_00276FD8(0x7D0, (int)D_00359108);
    func_0011A568();
    func_0011A558(0x758E5060, 0, 0);
    func_00277080(0x1A4, (int)D_00371120);
    func_0011A568();
    func_0011A558(0xE02F7469, 0, 0);
    func_00277128(0x64, (int)D_00359120);
    func_0011A568();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002769A8);

struct S2754A0_P {
    int unk0;
    int unk4;
};

extern "C" void func_002769B0(S2754A0_P *p, int n) {
    u32 i = 0;
    if (n) {
        S2754A0_P *q = p;
        do {
            int h = func_001150B8(q->unk0);
            func_00277378(h, q->unk0);
            char *r = (char *)func_00275A40(h);
            r[2] = 8;
            *(int *)(r + 0xC) = q->unk4;
            q++;
            i++;
        } while (i < n);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276BB0);

extern "C" void func_00276D48(int a, int *e, int stride) {
    func_00276D68(a, e, stride);
}

extern "C" void func_00276D68(int a, int *e, int stride) {
    while (*e) {
        S2754A0_F *p = func_00275A20(*e);
        p->unkC = e;
        ((u8 *)p)[2] = 9;
        e = (int *)((char *)e + stride);
    }
}

extern "C" void func_00276DC8(int a, int b) {
    void **slot = &D_003715C0[D_003715D0];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x18, a, b, 1, 0);
    D_003715C8[D_003715D0] = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276E70);

extern "C" void func_00276E88(int a, int b) {
    void **slot = &D_00370FC0[D_00370FD0];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0xC, a, b, 1, 0);
    D_00370FC8[D_00370FD0] = 1;
}

extern "C" void func_00276F30(int a, int b) {
    void **slot = &D_00371288[D_00371298];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0xC, a, b, 1, 0);
    D_00371290[D_00371298] = 1;
}

extern "C" void func_00276FD8(int a, int b) {
    void **slot = &D_00371088[D_00371098];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x14, a, b, 1, 0);
    D_00371090[D_00371098] = 1;
}

extern "C" void func_00277080(int a, int b) {
    void **slot = &D_00371470[D_00371480];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x10C, a, b, 1, 0);
    D_00371478[D_00371480] = 1;
}

extern "C" void func_00277128(int a, int b) {
    void **slot = &D_00371330[D_00371340];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x64, a, b, 1, 0);
    D_00371338[D_00371340] = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002771D0);

extern "C" void func_00277208(void) {
}
TEXT_PAD(16);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277220);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277298);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277368);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277378);
