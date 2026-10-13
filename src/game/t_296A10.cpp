#include "common.h"

struct S00297458 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00296A70 {
    int unk0;
    char pad[0x28];
    int unk2C;
    int unk30;
    u8 unk34;
    char pad1[0xB];
    int unk40;
};

struct S00296A48 {
    int unk0;
    struct S00296A48* unk4;
    int unk8;
    struct S00296A48* unkC;
    struct S00296A48* unk10;
    void* unk14;
    int unk18;
};

struct S296A10_N {
    int unk0;
    S296A10_N *unk4;
    S296A10_N *unk8;
    S296A10_N *unkC;
};

struct S296A10_L {
    int unk0;
    S296A10_L *unk4;
    int unk8;
    S296A10_L *unkC;
    S296A10_L *unk10;
    void *unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct S296A10_A {
    int unk0;
    S296A10_A *unk4;
    int unk8;
    S296A10_A *unkC;
    S296A10_A *unk10;
    void *unk14;
    u8 unk18;
    char pad19[0x1];
    u8 unk1A;
    char pad1B[0xD];
    int unk28;
    int unk2C;
};

struct S296A10_B {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    int unk4;
    int unk8;
    int unkC;
    u8 unk10;
    char pad11[0x3];
    int unk14;
    int unk18;
    int unk1C;
    u8 unk20;
};

struct S296A10_C {
    char pad0[0x18];
    void *unk18;
};

extern "C" {
void func_00297CF0(void *);
int func_0030A49C(void *, int, int);
extern char D_0035C330[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void*);
extern char D_0035C4D0[];
extern char D_0035C2E8[];
extern char D_0035C2B0[];
extern char D_0035C390[];
extern char D_0035C378[];
int func_00118F20(int, int, int, int);
extern char D_0035C298[];
extern char D_0035C348[];
extern char D_0035C360[];
}

extern "C" S296A10_A *func_00296A10(S296A10_A *p, int a) {
    p->unk2C = a;
    p->unk4 = p;
    p->unk14 = D_0035C2E8;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk1A = 0;
    p->unk28 = 0;
    p->unk18 = 0;
    return p;
}

extern "C" S00296A48* func_00296A48(S00296A48* p, int b) {
    p->unk18 = b;
    p->unk4 = p;
    p->unk14 = D_0035C330;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    return p;
}

extern "C" S00296A70* func_00296A70(S00296A70* p) {
    p->unk0 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk40 = 0;
    return p;
}

struct S296A90 {
    char pad0[0x2C];
    void *unk2C;
    char pad30[0x10];
    int unk40;
};
extern "C" void func_00296A90(S296A90 *p, int b) {
    if (p->unk2C != 0) {
        if (p->unk40 == 0) {
            func_00119400(D_00368A38[0], p->unk2C);
        }
    }
    if (b & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" S296A10_B *func_00296AF0(S296A10_B *p) {
    p->unk0 = 0;
    p->unk8 = 0x80;
    p->unk1 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk20 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296B28);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296CB8);

struct Sfunc_00296D88 {
    char pad0[4];
    void *unk4;
};
extern "C" void func_00296D88(Sfunc_00296D88 *p, int b) {
    if (p->unk4 != 0) {
        func_00119400(D_00368A38[0], p->unk4);
    }
    if (b & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296DE0);

struct Sfunc_00296EC0 {
    char pad0[4];
    void *unk4;
};
extern "C" void func_00296EC0(Sfunc_00296EC0 *p, int b) {
    if (p->unk4 != 0) {
        func_00119400(D_00368A38[0], p->unk4);
    }
    if (b & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

struct S296F18 {
    int unk0;
    u8 unk4;
    char pad5[3];
    u64 unk8;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20[0x200];
    int unk220;
    int unk224;
};
extern "C" S296F18 *func_00296F18(S296F18 *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk220 = 0;
    p->unk224 = 0;
    func_0030A49C(p->unk20, 0, 0x200);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00296F70);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002972F8);

extern "C" void func_002973C0(S296A10_C *p, int flags) {
    p->unk18 = D_0035C2B0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297400);

extern "C" S00297458* func_00297458(S00297458* p) {
    p->unk0 = 0;
    p->unk4 = 5;
    p->unk8 = 0;
    return p;
}

struct S297470 {
    char pad0[8];
    S297470 *unk8;
    int unkC;
};
extern "C" void func_00297470(int a, S297470 *p) {
    S297470 *next;
    if (p != 0) {
        do {
            func_00297470(a, (S297470 *)p->unkC);
            next = p->unk8;
            if (p != 0) {
                func_00297CF0(p);
            }
            p = next;
        } while (p != 0);
    }
}

extern "C" void func_002974D8(S296A10_N *x, S296A10_N **root) {
    S296A10_N *y = x->unkC;
    x->unkC = y->unk8;
    if (y->unk8 != 0) {
        y->unk8->unk4 = x;
    }
    y->unk4 = x->unk4;
    if (x == *root) {
        *root = y;
    } else if (x == x->unk4->unk8) {
        x->unk4->unk8 = y;
    } else {
        x->unk4->unkC = y;
    }
    y->unk8 = x;
    x->unk4 = y;
}

extern "C" void func_00297528(S296A10_N *x, S296A10_N **root) {
    S296A10_N *y = x->unk8;
    x->unk8 = y->unkC;
    if (y->unkC != 0) {
        y->unkC->unk4 = x;
    }
    y->unk4 = x->unk4;
    if (x == *root) {
        *root = y;
    } else if (x == x->unk4->unkC) {
        x->unk4->unkC = y;
    } else {
        x->unk4->unk8 = y;
    }
    y->unkC = x;
    x->unk4 = y;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297578);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002976E8);

extern "C" S296A10_N *RbTreeDecrement(S296A10_N *x) {
    if (x->unk0 == 0 && x->unk4->unk4 == x) {
        x = x->unkC;
    } else if (x->unk8) {
        S296A10_N *y = x->unk8;
        while (y->unkC) {
            y = y->unkC;
        }
        x = y;
    } else {
        S296A10_N *y = x->unk4;
        while (x == y->unk8) {
            x = y;
            y = y->unk4;
        }
        x = y;
    }
    return x;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002978C0);

extern "C" S296A10_N *RbTreeIncrement(S296A10_N *x) {
    if (x->unkC) {
        x = x->unkC;
        while (x->unk8) {
            x = x->unk8;
        }
    } else {
        S296A10_N *y = x->unk4;
        while (x == y->unkC) {
            x = y;
            y = y->unk4;
        }
        if (x->unkC != y) {
            x = y;
        }
    }
    return x;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297A48);

extern "C" int func_00297CC0(int a) {
    return func_00118F20(D_00368A38[0], a, 1, 0);
}

extern "C" void func_00297CF0(void* p) {
    func_00119400(D_00368A38[0], p);
}

extern "C" void func_00297D18(S296A10_L *p, int flags) {
    p->unk14 = D_0035C390;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00297D78(S296A10_L *p, int flags) {
    p->unk14 = D_0035C378;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00297DD8(S296A10_L *p, int flags) {
    p->unk14 = D_0035C360;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00297E38(S296A10_L *p, int flags) {
    p->unk14 = D_0035C348;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00297E98);

extern "C" int func_00297F20(void) {
    return 1;
}

extern "C" int func_00297F28(void) {
    return 1;
}

extern "C" void func_00297F30(S296A10_L *p, int flags) {
    p->unk14 = D_0035C298;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00297F90(S296A10_L *p, int flags) {
    p->unk14 = D_0035C298;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00297FF0(S296A10_L *p, int flags) {
    p->unk14 = D_0035C378;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00298050(S296A10_L *p, int flags) {
    p->unk14 = D_0035C360;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_002980B0(S296A10_L *p, int flags) {
    p->unk14 = D_0035C348;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00298110(S296A10_L *p, int flags) {
    p->unk14 = D_0035C390;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" S296A10_L *func_00298170(S296A10_L *p, int a, int b, int c, int d) {
    p->unk4 = p;
    p->unk8 = d;
    p->unkC = p;
    p->unk10 = p;
    p->unk14 = D_0035C4D0;
    p->unk18 = a;
    p->unk1C = c;
    p->unk20 = b;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002981A0);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002982B8);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298390);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298448);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298558);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_00298858);

INCLUDE_ASM("asm/nonmatchings/game/t_296A10", func_002989C8);
