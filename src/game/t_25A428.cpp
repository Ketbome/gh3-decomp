#include "common.h"

struct S25AA28 {
    char padC4[0xC4];
    int unkC4;
};

struct S25A_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" {
extern int D_00371488;
bool func_0027D870(int, u32, void *, int);
bool func_0027D400(int, u32, void *, int);
bool func_0027D470(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
int func_0027D188(int, u32, void *, int);
int func_0027CC30(int, u32, int, void *);
bool func_0027DF00(int, u32);
int func_0027DD88(int, u32);
void func_0027C160(int, u32, int);
void func_0028CE90(u32);
void func_0028CF18(void *);
void func_0028DC28(int);
void func_0028E220(void *, u32, int);
void func_0028D668(u32);
void func_0028D720(u32);
int func_00113900(char *);
int func_0014F748(void);
void func_0014F740(int);
extern u32 D_00372E70;
void func_0014F7B8(void);
int func_0025AA28(int, int, int);
extern int D_00370540;
int func_0028DAD8(void);
int func_00289E08(int);
int func_0028E6D0(int);
int func_0028CE18(int);
int func_001EB2B0(void);
void func_0014F750(int, u32);
extern int D_003715D4[] __attribute__((section(".sdata")));
void func_00291900(int);
int func_0028D1D8(int, int, int, int, int, int, int, int, int, int);
void func_00289ED8(int, void *);
int func_0028C200(int);
void func_00289B40(int, int);
}

extern "C" int CFunc_OnExitRun(int params, void *script) {
    u32 a = 0;
    func_0027D870(params, 0, &a, 0);
    int b = 0;
    func_0027D400(params, 0x7031F10C, &b, 0);
    func_0028E220(script, a, b);
    return 1;
}

extern "C" int CFunc_StopAllScripts(void) {
    func_0028DAD8();
    return 1;
}

