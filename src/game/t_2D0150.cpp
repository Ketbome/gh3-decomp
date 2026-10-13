#include "common.h"

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0150);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_get_song_rhythm_track_cfunc);

extern "C" void func_002D0240(int a, int b) {
    char buf[0x10];
    func_0027AA70(buf);
    func_0027C448((int)buf, 0xC451F558, a);
    CFunc_SoundEventFast(buf, b);
    func_0027AC90(buf);
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

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_get_song_tempo_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0E08);

struct SGAS {
    char pad0[0x20];
    int unk20;
};
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

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_play_stance_transition_cfunc);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D2120);
