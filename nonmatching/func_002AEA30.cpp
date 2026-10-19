// cflags: -funroll-loops
#include "common.h"

struct S2AED18 {
    char pad0[0x20];
    int unk20;
};

struct S2ADFD8_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
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
extern S2AED18 *D_00372318;
float func_0011ED10(void);

void func_0011C408(int, void *);
void func_002AF170(int, int, int);
void func_002DC9F0(int, int);
int func_0027D870(int, int, int *, int);
int func_002763E0(int, int);
int func_0027CC30(int, int, int, f32 *);
void func_0027F1E0(int, int, int, f32);
void func_001F5820(int, f32);
void func_0027C448(int, int, int);
extern int D_00371EEC;
int func_0027DF00(int, int);
int func_0027D268(int, int, int *, int);
extern int D_00371ED8;
extern int D_00371EDC[2];
void func_00289F90(int, int, void *);
int func_0027D1F8(int, int, int *, int);
int func_002DCA08(int);
void func_0028D720(int);
int func_002AE2A8(int, int);
extern int D_00368A38;
void Heap_Free(int, void *);
int *Heap_Alloc(int, int, int, int);
extern f32 D_00373130[] __attribute__((section(".sdata")));
}

GP_DATA(D_00371EDC);
GP_DATA(D_00371ED8);
extern "C" s32 CFunc_LightShow_AppendSnapshotParams(int arg0) {
    D_00371ED8 = 0;
    if ((func_0027DF00(arg0, 0x1A4E0EF9) ^ 1) != 0) {
        D_00371ED8 = func_0027D268(arg0, 0x164D476D, D_00371EDC, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_OverrideColor);

GP_DATA(D_00371EE4);
GP_DATA(D_00371EE0);
INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_SetTime);

struct SGPS {
    char pad0[0x20];
    int unk20;
};
GP_DATA(D_00371EEC);
extern "C" s32 CFunc_LightShow_GetPyroScript(int arg0, SGPS *arg1) {
    int out;
    if (func_0027D870(D_00371EEC, 0xCF465431, &out, 0) != 0) {
        func_0027C448(arg1->unk20, 0xCF465431, out);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AD7F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_PlaySnapshot);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_CycleNextSnapshot);

struct S2AD_Arr {
    int unk0;
    u32 unk4;
    int unk8;
};

extern "C" {
int func_0027CC30_i(int, int, int, void *) asm("func_0027CC30");
void func_0027F1E0_i(int, int, int) asm("func_0027F1E0");
int func_0027D470(int, int, int *, int);
int func_001F5958(int, void *);
}

GP_DATA(D_00371EE8);
extern int D_00371EE8;

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_RefreshSpotlightOverrideParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_EnableSpotlights);

extern "C" void func_002ADFD8(S2ADFD8_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

extern "C" void func_002ADFE8(S27E358 *p) {
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
            func_002ADFD8((S2ADFD8_0 *)n);
            n += 0xC;
        }
        p->unk8 = 0;
    }
}

extern "C" S2ADFD8_0 *func_002AE0A0(S2ADFD8_0 *self) {
    func_002ADFD8(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE0C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE2A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE3C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE430);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE4A0);

struct S2AE5_E {
    int a;
};

struct S2AE5_V {
    int unk0;
    S2AE5_E *unk4;
    S2AE5_E *unk8;
    int unkC;
};

extern "C" void func_002AE510(S2AE5_V *self, int flags) {
    S2AE5_V *v = (S2AE5_V *)((char *)self + 4);
    S2AE5_E *b = v->unk4;
    if (b) {
        S2AE5_E *e = v->unk8;
        int h = D_00368A38;
        for (S2AE5_E *p = b; p != e; p++) {
        }
        Heap_Free(h, b);
        v->unk4 = 0;
        v->unk8 = 0;
        v->unkC = 0;
    }
    if (flags & 1)
        Heap_Free(D_00368A38, self);
}

static inline int *S2AE5_Copy(int *first, const int &last, int *res) {
    for (; first != (int *)last; first++, res++) {
        if (res)
            *res = *first;
    }
    return res;
}

struct S2AE5_C {
    int unk0;
    S2AE5_V v;
};

