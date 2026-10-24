#include "common.h"

struct Node236 {
    Node236* next;
    Node236* prev;
};

struct List236 {
    int unk0;
    Node236 unk4;
};

extern "C" {
extern void* D_0036FD64;
extern void (*D_0036FD28)(void);
void func_002367E0(int, int);
extern List236 D_003979F0;
extern u8 D_00354A30[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void*);
void func_0023A350(void*);
s32 func_00233C50(void);
char* func_00233CA8_p(s32 a, s32 b) __asm__("func_00233CA8");
s32 func_00233CA8(s32 a, s32 b);
char* func_0023A458(s32 a, s32 b);
void func_00233CC0(char* q, char* buf);
}

GP_DATA(D_0036FD28);
extern "C" int CFunc_UpdatePakManVisibility(void) {
    D_0036FD28();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00236210);

struct E236 {
    char pad0[0x80];
    s32 unk80;
    char pad84[4];
    s32 unk88;
    char pad8C[0xC];
    s32 unk98;
    char pad9C[0x8E];
    u8 unk12A;
};

struct Sub236 {
    char pad0[0xC];
    s32 count;
};

struct C236 {
    s32 unk0;
    E236* unk4;
    Sub236 sub;
};

extern "C" {
extern s32 D_0036FD2C;
void* func_00233CA8_c(s32 a, s32 b) __asm__("func_00233CA8");
E236* func_0023A4F8(void* p, s32 i);
s32 func_0028D558(u32 k);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 p);
void func_0027C448(s32 o, u32 k, s32 v);
void func_0028D1D8(u32 k, s32 o, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
void func_0027AC90(s32 o);
void func_00113250(s32 o);
void func_002350B0(void* p, s32 v);
void func_00234CB8(void);
}

GP_DATA(D_0036FD2C);
extern "C" void func_00236520(void* unused, s32 id) {
    if (D_0036FD2C != 0) {
        s32 t = func_00233C50();
        if (t != 0) {
            C236* c = (C236*)func_00233CA8_c(t, 0);
            s32 i = 0;
            E236* found = 0;
            Sub236* sub0 = &c->sub;
            E236* first = c->unk4;
            if (i < sub0->count) {
                Sub236* sub = sub0;
                asm("" : "+r"(sub));
                do {
                    E236* e = func_0023A4F8(sub, i);
                    if (e->unk12A != 0) {
                        found = (e->unk98 ^ id) == 0 ? e : found;
                    }
                    i++;
                } while (i < sub->count);
            }
            s32 v = c->unk0;
            if ((v != 0 || found != first) && found != 0 && found->unk80 != v) {
                if (func_0028D558(0xE238C13D) != 0) {
                    s32 o = func_0027AA70(func_001287F0(8, 1));
                    s32 w = found->unk88;
                    if (w != 0) {
                        func_0027C448(o, 0x65629C05, w);
                    }
                    if (first != 0) {
                        s32 w2 = first->unk88;
                        if (w2 != 0) {
                            func_0027C448(o, 0x0E48C649, w2);
                        }
                    }
                    func_0028D1D8(0xE238C13D, o, 0, 0, 0, 0, 0, 0, 0, 0);
                    if (o != 0) {
                        func_0027AC90(o);
                        func_00113250(o);
                    }
                }
                func_002350B0(c, found->unk80);
                func_00234CB8();
            }
        }
    }
}

extern "C" void func_002366C8(void) {
}

extern "C" void func_002366D0(void* v) {
    D_0036FD64 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_002366D8);

extern "C" s32 func_002366E0(s32 unused, char* buf, s32 k) {
    s32 t = func_00233C50();
    if (t != 0) {
        char* o = func_00233CA8_p(t, k);
        if (o != 0) {
            char* q = *(char**)(o + 4);
            if (q != 0 && (q + 0xB0) != 0 && *(s8*)(q + 0xB0) != 0) {
                func_00233CC0(q, buf);
                return 1;
            }
        }
    }
    *buf = 0;
    return 0;
}

extern "C" s32 func_00236760(s32 unused, s32 a, s32 b, s32 c) {
    s32 t = func_00233C50();
    if (t != 0) {
        char* o = func_0023A458(func_00233CA8(t, c) + 8, a);
        if (o != 0) {
            o[0x12B] = b;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_002367D0);

extern "C" void func_002367E0(int a, int b) {
    if (b == 0xFFFF && a) {
        int* d = (int*)&D_003979F0;
        int* n = d + 1;
        d[1] = (int)n;
        n[1] = (int)n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00236810);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_002368D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_002368F8);

extern "C" void* func_00236900(int* p) {
    p[0xD] = (int)D_00354A30;
    p[0xC] = 1;
    p[2] = 0;
    p[3] = 0;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
    p[6] = 0;
    p[0] = 0;
    p[1] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    return p;
}

extern "C" void func_00236948(char* p, int f) {
    *(u8**)(p + 0x34) = D_00354A30;
    func_0023A350(p);
    if (f & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00236998);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00236F18);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00237320);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_002378D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00237BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00237BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00237CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00237DE0);
