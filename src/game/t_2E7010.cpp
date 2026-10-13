#include "common.h"

extern "C" {
void func_002E3AC0(void);
void func_002E1B50(int);
int func_002E5CA8(int, int, int);
void func_002E1488(int);
int func_002E3248(int);
int func_002E5788(int, int);
int func_002E5860(int, int);
int func_002E59A0(int, int);
int func_002E5A78(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7010);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E70B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E71A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7B60);

extern "C" void func_002E7BC8(void) {
    func_002E5860(0x10, 0x2F);
}

extern "C" void func_002E7BE8(void) {
    func_002E5A78(0x10, 0x2F);
}

extern "C" void func_002E7C08(void) {
    func_002E5788(0, 0x2F);
    func_002E3248(1);
}

extern "C" void func_002E7C30(void) {
    func_002E59A0(0, 0x2F);
    func_002E3248(1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7C58);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7D80);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7E20);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7E80);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7F90);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E81B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8318);

extern "C" void func_002E8440(void) {
    int i = 0x10;
    do {
        func_002E1488(i);
        func_002E1488(i + 1);
        func_002E1488(i + 2);
        func_002E1488(i + 3);
        func_002E1488(i + 4);
        func_002E1488(i + 5);
        func_002E1488(i + 6);
        func_002E1488(i + 7);
        func_002E1488(i + 8);
        func_002E1488(i + 9);
        func_002E1488(i + 10);
        func_002E1488(i + 11);
        func_002E1488(i + 12);
        func_002E1488(i + 13);
        func_002E1488(i + 14);
        func_002E1488(i + 15);
        i += 0x10;
    } while (i < 0x30);
    func_002E3248(0);
    func_002E1B50(0x25010);
    func_002E3AC0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8510);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8610);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8960);

extern "C" void func_002E8968(void) {
    int i = 0x10;
    do {
        func_002E1488(i);
        func_002E1488(i + 1);
        func_002E1488(i + 2);
        func_002E1488(i + 3);
        func_002E1488(i + 4);
        func_002E1488(i + 5);
        func_002E1488(i + 6);
        func_002E1488(i + 7);
        func_002E1488(i + 8);
        func_002E1488(i + 9);
        func_002E1488(i + 10);
        func_002E1488(i + 11);
        func_002E1488(i + 12);
        func_002E1488(i + 13);
        func_002E1488(i + 14);
        func_002E1488(i + 15);
        i += 0x10;
    } while (i < 0x30);
}

extern "C" int func_002E8A18(int a) {
    int i = func_002E5CA8(0, 0x2F, a);
    int n = 0;
    if (i >= 0) {
        do {
            n++;
            func_002E1488(i);
            i = func_002E5CA8(i + 1, 0x2F, a);
        } while (i >= 0);
    }
    func_002E3248(1);
    return n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8A98);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8C08);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8C28);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8D68);

GP_DATA(D_003728C4);
GP_DATA(D_003728C0);
GP_DATA(D_00372900);
GP_DATA(D_003728FC);
INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8FF0);
