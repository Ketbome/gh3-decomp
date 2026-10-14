#include "common.h"

struct O1E8D {
    u32 unk0;
    s32* unk4;
    char pad8[4];
    virtual void v0();
    virtual void v1();
    virtual s32 v2();
    virtual void v3();
};

struct E1E8AB {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x1C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct N1E8AB {
    N1E8AB* unk0;
    N1E8AB* unk4;
    E1E8AB* unk8;
};

struct I1E8AB {
    s32 unk0;
    N1E8AB* unk4;
};

struct L1E8AB {
    char pad0[0x24];
    N1E8AB unk24;
};

struct S1E89F8 {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x1C];
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
    virtual void v4();
};

struct S1E8E20 {
    u32 unk0;
};

struct S1E9360 {
    char pad0[0x4];
    s32 unk4;
};

struct S1E7948_S {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
};

struct S1E7948 {
    char pad0[0x10];
    S1E7948_S unk10;
};

struct S1E75A8_SC {
    char pad0[0x20];
    void* unk20;
};

struct S1E88F8_N {
    S1E88F8_N* unk0;
    S1E88F8_N* unk4;
    u32* unk8;
};

struct S1E88F8_I {
    s32 unk0;
    S1E88F8_N* unk4;
};

struct S1E88F8 {
    char pad0[0x18];
    S1E88F8_N unk18;
};

struct S1E8068_X {
    char pad0[0x10];
    s32 unk10;
};

struct S1E8068_N {
    S1E8068_N* unk0;
    S1E8068_N* unk4;
    S1E8068_X* unk8;
};

struct S1E8068_I {
    s32 unk0;
    S1E8068_N* unk4;
};

struct S1E8068 {
    char pad0[0xC];
    S1E8068_N unkC;
};

struct S1E7EC8_H {
    S1E7EC8_H* unk0;
    S1E7EC8_H* unk4;
};

struct S1E7EC8 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    S1E7EC8_H unkC;
    char unk14[0x8];
    void* unk1C;
};

struct S1E8EB0 {
    char pad0[0x2C];
    void* unk2C;
    void* unk30;
};

struct S1E7998 {
    char pad0[0xC];
    void* unkC;
    s32 unk10;
    char unk14[0x4];
};

extern "C" {
extern s32 D_0036DD70;
extern s32 D_0036DD74;
void func_001E8B50(void* p);
void func_001E8AB0(void* p);
extern S1E7948 D_0038ED70;
void func_0027D1F8(void* p, u32 key, s32* out, s32 d);
void func_0027C160(void* p, u32 key, s32 v);
void SetProgressionDifficulty(s32 v);
void SetProgressionMaxDifficulty(s32 v);
s32 GetProgressionDifficulty(void);
extern char D_0034D928[];
void func_001E99A0(void* p);
extern char D_0034DBD0[];
void func_00275730(void* p);
void func_001E8660(void* p, s32 v);
s32 func_001E9CB0(s32 v);
s32 func_001E9D98(s32 v);
s32 func_001E9390(void* p, s32 a, s32 b);
void func_001E8E20(S1E8E20* p, s32 f);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(s32 heap, void* p);
extern char D_0034D6A8[];
extern char D_0034D678[];
void func_001E92B0(void* p, int a);
s32 func_0027DF00(s32 p, u32 key);
extern s32 D_00368748;
extern char D_0034D7E8[];
void func_001E7F18(s32 a, s32 b);
int func_0027AA70(int);
int func_001287F0(int, int);
void func_0027ABB0(int, int);
void func_0027C028(int, u32, int);
void func_0028C9D0(int, int, int, int, int, int);
void func_0027AC90(int);
void func_00113250(int);
void func_001E8948(void* p);
s32 func_001E8838(void);
s32 func_001E8C00(s32* p);
void func_001E8A40(S1E89F8* p);
void func_001E8A88(S1E89F8* p);
extern char D_0034DC40[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E75A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E76C8);

extern "C" void func_001E7948(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        S1E7948* o = &D_0038ED70;
        S1E7948_S* t = &o->unk10;
        t->unk60 = 0;
        t->unk64 = 0;
        t->unk68 = 0;
    }
}

