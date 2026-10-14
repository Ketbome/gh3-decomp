#include "common.h"

struct N0 {
    N0* unk0;
};

struct S001C2670 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    s32 unk10;
    char pad14[0x20];
    N0* unk34;
};

struct S001C3538 {
    char pad0[0x8];
    u8 unk8;
    char pad9[0x7];
    u64 unk10_0 : 26;
    u64 unk10_26 : 4;
    u64 unk10_30 : 4;
    u64 unk10_34 : 17;
    u64 unk10_51 : 4;
    u64 unk10_55 : 9;
};

struct S001C2C88 {
    char pad0[0x4];
    void* unk4;
    s32 unk8;
};

struct S1C3898 {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
};

extern "C" {
void func_001BF288(s32 a);
void func_001C2CD8(s32 a, s32 b);
S001C2C88* func_001C2D28(void);
void func_0015EA08(void* p);
void func_001A0D38(void* p);
extern char D_00349DF8[];
extern char D_0038D080[];
void func_001BF628(void* p, s32 a);
void func_001BF6A0(void* p, s32 a);
void func_001C25A0(void* p, s32 v);
void func_001BF960(void* p);
void func_001BF2E8(s32 a, s32 b);
extern u8 D_00349E28[];
s32 func_0011D530(s32 a, s32 b, s32 c, s32 d);
S001C2C88* func_001C2D28_1(s32 a) __asm__("func_001C2D28");

extern s32 D_0036CBFC;
extern f32 D_00419240[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C1A30);

GP_DATA(D_0036CBFC);
extern "C" s32 func_001C1DE8(f32 x) {
    if (x <= D_00419240[0]) {
        return 0;
    }
    s32 last = D_0036CBFC - 1;
    if (D_00419240[last] <= x) {
        return last;
    }
    s32 step = D_0036CBFC >> 1;
    s32 best = 0;
    while (step != 0) {
        s32 i = best + step;
        if (D_00419240[i] < x) {
            best = i;
        }
        step >>= 1;
    }
    return best;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C1E70);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2508);

extern "C" void func_001C2550(char* p, s32 a) {
    *(void**)(p + 0x20) = D_00349E28;
    func_001C25A0(p, 1);
    func_001BF6A0(p, a);
}

extern "C" void func_001C25A0(void* pv, s32 v0) {
    register s32 v asm("$17") = v0;
    register char* p asm("$16") = (char*)pv;
    register s32 old asm("$18") = *(s32*)p;
    func_001BF960(p);
    s32 t = *(s32*)(p + 0x30);
    if (t != 0 && old != v) {
        func_001BF2E8(t, v ^ 1);
    }
}

extern "C" void func_001C25F8(char* p, s32 v) {
    if (v != 0 && *(s32*)(p + 0x30) != v) {
        func_001BF288(v);
        if (*(s32*)p == 0) {
            func_001BF2E8(v, 1);
            s32 t = *(s32*)(p + 0x30);
            if (t != 0) {
                func_001BF2E8(t, 0);
            }
        }
    }
    *(s32*)(p + 0x30) = v;
}

extern "C" void func_001C2670(S001C2670* p) {
    p->unk34 = 0;
}

extern "C" void func_001C2678(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2680);

extern "C" void func_001C2C18(void) {
}

extern "C" void func_001C2C20(S001C2670* p, N0* n) {
    n->unk0 = p->unk34;
    p->unk34 = n;
}

extern "C" void func_001C2C30(S001C2670* p, N0* n) {
    N0* c = p->unk34;

    if (c == n) {
        p->unk34 = c->unk0;
    } else if (c != 0) {
        while (c->unk0 != n) {
            c = c->unk0;
            if (c == 0) {
                return;
            }
        }
        c->unk0 = n->unk0;
    }
}

extern "C" void func_001C2C88(S001C2C88* p) {
    p->unk4 = D_00349DF8;
    func_0015EA08(p);
}

extern "C" void func_001C2CB0(S001C2670* p, f32 a, f32 b) {
    p->unk8 = a;
    p->unkC = b;
}

extern "C" void func_001C2CC0(S001C2670* p, s32 v) {
    p->unk10 = v;
}

extern "C" s32 func_001C2CC8(S001C2670* p) {
    return p->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2CD0);

extern "C" void func_001C2CD8(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        func_001A0D38(D_0038D080);
    }
}

extern "C" void func_001C2D08(void) {
    func_001C2CD8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2D28);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3150);

extern "C" void func_001C3240(s32 a, s32 b) {
    s32 r = func_0011D530(a, b, 0, 0);
    func_001C2D28_1(r)->unk8 = r;
}

extern "C" S001C2C88* func_001C3278(void) {
    S001C2C88* r = func_001C2D28();

    r->unk8 = 0;
    return r;
}

extern "C" {
void func_0019F538(void* p);
void func_0011A470(s32 v);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
extern s32 D_0036CC48;
extern s32 D_0038DFA0[];
}

GP_DATA(D_0036CC48);
extern "C" void func_001C32A0(S001C2C88* p) {
    func_0019F538(p);
    s32 n = D_0036CC48;
    if (p->unk8) {
        func_0011A470(p->unk8);
        n = D_0036CC48;
    }
    s32 i = 0;
    s32 end = n;
    if (n > 0) {
        s32* e = D_0038DFA0;
        do {
            i++;
            if (*e == (s32)p) {
                n--;
                D_0036CC48 = n;
                *e = D_0038DFA0[n];
                Heap_Free(D_00368A38, p);
                return;
            }
            n = end;
            e++;
        } while (i < n);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3348);

extern "C" u16 func_001C3538(S001C3538* p) {
    return 1 << (u16)p->unk10_26;
}

extern "C" u16 func_001C3558(S001C3538* p) {
    return 1 << (u16)p->unk10_30;
}

extern "C" s32 func_001C3578(char* p) {
    s32 k = (s32)((*(u64*)(p + 0x10) >> 20) & 0x3F);
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

extern "C" s32 func_001C35E0(S001C3538* p) {
    u32 v = p->unk10_51;

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

extern "C" u8 func_001C3638(S001C3538* p) {
    return p->unk8 + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3648);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3718);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3888);

extern "C" s32 func_001C3890(void) {
    return 1;
}

extern "C" void func_001C3898(S1C3898* p, s32 a, s32 b) {
    s32 area = a * b * 3;
    s32 sz = area + 0x36;
    p->unk0 = 0x42;
    p->unk1 = 0x4D;
    p->unk2 = sz;
    p->unk4 = sz >> 16;
    p->unk6 = 0;
    p->unk8 = 0;
    p->unkA = 0x36;
    p->unkC = 0;
    p->unkE = 0x28;
    p->unk10 = 0;
    p->unk12 = a;
    p->unk14 = a >> 16;
    p->unk16 = b;
    p->unk18 = b >> 16;
    p->unk1A = 1;
    p->unk1C = 0x18;
    p->unk1E = 0;
    p->unk20 = 0;
    p->unk22 = area;
    p->unk24 = area >> 16;
    p->unk26 = 0x1284;
    p->unk28 = 0;
    p->unk2A = 0x1284;
    p->unk2C = 0;
    p->unk2E = 0;
    p->unk30 = 0;
    p->unk32 = 0;
    p->unk34 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3960);
