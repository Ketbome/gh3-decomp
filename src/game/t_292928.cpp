#include "common.h"

struct S002934C8 {
    char pad[0xA8];
    int unkA8;
};

struct S00293518 {
    char pad[0xA8];
    int unkA8;
};

struct S00292928 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char pad[0x94];
    int unkA8;
};

struct S00293098 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00293340 {
    char pad[0xC];
    volatile int unkC;
};

extern "C" {
extern int D_003733C4;
int func_00293EE0(void*);
int func_00293FD0(void*);
int func_00294818(void*);
int func_00305018(void);
extern S00293098 D_00427EB0[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292928);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002929F0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292AF0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292BA8);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292BF0);

extern "C" void func_00292D60(S00292928* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292D70);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292D98);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292F78);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293038);

extern "C" void func_00293098(int i) {
    D_00427EB0[i].unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002930B8);

extern "C" void func_002930E8(void) {
    D_003733C4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002930F0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293120);

extern "C" void func_002931E8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002931F0);

extern "C" int func_00293200(S00292928* p) {
    return p->unkC == p->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293218);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293288);

extern "C" int func_002932D0(S00292928* p) {
    return p->unkC == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002932E0);

extern "C" void func_00293340(S00293340* p) {
    if (p->unkC > 0) {
        p->unkC--;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293360);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293460);

extern "C" int func_00293468(void) {
    func_00305018();
    return 1;
}

extern "C" void func_00293488(char* a) {
    func_00293EE0(a + 0x48);
}

extern "C" void func_002934A8(char* a) {
    func_00293FD0(a + 0x48);
}

extern "C" void func_002934C8(S002934C8* p) {
    p->unkA8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002934D0);

extern "C" void func_00293508(S00292928* p) {
    p->unkA8 = 1;
}

extern "C" int func_00293518(S00293518* p) {
    return p->unkA8;
}

extern "C" int func_00293520(S00292928* p, int v) {
    int old = p->unkA8;
    p->unkA8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293530);

extern "C" void func_00293578(char* a) {
    func_00294818(a + 0x48);
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293598);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002935A0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293678);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002936C0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293768);

extern "C" int func_00293998(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002939A0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002939D8);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293A08);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293A38);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293A88);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293C00);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293C70);

extern "C" void func_00293CE0(u64* p, u32 b, u32 c, u32 d) {
    *p = ((u64)b << 32) | ((u64)c << 28) | (u64)d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293D08);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293D80);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293EE0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00294028);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002943A0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002944B0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002947C0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00294818);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00294868);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002948C0);
