#include "common.h"

struct S29D8C8_0 {
    char pad0[0x2294];
    s32 unk2294;
};

struct S29E200_0 {
    char pad0[0xC];
    void *unkC;
    void *unk10;
    void *unk14;
};

struct S29E4C8_0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" {
extern int D_0035C4E8[];
extern int D_0035C5B0[];
extern int D_0035C5C8[];
extern int D_0035C720[];
extern int D_0035C768[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
int func_00113F38(void);
int func_00119400(s32, void *);
int func_0030A49C(s32, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D230);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D238);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D2A0);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D370);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D530);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D600);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D630);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D688);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D730);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D838);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D898);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8C0);

extern "C" s32 func_0029D8C8(S29D8C8_0 *arg0) {
    s32 x = arg0->unk2294 & 8;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8D8);

extern "C" s32 func_0029D8E0(S29D8C8_0 *arg0) {
    s32 x = arg0->unk2294 & 0x10;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8F0);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DA40);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DB70);

extern "C" void func_0029DB78(void) {
}

extern "C" s8 func_0029DB80(s32 arg0, s32 arg1) {
    return (*(s8 *)((char *)((arg0 + (arg1 & 0xFF))) + 0x2314));
}

extern "C" void func_0029DB90(s32 arg0, s32 arg1, s8 arg2) {
    (*(s8 *)((char *)((arg0 + (arg1 & 0xFF))) + 0x2314)) = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DE80);

extern "C" void func_0029E200(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C4E8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E260(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E2C0(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E320(void) {
    func_00113F38();
}

extern "C" s32 func_0029E340(void) {
    return 0;
}

extern "C" void func_0029E348(void) {
}

extern "C" void func_0029E350(void) {
}

extern "C" void func_0029E358(int arg0, s32 arg1) {
    func_0030A49C(arg1 + 8, 0, 8);
}

extern "C" s32 func_0029E380(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E388);

extern "C" void func_0029E408(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C768;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E468(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E4C8(S29E4C8_0 *arg0, s32 arg1) {
    arg0->unk8 = D_0035C5C8;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E508(S29E4C8_0 *arg0, s32 arg1) {
    arg0->unk8 = D_0035C5B0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E548);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E570);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E578);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E818);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029EAC8);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029EC08);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029EC40);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029F090);
