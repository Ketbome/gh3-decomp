#include "common.h"

struct S229 {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x10];
    void* unk1C;
    void* unk20;
    char pad24[0x84];
    void* unkA8;
    char padAC[0xC];
    int unkB8;
    char padBC[0x8];
    int unkC4;
    char padC8[0x4];
    void* unkCC;
};

extern "C" {
void func_0022B2E8(void*);
void func_00113FB8(void*);
void func_0022B320(void*);
int func_0022CB18(void*);
extern int D_0036F608;
void func_00229538(int, int);
void func_0022B3B8(S229*);
void func_0022B700(S229*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D30);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D38);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229F38);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A1D8);

extern "C" void func_0022A250(int a) {
    func_00229538(D_0036F608, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A278);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A2D8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A330);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A680);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A800);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9B0);

extern "C" void func_0022A9B8(S229* self) {
    self->unkB8 = 0;
    self->unkC4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022ABE8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022ADD0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE18);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE78);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AFC0);

extern "C" int func_0022B020(S229* self) {
    return func_0022CB18(self->unkA8) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B040);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B168);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B2E8);

extern "C" void func_0022B320(void* self) {
    func_0022B2E8(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B340);

extern "C" void func_0022B368(S229* self) {
    func_00113FB8(self->unkCC);
}

extern "C" void func_0022B388(S229* self) {
    func_0022B320(self->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3A8);

extern "C" void func_0022B3B8(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B5D0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B688);

extern "C" void func_0022B700(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B710);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B738);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B918);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B9D0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BA48);

extern "C" void func_0022BA70(S229* self) {
    ((void (*)(S229*))self->unk1C)(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BA90);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBD0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BCE0);
