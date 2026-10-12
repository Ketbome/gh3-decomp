// cflags: -funroll-loops
#include "common.h"

struct S00269208 {
    int unk0;
    int unk4;
    int unk8;
};

struct S0026AC08_2 {
    int unk0;
    int unk4;
};

struct S0026AC08 {
    char pad[0x28];
    int unk28;
    int unk2C;
    char pad1[0xC];
    S0026AC08_2 unk3C[1];
};

struct S268EB8_A {
    char pad0[0x24];
    int unk24;
    int unk28;
    int unk2C;
};

struct S268EB8_E {
    int unk0;
    int unk4;
    int unk8;
};

struct S268EB8_R {
    int unk0;
    int unk4;
    char pad8[0x10];
    int unk18;
};

struct S268EB8_F {
    char pad0[0x4];
    f32 unk4;
};

struct S268EB8_B {
    int unk0;
    S268EB8_F *unk4;
    f32 unk8;
    f32 unkC;
};

extern "C" {
extern int D_00372E88;
int func_0026AB60(int, int);
int func_0026ABA8(void);
extern int D_00370C40;
extern int D_00370C2C;
void func_00273B20(int);
extern S268EB8_E D_003A3480[];
void func_002E8A98(int, int);
S268EB8_R *func_0026A368(int);
void func_002E7E80(int, int, int, f32, f32);
void func_002E7F90(int, f32, f32);
int func_0026AC08(S0026AC08 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00268EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00268F40);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002691B0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269200);

extern "C" void func_00269208(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S00269208 *func_00269218(S00269208 *p) {
    func_00269208(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269240);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269420);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002694D8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269590);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002696C8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269780);

extern "C" void func_00269888(int k) {
    for (int i = 0; i < 2; i++) {
        if (D_003A3480[i].unk0 == k) {
            func_002E8A98(D_003A3480[i].unk4, D_003A3480[i].unk8);
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002698C8);

extern "C" void func_00269990(void* p, int v) {
    D_00372E88 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269998);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269B70);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269D38);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269E50);

extern "C" void func_00269F08(S268EB8_B *p) {
    if (p->unk4 != 0) {
        func_002E7F90(p->unk0, p->unk8 * p->unk4->unk4, p->unkC * p->unk4->unk4);
    } else {
        func_002E7F90(p->unk0, p->unk8, p->unkC);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269F60);

extern "C" void func_00269FE0(int a, f32 f, f32 g) {
    S268EB8_R *r = func_0026A368(a);
    if (r != 0) {
        func_002E7E80(r->unk0, r->unk4, r->unk18, f, g);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A030);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A368);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A488);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A5D0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A660);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A6C0);

extern "C" void func_0026A730(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S00269208 *func_0026A740(S00269208 *p) {
    func_0026A730(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A768);

extern "C" void func_0026A948(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S00269208 *func_0026A958(S00269208 *p) {
    func_0026A948(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A980);

extern "C" int func_0026AB60(int a, int b) {
    return 0xFFFF;
}

extern "C" void func_0026AB68(void) {
    func_0026AB60(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AB88);

extern "C" int func_0026ABA8(void) {
    return 1;
}

extern "C" int func_0026ABB0(void) {
    return 1;
}

extern "C" int func_0026ABB8(S268EB8_A *p) {
    if (++p->unk28 >= p->unk2C) {
        if (p->unk24 == 0) {
            return 0;
        }
        p->unk28 = 0;
        p->unk24--;
    }
    return func_0026AC08((S0026AC08 *)p);
}

extern "C" int func_0026AC08(S0026AC08* p) {
    int i = p->unk28;
    if (i < p->unk2C) {
        return p->unk3C[i].unk0;
    }
    return 0;
}

extern "C" int func_0026AC30(S268EB8_A *p) {
    if (p->unk24 != 0) {
        return 0;
    }
    return p->unk28 + 1 >= p->unk2C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AC60);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026ACB0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AD48);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AE30);

GP_DATA(D_00370C40);
GP_DATA(D_00370C2C);
extern "C" void func_0026AE70(void) {
    if (func_0026ABA8() == 0) {
        D_00370C40 = 0;
        D_00370C2C = 1;
        func_00273B20(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AEA8);
