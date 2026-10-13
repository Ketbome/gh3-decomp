#include "common.h"

struct S0025F910 {
    char pad[0x8];
    int unk8;
    char pad1[0x4];
    int unk10;
    char pad2[0x44];
    int unk58;
};

struct S25E_Buf {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct S25E_Obj {
    char pad0[0x18];
    int unk18;
    int unk1C[1];
};

struct S25E_P {
    char pad0[8];
    int *unk8;
};

extern "C" {
int func_0028DAB8(int);
S25E_P *func_0014E878(void);
S25E_P *func_0014E850(int);
int CrcFromPathLowercase(int);
void func_0022ADD0(S25E_Obj *, S25E_Buf *);
void func_001342E8(S25E_Buf *, int);
void func_0022ABE8(S25E_Buf *, S25E_Obj *, int, int, int, int, int, int);
bool func_0022B168(S25E_Obj *, int);
int func_0027D188(int, int, int *, int);
extern S25E_Obj *D_0036F658;
void func_00134340(S25E_Buf *);
void func_0022B0D0(S25E_Buf *, int, int, int);
int func_0027D870(int, int, int *, int);
extern S0025F910* D_00371028[] __attribute__((section(".sdata")));
extern int D_00371038[] __attribute__((section(".sdata")));
extern S0025F910* D_00371228[] __attribute__((section(".sdata")));
extern int D_00371238[] __attribute__((section(".sdata")));
extern S0025F910* D_00371088[] __attribute__((section(".sdata")));
extern int D_00371098[] __attribute__((section(".sdata")));
extern S0025F910* D_00370FA8[] __attribute__((section(".sdata")));
extern int D_00370FB8[] __attribute__((section(".sdata")));
extern S0025F910* D_00370FC0[] __attribute__((section(".sdata")));
extern int D_00370FD0[] __attribute__((section(".sdata")));
extern S0025F910* D_00371288[] __attribute__((section(".sdata")));
extern int D_00371298[] __attribute__((section(".sdata")));
extern S0025F910* D_00371470[] __attribute__((section(".sdata")));
extern int D_00371480[] __attribute__((section(".sdata")));
extern S0025F910* D_003690D8[] __attribute__((section(".sdata")));
extern int D_003690E8[] __attribute__((section(".sdata")));
extern S0025F910* D_003691F8[] __attribute__((section(".sdata")));
extern int D_00369208[] __attribute__((section(".sdata")));
extern S0025F910* D_003692A0[] __attribute__((section(".sdata")));
extern int D_003692B0[] __attribute__((section(".sdata")));
extern S0025F910* D_0036A790[] __attribute__((section(".sdata")));
extern int D_0036A7A0[] __attribute__((section(".sdata")));
extern S0025F910* D_0036A6E0[] __attribute__((section(".sdata")));
extern int D_0036A6F0[] __attribute__((section(".sdata")));
extern S0025F910* D_0036D540[] __attribute__((section(".sdata")));
extern int D_0036D550[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", func_0025E580);

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", func_0025E878);

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", func_0025EB48);

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", func_0025EC38);

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", func_0025F900);

extern "C" int func_0025F910(void) {
    return D_00371028[D_00371038[0]]->unk8;
}

extern "C" int func_0025F938(void) {
    return D_00371028[D_00371038[0]]->unk10;
}

extern "C" int func_0025F960(void) {
    return D_00371028[D_00371038[0]]->unk58;
}

extern "C" int func_0025F988(void) {
    return D_00371228[D_00371238[0]]->unk8;
}

extern "C" int func_0025F9B0(void) {
    return D_00371228[D_00371238[0]]->unk10;
}

extern "C" int func_0025F9D8(void) {
    return D_00371228[D_00371238[0]]->unk58;
}

extern "C" int func_0025FA00(void) {
    return D_00371088[D_00371098[0]]->unk10;
}

extern "C" int func_0025FA28(void) {
    return D_00371088[D_00371098[0]]->unk8;
}

extern "C" int func_0025FA50(void) {
    return D_00371088[D_00371098[0]]->unk58;
}

extern "C" int func_0025FA78(void) {
    return D_00370FA8[D_00370FB8[0]]->unk10;
}

extern "C" int func_0025FAA0(void) {
    return D_00370FA8[D_00370FB8[0]]->unk8;
}

extern "C" int func_0025FAC8(void) {
    return D_00370FA8[D_00370FB8[0]]->unk58;
}

extern "C" int func_0025FAF0(void) {
    return D_00370FC0[D_00370FD0[0]]->unk10;
}

extern "C" int func_0025FB18(void) {
    return D_00370FC0[D_00370FD0[0]]->unk8;
}

extern "C" int func_0025FB40(void) {
    return D_00370FC0[D_00370FD0[0]]->unk58;
}

extern "C" int func_0025FB68(void) {
    return D_00371288[D_00371298[0]]->unk10;
}

extern "C" int func_0025FB90(void) {
    return D_00371288[D_00371298[0]]->unk8;
}

extern "C" int func_0025FBB8(void) {
    return D_00371288[D_00371298[0]]->unk58;
}

extern "C" int func_0025FBE0(void) {
    return D_00371470[D_00371480[0]]->unk10;
}

extern "C" int func_0025FC08(void) {
    return D_00371470[D_00371480[0]]->unk8;
}

extern "C" int func_0025FC30(void) {
    return D_00371470[D_00371480[0]]->unk58;
}

extern "C" int func_0025FC58(void) {
    return D_003690D8[D_003690E8[0]]->unk10;
}

extern "C" int func_0025FC80(void) {
    return D_003690D8[D_003690E8[0]]->unk8;
}

extern "C" int func_0025FCA8(void) {
    return D_003690D8[D_003690E8[0]]->unk58;
}

extern "C" int func_0025FCD0(void) {
    return D_003691F8[D_00369208[0]]->unk10;
}

extern "C" int func_0025FCF8(void) {
    return D_003691F8[D_00369208[0]]->unk8;
}

extern "C" int func_0025FD20(void) {
    return D_003691F8[D_00369208[0]]->unk58;
}

extern "C" int func_0025FD48(void) {
    return D_003692A0[D_003692B0[0]]->unk10;
}

extern "C" int func_0025FD70(void) {
    return D_003692A0[D_003692B0[0]]->unk8;
}

extern "C" int func_0025FD98(void) {
    return D_003692A0[D_003692B0[0]]->unk58;
}

extern "C" int func_0025FDC0(void) {
    return D_0036A790[D_0036A7A0[0]]->unk10;
}

extern "C" int func_0025FDE8(void) {
    return D_0036A790[D_0036A7A0[0]]->unk8;
}

extern "C" int func_0025FE10(void) {
    return D_0036A790[D_0036A7A0[0]]->unk58;
}

extern "C" int func_0025FE38(void) {
    return D_0036A6E0[D_0036A6F0[0]]->unk10;
}

extern "C" int func_0025FE60(void) {
    return D_0036A6E0[D_0036A6F0[0]]->unk8;
}

extern "C" int func_0025FE88(void) {
    return D_0036A6E0[D_0036A6F0[0]]->unk58;
}

extern "C" int func_0025FEB0(void) {
    return D_0036D540[D_0036D550[0]]->unk10;
}

extern "C" int func_0025FED8(void) {
    return D_0036D540[D_0036D550[0]]->unk8;
}

extern "C" int func_0025FF00(void) {
    return D_0036D540[D_0036D550[0]]->unk58;
}

extern "C" int CFunc_UnloadAnim(int arg0) {
    S25E_Buf a;
    S25E_Buf b;
    int path = 0;
    int name;
    S25E_Obj *o = D_0036F658;
    func_0027D188(arg0, 0xA1DC81F9, &path, 1);
    name = 0;
    func_0027D870(arg0, 0x4D20D794, &name, 1);
    a.unk0 = 0;
    a.unk4 = 0;
    a.unk8 = 0;
    if (name != 0) {
        func_0022B0D0(&b, (int)o, name, 0);
        func_001342E8(&a, b.unk0);
        func_00134340(&b);
    } else {
        func_0022B0D0(&b, (int)o, CrcFromPathLowercase(path), 0);
        func_001342E8(&a, b.unk0);
        func_00134340(&b);
    }
    if (a.unk0) {
        func_0022ADD0(o, &a);
    }
    func_00134340(&a);
    return 1;
}

extern "C" int CFunc_LoadAsset(void) {
    return 0;
}

extern "C" int CFunc_UnloadAsset(void) {
    return 0;
}

extern "C" int CFunc_LoadAnim(int arg0) {
    S25E_Buf buf;
    int v;
    int w;
    int *pv = &v;
    S25E_Obj *obj = D_0036F658;
    int r = 0;
    int n = obj->unk18 + 1;
    obj->unk18 = n;
    ((int *)obj)[7 + n] = 0;
    v = 0;
    func_0027D188(arg0, 0xA1DC81F9, &w, 0);
    func_0027D870(arg0, 0x4D20D794, pv, 1);
    bool missing = !func_0022B168(obj, v);
    if (missing) {
        func_0022ABE8(&buf, obj, w, 6, v, 0, 0, 0);
        r = 1;
        func_00134340(&buf);
    }
    obj->unk18--;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", CFunc_ReloadAnim);

extern "C" int CFunc_LoadSkeleton(void) {
    return 0;
}

extern "C" bool CFunc_IsAssetLoaded(int arg0) {
    S25E_Buf buf;
    int a = 0;
    int b;
    func_0027D870(arg0, 0xA1DC81F9, &a, 1);
    int x = a;
    b = 0;
    func_0027D870(arg0, 0x91CC92C8, &b, 0);
    func_0022B0D0(&buf, (int)D_0036F658, x + b, 0);
    bool r = buf.unk0 != 0;
    func_00134340(&buf);
    return r;
}

extern "C" int CFunc_LoadTerrainSounds(void) {
    return 0;
}

extern "C" int CFunc_SetScenePermanent(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25E580", CFunc_LoadScene);

extern "C" int CFunc_UnloadScene(int arg0) {
    S25E_Buf a;
    S25E_Buf b;
    int path = 0;
    int r = 0;
    S25E_P *p;
    S25E_Obj *o;
    func_0027D188(arg0, 0x26861025, &path, 0);
    if (path) {
        p = func_0014E850(path);
        if (p) {
            r = 1;
        } else {
            p = func_0014E878();
        }
        o = D_0036F658;
        if (p) {
            int *q = p->unk8;
            func_0022B0D0(&a, (int)o, func_0028DAB8(path), 1);
            func_0022ADD0(o, &a);
            if (q) {
                func_0022B0D0(&b, (int)o, *q, 1);
                func_001342E8(&a, b.unk0);
                func_00134340(&b);
                func_0022ADD0(o, &a);
            }
            func_00134340(&a);
        }
    }
    return r;
}
