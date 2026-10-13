#include "common.h"

extern "C" {
void func_0027E1E8(void *, int);
int func_0027D870(int, int, int *, int);
int func_001150B8(int);
int func_0027CC30(int, int, int, int *);
void func_0027F1E0(int, int, int);
void func_002798B8(int);
void func_0013D100(int);
}

struct S0027EB70 {
    char pad[0x2];
    u8 unk2;
};

struct S0027E348 {
    int unk0;
    int unk4;
    int unk8;
};

struct S0027E698 {
    char pad[0x1];
    u8 unk1;
    u8 unk2;
    char pad1[0x1];
    int unk4;
    int unk8;
};

struct S0027EDB8 {
    char pad[0x4];
    int unk4;
    union {
        int v;
        int* a;
        float f;
        float* fa;
    } unk8;
};

struct S27EF20 {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    int unk4;
    int *unk8;
};

extern "C" int func_0027D828(int a, int b) {
    int out;
    int r;
    if (func_0027CC30(a, b, 3, &out) != 0) {
        r = out;
    } else {
        func_0027F1E0(a, 0, 1);
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027D870);

extern "C" void func_0027DC58(int a, int b, int *c, int d) {
    int out;
    int k = func_001150B8(b);
    out = 0;
    func_0027D870(a, k, &out, d);
    *c = out;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DCB8);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DD38);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DD88);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027DF00);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E090);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E160);

struct S27E180_N {
    char pad0[0xC];
    S27E180_N *unkC;
};
struct S27E180 {
    char pad0[4];
    char *unk4;
};
extern "C" void func_0027E180(S27E180 *p, int n) {
    if (p->unk4 != 0) {
        p->unk4 = p->unk4 + n;
    }
    S27E180_N *c = (S27E180_N *)p->unk4;
    if (c != 0) {
        do {
            func_0027E1E8(c, n);
            c = c->unkC;
        } while (c != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E1E8);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E288);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E300);

extern "C" void func_0027E348(S0027E348* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E358);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E410);

extern "C" S0027E348 *func_0027E488(S0027E348 *p) {
    func_0027E348(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E690);

extern "C" S0027E698* func_0027E698(S0027E698* p) {
    p->unk2 = 0;
    p->unk8 = 0;
    p->unk4 = 0;
    p->unk1 = 0;
    return p;
}

extern "C" void func_0027E6B0(int a, int b) {
    func_002798B8(a);
    if (b & 1) {
        func_0013D100(a);
    }
}

extern "C" int func_0027E6F8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E700);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E760);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E820);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027E9D8);

extern "C" void func_0027EB70(S0027EB70* p, u8 v) {
    p->unk2 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027EB78);

extern "C" void func_0027EDB8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EDE0(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE08(S0027EDB8* p, int i, float v) {
    if (p->unk4 == 1) {
        p->unk8.f = v;
    } else {
        p->unk8.fa[i] = v;
    }
}

extern "C" void func_0027EE30(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE58(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EE80(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EEA8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EED0(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" void func_0027EEF8(S0027EDB8* p, int i, int v) {
    if (p->unk4 == 1) {
        p->unk8.v = v;
    } else {
        p->unk8.a[i] = v;
    }
}

extern "C" int func_0027EF20(S27EF20 *p, int i) {
    if (p->unk2 == 3) {
        if (p->unk4 == 1) {
            return (int)p->unk8;
        }
        return p->unk8[i];
    }
    return 0;
}

extern "C" int func_0027EF60(S27EF20 *p, int i) {
    if (p->unk2 == 3) {
        if (p->unk4 == 1) {
            return (int)p->unk8;
        }
        return p->unk8[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027EFA0);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F008);

extern "C" void func_0027F1E0(int, int, int) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F1E8);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F410);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F610);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F6C8);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F728);

INCLUDE_ASM("asm/nonmatchings/game/t_27D828", func_0027F788);
