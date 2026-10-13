// cflags: -mno-check-zero-division
#include "common.h"

struct S002965E0 {
    char pad[0x1DC];
    int unk1DC;
};

struct S00296638 {
    char pad[0x24];
    int unk24;
};

struct S002965C0_2 {
    char pad[0x94];
    int unk94;
};

struct S002965C0 {
    char pad[0x20];
    S002965C0_2* unk20;
};

struct S00295048 {
    char pad[0x50000];
    int unk50000;
    int unk50004;
    int unk50008;
};

struct S00296848 {
    char pad[0x1A8];
    int unk1A8;
    char pad1[0x4];
    int unk1B0;
};

struct S00296640_2 {
    char pad[0x10];
    int unk10;
};

struct S00296640 {
    char pad[0x1C];
    S00296640_2* unk1C;
    char pad1[0x4];
    char unk24[0x144];
    u8 unk168;
    char pad2[0x1F];
    u8 unk188;
};

struct S2949F0_E {
    s8 unk0;
    char pad1[0x1F];
};

struct S2949F0_A {
    int unk0;
    char pad4[0x64];
    S2949F0_E unk68[3];
};

struct S2949F0_L {
    int unk0;
    S2949F0_L *unk4;
    int unk8;
    S2949F0_L *unkC;
    S2949F0_L *unk10;
    void *unk14;
    int unk18;
    int unk1C;
    char pad20[0x4];
    u8 unk24;
    char pad25[0x3];
    int unk28;
};

struct S2949F0_C {
    char pad0[0x8];
    int unk8;
};

struct S2949F0_B {
    char pad0[0x1C];
    S2949F0_C *unk1C;
    int *unk20;
};

struct S2949F0_D {
    char pad0[0x4];
    int unk4;
    int unk8;
};

struct S2949F0_F {
    char pad0[0x1C];
    S2949F0_D *unk1C;
    char pad20[0x1B4];
    int unk1D4;
};

struct S2949F0_G {
    int unk0;
    int unk4;
};

struct S2949F0_H {
    char pad0[0x4];
    S2949F0_G unk4[256];
    char pad804[0x10];
    int unk814;
    char pad818[0x4];
    int unk81C;
};

struct S2949F0_P {
    char pad0[0x8];
    int unk8;
};

struct S2949F0_Q {
    char pad0[0x1B0];
    int unk1B0;
};

struct S2949F0_N {
    int unk0;
    u32 unk4;
    int unk8;
    S2949F0_N *unkC;
    S2949F0_N *unk10;
    void *unk14;
};

struct S2949F0_R {
    int unk0;
    S2949F0_N unk4;
    char pad1C[0x8];
    char unk24[0x1B4];
    int unk1D8;
    int unk1DC;
};

struct S295FA8_Big {
    char pad0[0x2418];
    virtual ~S295FA8_Big();
};

struct S296138_N {
    char pad0[4];
    S296138_N *unk4;
    S296138_N *unk8;
    S296138_N *unkC;
};
struct S296138_L {
    char pad0[4];
    S296138_N *unk4;
    int unk8;
};

struct S295140 {
    char pad0[8];
    int unk8;
    int unkC;
    u64 unk10;
    u64 unk18;
};

