// cflags: -funroll-loops
#include "common.h"

struct S285400Obj {
    char pad0[2];
    u8 unk2;
    char pad3[5];
    int unk8;
    int unkC;
};

struct S285400Tmp {
    u32 lo : 8;
    u32 f8 : 1;
    u32 f9 : 7;
    u32 hi : 16;
    int unk4;
    int unk8;
    int unkC;
};

struct S00285A10 {
    char pad[0x5C];
    int unk5C;
    int unk60;
};

struct S285A60 {
    char pad0[4];
    int unk4;
    char pad8[0x54];
    S285A60 *unk5C;
    S285A60 *unk60;
};

struct S285828 {
    char pad0[4];
    int unk4;
    int unk8;
    u16 unkC;
    char padE[2];
    int unk10;
    char pad14[0x48];
    S285828 *unk5C;
};

extern "C" {
int func_002899A8(void);
void func_00285A30(int, int);
S00285A10 *func_00285A10(S00285A10 *);
int func_00288000(int, int);
extern struct S285A60 *D_00371348;
u8 *func_00283A08(u8 *);
extern struct S285A60 *D_00371344;
void func_00287F50(int);
extern int D_0037134C;
S285400Obj *func_00275A40(void);
S285400Tmp *func_001D0900(int, int);
u8 *func_00286A68(u8 *, int, S285400Tmp *);
u8 *func_002863A0(u8 *, int, S285400Tmp *);
void func_0025C5E8(S285400Tmp *);
int func_0027AA70(int);
int func_001287F0(int, int);
int func_0027E698(void *);
void *func_00138790(int, int);
u8 *func_00284F20(int, u8 *, int);
u8 *func_00283EF8(int, u8 *, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002848B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00284F20);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002851C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285400);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002855B0);

GP_DATA(D_00371344);
extern "C" S285828 *func_00285828(int a, int b, int c) {
    int t = func_002899A8();
    S285828 *n = (S285828 *)D_00371344;
    if (n != 0) {
        do {
            if (n->unk8 == a && n->unk10 == b && n->unkC == c) {
                if (n->unk4 == t) {
                    return n;
                }
                if (n->unk4 == 0) {
                    return n;
                }
            }
            n = n->unk5C;
        } while (n != 0);
    }
    return 0;
}

GP_DATA(D_0037134C);
GP_DATA(D_00371348);
GP_DATA(D_00371344);
extern "C" S285A60 *func_002858C0(void) {
    S285A60 *p;
    if (D_0037134C >= 0x64) {
        S285A60 *n = D_00371348->unk60;
        if (D_00371348) {
            func_00285A30((int)D_00371348, 3);
        }
        D_00371348 = n;
        if (n) {
            n->unk5C = 0;
        }
    }
    p = (S285A60 *)func_00285A10((S00285A10 *)func_00288000(0x64, 1));
    p->unk60 = 0;
    p->unk5C = D_00371344;
    if (D_00371344) {
        D_00371344->unk60 = p;
    } else {
        D_00371348 = p;
    }
    D_00371344 = p;
    return p;
}

extern "C" u8 *func_00285948(u8 *p, u32 v) {
    *p = v;
    p++;
    *p = v >> 8;
    p++;
    *p = v >> 16;
    p++;
    *p = v >> 24;
    return p + 1;
}

extern "C" u8 *func_00285978(u8 *p, f32 f) {
    union { f32 f; u32 u; } v;
    v.f = f;
    *p = v.u;
    p++;
    *p = v.u >> 8;
    p++;
    *p = v.u >> 16;
    p++;
    *p = v.u >> 24;
    return p + 1;
}

extern "C" u8* func_002859B0(u8* p, u16 v) {
    *p++ = v;
    *p++ = v >> 8;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002859D0);

GP_DATA(D_0037134C);
extern "C" S00285A10* func_00285A10(S00285A10* p) {
    p->unk5C = 0;
    p->unk60 = 0;
    D_0037134C++;
    return p;
}

extern "C" void func_00285A30(int a, int b) {
    D_0037134C -= 1;
    if (b & 1) {
        func_00287F50(a);
    }
}

GP_DATA(D_00371344);
extern "C" void func_00285A60(int a) {
    S285A60 *p = D_00371344;
    if (p) {
        do {
            if (p->unk4 == a) {
                p->unk4 = 0;
            }
            p = p->unk5C;
        } while (p);
    }
}

struct S285A90 {
    char pad0[0xC];
    u16 unkC;
    char pad0E[8];
    u8 unk16[1];
};
extern "C" void func_00285A90(S285A90 *p) {
    u8 i = 0;
    if (p->unkC != 0) {
        do {
            p->unk16[i] = i;
            i++;
        } while (i < p->unkC);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00285C90);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286108);

extern "C" u8 *func_00286160(u8 *p) {
    while (*p != 0x24) {
        p = func_00283A08(p);
    }
    p = func_00283A08(p);
    if (*p == 2) {
        p = func_00283A08(p);
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002861D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286270);

extern "C" int func_00286330(u8 *end, u8 *p) {
    while (*p != '$') {
        if (p == end)
            return 1;
        p = func_00283A08(p);
    }
    return p == end;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_00286398);

INCLUDE_ASM("asm/nonmatchings/game/t_2848B0", func_002863A0);
