#include "common.h"

struct S1D7C28 {
    void* unk0;
};

struct S1D7EE8_N {
    char pad0[0x8];
    void* unk8;
};

struct S1D7EE8_I {
    s32 unk0;
    S1D7EE8_N* unk4;
};

struct S1D7EE8 {
    char pad0[0x8];
    S1D7EE8_N* unk8;
};

struct S1D7F00 {
    char pad0[0x20];
    void* unk20;
};

struct S1D8150_Q {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x18];
    s32 unk2C;
    char pad30[0x10];
    s32 unk40;
};

struct S1D80D8 {
    char pad0[0x20];
    u32 unk20;
    s32 unk24;
    s32 unk28;
    virtual void v1();
    virtual void v2(S1D8150_Q* q);
    virtual void v3(S1D8150_Q* q);
    virtual void v4(S1D8150_Q* q, s32 v);
};

struct S1D8058_N {
    char pad0[0xC];
    S1D8058_N* unkC;
    S1D8058_N* unk10;
};

extern "C" char D_0034BFF0[];

struct S1D7F20_N {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    S1D7F20_N* unkC;
    S1D7F20_N* unk10;
    void* unk14;
    void Init() {
        unk4 = 0xFFFFFFFF;
        unk8 = 0;
        unkC = this;
        unk10 = this;
        unk14 = D_0034BFF0;
    }
};

struct S1D7F20 {
    char pad0[0x4];
    S1D7F20_N unk4;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    void* unk2C;
};

struct S1D67C8 {
    char pad0[0x2C];
    u32 unk2C;
    char pad30[0xC];
    u32 unk3C;
};

struct S1D67C8_R {
    char pad0[0x9C];
    s32 unk9C;
};

struct S1D67C8_Q {
    char pad0[0x160];
    u32 unk160;
};

extern "C" {
void func_00119400(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void* func_001D8180(void* p);
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BD78[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BCD8[];
extern char D_0034BFA8[];
extern char D_0034BFF0[];
extern s32 D_0036D554[] __attribute__((section(".sdata")));
void func_001DA368(s32 a, void* q, s32 b, s32 c);
u32 func_0011C030(void* p);
void func_001194B8(s32 heap, u32 v);
s32 func_001D7710(S1D80D8* p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6598);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6730);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6738);

extern "C" void func_001D67C8(S1D67C8* p, S1D67C8_Q* q) {
    func_001D7710((S1D80D8*)p);
    ((S1D67C8_R*)func_001D7710((S1D80D8*)p))->unk9C = 1;
    u32 t = func_0011C030((void*)func_001D7710((S1D80D8*)p));
    u32 d = p->unk2C;
    s32 h = D_00368A38[0];
    q->unk160 = (p->unk3C - t) / d;
    func_001194B8(h, d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6840);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D69D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6AB0);

extern "C" void func_001D6BA0(void) {
}

extern "C" void func_001D6BA8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D6BB8);

extern "C" s32 func_001D7710(S1D80D8* p) {
    return p->unk24;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7718);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7800);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7988);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7BD0);

extern "C" void func_001D7C28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7C68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7CA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7CE8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BD78;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7D28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7D68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7DA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7DE8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7E28(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7E68(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void func_001D7EA8(S1D7C28* p, s32 flags) {
    p->unk0 = D_0034BCD8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

extern "C" void* func_001D7EE8(S1D7EE8* p) {
    S1D7EE8_I it;
    it.unk4 = p->unk8;
    return it.unk4->unk8;
}

extern "C" void* func_001D7F00(S1D7F00* p) {
    return func_001D8180(p->unk20);
}

extern "C" S1D7F20* func_001D7F20(S1D7F20* p) {
    p->unk2C = D_0034BFA8;
    p->unk4.Init();
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk28 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D7F68);

extern "C" void func_001D8058(S1D80D8* p, S1D8150_Q* q) {
    func_001DA368(D_0036D554[0], q, p->unk24, p->unk28);
    S1D8058_N* n = (S1D8058_N*)((char*)q + 0x38);
    if (n->unk10 != n) {
        n->unk10->unkC = n->unkC;
        n->unkC->unk10 = n->unk10;
        n->unkC = n;
        n->unk10 = n;
        q->unk10 = 0;
        p->unk20 = 0xFFFFFFFF;
    }
}

extern "C" void func_001D80D8(S1D80D8* p, S1D8150_Q* q, s32 v) {
    p->unk28 = 1;
    p->unk24 = v;
    p->v3(q);
    q->unk2C = v;
    p->v2(q);
    p->unk28 = 0;
}

extern "C" void func_001D8150(S1D80D8* p, S1D8150_Q* q, s32 v) {
    q->unk40 = v;
    p->v4(q, q->unk2C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D8180);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D8208);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D82D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D6598", func_001D83D0);
