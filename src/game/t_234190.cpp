#include "common.h"

struct E234 {
    void* unk0;
    char pad4[0xC];
};

struct S234 {
    char pad0[0x7D0];
    E234 unk7D0[0x78];
    int unkF50;
};

struct S234b {
    char pad0[0x12A];
    u8 unk12A;
    u8 unk12B;
    u8 unk12C;
    u8 unk12D;
    u8 unk12E;
};

extern "C" {
extern int D_0036FD2C;
void func_00226098(void);
void func_0014EAC8(int);
extern void (*D_0036FD64)(void);
void func_0027D870(int, u32, int*, int);
int func_00233C50(int);
int func_00232A58(int, void*, void*);
int func_0023A458(void*, int);
int func_00233E10(int, int*, int);
void func_0027C160(int, u32, int);
char* func_00233CA8(char*, int);
int func_00239000(char*, char*, void*);
extern u8 D_0036FCE0[];
int func_0027D1F8(int, u32, int*, int);
void func_0027C448(int, u32, int);
int func_002366E0(int, void*, int);
void func_0027C028(int, u32, void*);
extern u8 D_0036FD78[];
s32 CrcFromPathLowercase(void* p);
s32 func_001150E0(s32 a, u8* b);
void func_00223318(s32 a);
void func_002333F8(s32 a, s32 b, s32 c, void (*f)(void), s32 d);
void func_00234190(s32 a, void* b);
void func_002348A0(void);
extern u8 D_00354700[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234190);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002342B0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002343E8);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234668);

extern "C" void func_00234808(void) {
}

extern "C" void func_00234810(char* a, char* b) {
    func_00223318(func_001150E0(*(s32*)(b + 0x80), D_00354700));
    *(u8*)(b + 0x12A) = 0;
    *(u8*)(b + 0x128) = 1;
    *(u8*)(b + 0x12C) = 0;
    func_00234190(**(s32**)(a + 0x40), b);
    func_002333F8(CrcFromPathLowercase(b + 0xB0), *(s32*)(b + 0x134), *(s32*)b, func_00234808, 0);
    func_002348A0();
}

GP_DATA(D_0036FD64);
extern "C" void func_002348A0(void) {
    func_00226098();
    func_0014EAC8(1);
    if (D_0036FD64) {
        D_0036FD64();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002348D8);

extern "C" void func_002349B0(S234b* self) {
    self->unk12A = 1;
    self->unk12E = 1;
    self->unk12D = 0;
    self->unk12C = 0;
}

extern "C" void func_002349C8(int a, S234b* p) {
    func_00232A58(*(int*)((char*)p + 0xAC), p, (void*)func_002349B0);
    *(u8*)((char*)p + 0x128) = 0;
    p->unk12E = 1;
    p->unk12A = 0;
    p->unk12C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234A10);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234B88);

extern "C" void func_00234C70(char* p) {
    *(int*)(p + 4) = 0;
    u32 k = *(u32*)p;
    if (k != 0x806FFF30) {
        *(int*)(p + 4) = func_0023A458(p + 8, k);
    }
    *(int*)p = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234CB8);

extern "C" int func_00234DD0(int a) {
    if (a != 0xC4E78E22) {
        char* t = (char*)func_00233C50(a);
        if (*(int*)(t + 0x114)) {
            *(int*)(t + 0x114) = 0;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234E18);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00234F68);

extern "C" void func_00235080(S234* self, S234b* b) {
    if (!b->unk12A) {
        self->unk7D0[self->unkF50].unk0 = b;
        self->unkF50++;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_002350B0);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_CreatePakManMap);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_DestroyPakManMap);

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_PendingPakManLoads);

extern "C" int CFunc_ExistsPakManMap(int a) {
    int tmp = 0;
    func_0027D870(a, 0x6C525544, &tmp, 1);
    return func_00233C50(tmp) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", CFunc_SetPakManCurrent);

extern "C" int CFunc_GetPakManCurrent(int s, char* c) {
    int a = 0;
    int b = 0;
    func_0027D870(s, 0x6C525544, &a, 1);
    func_0027D1F8(s, 0x53F1DF98, &b, 0);
    char* o = *(char**)(func_00233CA8((char*)func_00233C50(a), b) + 4);
    int v = 0x806FFF30;
    if (o) v = *(int*)(o + 0x80);
    func_0027C448(*(int*)(c + 0x20), 0xF2C9AC8B, v);
    return 1;
}

extern "C" int CFunc_GetPakManCurrentName(int s, char* c) {
    char buf[0x80];
    int a = 0;
    int b = 0;
    func_0027D870(s, 0x6C525544, &a, 1);
    func_0027D1F8(s, 0x53F1DF98, &b, 0);
    int r;
    if (func_002366E0(a, buf, 0) == 0) {
        func_0027C028(*(int*)(c + 0x20), 0xDCD6CB13, D_0036FD78);
        r = 0;
    } else {
        func_0027C028(*(int*)(c + 0x20), 0xDCD6CB13, buf);
        r = 1;
    }
    return r;
}

extern "C" int CFunc_GetPakManNumFreeSlots(int s, char* c) {
    int a = 0;
    func_0027D870(s, 0x6C525544, &a, 1);
    int b = -1;
    int r = func_00233E10(a, &b, 0);
    func_0027C160(*(int*)(c + 0x20), 0xA0C8A652, r);
    if (r) {
        func_0027C160(*(int*)(c + 0x20), 0x14CB5C86, b);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_234190", func_00236100);

extern "C" int CFunc_EnablePakManStreaming(void) {
    D_0036FD2C = 1;
    return 1;
}

GP_DATA(D_0036FD2C);
extern "C" int CFunc_DisablePakManStreaming(void) {
    D_0036FD2C = 0;
    return 1;
}

extern "C" int CFunc_RefreshPakManSizes(int s) {
    int a = 0;
    func_0027D870(s, 0x6C525544, &a, 1);
    char* t = (char*)func_00233C50(a);
    for (int i = 0; i < *(int*)(t + 0x88); i++) {
        func_00239000(func_00233CA8(t, i) + 8, t + 8, D_0036FCE0);
    }
    return 1;
}
