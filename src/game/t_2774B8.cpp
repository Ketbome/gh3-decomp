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

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002787F0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002791E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279358);
