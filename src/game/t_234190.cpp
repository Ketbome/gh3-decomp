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
int func_00230230(int, int);
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
extern u8 D_003546F0[];
void func_00233CC0(void* a, void* b);
s32 func_0028D578(s32 a);
s32 func_0027AA70(s32 a);
s32 func_001287F0(s32 a, s32 b);
void func_0027C448(s32 a, u32 k, s32 v);
void func_0027C028(s32 a, u32 k, void* v);
s32 func_002763E0(s32 a, s32 b);
void func_0027C7D0(s32 a, u32 k, s32 v);
void func_0028C9F0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_0027AC90(s32 a);
void func_00113250(s32 a);
void func_0028D720(s32 a);
}

extern "C" void func_00234190(s32 a, void* bp) {
    char* b = (char*)bp;
    char buf[0x40];
    func_00233CC0(b, buf);
    u32 crc = CrcFromPathLowercase(buf);
    s32 h = func_001150E0(a, D_003546F0);
    if (func_0028D578(h) != 0) {
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xBC5BF0CE, crc);
        func_0027C028(t, 0x1AB858E2, buf);
        s32 r = func_002763E0(*(s32*)(b + 0x88), 0);
        if (r != 0) {
            func_0027C7D0(t, 0x7031F10C, r);
        }
        func_0028C9F0(h, t, 0, 0, 0, 0);
        if (t != 0) {
            func_0027AC90(t);
            func_00113250(t);
        }
    }
    s32 x = *(s32*)(b + 0x84);
    if (x != 0) {
        func_0028D720(x);
    }
}

struct O2342 {
    void* unk0;
    char pad4[0x110];
    int unk114;
};

struct C2342 {
    char pad0[0x40];
    O2342* unk40;
    char pad44[0x784];
    int unk7C8;
    char pad7CC[0x784];
    int unkF50;
};

struct P2342 {
    char pad0[0x18];
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    char pad4C[0x4C];
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    char padAC[0x7E];
    u8 unk12A;
    char pad12B;
    u8 unk12C;
    u8 unk12D;
};

extern int D_0036FD30;
extern int D_0036FD34;
extern int D_0036FD38;
extern int D_0036FD3C;
extern int D_0036FD40;
extern int D_0036FD44;
extern int D_0036FD48;
extern int D_0036FD4C;
extern int D_0036FD50;
extern int D_0036FD54;
extern int D_0036FD58;
extern int D_0036FD5C;
extern int D_0036FD60;
extern "C" void func_001519B0(int, void*);
extern "C" void func_00233F20(void*, void*);

GP_DATA(D_0036FD34);
GP_DATA(D_0036FD3C);
GP_DATA(D_0036FD30);
GP_DATA(D_0036FD38);
GP_DATA(D_0036FD40);
GP_DATA(D_0036FD44);
GP_DATA(D_0036FD48);
GP_DATA(D_0036FD4C);
GP_DATA(D_0036FD50);
GP_DATA(D_0036FD54);
GP_DATA(D_0036FD58);
GP_DATA(D_0036FD5C);
GP_DATA(D_0036FD60);
extern "C" void func_002342B0(int a, int b, C2342* c, P2342* d, int e) {
    if (e == 1) {
        c->unk40->unk114 = 1;
        c->unk7C8 = 0;
        c->unkF50 = 0;
        d->unk12D = 0;
        return;
    }
    if (a == 0) {
        d->unk12A = 1;
        d->unk12C = 0;
        d->unk12D = 0;
        d->unk98 = b;
        d->unk9C = 0;
        d->unkA0 = 0;
        d->unkA4 = 0;
        d->unkA8 = 0;
        if (b != 0) {
            func_001519B0(b, (char*)d + 0xB0);
        }
        d->unk18 = D_0036FD30;
        d->unk20 = D_0036FD34;
        d->unk24 = D_0036FD38;
        d->unk1C = D_0036FD3C;
        d->unk28 = D_0036FD40;
        d->unk2C = D_0036FD44;
        d->unk30 = D_0036FD48;
        d->unk34 = D_0036FD4C;
        d->unk38 = D_0036FD50;
        d->unk40 = D_0036FD54;
        d->unk3C = D_0036FD58;
        d->unk44 = D_0036FD5C;
        d->unk48 = D_0036FD60;
        D_0036FD30 = 0;
        D_0036FD34 = 0;
        D_0036FD38 = 0;
        D_0036FD3C = 0;
        D_0036FD40 = 0;
        D_0036FD44 = 0;
        D_0036FD48 = 0;
        D_0036FD4C = 0;
        D_0036FD50 = 0;
        D_0036FD54 = 0;
        D_0036FD58 = 0;
        D_0036FD5C = 0;
        D_0036FD60 = 0;
        func_00233F20(c->unk40->unk0, d);
    }
}

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

