#include "common.h"

struct VEnt {
    s16 delta;
    s16 index;
    void* fn;
};

struct S001D0F68 {
    char pad0[0x4];
    s32 unk4;
    VEnt* unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    VEnt* unk18;
};

extern "C" {
void func_001D0330(void);
void func_001CE7C0(void);
void func_001D12E0(void);
void func_0027D188(void* p, s32 key, void* v, s32 req);
extern s32 D_00372D90;
extern char D_0034B698[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D00B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0130);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0170);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0228);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D02A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0330);

extern "C" void func_001D03B8(void) {
    func_001D0330();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D03D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0450);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0518);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0548);

extern "C" void func_001D0570(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0578);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0680);

extern "C" s32 func_001D0788(void) {
    return D_00372D90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0790);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0798);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0848);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0900);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D09C0);

extern "C" void func_001D0F18(void) {
    func_001CE7C0();
}

extern "C" int func_001D0F38(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0F40);

extern "C" S001D0F68* func_001D0F68(S001D0F68* p) {
    p->unk4 = 0;
    p->unk18 = (VEnt*)D_0034B698;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0F90);

extern "C" void func_001D0FF0(void) {
}

extern "C" void func_001D0FF8(void) {
}

extern "C" void func_001D1000(S001D0F68* p, void* a) {
    ((void (*)(void*, void*))p->unk18[3].fn)((char*)p + p->unk18[3].delta, a);
}

extern "C" void func_001D1028(void) {
}

extern "C" int func_001D1030(void) {
    return 2;
}

extern "C" s32 func_001D1038(S001D0F68* p, s32* q, void* a, void* b) {
    return ((s32 (*)(void*, s32, void*, void*))p->unk18[12].fn)((char*)p + p->unk18[12].delta, *q, a, b);
}

extern "C" void func_001D1068(S001D0F68* p, s32 v) {
    if (v != 0) {
        p->unk8 = (VEnt*)((s32)p->unk8 | 1);
    } else {
        p->unk8 = (VEnt*)((s32)p->unk8 & ~1);
    }
}

extern "C" void func_001D1090(void) {
}

extern "C" void func_001D1098(void) {
}

extern "C" void func_001D10A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D10A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D11B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1270);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D12E0);

extern "C" void func_001D1418(void) {
    func_001D12E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1438);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D14C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1548);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1598);

extern "C" s32 func_001D1610(S001D0F68* p, void* a, void* b) {
    return ((s32 (*)(void*, void*, void*))p->unk8[12].fn)((char*)p + p->unk8[12].delta, a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1638);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D17B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1910);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1998);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1B28);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1D90);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1E20);

extern "C" int func_001D1EA8(void* a, void* params) {
    s32 v;

    func_0027D188(params, 0, &v, 0);
    return 1;
}

extern "C" int func_001D1ED8(S001D0F68* p, void* a) {
    ((void (*)(void*, void*, s32))p->unk8[11].fn)((char*)p + p->unk8[11].delta, a, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1F08);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1F58);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D2030);
