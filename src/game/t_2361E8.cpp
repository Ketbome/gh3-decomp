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

INCLUDE_ASM("asm/nonmatchings/game/t_2361E8", func_00236520);

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
