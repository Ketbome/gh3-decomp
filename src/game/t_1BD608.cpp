// cflags: -funroll-loops
#include "common.h"

struct S001BD998 {
    char pad0[0x8];
    S001BD998* unk8;
};

struct S001BF1D0 {
    char pad0[0x8];
    u32 unk8;
    char padC[0x24];
    u64 unk30_0 : 26;
    u64 unk30_26 : 4;
    u64 unk30_30 : 4;
    u64 unk30_34 : 17;
    u64 unk30_51 : 4;
    u64 unk30_55 : 9;
    char pad38[0x10];
    u16 unk48;
    u16 unk4A;
    char pad4C[0x8];
    s32 unk54;
};

extern "C" {
s32 func_0019CD38(s32 a, s32 b);
extern S001BD998* D_0036CB74;
void func_001BB068(void);
void func_0019E380(s32 a, s32 b, s32 c, s32 d, s32 e);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
extern char* D_0036CB70;
void func_001BD9B8(S001BD998* p);
void func_001BF298(S001BF1D0* p);
void* func_0011A380(s32 size);
void func_0030A2F4(void* d, void* s, s32 n);
void func_001BE3A0(void* p, s32 a);
void func_001BF0B8(void* p);
s32 func_001BF4A0(char* p);
extern void* D_0036CBC0;
void func_001BF2B8(S001BF1D0* p);
void* Heap_Alloc(s32 h, s32 size, s32 a, s32 b);
void func_001BE088(void* p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD608);

extern "C" void func_001BD6E0(char* p, s32 a, s32 b, s32 c) {
    s32 i = 0;
    register char* pp asm("$18") = p;
    char* e = *(char**)(pp + 0x30);
    if (*(s32*)(pp + 0x28) > 0) {
        do {
            if (*(s32*)(e + 0x48) == a && *(s32*)(e + 0x44) == b) {
                func_0019CD38(*(s32*)(e + 0xC), c);
            }
            i++;
            e += 0x50;
        } while (i < *(s32*)(pp + 0x28));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD780);

GP_DATA(D_0036CB70);
extern "C" void func_001BD8E8() {
    if (D_0036CB70 == 0) {
        D_0036CB70 = (char*)Heap_Alloc(D_00368A38, 0x12C, 1, 0);
        for (s32 i = 0; i < 25; i++) func_001BD9B8((S001BD998*)(D_0036CB70 + i * 12));
    }
}

GP_DATA(D_0036CB74);
extern "C" S001BD998* func_001BD998(void) {
    S001BD998* p = D_0036CB74;

    if (p != 0) {
        D_0036CB74 = p->unk8;
    }
    return p;
}

extern "C" void func_001BD9B8(S001BD998* p) {
    p->unk8 = D_0036CB74;
    D_0036CB74 = p;
}

extern "C" void func_001BD9C8(S001BD998* p, s32 flags) {
    u32 f = *(u32*)((char*)p + 8);
    if (f & 2) {
        *(u32*)((char*)p + 8) = f & 0xFFFFFFFD;
        func_001BB068();
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct F1BDA {
    char pad0[8];
    u32 unk8;
    char padC[4];
    void* unk10;
    char pad14[0x18];
    void* unk2C;
};

extern "C" {
char* strcpy(char*, const char*);
void* func_0011D530(char*, char*, s32, s32);
void func_0030A554(char*, char*);
extern char D_00349CB0[];
}

GP_DATA(D_0036CBC0);
extern "C" F1BDA* func_001BDA28(const char* name, s32 a, s32 b, s32 c) {
    char buf[0x80];
    char buf2[0x10];
    if (a != 0) {
        strcpy(buf, name);
    } else {
        strcpy(buf, name);
    }
    func_0030A554(buf, D_00349CB0);
    F1BDA* f = (F1BDA*)func_0011D530(buf, buf2, 0, 0);
    f->unk10 = f;
    if (c != 0) f->unk8 |= 1;
    if (a != 0) {
        u32 t = f->unk8;
        f->unk8 = t | 8;
        if (b != 0 && c == 0) f->unk8 = t | 0xA;
    }
    func_001BE3A0(f, 0);
    if (a != 0 && c == 0) {
        f->unk2C = D_0036CBC0;
        D_0036CBC0 = f;
    }
    if (c != 0) func_001BF0B8(f);
    return f;
}

struct S1BDB {
    char pad0[8];
    u32 unk8;
    char padC[4];
    S1BDB* unk10;
    char pad14[0x18];
    void* unk2C;
};

GP_DATA(D_0036CBC0);
extern "C" S1BDB* func_001BDB28(S1BDB* a, s32 size, s32 f2, s32 f3, s32 f4, s32 f5) {
    S1BDB* p;
    if (f5 != 0) {
        p = (S1BDB*)func_0011A380(size);
        func_0030A2F4(p, a, size);
    } else {
        p = a;
        p->unk8 |= 0x80;
    }
    p->unk10 = p;
    if (f4 != 0) {
        p->unk8 |= 1;
    }
    if (f2 != 0) {
        u32 t = p->unk8;
        p->unk8 = t | 8;
        if (f3 != 0 && f4 == 0) {
            p->unk8 = t | 0xA;
        }
    }
    func_001BE3A0(p, 0);
    if (f2 != 0 && f4 == 0) {
        p->unk2C = D_0036CBC0;
        D_0036CBC0 = p;
    }
    if (f4 != 0) {
        func_001BF0B8(p);
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDC30);

extern "C" void func_001BDCF8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_001BE088(Heap_Alloc(D_00368A38, 0x60, 1, 0), a, b, c, d, e, f);
}

struct S1BDD {
    char pad0[8];
    u32 unk8;
    char padC[4];
    void* unk10;
    char pad14[0x14];
    s32 unk28;
    void* unk2C;
    char pad30[0x24];
    s32 unk54;
};

extern "C" S1BDD* func_001BDD90(S1BDD* o) {
    if (o->unk28 == 0) {
        return 0;
    }
    if (o->unk10 == 0) {
        return 0;
    }
    S1BDD* n = (S1BDD*)func_0011A380(o->unk28);
    func_0030A2F4(n, o->unk10, o->unk28);
    u32 f = n->unk8;
    if (f & 0x80) {
        n->unk8 = f ^ 0x80;
    }
    n->unk10 = n;
    n->unk54 = 0;
    func_001BE3A0(n, (s32)n - (s32)o);
    register u64 g asm("$3") = *(u64*)&n->unk8;
    if ((g & 9) == 8) {
        n->unk2C = D_0036CBC0;
        D_0036CBC0 = n;
    }
    return n;
}


INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDE38);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDF08);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE088);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE3A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE498);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE558);

