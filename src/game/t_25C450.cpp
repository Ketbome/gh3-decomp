#include "common.h"

struct S0025D4E0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct S25C450_S {
    char pad0[0x20];
    int unk20;
};

struct S25C450_H {
    char pad0[0x34];
    int unk34;
};

struct S25C_Pool {
    char *start;
    char *end;
    bool Has(void *p) { return (char *)p >= start && (char *)p < end; }
};

struct S25C_Node {
    char pad0[0x34];
    int unk34;
    char pad38[0xC];
    char unk44[1];
};

extern "C" {
extern char D_003568C0[];
extern char D_003568B0[];
void func_0025CAE8(char *, int, int, int);
int func_0025F960(void);
int func_0025F938(void);
int func_0025F910(void);
int func_0011A8D0(int);
int func_0011A8A8(int);
S25C_Node *func_00119A60(int, S25C_Node *);
S25C_Node *func_00119A40(int);
extern int D_00371038P asm("D_00371038");
extern S25C_Pool *D_00371028P[2] asm("D_00371028");
extern int D_00370FB8P asm("D_00370FB8");
extern S25C_Pool *D_00370FA8P[2] asm("D_00370FA8");
void func_00119400(int, void *);
void func_0011C2E8(S25C_Pool *, void *, int, S25C_Pool **);
extern int D_00370FD0P asm("D_00370FD0");
extern S25C_Pool *D_00370FC0P[2] asm("D_00370FC0");
S25C450_H *func_00119730(int, int, int);
int func_0011A8D8(int);
void func_0027C160(int, int, int);
int func_0025F9D8(void);
int func_0025F9B0(void);
int func_0025F988(void);
int func_0027D1F8(int, int, int *, int);
void func_0011A230(int, int, int, int, int);
void func_0011A300(int, int, int);
int CrcFromPathLowercase(int);
int func_0027D870(int, int, int *, int);
int func_00119710(int, int, int);
void func_001C4388(int);
extern char D_00356E88[];
extern char D_003705F0[];
void func_0011A550(int);
int func_0027D188(int, int, int *, int);
void func_0011A560(int, int, int);
int func_0027DF00(int, int);
extern int D_00368744[] __attribute__((section(".sdata")));
int func_00277208(void);
int func_0025C6A0(int, int);
int func_0011A568(void);
int func_0011E9C8(void);
extern int D_003705D8;
int func_00264B70(void);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_001194B8(int);
void func_00119CC0(int);
void func_00264F60(void);
}

extern "C" int CFunc_PrintChecksumTableUsage(void) {
    func_00277208();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C470);

