#include "common.h"

struct VEntry227 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S227 {
    VEntry227* unk0;
    char pad4[0x28];
    int unk2C;
    char pad30[0x380];
    int unk3B0;
    char pad3B4[0xD4];
    int unk488;
};

struct S227b {
    char pad0[0xC];
    int unkC;
    int unk10;
};

extern "C" {
void func_001DF898(int);
void func_0014EAE8(int, int);
void func_002285E8(int, int);
void func_001CEBA8(S227*, int*);
void func_00228820(S227*, int*);
void func_00228868(int, int);
int func_00289E08(int);
int func_001D83D0(void*, void*, void*);
extern void* D_0036D3B0[] __attribute__((section(".sdata")));
int func_00229EB8(void*);
int func_00229F38(void*);
void func_0022A1D8(void*);
void func_0011A558(u32, int, int);
void func_0011A568(void);
int func_001C7760(int);
int func_001C8258(int);
extern int D_0036CDB4;
extern int D_00372580;
void func_0027B678(int, void*, void*);
void* func_001287F0(int, int);
int func_00223C28(int, void*);
int func_0027AA98(void*, int);
void func_0027ABB0(int, int);
void func_0027AC90(int);
void func_00113250(int);
void func_001DF900(int);
void func_001E0600(int);
char* func_0014E1B8(int);
void func_00152D30(char*, int);
int func_0027DF00(int, u32);
}

extern "C" void func_00227C68(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00227CA8(void* self, int a) {
    func_001DF898(a);
}

extern "C" void func_00227CC8(int a, int b, int c, int d) {
    int v[2];
    if (d) v[1] = func_00289E08(d);
    else v[1] = 0;
    v[0] = c;
    func_001D83D0(D_0036D3B0[0], (void*)func_00228820, v);
}

struct V227 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int);
};

extern "C" void func_00227D20(S227* self, int s, S227b* b) {
    func_0011A558(0xB7B3BD86, 0, 0);
    char* t = func_0014E1B8(*(int*)b);
    if (t) {
        func_00152D30(t, 0);
        if (func_0027DF00(s, 0x393282E4)) {
            V227* o = *(V227**)(t + 0x10);
            if (o) o->v9(1);
        }
    }
    func_0011A568();
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int, S227b*))e->fn)((char*)self + e->delta, s, b);
    }
}

extern "C" void func_00227E00(int self, int obj) {
    int s = 0;
    int v;
    if (func_00223C28(obj, &v)) {
        s = func_0027AA98(func_001287F0(8, 1), v);
        func_0027ABB0(s, obj);
        obj = s;
    }
    func_0011A558(0xCD60B52E, 0, 0);
    func_001DF900(obj);
    func_0011A568();
    if (s) {
        func_0027AC90(s);
        func_00113250(s);
    }
}

extern "C" void func_00227EA8(int a, int b, int c, int d) {
    int v[2];
    if (d) v[1] = func_00289E08(d);
    else v[1] = 0;
    v[0] = c;
    func_001D83D0(D_0036D3B0[0], (void*)func_00228820, v);
}

extern "C" void func_00227F00(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00227F40(void) {
}

extern "C" void func_00227F48(void* self, int a, int b) {
    func_0014EAE8(b, 0);
}

extern "C" void func_00227F68(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00227FA8(int self, int obj) {
    int s = 0;
    int v;
    if (func_00223C28(obj, &v)) {
        s = func_0027AA98(func_001287F0(8, 1), v);
        func_0027ABB0(s, obj);
        obj = s;
    }
    func_0011A558(0xE2FE1B6D, 0, 0);
    func_001E0600(obj);
    func_0011A568();
    if (s) {
        func_0027AC90(s);
        func_00113250(s);
    }
}

extern "C" void func_00228050(int a, int b, int c, int d) {
    int v[2];
    if (d) v[1] = func_00289E08(d);
    else v[1] = 0;
    v[0] = c;
    func_001D83D0(D_0036D3B0[0], (void*)func_00228820, v);
}

extern "C" void func_002280A8(S227* self, int a, S227b* b) {
    if (!b->unk10) {
        if (!func_001C7760(D_0036CDB4) || func_001C8258(D_00372580)) {
            func_0011A558(0x5CAD44FA, 0, 0);
            func_0011A568();
        }
        if (b->unkC) {
            VEntry227* e = &self->unk0[2];
            ((void (*)(void*, int, S227b*))e->fn)((char*)self + e->delta, a, b);
        }
    }
}

extern "C" void func_00228148(void) {
}

extern "C" void func_00228150(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228158);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228278);

extern "C" void func_00228360(void) {
}

extern "C" void func_00228368(char* p, int a) {
    *(int*)(p + 0xC) = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 4) = 0;
    *(int*)(p + 0x14) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x34) = 0;
    *(int*)(p + 0x1C) = 0;
    *(int*)(p + 0x20) = 0;
    p[0x2C] = 1;
    p[0x2D] = 1;
    func_0027B678(a, (void*)func_00228868, p);
    if ((*(int*)(p + 0x30) || *(int*)(p + 0x34)) && *(int*)(p + 0xC) == 0) {
        int v = 0;
        if (p[0x2C]) v = p[0x2D] != 0;
        *(int*)(p + 0xC) = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228408);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002285E8);

extern "C" void func_00228820(S227* self, int* b) {
    int v = *b;
    if (self->unk2C == v) {
        func_001CEBA8(self, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228850);

extern "C" void func_00228860(void) {
}

extern "C" void func_00228868(int a, int b) {
    func_002285E8(b, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228890);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229538);

extern "C" int func_00229718(char* p) {
    int r = 0;
    switch (*(int*)(p + 0x3B0)) {
    case 0:
        if (func_00229EB8(p)) *(int*)(p + 0x3B0) = 1;
        else r = 1;
        break;
    case 1:
        if (func_00229F38(p)) {
            func_0022A1D8(p);
            *(int*)(p + 0x3B0) = 0;
            *(int*)(p + 0x3C4) = 0;
        }
        break;
    }
    return r;
}

extern "C" int func_002297A8(S227* self) {
    if (self->unk488 || self->unk3B0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002297D0);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229820);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002299B0);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229BA0);
