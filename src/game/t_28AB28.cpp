#include "common.h"

struct S0028C1E0 {
    char pad[0xB8];
    u8 unkB8;
};

struct S0028C8D0_2 {
    int unk0;
};

struct S0028C8D0 {
    char pad[0x40];
    int unk40;
    char pad1[0x60];
    S0028C8D0_2* unkA4;
    char pad2[0x2C];
    int unkD4;
};

struct S0028AB28 {
    char pad[0x14];
    u8* unk14;
};

struct S0028B8C0 {
    char pad[0x14];
    u8* unk14;
};

extern "C" {
void func_0028C590(void);
void func_0028C9F0(void);
int func_00288C48(void*);
int func_00288C00(void*);
int func_00289630(void*, void*);
}

extern "C" int func_0028AB28(S0028AB28* p) {
    if (p->unk14 == 0) {
        return 1;
    }
    return *p->unk14 == 0x24;
}

extern "C" void func_0028AB50(char* a) {
    func_00289630(a + 0xA8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AB70);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ABB0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ACA8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AD40);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ADE8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AE28);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AF38);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B738);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B7D0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B840);

extern "C" void func_0028B8C0(S0028B8C0* p) {
    u8* s = p->unk14;
    u8* n = s + 1;
    p->unk14 = n;
    p->unk14 = n + (s[1] | (n[1] << 8));
}

extern "C" void func_0028B8E8(S0028B8C0* p) {
    u8* s = p->unk14;
    u8* n = s + 3;
    p->unk14 = n;
    p->unk14 = n + (s[3] | (n[1] << 8));
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B910);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BC70);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BDA8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BE80);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BF48);

extern "C" void func_0028C1E0(S0028C1E0* p) {
    p->unkB8++;
}

extern "C" void func_0028C1F0(S0028C1E0* p) {
    p->unkB8--;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C200);

extern "C" void func_0028C470(char* a) {
    func_00288C48(a + 0xA8);
}

extern "C" void func_0028C490(char* a) {
    func_00288C00(a + 0xA8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C518);

extern "C" void func_0028C570(void) {
    func_0028C590();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C590);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C658);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C770);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C840);

extern "C" int func_0028C8D0(S0028C8D0* p) {
    if (p->unk40 != 0) {
        return p->unkA4->unk0;
    }
    return p->unkD4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C8F0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C8F8);

extern "C" void func_0028C9D0(void) {
    func_0028C9F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C9F0);
