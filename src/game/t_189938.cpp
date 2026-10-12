#include "common.h"

struct S00189E30 {
    char pad[0x48];
    char unk48;
};

struct S0018A070 {
    char pad[0xA0];
    int unkA0;
};

struct S0018A088 {
    char pad[0xA8];
    int unkA8;
};

struct S0018A618 {
    char pad[0x60];
    int unk60;
};

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189938);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189B38);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189BF8);

extern "C" void* func_00189E30(S00189E30* self) {
    return &self->unk48;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189E38);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189E90);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189ED8);

extern "C" int func_0018A070(S0018A070* self) {
    return self->unkA0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A078);

extern "C" int func_0018A088(S0018A088* self) {
    return self->unkA8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A090);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A1F0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A350);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A388);

extern "C" int func_0018A3C0(void) {
    return 1;
}

extern "C" int func_0018A3C8(void) {
    return 1;
}

extern "C" int func_0018A3D0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A3D8);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A430);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A468);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A4D0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A510);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A538);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A5A0);

extern "C" int func_0018A618(S0018A618* self) {
    return self->unk60;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A620);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A7A0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A800);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A860);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A898);

extern "C" int func_0018A900(S0018A618* self) {
    return self->unk60;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A908);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AC50);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018ACD8);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AD18);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AD80);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AEA0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AF58);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B028);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B058);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B070);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B128);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B1D0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B398);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B3C0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B5C0);
