#include "common.h"

struct S_00112A38 { char pad0[0x24]; float* unk24; char pad1[0x10]; float* unk38; };

struct S_00111A38 { char pad0[0x4]; int unk4; };
struct S_00112A30 { char pad0[0x28]; int unk28; };
struct S_00112A50 { char pad0[0x3C]; int unk3C; };

struct SA110 {
    float* unk0;
    char pad4[0xC];
    float* unk10;
};

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00110D00);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111290);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_001117F8);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111860);

extern "C" void func_00111A08(SA110* self, int i, float* v) {
    float* p = self->unk0;
    p += i;
    *p = *v;
}

extern "C" void func_00111A20(SA110* self, int i, float* v) {
    float* p = self->unk10;
    p += i;
    *p = *v;
}

extern "C" int func_00111A38(S_00111A38* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111A40);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111E38);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112830);

extern "C" int func_00112A30(S_00112A30* self) {
    return self->unk28;
}

extern "C" float func_00112A38(S_00112A38* self, int i) {
    float* p = self->unk24;
    p += i;
    return *p;
}

extern "C" int func_00112A50(S_00112A50* self) {
    return self->unk3C;
}

extern "C" float func_00112A58(S_00112A38* self, int i) {
    float* p = self->unk38;
    p += i;
    return *p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112A70);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112CE0);
