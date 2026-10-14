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
void func_00269B70(void);
int func_00251F68(void);
extern S00252EC8* D_0036CDB4[] __attribute__((section(".sdata")));
void func_001E19F8(int);
void func_001E1A28(int);
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00252FC0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_252068", CFunc_SetSoundBussEffects);

extern "C" int CFunc_GetSoundBussEffects(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_00253678);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002538C0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", func_002539C0);

INCLUDE_ASM("asm/nonmatchings/game/t_252068", CFunc_SoundEventFast);
