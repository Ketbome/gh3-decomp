#include "common.h"

struct S00272290 {
    char pad[0x1C];
    int unk1C;
    int unk20;
};

struct S00272B28_2 {
    int unk0;
};

struct S00272B28 {
    char pad[0x10];
    S00272B28_2* unk10;
};

struct S002724F8_3 {
    char pad[0xC];
    u32 unkC;
    int unk10;
};

struct S002724F8_4 {
    char pad[0x10];
    S002724F8_3* unk10;
};

extern "C" {
extern int D_00370DBC;
void func_002715B8(void *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271480);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271570);

extern "C" void *func_00271590(void *p) {
    func_002715B8(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002715B8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271628);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002716B8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271708);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271880);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271910);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271A00);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271A08);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271A98);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271C10);

extern "C" void func_00271CE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271E88);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271F28);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272020);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272058);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272160);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002721F8);

extern "C" int func_00272290(S00272290* p) {
    return p->unk20 >= p->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002722A8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002724B0);

extern "C" int func_002724F8(S002724F8_4* p) {
    S002724F8_3* q = p->unk10;
    p->unk10 = 0;
    q->unk10 = 0;
    q->unkC &= 0xFFFFFFFD;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272520);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002727E8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272920);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002729C0);

extern "C" int func_00272B28(S00272B28* p) {
    if (p->unk10 != 0) {
        return p->unk10->unk0 - 1;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272B48);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272E18);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272F70);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273060);

extern "C" void func_00273068(int v) {
    D_00370DBC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273070);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002730D0);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273240);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273298);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273308);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002733E0);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273428);
