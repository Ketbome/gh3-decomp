#include "common.h"

struct S00252EC8 {
    char pad[0x308];
    int unk308;
};

extern "C" {
void func_00269B70(void);
int func_00251F68(void);
extern S00252EC8* D_0036CDB4[] __attribute__((section(".sdata")));
void func_001E19F8(int);
void func_001E1A28(int);
}

extern "C" int func_00252068(void) {
    func_00251F68();
    return 1;
}

extern "C" int func_00252088(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252090);

extern "C" int func_00252D50(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252D58);

extern "C" void func_00252EC8(void) {
    func_001E19F8(D_0036CDB4[0]->unk308);
}

extern "C" void func_00252EF0(void) {
    func_001E1A28(D_0036CDB4[0]->unk308);
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252F18);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252FC0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002530A8);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002531C0);

extern "C" int func_00253280(void) {
    return 0;
}

extern "C" int func_00253288(void) {
    return 0;
}

extern "C" int func_00253290(void) {
    return 0;
}

extern "C" int func_00253298(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002532A0);

extern "C" void func_002532C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002532C8);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002533D8);

extern "C" int func_00253410(void) {
    return 0;
}

extern "C" int func_00253418(void) {
    return 0;
}

extern "C" void func_00253420(void) {
    func_00269B70();
}

extern "C" int func_00253440(void) {
    return 0;
}

extern "C" int func_00253448(void) {
    return 0;
}

extern "C" int func_00253450(void) {
    return 0;
}

extern "C" int func_00253458(void) {
    return 0;
}

extern "C" int func_00253460(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00253468);

extern "C" int func_00253670(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00253678);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002538C0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002539C0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00253CB8);
