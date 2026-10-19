// cflags: -funroll-loops
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
void func_001A0D98(void*, void*, int);
void func_002F3B80(void);
void func_002F3BD0(void);
void func_0019F7E0(N_19F*);
void Heap_Free(int, void*);
extern int D_00373310[];
extern int D_00373318[];
extern struct H_001A0380* D_0037331C;
void* Heap_Alloc(int, int, int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern S0019FA18* D_0036C42C;
void func_0019FA18_v(S0019FA18*) __asm__("func_0019FA18");
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

struct M19F { M19F* next; float unk4; char pad8[4]; int unkC; char pad10[0x3C]; M19F* prev; };
extern "C" int D_0036C420;
extern "C" {
void func_0019F6F8(N_19F*, N_19F*);
void func_0019F750(N_19F*, N_19F*, N_19F*);
void func_0019F790(N_19F*, int*, N_19F**);
}

GP_DATA(D_0036C420);
extern "C" void func_0019F5A0(void) {
    if (D_0036C420 != 0) {
        M19F* n = (M19F*)D_00373300;
        if (n) {
            M19F* cur = n->next;
        top:
            {
                M19F* last = 0;
                float f20 = n->unk4;
                M19F* a = 0;
                N_19F* head = 0;
                M19F* b = 0;
                while (cur && cur->unk4 == f20) {
                    M19F* nx = cur->next;
                    if (b == 0) {
                        b = ((cur->unkC & 8) == 0) ? 0 : cur;
                    } else {
                        int fl = cur->unkC;
                        if (a == 0) {
                            a = ((fl & 8) != 0) ? 0 : cur;
                        } else if (fl & 8) {
                            M19F* t = cur->prev;
                            func_0019F6F8((N_19F*)a, (N_19F*)t);
                            M19F* tmp = a;
                            a = 0;
                            func_0019F790((N_19F*)tmp, (int*)t, &head);
                            last = t;
                        }
                    }
                    cur = nx;
                }
                n = cur;
                if (b) {
                    if (a) {
                        M19F* t = cur->prev;
                        func_0019F6F8((N_19F*)a, (N_19F*)t);
                        func_0019F790((N_19F*)a, (int*)t, &head);
                        last = t;
                    }
                    n = cur;
                    if (head) {
                        func_0019F750(head, (N_19F*)last, (N_19F*)b);
                        n = cur;
                    }
                }
            }
            if (n) {
                cur = n->next;
                goto top;
            }
        }
        D_0036C420 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F838);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_0019F848);

GP_DATA(D_0036C42C);
extern "C" void func_0019F928(void) {
    if (D_0036C42C == 0) {
        int i;
        D_0036C42C = (S0019FA18*)Heap_Alloc(D_00368A38[0], 0x2BC, 1, 0);
        for (i = 0; i < 35; i++) {
            func_0019FA18_v(&D_0036C42C[i]);
        }
    }
}

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

struct H_001A0380 { H_001A0380* unk0; H_001A0380** unk4; char pad8[8]; B10_19F unk10; };

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0380);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0468);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A04A0);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0710);

INCLUDE_ASM("asm/nonmatchings/game/t_19F538", func_001A0A40);

extern "C" void* func_001A0D38(char* self) {
    int i;
    for (i = 0; i < 4; i++) {
        func_001A0D98(self, self + i * 0x3C8, i);
    }
    return self;
}

struct E19F { int unk0; int unk4; };
extern "C" void func_001A0F60_e(void*, E19F*, int*, int) __asm__("func_001A0F60");

extern "C" void func_001A0D98(void* a, void* base, int c) {
    E19F (*arr)[11] = (E19F (*)[11])base;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            E19F* e = &arr[j][i];
            e->unk0 = 1 << j;
            e->unk4 = 1 << i;
            func_001A0F60_e(a, e, &e->unk4, c);
        }
    }
}

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
