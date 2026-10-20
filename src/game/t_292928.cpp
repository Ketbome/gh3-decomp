// cflags: -funroll-loops
#include "common.h"

asm(".set D_00370E44_lui, D_00370E44");

struct S293_Q {
    u64 a;
    u64 b;
};

struct S293_Out {
    char pad0[0x8];
    S293_Q unk8;
};

struct S293_Buf {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x4];
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
    u64 unk48;
};

struct S002934C8 {
    char pad[0xA8];
    int unkA8;
};

struct S00293518 {
    char pad[0xA8];
    int unkA8;
};

struct S00292928 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    char pad[0x94];
    int unkA8;
};

struct S00293098 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00293340 {
    char pad[0xC];
    volatile int unkC;
};

struct S293EE0 {
    int unk0;
    char pad4[4];
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char pad1C[0x24];
    int unk40;
};

extern "C" {
void func_00300270(void);
void func_00300ED0(int, int, void *, int);
int func_00293998(void);
int func_002939A0(void);
int func_002939D8(void);
int func_00293A08(void);
int func_00293A38(int, S293_Out *);
void func_00293D08(int, int, int, int, int, int);
void func_002934C8(S002934C8 *);
extern int D_003733C4;
extern int D_003733C8;
extern int D_003733BC;
extern int D_003733B8;
extern int D_003733C0;
extern int D_00371718;
void func_002930E8(void);
void func_00293098(int);
int func_00293EE0_1(void*) asm("func_00293EE0");
void func_002EE680_4(int, int, int, int) asm("func_002EE680");
void func_00293FD0(void*, int);
int func_00294818(void*);
int func_002947C0(void*);
int func_00293578(char*);
int func_00305018(void);
extern S00293098 D_00427EB0[];
extern int D_00370E44_lui[] asm("D_00370E44_lui") __attribute__((section(".sdata")));
extern int D_00368A38[] __attribute__((section(".sdata")));
extern int D_003716C0;
int func_002943A0(int);
void func_002944B0(int);
void func_00294028(int);
void func_00274AB8(void);
void func_00300DC8(void *);
int Heap_Alloc(int, int, int, int);
int func_00292D98(int, int, int);
int func_00300EB8(void *);
void func_002EE6A0(int);
void func_002EE680(int);
void func_002EE670(int);
void func_00294AF8(int, S293_Q *);
void func_00293C70(u32);
void func_00293C00(int);
void func_002F3B80(void);
void func_002F3BD0(void);
void *func_00292808(void *, int);
void func_002791E0(void *);
void func_0025C5E8(void *);
void func_0027BF30(void *);
}

struct S292Node {
    char pad0[0xC];
    S292Node *next;
};

struct S292Obj {
    char pad0[4];
    S292Node *head;
};

extern "C" void *func_00292928(S292Obj *obj, int off) {
    S292Node *n = obj->head;
    if (n) {
        n = (S292Node *)((char *)n + off);
        obj->head = n;
    }
    void *r = (char *)obj + 8;
    while (n) {
        r = func_00292808(n, off);
        S292Node *c = n->next;
        if (c && c != r) {
            S292Node *p = c;
            if (p) {
                do {
                    S292Node *nx = p->next;
                    func_002791E0(p);
                    func_0025C5E8(p);
                    p = nx;
                } while (p);
            }
            n->next = 0;
            break;
        }
        n = n->next;
    }
    func_0027BF30(obj);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002929F0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292AF0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292BA8);

GP_DATA(D_003716C0);
extern "C" void func_00292BB0(void) {
    D_003716C0 = func_00292D98(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0), 6, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292BF0);

