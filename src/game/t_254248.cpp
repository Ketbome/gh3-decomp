#include "common.h"

asm(".set D_00370AE0_gp, D_00370AE0");
asm(".set D_00368A38_lui, D_00368A38");

struct S254248_A {
    char pad0[0x1E0];
    int unk1E0;
};

extern "C" {
void func_002682B8_f(int, f32, int, int) asm("func_002682B8");
void func_00268330_f(int, f32, int, int) asm("func_00268330");
int func_0027D470(int, int, int **, int);
int func_0011A5B8(int *, int);
void func_002678F0(int, int);
void func_0027C448(int, int, int);
int func_0026F3B8(int, int);
void func_00113250(int);
void func_0027AC90(int);
int func_0027AA70(int);
int func_001287F0(int, int);
int CFunc_PlaySound(int, int);
int func_0026DCC8(int);
void func_0026C738(int, f32);
extern char D_00356110[];
void func_0030B550(char *, char *, int);
void func_0026C5E8(int, int);
void func_0026DE28(int);
int func_0026DAF8(int, int);
void func_0026BBA8(int, int, int, int);
void func_0026CA78(int, int, int);
int func_0027CFA8(int, int, int *, int);
void func_002E7C58(int, int);
void func_00275F08(u32, int);
int func_0026A660(int);
int func_0026C250(int, int, int);
int func_0026C120(int, int, int);
void func_002E7D80(int);
void func_0026D6D0(int, int, int);
int func_0026DCA0(int);
int func_0027D828(int, int);
int func_002E6C80(int);
int func_0026DE20(void);
void func_0027C160(int, int, int);
void func_0026C870(void);
int func_0026A030(void);
int func_0026E8B8(void);
int func_002EA460(void);
int func_002E8968(void);
int func_00266D20(void);
int func_0026AE70(void);
int func_0026CC48(void);
extern int D_00370AE0[] __attribute__((section(".sdata")));
void func_00267A00(int);
int func_0027D870(int, int, void*, int);
int func_0027DF00(int, u32);
void func_0026CBE8(int);
void func_002E7010(int);
int func_0027D1F8(int, u32, void*, int);
int func_0027D268(int, u32, void*, int);
void func_002696C8(void);
void func_002EA620(void);
int func_0026E158(int);
void func_00267910(int, int);
int func_0026A5D0(int);
int func_0026E0E8(int);
void func_0026C7A8(int);
void func_0026CC80(int);
void func_002E6D40(int);
bool func_002E7B60(int);
void func_0026A3F0(int);
void func_0026CCD8(int);
void func_0026DBD8(int);
void func_0026C9E8(f32);
void func_0026C940(f32);
void func_00267758(int, int);
void func_002E70B0(int);
void func_00268228(int, f32);
int func_002EBC18(int);
void func_002EBA98(int);
void func_002EA740(int);
int func_0027D188(int, u32, void*, int);
extern S254248_A *D_00368A38;
extern S254248_A *D_00368A38_lui[] asm("D_00368A38_lui") __attribute__((section(".sdata")));
int func_0026DC20(int);
void func_00119490(S254248_A *, int);
void func_001194B8(S254248_A *);
int func_00266E08(int);
int func_00266CE0(int);
void func_00267310(int, f32);
int func_0026DAB0(int);
void func_0026D660(u64 *, u64 *);
extern int D_00370AE0_gp asm("D_00370AE0_gp");
}

extern "C" int CFunc_AddSoundEventData(void) {
    return 0;
}

extern "C" int CFunc_RequestNewSoundEvent(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StopSoundEvent);

extern "C" int CFunc_IsSoundEventPlaying(void) {
    return 0;
}

extern "C" int CFunc_AddSoundEventScript(void) {
    return 0;
}

extern "C" int CFunc_RemoveSoundEventScript(void) {
    return 0;
}

extern "C" int CFunc_LoadSound(int a) {
    int x = 0;
    if (!func_0027D870(a, 0, &x, 0)) {
        return 0;
    }
    func_0026A3F0(x);
    return 1;
}

