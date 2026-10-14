#include "common.h"

struct S00252EC8 {
    char pad[0x308];
    int unk308;
};

extern "C" {
struct S252_Vec {
    f32 x, y, z, w;
};
struct S252_Cam {
    char pad[0xD8];
    f32 unkD8;
};
int func_0027D2D8(int, u32, S252_Vec *, int);
int func_0027D268(int, u32, f32 *, int);
S252_Cam *func_0015D5A0(int);
void func_002530A8(int, int, int);
int func_0015DB00(int);
int func_0015D2E8(int, int);
int func_0027DF00(int, u32);
int func_0027D1F8(int, int, int *, int);
int func_0027D870(int, int, int *, int);
int func_0027D400(int, int, int *, int);
void func_002532C8(int, int);
void func_00269998(int, int);
struct S252_N { u32 unk0; int unk4; int unk8; };
struct S252_L { int unk0; u32 unk4; int unk8; };
S252_N *func_0027B300(int, S252_N *);
void func_00269B70(void);
int func_00251F68(void);
extern S00252EC8* D_0036CDB4[] __attribute__((section(".sdata")));
void func_001E19F8(int);
void func_001E1A28(int);
void func_0015D5E8(int, void *, void *, int);
void func_002EB280(void *);
}

typedef unsigned int u128_252 __attribute__((mode(TI)));

struct S252_Obj {
    char pad0[0x2C];
    int unk2C;
    char pad30[0x50];
    u128_252 unk80;
};

struct S252_Loc {
    int a0;
    int a4;
    int a8;
    int aC;
    int a10;
    int a14;
    int pad18;
    int pad1C;
    float f20;
    int pad24[3];
    u128_252 v30;
};

extern "C" int CFunc_KillCamAnim(void) {
    func_00251F68();
    return 1;
}

extern "C" int CFunc_ViewportUsedByMovieCamera(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252090);

