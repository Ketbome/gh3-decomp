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
extern S001BD998* D_0036CB74;
void func_001BB068(void);
void func_0019E380(s32 a, s32 b, s32 c, s32 d, s32 e);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
void func_001BF298(S001BF1D0* p);
void func_001BF2B8(S001BF1D0* p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD608);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD780);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BD8E8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDA28);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDB28);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDC30);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDD90);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDE38);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BDF08);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE088);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE3A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE498);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BE558);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF0B8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF358);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF4A0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF568);

INCLUDE_ASM("asm/nonmatchings/game/t_1BD608", func_001BF5C0);

extern "C" void func_001BF5F8(u64* p, u16 a, u16 b, u16 c, s32 d) {
    *p = (u64)a | ((u64)c << 16) | ((u64)b << 32) | ((u64)d << 48);
}
