#include "common.h"

struct SGAS {
    char pad0[0x20];
    int unk20;
};

extern "C" {
void func_002D0CF0(f32 *, int *);
void func_0027C1F8(int, int, f32);
void func_002D1190(void *, int, int, int, int);
void func_0027F1E0(int, int, int);
void func_0027D400(int, int, int *, int);
int func_0027CC30(int, int, int, int *);
int func_002763E0(int, int);
int func_002D0150(int);
void func_0027C160(int, int, int);
int func_0027D870(int, int, int *, int);
void func_0027AA70(void *);
void func_0027AC90(void *);
void CFunc_SoundEventFast(void *, int);
int func_00289E08(void *);
int func_002D0F08(int);
int func_002D0E08(void);
void func_0027C448(int, int, int);
s32 func_00289C88(s32, s32);
char *func_00289C80(s32);
int func_00289CF8(s32);
}

extern "C" int func_002D0150(int arg0) {
    int h = func_002763E0(0x6F53CF2D, 1);
    int out = 0;
    int v;
    func_0027D400(h, arg0, &out, 0);
    int s = out;
    if (func_0027CC30(s, 0x05294EBF, 1, &v) == 0) {
        func_0027F1E0(s, 0, 1);
        return 0;
    }
    return v;
}

extern "C" s32 CFunc_get_song_rhythm_track_cfunc(int arg0, SGAS *arg1) {
    int out = 0x0466857F;
    func_0027D870(arg0, 0xCC12115E, &out, 0);
    int t = arg1->unk20;
    func_0027C160(t, 0x05294EBF, func_002D0150(out));
    return 1;
}

extern "C" void func_002D0240(int a, int b) {
    char buf[0x10];
    func_0027AA70(buf);
    func_0027C448((int)buf, 0xC451F558, a);
    CFunc_SoundEventFast(buf, b);
    func_0027AC90(buf);
}

extern "C" {
int func_00275F08(u32, int);
int func_00276008(u32, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D02A0);

extern "C" s32 CFunc_GuitarEvent_MissedNote_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x14);
    *(s32 *)(func_00289C80(arg1) + 0x10) = 0;
    return 1;
}

extern "C" s32 CFunc_GuitarEvent_MissedNote_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_MissedNote_CFunc);

extern "C" s32 CFunc_GuitarEvent_UnnecessaryNote_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0xC);
    *(s32 *)(func_00289C80(arg1) + 0x8) = 0;
    return 1;
}

extern "C" s32 CFunc_GuitarEvent_UnnecessaryNote_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_UnnecessaryNote_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_event_spawner_cfunc);

extern "C" void func_002D0CF0(f32 *out, int *tempo) {
    int h = func_002763E0(0xD95930AC, 1);
    int out2;
    int v;
    if (func_0027CC30(h, 0x8C309373, 1, &out2) == 0) {
        func_0027F1E0(h, 0, 1);
        v = 0;
    } else {
        v = out2;
    }
    f32 r;
    if (v == 0) {
        r = 100.0f;
    } else {
        r = 1000.0f / (f32)v * 60.0f;
    }
    *out = r;
    *tempo = v;
}

extern "C" s32 CFunc_get_song_tempo_cfunc(int arg0, SGAS *arg1) {
    f32 a;
    int b;
    func_002D0CF0(&a, &b);
    func_0027C1F8(arg1->unk20, 0x8B4A1490, a);
    func_0027C160(arg1->unk20, 0x0EBB7064, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0E08);

extern "C" s32 CFunc_get_anim_speed_for_tempo_cfunc(int arg0, SGAS *arg1) {
    int t = arg1->unk20;
    func_0027C448(t, 0xA7E8878D, func_002D0E08());
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0F08);

extern "C" s32 CFunc_hero_get_skill_level_cfunc(int arg0, SGAS *arg1) {
    int a = func_00289E08(arg1);
    int t = arg1->unk20;
    int b = func_002D0F08(a);
    func_0027C448(t, 0xA1C21B88, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D1190);

extern "C" void CFunc_play_stance_transition_cfunc(int arg0, void *arg1) {
    int a;
    int b;
    int c;
    func_0027D870(arg0, 0x9977B95F, &a, 1);
    int x = a;
    func_0027D870(arg0, 0x34CD6F44, &b, 1);
    int y = b;
    func_0027D870(arg0, 0x859884E9, &c, 1);
    int z = c;
    func_002D1190(arg1, func_00289E08(arg1), x, y, z);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D1578);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_hero_play_tempo_anim_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_enable_crowd_models_cfunc);

extern "C" s32 CFunc_AnimatedTextureLoop_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x48);
    *(s32 *)(func_00289C80(arg1) + 0x44) = 0;
    return 1;
}

extern "C" s32 CFunc_AnimatedTextureLoop_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_AnimatedTextureLoop_CFunc);

extern "C" void func_002D2110(void) {
}

extern "C" void func_002D2118(void) {
}

extern "C" {
float func_002AED18(void);
void func_00260D50_f(float) asm("func_00260D50");
float func_00260D08(void);
float *func_002CDCF8(u32);
float func_00275DE0(u32, int);
void func_0027C898(int, u32, int);
void *func_001287F0(int, int);
int func_0027AA70_i(int) asm("func_0027AA70");
void func_0027AC90_i(int) asm("func_0027AC90");
void func_00113250(int);
void CFunc_SpawnScriptNow(int, int);
}

extern "C" void func_002D2120(int a) {
    float f20 = func_002AED18();
    func_00260D50_f(f20);
    float f21 = func_00260D08();
    *func_002CDCF8(0x6D735468) = f20;
    float *q = func_002CDCF8(0x5FD80EDC);
    f20 = *q;
    *q = f21;
    if (func_00276008(0x2B580363, 0) == 0x64CB606E) {
        func_002D2118();
    }
    float t = func_00275DE0(0x7617AFAE, 0) * 0.001f;
    if (f20 < t && t <= f21) {
        int o = func_0027AA70_i((int)func_001287F0(8, 1));
        func_0027C448(o, 0, 0xD7B6902D);
        int p = func_0027AA70_i((int)func_001287F0(8, 1));
        func_0027C448(p, 0xD24F570C, func_00276008(0x03A17838, 1));
        func_0027C448(p, 0x44949010, func_00276008(0x9B2F5962, 1));
        func_0027C448(p, 0xD524D574, func_00276008(0x6BF07EAD, 1));
        func_0027C160(p, 0xD16B61E6, func_00275F08(0x0A4DD04A, 1));
        func_0027C160(p, 0xC9428A08, func_00275F08(0xAB76E33E, 1));
        func_0027C448(p, 0, 0xDE655351);
        func_0027C898(o, 0x7031F10C, p);
        CFunc_SpawnScriptNow(o, a);
        if (o != 0) {
            func_0027AC90_i(o);
            func_00113250(o);
        }
    }
}
