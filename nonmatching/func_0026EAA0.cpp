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

struct S26E008 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10[1];
};

extern "C" {
void func_0030B550(char *, const char *, ...);
extern char D_00358958[];
void *func_0011DF78(char *, int, int, int);
int func_0011DB60(void *);
int func_0011DBB8(void *, void *, int, int);
int func_0011E008(void *);
int func_001150B8(void);
int func_0026DCA0(int);
void func_00277378_i(int, int) asm("func_00277378");
extern int *D_00370CBC;
extern int D_004278B0[];
int func_0026E008(void *, int);
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
void func_0026E1B0(int, int);
extern int D_00370C18;
void func_00273070(void);
int func_0026E5C8(int, int);
extern int D_00370CB8;
struct S26D_Blk {
    int key;
    int size;
};
extern S26D_Blk D_0041B560;
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

struct S26DD48_T {
    int unk0;
    char pad[0x7C];
};
struct S26DD48 {
    char pad0[0x1C];
    int unk1C;
};
extern S26DD48_T D_003A44B0[];
extern "C" int func_0026ABB0(void);
extern "C" int func_0026AD48(int, int);

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

extern "C" int func_0026E008(void *vp, int key) {
    S26E008 *p = (S26E008 *)vp;
    char buf[256];
    func_0030B550(buf, D_00358958, key);
    void *h = func_0011DF78(buf, 1, 0x64, 0);
    if (h != 0) {
        int n = func_0011DB60(h);
        p->unk4 = n;
        if (n >= 0x1000) {
            func_0011E008(h);
            return 0;
        }
        func_0011DBB8(h, p->unk10, 1, n);
        func_0011E008(h);
        p->unk0 = key;
        return 1;
    }
    return 0;
}

extern "C" int func_0026E0B8(int *p) {
    if (*p) {
        func_0026DFE8((S0026DFE8 *)p);
        return 1;
    }
    return 0;
}

extern "C" S26D_Ent *func_0026E0E8(int k) {
    for (int i = 0; i < 1; i++) {
        if (D_003A34A0[i].key == 0) {
            if (func_0026E008(&D_003A34A0[i], k))
                return &D_003A34A0[i];
            return 0;
        }
    }
    return 0;
}

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

extern "C" void func_0026E1B0(int a, int b) {
    if (b == 0xFFFF) {
        if (a != 0) {
            for (int i = 0; i < 1; i++)
                func_0026DFC0((S0026DFE8 *)&D_003A34A0[i]);
        }
    }
}

extern "C" void func_0026E1E8(void) {
    func_0026E1B0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E208);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E470);

GP_DATA(D_00370CBC);
extern "C" void func_0026E560(int a) {
    int t = func_001150B8();
    if (func_0026DCA0(t) != 0) {
        func_00277378_i(t, a);
        if (D_00370CBC < D_004278B0) {
            *D_00370CBC++ = t;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E638);

GP_DATA(D_00370CB8);
extern "C" void func_0026E890(int a) {
    D_00370CB8 = func_0026E5C8(D_00370CB8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E8B8);

extern "C" S26D_Blk *func_0026EAA0(void) {
    int key = func_001150B8();
    int end = D_00370CB8;
    for (S26D_Blk *p = &D_0041B560; (int)p != end; p = (S26D_Blk *)((char *)p + (p->size * 4 + 8))) {
        if (p->key == key)
            return p;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EB08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EC08);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026ED98);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EED8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026F158);
