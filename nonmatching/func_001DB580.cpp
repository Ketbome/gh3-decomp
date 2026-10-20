#include "common.h"

struct S1DB9C0_N {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    S1DB9C0_N* unkC;
    S1DB9C0_N* unk10;
    void* unk14;
};

struct S1DB9C0 {
    s32 unk0;
    S1DB9C0_N unk4;
};

struct S1DB560 {
    char pad0[0x28];
    s32 unk28;
};

struct S1DC750 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct S1DBAC0_N {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    S1DBAC0_N* unkC;
    S1DBAC0_N* unk10;
    virtual void v1(s32 f);
    S1DBAC0_N* Get() { return unk4 == 0xFFFFFFFF ? 0 : this; }
};

struct S1DBAC0 {
    char pad0[0x10];
    S1DBAC0_N* unk10;
};

extern "C" {
extern char D_0034C278[];
void func_001DBC78(void* params, void* script, s32 v);
void func_0027D870(void* params, u32 key, s32* out, s32 d);
void func_001DBB40(s32 a, void* script, s32 v);
extern s32 D_0036D554;
extern char D_0034C260[];
void func_001DCC38(s32 a, s32 b);
void Heap_Free(s32 h, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DA7B8);

extern "C" void func_001DA8F8(char* p, s32 flags) {
    *(char**)(p + 0x210) = D_0034C260;
    s32 k = *(s32*)(p + 8);
    if (k != 0) {
        func_001DCC38(k, 3);
    }
    char* l = p + 0x14;
    char* e = p + 0x18;
    char* c = *(char**)(l + 8);
    *(char**)(l + 8) = e;
    *(char**)(l + 4) = e;
    if (c != e) {
        char* end = e;
        asm("" : "+r"(end));
        char* x = c;
        do {
            c = *(char**)(c + 4);
            Heap_Free(D_00368A38[0], x);
            x = c;
        } while (c != end);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DA9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DAB18);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DAC78);

extern "C" void func_001DB560(S1DB560* p, s32 v) {
    p->unk28 = v;
}

extern "C" void func_001DB568(void) {
}

extern "C" void func_001DB570(void) {
}

extern "C" void func_001DB578(void) {
}

struct N1DB5 {
    N1DB5* unk0;
    N1DB5* unk4;
    void* unk8;
};

struct I1DB5 {
    s32 unk0;
    N1DB5* unk4;
    I1DB5& operator++() { unk4 = *(N1DB5**)unk4; return *this; }
};

extern "C" {
void* Heap_Alloc(s32 h, s32 sz, s32 a, s32 b);
}

extern "C" void func_001DB580(char* p, char* o) {
    I1DB5 d;
    I1DB5 b;
    I1DB5 c;
    N1DB5* hd = (N1DB5*)(p + 0x18);
    N1DB5* first = hd->unk0;
    b.unk4 = hd;
    c.unk4 = hd;
    N1DB5* node = (N1DB5*)Heap_Alloc(D_00368A38[0], 0xC, 1, 0);
    N1DB5 el;
    el.unk0 = first;
    el.unk4 = hd;
    el.unk8 = o;
    if (node) {
        *node = el;
    }
    hd->unk0 = node;
    node->unk0->unk4 = node;
    d.unk4 = (++b).unk4;
    *(s32*)(o + 0x10) = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DB638);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DB708);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DB8A8);

extern "C" S1DB9C0* func_001DB9C0(S1DB9C0* p) {
    S1DB9C0_N* n = &p->unk4;
    n->unk4 = 0xFFFFFFFF;
    n->unk8 = 0;
    n->unkC = n;
    n->unk10 = n;
    n->unk14 = D_0034C278;
    return p;
}

struct S1DB9F0_N {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    S1DB9F0_N* unkC;
    S1DB9F0_N* unk10;
    void* unk14;
    S1DB9F0_N* Get() { return unk4 == 0xFFFFFFFF ? 0 : this; }
};

struct S1DB9F0 {
    s32 unk0;
    S1DB9F0_N unk4;
};

extern "C" {
void func_00119490(s32 h, s32 v);
void func_001194B8(s32 h);
s32 func_00119610(s32 h, s32 v);
void* operator_new(u32 size);
extern char D_0034C290[];
}

extern "C" void func_001DB9F0(S1DB9F0* p, u32 key) {
    S1DB9F0_N* n = p->unk4.unkC;
    while ((n = n->Get()) != 0) {
        if (n->unk4 == key) {
            return;
        }
        n = n->unkC;
    }
    s32 h = D_00368A38[0];
    func_00119490(h, func_00119610(h, 5));
    S1DB9F0_N* o = (S1DB9F0_N*)operator_new(0x18);
    s32 h3 = D_00368A38[0];
    o->unk4 = key;
    o->unk8 = 0;
    o->unkC = o;
    o->unk10 = o;
    o->unk14 = D_0034C290;
    func_001194B8(h3);
    S1DB9F0_N* h2 = &p->unk4;
    S1DB9F0_N* last = h2->unk10;
    o->unkC = h2;
    o->unk10 = last;
    h2->unk10->unkC = o;
    h2->unk10 = o;
}

extern "C" void func_001DBAC0(S1DBAC0* p, u32 key) {
    S1DBAC0_N* found = 0;
    S1DBAC0_N* n = p->unk10;
    while ((n = n->Get()) != 0) {
        if (n->unk4 == key) {
            found = n;
            break;
        }
        n = n->unkC;
    }
    if (found != 0) {
        found->unk10->unkC = found->unkC;
        found->unkC->unk10 = found->unk10;
        found->unkC = found;
        found->unk10 = found;
        found->v1(3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DBB40);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DBC78);

extern "C" int CFunc_BroadcastEvent(void* params, void* script) {
    func_001DBC78(params, script, 1);
    return 1;
}

extern "C" int CFunc_LaunchEvent(void* params, void* script) {
    func_001DBC78(params, script, 0);
    return 1;
}

GP_DATA(D_0036D554);
extern "C" int CFunc_WaitForEvent(void* params, void* script) {
    s32 v;
    func_0027D870(params, 0x7321A8D6, &v, 0);
    func_001DBB40(D_0036D554, script, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", CFunc_ObjectExists);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", CFunc_TerminateObjectsScripts);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", CFunc_AssignAlias);

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", CFunc_SetObjectProps);

extern "C" int CFunc_PrintEventLog(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DC748);

extern "C" void func_001DC750(S1DC750* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S1DC750* func_001DC760(S1DC750* p) {
    func_001DC750(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DC788);
