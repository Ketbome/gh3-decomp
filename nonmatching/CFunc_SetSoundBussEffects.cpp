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

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002532C8);

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

extern "C" {
int func_001150E0_b(int, char *) asm("func_001150E0");
extern char D_00370430[];
void func_0030B550_b(char *, const char *, ...) asm("func_0030B550");
void func_00269888(u32, f32);
int func_0027D870_b(int, int, u32 *, int) asm("func_0027D870");
}

extern "C" int CFunc_SetSoundBussEffects(int params) {
    char buf[0x10];
    int sp10 = 0;
    int sp14;
    u32 sp18;
    u32 sp1C;
    f32 sp20;
    int i = 1;
    int done = 0;
    register int c asm("$18") = 0x499F6E0D;
    func_0027D268(params, 0x906B67BA, (f32 *)&sp10, 0);
    do {
        register int key asm("$16") = c;
        if (!(i < 2)) {
            func_0030B550_b(buf, D_00370430, i);
            key = func_001150E0_b(key, buf);
        }
        if (func_0027D400(params, key, &sp14, 0)) {
            sp20 = 1.0f;
            func_0027D870_b(sp14, 0x499F6E0D, &sp18, 1);
            func_0027D870_b(sp14, 0xA1DC81F9, &sp1C, 1);
            switch (sp18) {
            case 0x0F36AD93:
                func_0027D268(sp14, 0xD8604126, &sp20, 0);
                func_00269888(sp1C, sp20);
                break;
            case 0x1AE536AC:
            case 0x73E18C78:
            case 0x94AA749E:
            case 0x9FC59444:
            case 0xD47A9AF8:
            case 0xE7F8E720:
                func_0027D268(sp14, 0x906B67BA, &sp20, 0);
                break;
            }
        } else {
            done = 1;
        }
        i++;
    } while (!done);
    return 1;
}

extern "C" int CFunc_GetSoundBussEffects(void) {
    return 1;
}

extern "C" {
int func_001150E0(int, char *);
float func_00275DE0(u32, int);
int func_00275F08(u32, int);
int func_00276008(u32, int);
int func_002763E0(int, int);
void func_0027C160(int, u32, int);
void func_0027C1F8(int, u32, float);
void func_0027C448(int, u32, int);
int func_0027D1F8(int, int, int *, int);
extern int D_00370434;
extern char D_00370438[];
extern int D_00372E58;
extern int D_00372E60;
extern int D_00372E64;
extern float D_00372E68;
extern int D_00372E6C;
}

GP_DATA(D_00370434);
extern "C" int func_00253678(int a, int b) {
    int sp0;
    int sp4;
    float sp8;
    int spC;
    int sp10;
    if (D_00370434 == 0) {
        D_00372E64 = func_00275F08(0x1F5DD214, 1);
        D_00372E58 = func_00276008(0xAEA1C866, 1);
        D_00372E68 = func_00275DE0(0x9A6ED562, 1);
        D_00372E60 = func_00276008(0x59F9BA16, 1);
        D_00372E6C = func_00275F08(0x6C7486B9, 1);
        D_00370434 = 1;
    }
    int t = func_002763E0(func_001150E0(a, D_00370438), 0);
    int r = t != 0;
    if (t == 0 || (func_0027D1F8(t, 0x9B1D1396, &sp0, 0) ^ 1) != 0) {
        sp0 = D_00372E64;
    }
    func_0027C160(b, 0x8A7A1F88, sp0);
    if (t == 0 || (func_0027D870(t, 0x95418465, &sp4, 0) ^ 1) != 0) {
        sp4 = D_00372E58;
    }
    func_0027C448(b, 0x92ECB746, sp4);
    if (t == 0 || (func_0027D268(t, 0x14021E42, &sp8, 0) ^ 1) != 0) {
        sp8 = D_00372E68;
    }
    func_0027C1F8(b, 0xD4F52446, sp8);
    if (t == 0 || (func_0027D870(t, 0xBC2F36B9, &spC, 0) ^ 1) != 0) {
        spC = D_00372E60;
    }
    func_0027C448(b, 0x61D8542A, spC);
    if (t == 0 || (func_0027D1F8(t, 0xF546374F, &sp10, 0) ^ 1) != 0) {
        sp10 = D_00372E6C;
    }
    func_0027C160(b, 0x5726EB0E, sp10);
    return r;
}

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
