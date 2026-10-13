#include "common.h"

struct S00291CF0 {
    int unk0;
    int unk4;
    int unk8;
};

struct S00290CF8 {
    char pad[0x4];
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

struct S002920F0 {
    char pad[0x8];
    int unk8;
    char pad1[0x4];
    int unk10;
};

struct S00290A20_2 {
    int unk0;
    int unk4;
};

struct S00290A20 {
    char pad[0x14C];
    S00290A20_2 unk14C[19];
    int unk1E4;
    int unk1E8;
};

struct S2908_Loop {
    int ptr;
    int count;
};

struct S2908_Script {
    char pad0[0x4];
    int unk4;
    char pad8[0x13C];
    int unk144;
    S2908_Loop loops[20];
    int unk1E8;
    int unk1EC;
    char pad1F0[0x4];
    int unk1F4;
};

struct S2908_Node {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x4];
    S2908_Node *next;
    S2908_Node *prev;
};

struct S2908_List {
    char pad0[0x14];
    void *vptr;
    int unk18;
    S2908_Node *head;
    S2908_Node *tail;
    int unk24;
};

struct S2908_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    int unk4;
    int unk8;
    int unkC;
};

struct S2908_V {
    char pad0[0x14];
    virtual ~S2908_V();
};

struct S2908_Buf {
    char pad0[0x4];
    void *unk4;
    char pad8[0xE];
    u8 unk16;
};

struct S2908_Pool {
    char *start;
    char *end;
    bool Has(void *p) { return (char *)p >= start && (char *)p < end; }
};

extern "C" {
void func_0011C2E8(S2908_Pool *, void *);
void func_0028EB18(void *, char *);
void func_0028EBA0(void *);
int func_0028E868(int, int);
void func_00279358(void *, int, int, int);
int Heap_Alloc(int, int, int, int);
void func_001C55A8(void *);
int func_00291D28(int, int, int);

void func_00291C40(void *);
void func_00291F08(int, int *);
void func_00291FC0(void *);
void func_00291020(S2908_List *, S2908_Node *);
void func_00290D18(S2908_Node *, int);
void func_002908A0(S2908_Script *, int);
void func_0011A470(int);
void Heap_Free(int, void *);
extern char D_0035BBB0[];
extern char D_0035BBC8[];
extern char D_0035BF60[];
extern int D_00368A38;
extern S2908_V *D_003715D4;
extern u32 D_003715D8;
extern S2908_Comp D_003AAC88;
void func_00290BD0(int, int);
extern S002920F0* D_003715C0[2];
extern int D_003715D0;
}

extern "C" void func_002908A0(S2908_Script *s, int v) {
    int n = ++s->unk1E8;
    if (n >= 20) {
        func_0028EB18(s, D_0035BBB0);
        return;
    }
    s->loops[n].ptr = v;
    s->loops[s->unk1E8].count = 0;
    s->unk1EC = 1;
}

extern "C" void func_00290908(S2908_Script *s, int v) {
    while (s->unk1EC) {
        if (s->loops[s->unk1E8].count != 0) {
            break;
        }
        if (func_0028E868(v, s->loops[s->unk1E8].ptr)) {
            func_0028EBA0(s);
            continue;
        }
        break;
    }
    func_002908A0(s, v);
}

extern "C" void func_002909A8(S2908_Script *s, int a) {
    if (s->unk144 != 0 || (s->unk4 & 0xFE00)) {
        if (++s->unk144 >= 20) {
            func_0028EB18(s, D_0035BBC8);
            return;
        }
    }
    func_00279358((char *)s + 4 + s->unk144 * 16, a, 0, 0);
}

extern "C" void func_00290A20(S00290A20* p) {
    p->unk14C[p->unk1E8].unk0++;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290A40);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290AA8);

extern "C" void func_00290BD0(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_003AAC88.b8 = 0;
        D_003AAC88.type = 0;
        D_003AAC88.unk2 = 0;
        D_003AAC88.unk4 = 0;
        D_003AAC88.unkC = 0;
        D_003AAC88.unk8 = 0;
    }
}

extern "C" void func_00290C20(void) {
    func_00290BD0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290C40);

GP_DATA(D_003715D8);
GP_DATA(D_003715D4);
extern "C" void func_00290CA0(void) {
    if (D_003715D8 >= 2) {
        D_003715D8--;
    } else {
        delete D_003715D4;
        D_003715D4 = 0;
        D_003715D8 = 0;
    }
}

