#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" {
void func_001A4050(void*, int);
void func_002F3B80(void);
void func_002F3BD0(void);
extern int D_0037334C;
extern int D_00373348;
extern int D_0036C58C;
void func_001A41D0(int, int, int);
extern u128* D_00373270;
extern int D_00373294;
void func_0019BE48(int);
void func_001A42E0(void*, u8);
}

extern "C" u128* func_001A37A8(u8* src) {
    if (D_00373294 != 0) func_0019BE48(0);
    u128* base = D_00373270;
    u128* d = base;
    u128* s = (u128*)src;
    int i;
    for (i = 0; i < (*src + 2) * 16; i += 16) {
        *d = *s;
        s++;
        d++;
    }
    int n = *src + 2;
    D_00373270 = D_00373270 + n;
    return base;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A3850);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A3D80);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4050);

extern "C" void func_001A4190(int a0, int a1) {
    func_001A41D0(a0, (a1 & 255), 0);
}

extern "C" void func_001A41B0(int a0, int a1) {
    func_001A41D0(a0, 0, (a1 & 255));
}

struct S001A41D0 { u8 unk0; u8 unk1; };

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A41D0);

struct S_001A4258 { char pad0[1]; u8 unk1; };

extern "C" int func_001A4258(S_001A4258* self) {
    u32 v;
    for (v = 8; v != 0; v >>= 1) {
        if (v & self->unk1) break;
    }
    switch ((int)v) {
    case 1:
        return 4;
    case 2:
    case 4:
        return 7;
    case 8:
        return 0xE;
    default:
        return 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A42E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4330);

struct S1A4488 { char pad0[4]; int unk4; };

extern "C" void func_001A4488(S1A4488* self, int a, int b) {
    func_001A41D0((int)self, 8, 0);
    self->unk4 = a;
    func_001A4050(self, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A44E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4698);

extern "C" void func_001A46D0(void) {
    D_0037334C = 0;
    D_00373348 = 0;
}

extern "C" int func_001A46E0(int i) {
    func_002F3B80();
    int* p = &(&D_00373348)[i];
    int old = *p;
    *p = 1;
    func_002F3BD0();
    return old ^ 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4730);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4770);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A49E0);

extern "C" void func_001A4D00(void) {
    D_0036C58C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4D08);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4D20);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A4E48);

INCLUDE_ASM("asm/nonmatchings/game/t_1A37A8", func_001A5560);