struct E2348 {
    char pad0[0x44];
    s32 a[1];
};

extern "C" void func_002348D8(char* a, char* b) {
    if ((func_00230230(CrcFromPathLowercase(b + 0xB0), *(s32*)(b + 0x134)) ^ 1) != 0) {
        *(u8*)(b + 0x128) = 0;
        *(u8*)(b + 0x12A) = 0;
        *(u8*)(b + 0x12C) = 0;
        char* o = *(char**)(a + 0x40);
        if (*(s32*)(o + 0x8C) != 0) {
            for (s32 i = 0; i < *(s32*)(o + 0x88); i++) {
                s32 e = (s32)func_00233CA8(o, i);
                if (*(s32*)(*(s32*)(b + 0x134) * 0x38 + e + 0x2C) == *(s32*)b) {
                    ((E2348*)e)->a[*(s32*)(b + 0x134)] = 0;
                }
            }
        }
    }
}

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

struct N234 {
    s32 unk0;
    N234* unk4;
    char* unk8;
};

struct I234 {
    s32 unk0;
    N234* unk4;
};

struct L234 {
    char pad0[4];
    N234* unk4;
    N234* unk8;
};

extern "C" {
extern L234 D_003979F0;
extern void (*D_0036FD28)(void*);
void func_00234A10(char*);
void func_00234B88(char*);
}

GP_DATA(D_0036FD28);
extern "C" void func_00234CB8(void) {
    I234 end;
    I234 it;
    u8 buf[0x10];
    it.unk4 = D_003979F0.unk8;
    end.unk4 = (N234*)((char*)&D_003979F0 + 4);
    if (it.unk4 != end.unk4) {
        do {
            char* o = it.unk4->unk8;
            int i;
            for (i = 0; i < *(int*)(o + 0x88); i++) {
                char* e = func_00233CA8(o, i);
                if (*(int*)e != 0) {
                    func_00234A10(e);
                    if (*(int*)(e + 0x7C8) == 0) {
                        func_00234B88(e);
                        if (*(int*)(e + 0xF50) == 0) {
                            func_00234C70(e);
                        }
                    }
                }
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
    if (func_00233C50(0x7A354E97) != 0) {
        func_0027AA70((s32)buf);
        func_0027C448((s32)buf, 0x6C525544, 0x7A354E97);
        D_0036FD28(buf);
        func_0027AC90((s32)buf);
    }
}

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

extern "C" {
void func_00223340(void);
void func_00234CB8(void);
int func_00276008(u32, int);
void func_002532C0(int, int);
int func_0027D188(int, u32, int*, int);
void func_002350B0(char*, int);
}

static inline int Ne_234190(int a, int b) {
    return a != b;
}

extern "C" int func_0027D870_i(int, u32, int*, int) __asm__("func_0027D870");
extern "C" int CFunc_SetPakManCurrent(int p) {
    int a = 0;
    int m2;
    int b = 0;
    func_0027D870(p, 0x6C525544, &a, 1);
    if (a == 0x7A354E97) func_00223340();
    func_0027D1F8(p, 0x53F1DF98, &b, 0);
    int m = func_00233C50(a);
    m2 = m;
    if (m2 == 0) return 0;
    char* o = func_00233CA8((char*)m, b);
    int h = 0;
    func_0027D870_i(p, 0xF2C9AC8B, &h, 0);
    if (h == 0) {
        int path;
        func_0027D188(p, 0xDCD6CB13, &path, 1);
        h = CrcFromPathLowercase((void*)path);
    }
    if (h == 0xD98E0FD5) h = 0x6956C518;
    func_002350B0(o, h);
    func_00234CB8();
    int f = 0;
    if (a == 0x7A354E97) f = Ne_234190(0x806FFF30, h);
    if (f) {
        int c = func_00276008(0x8320D478, 0);
        func_002532C0(h, c);
    }
    return 1;
}

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
