#include "common.h"

struct S1F0010_M {
    char pad0[0x30];
    void* unk30;
};

struct S1F0010 {
    char pad0[0x1FC];
    s32 unk1FC;
    char pad200[0x10];
    S1F0010_M* unk210;
    struct { char pad[0x1C]; s32 unk1C; }* unk214;
    char pad218[0x4C];
    s32 unk264;
};

struct S1F0A30 {
    char pad0[0x18];
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13();
    virtual int v14(void* b, s32 c, s32 d);
};

struct S1EFA78_R {
    char pad0[0x30];
    u32 unk30;
};

typedef int TI128 __attribute__((mode(TI)));

struct S1F0EF8_M {
    u8 unk0;
    char pad1;
    u16 unk2;
    u8* unk4;
    char pad8[0x28];
};

struct Arr1EF {
    s32 unk0;
    u32 count;
    void** data;
    void* Get(u32 i) { return count == 1 ? (void*)data : data[i]; }
    u32 GetSize() { return count; }
};

extern "C" {
void func_001EE608(void*, int, int, int);
void func_001EF5F0(void*, int);
void func_001F23E8(void*);
void func_001EDD30(void*);
void func_001F1D08(void*);
void func_001571F8(void*, int);
void func_001EF548(void*, void*);
void func_00160DE8(void*, u32);
s32 func_0027D268(void*, u32, f32*, int);
bool func_0027D870(void*, u32, s32*, int);
s32 func_0027D1F8(void*, u32, s32*, int);
void func_001EF688(void*, f32);
s32 func_001EE6F8(void*, s32);
void func_00157220(void*, s32, int);
void func_001619D8(void*, s32);
void func_0014E098(void*, char*);
void func_00113528(char*);
u32 func_00115028(char*);
void* func_00160170(void*, u32, int, int, int, int);
void func_0015F4B8(void*, s32);
S1EFA78_R* func_0015D2E8(s32, int);
S1EFA78_R* func_0015DB00(s32);
u32 func_00161E78(void*);
void func_00161EE0(void*, u32);
s32 func_0027D188(void*, u32, s32*, int);
s32 func_00160C58(void*, s32, s32, s32);
void func_00161DD8(void*, u8, u8, u8, u8);
int func_00157100(void*, u8*);
void func_00160FF8(void*, s32, s32, f32, f32);
s32 func_0027D400(void*, u32, s32*, int);
void func_00134700(void*);
void func_00134938(void*, s32, int);
void func_00134748(void*, int);
void func_001EE718(void*, void*);
f32 func_00160698(void*, s32, void*, s32);
void func_0027C1F8(void*, u32, f32);
bool func_0027DF00(void*, u32);
int func_00157190(void*, s32, u8*);
void func_0014DB38(f32, f32, f32, f32*, f32*, f32*);
void func_00160E80(void*, u32, f32, f32, f32);
s32 func_0027D2D8(void*, u32, TI128*, int);
void func_001F2440(void*, TI128, f32);
void func_001F1F20(void*);
extern void* D_00372580[] __attribute__((section(".sdata")));
void* func_001CA590(void*, u16);
s32 func_001CC090(void*);
void func_00296AF0(void*);
s32 func_002DF898(void*);
void* func_001CA020(void*, s32);
void func_0029D238(void*, S1F0EF8_M*);
s32 func_0027D470(void*, u32, Arr1EF**, int);
s32 func_00160A90(void*, s32, s32, s32);
void func_0010F690(void*);
s32 func_001EED78(void*, void*, s32, s32, s32, s32, s32, f32, f32);
void func_0027C448(void*, u32, s32);
extern s32 D_00372B58;
extern s32 D_0036C798;
}

extern "C" void func_001EF6D0(S1F0010* p) {
    func_001F1D08(p);
    p->unk264 = 0;
}

extern "C" void func_001EF6F8(S1F0010* p, int a, void* b, s32* c) {
    char buf[0x200];
    func_0014E098(b, buf);
    func_00113528(buf);
    void* r = func_00160170(p->unk210, func_00115028(buf), a, 0, 0, 1);
    if (r) {
        func_0015F4B8(r, *c);
    }
}

