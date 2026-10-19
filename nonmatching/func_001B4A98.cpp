#include "common.h"

struct S001B49A0 {
    char pad0[0x6];
    s16 unk6;
    char pad8[0x4];
    s32 unkC;
};

struct R1B43;
extern "C" {
void* func_0019F9F8(void);
extern s32 D_0036C948;
extern s32 D_0036C94C;
extern s32 D_0036C950;
extern s32 D_0036C954;
extern s32 D_0036C958;
extern s32 D_0036C95C;
extern s32 D_0036C960;
extern s32 D_0036C964;
extern s32 D_0036CA4C;
extern s32 D_0037329C;
extern s32 D_00373338;
extern s32 D_00373324;
extern s32 D_00373294;
void func_001B58B0(s32);
void func_0019BE48(s32);
extern s32 D_00373288;
extern s32 D_00373298;
extern u32* D_003732E0;
extern s32 D_00373284;
void func_001BD128(void);
void func_001BB680(void*, s32, s32, f32, f32, f32, f32, f32, f32);
void func_001BCD88(void*, f32, f32, f32, f32);
extern s32 D_0036CAA4;
extern s32 D_0036CA50;
extern s32 D_0036CA54;
void func_001B61D0(void);
void func_001B7898(void*);
void func_001B95F0(void*);
void func_001B6620(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4190);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B42D8);

GP_DATA(D_0036C948);
GP_DATA(D_0036C94C);
GP_DATA(D_0036C950);
GP_DATA(D_0036C958);
GP_DATA(D_0036C954);
GP_DATA(D_0036C960);
GP_DATA(D_0036C95C);
extern "C" void func_001B4330(void) {
    D_0036C948 = 0;
    D_0036C94C = 0;
    D_0036C950 = 0;
    D_0036C958 = 0;
    D_0036C954 = 0;
    D_0036C960 = 0;
    D_0036C95C = 0;
    D_0036C964 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4358);

struct D1B43 {
    char pad0[4];
    s32 unk4;
    char pad8[0x38];
};

struct Q1B43 {
    char pad0[8];
    s32 unk8;
    char pad0C[0x44];
};

struct R1B43;

struct E1B43 {
    char pad0[8];
    s32 unk8;
    char padC[0x28];
    R1B43* unk34;
    char pad38[0x18];
};

struct T1B43 {
    s32 unk0;
    char pad4[0xC];
    E1B43* unk10;
};

struct S1B43 {
    char pad0[0x14];
    T1B43* unk14;
    s32 unk18;
    s32 unk1C;
    D1B43* unk20;
    char pad24[4];
    s32 unk28;
    char pad2C[4];
    Q1B43* unk30;
};

struct R1B43 {
    S1B43* unk0;
    s32 unk4;
    Q1B43* unk8;
    s32 unkC;
    R1B43* unk10;
};

struct A1B43 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_001B4360(A1B43* a, S1B43* s) {
    register s32 i asm("$7") = 0;
    T1B43* t = s->unk14;
    s32 n = a->unk4;
    s32 cnt = t->unk0;
    register s32 key asm("$4") = a->unk0;
    E1B43* e = t->unk10;
    for (; i < cnt; i++, e++) {
        if (e->unk8 == key) {
            break;
        }
    }
    R1B43* r = (R1B43*)func_0019F9F8();
    r->unk0 = s;
    register s32 t18 asm("$3") = s->unk18;
    r->unk4 = t18;
    register s32 m asm("$4") = s->unk28;
    s32 b = (s32)s->unk30;
    r->unkC = n;
    m = m * 0x50;
    r->unk8 = (Q1B43*)(b + m);
    register R1B43* ee asm("$4") = e->unk34;
    r->unk10 = ee;
    e->unk34 = r;
    register Q1B43* q asm("$6") = r->unk8;
    register s32 j asm("$7") = 0;
    if (n > 0) {
        do {
            register s32 j1 asm("$9") = j + 1;
            register s32 cnt2 asm("$5") = s->unk1C;
            register s32 want asm("$7") = q->unk8;
            register s32 k asm("$4") = 0;
            register D1B43* d asm("$3") = s->unk20;
            for (; k < cnt2; k++, d++) {
                if (d->unk4 == want) {
                    break;
                }
            }
            q->unk8 = (s32)d;
            j = j1;
            q = q + 1;
        } while (j < n);
    }
    s->unk28 += n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4468);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B46B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B46C0);

