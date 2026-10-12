#include "common.h"

struct E234 {
    void* unk0;
    char pad4[0xC];
};

struct S234 {
    char pad0[0x7D0];
    E234 unk7D0[0x78];
    int unkF50;
};

struct S234b {
    char pad0[0x12A];
    u8 unk12A;
    u8 unk12B;
    u8 unk12C;
    u8 unk12D;
    u8 unk12E;
};

extern "C" {
extern int D_0036FD2C;
void func_00226098(void);
void func_0014EAC8(int);
extern void (*D_0036FD64)(void);
void func_0027D870(int, u32, int*, int);
int func_00233C50(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234190);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002342B0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002343E8);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234668);

extern "C" void func_00234808(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234810);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002348A0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002348D8);

extern "C" void func_002349B0(S234b* self) {
    self->unk12A = 1;
    self->unk12E = 1;
    self->unk12D = 0;
    self->unk12C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002349C8);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234A10);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234B88);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234C70);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234E18);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234F68);

extern "C" void func_00235080(S234* self, S234b* b) {
    if (!b->unk12A) {
        self->unk7D0[self->unkF50].unk0 = b;
        self->unkF50++;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002350B0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_CreatePakManMap);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_DestroyPakManMap);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_PendingPakManLoads);

extern "C" int CFunc_ExistsPakManMap(int a) {
    int tmp = 0;
    func_0027D870(a, 0x6C525544, &tmp, 1);
    return func_00233C50(tmp) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_SetPakManCurrent);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_GetPakManCurrent);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_GetPakManCurrentName);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_GetPakManNumFreeSlots);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00236100);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_EnablePakManStreaming);

extern "C" int CFunc_DisablePakManStreaming(void) {
    D_0036FD2C = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_RefreshPakManSizes);