extern "C" int CFunc_UnloadAllSFX(void) {
    func_0026A030();
    return 1;
}

extern "C" int CFunc_ResetBCSND(void) {
    func_002696C8();
    func_002EA620();
    return 1;
}

struct SLoadFSB {
    char pad0[0x20];
    int unk20;
};
extern "C" s32 CFunc_LoadFSB(int arg0, SLoadFSB *arg1) {
    func_0027C160(arg1->unk20, 0xB3F0F2FE, func_002E6C80(func_0027D828(arg0, 0xC3F4169A)));
    return 1;
}

extern "C" int CFunc_UnLoadFSB(int a) {
    int x = 0;
    func_0027D1F8(a, 0xB3F0F2FE /* fsb_index */, &x, 1);
    func_002E6D40(x);
    return 1;
}

extern "C" int CFunc_LockDSP(void) {
    return 0;
}

extern "C" int CFunc_UnLockDSP(void) {
    return 0;
}

extern "C" int CFunc_PlayStream(int a) {
    int x = 0;
    return func_0027D870(a, 0, &x, 0) != 0;
}

extern "C" int CFunc_StreamExists(int arg0) {
    int out = 0;
    int r = 0;
    if (func_0027D870(arg0, 0, &out, 0) != 0) {
        r = func_0026DCA0(out) != 0;
    }
    return r;
}

extern "C" int CFunc_AddStream(int arg0) {
    int a = 0;
    int b;
    if (func_0027D870(arg0, 0, &a, 0) != 0) {
        b = 0;
        if (func_0027D870(arg0, 0x02E58C18, &b, 0) != 0) {
            return func_0026C120(a, b, 0);
        }
    }
    return 0;
}

extern "C" int CFunc_RemoveStream(int arg0) {
    int a = 0;
    int b;
    if (func_0027D870(arg0, 0, &a, 0) != 0) {
        b = 0;
        if (func_0027D870(arg0, 0x02E58C18, &b, 0) != 0) {
            return func_0026C250(a, b, 0);
        }
    }
    return 0;
}

extern "C" int CFunc_StopSoundStream(int a) {
    int x = 0;
    if (func_0027D870(a, 0x1C397CBC /* unique_id */, &x, 0)) {
        func_002E70B0(x);
    }
    return 1;
}

extern "C" s32 CFunc_StopStream(int arg0) {
    int out = 0;
    if (func_0027D870(arg0, 0x1C397CBC, &out, 0) == 0) {
        if (func_0027D870(arg0, 0, &out, 0) == 0) {
            return 0;
        }
    }
    func_002E7D80(out);
    return 0;
}

extern "C" int CFunc_StopSoundsByBuss(int a) {
    int x = 0;
    func_0027D870(a, 0, &x, 0);
    return 1;
}

extern "C" int CFunc_StopAudioStreams(void) {
    return 0;
}