struct S1BF0 {
    char pad0[0x14];
    char* unk14;
    char pad18[0x30];
    u16 unk48;
    u16 unk4A;
};

extern "C" void func_001BF0B8(void* pv) {
    S1BF0* p = (S1BF0*)pv;
    s32 i = 0;
    s32 n = p->unk4A - 1;
    s32 w = p->unk48 * func_001BF4A0((char*)p);
    s32 sz = w / 8;
    char* tmp = (char*)Heap_Alloc(D_00368A38, sz, 1, 0);
    if (n > 0) {
        s32 hi = n * sz;
        s32 lo = 0;
        s32 neg = -sz;
        do {
            i++;
            n--;
            func_0030A2F4(tmp, p->unk14 + lo, sz);
            func_0030A2F4(p->unk14 + lo, p->unk14 + hi, sz);
            lo += sz;
            func_0030A2F4(p->unk14 + hi, tmp, sz);
            hi += neg;
        } while (i < n);
    }
    Heap_Free(D_00368A38, tmp);
}

extern "C" void func_001BF1D0(S001BF1D0* p, s32 v) {
    if (v) {
        p->unk8 |= 0x400;
    } else {
        p->unk8 &= ~0x400;
    }
}

extern "C" void func_001BF200(S001BF1D0* p, s32 v) {
    if (v) {
        p->unk8 |= 0x800;
    } else {
        p->unk8 &= ~0x800;
    }
}

