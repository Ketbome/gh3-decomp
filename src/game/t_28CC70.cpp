#include "common.h"

asm(".set D_00368A38_lui, D_00368A38");


struct S28C_Ent {
    char pad0[0x14];
    int unk14;
    void *unk18;
    char pad1C[0x30 - 0x1C];
};

struct S28C_Obj {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x20 - 0xC];
    int unk20;
    char pad24[0x2C - 0x24];
    int unk2C;
    char pad30[0x40 - 0x30];
    int unk40;
    char pad44[0xA4 - 0x44];
    S28C_Ent *unkA4;
    char padA8[0xB4 - 0xA8];
    int unkB4;
    int unkB8;
    char padBC[0xC4 - 0xBC];
    int unkC4;
    char padC8[0xD8 - 0xC8];
    int unkD8;
    int unkDC;
    int unkE0;
    char padE4[0xF0 - 0xE4];
    int unkF0;
    char padF4[4];
    int unkF8;
    void *unkFC;
    char pad100[0x144 - 0x100];
    int unk144;
    char pad148[0x1E8 - 0x148];
    int unk1E8;
    char pad1EC[0x1F4 - 0x1EC];
    int unk1F4;
};

struct S28C_Bits {
    u32 b0 : 1;
    u32 b1 : 1;
    bool B1() {
        return (*(u32 *)this >> 1) & 1;
    }
};

struct S28C_Args {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct S28C_Info {
    int unk0;
    int unk4;
    int unk8;
    u8 unkC;
};

struct S28C_Msg {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    void *unk4;
    int unk8;
    int unkC;
    u8 unk10;
    char pad11[0x3];
    int unk14;
    int unk18;
    int unk1C;
    u8 unk20;
};

struct S28C_Node {
    int unk0;
    S28C_Obj *unk4;
    S28C_Node *unk8;
};

struct S28C_List {
    char pad[0x18];
    S28C_Node *unk18;
};

struct S0028E210 {
    char pad[0xF4];
    int unkF4;
};

struct S0028E218 {
    char pad[0xF4];
    int unkF4;
};

struct S0028EB10 {
    char pad[0x1F0];
    int unk1F0;
};

struct S0028CF18 {
    char pad[0xD8];
    int unkD8;
};

extern "C" {
void func_001D8CD0(int, void *, int, int, int, int, int, int);
extern int D_00368A38;
extern int D_00368A38_lui[] asm("D_00368A38_lui") __attribute__((section(".sdata")));
extern int D_00372580[] __attribute__((section(".sdata")));
int func_00119610(int, int);
void func_00119490(int, int);
int func_00118F20(int, int, int, int);
int func_001D8BF0(int);
void func_001DA0C8(int, void *);
void func_001D9180(int, int, bool);
void func_001D9878(int);
void func_001DA028(int, void *);
void func_001194B8(int);
int func_001C8258(int);
S28C_Msg *func_00296AF0(S28C_Msg *);
int func_001CA020(int, int);
void func_0029D238(int, S28C_Msg *);
void func_0027AC90(void *);
void func_00113250(void *);
void func_0028AAC0(void *, int, void *);
void *func_0028D1D8(int, int, int, int, int, int, bool, bool, bool, int);
void func_00289ED8(void *, void *);

int func_0028C770(void *, int);
void *func_0012D028(int, int);
void *func_002899D8(void *);
void func_0028A2D0(void *, int, int, int);
void func_0028C200(void *);
int func_0028C200_i(void *) asm("func_0028C200");
void func_00289B40(void *, int);
void *func_002899B0(void *);
void func_0028A300(void *);
void func_0028A558(void *);
void func_0028C848(void *, int);
int func_0028C590(void *, int);
void func_001D9F40(int, void *, int);
void *func_001287F0(int, int);
void *func_0027AA70(void *);
void func_0027ABB0(void *, int);
void func_0028E9B0(void *);
void func_0028E610(void *);
void func_0028D578(void);
void func_0028D720(int);
void func_001150B8(void);
void func_0028DB50(S28C_List *, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CC70);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CCD8);

extern "C" void func_0028CCE8(int a, int b, int c, void *d) {
    S28C_Obj *o = (S28C_Obj *)func_002899D8(func_0012D028(0x10C, 1));
    func_0028A2D0(o, a, b, c);
    func_0028C200(o);
    if (o->unk20) {
        func_0027ABB0(d, o->unk20);
    }
    if (o) {
        func_00289B40(o, 3);
    }
}

extern "C" void func_0028CD90(void) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        S28C_Bits *f = (S28C_Bits *)&p->unkD8;
        if (f->b0) {
            if (!f->B1() && !*(u8 *)&p->unkB8) {
                func_0028A300(p);
            }
        }
        p = next;
    }
}

extern "C" void func_0028CE18(int v) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        if (p->unkD8 & 1) {
            p->unkD8 = (p->unkD8 & ~4) | ((v & 1) << 2);
        }
        p = (S28C_Obj *)func_002899B0(p);
    }
}

extern "C" void func_0028CE90(int a) {
    S28C_Obj *p;
    for (p = (S28C_Obj *)func_002899B0(0); p; p = (S28C_Obj *)func_002899B0(p)) {
        if ((p->unkD8 & 1) && func_0028C590(p, a)) {
            p->unkD8 &= ~4;
        }
    }
}

extern "C" void func_0028CF18(S0028CF18* p) {
    if (p != 0 && (p->unkD8 & 1)) {
        p->unkD8 &= ~4;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028CF40);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D090);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D098);