extern "C" void func_00292D60(S00292928* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S00292928 *func_00292D70(S00292928 *p) {
    func_00292D60(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292D98);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00292F78);

GP_DATA(D_00371718);
extern "C" void func_00292FB0(int a) {
    if (a >= 0) {
        D_003733BC = a;
        D_003733B8 = 0x1F51E0;
        D_00371718 = 1;
        D_003733C8 = 0;
        D_003733C0 = 0;
    }
    func_002930E8();
    for (int i = 0; i < D_003733C8; i++) {
        func_00293098(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293038);

extern "C" void func_00293098(int i) {
    D_00427EB0[i].unk8 = 0;
}

extern "C" void func_002930B8(void) {
    if (D_003733C8 != 0) {
        D_003733C8 = 0;
        D_003733BC = D_00427EB0[0].unk0;
    }
}

extern "C" void func_002930E8(void) {
    D_003733C4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002930F0);

struct S293120_E {
    int unk0;
    char pad[0x4CE3C];
};
struct S293120 {
    int unk0;
    S293120_E *unk4;
    volatile int unk8;
    volatile int unkC;
    int unk10;
};

extern "C" void func_00293120(S293120 *p, int a, S293120_E *b, int n) {
    p->unkC = 0;
    p->unk0 = a;
    p->unk4 = b;
    p->unk10 = n;
    p->unk8 = 0;
    for (int i = 0; i < n; i++) {
        p->unk4[i].unk0 = 0;
    }
}


extern "C" void func_002931E8(void) {
}

extern "C" void func_002931F0(S293120 *p) {
    p->unkC = 0;
    p->unk8 = 0;
}

extern "C" int func_00293200(S00292928* p) {
    return p->unkC == p->unk10;
}

struct S293_VQ {
    int unk0;
    int unk4;
    volatile int unk8;
    volatile int unkC;
    int unk10;
};

struct S293218 { char pad0[4]; int base; volatile int idx; volatile int cnt; int size; };
extern "C" void func_00293218(S293218* s) {
    func_002F3B80();
    *(int*)(s->idx * 0x4CE40 + s->base) = 2;
    s->cnt = s->cnt + 1;
    s->idx = (s->idx + 1) % s->size;
    func_002F3BD0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293288);

extern "C" int func_002932D0(S00292928* p) {
    return p->unkC == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002932E0);

extern "C" void func_00293340(S00293340* p) {
    if (p->unkC > 0) {
        p->unkC--;
    }
}

extern "C" int func_00293360(int a, int, int, int b, int c, int d, int e, int f) {
    func_00300270();
    func_00300ED0(a, 0, (void *)func_00293998, 0);
    func_00300ED0(a, 1, (void *)func_002939A0, 0);
    func_00300ED0(a, 2, (void *)func_002939D8, 0);
    func_00300ED0(a, 3, (void *)func_00293A08, 0);
    func_00300ED0(a, 5, (void *)func_00293A38, 0);
    func_002934C8((S002934C8 *)a);
    func_00293D08(a + 0x48, b, c, d, e, f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293460);

extern "C" int func_00293468(void) {
    func_00305018();
    return 1;
}

extern "C" void func_00293488(char* a) {
    func_00293EE0_1(a + 0x48);
}

extern "C" void func_002934A8(char* a, int n) {
    func_00293FD0(a + 0x48, n);
}

extern "C" void func_002934C8(S002934C8* p) {
    p->unkA8 = 0;
}

extern "C" int func_002934D0(char *p) {
    func_002947C0(p + 0x48);
    func_00300DC8(p);
    return 1;
}

extern "C" void func_00293508(S00292928* p) {
    p->unkA8 = 1;
}

extern "C" int func_00293518(S00293518* p) {
    return p->unkA8;
}

extern "C" int func_00293520(S00292928* p, int v) {
    int old = p->unkA8;
    p->unkA8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293530);

extern "C" int func_00293578(char* a) {
    return func_00294818(a + 0x48);
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293598);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002935A0);

extern "C" int func_00293678(char *p) {
    int r = 0;
    if (!func_00293578(p)) {
        r = func_00300EB8(p) != 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002936C0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293768);

extern "C" int func_00293998(void) {
    return 1;
}

extern "C" int func_002939A0(void) {
    func_00274AB8();
    func_00294028(D_00370E44_lui[0] + 0x6F1648);
    return 1;
}

extern "C" int func_002939D8(void) {
    func_002943A0(D_00370E44_lui[0] + 0x6F1648);
    return 1;
}

extern "C" int func_00293A08(void) {
    func_002944B0(D_00370E44_lui[0] + 0x6F1648);
    return 1;
}

struct S293_Q2 {
    S293_Q q;
    u64 c;
    u64 d;
};

extern "C" int func_00293A38(int a, S293_Out *out) {
    S293_Q2 q;
    func_00294AF8(D_00370E44_lui[0] + 0x6F1648, &q.q);
    out->unk8 = q.q;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293A88);

extern "C" u32 func_00293BB8(S00292928 *p, u32 x) {
    if (x == ((p->unk8 * 16 + p->unk4 + 0x10) & 0x0FFFFFFF)) {
        return 0;
    }
    return (x - p->unk0) >> 11;
}

extern "C" void func_00293C00(int x) {
    func_002F3B80();
    *(volatile u32*)0x1000F590 = *(volatile u32*)0x1000F520 | 0x10000;
    *(volatile u32*)0x1000B000 = x;
    *(volatile u32*)0x1000F590 = *(volatile u32*)0x1000F520 & ~0x10000;
    func_002F3BD0();
}

extern "C" void func_00293C70(u32 x) {
    func_002F3B80();
    *(volatile u32*)0x1000F590 = *(volatile u32*)0x1000F520 | 0x10000;
    *(volatile u32*)0x1000B400 = x;
    *(volatile u32*)0x1000F590 = *(volatile u32*)0x1000F520 & ~0x10000;
    func_002F3BD0();
}

extern "C" void func_00293CE0(u64* p, u32 b, u32 c, u32 d) {
    *p = ((u64)b << 32) | ((u64)c << 28) | (u64)d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293D08);

struct S293_E {
    long unk0;
    long unk8;
    int unk10;
    int unk14;
};

struct S293_D {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x2C];
    int unk44;
    char pad48[8];
    S293_E *unk50;
    int unk54;
    int unk58;
    int unk5C;
};

extern "C" void func_00293C70_3(int, int, int) asm("func_00293C70");

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293D80);

extern "C" void func_00293EE0(S293EE0 *p, int *o1, int *o2, int *o3, int *o4) {
    func_002EE6A0(p->unk40);
    int a = p->unk10;
    int b = p->unk14;
    int c = a + 2;
    int cap = p->unk18;
    int hi = (((p->unkC + a) << 11) + b) % cap;
    int len = ((p->unk8 - c) << 11) - b;
    if (cap - hi >= len) {
        *o1 = p->unk0 + hi;
        *o2 = len;
        *o3 = 0;
        *o4 = 0;
    } else {
        *o1 = p->unk0 + hi;
        *o2 = p->unk18 - hi;
        *o3 = p->unk0;
        *o4 = len - (p->unk18 - hi);
    }
    func_002EE680_4(p->unk40, len, c, hi);
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00293FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00294028);

extern "C" int func_002943A0(int v) {
    S293_Buf *p = (S293_Buf *)v;
    func_002EE6A0(p->unk40);
    p->unk44 = 0;
    func_00293C70(5);
    p->unk1C = *(volatile int *)0x1000B410;
    p->unk20 = *(volatile int *)0x1000B430;
    p->unk24 = *(volatile int *)0x1000B420;
    p->unk28 = *(volatile int *)0x1000B400;
    while (*(volatile int *)0x10002010 & 0xF0) {
    }
    func_00293C00(0);
    p->unk2C = *(volatile int *)0x1000B010;
    p->unk30 = *(volatile int *)0x1000B020;
    p->unk34 = *(volatile int *)0x1000B000;
    p->unk38 = *(volatile int *)0x10002020;
    p->unk3C = *(volatile int *)0x10002010;
    func_002EE680(p->unk40);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002944B0);

extern "C" int func_002947C0(void *v) {
    S293_Buf *p = (S293_Buf *)v;
    func_00293C70(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_002EE670(p->unk40);
    return 1;
}

extern "C" int func_00294818(void *v) {
    S293_Buf *p = (S293_Buf *)v;
    func_002EE6A0(p->unk40);
    int r = p->unk10 * 2048 + p->unk14;
    func_002EE680(p->unk40);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_00294868);

INCLUDE_ASM("asm/nonmatchings/game/t_292928", func_002948C0);
