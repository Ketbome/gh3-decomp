#include "common.h"

struct S0028E210 {
    char pad[0xF4];
    int unkF4;
};

struct S0028E218 {
    char pad[0xF4];
    int unkF4;
};

struct S0028EB10 {
    char pad[0x1F0];
    int unk1F0;
};

struct S0028CF18 {
    char pad[0xD8];
    int unkD8;
};

extern "C" {
void func_0028D578(void);
void func_0028D720(void);
void func_001150B8(void);
void func_0028DB50(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CC70);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CCD8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CCE8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CD90);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CE18);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CE90);

extern "C" void func_0028CF18(S0028CF18* p) {
    if (p != 0 && (p->unkD8 & 1)) {
        p->unkD8 &= ~4;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CF40);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D090);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D098);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D168);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D1B0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D1D8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D490);

extern "C" void func_0028D558(void) {
    func_0028D578();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D578);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D660);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D668);

extern "C" void func_0028D700(void) {
    func_0028D720();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D720);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D7D0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D7D8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D870);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D878);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D938);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D940);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DA08);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DA38);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DA40);

extern "C" void func_0028DAB8(void) {
    func_001150B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DAD8);

extern "C" void func_0028DB28(int a) {
    func_0028DB50(a, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DB48);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DB50);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DBD0);

extern "C" void func_0028DC28(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DC30);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DDE8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DE38);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DE68);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E008);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E010);

extern "C" void func_0028E210(S0028E210* p, int v) {
    p->unkF4 = v;
}

extern "C" int func_0028E218(S0028E218* p) {
    return p->unkF4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E220);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E278);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E610);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E858);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E8A0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E9B0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028EAC0);

extern "C" void func_0028EB10(S0028EB10* p, int v) {
    p->unk1F0 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028EB18);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028EB50);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028EBA0);
