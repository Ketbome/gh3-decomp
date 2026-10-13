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

struct S27E358_N {
    char pad0[8];
    S27E358_N *unk8;
};
struct S27E358 {
    u32 unk0;
    S27E358_N *unk4;
    int unk8;
};

extern "C" {
void func_00269F08(S268EB8_B *);
void func_0011C408(int, void *);
extern S268EB8_B D_003A3420[4];
int func_002E8A18(int);
int func_0026ABB0(void);
void func_00273B48(int, int);
void func_00273B80(int);
extern int D_00370C50;
void func_00270EE0(void);
int func_00270F08(void);
void func_00268130(int, int);
int func_0026ACB0(int);
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

extern "C" void func_002691B0(int a) {
    int i;
    func_00270EE0();
    i = func_00270F08();
    if (i >= 0) {
        do {
            func_00268130(a, i);
            i = func_00270F08();
        } while (i >= 0);
    }
}

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

extern "C" void func_002694D8(S27E358 *p) {
    char *h = (char *)p->unk4;
    char *n;
    if (h) {
        u32 cnt;
        u32 i;
        n = h;
        cnt = 1 << p->unk0;
        for (i = 0; i < cnt; i++) {
            S27E358_N *m = ((S27E358_N *)n)->unk8;
            while (m) {
                S27E358_N *k = m;
                m = m->unk8;
                func_0011C408(0, k);
            }
            func_00269208((S00269208 *)n);
            n += 0xC;
        }
        p->unk8 = 0;
    }
}

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

extern "C" void func_00269E50(int a, f32 x, f32 y) {
    for (int i = 0; i < 4; i++) {
        if (D_003A3420[i].unk0 == a) {
            D_003A3420[i].unk8 = x;
            D_003A3420[i].unkC = y;
            func_00269F08(&D_003A3420[i]);
        }
    }
}

extern "C" void func_00269F08(S268EB8_B *p) {
    if (p->unk4 != 0) {
        func_002E7F90(p->unk0, p->unk8 * p->unk4->unk4, p->unkC * p->unk4->unk4);
    } else {
        func_002E7F90(p->unk0, p->unk8, p->unkC);
    }
}

extern "C" void func_00269F60(int a) {
    for (int i = 0; i < 4; i++) {
        if (D_003A3420[i].unk0 == a) {
            func_00269F08(&D_003A3420[i]);
        }
    }
}

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

struct S26A660 {
    int unk0;
    int unk4;
    char pad8[0x10];
    int unk18;
};
extern "C" int func_0026A660(int a) {
    S26A660 *p = (S26A660 *)func_0026A368(a);
    int r = 0;
    if (p != 0) {
        int v = func_002E8A18(p->unk0);
        if (p->unk18 != 0) {
            v |= func_002E8A18(p->unk4);
        }
        r = v != 0;
    }
    return r;
}

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

struct S26AC60 {
    char pad0[4];
    int unk4;
    char pad8[8];
    int unk10;
    char pad14[0x68];
    void (*unk7C)(int, int, int);
};
GP_DATA(D_00370C50);
extern "C" void func_0026AC60(S26AC60 *p, int b) {
    if (p->unk7C != 0) {
        p->unk7C(p->unk4, b != 0, 0);
        p->unk7C = 0;
    }
    if (D_00370C50 == p->unk10) {
        D_00370C50 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026ACB0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AD48);

extern "C" int func_0026AE30(int a) {
    while (func_0026ACB0(a) == 0) {
        a++;
    }
    return a;
}

GP_DATA(D_00370C40);
GP_DATA(D_00370C2C);
extern "C" void func_0026AE70(void) {
    if (func_0026ABA8() == 0) {
        D_00370C40 = 0;
        D_00370C2C = 1;
        func_00273B20(1);
    }
}

extern "C" void func_0026AEA8(int a) {
    if (func_0026ABB0() == 0) {
        if (a == -1) {
            func_00273B80(0);
            return;
        }
        func_00273B48(a, 1);
    }
}
