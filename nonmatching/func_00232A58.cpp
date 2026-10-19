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
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003544E8[];
void func_00119490(s32 h, s32 v);
s32 func_00119610(s32 h, s32 v);
void func_001194B8(s32 h);
void* Heap_Alloc(s32 h, s32 size, s32 a, s32 b);
void func_00289F70(s32 a, s32 b, void* c, s32 d);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
void func_0027C448(s32 a, u32 k, s32 v);
void func_0027C160(s32 a, u32 k, s32 v);
void func_0028D1B0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_0027AC90(s32 a);
void func_00113250(s32 a);
void func_002305C0(void);
extern u8 D_003546D8[];
s32 func_0028D578(s32 a);
void func_0027C028(s32 a, u32 k, void* v);
s32 func_002763E0(s32 a, s32 b);
void func_0027C7D0(s32 a, u32 k, s32 v);
void func_0028C9F0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002320A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002320A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_002321B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232668);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232670);

extern "C" void func_002327A8(void) {
    func_0011E050(1);
}

GP_DATA(D_0036FBE8);
extern "C" void func_002327C8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (c != 0) {
        s32 t = func_0027AA70(func_001287F0(8, 1));
        if (a != 0) {
            func_0027C448(t, 0, 0x6086AA70);
        } else {
            func_0027C448(t, 0, 0xFF03CC4E);
        }
        func_0027C448(t, 0x520C0C9C, d);
        func_0027C448(t, 0x26861025, b);
        func_0027C160(t, 0xEC953EEC, e);
        func_0028D1B0(c, t, 0, 0, 0, 0, 0, 0, 0, 0);
        if (t != 0) {
            func_0027AC90(t);
            func_00113250(t);
        }
    }
    if (a == 0) {
        func_002305C0();
        D_0036FBE8 = 0;
    }
}

extern "C" void func_00232908(int a, int b, int c) {
    if (!a && b) {
        func_001519B0(b, c);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00232930);

struct E2329 {
    s32 unk0;
    char pad4[4];
    s32 unk8;
    char padC[0x18];
    s32 unk24;
    s32 unk28;
    char pad2C[8];
    char* unk34;
};

struct O2329 {
    char pad0[0x10];
    u32 unk10;
};

extern "C" {
extern E2329 D_00396F70[];
extern char func_00232930[];
void func_0011DB50(void*, void*, s32, s32);
void func_0011DC18(void*);
}

extern "C" s32 func_00232A58(O2329* o, s32 a1, s32 a2) {
    s32 i;
    E2329* t = D_00396F70;
    E2329* e;
    for (i = 0; i < 0x30; i += 3) {
        e = &t[0];
        if (e->unk0 != 0 && (O2329*)e->unk34 == o) {
            o->unk10 |= 0x80;
            func_0011DB50(e->unk34, func_00232930 + 8, 0, 0);
            e->unk28 = a1;
            e->unk24 = a2;
            e->unk8 = 1;
            func_0011DC18(e->unk34);
            return 1;
        }
        e = &t[1];
        if (e->unk0 != 0 && (O2329*)e->unk34 == o) {
            o->unk10 |= 0x80;
            func_0011DB50(e->unk34, func_00232930 + 8, 0, 0);
            e->unk28 = a1;
            e->unk24 = a2;
            e->unk8 = 1;
            func_0011DC18(e->unk34);
            return 1;
        }
        e = &t[2];
        if (e->unk0 != 0 && (O2329*)e->unk34 == o) {
            o->unk10 |= 0x80;
            func_0011DB50(e->unk34, func_00232930 + 8, 0, 0);
            e->unk28 = a1;
            e->unk24 = a2;
            e->unk8 = 1;
            func_0011DC18(e->unk34);
            return 1;
        }
        t += 3;
    }
    return 1;
}

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

extern "C" s32 CFunc_WaitUnloadPak(s32 self, s32 params) {
    s32 f = func_00233728();
    if (func_00230230(f, 0)) {
        s32 h = D_00368A38[0];
        void* fn = (void*)func_002338E0;
        func_00119490(h, func_00119610(h, 5));
        void** m = (void**)Heap_Alloc(D_00368A38[0], 0xC, 1, 0);
        m[0] = D_003544E8;
        m[1] = fn;
        m[2] = (void*)f;
        func_00289F70(params, 7, m, 0);
        func_001194B8(D_00368A38[0]);
    }
    return 1;
}

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

struct J2320 {
    s32 unk0;
    s32 unk4;
};

extern "C" {
void* func_0027B300_j(s32 l, void* it) __asm__("func_0027B300");
s32 func_0027D470_j(s32 p, u32 key, J2320** v, s32 req) __asm__("func_0027D470");
s32 func_002763E0_j(s32 a, s32 b) __asm__("func_002763E0");
}

extern "C" s32 func_00233D10(s32 a) {
    char* it = 0;
    s32 best = 0;
    s32 list = func_002763E0_j(a, 1);
    while ((it = (char*)func_0027B300_j(list, it)) != 0) {
        s32 v = 0;
        if ((*(u32*)it & 0xFE00) == 0x3400) {
            v = func_00233D10(*(s32*)(it + 8));
        } else {
            s32 n = *(s32*)(it + 8);
            J2320* x = 0;
            J2320* y = 0;
            if (func_0027D470_j(n, 0x7A354E97, &x, 0) != 0) {
                v = x->unk4;
            }
            if (func_0027D470_j(n, 0xB0EAA257, &y, 0) != 0) {
                v += y->unk4;
            }
        }
        best = best < v ? v : best;
    }
    return best;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233E10);

INCLUDE_ASM("asm/nonmatchings/game/t_2320A0", func_00233F08);

extern "C" void func_00234080(s32 a, char* b) {
    char buf[0x40];
    func_00233CC0((int)b, (int)buf);
    u32 crc = CrcFromPathLowercase(buf);
    s32 h = func_001150E0(a, D_003546D8);
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
}