extern "C" S2AE5_C *func_002AE5E8(S2AE5_C *self, S2AE5_C *o) {
    S2AE5_V *a = &o->v;
    S2AE5_V *v = &self->v;
    self->unk0 = o->unk0;
    v->unk4 = 0;
    v->unk8 = 0;
    v->unkC = 0;
    int n;
    n = a->unk4 ? (((int)a->unk8 - (int)a->unk4) >> 2) : 0;
    if (n != 0) {
        int *buf = Heap_Alloc(D_00368A38, n * 4, 1, 0);
        v->unk4 = (S2AE5_E *)buf;
        v->unk8 = (S2AE5_E *)buf;
        v->unkC = (int)(buf + n);
    }
    int *r0 = (int *)v->unk4;
    int *f0 = (int *)a->unk4;
    int last = (int)a->unk8;
    v->unk8 = (S2AE5_E *)S2AE5_Copy(f0, last, r0);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE6C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE870);

struct S2AE9F8 {
    char pad0[0xC];
    int unkC;
};
extern "C" void func_002AE9F8(S2AE9F8 *p) {
    if (p->unkC != 0) {
        func_0028D720(p->unkC);
        p->unkC = 0;
    }
}

struct S2AEA30_N {
    S2AEA30_N *unk0;
    S2AEA30_N *unk4;
    void *unk8;
};

struct S2AEA30_L {
    char pad0[0xC];
    S2AEA30_N *unkC;
};

struct S2AEA30_I {
    char unk0;
    char unk1;
    short pad2;
    void *unk4;
    int unk8;
    int unkC;
};

struct S2AEA30_Cur {
    int pad0;
    S2AEA30_N *unk4;
    int unk8;
    int unkC;
};

struct S2AEA30 {
    void *unk0;
    S2AEA30_L *unk4;
};

extern char D_00362750[];
extern char D_003627C0[];
extern char D_00340F78[];

extern "C" void func_002AEA30(S2AEA30 *a, int flags) {
    S2AEA30_I g;
    S2AEA30_Cur end, it, d, h, e, f;
    a->unk0 = D_00362750;
    func_002AE510((S2AE5_V *)((char *)a + 0x10), 2);
    S2AEA30_L *l = a->unk4;
    a->unk0 = D_003627C0;
    if (l) {
        g.unk1 = 0;
        g.unk4 = a;
        end.unk4 = (S2AEA30_N *)((char *)l + 8);
        it.unk4 = l->unkC;
        if (it.unk4 != end.unk4) {
            do {
                S2AEA30_N *n = it.unk4;
                if (n->unk8 == g.unk4) {
                    h.unk4 = n;
                    f.unk4 = n;
                    S2AEA30_N *nx = n->unk4;
                    e.unk4 = n;
                    h.unk4 = nx;
                    n->unk0->unk4 = n->unk4;
                    n->unk4->unk0 = n->unk0;
                    Heap_Free(D_00368A38, n);
                    d.unk4 = it.unk4 = h.unk4;
                } else {
                    it.unk4 = n->unk4;
                }
            } while (it.unk4 != end.unk4);
        }
    }
    a->unk0 = D_00340F78;
    if (flags & 1) {
        Heap_Free(D_00368A38, a);
    }
}

struct S2AEB48_V {
    virtual void v1();
    virtual void v2();
    virtual void v3(void *q);
};

struct S2AEB48 : S2AEB48_V {
    void *unk4;
};

extern "C" void func_00289F90_1(void *) asm("func_00289F90");

extern "C" void func_002AEB48(S2AEB48 *p, void *q) {
    if (p->unk4 == 0) {
        func_00289F90_1(q);
    } else {
        p->v3(q);
    }
}

struct S2AEB98_P {
    int unk0;
};
struct S2AEB98 {
    char pad0[4];
    S2AEB98_P *unk4;
    s16 unk8;
    char padA[2];
    int (*unkC)(int, void *);
};
INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEB98);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEBF0);

extern "C" void func_002AECF8(void) {
    func_002AE2A8(1, 0xFFFF);
}

extern "C" float func_002AED18(void) {
    if (D_00372318->unk20 != 0) {
        return 0.0f;
    }
    return func_0011ED10();
}

