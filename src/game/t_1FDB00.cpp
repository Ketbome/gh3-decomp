#include "common.h"

struct VEntry1FD {
    s16 delta;
    s16 unk2;
    void (*fn)(void*);
};

struct S1FD {
    char pad0[0x18];
    VEntry1FD* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    char pad28[0x4];
    int unk2C;
    char pad30[0x4C];
    int unk7C;
};

extern "C" {
void* func_00113D20(u32 size);
void* func_001FDDC0(void*);
void func_00276D68(u32, void*, int);
extern u8 D_0038F8E8[];
S1FD* func_001FEE90(void*, void*);
void func_0027C448(void*, u32, int);
void func_001CE888(void*, void*);
void func_001CE868(void*, void*);
void func_001D0F90(void*, int);
extern u8 D_0034FC68[];
}

extern "C" void func_001FDB00(S1FD* self) {
    self->unk7C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDB08);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDC60);

extern "C" void* func_001FDD68(void) {
    return func_001FDDC0(func_00113D20(0xF0));
}

extern "C" void func_001FDD90(void) {
    func_00276D68(0x5CB5CB7E, D_0038F8E8, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDDC0);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDE48);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FDEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEB08);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEB48);

extern "C" void func_001FEC40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEC48);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FECB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FED08);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FED90);

extern "C" int func_001FEDE0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEDE8);

extern "C" void func_001FEE88(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEE90);

INCLUDE_ASM("asm/nonmatchings/game/t_1FDB00", func_001FEEE0);
