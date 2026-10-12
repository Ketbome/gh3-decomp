// cflags: -funroll-loops
#include "common.h"

struct S0028C1E0 {
    char pad[0xB8];
    u8 unkB8;
};

struct S0028C8D0_2 {
    int unk0;
};

struct S0028C8D0 {
    char pad[0x40];
    int unk40;
    char pad1[0x60];
    S0028C8D0_2* unkA4;
    char pad2[0x2C];
    int unkD4;
};

struct S0028AB28 {
    char pad[0x14];
    u8* unk14;
};

struct S0028B8C0 {
    char pad[0x14];
    u8* unk14;
};

struct S28AB_Scr {
    char pad0[0x14];
    u8 *unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[0x94];
    int unkB8;
    u8 *unkBC;
};

struct S28AB_Ctx {
    char pad0[0x18];
    int unk18;
    int unk1C[1];
    void Push(int v) {
        unk18++;
        unk1C[unk18] = v;
    }
    void Pop() { unk18--; }
};

struct S28AB_ObjBase {
    char pad0[0x8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int, int);
};

struct S28AB_Obj : S28AB_ObjBase {
    char padC[0x48];
    int unk54;
};

struct S28AB_Scr2 {
    char pad0[0x14];
    u8 *unk14;
    int unk18;
    int unk1C;
    char pad20[0x98];
    u32 lo : 9;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 hi : 21;
    u8 *unkBC;
    bool B10() { return (*(u32 *)((char *)this + 0xB8) >> 10) & 1; }
};

struct S28AB_Scr3 {
    char pad0[0x14];
    u8 *unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    char pad28[0x14];
    int unk3C;
};

struct S28AB_Ent {
    int unk0;
    char pad4[0x8];
    int unkC;
    char pad10[0x20];
};

struct S28AB_Tab {
    char pad0[0x40];
    int unk40;
    char pad44[0x60];
    S28AB_Ent *unkA4;
    char padA8[0x20];
    int unkC8;
    char padCC[0x8];
    int unkD4;
};

extern "C" {
extern S28AB_Ctx *D_0036F658;
extern int D_00372580;
void func_001C8258(int);
int func_0028ABB0(int, int);
u8 *func_00283A08(u8 *);
void func_0028B840(S28AB_Scr *);
u8 *func_002870C0(int, u8 *, int, int *);
void func_00288C90(void *, f32);
void func_00288B88(void *, f32, int);
int func_0028C590(S28AB_Tab *, int);
void func_0028C9F0(void);
int func_00288C48(void*);
int func_00288C00(void*);
int func_00289630(void*, void*);
}

extern "C" int func_0028AB28(S0028AB28* p) {
    if (p->unk14 == 0) {
        return 1;
    }
    return *p->unk14 == 0x24;
}

extern "C" void func_0028AB50(char* a) {
    func_00289630(a + 0xA8, a);
}

extern "C" void func_0028AB70(S28AB_Scr *p) {
    p->unk1C = 0;
    p->unk14 = func_002870C0(p->unk18, p->unk14, p->unk20, &p->unk1C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ABB0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ACA8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AD40);

extern "C" void func_0028ADE8(S28AB_Scr *p, void (*fn)(int, S28AB_Scr *)) {
    if (p->unk1C) {
        fn(p->unk1C, p);
    } else {
        fn(p->unk18, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AE28);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AF38);

extern "C" void func_0028B738(S28AB_Scr2 *p, int b) {
    if (p->B10()) {
        if (b) {
            b = 0;
        } else {
            b = 1;
        }
    }
    if (!b) {
        u8 *s = p->unkBC;
        p->unk14 = s;
        if (*s == 0x27) {
            p->unkBC = 0;
            p->b9 = 0;
            p->b10 = 0;
            func_0028B840((S28AB_Scr *)p);
            return;
        }
    }
    p->unkBC = 0;
    p->b9 = 0;
    p->b10 = 0;
}

extern "C" void func_0028B7D0(S28AB_Scr *p) {
    u8 *s = p->unk14;
    u8 *n = s + 1;
    p->unk14 = n;
    p->unkB8 |= 0x200;
    int off = s[1] | (n[1] << 8);
    p->unk14 = s + 3;
    p->unkB8 &= ~0x400;
    p->unkBC = n + off;
    if (n[2] == 0x39) {
        p->unk14 = s + 4;
        p->unkB8 |= 0x400;
    }
}

extern "C" void func_0028B840(S28AB_Scr *p) {
    u8 *s = p->unk14;
    u8 *n = s + 1;
    p->unk14 = n;
    p->unkB8 |= 0x200;
    u32 off = s[1] | (n[1] << 8);
    if (off < 4) {
        p->unk14 = s;
    }
    u8 *q = p->unk14;
    p->unkBC = q + off;
    p->unk14 = q + 4;
    p->unkB8 &= ~0x400;
    if (q[4] == 0x39) {
        p->unk14 = q + 5;
        p->unkB8 |= 0x400;
    }
}

extern "C" void func_0028B8C0(S0028B8C0* p) {
    u8* s = p->unk14;
    u8* n = s + 1;
    p->unk14 = n;
    p->unk14 = n + (s[1] | (n[1] << 8));
}

extern "C" void func_0028B8E8(S0028B8C0* p) {
    u8* s = p->unk14;
    u8* n = s + 3;
    p->unk14 = n;
    p->unk14 = n + (s[3] | (n[1] << 8));
}

extern "C" void func_0028B910(S28AB_Scr *p) {
    while (*p->unk14 != 0x3D) {
        if (*p->unk14 == 0x3C) {
            p->unk14++;
            func_0028B910(p);
        } else {
            p->unk14 = func_00283A08(p->unk14);
        }
    }
    p->unk14++;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028B9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BC70);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BDA8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BE80);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028BF48);

extern "C" void func_0028C1E0(S0028C1E0* p) {
    p->unkB8++;
}

extern "C" void func_0028C1F0(S0028C1E0* p) {
    p->unkB8--;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C200);

extern "C" void func_0028C470(char* a) {
    func_00288C48(a + 0xA8);
}

extern "C" void func_0028C490(char* a) {
    func_00288C00(a + 0xA8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C518);

extern "C" int func_0028C570(S28AB_Tab *p, int v) {
    return func_0028C590(p, v);
}

extern "C" int func_0028C590(S28AB_Tab *p, int v) {
    if (p->unkD4 == v) {
        return 1;
    }
    for (int i = 0; i < p->unk40; i++) {
        if (p->unkA4[i].unk0 == v) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C658);

extern "C" int func_0028C770(S28AB_Tab *p, int v) {
    if (p->unkC8 == v) {
        return 1;
    }
    for (int i = 0; i < p->unk40; i++) {
        if (p->unkA4[i].unkC == v) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C840);

extern "C" int func_0028C8D0(S0028C8D0* p) {
    if (p->unk40 != 0) {
        return p->unkA4->unk0;
    }
    return p->unkD4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C8F0);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C8F8);

extern "C" void func_0028C9D0(void) {
    func_0028C9F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028C9F0);