extern "C" void func_001E7978(void) {
    func_001E7948(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7998);

extern "C" void func_001E79F0(S1E7998* p) {
    void* q = p->unk14;
    s32 a = func_001E9CB0(p->unk10);
    s32 b = func_001E9D98(p->unk10);
    if (func_001E9390(q, a, b) != 0) {
        func_001E8E20((S1E8E20*)p, 1);
    }
}

extern "C" u32 func_001E7A58(void) {
    return 0xB4BA8031;
}

extern "C" void func_001E7A68(char* p, int flags) {
    *(char**)(p + 0xC) = D_0034D678;
    func_001E92B0(p + 0x14, 2);
    s32 h = D_00368A38[0];
    *(char**)(p + 0xC) = D_0034D6A8;
    Heap_Free(h, *(void**)(p + 4));
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" s32 func_001E7AE0(void) {
    return 1;
}

extern "C" void func_001E7AE8(char* p, int flags) {
    s32 h = D_00368A38[0];
    *(char**)(p + 0xC) = D_0034D6A8;
    Heap_Free(h, *(void**)(p + 4));
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7B48);

extern "C" void func_001E7CE0(char* p, int flags) {
    *(char**)(p + 0xC) = D_0034D7E8;
    char* q = *(char**)(p + 0x28);
    if (q != 0) {
        Heap_Free(D_00368A38[0], q);
    }
    func_001E92B0(p + 0x10, 2);
    s32 h = D_00368A38[0];
    *(char**)(p + 0xC) = D_0034D6A8;
    Heap_Free(h, *(void**)(p + 4));
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7D70);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7EA8);

extern "C" s32 func_001E7EC0(void) {
    return 1;
}

extern "C" S1E7EC8* func_001E7EC8(S1E7EC8* p) {
    S1E7EC8_H* h = &p->unkC;
    p->unk1C = D_0034D928;
    h->unk0 = h;
    p->unk0 = 0;
    p->unk4 = 0;
    h->unk4 = h;
    func_001E99A0(p->unk14);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7F18);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E7FD8);

extern "C" S1E8068_X* func_001E8068(S1E8068* p, s32 key) {
    S1E8068_I it;
    S1E8068_I e;
    it.unk4 = p->unkC.unk4;
    e.unk4 = &p->unkC;
    while (it.unk4 != e.unk4) {
        S1E8068_X* x = it.unk4->unk8;
        if (x->unk10 == key) {
            return x;
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unkC;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E80C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8168);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8170);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8238);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E82F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8660);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8838);

extern "C" void func_001E88F8(S1E88F8* p) {
    S1E88F8_I it;
    S1E88F8_I e;
    it.unk4 = p->unk18.unk4;
    e.unk4 = &p->unk18;
    while (it.unk4 != e.unk4) {
        *it.unk4->unk8 = 0x0F636D0D;
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk18;
    }
}

extern "C" void func_001E8948(void* pv) {
    E1E8AB* p = (E1E8AB*)pv;
    u32 k = p->unkC;
    if (k == 0xBD982FDC || k == 0x7B01911C) {
        return;
    }
    if (k == 0x152D376E) {
        if (func_001E8838() != 0) {
            if (func_001E8C00((s32*)p) != 0) {
                func_001E8A40((S1E89F8*)p);
            } else {
                func_001E8A88((S1E89F8*)p);
            }
        }
    }
    if (p->unkC == 0xB4E103FD) {
        p->v4();
    }
}

extern "C" s32 func_001E89F8(S1E89F8* p) {
    return p->unkC != 0xB4E103FD ? 0 : p->v3();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8A38);

extern "C" void func_001E8A40(S1E89F8* p) {
    p->unkC = 0xB4E103FD;
    func_001E8AB0(p);
    p->v4();
}

extern "C" void func_001E8A88(S1E89F8* p) {
    p->unkC = 0xBD982FDC;
    func_001E8B50(p);
}

