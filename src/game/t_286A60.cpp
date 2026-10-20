#include "common.h"

struct S2867_N {
    char pad0[0x8];
    int unk8;
};

struct S2867_V {
    virtual ~S2867_V();
};

struct S2867_Flags {
    char pad0[0x8];
    int unk8;
};

struct S2867_Val {
    S2867_V *obj;
    int value;
    u32 type : 4;
    u32 b4 : 2;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
};

struct S2867_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    int unk4;
    int unk8;
    int unkC;
};

struct S2867_Ent {
    int a;
    int b;
};

struct S2867_Key {
    char pad0[0x2];
    u8 type;
    char pad3;
    int unk4;
};

struct S2867_Pool {
    char *start;
    char *end;
    bool Has(void *p) { return (char *)p >= start && (char *)p < end; }
};

extern "C" {
extern S2867_Pool *D_00371330[2];
extern int D_00371340;
extern S2867_Pool *D_00371088[] __attribute__((section(".sdata")));
extern int D_00371098;
void func_0011C2E8(S2867_Pool *, void *);
void *func_0011C2A8(S2867_Pool *);
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
void *Heap_Alloc(int, int, int, int);
void Heap_Free(int, void *);
extern int D_00368A38;
u32 func_001150B8(char *);
void func_00287EF0(u32, int *, int);
void func_00292AF0(void *, void *, void *, u32, int);
void func_00275A90(void);
extern void *D_003715D4;
void func_002917B0(void *, int);
extern int D_0037136C;
extern S2867_Ent D_003A9CE8[];
void func_002881F8(S2867_Key *);
extern int D_00372EE8;
extern char D_003A9AD8[];
extern S2867_Comp D_003A9CD8;
void func_0028E8A0(void *);
int CrcFromPathLowercase(void);
void func_002774B8(int, int);
int func_002875F0(int, int, int, int, int);
int func_00287578(char *, int, int, int);
void func_00287EB0(char *, int *, int);
int strlen(char *);
int strcmp(char *, char *);
extern char D_003713C0[];
void func_00288B10(S2867_Val *);
void func_00288888(S2867_Val *);
void func_00288A20(S2867_Val *, int);
int func_0028C658(void *);
void func_0028A300(void *);
void func_0028A558(void *);
void *func_002899B0(void *);
S2867_N *func_00275CE8(S2867_N *);
char *func_0011A380(int);
void func_0011D220(int);
void func_00288678(void);
void func_00288238(int, int);
void func_00288170(int, int);
void func_0027C7D0(int, u32, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00286A60);

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00286A68);

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002870C0);