extern "C" {
extern int D_00370E44;
void func_00293488(int, int *, int *, int *, int *);
void func_002934A8(int, int);
int func_00293530(int, u64, u64, int, int);
void func_00275030(char *);
extern char D_0035C218[];
int func_002952D8(int, int, int, int, int, int, char *, int);
void func_00297E98(void *, int);
void func_00297470(void *, void *);
void func_0029D898(void *);
extern char D_0035C298[];
extern int D_00368A38;
void Heap_Free(int, int);
void func_0029FEF0(void);
extern int D_00371784;
extern int D_00372ED0;
void func_0029FF10(void);
int func_00296798_1(void*) asm("func_00296798");
void func_002965C0_3(void *, int, int *) asm("func_002965C0");
char* func_00296920(void*, int);
void strcpy(void*);
extern char D_00371798[];
extern char D_0035C318[];
extern char D_0035C300[];
extern int D_003717E0;
extern int D_003717E4;
void func_002964D8(int, int);
int func_00113DF0(int, int, int);
int func_00296470(int);
void func_0011DBB8(int, int, int, int);
void func_0011E008(int);
int strcmp(char *, char *);
char *func_0030A970_2(char *, char *) asm("strcpy");
extern char D_0035C280[];
void func_00297400(void *);
void func_0029FEA8(S2949F0_R *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002949F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00294AF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00294C90);

extern "C" int func_00294FD0(S2949F0_P *p) {
    if (p->unk8 != 0) {
        func_0011E008(p->unk8);
        p->unk8 = 0;
    }
    return 1;
}

extern "C" int func_00295010(S2949F0_P *p, int a, int b) {
    func_0011DBB8(p->unk8, a, 1, b);
    return b;
}

extern "C" void func_00295048(S00295048* p) {
    p->unk50008 = 0x50000;
    p->unk50000 = 0;
    p->unk50004 = 0;
}

extern "C" void func_00295060(void) {
}

extern "C" int func_00295068(S00295048 *p, char **out) {
    int n = p->unk50008 - p->unk50004;
    if (n != 0) {
        *out = (char *)p + p->unk50000;
    }
    return n;
}

extern "C" void func_00295098(S00295048 *p, int n) {
    int c = p->unk50004;
    int size = p->unk50008;
    int w = p->unk50000;
    int m = size - c;
    if (n < m) {
        m = n;
    }
    p->unk50004 = c + m;
    p->unk50000 = (w + m) % size;
}

extern "C" int func_002950D8(S00295048 *p, char **out) {
    if (p->unk50004 != 0) {
        *out = (char *)p + (p->unk50000 - p->unk50004 + p->unk50008) % p->unk50008;
    }
    return p->unk50004;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295118);

extern "C" int func_00295140(int, S295140 *a, char *b) {
    int s0, s1, s2, s3;
    int off = a->unk8;
    int want = a->unkC;
    int n = (int)(b + *(int *)(b + 0x50008)) - off;
    if (want < n) {
        n = want;
    }
    int rest = want - n;
    int r;
    func_00293488(D_00370E44 + 0x6F1600, &s0, &s1, &s2, &s3);
    r = func_002952D8((s0 & 0x0FFFFFFF) | 0x20000000, s1, (s2 & 0x0FFFFFFF) | 0x20000000, s3, off, n, b, rest);
    if (r > 0) {
        if (func_00293530(D_00370E44 + 0x6F1600, a->unk10, a->unk18, s0, r) == 0) {
            func_00275030(D_0035C218);
        }
    }
    func_002934A8(D_00370E44 + 0x6F1600, r);
    return r > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295278);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002952D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295408);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295630);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295D40);

GP_DATA(D_00371784);
extern "C" void func_00295DA8(void) {
    D_00371784 = 0;
    D_00372ED0 = 0;
}

GP_DATA(D_003717E0);
GP_DATA(D_003717E4);
extern "C" int func_00295DB8(int a) {
    if (D_003717E0 == 0 && a != 0) {
        D_003717E0 = func_00296470(func_00113DF0(0x1E0, 0, 1));
    }
    D_003717E4++;
    return D_003717E0;
}

extern "C" void func_00295E08(void) {
    if ((u32)D_003717E4 >= 2) {
        D_003717E4--;
    } else {
        if (D_003717E0 != 0) {
            func_002964D8(D_003717E0, 3);
        }
        D_003717E0 = 0;
        D_003717E4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295E50);

extern "C" void func_00295FA8(S2949F0_R *self, char *obj) {
    S2949F0_N *n = (S2949F0_N *)(obj + 0x1808);
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    func_0029D898(obj);
    if (obj) {
        delete (S295FA8_Big *)obj;
    }
    self->unk1D8--;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296028);

extern "C" void func_00296138(char *obj, int b) {
    S296138_L *l = (S296138_L *)(obj + 0x804);
    if (l->unk8 != 0) {
        func_00297470(l, l->unk4->unk4);
        l->unk4->unk8 = l->unk4;
        l->unk4->unk4 = 0;
        l->unk4->unkC = l->unk4;
        l->unk8 = 0;
    }
    func_00297E98(l, 2);
    if (b & 1) {
        Heap_Free(D_00368A38, (int)obj);
    }
}

extern "C" void func_002961C8(S2949F0_H *p, int t) {
    int i;
    int sum = 0;
    for (i = 0; i < 256 && i < p->unk814; i++) {
        if (t - p->unk4[i].unk4 < 1000) {
            sum += p->unk4[i].unk0;
        }
    }
    p->unk81C = sum;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296220);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296280);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296468);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296470);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002964D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296550);

