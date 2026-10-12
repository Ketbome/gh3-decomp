#include "common.h"

struct VEntry1FB {
    s16 delta;
    s16 unk2;
    void (*fn)(void*, int);
};

struct S1FB {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char pad[0xC];
    VEntry1FB* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
};

extern "C" {
void func_001FB998(int, int);
int func_001FC608(void*);
int func_001FC690(void*);
int func_001FC468(void*);
void func_001FC718(int, int);
int func_0027DC58(int, int, void*, int);
int func_001FBB70(int);
int func_0026DD48(int, void*);
void func_001CE888(void*, void*);
u32 func_00275570(void);
extern u32 D_00370F40[];
extern u8 D_0034FAC8[];
void func_001D0F90(void*, int);
}

extern "C" void func_001FBAF0(void) {
}

extern "C" void func_001FBAF8(void) {
    func_001FB998(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBB18);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBB70);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBC50);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBD68);

extern "C" int func_001FBDA0(void* self) {
    func_001FC608(self);
    return 1;
}

extern "C" int func_001FBDC0(void* self) {
    func_001FC690(self);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBDE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBE50);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBEA8);

extern "C" int func_001FBEF0(void* self) {
    return func_001FC468(self) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBF10);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC030);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC0A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC1E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC220);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC468);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC608);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC690);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC718);

extern "C" void func_001FCA18(void) {
    func_001FC718(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCA38);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCA90);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCB08);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCB68);

extern "C" void func_001FD3E8(void) {
}

extern "C" void func_001FD3F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FD3F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FD628);

extern "C" void func_001FD9B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FD9B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FDA30);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FDA88);
