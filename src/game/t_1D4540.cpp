#include "common.h"

struct S1D5000 {
    s32 unk0;
    f32 unk4;
    u8 unk8;
    char pad9[3];
    s32 unkC;
    s32 unk10;
};

struct S1D5348 {
    char pad0[0x164];
    S1D5000 unk164;
};

struct S1D5848 {
    s32 unk0;
    s32 unk4;
};

struct S1D5858 {
    char pad0[0x160];
    s32 unk160;
};

struct S1D6450 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

struct S1D5570 {
    void* unk0;
    s32 unk4;
};

struct S1D55D8 {
    char pad0[0xC];
    s32 unkC;
};

struct S1D4AA0 {
    char pad0[0x20];
    void* unk20;
};

struct S1D54A0 {
    char pad0[0x154];
    s32 unk154;
};

struct S1D5800_B {
    char pad0[0x8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

struct S1D5800 : S1D5800_B {
    s32 unkC;
    bool Test(s32 m) { return (unkC & m) != 0; }
    char pad10[0x150];
    s32 unk160;
};

struct S1D4600_E {
    s32 unk0;
    s32 (*unk4)(void);
};

struct S1D4600 {
    char pad0[0x50];
    u32 unk50;
    S1D4600_E unk54[1];
};

struct S1D5870 {
    void* unk0;
    void* unk4;
};

struct S1D4BB0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    S1D4BB0* unk14;
};

struct S1D51F8 {
    char pad0[0x40];
    u32 unk40;
};

struct S1D45A0 {
    char pad0[0x24];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

struct S1D52E8 {
    char pad0[0x8];
    void* unk8;
    char padC[0x44];
    s32 unk50;
};

extern "C" {
void func_001D7F68(void* p, void* q);
void func_001D8058(void* p, void* q);
void func_001D8150(void* p);
void func_001D46A8(void* p);
extern char D_0034BD58[];
extern char D_0034BD38[];
void func_001D1B28(void* p);
s32 func_001D51F8(S1D5000* p);
void* func_001D5BA0(void* p, u32 key, void* q);
s32 func_001D7710(void* p);
void func_001D59E8(void* p, s32 v);
void* func_00118F20(s32 heap, s32 size, s32 a, s32 b);
void* func_001D58E0(void* p);
extern u32 D_0036D414;
extern void* D_0036D410;
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void func_0027AC90(void* p);
void func_00113250(void* p);
void func_00119400(s32 heap, void* p);
extern char D_0034BBF0[];
extern S1D4BB0* D_0041A9B0[];
S1D51F8* func_001D7EE8(void* p);
void func_001D6AB0(void* p, void* q);
void func_001D11B0(void* p, s32 v);
void func_001D6840(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern char D_0034BD98[];
}

extern "C" void func_001D4540(void* p, void* q) {
    func_001D7F68(p, q);
}

extern "C" void func_001D4560(void* p, void* q) {
    func_001D7F68(p, q);
}

extern "C" void func_001D4580(void* p, void* q) {
    func_001D8058(p, q);
}

extern "C" void func_001D45A0(S1D45A0* p, S1D45A0* q, s32 v) {
    p->unk24 = v;
    p->unk28 = 1;
    func_001D8058(p, q);
    q->unk2C = v;
    func_001D7F68(p, q);
    p->unk28 = 0;
}

extern "C" void func_001D4600(S1D4600* p, s32 a, s32 (*b)(void), void (*fn)(void)) {
    (&p->unk54[0] + p->unk50)->unk0 = a;
    p->unk54[p->unk50].unk4 = b;
    p->unk50++;
    if (fn != 0) {
        fn();
    }
}

extern "C" s32 func_001D4650(S1D4600* p, s32 key) {
    for (u32 i = 0; i < p->unk50; i++) {
        S1D4600_E* e = &p->unk54[i];
        if (e->unk0 == key) {
            return e->unk4();
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D46A8);

extern "C" void func_001D48A0(void* p) {
    func_001D8150(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D48C0);

extern "C" void func_001D4AA0(S1D4AA0* p) {
    func_001D46A8(p->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4C08);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4CA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4CC8);

extern "C" void* func_001D4CF0(s32 create) {
    if (D_0036D410 == 0 && create != 0) {
        D_0036D410 = func_001D58E0(func_00118F20(D_00368A38[0], 0xC, 1, 0));
    }
    D_0036D414++;
    return D_0036D410;
}

extern "C" void func_001D4D48(void) {
    if (D_0036D414 >= 2) {
        D_0036D414--;
        return;
    }
    if (D_0036D410 != 0) {
        func_001D59E8(D_0036D410, 3);
    }
    D_0036D410 = 0;
    D_0036D414 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D4D90);

extern "C" S1D5000* func_001D5000(S1D5000* p) {
    p->unk0 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    return p;
}

extern "C" void func_001D5018(S1D5000* p, u8 v) {
    p->unk8 = v;
}

extern "C" void func_001D5020(S1D5000* p, s32 v) {
    p->unk0 = v;
}

extern "C" void func_001D5028(S1D5000* p, f32 v) {
    p->unk4 = v;
}

extern "C" void func_001D5030(S1D5000* p, s32 v) {
    p->unk10 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5038);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5138);

extern "C" s32 func_001D51F8(S1D5000* p) {
    return p->unk10 != 0 || p->unk8 < func_001D7EE8(D_0036D410)->unk40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5250);

extern "C" void func_001D52E8(S1D52E8* p, s32 v) {
    p->unk8 = D_0034BD98;
    func_001D6AB0(func_001D5BA0(D_0036D410, p->unk50, (void*)1), p);
    func_001D11B0(p, v);
}

extern "C" u8 func_001D5348(S1D5348* p) {
    return p->unk164.unk8;
}

extern "C" void func_001D5350(S1D5348* p, u8 v) {
    func_001D5018(&p->unk164, v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5370);

extern "C" void func_001D54A0(S1D54A0* p) {
    func_001D1B28(p);
    p->unk154 &= ~0x40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D54D8);

extern "C" S1D5570* func_001D5570(S1D5570* p, s32 v) {
    p->unk4 = v;
    p->unk0 = D_0034BD58;
    return p;
}

extern "C" s32 func_001D5588(S1D5848* p, S1D5348* q) {
    s32 r = func_001D51F8(&q->unk164);
    return ((p->unk4 & 1) ^ r) != 0;
}

extern "C" S1D5570* func_001D55C0(S1D5570* p, s32 v) {
    p->unk4 = v;
    p->unk0 = D_0034BD38;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D55D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D55F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5688);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5758);

extern "C" void func_001D57F0(void) {
}

extern "C" void func_001D57F8(void) {
}

extern "C" void func_001D5800(S1D5848* p, S1D5800* q) {
    s32 t = q->unk160;
    p->unk4 += t;
    if (!q->Test(1)) {
        q->v8();
    }
}

extern "C" void func_001D5848(S1D5848* p) {
    p->unk4++;
}

extern "C" void func_001D5858(S1D5848* p, S1D5858* q) {
    p->unk4 += q->unk160;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5870);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D58E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D59E8);

extern "C" s32 func_001D5B60(void* p, void* q) {
    void* r = func_001D5BA0(p, 0x69B05E2C, q);
    return r ? func_001D7710(r) : 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5BA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5C30);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5D28);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5EB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D5F60);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D6030);

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D62D0);

extern "C" void func_001D6450(S1D6450* p, s32 v) {
    p->unk60 -= v;
}

extern "C" void func_001D6460(S1D6450* p, s32 v) {
    p->unk60 += v;
    if (v < p->unk5C) {
        p->unk5C = v;
    }
}

extern "C" s32 func_001D6488(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D4540", func_001D6490);
