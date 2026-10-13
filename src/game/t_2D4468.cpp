#include "common.h"

struct S002D5B48 {
    char pad0[4];
    void *unk4;
    char pad8[0xE];
    u8 unk16;
};

extern "C" {
extern int D_00368A38;
void func_00119400(int, void *);
void func_002D5A90(void);
}
struct S2D4468_A {
    int unk0;
    int unk4;
    int unk8;
};


struct S2D5878_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_select_guitar_build_finish_array);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D4B38);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_store_prune_guitar_finishes);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_SetPS2DOFZ);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5868);

extern "C" void func_002D5878(S2D5878_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

extern "C" S2D5878_0 *func_002D5888(S2D5878_0 *self) {
    func_002D5878(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D58B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5A90);

extern "C" void func_002D5B48(S002D5B48 *p, int b) {
    if (p->unk16 == 0) {
        if (p->unk4) {
            func_002D5A90();
            if (p->unk4) {
                func_00119400(D_00368A38, p->unk4);
            }
            p->unk4 = 0;
        }
    }
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}

extern "C" void func_002D5BC0(S2D4468_A *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5BD0);

extern "C" S2D4468_A *func_002D5C88(S2D4468_A *self) {
    func_002D5BC0(self);
    return self;
}

extern "C" void func_002D5CB0(S2D4468_A *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S2D4468_A *func_002D5CC0(S2D4468_A *self) {
    func_002D5CB0(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5EC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5F80);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D6160);
