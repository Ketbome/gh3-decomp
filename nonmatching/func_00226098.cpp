#include "common.h"

struct A2270 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

struct O2270 {
    virtual void v0();
    virtual void v1(s32 a, A2270* b);
};

struct E225C {
    s32 key;
    s32 on;
    char pad8[0x18];
};

struct VEntry225 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S225 {
    VEntry225* unk0;
};

struct S225b {
    char pad0[0xC];
    int unkC;
    int unk10;
};

struct List225 {
    int unk0;
    int unk4;
    void* unk8;
};

extern "C" {
extern List225 D_003938C8;
void func_00226B28(int, int);
void func_001EABC0(int, int);
void func_002A1918(int, int, int, int, int);
void func_00226CD0(int, int);
void func_00226E30(int, int);
void func_0027D870(int, int, int*, int);
int func_00226918(int);
int func_00225E20(int);
void func_00225A78(void*, int);
void memset(void*, int, int);
void func_00225CA8(int, void*);
extern u8 D_00352470[];
u32 CrcFromPathLowercase(const char*);
extern int D_003918C8[];
int func_00289E08(int);
int func_001D83D0(void*, void*, void*);
extern void* D_0036D3B0[] __attribute__((section(".sdata")));
extern u8 func_00228820[];
void func_00226178(int, int);
int func_0027D1F8(int, int, int*, int);
extern void* D_00368A38;
void Heap_Free(void*, void*);
void func_00226730(int, int, int);
void func_0011A558(u32 a, s32 b, s32 c);
void func_0011A568(void);
s32 func_001C7760(s32 a);
s32 func_001C8258(s32 a);
extern s32 D_0036CDB4;
extern s32 D_00372580;
s32 func_00223C28(s32 a, void* b);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA98(s32 a, s32 b);
void func_0027ABB0(s32 a, s32 b);
void func_001E0428(s32 a);
void func_0027AC90(s32 a);
void func_00113250(s32 a);
void func_001DF900(s32 a);
}

extern "C" void func_00225BF0(void* a, int b) {
    func_00225A78(a, func_00225E20(b));
}

extern "C" s32 func_00225C28(char* a, s32 k) {
    E225C* e = (E225C*)(a + 4);
    u32 i = 0;
    do {
        if (e[0].on != 0 && k == e[0].key) return 1;
        if (e[1].on != 0 && k == e[1].key) return 1;
        if (e[2].on != 0 && k == e[2].key) return 1;
        i += 4;
        if (e[3].on != 0 && k == e[3].key) return 1;
        e += 4;
    } while (i < 0x100);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00225D78);

extern "C" int func_00225E20(int a) {
    char buf[0x100];
    buf[0] = D_00352470[0];
    memset(buf + 1, 0, 0xFF);
    func_00225CA8(a, buf);
    return CrcFromPathLowercase(buf);
}

struct H225 {
    int unk0;
    char* unk4;
    char* unk8;
};

extern "C" {
extern H225 D_003920C8[];
extern s8 D_003938D8[];
extern int D_00372E4C;
extern s32 D_00372E40;
extern s32 D_00372E48;
void func_00226030(void);
}

extern "C" void func_00225E70(int a, int b) {
    D_00372E48 = b;
    D_00372E40 = a;
    for (int i = 0; i < 0x200; i++) {
        D_003918C8[i] = 0;
        D_003938D8[i] = 0;
        H225* h = &D_003920C8[i];
        char* e = (char*)h + 4;
        h->unk4 = e;
        char* c = h->unk8;
        h->unk8 = e;
        if (c != e) {
            char* end = e;
            asm("" : "+r"(end));
            do {
                char* nx = *(char**)(c + 4);
                Heap_Free(D_00368A38, c);
                c = nx;
            } while (c != end);
        }
    }
    D_00372E4C = 0;
    func_00226030();
}

extern "C" void func_00225F58(int a, int b) {
    func_002A1918(a, b, 0, 0, 0);
}

extern "C" int func_00225F80(void) {
    return D_003938C8.unk8 != &D_003938C8.unk4;
}

struct N225;
extern "C" struct N225* D_003938D0[];

struct N225 {
    N225* unk0;
    N225* unk4;
    int unk8;
    int unkC;
};

struct It225 {
    int unk0;
    N225* unk4;
    int unk8;
    int unkC;
};

extern "C" int func_00225FA0(void) {
    if (!func_00225F80()) return 0;
    It225 a, b, c, d, e;
    a.unk4 = D_003938D0[0];
    func_00225F58(a.unk4->unk8, a.unk4->unkC);
    N225* n = a.unk4;
    c.unk4 = n;
    e.unk4 = n;
    N225* nx = n->unk4;
    d.unk4 = n;
    c.unk4 = nx;
    n->unk0->unk4 = n->unk4;
    n->unk4->unk0 = n->unk0;
    Heap_Free(D_00368A38, n);
    b.unk4 = c.unk4;
    return 1;
}

extern "C" void func_00226030(void) {
    List225* d = &D_003938C8;
    char* e = (char*)d + 4;
    char* c = (char*)d->unk8;
    d->unk8 = e;
    d->unk4 = (int)e;
    if (c != e) {
        char* end = e;
        asm("" : "+r"(end));
        do {
            char* nx = *(char**)(c + 4);
            Heap_Free(D_00368A38, c);
            c = nx;
        } while (c != end);
    }
}

extern "C" int func_00222F90(int);

