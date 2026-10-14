#include "common.h"

struct S23A248 {
    s32* unk0;
    void* unk4;
    char pad8[4];
    s32 unkC;
    char pad10[4];
    void* unk14;
    char pad18[4];
    void* unk1C;
    void* unk20;
};

struct S238EE0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x10];
    s32 unk2C;
};

struct S238EE0_O {
    char pad0[4];
    u32 unk4;
    s32* unk8;
};

extern "C" {
void* Heap_Alloc(s32 h, s32 size, s32 a, s32 b);
S238EE0_O* func_002764E8(s32 a, s32 b);
s32 func_002378D8(void* a, s32* b, s32 c);
s32 func_001150B8(s32 a);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00238490);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00238890);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00238A38);

extern "C" void func_00238EE0(S238EE0* p, s32 a) {
    s32* arr = (s32*)Heap_Alloc(D_00368A38, p->unk18 * 4, 1, 0);
    s32 i;
    for (i = 0; i < p->unk18; i++) {
        arr[i] = i;
    }
    S238EE0_O* o = func_002764E8(a, 0);
    if (o != 0 && o->unk4 == p->unk18) {
        u32 u;
        s32* q = arr;
        for (u = 0; u < o->unk4; u++) {
            *q++ = o->unk4 == 1 ? (s32)o->unk8 : o->unk8[u];
        }
    }
    p->unk2C = func_002378D8(p, arr, 1);
    if (arr != 0) {
        Heap_Free(D_00368A38, arr);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00238FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00239000);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00239118);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00239128);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00239230);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_00239CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_0023A0C8);

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_0023A168);

extern "C" void func_0023A248(S23A248* p) {
    if (p->unk0) {
        for (s32 i = 0; i < p->unkC; i++) {
            if (p->unk0[i]) {
                Heap_Free(D_00368A38, (void*)p->unk0[i]);
            }
            p->unk0[i] = 0;
        }
        if (p->unk0) {
            Heap_Free(D_00368A38, p->unk0);
        }
        if (p->unk4) {
            Heap_Free(D_00368A38, p->unk4);
        }
        p->unk0 = 0;
        p->unk4 = 0;
    }
    if (p->unk14) {
        Heap_Free(D_00368A38, p->unk14);
        if (p->unk1C) {
            Heap_Free(D_00368A38, p->unk1C);
        }
        if (p->unk20) {
            Heap_Free(D_00368A38, p->unk20);
        }
        p->unk14 = 0;
        p->unk1C = 0;
        p->unk20 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_238490", func_0023A350);

extern "C" s32 func_0023A458(char* p0, s32 key0) {
    register s32 off asm("$17") = 0;
    char* p = p0;
    s32 i = 0;
    s32 r = 0;
    s32 key = key0;
    while (i < *(s32*)(p + 0xC)) {
        s32 cur = off;
        asm("" : "+r"(cur));
        if (func_001150B8(*(s32*)(p + 8) + off + 0xB0) == key) {
            r = *(s32*)(p + 8) + off;
            break;
        }
        off = cur + 0x13C;
        i++;
    }
    return r;
}
