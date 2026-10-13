#include "common.h"

struct S22D {
    char pad0[0x40];
    int unk40;
    char pad44[0x4C];
    int unk90;
    int unk94;
};

extern "C" {
extern int D_0036F8D0;
extern u8 D_0036F8F0[];
extern u8 D_00353620[];
extern u8 D_0036F9A0[];
extern u8 D_00353980[];
extern u8 D_00353B30[];
extern u8 D_0036FA88[];
extern u8 D_0036FAD8[];
extern u8 D_00354030[];
void func_002253A8(int, void*);
}

extern "C" void* func_0022DD98(void) {
    return D_0036F8F0;
}

extern "C" int func_0022DDA8(void) {
    return 0xE;
}

extern "C" void func_0022DDB0(int v) {
    if (v) {
        D_0036F8D0 = 1;
    } else {
        D_0036F8D0 = 0;
    }
}

extern "C" void func_0022DDF0(void);

extern "C" void* func_0022DDC8(void* p) {
    func_0022DDF0();
    return p;
}

extern "C" void func_0022DDF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DDF8);

extern "C" int func_0022DE20(void) {
    return 0x90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DE28);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DEE8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DF70);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E020);

extern "C" void* func_0022E080(void) {
    return D_00353620;
}

extern "C" int func_0022E090(void) {
    return 7;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E098);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E0C0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E1D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E270);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E2F8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E428);

extern "C" void* func_0022E490(void) {
    return D_0036F9A0;
}

extern "C" int func_0022E4A0(void) {
    return 8;
}

extern "C" void func_0022E4D0(S22D*);

extern "C" S22D* func_0022E4A8(S22D* p) {
    func_0022E4D0(p);
    return p;
}

extern "C" void func_0022E4D0(S22D* self) {
    self->unk90 = 0;
    self->unk94 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E4E0);

extern "C" int func_0022E508(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E510);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E648);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E810);

extern "C" void* func_0022E878(void) {
    return D_00353980;
}

extern "C" int func_0022E888(void) {
    return 9;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E890);

extern "C" int func_0022E8B8(void) {
    return 0x94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E8C0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E980);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EA70);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EB68);

extern "C" void* func_0022EBC8(void) {
    return D_00353B30;
}

extern "C" int func_0022EBD8(void) {
    return 0xA;
}

extern "C" void func_0022EBE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EBE8);

extern "C" int func_0022EC10(void) {
    return 0x90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EC18);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022ECC8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022ED50);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EDD0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EF38);

extern "C" void* func_0022EF98(void) {
    return D_0036FA88;
}

extern "C" int func_0022EFA8(void) {
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EFB0);

extern "C" int func_0022EFD8(void) {
    return 0xA0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EFE0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F098);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F120);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F1A8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F2F8);

extern "C" void* func_0022F358(void) {
    return D_0036FAD8;
}

extern "C" int func_0022F368(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F370);

extern "C" int func_0022F398(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F3A0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F3D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F588);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F650);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F7D8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F9A8);

extern "C" void* func_0022FA08(void) {
    return D_00354030;
}

extern "C" int func_0022FA18(S22D* self) {
    return !self->unk40 ? 0xC : 0xD;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FA30);

extern "C" int func_0022FA58(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FA60);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FB30);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FBB8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FC40);
