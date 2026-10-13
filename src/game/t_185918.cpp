#include "common.h"

struct S001874D0 {
    char pad[0xC];
    u16 unkC;
};

struct S001874D8 {
    char pad[0xE];
    u16 unkE;
};

struct S_001873D8 { int unk0; int unk4; char pad8[8]; int* unk10; };

extern "C" {
int func_001BF4A0(int, void*);
int func_001C3578(int, void*);
extern int D_0036B594;
extern int D_00368A38;
void Heap_Free(int, int);
void func_001BE498(int);
void func_001BF230(int);
void func_001BF258(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185918);

GP_DATA(D_0036B594);
extern "C" void func_00185B98(void) {
    if (D_0036B594) {
        Heap_Free(D_00368A38, D_0036B594);
    }
    D_0036B594 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186060);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186310);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001863D0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186788);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186CF0);

static inline int S_001873D8_Get(S_001873D8* self) {
    if ((self->unk4 >> 2) & 1) {
        return *self->unk10;
    }
    if (self->unk4 & 1) {
        return (int)self->unk10;
    }
    return 0;
}

static inline int S_001873D8_Get2(S_001873D8* self) {
    if ((self->unk4 >> 1) & 1) {
        return (int)self->unk10;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186E40);

static inline int S_001873D8_GetF(S_001873D8* self, int f) {
    if ((f >> 2) & 1) {
        return *self->unk10;
    }
    if (f & 1) {
        return (int)self->unk10;
    }
    return 0;
}

static inline int S_001873D8_Get2F(S_001873D8* self, int f) {
    if ((f >> 1) & 1) {
        return (int)self->unk10;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186F90);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187038);

extern "C" int func_001870E0(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0xC);
    }
    return 0;
}

extern "C" int func_00187158(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x24);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001871D0);

extern "C" void func_001873D8(S_001873D8* self) {
    func_001BE498(S_001873D8_Get(self));
}

extern "C" int func_00187428(void) {
    return 96;
}

extern "C" void func_00187430(S_001873D8* self) {
    func_001BF230(S_001873D8_Get(self));
}

extern "C" void func_00187480(S_001873D8* self) {
    func_001BF258(S_001873D8_Get(self));
}

extern "C" u16 func_001874D0(S001874D0* self) {
    return self->unkC;
}

extern "C" u16 func_001874D8(S001874D8* self) {
    return self->unkE;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001874E0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001875A8);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187650);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187708);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001877D0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187898);
