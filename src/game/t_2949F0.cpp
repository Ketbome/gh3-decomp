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

extern "C" {
extern int D_00371784;
extern int D_00372ED0;
void func_0029FF10(void);
int func_00296798(void*);
char* func_00296920(void*, int);
void func_0030A970(void*);
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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295068);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295DB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295E08);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295E50);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00295FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296028);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296138);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002961C8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002965E8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296920);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_00296948);

extern "C" int func_00296988(S00296848* p) {
    if (*(int*)p == 3 || *(int*)p == 1) {
        return 0;
    }
    return p->unk1A8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002969B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2949F0", func_002969E0);
