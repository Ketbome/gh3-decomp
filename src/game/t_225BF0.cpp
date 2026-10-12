#include "common.h"

struct VEntry225 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S225 {
    VEntry225* unk0;
};

struct S225b {
    char pad0[0xC];
    int unkC;
    int unk10;
};

struct List225 {
    int unk0;
    int unk4;
    void* unk8;
};

extern "C" {
extern List225 D_003938C8;
void func_00226B28(int, int);
void func_001EABC0(int, int);
void func_002A1918(int, int, int, int, int);
void func_00226CD0(int, int);
void func_00226E30(int, int);
void func_0027D870(int, int, int*, int);
void func_00226918(int);
int func_00225E20(int);
void func_00225A78(void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225BF0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225C28);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225D78);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225E20);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225E70);

extern "C" void func_00225F58(int a, int b) {
    func_002A1918(a, b, 0, 0, 0);
}

extern "C" int func_00225F80(void) {
    return D_003938C8.unk8 != &D_003938C8.unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226030);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226098);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226178);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002262A0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002262A8);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226338);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226528);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226730);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226888);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226918);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226970);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002269D8);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226A58);

extern "C" void func_00226AF0(int a) {
    int tmp = 0;
    func_0027D870(a, 0, &tmp, 1);
    func_00226918(tmp);
}

extern "C" int func_00226B20(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226B28);

extern "C" void func_00226C78(int a, int b) {
    func_00226CD0(b, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226CA0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226E30);

extern "C" void func_00226F40(void) {
    func_00226B28(1, 0xFFFF);
}

extern "C" void func_00226F60(S225* self, int a, S225b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry225* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227048);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002270A0);

extern "C" void func_00227140(void* self, int a, int* b) {
    func_001EABC0(*b, 1);
}

extern "C" void func_00227160(void* self, int a, int b) {
    func_001EABC0(b, 0);
}

extern "C" void func_00227180(S225* self, int a, S225b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry225* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002271C0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227268);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002272C0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227570);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227B80);