extern "C" S28C_Obj *func_0028D168(int key) {
    S28C_Obj *p = 0;
    while ((p = (S28C_Obj *)func_002899B0(p)) != 0) {
        if (p->unkB4 == key) {
            return p;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D1B0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D1D8);

extern "C" int func_0028D490(S28C_Args *p, S28C_Obj *q, int c) {
    int a0 = p->unk0;
    int a2 = p->unkC;
    int t0 = q->unkC4;
    int t1 = p->unk8;
    void *r = func_0028D1D8(a0, p->unk4, a2, p->unk10, t0, t1, p->unk14 != 0, p->unk18 != 0, p->unk1C != 0, 0);
    if (r) {
        if (!p->unk20) {
            func_00289ED8(r, q);
        }
        if (c) {
            if (!func_0028C200_i(r)) {
                func_00289B40(r, 3);
            }
        }
    }
    return 1;
}

extern "C" void func_0028D558(void) {
    func_0028D578();
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D578);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D660);

extern "C" void func_0028D668(int a) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if ((p->unkD8 & 1) && func_0028C590(p, a)) {
            func_0028A300(p);
            func_0028A558(p);
        }
        p = next;
    }
}

extern "C" void func_0028D700(int a) {
    func_0028D720(a);
}

extern "C" void func_0028D720(int key) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if (p->unkD8 & 1) {
            bool hit = p->unkE0 == key || p->unkB4 == key || p->unkDC == key;
            if (hit) {
                func_0028A300(p);
                func_0028A558(p);
            }
        }
        p = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D7D0);

extern "C" void func_0028D7D8(int a) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if ((p->unkD8 & 1) && func_0028C770(p, a)) {
            func_0028A300(p);
            func_0028A558(p);
        }
        p = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D870);

extern "C" void func_0028D878(int a, int b, S28C_Obj *c) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if ((p->unkD8 & 1) && p != c && func_0028C770(p, a) && p->unkE0 == b) {
            func_0028A300(p);
            func_0028A558(p);
        }
        p = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028D938);

extern "C" void func_0028D940(int a, int b, S28C_Obj *c) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if ((p->unkD8 & 1) && p != c && func_0028C770(p, a) && func_0028C590(p, b)) {
            func_0028A300(p);
            func_0028A558(p);
        }
        p = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DA08);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DA38);

extern "C" S28C_Obj *func_0028DA40(int key) {
    S28C_Obj *p = (S28C_Obj *)func_002899B0(0);
    while (p) {
        S28C_Obj *next = (S28C_Obj *)func_002899B0(p);
        if ((p->unkD8 & 1) && p->unkE0 == key) {
            return p;
        }
        p = next;
    }
    return 0;
}

extern "C" void func_0028DAB8(void) {
    func_001150B8();
}

extern "C" void func_0028DAD8(void) {
    S28C_Obj *p;
    for (p = (S28C_Obj *)func_002899B0(0); p; p = (S28C_Obj *)func_002899B0(p)) {
        func_0028A300(p);
        func_0028A558(p);
    }
}

extern "C" void func_0028DB28(S28C_List *a) {
    func_0028DB50(a, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DB48);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DB50);

extern "C" void func_0028DBD0(int a) {
    S28C_Obj *p;
    for (p = (S28C_Obj *)func_002899B0(0); p; p = (S28C_Obj *)func_002899B0(p)) {
        func_0028C848(p, a);
    }
}

extern "C" void func_0028DC28(void) {
}

extern "C" void func_0028DC30(S28C_Obj *p, int a, int b) {
    int h = D_00368A38_lui[0];
    func_00119490(h, func_00119610(h, 0x3A));
    if (p->unkF0 == 0) {
        p->unkF0 = func_001D8BF0(func_00118F20(D_00368A38_lui[0], 0x14, 1, 0));
    } else {
        func_001DA0C8(p->unkF0, p);
    }
    func_001D9180(p->unkF0, a, b != 0);
    func_001D9878(p->unkF0);
    func_001DA028(p->unkF0, p);
    func_001194B8(D_00368A38);
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DDE8);

extern "C" void func_0028DE38(S28C_Obj *p, int a) {
    if (p->unkF0) {
        func_001D9F40(p->unkF0, p, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028DE68);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E008);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E010);

extern "C" void func_0028E210(S0028E210* p, int v) {
    p->unkF4 = v;
}

extern "C" int func_0028E218(S0028E218* p) {
    return p->unkF4;
}

extern "C" void func_0028E220(S28C_Obj *p, int a, int b) {
    p->unkF8 = a;
    if (b) {
        void *r = func_0027AA70(func_001287F0(8, 1));
        p->unkFC = r;
        func_0027ABB0(r, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E278);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E610);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E858);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E8A0);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028E9B0);

extern "C" void func_0028EAC0(S28C_Obj *p) {
    if (p->unk144 || (p->unk4 & 0xFE00) || p->unk1E8 || p->unk1F4) {
        func_0028E9B0(p);
    }
}

extern "C" void func_0028EB10(S0028EB10* p, int v) {
    p->unk1F0 = v;
}

extern "C" void func_0028EB18(S28C_Obj *p, int a) {
    func_0028E9B0(p);
    p->unk1F4 = a;
}

extern "C" int func_0028EB50(S28C_Obj *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0x200) {
        return p->unk8;
    }
    if (t == 0x400) {
        return *(float *)&p->unk8 != 0.0f;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_28CC70", func_0028EBA0);