extern "C" void func_001EF780(void* p, int a) {
    func_001EE608(p, a, 1, 1);
}

extern "C" s32 func_001EF7A0(void* p) {
    func_001EF5F0(p, 1);
    return 1;
}

extern "C" s32 func_001EF7C0(void* p) {
    func_001EF5F0(p, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF7E0);

extern "C" s32 func_001EF898(S1F0010* p, void* a) {
    if (!p->unk210) {
        return 0;
    }
    s32 v;
    TI128 vec;
    f32 f;
    if (func_0027D870(a, 0xAF124177, &v, 0)) {
        vec = *(TI128*)((char*)p + 0x220);
    } else {
        func_0027D2D8(a, 0xAF124177, &vec, 0);
    }
    f = 0.3f;
    func_0027D268(a, 0xF3777D3B, &f, 0);
    func_001F2440(p, vec, f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF950);

extern "C" s32 func_001EF9A0(S1F0010* p, void* a) {
    s32 v = 0;
    S1EFA78_R* r;
    if (func_0027D870(a, 0x9FD29151, &v, 0)) {
        r = func_0015D2E8(v, 1);
    } else {
        s32 w = 0;
        func_0027D1F8(a, 0x9FD29151, &w, 0);
        r = func_0015DB00(w);
    }
    if (func_0027DF00(a, 0xFEDCE703)) {
        func_00161EE0(p->unk210, r->unk30);
    } else {
        func_00161EE0(p->unk210, func_00161E78(p->unk210) | r->unk30);
    }
    return 1;
}

extern "C" s32 func_001EFA78(S1F0010* p, void* a) {
    s32 v = 0;
    S1EFA78_R* r;
    if (func_0027D870(a, 0x9FD29151, &v, 0)) {
        r = func_0015D2E8(v, 1);
    } else {
        s32 w = 0;
        func_0027D1F8(a, 0x9FD29151, &w, 0);
        r = func_0015DB00(w);
    }
    func_00161EE0(p->unk210, (func_00161E78(p->unk210) & ~r->unk30) & 0xFFFF);
    return 1;
}

extern "C" s32 func_001EFB28(S1F0010* p) {
    if (p->unk210) {
        func_00160DE8(p->unk210, 0xC4E78E22);
    }
    return 1;
}

extern "C" s32 func_001EFB58(S1F0010* p, void* a) {
    if (p->unk210) {
        s32 hi;
        s32 si;
        s32 vi;
        f32 h;
        f32 s;
        f32 v;
        bool ok = func_0027D1F8(a, 0x6E94F918, &hi, 0) && func_0027D1F8(a, 0xE4F130F4, &si, 0)
            && func_0027D1F8(a, 0x949BC47B, &vi, 0);
        if (ok) {
            func_0014DB38(hi, si * 0.01f, vi * 0.01f, &h, &s, &v);
            func_00160E80(p->unk210, 0xC4E78E22, h, s, v);
        }
    }
    return 1;
}

extern "C" s32 func_001EFC60(S1F0010* p, void* a) {
    if (p->unk210) {
        s32 c[3];
        bool ok = func_0027D1F8(a, 0x93F60062, &c[0], 0) && func_0027D1F8(a, 0xFE2BE489, &c[1], 0)
            && func_0027D1F8(a, 0x8E411006, &c[2], 0);
        if (ok) {
            func_00161DD8(p->unk210, c[0], c[1], c[2], 0xFF);
        }
    }
    return 1;
}

extern "C" s32 func_001EFD18(S1F0010* p, void* a) {
    if (p->unk210) {
        s32 s[3];
        s[0] = 0xC4E78E22;
        func_0027D268(a, 0xA6F5352F, (f32*)&s[1], 1);
        func_0027D870(a, 0x83418A6A, &s[2], 1);
        func_0027D870(a, 0xE7308C1F, &s[0], 0);
    }
    return 1;
}

extern "C" bool func_001EFD98(S1F0010* p, void* a) {
    Arr1EF* arr;
    s32 w;
    s32 v;
    s32 r = 0;
    if (func_0027D470(a, 0x5EF31148, &arr, 0)) {
        for (u32 i = 0; i < arr->GetSize(); i++) {
            void* e = arr->Get(i);
            func_0027D188(e, 0x9FBBDB72, &w, 1);
            func_0027D188(e, 0x7799D66C, &v, 1);
            s32 k = 0xC4E78E22;
            func_0027D870(e, 0xA01371B1, &k, 0);
            if (p->unk210 && func_00160A90(p->unk210, k, w, v)) {
                r = 1;
            }
        }
    } else {
        func_0027D188(a, 0x9FBBDB72, &w, 1);
        func_0027D188(a, 0x7799D66C, &v, 1);
        s32 k = 0xC4E78E22;
        func_0027D870(a, 0xA01371B1, &k, 0);
        if (p->unk210) {
            r = func_00160A90(p->unk210, k, w, v) != 0;
        }
    }
    return r != 0;
}

extern "C" bool func_001EFF40(S1F0010* p, void* a) {
    s32 s[3];
    s32 r = 0;
    s[0] = 0;
    func_0027D188(a, 0x9FBBDB72, &s[1], 1);
    func_0027D870(a, 0x7799D66C, &s[0], 1);
    s[2] = 0xC4E78E22;
    func_0027D870(a, 0xA01371B1, &s[2], 0);
    if (p->unk210) {
        r = func_00160C58(p->unk210, s[2], s[1], s[0]);
    }
    return r != 0;
}

extern "C" s32 func_001EFFF0(void* p) {
    func_001F23E8(p);
    return 1;
}

extern "C" bool func_001F0010(S1F0010* p) {
    return p->unk210->unk30 != 0;
}

extern "C" s32 func_001F0020() {
    return 1;
}

extern "C" s32 func_001F0028(S1F0010* p) {
    func_001571F8(p->unk210->unk30, 1);
    return 1;
}

extern "C" s32 func_001F0050(S1F0010* p) {
    func_001571F8(p->unk210->unk30, 0);
    return 1;
}

extern "C" s32 func_001F0078(S1F0010* p, void* a) {
    s32 v;
    func_0027D1F8(a, 0x7F8C98FE, &v, 0);
    func_00157220(p->unk210->unk30, v, 1);
    return 1;
}

extern "C" s32 func_001F00C8(S1F0010* p, void* a) {
    s32 v;
    func_0027D1F8(a, 0x7F8C98FE, &v, 0);
    func_00157220(p->unk210->unk30, v, 0);
    return 1;
}

extern "C" s32 func_001F0118(S1F0010* p, void* a) {
    u8 col[4];
    s32 c[3];
    func_0027D1F8(a, 0x93F60062, &c[0], 0);
    func_0027D1F8(a, 0xFE2BE489, &c[1], 0);
    func_0027D1F8(a, 0x8E411006, &c[2], 0);
    u8 r = c[0];
    u32 g = c[1];
    u32 b = c[2];
    col[0] = r;
    col[1] = g;
    col[2] = b;
    col[3] = 0x80;
    func_00157100(p->unk210->unk30, col);
    func_001571F8(p->unk210->unk30, 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F01D0);

extern "C" s32 func_001F0360(S1F0010* p, void* a) {
    u8 col[4];
    s32 c[4];
    func_0027D1F8(a, 0x7F8C98FE, &c[0], 0);
    func_0027D1F8(a, 0x93F60062, &c[1], 0);
    func_0027D1F8(a, 0xFE2BE489, &c[2], 0);
    func_0027D1F8(a, 0x8E411006, &c[3], 0);
    u8 r = c[1];
    u32 g = c[2];
    u32 b = c[3];
    col[0] = r;
    col[1] = g;
    col[2] = b;
    col[3] = 0x80;
    func_00157190(p->unk210->unk30, c[0], col);
    func_00157220(p->unk210->unk30, c[0], 1);
    return 1;
}

extern "C" s32 func_001F0438(S1F0010* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0x83418A6A, &v, 0);
    s32 id = v;
    f32 x;
    f32 y;
    s32 w = 0;
    func_0027D268(a, 0x0D9295C1, &x, 0);
    func_0027D268(a, 0x949BC47B, &y, 0);
    func_0027D1F8(a, 0x318F2BDB, &w, 0);
    func_00160FF8(p->unk210, id, w, x, y);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F04F8);

extern "C" bool func_001F07A8(S1F0010* p) {
    p->unk1FC = 1;
    return true;
}

extern "C" s32 func_001F07B8(S1F0010* p) {
    p->unk1FC = 0;
    return 1;
}

extern "C" s32 func_001F07C8(void* p) {
    func_001EDD30(p);
    return 1;
}

extern "C" int func_001F07E8(S1F0010* p, void* s) {
    s32 a = 0;
    bool missing = !func_0027D870(s, 0xA1DC81F9, &a, 0);
    if (missing) func_0027D870(s, 0, &a, 1);
    s32 b;
    func_0027D188(s, 0x286A8D26, &b, 1);
    s32 c = 0;
    missing = !func_0027D870(s, 0x7E4813A7, &c, 0);
    if (missing) c = D_00372B58;
    s32 d = 0;
    func_0027D870(s, 0x32EC33F0, &d, 0);
    D_0036C798 = d;
    func_001EF6F8(p, a, (void*)b, &c);
    return 1;
}

static inline bool Has1F08D8(void* a, u32 k, s32* v) { return func_0027D870(a, k, v, 0); }
extern "C" int func_001F08D8(S1F0010* p, void* s) {
    s32 a = 0;
    bool missing = !func_0027D870(s, 0xA1DC81F9, &a, 0);
    if (missing) func_0027D870(s, 0, &a, 1);
    func_001619D8(p->unk210, a);
    return 1;
}

extern "C" s32 func_001F0950(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    func_001EF780(p, v);
    return 1;
}

extern "C" s32 func_001F0998(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    func_001EE608(p, v, 0, 1);
    return 1;
}

extern "C" bool func_001F09E8(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    return func_001EE6F8(p, v) != 0;
}

extern "C" s32 func_001F0A30(S1F0010* p, void* a) {
    if (p->unk210) {
        char buf[0x80];
        s32 n;
        func_0027D400(a, 0x456D28D1, &n, 1);
        s32 b = 0;
        func_0027D870(a, 0x299EE352, &b, 0);
        s32 c = 0;
        func_0027D400(a, 0x7031F10C, &c, 0);
        func_00134700(buf);
        func_00134938(buf, n, 1);
        ((S1F0A30*)p)->v14(buf, c, b);
        func_00134748(buf, 2);
    }
    return 1;
}

extern "C" s32 func_001F0B00(void* p, void* a) {
    f32 v;
    func_0027D268(a, 0, &v, 1);
    func_001EF688(p, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0B48);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0B70);

static inline void Set1F0EF8(u8* d, s32 v) { *d = v; }
extern "C" s32 func_001F0EF8(char* p) {
    func_001F1F20(p + 0x40);
    func_001F1F20(p + 0xD4);
    func_001F1F20(p + 0x168);
    void* g = D_00372580[0];
    void* r = func_001CA590(g, (*(s32**)(p + 0xC))[0xB]);
    if (r && func_001CC090(r)) {
        S1F0EF8_M m;
        u8 d;
        func_00296AF0(&m);
        void* x = func_001CA020(g, func_002DF898(r));
        Set1F0EF8(&d, (*(s32**)(p + 0xC))[0xB]);
        m.unk4 = &d;
        m.unk2 = 1;
        m.unk0 = 0xB7;
        func_0029D238(x, &m);
    }
    return 1;
}

extern "C" s32 func_001F0FC8(S1F0010* p, void* a, void** b) {
    TI128 pair[2];
    s32 v = 0;
    func_0027D870(a, 0x7B66ECC5, &v, 0);
    void* s = 0;
    if (func_0027D400(a, 0x2EEB4B09, (s32*)&s, 0)) {
        func_0010F690(&pair[0]);
        func_0010F690(&pair[1]);
        func_0027D2D8(s, 0x6086AA70, &pair[0], 1);
        func_0027D2D8(s, 0xFF03CC4E, &pair[1], 1);
        v = func_001EED78(p, pair, v, 0, 0, 0, 0, 1.0f, 0.0f);
        if (v) {
            func_0027C448(b[8], 0xED615AF5, v);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F10D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F16C0);
