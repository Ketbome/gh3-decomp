#include "common.h"

extern "C" {
void func_00119400(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003417B0[];
void func_00172CC8(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176C78);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176DC0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176FE0);

extern "C" void func_001773F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001773F8);

extern "C" u32 func_00177828(void) {
    return 0xF221474C /* linear */;
}

extern "C" void func_00177838(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" float func_00177878(float v) {
    return v;
}

extern "C" u32 func_00177880(void) {
    return 0xF1B82F5A /* degenerateblend */;
}

extern "C" void func_00177890(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001778D0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001779F0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177FB0);

extern "C" void func_001785C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001785D0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178860);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178880);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178910);

extern "C" void func_00178920(void) {
    func_00172CC8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178940);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178AB0);
