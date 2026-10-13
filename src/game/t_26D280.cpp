// cflags: -funroll-loops
#include "common.h"

struct S0026DFE8 {
    int unk0;
    int unk4;
};

struct S0026D660 {
    char pad[0xC80];
    int unkC80;
    int unkC84;
    u64 unkC88;
    u64 unkC90;
    char padC98[0x18];
};

struct S26D_Ent {
    int key;
};

extern "C" {
void func_0026AE70(void);
int func_0026ABA8(void);
int func_002741B8(int);
extern int D_00370C08;
int func_00273DE8(void);
extern int D_00370C50;
extern S26D_Ent D_003A34A0[];
extern int D_00370C14;
void func_00273498(void);
int func_0026E0B8(int *);
extern S0026D660 D_003A66F0;
int func_002741F8(int, int);
int func_0026E1B0(int, int);
extern int D_00370C18;
void func_00273070(void);
int func_0026E5C8(int, int);
extern int D_00370CB8;
void func_0026DFE8(S0026DFE8 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D280);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D480);

extern "C" void func_0026D660(u64* a, u64* b) {
    *a = D_003A66F0.unkC88;
    *b = D_003A66F0.unkC90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D680);

GP_DATA(D_00370C18);
extern "C" void func_0026D688(void) {
    if (D_00370C18 == 1) {
        func_00273070();
    }
}

extern "C" void func_0026D6B0(void) {
    func_00273498();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D9F8);

extern "C" int func_0026DAB0(int i) {
    if (func_0026ABA8() != 0) {
        return 0;
    }
    return (&D_003A66F0)[i].unkC80;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DAF8);

extern "C" void func_0026DBD8(int a) {
    if (func_0026ABA8() == 0) {
        if (D_00370C18 != a) {
            func_0026AE70();
        }
        D_00370C18 = a;
    }
}

GP_DATA(D_00370C08);
extern "C" int func_0026DC20(int a) {
    if (func_0026ABA8() != 0) {
        return 0;
    }
    int r = func_002741B8(a);
    D_00370C08 = r;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC60);

GP_DATA(D_00370C50);
extern "C" int func_0026DC68(int a) {
    if (D_00370C50 == a) {
        return 0x20;
    }
    return func_00273DE8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC98);

extern "C" int func_0026DCA0(int a) {
    return func_002741F8(a, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DD48);

extern "C" int func_0026DE20(void) {
    return D_00370C14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DE28);

extern "C" S0026DFE8 *func_0026DFC0(S0026DFE8 *p) {
    func_0026DFE8(p);
    return p;
}

extern "C" void func_0026DFE8(S0026DFE8* p) {
    p->unk0 = 0;
    p->unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DFF8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E008);

extern "C" int func_0026E0B8(int *p) {
    if (*p) {
        func_0026DFE8((S0026DFE8 *)p);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E0E8);

extern "C" S26D_Ent *func_0026E138(int k) {
    for (int i = 0; i < 1; i++) {
        if (D_003A34A0[i].key == k) {
            return &D_003A34A0[i];
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E158);

extern "C" void func_0026E190(int *p) {
    func_0026E0B8(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E1B0);

extern "C" void func_0026E1E8(void) {
    func_0026E1B0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E208);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E470);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E560);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E638);

GP_DATA(D_00370CB8);
extern "C" void func_0026E890(int a) {
    D_00370CB8 = func_0026E5C8(D_00370CB8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E8B8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EAA0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EB08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EC08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026ED98);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EED8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026F158);
