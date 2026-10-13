#include "common.h"

extern "C" {
void func_00244930_1(void*) __asm__("func_00244930");
extern u8 D_00397A40[];
extern u8 D_00397A00[];
void func_002432F8(int, int);
void func_00119400(int, void*);
extern int D_0036FF08;
int func_002443C0(void*, int, int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00354B70[];
u8* func_00246B30(u8*);
u8* func_00246B78(u8*);
void func_00243FA8(int, int, int, int, int);
}

extern "C" void func_00243208(void** p) {
    func_00244930_1(p[2]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243228);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002432C0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002432F8);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243360);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243398);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002433A8);

extern "C" int func_00243470(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243478);

extern "C" int func_00243498(void) {
    return 0;
}

extern "C" void func_002434A0(void) {
}

extern "C" u8* func_002434A8(void) {
    return D_00397A40;
}

extern "C" void func_002434B8(void) {
}

extern "C" u8* func_002434C0(void) {
    return D_00397A00;
}

extern "C" char* func_002434D0(char* p) {
    return p + 0xA0;
}

extern "C" char* func_002434D8(char** p) {
    return p[2] + 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002434E8);

struct N243 {
    char pad0[0xC];
    N243* prev;
    N243* next;
    void* vt;
};

extern "C" void func_00243558(N243* p, int flags) {
    N243* t = p->next;
    p->vt = D_00354B70;
    t->prev = p->prev;
    p->prev->next = p->next;
    p->prev = p;
    p->next = p;
    if (flags & 1) func_00119400(D_00368A38[0], p);
}

extern "C" void func_002435B8(void) {
    func_002432F8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002435D8);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243678);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002436D8);

extern "C" void* func_002436E0(int* p) {
    p[0] = 0;
    p[1] = 0;
    return p;
}

extern "C" int D_00368A38[] __attribute__((section(".sdata")));

extern "C" void func_002436F0(void* p, int f) {
    if (f & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_00243720(int* p, int v) {
    *p = (*p & ~3) | (v & 3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243740);

extern "C" int func_00243A98(u8* n) {
    register u8* c asm("$16") = n + 4;
    int r;
    if (((*n & 3) ^ 3) != 0) {
        int a = func_00243A98(func_00246B30(c));
        int b = func_00243A98(func_00246B78(c)) + 1;
        asm("" : "+r"(b));
        r = a + b;
    } else {
        r = 1;
    }
    return r;
}

extern "C" int func_00243B08(u8* n) {
    register u8* c asm("$16") = n + 4;
    int r;
    if (((*n & 3) ^ 3) != 0) {
        register int a asm("$17") = func_00243B08(func_00246B30(c));
        r = a + func_00243B08(func_00246B78(c));
    } else {
        r = *(u16*)(n + 2);
    }
    return r;
}

extern "C" u32 func_00243B70(u8* n) {
    register u8* c asm("$16") = n + 4;
    u32 b;
    if (((*n & 3) ^ 3) != 0) {
        register u32 a asm("$17") = func_00243B70(func_00246B30(c));
        b = func_00243B70(func_00246B78(c));
        if (a < b) b = a;
    } else {
        b = *(u32*)(n + 4);
    }
    return b;
}

extern "C" void func_00243BE0(u32* p, int v) {
    if (v) {
        *p |= 1;
    } else {
        *p &= 0xFFFFFFFE;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243C10);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243E90);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00243FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244060);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244128);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002441D0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002443C0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_002445A0);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244898);

extern "C" int func_00244930(char* p, int b, int c) {
    int t = *(int*)(p + 0x34);
    if (!t) {
        return 0;
    }
    D_0036FF08 = 0;
    return func_002443C0(p, t, b, c) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244970);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244B68);

INCLUDE_ASM("asm/nonmatchings/game/t_243208", func_00244C40);
