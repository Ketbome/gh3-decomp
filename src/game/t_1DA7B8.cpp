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

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DB580);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1DA7B8", func_001DB9F0);

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
