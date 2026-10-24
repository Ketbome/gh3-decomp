// cflags: -funroll-loops
#include "common.h"

extern "C" {
extern int D_00369798;
int func_002B5888(int);
void func_00144FC0(int, int, int, int, int);
int func_00119610(int, int);
void func_001194B8(int);
void func_00119490(int, int);
int Heap_Alloc(int, int, int, int);
extern int D_003720E8;
int func_0027DF00(int, u32);
void Heap_Free(int, int);
extern int D_003720E4;
extern int D_00368A38;
extern int D_00368744;
int func_002B5C08(int, int);
int func_002B5CA8(int, int);
int func_0027D870(int, int, int *, int);
int func_002B5BC8(int, int);
int func_0027D1F8(int, int, int *, int);
int func_002DCA40(int);
void func_0027C160(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DumpNoteMappings);

GP_DATA(D_003720E8);
extern "C" int CFunc_TextOutputStart(void) {
    if (D_00368744 != 0) {
        int h = D_00368A38;
        func_00119490(h, func_00119610(h, 0x3B));
    }
    int m = Heap_Alloc(D_00368A38, 0x200000, 1, 0);
    D_003720E4 = m;
    D_003720E8 = m;
    if (D_00368744 != 0) {
        func_001194B8(D_00368A38);
    }
    return 1;
}

extern "C" int func_0027D188(int, int, int *, int);
extern "C" void func_0030B550(int, char *, int);
extern "C" char D_003720F0[];
extern "C" int CFunc_TextOutputEnd_2(int, int) asm("CFunc_TextOutputEnd");

GP_DATA(D_003720E4);
extern "C" int CFunc_TextOutput(int px, int b) {
    register int params asm("$16") = px;
    int first = D_003720E4 == 0;
    int n;
    if (first) CFunc_TextOutputStart();
    func_0027D188(params, 0xC4745838, &n, 1);
    func_0030B550(D_003720E8, D_003720F0, n);
    register char *t0 asm("$3") = (char *)D_003720E8;
    register char *q asm("$4");
    if (*t0) {
        q = t0;
        for (;;) {
            char *n2 = q + 1;
            D_003720E8 = (int)n2;
            if (q[1] == 0) break;
            q = n2;
        }
    }
    char *p = (char *)D_003720E8;
    *p = 0xD;
    p++;
    D_003720E8 = (int)p;
    *p = 0xA;
    D_003720E8 = (int)(p + 1);
    p[1] = 0;
    if (first) CFunc_TextOutputEnd_2(params, b);
    return 1;
}

extern "C" int CFunc_TextOutputEnd(int params) {
    char buf[0x200];
    if (func_0027DF00(params, 0xC844F1E2)) {
        char *p = (char *)D_003720E4;
        while (*p) {
            char *o = buf;
            while (*p != '\n') {
                *o = *p;
                p++;
                o++;
            }
            *o = *p;
            o[1] = 0;
            p++;
        }
    }
    if (D_003720E4)
        Heap_Free(D_00368A38, D_003720E4);
    D_003720E8 = 0;
    D_003720E4 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_ApplyBossBattleGemMisses);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DebugTransform);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", func_002BF900);

extern "C" {
int func_0027D378(int, u32, f32 *, f32 *, int);
int func_0027D268(int, u32, f32 *, int);
int func_0027CC30(int, u32, int, f32 *);
int func_002763E0(int, int);
void func_0027F1E0(int, int, int);
void func_002BF900(int, int, f32, f32, f32, f32, f32, f32, f32, int, f32, int, int, int, f32);
}
extern "C" int CFunc_CreateGemMover(int params) {
    int a;
    int b;
    f32 f0, f1;
    f32 f2, f3;
    f32 f4;
    f32 f5;
    f32 f6;
    int c;
    int d;
    int e;
    f32 w;
    int g;
    f32 f7;
    if (func_0027D870(params, 0xA1DC81F9, &a, 0)) {
        int *pb = &b;
        b = 0;
        func_0027D378(params, 0x734D06F5, &f0, &f1, 1);
        func_0027D378(params, 0x09A7DC2E, &f2, &f3, 1);
        func_0027D268(params, 0x66ECC08A, &f4, 1);
        func_0027D268(params, 0x62269D7E, &f5, 1);
        func_0027D268(params, 0xA6F5352F, &f6, 1);
        func_0027D870(params, 0x7321A8D6, &c, 1);
        func_0027D1F8(params, 0x67E6859A, &d, 1);
        func_0027D870(params, 0x99A9B716, pb, 0);
        func_0027D870(params, 0x1BFF0C3D, &e, 1);
        int h = func_002763E0(e, 1);
        int ok = func_0027CC30(h, 0x6FF009E0, 2, &w);
        f32 v = w;
        if (!ok) {
            func_0027F1E0(h, 0, 1);
            v = 0.0f;
        }
        int flag = 0;
        g = 0;
        f7 = 0;
        if (func_0027D870(params, 0x385D13E4, &g, 0)) {
            flag = 1;
            func_0027D268(params, 0xFE82614D, &f7, 1);
        }
        func_002BF900(a, flag, f0, f1, f2, f3, f4, f5, f6, g, f7, c, d - 1, b, v);
        return 1;
    }
    return 0;
}

static inline void Gem_Pick(int &v, int arg0) {
    int b;
    if (func_0027D870(arg0, 0x385D13E4, &b, 0)) {
        v = b;
    }
}

extern "C" int CFunc_DestroyGem(int arg0) {
    int a;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0)) {
        if (func_002B5888(a)) {
            int v = a;
            Gem_Pick(v, arg0);
            func_00144FC0(D_00369798, v, 1, 0, 0);
            return 1;
        }
        return 0;
    }
    return 0;
}


extern "C" int CFunc_MakeDeadWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5BC8(a, b - 1);
    }
    return 0;
}

extern "C" int CFunc_MakeStarWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5C08(a, b - 1);
    }
    return 0;
}

extern "C" int CFunc_MakeNormalWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5CA8(a, b - 1);
    }
    return 0;
}

struct SGIHBI {
    char pad0[0x20];
    int unk20;
};
extern "C" s32 CFunc_GetInputHandlerBotIndex(int arg0, SGIHBI *arg1) {
    int out;
    func_0027D1F8(arg0, 0x67E6859A, &out, 1);
    func_0027C160(arg1->unk20, 0xB30D9965, func_002DCA40(out - 1));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_UpdateGemMovers);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", func_002C07E8);
