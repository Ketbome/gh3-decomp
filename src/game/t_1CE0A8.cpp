#include "common.h"

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, void*);
};

struct N8 {
    char pad0[0x4];
    N8* unk4;
    N8* unk8;
};

struct L4 {
    char pad0[0x4];
    N8* unk4;
    void* unk8;
};

struct E8 {
    s32 unk0;
    s32 unk4;
};

struct S001CE670 {
    u8 unk0;
    u8 unk1[0x33];
    u32 unk34;
};

struct S001CE0A8 {
    char pad0[0x8];
    VEnt* unk8;
    u32 unkC;
    char pad10[0x8];
    N8* unk18;
    char pad1C[0x4];
    s32 unk20;
    char pad24[0x4];
    void* unk28;
    s32 unk2C;
    char pad30[0x4];
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

extern "C" {
void func_001CF148(void* a, void* b, s32 c);
void func_001CFBC8(void* a, void* b, void* c, s32 d);
void func_001CF000(void);
void func_0028D7D8(void);
void func_0028A5A0(void* a, void* b);
void func_0027AE70(void* p);
s32 func_0027D1F8(void* p, s32 key, void* v, s32 req);
s32 func_0027D870(void* p, s32 key, void* v, s32 req);
s32 func_0027DF00(void* p);
void func_0027ABB0(void* a, void* b);
void func_001CEBE0(S001CE0A8* p);
void func_0027C448(s32 a, u32 key, s32 b);
void func_001D0798(N8* n);
extern char D_0034B4F0[];
extern E8 D_0032C320[];
void func_001CE7A0(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE0A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE1D0);

extern "C" void func_001CE218(S001CE0A8* p, u32 m) {
    p->unk34 &= ~m;
    p->unk38 &= ~m;
    p->unk3C &= ~m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE248);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE410);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE4C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE5A0);

extern "C" void func_001CE670(S001CE670* p) {
    s32 i;

    for (i = 0; D_0032C320[i].unk0 > 0; i++) {
        if (p->unk34 & D_0032C320[i].unk0) {
            p->unk1[D_0032C320[i].unk4] = 0xFF;
        } else {
            p->unk1[D_0032C320[i].unk4] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE730);

extern "C" void func_001CE778(void) {
    func_001CE7A0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE798);

extern "C" void func_001CE7A0(void) {
}

extern "C" L4* func_001CE7A8(L4* p) {
    p->unk4 = 0;
    p->unk8 = D_0034B4F0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE7C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE810);

extern "C" void func_001CE868(L4* l, N8* n) {
    n->unk8 = l->unk4;
    if (l->unk4 != 0) {
        l->unk4->unk4 = n;
    }
    l->unk4 = n;
}

extern "C" void func_001CE888(L4* l, N8* n) {
    if (n->unk4 != 0) {
        n->unk4->unk8 = n->unk8;
    } else {
        l->unk4 = n->unk8;
    }
    if (n->unk8 != 0) {
        n->unk8->unk4 = n->unk4;
    }
    n->unk4 = 0;
    n->unk8 = 0;
}

extern "C" L4* func_001CE8C0(L4* p) {
    p->unk4 = 0;
    p->unk8 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CE990);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEAD0);

extern "C" void func_001CEB48(S001CE0A8* p, N8* key) {
    N8* prev = 0;
    N8* n;

    for (n = p->unk18; n != 0; n = n->unk8) {
        if (n->unk4 == key) {
            break;
        }
        prev = n;
    }
    if (n != 0) {
        if (prev != 0) {
            prev->unk8 = n->unk8;
        } else {
            p->unk18 = n->unk8;
        }
        func_001D0798(n);
    }
}

extern "C" void func_001CEBA8(S001CE0A8* p) {
    if (((s32)p->unkC >> 1) & 1) {
        return;
    }
    func_001CEBE0(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEBE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CED18);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CED20);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CED98);

extern "C" void func_001CEDE0(S001CE0A8* p, s32 v) {
    p->unk20 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEDE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEE38);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEE88);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEED8);

extern "C" void func_001CEF30(S001CE0A8* p) {
    if (p->unk28 != 0) {
        func_0027AE70(p->unk28);
    }
}

extern "C" s32 func_001CEF58(S001CE0A8* p, s32 key, void* v) {
    if (p->unk28 != 0) {
        return func_0027D1F8(p->unk28, key, v, 0);
    }
    return 0;
}

extern "C" s32 func_001CEF80(S001CE0A8* p, s32 key, void* v) {
    if (p->unk28 != 0) {
        return func_0027D870(p->unk28, key, v, 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CEFA8);

extern "C" s32 func_001CEFD8(S001CE0A8* p) {
    if (p->unk28 != 0) {
        return func_0027DF00(p->unk28);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF000);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF040);

extern "C" void func_001CF120(S001CE0A8* p, void* a) {
    if (p->unk28 != 0) {
        func_0027ABB0(a, p->unk28);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF148);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF218);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF470);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF538);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF640);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF6A8);

extern "C" void func_001CF748(void* a, void* b, S001CE0A8* c) {
    func_001CF148(a, b, c->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF768);

extern "C" int func_001CF7B8(void) {
    func_001CF000();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF7D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF898);

extern "C" int func_001CF8E8(void* a, void* b, void* c) {
    func_0028A5A0(c, a);
    return 1;
}

extern "C" int func_001CF910(S001CE0A8* a, void* b, S001CE0A8* c) {
    s32 v = a->unk2C;

    func_0027C448(c->unk20, 0x0830ECAF /* objid */, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF940);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CF980);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFA08);

extern "C" int func_001CFA50(void) {
    func_0028D7D8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFA70);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFB18);

extern "C" void func_001CFB88(void* a, void* b, void* c) {
    func_001CFBC8(a, b, c, 1);
}

extern "C" void func_001CFBA8(void* a, void* b, void* c) {
    func_001CFBC8(a, b, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFBC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFD00);

extern "C" int func_001CFD78(S001CE0A8* p) {
    p->unkC &= ~4;
    return 1;
}

extern "C" int func_001CFD98(S001CE0A8* p) {
    p->unkC |= 4;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFE38);

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFEB8);

extern "C" int func_001CFF58(S001CE0A8* p, u32 key, void* a) {
    switch (key) {
    case 0xC6870028 /* Die */:
        ((void (*)(void*))p->unk8[8].fn)((char*)p + p->unk8[8].delta);
        break;
    case 0x6C63C7C5 /* SetProps */:
        p->unk8[2].fn((char*)p + p->unk8[2].delta, a);
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CE0A8", func_001CFFC8);
