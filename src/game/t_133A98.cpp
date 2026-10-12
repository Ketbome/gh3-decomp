#include "common.h"

struct S_001344E8 { char pad0[0x6C]; char unk6C; };
struct S_001346E0 { char pad0[0x6C]; char unk6C; };

struct S_001349B0 { char pad0[0x6C]; char unk6C; };

struct S_00133F80 { char pad0[0x4]; int unk4; char pad1[0x4]; int unkC; void* unk10; };

struct VE_00134E18 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int, int, int); };
struct S_00134E18 { char pad0[0x8]; VE_00134E18* unk8; };

extern "C" {
void func_0027ACF8(char*);
void func_0027C448(char*);
void func_0027D870(char*, int, int, int);
void func_00134D60(int, int);
extern int D_00369420;
void func_00160A90(int);
extern u8 D_0033A350[];
void func_00161BA0(int);
}

struct S_00134278 { char pad0[0xC]; int unkC; };
struct S_00134280 { char pad0[0xC]; int unkC; };
struct S_00134378 { char pad0[0x224]; int unk224; };
struct S_00134D20 { char pad0[0x74]; int unk74; };

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133A98);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133B10);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133D38);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133F60);

extern "C" S_00133F80* func_00133F80(S_00133F80* self) {
    self->unk4 = 0;
    self->unk10 = D_0033A350;
    self->unkC = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133FE0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134128);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134208);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134210);

extern "C" int func_00134278(S_00134278* self) {
    return self->unkC;
}

extern "C" void func_00134280(S_00134280* self, int v) {
    self->unkC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134288);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001342B0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001342E8);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134340);

extern "C" int func_00134378(S_00134378* self) {
    return self->unk224;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134380);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001343B0);

extern "C" void func_001344E8(S_001344E8* self) {
    func_0027ACF8(&self->unk6C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134508);

extern "C" void func_001346E0(S_001346E0* self) {
    func_0027C448(&self->unk6C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134700);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134748);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001347B0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001348C8);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134938);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134998);

extern "C" void func_001349A8(void) {
}

extern "C" void func_001349B0(S_001349B0* self, int p1, int p2) {
    func_0027D870(&self->unk6C, p1, p2, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001349D0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134A20);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134A50);

extern "C" int func_00134D20(S_00134D20* self) {
    return self->unk74;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134D28);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134D60);

extern "C" void func_00134DB0(void) {
    func_00134D60(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134DD0);

extern "C" void func_00134E18(S_00134E18* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    VE_00134E18* e = &self->unk8[11];
    e->unk4((char*)self + e->unk0, a1, a2, a3, a4, a5, a6);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134E40);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134FB0);

extern "C" void func_00135048(void) {
    func_00160A90(D_00369420);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00135068);

extern "C" int func_00135A70(void) {
    func_00161BA0(D_00369420);
    return 1;
}
