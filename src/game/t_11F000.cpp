#include "common.h"

struct S_00120C60 { char pad0[0x10]; int unk10; };

struct SA11F_E {
    int unk0;
    int unk4;
    int unk8;
};

struct SA11F_W {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x4];
    int unk10;
    int unk14;
};

extern "C" {
extern int D_00368748[] __attribute__((section(".sdata")));
extern int D_00368D80;
extern int D_00368C18[] __attribute__((section(".sdata")));
extern int D_00368C08[] __attribute__((section(".sdata")));
extern SA11F_E D_00415170[];
extern u8 D_00338F30[];
void func_0011DA60(void*, int);
int func_0011F110(void*);
int func_0011F028(void*);
void func_0011A470(int);
void func_002F2400(int);
void func_002F3B80(void);
void func_002F3BD0(void);
S_00120C60* func_001208C0(void);
extern int D_00368D78;
int func_00120F78(void*, int);
}

struct S_0011FB38 { char pad0[0x48]; int unk48; char pad1[0x100]; int unk14C; int unk150; int unk154; int unk158; };

GP_DATA(D_00368D78);
extern "C" int func_0011F000(void* self) {
    return func_00120F78(self, D_00368D78) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F028);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F110);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F238);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F3E8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F478);

extern "C" int func_0011F4D8(void* self) {
    if (D_00368748[0]) {
        return 0;
    }
    return func_0011F110(self);
}

extern "C" int func_0011F510(void* self) {
    if (D_00368748[0]) {
        return func_0011F000(self);
    }
    return func_0011F028(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F548);

extern "C" void func_0011F598(void* self, int flags) {
    ((void**)self)[0x11] = D_00338F30;
    func_0011DA60(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F710);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F768);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FA98);

extern "C" void func_0011FB38(S_0011FB38* self) {
    self->unk48 = -1;
    self->unk14C = 0;
    self->unk150 = 0;
    self->unk154 = 0;
    self->unk158 = 0;
}

extern "C" int func_0011FB58(void) {
    return 0;
}

extern "C" int func_0011FB60(void) {
    return 0;
}

extern "C" int func_0011FB68(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FB70);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FBE0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FC50);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FCC0);

extern "C" void func_0011FD30(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FD38);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FDC0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FF58);

extern "C" int func_00120008(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120010);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001200D0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120180);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001203A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001204D8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120598);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120628);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001206C8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001206D0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120710);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001207A0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001208C0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120938);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120A40);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C08);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C58);

extern "C" int func_00120C60(void) {
    return func_001208C0()->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C80);

extern "C" int func_00120DF0(void) {
    return 1;
}

extern "C" void func_00120DF8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120E00);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120E40);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120F78);
