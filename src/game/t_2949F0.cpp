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

extern "C" {
extern int D_00371784;
extern int D_00372ED0;
void func_0029FF10(void);
int func_00296798(void*);
char* func_00296920(void*, int);
void func_0030A970(void*);
extern char D_00371798[];
extern char D_0035C318[];
extern char D_0035C300[];
extern int D_003717E0;
extern int D_003717E4;
void func_002964D8(int, int);
int func_00113DF0(int, int, int);
int func_00296470(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002949F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00294AF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00294C90);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00294FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295010);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295098);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002950D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295118);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295140);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295278);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002952D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295408);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295630);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295D40);

extern "C" void func_00295DA8(void) {
    D_00371784 = 0;
    D_00372ED0 = 0;
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296028);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296138);

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
    func_00296798(a + 0x24);
}

extern "C" int func_00296638(S00296638* p) {
    return p->unk24;
}

extern "C" void func_00296640(S00296640* p) {
    func_00296920(p->unk24, p->unk1C->unk10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296668);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296678);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002966D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296738);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296798);

extern "C" void func_00296848(S00296848* p, int v) {
    if (p->unk1A8 != v) {
        p->unk1A8 = v;
        p->unk1B0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296868);

extern "C" void func_002968D0(S00296640* p, int b) {
    if (b == 0) {
        p->unk168 = 0;
    }
    func_0030A970(&p->unk168);
}

extern "C" void func_002968F8(S00296640* p, int b) {
    if (b == 0) {
        p->unk188 = 0;
    }
    func_0030A970(&p->unk188);
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
