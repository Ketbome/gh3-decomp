// cflags: -funroll-loops
#include "common.h"

struct S002D5B48 {
    char pad0[4];
    void *unk4;
    char pad8[0xE];
    u8 unk16;
};

struct S27E358_N {
    char pad0[8];
    S27E358_N *unk8;
};
struct S27E358 {
    u32 unk0;
    S27E358_N *unk4;
    int unk8;
};

extern "C" {
void func_0011C408(int, void *);
extern int D_00368A38;
void Heap_Free(int, void *);
void func_002D5A90_v(void) asm("func_002D5A90");
void func_002D5A90(S27E358 *);
}
struct S2D4468_A {
    int unk0;
    int unk4;
    int unk8;
};


struct S2D5878_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_select_guitar_build_finish_array);

extern "C" int func_002D4B38(int k, int *keys, int *vals, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (k == keys[i]) {
            return vals[i];
        }
    }
    return 0x0C3AA5D7;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_store_prune_guitar_finishes);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", CFunc_SetPS2DOFZ);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5868);

extern "C" void func_002D5878(S2D5878_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

extern "C" S2D5878_0 *func_002D5888(S2D5878_0 *self) {
    func_002D5878(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D58B0);

extern "C" void func_002D5A90(S27E358 *p) {
    char *h = (char *)p->unk4;
    char *n;
    if (h) {
        u32 cnt;
        u32 i;
        n = h;
        cnt = 1 << p->unk0;
        for (i = 0; i < cnt; i++) {
            S27E358_N *m = ((S27E358_N *)n)->unk8;
            while (m) {
                S27E358_N *k = m;
                m = m->unk8;
                func_0011C408(0, k);
            }
            func_002D5878((S2D5878_0 *)n);
            n += 0xC;
        }
        p->unk8 = 0;
    }
}

extern "C" void func_002D5B48(S002D5B48 *p, int b) {
    if (p->unk16 == 0) {
        if (p->unk4) {
            func_002D5A90_v();
            if (p->unk4) {
                Heap_Free(D_00368A38, p->unk4);
            }
            p->unk4 = 0;
        }
    }
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_002D5BC0(S2D4468_A *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" void func_002D5BD0(S27E358 *p) {
    char *h = (char *)p->unk4;
    char *n;
    if (h) {
        u32 cnt;
        u32 i;
        n = h;
        cnt = 1 << p->unk0;
        for (i = 0; i < cnt; i++) {
            S27E358_N *m = ((S27E358_N *)n)->unk8;
            while (m) {
                S27E358_N *k = m;
                m = m->unk8;
                func_0011C408(0, k);
            }
            func_002D5BC0((S2D4468_A *)n);
            n += 0xC;
        }
        p->unk8 = 0;
    }
}

extern "C" S2D4468_A *func_002D5C88(S2D4468_A *self) {
    func_002D5BC0(self);
    return self;
}

extern "C" void func_002D5CB0(S2D4468_A *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S2D4468_A *func_002D5CC0(S2D4468_A *self) {
    func_002D5CB0(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5EC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D5F80);

INCLUDE_ASM("asm/nonmatchings/game/t_2D4468", func_002D6160);
