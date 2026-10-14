#include "common.h"

struct S2CF4F0 {
    char pad0[0x20];
    int unk20;
};

struct S2CDD30 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    u8 unk10;
    char pad11[0xB];
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
};

extern "C" {
int func_00275F08(u32, int);
int func_0027CC30(int, u32, int, int *);
void func_0027F1E0(int, int, int);
void func_002CDD30(S2CDD30 *);
s32 func_00289C88(s32, s32);
char *func_00289C80(s32);
void CFunc_SpawnScriptNow(int, int);
void func_00113250(int);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027AC90(int);
void func_0027C448(int, u32, int);
void func_0027C898(int, u32, int);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCF8);

extern "C" void func_002CDD30(S2CDD30 *p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk24 = 0;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    p->unk38 = 0;
    p->unk3C = 0;
    p->unk40 = 0;
}

extern "C" s32 CFunc_check_for_star_power_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x44);
    func_002CDD30((S2CDD30 *)func_00289C80(arg1));
    return 1;
}

extern "C" s32 CFunc_check_for_star_power_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

extern "C" void func_002CDDD0(u32 key, S2CDD30 *p, int arg) {
    int ok = 0;
    if (key == 0xF8B928FD || key == 0xA572DCB2)
        ok = 1;
    if (ok) {
        int e = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(e, 0, 0x38C4BE6D);
        int c = func_0027AA70(func_001287F0(8, 1));
        func_0027C898(e, 0x7031F10C, c);
        int t = p->unk8;
        int v;
        int w;
        if (func_0027CC30(t, 0x67E6859A, 1, &v) == 0) {
            func_0027F1E0(t, 0, 1);
            w = 0;
        } else {
            w = v;
        }
        if (w == 1) {
            func_0027C448(c, 0x1BFF0C3D, 0x57D6374F);
            CFunc_SpawnScriptNow(e, arg);
            if (func_00275F08(0x8737EEDA, 0)) {
                func_0027AC90(e);
                func_0027C448(e, 0, 0xF010A127);
                CFunc_SpawnScriptNow(e, arg);
            }
        } else {
            func_0027C448(c, 0x1BFF0C3D, 0xD95930AC);
            CFunc_SpawnScriptNow(e, arg);
        }
        if (e) {
            func_0027AC90(e);
            func_00113250(e);
        }
    }
}

extern "C" int *func_002CDCC0_p(int) asm("func_002CDCC0");

extern "C" void func_002CDF70(u32 key, S2CF4F0 *s) {
    if (key == 0x39940016) {
        s->unk20 = 0;
        return;
    }
    int *p = func_002CDCC0_p(0x84517E);
    int t = *(int *)((char *)s + 8);
    int v;
    int w;
    if (func_0027CC30(t, 0x5F1B348F, 1, &v) == 0) {
        func_0027F1E0(t, 0, 1);
        w = 0;
    } else {
        w = v;
    }
    if (w == 0) {
        *p = 0x64;
        s->unk20 = 0;
    } else if (w == 1) {
        if (*p != 0) {
            *p = *p - 1;
            s->unk20 = 0;
        } else {
            s->unk20 = 1;
        }
    } else if (w == 2) {
        s->unk20 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_check_for_star_power_CFunc);

extern "C" s32 CFunc_GuitarEvent_Note_Window_Open_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x8);
    *(s32 *)(func_00289C80(arg1) + 0x0) = 0;
    return 1;
}

extern "C" s32 CFunc_GuitarEvent_Note_Window_Open_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_GuitarEvent_Note_Window_Open_CFunc);

extern "C" s32 CFunc_strum_iterator_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x28);
    *(s32 *)(func_00289C80(arg1) + 0x24) = 0;
    return 1;
}

extern "C" s32 CFunc_strum_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_strum_iterator_CFunc);

extern "C" s32 CFunc_wait_for_correct_frame_cfunc(int arg0, S2CF4F0 *arg1) {
    int out;
    int t = func_00275F08(0x500D9785, 1);
    int h = arg1->unk20;
    int v;
    int r;
    if (func_0027CC30(h, 0x67E6859A, 1, &out) == 0) {
        func_0027F1E0(h, 0, 1);
        v = 0;
    } else {
        v = out;
    }
    if (v == 1) {
        if (t == v) {
            return 1;
        }
        goto no;
    }
    r = 1;
    if (t != 0) {
no:
        r = 0;
    }
    return r;
}

extern "C" s32 CFunc_rock_meter_star_power_on_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x20);
    *(s32 *)(func_00289C80(arg1) + 0x1C) = 0;
    return 1;
}

extern "C" s32 CFunc_rock_meter_star_power_on_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_rock_meter_star_power_on_CFunc);