GP_DATA(D_00370540);
extern "C" int CFunc_FirstTimeThisIsCalled(void) {
    if (D_00370540 != 0) {
        D_00370540 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_StringToCharArray);

extern "C" {
unsigned int strlen(const char *);
char *strcpy(char *, const char *);
void func_0030A554(char *, char *);
int func_0030B550(char *, const char *, ...);
void func_0027C028(int, u32, char *);
extern char D_003704B8[];
extern char D_00370548[];
}

extern "C" int CFunc_AppendSuffix(int params, S25A_Script *script) {
    char buf[112];
    char suf[32];
    char *path = D_003704B8;
    int len;
    int cap;
    int num;
    u32 key;
    func_0027D188(params, 0xC4745838, &path, 0);
    len = strlen(path);
    strcpy(buf, path);
    cap = 15;
    func_0027D1F8(params, 0xA6931595, &cap, 0);
    num = 1;
    func_0027D1F8(params, 0x4A4F7821, &num, 0);
    func_0030B550(suf, D_00370548, num);
    int sl = strlen(suf);
    if (cap < len + sl) {
        buf[cap - sl] = 0;
    }
    func_0030A554(buf, suf);
    func_0027D870(params, 0x50060694, &key, 0);
    func_0027C028(script->unk20, key, buf);
    return 1;
}

extern "C" int CFunc_IsObjectScript(int a, int b) {
    return func_00289E08(b) != 0;
}

extern "C" int CFunc_StopRendering_C(void) {
    func_0014F750(0, 0xB8CA16A5);
    return 1;
}

extern "C" int CFunc_StartRendering_C(void) {
    func_0014F750(1, 0xB8CA16A5);
    return 1;
}

extern "C" void CFunc_RenderingEnabled(void) {
    func_0014F7B8();
}

extern "C" int CFunc_Toggle2d(int params) {
    int old = func_0014F748();
    if (func_0027DD88(params, 0xF649D637)) {
        func_0014F740(1);
    } else if (func_0027DD88(params, 0xD443A2BC)) {
        func_0014F740(0);
    } else {
        func_0014F740(func_0014F748() == 0);
    }
    return old;
}

extern "C" int CFunc_SetScriptWarningLevel(int a) {
    u32 v = 0x806FFF30;
    int lvl;
    func_0027D870(a, 0x651533EC, &v, 0);
    switch (v) {
    case 0x806FFF30:
        D_00371488 = 0;
        break;
    case 0xD6454EFA:
        lvl = 1;
        goto store;
    case 0x4E10B054:
        lvl = 2;
    store:
        D_00371488 = lvl;
        break;
    }
    return 1;
}

extern "C" int func_0025AA28(int params, int sc, int flag) {
    S25AA28 *s = (S25AA28 *)sc;
    int a = 0;
    func_0027D870(params, 0, &a, 0);
    int b = 0;
    func_0027D400(params, 0x7031F10C, &b, 0);
    int c = 0;
    func_0027D870(params, 0x40C698AF, &c, 0);
    int d = 0;
    func_0027D870(params, 0x86068BD9, &d, 0);
    int e = 0;
    func_0027D400(params, 0x0DD85BDA, &e, 0);
    int f = 0;
    int g = 0;
    func_0027D1F8(params, 0x20209C31, &f, 0);
    func_0027D1F8(params, 0x23627FD7, &g, 0);
    int h = 0;
    func_0027D1F8(params, 0x2EBFF4BC, &h, 0);
    int u = s->unkC4;
    int r = func_0028D1D8(a, b, d, e, u, c, f != 0, g != 0, h != 0, 0);
    if (r) {
        if (!func_0027DF00(params, 0x01917DF2)) {
            func_00289ED8(r, s);
        }
        if (flag && !func_0028C200(r)) {
            func_00289B40(r, 3);
        }
    }
    return 1;
}

extern "C" int CFunc_SpawnScript(int params, int script) {
    int f = 0;
    func_0027D1F8(params, 0xEE67888A, &f, 0);
    return func_0025AA28(params, script, f != 0);
}

extern "C" void CFunc_SpawnScriptNow(int a, int b) {
    func_0025AA28(a, b, 1);
}

extern "C" void CFunc_SpawnScriptLater(int a, int b) {
    func_0025AA28(a, b, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnedScriptNoRepeatFor);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnInstanceLimits);

extern "C" int CFunc_KillSpawnedScript(int params) {
    u32 id;
    if (func_0027D870(params, 0xA1DC81F9, &id, 0)) {
        func_0028D668(id);
        return 1;
    }
    u32 n;
    if (func_0027D870(params, 0x40C698AF, &n, 0)) {
        func_0028D720(n);
        return 1;
    }
    return 1;
}

extern "C" int CFunc_UnBlockInterruptedScript(int a, int b) {
    func_0028E6D0(b);
    return 1;
}

extern "C" int CFunc_PauseSpawnedScripts(int params, void *script) {
    func_0028CE18(1);
    func_0028CF18(script);
    return 1;
}

extern "C" int CFunc_UnPauseSpawnedScripts(void) {
    func_0028CE18(0);
    return 1;
}

extern "C" int CFunc_UnPauseSpawnedScript(int params) {
    u32 id;
    func_0027D870(params, 0, &id, 1);
    func_0028CE90(id);
    return 1;
}

extern "C" int CFunc_DumpScripts(int params) {
    if (!func_0027DF00(params, 0x202ED1B4)) {
        func_0028DC28(func_0027DF00(params, 0x2AB71EEF));
    }
    return 1;
}

extern "C" int CFunc_DumpProxims(void) {
    func_001EB2B0();
    return 1;
}

extern "C" int CFunc_DumpProximTriggers(void) {
    return 0;
}

struct S25B238 {
    u32 unk0;
    char pad4[4];
    int unk8;
};
extern "C" {
void func_0027EDE0(int, u32, int);
void func_0027EE08(int, u32, float);
void func_0027EE30(int, u32, int);
char *StrDupHeap5(char *);
void func_0027EDB8(int, u32, char *);
int func_001287F0(int, int);
int func_0027AA98(int, int);
void func_0027EED0(int, u32, int);
int func_00138790(int, int);
int func_0027E698(int);
int func_0027A9B8(int, int, int);
void func_0027EEF8(int, u32, int);
}
extern "C" void func_0025B238(int a, u32 k, S25B238 *c) {
    switch ((c->unk0 >> 9) & 0x7F) {
    case 1:
        func_0027EDE0(a, k, c->unk8);
        break;
    case 2:
        func_0027EE08(a, k, *(float *)&c->unk8);
        break;
    case 13:
        func_0027EE30(a, k, c->unk8);
        break;
    case 3:
        func_0027EDB8(a, k, StrDupHeap5((char *)c->unk8));
        break;
    case 10: {
        int v = func_0027AA98(func_001287F0(8, 1), c->unk8);
        func_0027EED0(a, k, v);
        break;
    }
    case 12: {
        int w = func_0027E698(func_00138790(0xC, 1));
        func_0027A9B8(w, c->unk8, 0);
        func_0027EEF8(a, k, w);
        break;
    }
    }
}

struct S25A_PushArr {
    char pad0[4];
    int unk4;
};
struct S25A_PushL {
    u32 key;
    int a;
    int arr;
};
extern "C" {
S25B238 *func_0027B300(int, S25B238 *);
int func_0027AA70(int);
void func_0027C898(int, u32, int);
void func_0027EB78(int, int);
void func_0027E760(int, int, int);
void func_0027C740(int, u32, int);
bool func_0027D470_b(int, u32, void *, int) asm("func_0027D470");
bool func_0027D400_b(int, u32, void *, int) asm("func_0027D400");
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_Push);

struct S25A_Arr {
    char pad0[2];
    u8 type;
    char pad3;
    int unk4;
    int unk8;
};
struct S25A_PL {
    u32 key;
    int a;
    S25A_Arr *obj;
};
extern "C" {
void func_0027C1F8(int, u32, f32);
void func_0027C028(int, u32, char *);
void func_0027C448(int, u32, int);
void func_0027C7D0(int, u32, int);
void func_0027C678(int, u32, int);
f32 func_0027EFA0(S25A_Arr *, int);
char *func_0027EF60(S25A_Arr *, int);
void func_002797A8(S25A_Arr *, int);
void func_0027E820(S25A_Arr *, int);
void func_0027ACF8(int, u32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_Pop);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_CanPop);

extern "C" int CFunc_StringLength(int params, S25A_Script *script) {
    int n = 0;
    int tmp;
    if (func_0027CC30(params, 0x61414D56, 3, &tmp)) {
        char *s = 0;
        func_0027D188(params, 0x61414D56, &s, 0);
        n = func_00113900(s);
    }
    func_0027C160(script->unk20, 0xCC91E842, n);
    return 1;
}

struct S25A_RArr {
    int unk0;
    u32 unk4;
    int unk8;
};

struct S25A_Req {
    S25A_RArr *unk0;
    u32 unk4;
    int unk8;
};

extern "C" {
void func_0027B4D0(void *, void *, void *, int);
extern char func_0025C6F8[];
}

extern "C" int CFunc_RequireParams(int params, S25A_Script *script) {
    int sp10;
    S25A_RArr *arr = 0;
    if (func_0027D870(params, 0x90FEC815, &sp10, 0)) {
        func_0027D400(script->unk20, sp10, &arr, 1);
    } else if ((func_0027D400(params, 0x90FEC815, &arr, 0) ^ 1) != 0) {
        arr = (S25A_RArr *)script->unk20;
    }
    if (arr == 0) return 0;
    S25A_Req r;
    r.unk0 = 0;
    r.unk4 = 0;
    r.unk8 = 0;
    if ((func_0027D470(params, 0, &r, 0) ^ 1) != 0) {
        return arr->unk4 == 0;
    }
    int c = 0;
    func_0027B4D0(arr, func_0025C6F8, &r, 1);
    if (func_0027DF00(params, 0x1F26CCAF)) c = r.unk8 != 0;
    if (c) return 0;
    int d = 0;
    if (func_0027DF00(params, 0xC4E78E22)) d = r.unk4 < r.unk0->unk4;
    if (d) return 0;
    return r.unk4 != 0;
}

extern "C" {
extern int D_00368A38;
void *Heap_Alloc(int, int, int, int);
void Heap_Free(int, void *);
void memset(void *, int, int);
void func_00113960(char *, int, char *);
void func_0027C028(int, u32, char *);
}

extern "C" int CFunc_ShortenUIString(int params, S25A_Script *script) {
    char *s = 0;
    func_0027D188(params, 0x96875C0F, &s, 0);
    int r = 0;
    if (s) {
        int n = 0x14;
        func_0027D1F8(params, 0xE2DB8458, &n, 0);
        char *buf = (char *)Heap_Alloc(D_00368A38, n + 4, 1, 0);
        memset(buf, 0, n + 4);
        func_00113960(buf, n, s);
        if (n < func_00113900(s)) {
            buf[n] = 0x2E;
            buf[n + 1] = 0x2E;
            buf[n + 2] = 0x2E;
        }
        func_0027C028(script->unk20, 0xE8EE8638, buf);
        if (buf) Heap_Free(D_00368A38, buf);
        r = 1;
    }
    return r;
}

extern "C" {
void func_00113930(char *, char *);
extern char D_003704B8[];
bool func_0027D188_b(int, u32, void *, int) asm("func_0027D188");
}
struct S25A_SW {
    u32 key;
    char *s;
};

extern "C" int CFunc_StringRemoveTrailingWhitespace(int params, S25A_Script *script) {
    S25A_SW l;
    l.s = D_003704B8;
    l.key = 0x99DB757C;
    bool miss = !func_0027D188_b(params, 0x61414D56, &l.s, 0);
    if (miss) {
        func_0027D870(params, 0x5B058376, &l.key, 1);
        bool miss2 = !func_0027D188_b(script->unk20, l.key, &l.s, 1);
        if (miss2) return 0;
    }
    int n = func_00113900(l.s);
    char *buf = (char *)Heap_Alloc(D_00368A38, n + 1, 1, 0);
    func_00113930(buf, l.s);
    for (int i = n - 1; i >= 0 && buf[i] == 0x20; i--) {
        buf[i] = 0;
    }
    func_0027C028(script->unk20, l.key, buf);
    if (buf) Heap_Free(D_00368A38, buf);
    return 1;
}

extern "C" int CFunc_ScriptCacheDeleteZeroUsage(void) {
    func_00291900(D_003715D4[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BC10);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BD80);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025C1C0);