extern "C" void func_00226098(void) {
    It225 a, end, c, d, e;
    It225* pe = &end;
    a.unk4 = (N225*)D_003938C8.unk8;
    N225* tl = (N225*)((char*)&D_003938C8 + 4);
    pe->unk4 = tl;
    if (a.unk4 != end.unk4) {
        It225* pe2 = pe;
        N225* tl2 = tl;
        asm("" : "+r"(tl2), "+r"(pe2));
        do {
            if ((func_00222F90(a.unk4->unk8) ^ 1) != 0) {
                N225* n = a.unk4;
                c.unk4 = n;
                e.unk4 = n;
                N225* nx = n->unk4;
                d.unk4 = n;
                c.unk4 = nx;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                Heap_Free(D_00368A38, n);
                end.unk4 = c.unk4;
                a.unk4 = c.unk4;
            } else {
                a.unk4 = a.unk4->unk4;
            }
            pe2->unk4 = tl2;
        } while (a.unk4 != end.unk4);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226178);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002262A0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002262A8);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226338);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226340);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226528);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226730);

static inline s32 Find226(s32 key, s32* out) {
    s32 i = key & 0x1FF;
    if (D_003918C8[i]) {
        do {
            if (D_003918C8[i] == key) {
                if (out) *out = i;
                return 1;
            }
            i = (i + 1) & 0x1FF;
        } while (D_003918C8[i]);
    }
    return 0;
}

extern s8 D_003938D8[];

extern "C" s32 func_00226888(s32 key) {
    s32 i;
    return Find226(key, &i) ? D_003938D8[i] != 0 : 0;
}

extern "C" int func_00226918(int key) {
    int i = key & 0x1FF;
    if (D_003918C8[i]) {
        do {
            if (D_003918C8[i] == key) return 1;
            i = (i + 1) & 0x1FF;
        } while (D_003918C8[i]);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226970);

extern "C" int CFunc_CreateNodeFlag(int s) {
    int a = 0;
    func_0027D870(s, 0, &a, 1);
    int b = 0;
    func_0027D1F8(s, 0, &b, 0);
    func_00226178(a, b != 0);
    return 1;
}

extern "C" int CFunc_ChangeNodeFlag(int s) {
    int a = 0;
    func_0027D870(s, 0, &a, 1);
    int b = 0;
    func_0027D1F8(s, 0, &b, 1);
    int c = 0;
    func_0027D1F8(s, 0x8002809C, &c, 0);
    func_00226730(a, b != 0, c);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", CFunc_GetNodeFlag);

extern "C" void CFunc_NodeFlagExists(int a) {
    int tmp = 0;
    func_0027D870(a, 0, &tmp, 1);
    func_00226918(tmp);
}

extern "C" int CFunc_DumpNodeFlags(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226B28);

extern "C" void func_00226C78(int a, int b) {
    func_00226CD0(b, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226CA0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00226CD0);

extern "C" s32 D_00372E40;
extern "C" s32 D_00372E48;

struct S226a { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; };
struct S226b { s32 unk0; s32 unk4; s32 unk8; };

GP_DATA(D_00372E40);
extern "C" void func_00226E30(int ai, int bi) {
    S226a* a = (S226a*)ai;
    S226b* b = (S226b*)bi;
    s32 t = b->unk4;
    if (t == D_00372E40) {
        a->unk4 = Find226(b->unk8, &a->unkC);
    } else if (t == D_00372E48) {
        a->unk8 = Find226(b->unk8, &a->unk10);
    } else if (t == 0xA1DC81F9) {
        a->unk0 = b->unk8;
    }
}

extern "C" void func_00226F40(void) {
    func_00226B28(1, 0xFFFF);
}

extern "C" void func_00226F60(S225* self, int a, S225b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry225* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00226FA0(s32 self, s32 a) {
    s32 buf;
    s32 r = 0;
    if (func_00223C28(a, &buf) != 0) {
        r = func_0027AA98(func_001287F0(8, 1), buf);
        func_0027ABB0(r, a);
        a = r;
    }
    func_0011A558(0xAD57CF1F, 0, 0);
    func_001E0428(a);
    func_0011A568();
    if (r != 0) {
        func_0027AC90(r);
        func_00113250(r);
    }
}

extern "C" void func_00227048(int a, int b, int c, int d) {
    int v[2];
    if (d) v[1] = func_00289E08(d);
    else v[1] = 0;
    v[0] = c;
    func_001D83D0(D_0036D3B0[0], func_00228820, v);
}

extern "C" void func_002270A0(O2270* o, s32 a, A2270* b) {
    if (b->unk10 == 0) {
        if (func_001C7760(D_0036CDB4) == 0 || func_001C8258(D_00372580) != 0) {
            func_0011A558(0xBDF8E6F2, 0, 0);
            func_0011A568();
        }
        if (b->unkC != 0) {
            o->v1(a, b);
        }
    }
}

extern "C" void func_00227140(void* self, int a, int* b) {
    func_001EABC0(*b, 1);
}

extern "C" void func_00227160(void* self, int a, int b) {
    func_001EABC0(b, 0);
}

extern "C" void func_00227180(S225* self, int a, S225b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry225* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_002271C0(s32 self, s32 a) {
    s32 buf;
    s32 r = 0;
    if (func_00223C28(a, &buf) != 0) {
        r = func_0027AA98(func_001287F0(8, 1), buf);
        func_0027ABB0(r, a);
        a = r;
    }
    func_0011A558(0xAD57CF1F, 0, 0);
    func_001DF900(a);
    func_0011A568();
    if (r != 0) {
        func_0027AC90(r);
        func_00113250(r);
    }
}

extern "C" void func_00227268(int a, int b, int c, int d) {
    int v[2];
    if (d) v[1] = func_00289E08(d);
    else v[1] = 0;
    v[0] = c;
    func_001D83D0(D_0036D3B0[0], func_00228820, v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_002272C0);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227570);

INCLUDE_ASM("asm/nonmatchings/game/t_225BF0", func_00227B80);