extern "C" int CFunc_ShowCamOffset(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", CFunc_GetCamOffset);

extern "C" void CFunc_HasMovieStarted(void) {
    func_001E19F8(D_0036CDB4[0]->unk308);
}

extern "C" void CFunc_IsMovieQueued(void) {
    func_001E1A28(D_0036CDB4[0]->unk308);
}

extern "C" int CFunc_CamDistFromPosLessThan(int params) {
    S252_Vec v;
    f32 lim;
    f32 d;
    int t;
    func_0027D2D8(params, 0x7F261953, &v, 1);
    lim = 0.0f;
    func_0027D268(params, 0x7E832F08, &lim, 1);
    S252_Cam *c = func_0015D5A0(0);
    asm volatile("lqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 0x80(%3)\n\tvsub.xyzw $vf2, $vf2, $vf1\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni %1, $vf1\n\tmtc1 %1, %0\n\tnop\n\tnop\n\tsqrt.s %0, %0"
        : "=f"(d), "=&r"(t) : "r"(&v), "r"(c));
    return d * c->unkD8 < lim;
}

struct S252_M4 {
    u128_252 r0, r1, r2, r3;
};

struct S252_VEnt {
    s16 delta;
    s16 unk2;
    void (*fn)(void *);
};

struct S252_Comp {
    char pad0[0x18];
    S252_VEnt *vt;
    int unk1C;
};

struct S252_Node {
    char pad0[0x80];
    u128_252 unk80;
    char pad90[0x10];
    S252_M4 unkA0;
};

struct S252_CamN {
    char pad0[0x80];
    u128_252 unk80;
    S252_M4 unk90;
};

extern "C" {
S252_Node *func_001D8618(int, int);
S252_Comp *func_001D1CF8(S252_Node *, u32);
S252_CamN *func_0015D5A0_n(int) asm("func_0015D5A0");
void func_0015DC18(int, int);
extern int D_0036D3B0;
}

extern "C" int func_00252FC0(int id, int cam, int copy) {
    S252_Node *n = func_001D8618(D_0036D3B0, id);
    if (!n) {
        return 0;
    }
    S252_Comp *c = func_001D1CF8(n, 0xC4E311FA);
    if (c) {
        if (copy) {
            S252_M4 *sp = &func_0015D5A0_n(cam)->unk90;
            S252_M4 *d = &n->unkA0;
            *d = *sp;
            n->unk80 = func_0015D5A0_n(cam)->unk80;
            c->vt[2].fn((char *)c + c->vt[2].delta);
        }
        func_0015DC18(cam, c->unk1C);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002530A8);

extern "C" void CFunc_SetActiveCamera(int arg0) {
    int s = 0;
    int c;
    int r;
    func_0027D870(arg0, 0x40C698AF, &s, 0);
    c = 0;
    if (func_0027D870(arg0, 0x9FD29151, &c, 0)) {
        r = func_0015D2E8(c, 1);
    } else {
        int d = 0;
        func_0027D1F8(arg0, 0x9FD29151, &d, 0);
        r = func_0015DB00(d);
    }
    func_002530A8(s, r, func_0027DF00(arg0, 0x10C1C887));
}

extern "C" int CFunc_SetPrepassViewportCamera(void) {
    return 0;
}

extern "C" int CFunc_WaitMovie(void) {
    return 0;
}

extern "C" int CFunc_MovieMembFunc(void) {
    return 0;
}

extern "C" int CFunc_DumpMovies(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002532A0);

extern "C" void func_002532C0(void) {
}

extern "C" void func_002532C8(int a, int b) {
    S252_N *n = 0;
    while ((n = func_0027B300(b, n))) {
        u32 t = n->unk0 & 0xFE00;
        if (t == 0x1400) {
            func_00269998(a, n->unk4);
            func_002532C8(n->unk4, n->unk8);
        } else if (t == 0x1800) {
            S252_L *l = (S252_L*)n->unk8;
            u32 i = 0;
            if (l->unk4 != 0) {
                do {
                    int v;
                    if (l->unk4 == 1) v = l->unk8;
                    else v = ((int*)l->unk8)[i];
                    func_00269998(a, v);
                    i++;
                } while (i < l->unk4);
            }
        }
    }
}

extern "C" int CFunc_CreateBussSystem(int arg0) {
    int out;
    if (func_0027D400(arg0, 0, &out, 1) != 0) {
        func_002532C8(0, out);
    }
    return 1;
}

extern "C" int CFunc_SoundBussLock(void) {
    return 0;
}

extern "C" int CFunc_SoundBussUnLock(void) {
    return 0;
}

extern "C" void CFunc_SetSoundBussParams(void) {
    func_00269B70();
}

extern "C" int CFunc_GetSoundBussParams(void) {
    return 0;
}

extern "C" int CFunc_PushSoundBussParams(void) {
    return 0;
}

extern "C" int CFunc_PopSoundBussParams(void) {
    return 0;
}

extern "C" int CFunc_CreateSoundBussEffects(void) {
    return 0;
}

extern "C" int CFunc_DestroySoundBussEffects(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", CFunc_SetSoundBussEffects);

extern "C" int CFunc_GetSoundBussEffects(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00253678);

extern "C" void func_002538C0(int params, S252_Obj *obj) {
    S252_Loc l;
    int *p8 = &l.a8;
    l.a0 = 0;
    l.a8 = 0;
    l.a14 = 0;
    func_0027D870(params, 0xC451F558, &l.a0, 1);
    func_0027D268(params, 0xD4F52446, &l.f20, 1);
    l.a4 = (int)(l.f20 * 1000.0f);
    func_0027D870(params, 0x61D8542A, p8, 1);
    func_0027D1F8(params, 0x5726EB0E, &l.aC, 1);
    l.a10 = 0;
    if (obj) {
        l.a14 = obj->unk2C;
        if (l.a8 == 0x49EF8F3F) {
            l.v30 = obj->unk80;
            func_0015D5E8(0, &l.v30, &l.a10, 0);
        }
    }
    func_002EB280(&l);
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002539C0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", CFunc_SoundEventFast);