struct S2873A0 {
    u32 unk0;
    char pad4[4];
    int unk8;
    int unkC;
    bool B10() { return (unk0 >> 10) & 1; }
};
extern "C" {
void func_00275988(void *);
void func_00275730(int);
void func_0025C478(int);
void func_0025C530(int);
void func_0011A470(int);
void func_0027AC90(int);
void func_00113250(int);
void func_002798B8(int);
void func_0027E6B0(int, int);
void func_002880B8(void *);
}
extern "C" void func_002873A0(S2873A0 *p) {
    func_00275988(p);
    if (!p->B10()) {
        switch (((u8 *)p)[2]) {
        case 1:
            break;
        case 3:
            func_00275730(p->unkC);
            break;
        case 5:
            func_0025C478(p->unkC);
            break;
        case 6:
            func_0025C530(p->unkC);
            break;
        case 7:
            func_0011A470(p->unkC);
            break;
        case 10: {
            int o = p->unkC;
            if (o) {
                func_0027AC90(o);
                func_00113250(o);
            }
            break;
        }
        case 12:
            func_002798B8(p->unkC);
            if (p->unkC) {
                func_0027E6B0(p->unkC, 3);
            }
            break;
        case 26:
            break;
        }
        p->unkC = 0;
        func_002880B8(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00287498);

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002874A8);

extern "C" int func_00287578(char *name, int a, int b, int c) {
    int t = CrcFromPathLowercase();
    func_002774B8(t, (int)name);
    return func_002875F0(t, a, b, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002875F0);

extern "C" void func_00287EB0(char *name, int *p, int flag) {
    func_00287EF0(func_001150B8(name), p, flag);
}

extern "C" void func_00287EF0(u32 key, int *p, int flag) {
    func_00292AF0(p, p, (void *)func_00275A90, key, flag != 0);
    *p = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00287F30);

GP_DATA(D_00371340);
GP_DATA(D_00371330);
extern "C" void func_00287F50(void *p) {
    S2867_Pool *pl = D_00371330[D_00371340];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    pl = D_00371330[D_00371340 ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void *func_00288000(int size) {
    S2867_Pool *pl = D_00371330[D_00371340];
    if (pl) {
        void *r = func_0011C2A8(pl);
        if (!r) {
            int h = D_00368A38;
            func_00119490(h, func_00119610(h, 1));
            r = Heap_Alloc(D_00368A38, size, 1, 0);
            func_001194B8(D_00368A38);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38, size, 1, 0);
}

extern "C" void func_002880B8(void *p) {
    S2867_Pool *pl = D_00371088[D_00371098];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    pl = D_00371088[D_00371098 ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    if (p) {
        Heap_Free(D_00368A38, p);
    }
}

GP_DATA(D_00372EE8);
extern "C" void func_00288170(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_00372EE8 = 0;
        func_0028E8A0(D_003A9AD8);
        D_003A9CD8.b8 = 0;
        D_003A9CD8.type = 0;
        D_003A9CD8.unk2 = 0;
        D_003A9CD8.unk4 = 0;
        D_003A9CD8.unkC = 0;
        D_003A9CD8.unk8 = 0;
    }
}

extern "C" void func_002881D8(void) {
    func_00288170(1, 0xFFFF);
}

extern "C" void func_002881F8(S2867_Key *k) {
    if (k->type == 7 && D_003715D4) {
        func_002917B0(D_003715D4, k->unk4);
    }
}

GP_DATA(D_0037136C);
extern "C" void func_00288238(int a, int b) {
    int n = D_0037136C;
    D_003A9CE8[n].a = a;
    D_003A9CE8[n].b = b != 0;
    D_0037136C = n + 1;
    func_002881F8((S2867_Key *)a);
}

extern "C" void func_00288280(int a) {
    func_00288238(a, 1);
}

extern "C" void func_002882A0(int a) {
    func_00288238(a, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002882C0);

extern "C" void func_002882D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002882D8);

extern "C" void func_002882E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002882E8);

extern "C" int func_00288410(char *name, int a, int b, int c) {
    if (strcmp(name + strlen(name) - 3, D_003713C0)) {
        func_00287EB0(name, (int *)a, b);
    } else {
        func_00287578(name, a, b, c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002884A0);

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_002884A8);

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00288678);

extern "C" void func_002886F8(int *p) {
    if (*p) {
        func_00292AF0(p, 0, (char *)func_00288678 + 8, 0, 0);
        for (void *o = func_002899B0(0); o; o = func_002899B0(o)) {
            if (!func_0028C658(o)) {
                func_0028A300(o);
                func_0028A558(o);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00288778);

extern "C" void func_002887B0(int a, int b) {
    if (b != 0) {
        func_0027C7D0(a, 0x4DC74037, b);
    }
}

extern "C" void func_002887D8(void *p, int flags) {
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_00288808(S2867_Val *d, S2867_Val *s) {
    d->obj = s->obj;
    d->value = s->value;
    d->type = s->type;
    d->b6 = s->b6;
    d->b7 = s->b7;
    s->obj = 0;
    s->value = 0;
    s->type = 0;
    s->b6 = 0;
    s->b7 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00288888);

extern "C" void func_00288910(S2867_Val *v, int type, S2867_Flags *a, int b) {
    func_00288888(v);
    v->type = type;
    v->value = b;
    v->obj = (S2867_V *)a;
    v->b6 = 0;
    a->unk8 |= 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_286A60", func_00288990);

extern "C" void func_00288998(S2867_Val *v, int type, S2867_V *obj, int d) {
    func_00288888(v);
    v->obj = obj;
    v->type = type;
    if (d) func_00288A20(v, d);
    v->b6 = 0;
}

struct S2867_R {
    int unk0;
    int unk4;
    int unk8;
    virtual ~S2867_R();
};

extern "C" {
int func_00288E30(S2867_Val *, int);
int func_002892B0(S2867_Val *, int, S2867_R *);
void func_002891A8(S2867_Val *);
extern char D_0035AF80[];
}

extern "C" void func_00288A20(S2867_Val *v, int arg) {
    if (func_00288E30(v, arg)) {
        S2867_R *r = (S2867_R *)Heap_Alloc(D_00368A38, 0x10, 1, 0);
        r->unk0 = 0;
        r->unk4 = 0;
        *(char **)((char *)r + 0xC) = D_0035AF80;
        r->unk8 = 0;
        v->value = (int)r;
        v->b4 = func_002892B0(v, arg, r);
        S2867_R *p = (S2867_R *)v->value;
        if (p->unk4 == 0) {
            delete p;
            v->value = 0;
        }
        if (v->type == 4) {
            func_002891A8(v);
        }
        v->b7 = 1;
    }
}

