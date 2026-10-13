#include "common.h"

struct S232 {
    int unk0;
    char pad4[0x8C];
    char* unk90;
};

struct List232 {
    int unk0;
    void* unk4;
    void* unk8;
};

extern "C" {
void func_0011E050(int);
void func_0011E130(void);
extern int D_0036FBE8;
bool func_00230230(int, int);
void func_001519B0(int, int);
extern List232 D_00396F60;
void func_00289F90(int);
void func_0030A970(int, int);
void func_00113528(int);
char* func_0030E720(int, void*);
extern u8 D_0036FD68[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002320A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002320A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002321B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232668);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232670);

extern "C" void func_002327A8(void) {
    func_0011E050(1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002327C8);

extern "C" void func_00232908(int a, int b, int c) {
    if (!a && b) {
        func_001519B0(b, c);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232930);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232A58);

extern "C" void func_00232BC8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", CFunc_LoadPak);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002333F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002335F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233728);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", CFunc_UnloadPak);

extern "C" bool func_002338E0(S232* self) {
    return !func_00230230(self->unk0, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", CFunc_WaitUnloadPak);

GP_DATA(D_0036FBE8);
extern "C" int CFunc_AsyncLoadPakInProgress(void) {
    func_0011E130();
    return D_0036FBE8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", CFunc_LinkRawAsset);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", CFunc_UnlinkRawAsset);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233B68);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233B70);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233BA0);

extern "C" void func_00233BE8(char* p, int a) {
    if ((*(int (**)(char*))(p + 4))(p + 8)) {
        func_00289F90(a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233C28);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233C50);

extern "C" char* func_00233CA8(S232* self, int i) {
    return self->unk90 + i * 0xF58;
}

extern "C" void func_00233CC0(int a, int b) {
    func_0030A970(b, a + 0xB0);
    func_00113528(b);
    char* r = func_0030E720(b, D_0036FD68);
    if (r) {
        *r = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233D10);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233E10);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00234080);