extern "C" int func_001BF230(S001BF1D0* p) {
    p->unk8 |= 2;
    func_001BB068();
    return 1;
}

extern "C" int func_001BF258(S001BF1D0* p) {
    p->unk8 &= ~2;
    func_001BB068();
    return 1;
}

extern "C" void func_001BF288(S001BF1D0* p) {
    p->unk8 |= 4;
}

extern "C" void func_001BF298(S001BF1D0* p) {
    p->unk54++;
    p->unk8 |= 2;
}

extern "C" void func_001BF2B8(S001BF1D0* p) {
    if (--p->unk54 == 0) {
        p->unk8 &= ~2;
    }
}

extern "C" void func_001BF2E8(char* p, s32 v) {
    s32 old = ((s32)*(u32*)(p + 8) >> 1) & 1;
    if (v != 0) {
        func_001BF298((S001BF1D0*)p);
    } else {
        func_001BF2B8((S001BF1D0*)p);
    }
    if (old != v) {
        func_001BB068();
    }
}

extern "C" u16 func_001BF348(S001BF1D0* p) {
    return p->unk48;
}

extern "C" u16 func_001BF350(S001BF1D0* p) {
    return p->unk4A;
}

extern u32 D_00372C30;
extern s32 D_0036C7E8;
extern s32 D_0036C7F0;

extern "C" void func_001BF358(char* p) {
    s32 f = *(s32*)(p + 8);
    if ((f >> 1) & 1) {
        if (((f >> 11) & 1) == 0) {
            u32 x = *(u16*)(p + 0x4C);
            u32 y = *(u16*)(p + 0x4E);
            u16 a = *(u16*)&D_00372C30;
            D_00372C30 += x;
            u16 b = *(u16*)&D_00372C30;
            D_00372C30 += y;
            if ((u32)(D_0036C7E8 + D_0036C7F0) >= D_00372C30) {
                *(u16*)(p + 0x50) = a;
                *(u16*)(p + 0x52) = b;
                func_0019E380(6, (s32)(p + 0x30), (s16)a, (s16)b, -1);
            }
        }
    }
}

extern "C" void func_001BF408(char* p) {
    func_0019E380(0x50, *(s32*)(p + 0x40), *(s16*)(p + 0x50), -1, -1);
    s32 t = *(s32*)(p + 0x44);
    if (t != 0) {
        func_0019E380(0x50, t, *(s16*)(p + 0x52), -1, -1);
    }
}

extern "C" u16 func_001BF460(S001BF1D0* p) {
    return 1 << (u16)p->unk30_26;
}

extern "C" u16 func_001BF480(S001BF1D0* p) {
    return 1 << (u16)p->unk30_30;
}

extern "C" s32 func_001BF4A0(char* p) {
    s32 k = (s32)((*(u64*)(p + 0x30) >> 20) & 0x3F);
    switch (k) {
    case 0:
        return 0x20;
    case 1:
        return 0x18;
    case 2:
        return 0x10;
    case 19:
        return 8;
    case 20:
        return 4;
    }
    return 0;
}

extern "C" s32 func_001BF508(S001BF1D0* p) {
    u32 v = p->unk30_51;

    switch (v) {
    case 0:
        return 32;
    case 1:
        return 24;
    case 2:
        return 16;
    }
    return 0;
}

extern "C" s32 func_001BF560(void) {
    return 1;
}

extern "C" s32 func_001BF568(s32 x) {
    switch (x) {
    case 32:
        return 0;
    case 24:
        return 1;
    case 16:
        return 2;
    case 8:
        return 0x13;
    case 4:
        return 0x14;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF5C0);

extern "C" void func_001BF5F8(u64* p, u16 a, u16 b, u16 c, s32 d) {
    *p = (u64)a | ((u64)c << 16) | ((u64)b << 32) | ((u64)d << 48);
}