extern "C" f32 func_002AED50(void *p, int i) {
    return D_00373130[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_MonitorControllerStates);

extern "C" s32 CFunc_AllocateDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_ClearDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_WriteDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_ReadDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutChecksum(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutInt(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutFloat(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutString(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetChecksum(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetInt(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetFloat(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetString(void) {
    return 0;
}

extern "C" s32 CFunc_GetBufferFileCount(void) {
    return 0;
}

extern "C" s32 CFunc_ReplayInput(void) {
    return 0;
}

extern "C" s32 CFunc_RecordInput(void) {
    return 0;
}

struct S2AF170_P {
    u8 b[0x38];
    int unk38;
};

struct S2AF170_O {
    char pad0[0x1C];
    S2AF170_P *unk1C;
};

extern "C" S2AF170_O *func_002DCA08_o(int) asm("func_002DCA08");

extern "C" void func_002AF170(int out, int flags, int c) {
    S2AF170_O *o = func_002DCA08_o(out);
    o->unk1C->b[11] = 0;
    o->unk1C->b[10] = 0;
    o->unk1C->b[9] = 0;
    o->unk1C->b[12] = 0;
    o->unk1C->b[13] = 0;
    o->unk1C->b[16] = 0;
    if (flags & 0x10000) o->unk1C->b[0x10] = 0xFF;
    if (flags & 0x1000) o->unk1C->b[0xA] = 0xFF;
    if (flags & 0x100) o->unk1C->b[9] = 0xFF;
    if (flags & 0x10) o->unk1C->b[0xB] = 0xFF;
    if (flags & 1) o->unk1C->b[0xC] = 0xFF;
    o->unk1C->b[15] = 0;
    o->unk1C->b[14] = 0;
    o->unk1C->b[7] = 0;
    o->unk1C->b[8] = 0;
    o->unk1C->b[6] = 0;
    o->unk1C->b[5] = 0;
    o->unk1C->b[1] = 0;
    o->unk1C->b[2] = 0;
    o->unk1C->b[3] = 0;
    o->unk1C->b[4] = 0;
    o->unk1C->b[17] = 0;
    o->unk1C->b[18] = 0;
    o->unk1C->b[19] = 0;
    o->unk1C->b[20] = 0;
    o->unk1C->b[21] = 0;
    o->unk1C->b[22] = 0;
    o->unk1C->b[23] = 0;
    o->unk1C->b[24] = 0;
    o->unk1C->b[25] = 0;
    o->unk1C->b[26] = 0;
    o->unk1C->b[27] = 0;
    o->unk1C->b[28] = 0;
    o->unk1C->b[29] = 0;
    o->unk1C->b[30] = 0;
    o->unk1C->b[31] = 0;
    o->unk1C->b[32] = 0;
    o->unk1C->b[33] = 0;
    o->unk1C->b[34] = 0;
    o->unk1C->b[35] = 0;
    o->unk1C->b[36] = 0;
    if (c == 0) {
        o->unk1C->unk38 = 0;
    } else {
        o->unk1C->unk38 = 0x1000;
    }
}

extern "C" int CFunc_SetInput(int arg0) {
    int a = 0;
    if (func_0027D1F8(arg0, 0xB30D9965, &a, 0)) {
        int b = 0;
        func_0027D1F8(arg0, 0x5C430371, &b, 0);
        int c = 0;
        func_0027D1F8(arg0, 0x55CC895E, &c, 0);
        func_002AF170(a, b, c);
    }
    return 1;
}

extern "C" s32 CFunc_EnableInput(int arg0) {
    int out;
    int t = func_0027DF00(arg0, 0xD443A2BC) ^ 1;
    if (func_0027D1F8(arg0, 0xB30D9965, &out, 0) != 0) {
        func_002DC9F0(out, t);
    }
    return 0;
}

struct S2AF438 {
    char pad0[0x20];
    struct { char pad0[0xC]; int unkC; } *unk20;
};
extern "C" int func_002AF438(S2AF438 *p, int n) {
    if (n >= 2) {
        return 1;
    }
    return p->unk20->unkC == 8;
}

extern "C" int CFunc_IsGuitarController(int arg0) {
    int out = 0;
    if (func_0027D1F8(arg0, 0xB30D9965, &out, 0) != 0) {
        return func_002AF438((S2AF438 *)func_002DCA08(out), out);
    }
    return 0;
}

extern "C" s32 CFunc_UnBindGuitarControllerStatus(void) {
    return 1;
}

extern "C" int func_002DC9D8(int);
struct S2AF4B0_B {
    char pad0[9];
    u8 u9;
    u8 uA;
    u8 uB;
    u8 uC;
    u8 uD;
    u8 uE;
    u8 uF;
    u8 u10;
};
struct S2AF4B0_C {
    char pad0[0x1C];
    S2AF4B0_B *unk1C;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AF4B0);