extern "C" void func_001B47B8(s32 a) {
    s32 n = D_00373288;
    s32 m = D_00373298;
    u32* q = D_003732E0;
    q[0] = (a << 15) | n | q[0];
    n = n * m;
    q[3] = n;
    D_00373284 += n + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4808);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4828);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B48D8);

extern "C" s32 func_001B49A0(S001B49A0* p) {
    s32 v = p->unk6;
    return v & 1;
}

extern "C" void func_001B49B0(S001B49A0* p, s32 v) {
    p->unkC += v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B49C0);

extern "C" void func_001B4A88(s32 v) {
    D_0036CA4C = v;
}

extern "C" s32 func_001B4A90(void) {
    return D_0036CA4C;
}

struct N1B4A {
    N1B4A* unk0;
    char pad4[8];
    u32 unkC;
    s32 unk10;
    s32 unk14;
    char pad18[0x18];
    s16 unk30;
    s16 unk32;
    char pad34[8];
    s32 unk3C;
    char* unk40;
};

struct M1B4A {
    char pad0[0x2C];
    u32 unk2C;
};

extern "C" {
M1B4A* func_0015D2E8(u32, s32);
void func_001A9DA8(char*, void*, u64, u64, u64);
extern N1B4A* D_00373300;
extern s32 D_00373340;
extern char D_0038C9A0[];
}

extern "C" void func_001B4A98(u32 a0, u32 a1) {
    u32 k = a1;
    switch (a1) {
    case 0x8BB6EEE0:
        k = 0x70ACD9BB;
        break;
    case 0xCC169430:
        k = 0x370CA36B;
        break;
    case 0xF176BD80:
        k = 0x0A6C8ADB;
        break;
    case 0x43566190:
        k = 0xB84C56CB;
        break;
    case 0x7E364820:
        k = 0x852C7F7B;
        break;
    case 0x399632F0:
        k = 0xC28C05AB;
        break;
    case 0x04F61B40:
        k = 0xFFEC2C1B;
        break;
    case 0x86A68C91:
        k = 0x7DBCBBCA;
        break;
    }
    u32 k2 = 0;
    switch (k) {
    case 0x70ACD9BB:
        k2 = 0x852C7F7B;
        break;
    case 0x370CA36B:
        k2 = 0xC28C05AB;
        break;
    case 0x0A6C8ADB:
        k2 = 0xFFEC2C1B;
        break;
    case 0xB84C56CB:
        k2 = 0x7DBCBBCA;
        break;
    }
    N1B4A* n = D_00373300;
    if (n) {
        do {
            s32 i;
            for (i = 0; i < n->unk3C; i++) {
                u32 e = *(u32*)(n->unk40 + (i << 6));
                if (e == k || e == k2) {
                    n->unk32 = 0x4000;
                    u32 v = 0;
                    n->unk14 = 0;
                    n->unkC |= 0xC0;
                    n->unk10 = 0;
                    n->unk30 = 0;
                    D_00373340 = 0;
                    switch (a0) {
                    case 0xC50D1E72:
                        v = 0x2FC0;
                        break;
                    case 0x2463DADF:
                        v = 0x2BC0;
                        break;
                    case 0x5802FF04:
                        v = 0x2DC0;
                        break;
                    case 0xA0C0B4B2:
                        v = 0x31C0;
                        break;
                    case 0x3DCF55C4:
                        v = 0x33C0;
                        break;
                    case 0x41AE701F:
                        v = 0x35C0;
                        break;
                    case 0xDCA19169:
                        v = 0x37C0;
                        break;
                    case 0x8A35259F:
                        v = 0x39C0;
                        break;
                    }
                    M1B4A* m = func_0015D2E8(a0, 1);
                    u64 w = v & 0x3FFF;
                    if (m) m->unk2C |= 0x80000;
                    u64 t = ((w | 0x8000) | (w << 20)) | ((w << 40) | ((u64)0x8000 << 20)) | ((u64)0x8000 << 40);
                    func_001A9DA8(D_0038C9A0, n, (w | 0x1C008000) | ((u64)0xC000 << 19), t, t);
                }
            }
            n = n->unk0;
        } while (n);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4E70);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5240);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B58A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B58B0);

extern "C" void func_001B5BD0(void) {
    func_001B58B0(D_0037329C);
}

extern "C" void func_001B5BF8(void) {
    func_001B58B0(D_00373338);
}

extern "C" void func_001B5C20(void) {
    s32 x = D_0037329C;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

extern "C" void func_001B5C50(void) {
    s32 x = D_00373338;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

extern "C" void func_001B5C80(void) {
    s32 x = D_00373324;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

GP_DATA(D_0036CA50);
INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5DD8);
