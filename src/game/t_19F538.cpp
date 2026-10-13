#include "common.h"

struct S0019FA18 {
    char pad[0x10];
    void* unk10;
};

struct B10_19F {
    u64 f0 : 16;
    u64 f16 : 1;
    u64 f17 : 3;
    u64 f20 : 3;
    u64 f23 : 41;
};
struct S1A0_19F { int unk0; int unk4; char pad8[8]; B10_19F unk10; };
struct N_19F { N_19F* next; char pad4[0x48]; N_19F* prev; };

struct S1A1118 { int unk0; int unk4; int unk8; int unkC; int unk10; };

extern "C" {
void func_002F3B80(void);
void func_002F3BD0(void);
void func_0019F7E0(N_19F*);
extern int D_00372D24;
extern char* D_00373308;
extern int* D_00373320;
extern N_19F* D_00373300;
extern N_19F* D_00373304;
extern void* D_0036C430;
int func_001A1028(int);
int func_001A1330(u32);
extern struct S1A1118 D_00348740[];
extern int D_00348790[];
}

struct N19F538 { N19F538* unk0; char pad4[0x34]; int unk38; };

extern "C" void func_0019F538(int a) {
    N19F538* p = (N19F538*)D_00373300;
    if (p) {
        do {
            if (p->unk38 == a) {
                N19F538* n = p->unk0;
                func_002F3B80();
                func_0019F7E0((N_19F*)p);
                p = n;
                func_002F3BD0();
            } else {
                p = p->unk0;
            }
        } while (p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F5A0);

static inline void N_19F_Unlink(N_19F* first, N_19F* last) {
    if (first == D_00373300) {
        last->next->prev = 0;
        D_00373300 = last->next;
    } else if (last == D_00373304) {
        first->prev->next = 0;
        D_00373304 = first->prev;
    } else {
        last->next->prev = first->prev;
        first->prev->next = last->next;
    }
}

extern "C" void func_0019F6F8(N_19F* first, N_19F* last) {
    N_19F_Unlink(first, last);
}

extern "C" void func_0019F750(N_19F* first, N_19F* last, N_19F* before) {
    last->next = before;
    if (D_00373300 == before) {
        first->prev = 0;
        D_00373300 = first;
        last->next->prev = last;
    } else {
        first->prev = before->prev;
        before->prev->next = first;
        before->prev = last;
    }
}

extern "C" void func_0019F790(N_19F* n, int* b, N_19F** head) {
    if (!*head) {
        *head = n;
        n->prev = 0;
    } else {
        N_19F* p = *head;
        while (p->next) {
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
    *b = 0;
}

extern "C" void func_0019F7E0(N_19F* n) {
    N_19F_Unlink(n, n);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F838);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F848);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F928);

GP_DATA(D_0036C430);
extern "C" void* func_0019F9F8(void) {
    S0019FA18* p = (S0019FA18*)D_0036C430;
    if (p) {
        D_0036C430 = p->unk10;
    }
    return p;
}

GP_DATA(D_0036C430);
extern "C" void* func_0019FA18(S0019FA18* self) {
    void* t1 = D_0036C430;
    self->unk10 = t1;
    D_0036C430 = self;
    return t1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019FA28);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019FE18);

extern "C" void func_0019FEB0(void) {
    char* p = D_00373308;
    if (p) {
        int off = D_00372D24 ? 0 : 4;
        do {
            *(int*)(p + off) = 0;
            p = *(char**)(p + 0x280);
        } while (p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019FEF0);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A01F0);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0220);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0380);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0468);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A04A0);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0710);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0A40);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0D38);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0D98);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0F60);

extern "C" int func_001A1028(int x) {
    switch (x) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 1;
    case 19:
        return 2;
    case 20:
        return 3;
    }
    return -1;
}

struct S_001A1078 { int unk0; int unk4; };

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A1078);

extern "C" int func_001A1118(int a0, int a, int b, int c) {
    S1A1118* e = &D_00348740[func_001A1028(c)];
    return (a / e->unk8) * (b / e->unkC);
}

extern "C" int func_001A1180(int a0, int a, int b, int c) {
    switch (c) {
    case 0:
    case 1:
    case 19:
        return *(int*)((char*)D_00348790 + a * 4 + b * 32);
    case 2:
    case 20:
        return *(int*)((char*)D_00348790 + b * 4 + a * 32);
    }
    return -1;
}

extern "C" void func_001A11D8(int a0, int* pa, int* pb, int v, int sel) {
    int yi = -1;
    int yj = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (*(int*)((char*)D_00348790 + (i * 32 + j * 4)) == v) {
                yi = i;
                yj = j;
                break;
            }
        }
    }
    S1A1118* e = &D_00348740[func_001A1028(sel)];
    switch (sel) {
    case 0:
    case 1:
    case 19:
        *pa = yj * e->unk8;
        *pb = yi * e->unkC;
        break;
    case 2:
    case 20:
        *pa = yi * e->unk8;
        *pb = yj * e->unkC;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A1318);

extern "C" int func_001A1330(u32 x) {
    int n = 0;
    while (x) {
        x >>= 1;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A1358);