extern "C" void func_00296598(void) {
    func_0029FF10();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002965B8);

extern "C" void func_002965C0(S002965C0* p, int v) {
    p->unk20->unk94 = v;
}

extern "C" int func_002965D0(S002965C0* p) {
    return p->unk20->unk94;
}

extern "C" int func_002965E0(S002965E0* p) {
    return p->unk1DC;
}

extern "C" void func_002965E8(S2949F0_B *p, int v) {
    if (*p->unk20 != v) {
        if (*p->unk20 != 0) {
            p->unk1C->unk8 = 1;
        }
        *p->unk20 = v;
    }
}

extern "C" void func_00296618(char* a) {
    func_00296798_1(a + 0x24);
}

extern "C" int func_00296638(S00296638* p) {
    return p->unk24;
}

extern "C" void func_00296640(S00296640* p) {
    func_00296920(p->unk24, p->unk1C->unk10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296668);

extern "C" void func_00296678(S2949F0_Q *p, char *s) {
    char *q = (char *)p + 0x48;
    if (strcmp(s, q)) {
        func_0030A970_2(q, s);
        p->unk1B0 = 1;
    }
}

extern "C" void func_002966D8(S2949F0_Q *p, char *s) {
    char *q = (char *)p + 0x58;
    if (strcmp(s, q)) {
        func_0030A970_2(q, s);
        p->unk1B0 = 1;
    }
}

struct S296738 {
    char pad0[4];
    char unk4[0x1AC];
    int unk1B0;
};
extern "C" void func_00296738(S296738 *p, char *a) {
    char *s = p->unk4;
    if (strcmp(a, s) != 0) {
        func_0030A970_2(s, a);
        p->unk1B0 = 1;
    }
}

extern "C" void func_00296798(int *p, int v) {
    int old = *p;
    if (old != v) {
        S2949F0_B *o = (S2949F0_B *)D_003717E0;
        if (old != 0) {
            o->unk1C->unk8 = 1;
        }
        *p = v;
        switch (v) {
        case 1:
            func_002965C0_3(o, 0x1068, p);
            break;
        case 2:
        case 4:
            func_002965C0_3(o, 0x61A80, p);
            break;
        case 3:
            func_002965C0_3(o, 0x493E0, p);
            break;
        }
    }
}

extern "C" void func_00296848(S00296848* p, int v) {
    if (p->unk1A8 != v) {
        p->unk1A8 = v;
        p->unk1B0 = 1;
    }
}

extern "C" void func_00296868(S2949F0_Q *p, int i, char *s) {
    char *q = (char *)p + 0x18 + i * 16;
    if (strcmp(s, q)) {
        func_0030A970_2(q, s);
        p->unk1B0 = 1;
    }
}

extern "C" void func_002968D0(S00296640* p, int b) {
    if (b == 0) {
        p->unk168 = 0;
    }
    strcpy(&p->unk168);
}

extern "C" void func_002968F8(S00296640* p, int b) {
    if (b == 0) {
        p->unk188 = 0;
    }
    strcpy(&p->unk188);
}

extern "C" char *func_00296920(void *v, int i) {
    S2949F0_A *p = (S2949F0_A *)v;
    if (p->unk0 == 3) {
        return D_00371798;
    }
    return (char *)&p->unk68[i];
}

extern "C" int func_00296948(S2949F0_A *p) {
    int n = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (p->unk68[i].unk0 == 0) {
            break;
        }
        n++;
    }
    return n;
}

extern "C" int func_00296988(S00296848* p) {
    if (*(int*)p == 3 || *(int*)p == 1) {
        return 0;
    }
    return p->unk1A8;
}

extern "C" S2949F0_L *func_002969B0(S2949F0_L *p, int a) {
    p->unk18 = a;
    p->unk4 = p;
    p->unk14 = D_0035C318;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk1C = 0;
    return p;
}

extern "C" S2949F0_L *func_002969E0(S2949F0_L *p, int a) {
    p->unk1C = a;
    p->unk4 = p;
    p->unk14 = D_0035C300;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk28 = 0;
    p->unk24 = 0;
    return p;
}
