#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S00199370 {
    char pad[0x14];
    VEntry* unk14;
};

struct S00199BF0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    s8 unk18;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001992F8);

extern "C" int func_00199368(void) {
    return 1;
}

extern "C" int func_00199370(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199398);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001993D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001994A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199960);

extern "C" int func_001999C8(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_001999F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199A30);

extern "C" int func_00199A98(void) {
    return 1;
}

extern "C" int func_00199AA0(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199B08);

extern "C" int func_00199B78(void) {
    return 1;
}

extern "C" int func_00199B80(void) {
    return 1;
}

extern "C" int func_00199B88(S00199370* self) {
    VEntry* e = &self->unk14[5];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199BB0);

extern "C" S00199BF0* func_00199BF0(S00199BF0* self) {
    self->unk18 = 0;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199C18);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199C60);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199CB8);

extern "C" int func_00199D28(int i) {
    return (i + 1) & 0xF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199D38);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199D90);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_00199EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A088);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A2E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A320);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A5D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A640);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019A6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AC40);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AE30);

INCLUDE_ASM("asm/nonmatchings/game/t_1992F8", func_0019AF18);
