#include "common.h"

struct S_0019B668 { int unk0; int unk4; int unk8; };
struct E_0019CFE8 { int unk0; int unk4; u64 unk8; };

extern "C" {
int func_0019D0B0(int, int, long);
void func_0030A2F4(void*, void*, int);
void func_0019B550(S_0019B668*, int, int);
void func_0011A470(int);
extern int D_0036C0C4;
extern int D_0036C118;
extern E_0019CFE8 D_00415D00[];
extern char* D_00373270;
extern int D_003732A0;
extern char* D_003732A4;
extern int D_0037328C;
extern int D_00373284;
void func_0019C3F0(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B448);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B550);

GP_DATA(D_0036C0C4);
extern "C" void func_0019B668(S_0019B668* self) {
    func_0019B550(self, self->unk8, 5);
    self->unk8 = 0;
    func_0011A470(self->unk4);
    func_0011A470(self->unk0);
    func_0011A470(D_0036C0C4);
    D_0036C0C4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B6B8);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B778);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B880);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B978);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BA98);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BCA0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BE48);

extern "C" int func_0019BF10(u16* p) {
    return (*p + 1) << 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BF20);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BFC8);

extern "C" void func_0019C208(u16* src, void* dst) {
    func_0030A2F4(dst, src, (*src + 1) << 4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C238);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C648);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C700);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C908);

extern "C" void func_0019CCF8(int a0, int a1) {
    func_0019C3F0(a0, a1, 0);
}

extern "C" void func_0019CD18(int a0, int a1) {
    func_0019C3F0(a0, a1, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019CD38);

extern "C" int func_0019CFE8(int a, int b, u64 c) {
    int n = D_0036C118;
    if (n >= 40) {
        return 0;
    }
    E_0019CFE8* e = &D_00415D00[n];
    e->unk0 = a;
    e->unk4 = b;
    D_00415D00[n].unk8 = c;
    D_0036C118 = n + 1;
    return 1;
}

extern "C" void func_0019D038(void) {
    E_0019CFE8* p = D_00415D00;
    int i = 0;
    if (D_0036C118 > 0) {
        do {
            i++;
            func_0019D0B0(p->unk0, p->unk4, p->unk8);
            p++;
        } while (i < D_0036C118);
    }
    D_0036C118 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D248);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D290);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D2A0);
