#include "common.h"

struct S233C_N {
    s32 unk0;
    S233C_N* unk4;
    s32* unk8;
};

struct S233C_I {
    s32 unk0;
    S233C_N* unk4;
};

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
extern List232 D_003979F0;
void func_0011E050(int);
void func_0011E130(void);
extern int D_0036FBE8;
bool func_00230230(int, int);
void func_001519B0(int, int);
extern List232 D_00396F60;
void func_00289F90(int);
void strcpy(int, int);
void func_00113528(int);
char* func_0030E720(int, void*);
extern u8 D_0036FD68[];
int func_0027D188(int, u32, char**, int);
int func_0027D1F8(int, u32, int*, int);
void func_002316D0(int, int);
int func_002320A8(int, int);
int func_00232670(int, int);
u32 CrcFromPathLowercase(const char*);
extern u8 D_003544A8[];
int func_00233728(void);
int func_001150E0(int, void*);
void func_00223318(int);
void func_002335F0(int, int);
void func_002333F8(int, int, int, int, void*);
extern int D_0036FBE4;
extern u8 D_00396AEC[];
extern u8 D_003544D8[];
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

GP_DATA(D_0036FBE4);
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

extern "C" int CFunc_LinkRawAsset(int s) {
    char* p = 0;
    int x;
    char* q = (char*)D_003544A8;
    int v;
    func_0027D188(s, 0, &p, 0);
    if (p) {
        v = CrcFromPathLowercase(p);
    } else {
        x = 0;
        func_0027D1F8(s, 0x21902065, &x, 1);
        v = x;
    }
    func_0027D188(s, 0xF2C9AC8B, &q, 0);
    func_002316D0(CrcFromPathLowercase(q), v);
    return 1;
}

extern "C" int CFunc_UnlinkRawAsset(int s) {
    char* p = 0;
    int x;
    char* q = (char*)D_003544A8;
    int v;
    func_0027D188(s, 0, &p, 0);
    if (p) {
        v = CrcFromPathLowercase(p);
    } else {
        x = 0;
        func_0027D1F8(s, 0x21902065, &x, 1);
        v = x;
    }
    func_0027D188(s, 0xF2C9AC8B, &q, 0);
    int c = CrcFromPathLowercase(q);
    if ((func_002320A8(c, v) ^ 1) != 0) return 0;
    return (func_00232670(c, v) ^ 1) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233B68);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233B70);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233BA0);

extern "C" void func_00233BE8(char* p, int a) {
    if ((*(int (**)(char*))(p + 4))(p + 8)) {
        func_00289F90(a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233C28);

extern "C" s32* func_00233C50(s32 v) {
    S233C_I end;
    S233C_I it;
    it.unk4 = (S233C_N*)D_003979F0.unk8;
    end.unk4 = (S233C_N*)&D_003979F0.unk4;
    if (it.unk4 != end.unk4) {
        do {
            if (*it.unk4->unk8 == v) {
                return it.unk4->unk8;
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

extern "C" char* func_00233CA8(S232* self, int i) {
    return self->unk90 + i * 0xF58;
}

extern "C" void func_00233CC0(int a, int b) {
    strcpy(b, a + 0xB0);
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
