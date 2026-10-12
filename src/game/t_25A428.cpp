#include "common.h"

extern "C" {
void func_0014F7B8(void);
void func_0025AA28(int, int, int);
extern int D_00370540;
int func_0028DAD8(void);
int func_00289E08(int);
int func_0028E6D0(int);
int func_0028CE18(int);
int func_001EB2B0(void);
void func_0014F750(int, u32);
extern int D_003715D4[] __attribute__((section(".sdata")));
void func_00291900(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025A428);

extern "C" int func_0025A498(void) {
    func_0028DAD8();
    return 1;
}

extern "C" int func_0025A4B8(void) {
    if (D_00370540 != 0) {
        D_00370540 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025A4D8);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025A738);

extern "C" int func_0025A868(int a, int b) {
    return func_00289E08(b) != 0;
}

extern "C" int func_0025A888(void) {
    func_0014F750(0, 0xB8CA16A5);
    return 1;
}

extern "C" int func_0025A8B0(void) {
    func_0014F750(1, 0xB8CA16A5);
    return 1;
}

extern "C" void func_0025A8D8(void) {
    func_0014F7B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025A8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025A988);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025AA28);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025ABD0);

extern "C" void func_0025AC28(int a, int b) {
    func_0025AA28(a, b, 1);
}

extern "C" void func_0025AC48(int a, int b) {
    func_0025AA28(a, b, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025AC68);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025ADD8);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B0A0);

extern "C" int func_0025B118(int a, int b) {
    func_0028E6D0(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B138);

extern "C" int func_0025B170(void) {
    func_0028CE18(0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B190);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B1C0);

extern "C" int func_0025B210(void) {
    func_001EB2B0();
    return 1;
}

extern "C" int func_0025B230(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B238);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B380);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B4E0);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B738);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B840);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B990);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BAA8);

extern "C" int func_0025BBE8(void) {
    func_00291900(D_003715D4[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BC10);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BD80);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025C1C0);
