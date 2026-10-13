#include "common.h"

extern "C" {
extern u8 D_00370044;
void func_0010F690(void*);
void func_001342B0(void*);
extern u8 D_00397A50[];
extern u8 D_00354B58[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245220);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002454C8);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002454D0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245598);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002455A0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00245648);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_002456B0);

extern "C" void func_00246B08(void) {
}

extern "C" void func_00246B10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246B18);

extern "C" {
int func_00246BD8(int*);
int func_00246BC0(int*);
}

extern "C" int func_00246B30(int* p) {
    if (func_00246BD8(p)) {
        return func_00246BC0(p) + 8;
    }
    return func_00246BC0(p);
}

extern "C" int func_00246B78(int* p) {
    if (func_00246BD8(p)) {
        return func_00246BC0(p);
    }
    return func_00246BC0(p) + 8;
}

extern "C" int func_00246BC0(int* p) {
    return *p & 0xFFFFFFFC;
}

extern "C" int func_00246BD8(int* p) {
    return *p & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246BE8);

extern "C" void func_00246C50(int a, int b) {
    if (b == 0xFFFF && a) {
        u32* d = (u32*)D_00397A50;
        u32 k = 0xFFFFFFFF;
        d[5] = (u32)D_00354B58;
        d[1] = k;
        d[3] = (u32)d;
        d[4] = (u32)d;
        d[2] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246C98);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246CC0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246D48);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246DE0);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246E30);

GP_DATA(D_00370044);
extern "C" int func_00246EF0(void) {
    int v = D_00370044 + 1;
    D_00370044 = v;
    return v & 0xFF;
}

extern "C" void* func_00246F08(char* p) {
    func_0010F690(p);
    func_0010F690(p + 0x10);
    func_001342B0(p);
    *(int*)(p + 0x30) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00246F48);

INCLUDE_ASM("asm/nonmatchings/game/t_245220", func_00247020);
