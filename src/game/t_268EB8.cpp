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

extern "C" {
extern int D_00372E88;
int func_0026AB60(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00268EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00268F40);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002691B0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269200);

extern "C" void func_00269208(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269218);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269240);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269420);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002694D8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269590);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002696C8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269780);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269888);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_002698C8);

extern "C" void func_00269990(void* p, int v) {
    D_00372E88 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269998);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269B70);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269D38);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269E50);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269F08);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269F60);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_00269FE0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A030);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A368);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A488);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A5D0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A660);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A6C0);

extern "C" void func_0026A730(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A740);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A768);

extern "C" void func_0026A948(S00269208* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026A958);

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

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026ABB8);

extern "C" int func_0026AC08(S0026AC08* p) {
    int i = p->unk28;
    if (i < p->unk2C) {
        return p->unk3C[i].unk0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AC30);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AC60);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026ACB0);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AD48);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AE30);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_268EB8", func_0026AEA8);
