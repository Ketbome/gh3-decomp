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
void *func_001D1CF8(void *, u32);
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
int func_0027D870(int, u32, int *, int);
void func_00289608(void *, int);
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

struct S28AB_VEnt {
    s16 delta;
    s16 unk2;
    int (*fn)(void *, void *, int, int);
};

struct S28AB_Comp {
    char pad0[0x18];
    S28AB_VEnt *vt;
};

struct S28AB_Tgt {
    char pad0[8];
    S28AB_VEnt *vt;
    char pad0C[0x48];
    int unk54;
};

struct S28AB_Msg {
    char pad0[4];
    u32 unk4;
};

extern "C" int func_0028ABB0(S28AB_Msg *msg, int a, S28AB_Tgt *obj, int b) {
    int r;
    S28AB_Ctx *c = D_0036F658;
    int pv = obj->unk54;
    c->unk18++;
    *(int *)(c->unk18 * 4 + (int)c + 0x1C) = pv;
    u32 id = msg->unk4;
    if (id == 0x57525413) {
        r = obj->vt[5].fn((char *)obj + obj->vt[5].delta, msg, a, b);
    } else if (id == 0x0ADA4E74) {
        r = obj->vt[5].fn((char *)obj + obj->vt[5].delta, msg, a, b);
    } else {
        S28AB_Comp *k = (S28AB_Comp *)func_001D1CF8(obj, id);
        r = k->vt[13].fn((char *)k + k->vt[13].delta, msg, a, b);
    }
    c->Pop();
    return r != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028ACA8);

INCLUDE_ASM("asm/nonmatchings/game/t_28AB28", func_0028AD40);

extern "C" void func_0028ADE8(S28AB_Scr *p, void (*fn)(int, S28AB_Scr *)) {
    if (p->unk1C) {
        fn(p->unk1C, p);
    } else {
        fn(p->unk18, p);
    }
}

extern "C" int func_0028AE28(S28AB_Scr *p) {
    int out = 0;
    u8 *s = p->unk14;
    switch (*s) {
    case 0x2C:
        p->unk14 = s + 1;
        func_0027D870(p->unk20, 0, &out, 0);
        break;
    case 0x2D: {
        u8 *q = s + 2;
        p->unk14 = q;
        int v = s[2] | (q[1] << 8) | (q[2] << 16) | (q[3] << 24);
        p->unk14 = s + 6;
        func_0027D870(p->unk20, v, &out, 0);
        break;
    }
    case 0x16: {
        u8 *q = s + 1;
        p->unk14 = q;
        out = s[1] | (q[1] << 8) | (q[2] << 16) | (q[3] << 24);
        p->unk14 = s + 5;
        break;
    }
    }
    return out;
}

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

struct S28BC_E {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct S28BC_I {
    char pad0[0x10];
    char *unk10;
    char pad14[0x1C];
};

struct S28BC_O {
    char pad0[0x14];
    int unk14;
    char pad18[0xC];
    S28BC_E *unk24;
    S28BC_E unk28;
    S28BC_E *unk3C;
    int unk40;
    char pad44[0x60];
    S28BC_I *unkA4;
};

extern "C" {
extern int D_00368A38;
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
void *func_0011A380(int);
}

extern "C" void func_0028BC70(S28BC_O *o) {
    o->unk14 = o->unk14 + 1;
    if (o->unk24 == &o->unk28) {
        int h = D_00368A38;
        func_00119490(h, func_00119610(h, 5));
        o->unk3C = (S28BC_E *)func_0011A380(0xC8);
        func_001194B8(D_00368A38);
        *o->unk3C = o->unk28;
        o->unk24 = o->unk3C;
        for (int i = 0; i < o->unk40; i++) {
            S28BC_I *it = (S28BC_I *)((char *)o->unkA4 + i * 0x30);
            if (it->unk10) {
                it->unk10 = (char *)o->unk3C + (it->unk10 - 0x28 - (char *)o);
            }
        }
    }
    S28BC_E *p = o->unk24;
    if (p) {
        p = p + 1;
    } else {
        p = o->unk3C;
    }
    o->unk24 = p;
    o->unk24->unk0 = o->unk14;
    o->unk24->unk4 = 0;
    o->unk24->unk8 = 0;
    o->unk24->unkC = 1;
    o->unk24->unk10 = 0;
}

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

extern "C" void func_0028C4B0(char *p, u32 v, int b) {
    func_00288B88(p + 0xA8, (f32)v * 0.001f, b);
}

extern "C" void func_0028C518(char *p, u32 v) {
    func_00288C90(p + 0xA8, (f32)v);
}

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

struct S28C_H {
    int unk0;
    int key;
    int unk8;
    int unkC;
    S28C_H *next;
};

struct S28C_E {
    int id;
    char pad[0x2C];
};

struct S28C_O {
    char pad0[0x10];
    int unk10;
    char pad14[0x2C];
    int unk40;
    char pad44[0x60];
    S28C_E *unkA4;
    char padA8[0x2C];
    int unkD4;
};

extern "C" S28C_H **D_003710A4;

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

struct S0028C848 {
    char pad[0x40];
    int unk40;
    char pad1[0x60];
    char* unkA4;
};

extern "C" void func_0028C848(S0028C848* p, int b) {
    func_00289608((char*)p + 0xA8, b);
    for (int i = 0; i < p->unk40; i++) func_00289608(p->unkA4 + i * 0x30 + 0x1C, b);
}

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