extern "C" S00290CF8* func_00290CF8(S00290CF8* p) {
    p->unk8 = 0;
    p->unkC = 0;
    p->unk4 = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

extern "C" void func_00290D18(S2908_Node *p, int flags) {
    if (p->unk8) {
        func_0011A470(p->unk8);
    }
    if (flags & 1) {
        func_00291C40(p);
    }
}

extern "C" S2908_List *func_00290D68(S2908_List *p) {
    func_001C55A8(p);
    p->vptr = D_0035BF60;
    p->unk18 = func_00291D28(Heap_Alloc(D_00368A38, 0x1C, 1, 0), 8, 0);
    p->head = 0;
    p->tail = 0;
    p->unk24 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00290DD8);

extern "C" void func_00290FD8(void) {
}

extern "C" void func_00290FE0(void) {
}

extern "C" void func_00290FE8(S2908_List *l, S2908_Node *n) {
    n->prev = 0;
    n->next = l->head;
    l->head = n;
    if (n->next) {
        n->next->prev = n;
    }
    if (l->tail == 0) {
        l->tail = l->head;
    }
}

extern "C" void func_00291020(S2908_List *l, S2908_Node *n) {
    if (n->prev) {
        n->prev->next = n->next;
    }
    if (n->next) {
        n->next->prev = n->prev;
    }
    if (n == l->head) {
        l->head = n->next;
    }
    if (n == l->tail) {
        l->tail = n->prev;
    }
    n->next = 0;
    n->prev = 0;
}

extern "C" void func_00291080(S2908_List *l, S2908_Node *n) {
    int k = n->unk4;
    func_00291F08(l->unk18, &k);
    func_00291020(l, n);
    if (n) {
        func_00290D18(n, 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002910E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291230);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291608);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002917B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002918F8);

extern "C" void func_00291900(S2908_List *l) {
    S2908_Node *n = l->head;
    while (n) {
        S2908_Node *next = n->next;
        int k = n->unk4;
        func_00291F08(l->unk18, &k);
        n->next = 0;
        n->prev = 0;
        if (n) {
            func_00290D18(n, 3);
        }
        n = next;
    }
    l->head = 0;
    l->tail = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291980);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291988);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291C38);

GP_DATA(D_003715D0);
GP_DATA(D_003715C0);
extern "C" void func_00291C40(void *p) {
    S2908_Pool *pl = (S2908_Pool *)D_003715C0[D_003715D0];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    pl = (S2908_Pool *)D_003715C0[D_003715D0 ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p);
        return;
    }
    if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_00291CF0(S00291CF0* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S00291CF0 *func_00291D00(S00291CF0 *p) {
    func_00291CF0(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291D28);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00291FC0);

extern "C" void func_00292078(S2908_Buf *p, int flags) {
    if (!p->unk16 && p->unk4) {
        func_00291FC0(p);
        if (p->unk4) {
            Heap_Free(D_00368A38, p->unk4);
        }
        p->unk4 = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

GP_DATA(D_003715D0);
GP_DATA(D_003715C0);
extern "C" int func_002920F0(void) {
    return D_003715C0[D_003715D0]->unk10;
}

extern "C" int func_00292110(void) {
    return D_003715C0[D_003715D0]->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_00292130);

INCLUDE_ASM("asm/nonmatchings/game/t_2908A0", func_002921E8);

struct S292808 {
    u32 unk0;
    char pad4[4];
    int unk8;
    int unkC;
};
extern "C" {
unsigned int strlen(const char *);
int func_00286160(int);
char *func_00292928(int, int);
char *func_002921E8(int, int);
}
extern "C" char *func_00292808(S292808 *p, int n) {
    if (p->unkC != 0) {
        p->unkC += n;
    }
    char *r = (char *)p + 0x10;
    switch ((p->unk0 >> 9) & 0x7F) {
    case 3:
        p->unk8 += n;
        r += ((int)strlen((char *)p->unk8) + 4) & -4;
        break;
    case 7:
        p->unk8 += n;
        r += (func_00286160(p->unk8) - p->unk8 + 3) & ~3u;
        break;
    case 6:
        r += 0x10;
        p->unk8 += n;
        break;
    case 5:
        r += 0xC;
        p->unk8 += n;
        break;
    case 10:
        p->unk8 += n;
        r = func_00292928(p->unk8, n);
        break;
    case 12:
        p->unk8 += n;
        r = func_002921E8(p->unk8, n);
        break;
    case 1:
    case 26:
        break;
    }
    return r;
}
