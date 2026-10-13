#include "common.h"

struct S0027AA58 {
    char pad[0x2];
    u8 unk2;
    u8 unk3;
    int unk4;
};

struct S0027B300 {
    char pad[0x4];
    int unk4;
    char pad1[0x4];
    int unkC;
};

struct S27A_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    u32 key;
    u32 val;
    S27A_Comp *next;
};
struct S27A_List {
    char pad0[4];
    S27A_Comp *unk4;
};

extern "C" {
void func_0027AAD8_v(void) asm("func_0027AAD8");
void *func_001D0900(int, int);
void func_00279358(void *, void *, int, int);
void func_0027BDB0(void *, void *, int);
void func_002791E0(void *);
void func_0025C5E8(void *);
void func_0027AAD8(int, int);
extern u8 D_003711D8;
void func_0027AA58(S0027AA58 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002797A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002798B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002798B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_00279F10);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027A9B8);

GP_DATA(D_003711D8);
extern "C" void func_0027AA58(S0027AA58* p) {
    p->unk4 = 0;
    p->unk2 = 0;
    p->unk3 = D_003711D8;
}

extern "C" S0027AA58 *func_0027AA70(S0027AA58 *p) {
    func_0027AA58(p);
    return p;
}

extern "C" S0027AA58 *func_0027AA98(S0027AA58 *a, int b) {
    func_0027AA58(a);
    func_0027AAD8((int)a, b);
    return a;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AAD8);

extern "C" S27A_List *func_0027ABB0(S27A_List *a, S27A_List *b) {
    if (a->unk4 == 0) {
        func_0027AAD8_v();
        return a;
    }
    S27A_Comp *s = b->unk4;
    if (s != 0) {
        do {
            S27A_Comp *c = (S27A_Comp *)func_001D0900(0x10, 1);
            c->key = 0;
            c->next = 0;
            c->val = 0;
            c->b8 = 0;
            c->type = 0;
            c->unk2 = 0;
            func_00279358(c, s, 0, 0);
            func_0027BDB0(a, c, 0);
            s = s->next;
        } while (s != 0);
    }
    return a;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AC80);

struct S27AC90_N {
    char pad0[4];
    int unk4;
    char pad8[4];
    S27AC90_N *unkC;
};
struct S27AC90 {
    char pad0[3];
    u8 unk3;
    S27AC90_N *unk4;
};
extern "C" void func_0027AC90(S27AC90 *p) {
    S27AC90_N *n = p->unk4;
    if (n != 0) {
        do {
            S27AC90_N *next = n->unkC;
            func_002791E0(n);
            func_0025C5E8(n);
            n = next;
        } while (n != 0);
    }
    p->unk4 = 0;
    p->unk3 = D_003711D8;
}

extern "C" void func_0027ACF8(S27AC90 *p, int key) {
    S27AC90_N *prev = 0;
    S27AC90_N *n = p->unk4;
    S27AC90_N *next;
    if (n != 0) {
        do {
            next = n->unkC;
            if (n->unk4 == key) {
                if (prev != 0) {
                    prev->unkC = next;
                } else {
                    p->unk4 = next;
                }
                func_002791E0(n);
                func_0025C5E8(n);
            } else {
                prev = n;
            }
            n = next;
        } while (next != 0);
    }
    if (p->unk4 == 0) {
        p->unk3 = D_003711D8;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027ADA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AF38);

extern "C" int func_0027B300(S0027B300* a, S0027B300* b) {
    if (b == 0) {
        return a->unk4;
    }
    return b->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B318);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B4D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B678);