extern "C" int CFunc_IsStreamPlaying(int arg0) {
    int a = 0;
    int b = 0;
    int *pa = &a;
    func_0027D1F8(arg0, 0xAF6450A6, &b, 0);
    if (func_0027D870(arg0, 0, pa, 0)) {
        int v = func_0026A5D0(a);
        if (v && b) {
            if (func_0026DCC8(a)) {
                v = 0;
            }
        }
        return v;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetStreamParams);

extern "C" int CFunc_PreprocessStreamSets(void) {
    func_0026E8B8();
    return 1;
}

extern "C" int CFunc_PlayStreamFromSet(int arg0, int arg1) {
    int o = func_0027AA70(func_001287F0(8, 1));
    if (func_0026F3B8(arg0, o)) {
        CFunc_PlaySound(o, arg1);
        if (o) {
            func_0027AC90(o);
            func_00113250(o);
            return 1;
        }
        return 1;
    }
    if (o) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 0;
}

extern "C" int CFunc_LoadSoundRAM(int arg0) {
    int ok = 0;
    int v = 0;
    int out = 0;
    if (func_0027D188(arg0, 0, &out, 0)) {
        ok = func_0027D1F8(arg0, 0, &v, 0) != 0;
    }
    if (ok) {
        func_0026BBA8(out, v, 0, 0);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_PlayTrack(int arg0) {
    int flag;
    int idx;
    int track;
    char buf[0x30];
    idx = 0x3E7;
    track = 0;
    flag = 0;
    if (func_0027CFA8(arg0, 0, &track, 0) == 0) {
        func_0027D1F8(arg0, 0, &idx, 0);
        track = func_0026DAF8(idx, 0);
        func_0030B550(buf, D_00356110, track);
        track = (int)buf;
    }
    func_0027D1F8(arg0, 0x5EA0E211, &flag, 0);
    if (track) {
        func_0026AE70();
        func_0026C5E8(track, flag != 0);
        func_0026DE28(idx);
    }
    return 1;
}

extern "C" int CFunc_PlayMusicStream(int arg0) {
    int out = 0;
    f32 f;
    int ok = func_0027D870(arg0, 0, &out, 0);
    int o = out;
    if (ok) {
        f = -1.0f;
        func_0027D268(arg0, 0xF6A36814, (void *)&f, 0);
        func_0026C738(o, f);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_LoadStreamFrameAmp(int a) {
    int x;
    if (func_0027D870(a, 0, &x, 0)) {
        return func_0026E0E8(x) != 0;
    }
    return 0;
}

extern "C" int CFunc_FreeStreamFrameAmp(int a) {
    int x;
    if (func_0027D870(a, 0, &x, 0)) {
        return func_0026E158(x);
    }
    return 0;
}

extern "C" int CFunc_BCSND_UpdateSound(void) {
    func_002EA460();
    return 1;
}

extern "C" int CFunc_SetStereoSound(int a) {
    int x = 1;
    if (func_0027D1F8(a, 0, &x, 0)) {
        func_002EA740(x != 0);
        return 1;
    }
    return 0;
}

struct S254_Script {
    char pad0[0x20];
    int unk20;
};
struct S254_O1 {
    f32 a;
    f32 b;
    char pad[0x18];
};
struct S254_O2 {
    char pad[0x20];
};
struct S254_PL {
    int sp40;
    int sp44;
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    f32 sp54;
    int sp58;
    int sp5C;
    int sp60;
    int sp64;
    int sp68;
};
struct S254_PF {
    S254_O1 o1;
    S254_O2 o2;
    S254_PL l;
};
extern "C" {
void func_00266898(void *);
void func_00266BE8(void *);
void func_002668F8(void *, int);
void func_00256340(void *, int);
void func_0026A488(int, int, int, f32, f32, f32);
int func_0027D400(int, u32, void *, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PlaySound);

extern "C" int CFunc_IsSoundLoaded(void) {
    return 0;
}

extern "C" int CFunc_StopSound(int arg0) {
    int out = 0;
    if (func_0027D870(arg0, 0, &out, 0)) {
        int r = func_0026A660(out);
        if (r == 0) {
            func_00275F08(0xD7BB618D, 0);
        }
        return r;
    }
    return 0;
}

extern "C" int CFunc_StopAllSounds(void) {
    func_002E8968();
    return 1;
}

extern "C" int CFunc_SetSoundSeekPosition(void) {
    return 0;
}

extern "C" int CFunc_IsSoundSeekDone(void) {
    return 0;
}

extern "C" int CFunc_PauseSoundsByBuss(void) {
    return 0;
}

extern "C" int CFunc_UnPauseSoundsByBuss(void) {
    return 0;
}

extern "C" {
void func_00269E50(int, f32, f32);
void func_00269FE0(int, f32, f32);
}

struct S254_SP {
    int sp0;
    int sp4;
    f32 a;
    f32 b;
    f32 c;
};

extern "C" int CFunc_SetSoundParams(int params) {
    S254_SP l;
    l.sp0 = 0;
    l.sp4 = 0;
    int *p4 = &l.sp4;
    func_0027D870(params, 0, &l.sp0, 0);
    func_0027D870(params, 0x1C397CBC, p4, 0);
    if (l.sp0 != 0 || l.sp4 != 0) {
        l.a = 100.0f;
        l.b = 100.0f;
        int found = 0;
        if (func_0027D268(params, 0x5E285A66, &l.a, 0)) found = 1;
        if (func_0027D268(params, 0xA4276705, &l.b, 0)) found = 1;
        if (func_0027D268(params, 0xF6A36814, &l.c, 0)) {
            found = 1;
            l.b = l.a = l.c;
        }
        if (found) {
            if (l.sp4 != 0) {
                func_00269E50(l.sp4, l.a * 0.01f, l.b * 0.01f);
            } else {
                func_00269FE0(l.sp0, l.a * 0.01f, l.b * 0.01f);
            }
        }
    }
    return 1;
}

extern "C" int CFunc_IsSoundPlaying(int a) {
    int x = 0;
    if (func_0027D870(a, 0, &x, 0)) {
        return func_0026A5D0(x);
    }
    return 0;
}

extern "C" int CFunc_IsSoundPlayingByID(void) {
    return 0;
}

extern "C" int CFunc_AddSoundBanks(int a) {
    int *arr;
    u32 i;
    int h;
    if (func_0027D470(a, 0, &arr, 0)) {
        i = 0;
        h = D_00370AE0[0];
        if (arr[1] != 0) {
            do {
                func_002678F0(h, func_0011A5B8(arr, i) << 10);
                i++;
            } while (i < (u32)arr[1]);
        }
    }
    return 1;
}

extern "C" int CFunc_ClearSoundBank(int a) {
    int x;
    if (func_0027D1F8(a, 0, &x, 0)) {
        func_00267910(D_00370AE0_gp, x);
    }
    return 1;
}

extern "C" int CFunc_RemoveAllSoundBanks(void) {
    func_00267A00(D_00370AE0[0]);
    return 1;
}

extern "C" int CFunc_RemoveSoundGroup(int a) {
    int x = 0;
    if (func_0027D870(a, 0, &x, 0)) {
        int g = func_00266E08(x);
        if (g) {
            return func_00266CE0(g);
        }
    }
    return 0;
}

extern "C" int CFunc_ClearSoundGroups(void) {
    func_00266D20();
    return 1;
}

extern "C" int CFunc_SetDefaultSoundPriority(int a) {
    int x = 50;
    func_0027D1F8(a, 0, &x, 0);
    func_00267758(D_00370AE0[0], x);
    return 1;
}

extern "C" int CFunc_SetSfxReverb(int a) {
    f32 x = 0.0f;
    int y = 0;
    func_0027D268(a, 0, &x, 0);
    if (100.0f < x) {
        x = 100.0f;
    }
    func_0027D1F8(a, 0x6835B854, &y, 0);
    f32 xx = x;
    int yy = y;
    int hh = D_00370AE0[0];
    int r = func_0027DF00(a, 0xF16FB852);
    func_00268330_f(hh, xx, yy, r);
    return 1;
}

extern "C" int CFunc_SetSfxDropoff(int a) {
    f32 x = 25.0f;
    func_0027D268(a, 0, &x, 0);
    if (x <= 0.0f) {
        return 0;
    }
    func_00267310(D_00370AE0[0], x * 12.0f);
    return 1;
}

extern "C" int CFunc_SetSfxVolume(int a) {
    f32 x = 100.0f;
    func_0027D268(a, 0, &x, 0);
    func_00268228(D_00370AE0[0], x);
    return 1;
}

extern "C" int CFunc_SetGlobalPitchModulation(int a) {
    f32 x = 1.0f;
    func_0027D268(a, 0, &x, 0);
    f32 xx = x;
    int hh = D_00370AE0[0];
    int y = func_0027DF00(a, 0xC406CE6F);
    int r = func_0027DF00(a, 0x6A3BD54B);
    func_002682B8_f(hh, xx, y, r);
    return 1;
}

extern "C" int CFunc_SetMusicVolume(int a) {
    f32 x = 100.0f;
    func_0027D268(a, 0, &x, 0);
    func_0026C940(x);
    return 1;
}

extern "C" int CFunc_SetMusicStreamVolume(int a) {
    f32 x = 100.0f;
    func_0027D268(a, 0, &x, 0);
    func_0026C9E8(x);
    return 1;
}

extern "C" int CFunc_StopMusic(void) {
    func_0026AE70();
    return 1;
}

extern "C" int CFunc_PauseMusic(int a) {
    int x = 1;
    func_0027D1F8(a, 0, &x, 0);
    func_0026C7A8(x);
    return 1;
}

extern "C" int CFunc_PauseStream(int a) {
    int x = 1;
    func_0027D1F8(a, 0, &x, 0);
    return 0;
}

extern "C" s32 CFunc_PauseStreamNum(int arg0) {
    int x = 0;
    int y = 1;
    func_0027D1F8(arg0, 0, &x, 0);
    func_0027D1F8(arg0, 0x28656D12, &y, 0);
    return 1;
}

extern "C" int CFunc_PauseStreamID(int arg0) {
    int v = 1;
    int out = 0;
    func_0027D870(arg0, 0, &out, 0);
    int o = out;
    func_0027D1F8(arg0, 0x28656D12, &v, 0);
    if (o) {
        func_002E7C58(o, v != 0);
    }
    return 1;
}

extern "C" int CFunc_LoadMusicHeader(int a) {
    int x = 0;
    func_0027D188(a, 0, &x, 0);
    if (x) {
        func_00119490(D_00368A38, D_00368A38->unk1E0);
        int r = func_0026DC20(x);
        func_001194B8(D_00368A38_lui[0]);
        return r;
    }
    return 0;
}

extern "C" int CFunc_LoadStreamHeader(int a) {
    int x = 0;
    func_0027D188(a, 0, &x, 0);
    if (x) {
        func_00119490(D_00368A38, D_00368A38->unk1E0);
        func_001194B8(D_00368A38);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_AddMusicTrack);

extern "C" s32 CFunc_ChangeTrackState(int arg0) {
    int out = 0;
    func_0027D1F8(arg0, 0, &out, 0);
    func_0026D6D0(out, func_0027DF00(arg0, 0xD443A2BC), 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_TrackEnabled);

extern "C" void CFunc_MusicIsPaused(void) {
    func_0026C870();
}

extern "C" int CFunc_ClearMusicTrackList(int a) {
    func_0026CBE8(func_0027DF00(a, 0x389129E4) == 0);
    return 1;
}

extern "C" int CFunc_SkipMusicTrack(void) {
    func_0026CC48();
    return 1;
}

extern "C" int CFunc_SetMusicMode(int a) {
    int x = 1;
    func_0027D1F8(a, 0, &x, 0);
    func_0026DBD8(x == 0);
    return 1;
}

extern "C" int CFunc_SetRandomMode(int a) {
    int x = 1;
    func_0027D1F8(a, 0, &x, 0);
    func_0026CC80(x);
    return 1;
}

extern "C" int CFunc_SetMusicLooping(int a) {
    int x = 1;
    func_0027D1F8(a, 0, &x, 0);
    func_0026CCD8(x != 0);
    return 1;
}

struct SGCT {
    char pad0[0x20];
    int unk20;
};
extern "C" s32 CFunc_GetCurrentTrack(int arg0, SGCT *arg1) {
    func_0027C160(arg1->unk20, 0x8D02705D, func_0026DE20());
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_GetValueFromVolume);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadSoundStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadChecksumStream);

extern "C" void CFunc_PreLoadStreamDone(int a) {
    int x;
    func_0027D870(a, 0, &x, 1);
    func_002E7010(x);
}

extern "C" int CFunc_IsSoundStreamPlaying(int a) {
    int x;
    func_0027D870(a, 0, &x, 1);
    if (x == 0) {
        return 0;
    }
    return !func_002E7B60(x);
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StartPreLoadedStream);