extern "C" void func_0025C478(void *p) {
    S25C_Pool *pl = D_00370FC0P[D_00370FD0P];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00370FD0P, D_00370FC0P);
        return;
    }
    pl = D_00370FC0P[D_00370FD0P ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00370FD0P, D_00370FC0P);
        return;
    }
    if (p) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_0025C530(void *p) {
    S25C_Pool *pl = D_00370FA8P[D_00370FB8P];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00370FB8P, D_00370FA8P);
        return;
    }
    pl = D_00370FA8P[D_00370FB8P ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00370FB8P, D_00370FA8P);
        return;
    }
    if (p) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_0025C5E8(void *p) {
    S25C_Pool *pl = D_00371028P[D_00371038P];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00371038P, D_00371028P);
        return;
    }
    pl = D_00371028P[D_00371038P ^ 1];
    if (pl && pl->Has(p)) {
        func_0011C2E8(pl, p, D_00371038P, D_00371028P);
        return;
    }
    if (p) {
        func_00119400(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025C6F8);

extern "C" void func_0025C790(void) {
    func_0025C6A0(1, 0xFFFF);
}

extern "C" int CFunc_PushMemProfile(int arg0) {
    int out;
    func_0027D188(arg0, 0, &out, 1);
    func_0011A560(out, 0, 0);
    return 1;
}

extern "C" int CFunc_PopMemProfile(void) {
    func_0011A568();
    return 1;
}

extern "C" int CFunc_GotExtraMemory(void) {
    return D_00368744[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", CFunc_MemPushContext);

extern "C" int CFunc_MemPopContext(void) {
    func_001194B8(D_00368A38[0]);
    return 1;
}

extern "C" int CFunc_MemInitHeap(int arg0) {
    int out = 0;
    int v;
    func_0027D188(arg0, 0xA1DC81F9, &out, 1);
    v = 0;
    func_0027D1F8(arg0, 0x083FDB95, &v, 1);
    func_0011A230(D_00368A38[0], CrcFromPathLowercase(out), v, out, 0);
    return 1;
}

extern "C" void CFunc_MemDeleteHeap(int arg0) {
    int out[2];
    out[0] = 0;
    if (func_0027D188(arg0, 0xA1DC81F9, &out[1], 0)) {
        out[0] = CrcFromPathLowercase(out[1]);
    } else {
        func_0027D870(arg0, 0xA1DC81F9, out, 1);
    }
    func_0011A300(D_00368A38[0], out[0], 0);
}

extern "C" int CFunc_SetMemThreadSafe(int arg0) {
    if (func_0027DF00(arg0, 0xD443A2BC) != 0) {
        func_0011A550(0);
    } else {
        func_0011A550(1);
    }
    return 1;
}

extern "C" s32 CFunc_AnalyzeHeap(int arg0) {
    int out;
    int h = D_00368A38[0];
    out = 0x0C7800B0;
    if (arg0 != 0) {
        func_0027D870(arg0, 0, &out, 0);
    }
    int t = func_00119710(h, out, 1);
    if (t != 0) {
        func_001C4388(t);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", CFunc_PrintMemInfo);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CAE8);

extern "C" int CFunc_DisplayFreeMem(void) {
    int h = D_00368A38[0];
    S25C_Node *n = func_00119A40(h);
    char *m1;
    char *m2;
    if (n) {
        do {
            int v = n->unk34;
            char *name = n->unk44;
            int a = func_0011A8A8(v);
            int b = func_0011A8D8(v);
            int c = func_0011A8D0(v);
            func_0025CAE8(name, a, b, c);
            n = func_00119A60(h, n);
        } while (n);
    }
    m1 = D_003568B0;
    m2 = D_003568C0;
    {
        int a = func_0025F910();
        int b = func_0025F938();
        int ab = a - b;
        int c = func_0025F910();
        int d = func_0025F910();
        int e = func_0025F960();
        func_0025CAE8(m1, ab, c, d - e);
    }
    {
        int a = func_0025F988();
        int b = func_0025F9B0();
        int ab = a - b;
        int c = func_0025F988();
        int d = func_0025F988();
        int e = func_0025F9D8();
        func_0025CAE8(m2, ab, c, d - e);
    }
    return 1;
}

extern "C" int CFunc_GetHeapSize(int a, S25C450_S *s) {
    int h = D_00368A38[0];
    int out = 0;
    func_0027D870(a, 0, &out, 0);
    S25C450_H *p = func_00119730(h, out, 1);
    if (p) {
        int n = p->unk34;
        if (n) {
            int k = s->unk20;
            func_0027C160(k, 0x083FDB95, func_0011A8D8(n));
        }
    }
    return 1;
}

extern "C" int CFunc_GetMemProfileSize(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025CDC0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D458);

extern "C" int CFunc_DumpHeaps(int arg0, int arg1) {
    if (arg0 != 0) {
        if (func_0027DF00(arg0, 0xE0858748) != 0) {
            return 1;
        }
    }
    return 1;
}

extern "C" int CFunc_DumpFragments(void) {
    return 1;
}

extern "C" int CFunc_MemViewToggle(void) {
    func_0011E9C8();
    return 1;
}

extern "C" int func_0025D4D8(void) {
    return 0;
}

extern "C" S0025D4E0* func_0025D4E0(S0025D4E0* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D500);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D680);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025D6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", CFunc_DumpMemStatistics);

extern "C" int CFunc_GetNumUsedStructs(int a, S25C450_S *s) {
    int h1 = s->unk20;
    func_0027C160(h1, 0x86B89CE7, func_0025F9B0());
    int h2 = s->unk20;
    func_0027C160(h2, 0x3DD01EA1, func_0025F988());
    int h3 = s->unk20;
    func_0027C160(h3, 0x6289DD76, func_0025F9D8());
    return 1;
}

extern "C" int CFunc_InitNetMiscHeap(void) {
    func_00119CC0(D_00368A38[0]);
    return 1;
}

GP_DATA(D_003705D8);
extern "C" void func_0025DF98(void) {
    D_003705D8 = func_00264B70();
}

extern "C" void func_0025DFB8(void) {
    if (D_003705D8 != 0) {
        func_00264F60();
        D_003705D8 = 0;
    }
}

extern "C" void func_0025DFE0(void *) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025DFE8);

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025E168);

extern "C" void func_0025E170(void) {
    func_0025DFE0(D_003705F0);
    func_0025DFE0(D_00356E88);
    func_0025DFE0(D_00356E88);
    func_0025DFE0(D_003705F0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25C450", func_0025E1C8);