extern "C" void func_001E8AB0(void* pv) {
    L1E8AB* p = (L1E8AB*)pv;
    I1E8AB it;
    I1E8AB e;
    it.unk4 = p->unk24.unk4;
    e.unk4 = &p->unk24;
    while (it.unk4 != e.unk4) {
        if (it.unk4->unk8->unkC != 0xBD982FDC) {
            it.unk4->unk8->unkC = 0x7B01911C;
            it.unk4->unk8->v5();
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk24;
    }
}

extern "C" void func_001E8B50(void* pv) {
    L1E8AB* p = (L1E8AB*)pv;
    I1E8AB it;
    I1E8AB e;
    it.unk4 = p->unk24.unk4;
    e.unk4 = &p->unk24;
    while (it.unk4 != e.unk4) {
        if (it.unk4->unk8->unkC == 0x7B01911C) {
            it.unk4->unk8->unkC = 0x152D376E;
            it.unk4->unk8->v6();
            func_001E8948(it.unk4->unk8);
        }
        it.unk4 = it.unk4->unk4;
        e.unk4 = &p->unk24;
    }
}

extern "C" s32 func_001E8C00(s32* p) {
    if (*p != 0) {
        bool a = false;
        if (func_0027DF00(*p, 0x30768FE3)) {
            a = D_00368748 == 0;
        }
        if (a) {
            return 0;
        }
        bool b = false;
        if (func_0027DF00(*p, 0xC4648CE4)) {
            b = D_00368748 != 0;
        }
        if (b) {
            return 0;
        }
    }
    return 1;
}

extern "C" void func_001E8C80(void) {
}

extern "C" void func_001E8C88(void) {
}

extern "C" void func_001E8C90(void) {
}

extern "C" void func_001E8C98(void) {
}

extern "C" void func_001E8CA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8CA8);

extern "C" void func_001E8D88(O1E8D* p) {
    if (p->v2() != 0) {
        register s32 f asm("$3");
        if (p->unk4 != 0) {
            s32 i = GetProgressionDifficulty();
            register s32* a asm("$3") = p->unk4;
            s32 d = a[i];
            f = 1;
            if (d != 0) {
                f = p->unk0 == 0x4E29E602;
            }
        } else {
            f = p->unk0 == 0x4E29E602;
        }
        if (f != 0) {
            return;
        }
    }
    p->v3();
}

extern "C" void func_001E8E20(S1E8E20* p, s32 f) {
    p->unk0 = f ? 0x4E29E602 : 0x0F636D0D;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8E40);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8E48);

extern "C" void func_001E8EB0(S1E8EB0* p, s32 flags) {
    p->unk2C = D_0034DBD0;
    func_00275730(p->unk30);
    p->unk30 = 0;
    func_001E8660(p, flags);
}

extern "C" void func_001E8F00(char* p) {
    int t = func_0027AA70(func_001287F0(8, 1));
    int k = *(int*)p;
    if (k != 0) func_0027ABB0(t, k);
    func_0027C028(t, 0xA1DC81F9, *(int*)(p + 0x30));
    func_0028C9D0(0x04C7C464, t, 0, 0, 0, 0);
    if (t != 0) {
        func_0027AC90(t);
        func_00113250(t);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E8FF0);

extern "C" s32 func_001E9008(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E9010);

extern "C" void func_001E92B0(void* pv, s32 flags) {
    char* p = (char*)pv;
    *(char**)(p + 0xC) = D_0034DC40;
    u32 k = *(u32*)(p + 8);
    if (k == 0x9E497FC6) goto a;
    if (k > 0x9E497FC6) goto end;
    if (k == 0x7A26BB9D) goto b;
    goto end;
a: {
        void* q = *(void**)p;
        if (q != 0) {
            Heap_Free(D_00368A38[0], q);
        }
        goto end;
    }
b: {
        void* q = *(void**)p;
        if (q != 0) {
            Heap_Free(D_00368A38[0], q);
        }
    }
end:
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" s32 func_001E9360(S1E9360* p) {
    return p->unk4 < 2 ? 0 : GetProgressionDifficulty();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E75A8", func_001E9390);

extern "C" void SetProgressionMaxDifficulty(s32 v) {
    D_0036DD70 = v;
}

extern "C" void SetProgressionDifficulty(s32 v) {
    D_0036DD74 = v;
}

extern "C" s32 GetProgressionDifficulty(void) {
    return D_0036DD74;
}

extern "C" int CFunc_SetProgressionDifficulty(void* params) {
    s32 v;
    func_0027D1F8(params, 0x44949010, &v, 1);
    SetProgressionDifficulty(v);
    return 1;
}

extern "C" int CFunc_GetProgressionDifficulty(void* params, S1E75A8_SC* script) {
    void* x = script->unk20;
    func_0027C160(x, 0x44949010, GetProgressionDifficulty());
    return 1;
}

extern "C" int CFunc_SetProgressionMaxDifficulty(void* params) {
    s32 v;
    func_0027D1F8(params, 0x44949010, &v, 1);
    SetProgressionMaxDifficulty(v);
    return 1;
}
