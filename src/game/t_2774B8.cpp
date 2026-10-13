#include "common.h"

struct S002777B8 {
    char pad[0x8];
    int unk8;
};

extern "C" {
extern char D_003592B0[];
extern char D_003A98E0[];
extern int D_00371188;
void func_0030B550(char *, char *, int);
char *func_002774D8(void);
void func_00278C50(int, int);
int func_00278450(int, int, u8);
void func_00277378(void);
void func_00277540_v(void) asm("func_00277540");
S002777B8* func_0027B300(int, int);
char* func_00278E48(int);
}

extern "C" void func_002774B8(void) {
    func_00277378();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002774D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277538);

GP_DATA(D_00371188);
extern "C" char *func_00277540(int a) {
    char *r = func_002774D8();
    if (r == 0) {
        char *p = &D_003A98E0[D_00371188 * 0x64];
        D_00371188++;
        if (D_00371188 >= 5) {
            D_00371188 = 0;
        }
        func_0030B550(p, D_003592B0, a);
        r = p;
    }
    return r;
}

extern "C" void func_002775B8(void) {
    func_00277540_v();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002775D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002775E8);

extern "C" char* func_002777B8(int a) {
    return func_00278E48(func_0027B300(a, 0)->unk8) + 0x18;
}

struct S2777E0 {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    int unk4;
};
extern "C" int func_002777E0(S2777E0 *p) {
    return func_00278450((int)p + 0xC, p->unk4, p->unk2) + 0xC;
}

struct S277810 {
    char pad0[4];
    S002777B8 *unk4;
};
extern "C" void func_00277810(S277810 *p, int n) {
    S002777B8 *q = (S002777B8 *)((char *)func_0027B300((int)p, 0) + n);
    p->unk4 = q;
    int t = q->unk8 + n;
    q->unk8 = t;
    func_00278C50(t, n);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277860);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002778D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278098);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278450);

struct S2787F0 {
    u32 unk0;
    char pad4[4];
    int unk8;
};
extern "C" {
int func_0027B800(void *);
int func_0027B7D0(void *);
S2787F0 *S2787F0_next(void *, void *) asm("func_0027B300");
int func_002778D8(int);
unsigned int strlen(const char *);
}
extern "C" int func_002787F0(void *self) {
    int a = func_0027B800(self);
    int b = func_0027B7D0(self);
    int n = b - a;
    int t = n * 8 + 4;
    int size = a * 4 + t;
    size += 3;
    size += n;
    size &= ~3u;
    for (S2787F0 *p = S2787F0_next(self, 0); p; p = S2787F0_next(self, p)) {
        switch ((p->unk0 >> 9) & 0x7F) {
        case 6:
            size += 0x10;
            break;
        case 5:
            size += 0xC;
            break;
        case 3:
            size += 1;
            size += strlen((char *)p->unk8);
            size = (size + 3) & ~3u;
            break;
        case 10:
            size += 0x18;
            size += func_002787F0((void *)p->unk8);
            break;
        case 12:
            size += 0xC;
            size += func_002778D8(p->unk8);
            break;
        case 1:
        case 13:
            break;
        }
    }
    return size;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278910);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278C50);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278D78);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278E48);

struct S279118 {
    u16 unk0;
    u8 unk2;
    char pad3[1];
    char unk4[1];
};
struct S279118E {
    char b[8];
};
INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279118);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279150);

struct S2791E0 {
    u32 unk0;
    char pad4[4];
    int unk8;
};
extern "C" {
void S2791E0_f1(int) asm("func_00275730");
void S2791E0_f2(int) asm("func_0025C478");
void S2791E0_f3(int) asm("func_0025C530");
void S2791E0_f4(int) asm("func_0027AC90");
void S2791E0_f5(int) asm("func_00113250");
void S2791E0_f6(int) asm("func_002798B8");
void S2791E0_f7(int, int) asm("func_0027E6B0");
void S2791E0_f8(int) asm("func_0011A470");
void S2791E0_f9(int, int) asm("func_0027E410");
}
extern "C" void func_002791E0(S2791E0 *p) {
    if (p->unk8 == 0) {
        p->unk0 &= 0xFFFF01FF;
    } else {
        switch ((p->unk0 >> 9) & 0x7F) {
        case 3:
            if (p->unk8) {
                S2791E0_f1(p->unk8);
            }
            break;
        case 5:
            if (p->unk8) {
                S2791E0_f2(p->unk8);
            }
            break;
        case 6:
            if (p->unk8) {
                S2791E0_f3(p->unk8);
            }
            break;
        case 10: {
            int o = p->unk8;
            if (o) {
                S2791E0_f4(o);
                S2791E0_f5(o);
            }
            break;
        }
        case 12: {
            int o = p->unk8;
            if (o) {
                S2791E0_f6(o);
                S2791E0_f7(o, 3);
            }
            break;
        }
        case 7:
            if (p->unk8) {
                S2791E0_f8(p->unk8);
            }
            ((u16 *)p)[1] = 0;
            break;
        case 23:
            if (p->unk8) {
                S2791E0_f8(p->unk8);
            }
            break;
        case 27:
            if (p->unk8) {
                S2791E0_f9(p->unk8, 3);
            }
            break;
        case 4:
        case 26:
            break;
        }
        p->unk8 = 0;
        p->unk0 &= 0xFFFF01FF;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279358);
