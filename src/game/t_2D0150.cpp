#include "common.h"

extern "C" {
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0150);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_get_song_rhythm_track_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0240);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D02A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_MissedNote_CFunc_Setup);

extern "C" s32 CFunc_GuitarEvent_MissedNote_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_MissedNote_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_UnnecessaryNote_CFunc_Setup);

extern "C" s32 CFunc_GuitarEvent_UnnecessaryNote_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_GuitarEvent_UnnecessaryNote_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_event_spawner_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_get_song_tempo_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0E08);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_get_anim_speed_for_tempo_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D0F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_hero_get_skill_level_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D1190);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_play_stance_transition_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", func_002D1578);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_hero_play_tempo_anim_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_enable_crowd_models_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D0150", CFunc_AnimatedTextureLoop_CFunc_Setup);

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
