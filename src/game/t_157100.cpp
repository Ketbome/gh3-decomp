#include "common.h"

struct S_00157538 { char pad0[0x4]; int unk4; void* unk8; };

struct S_00157558 { int unk0; int unk4; void* unk8; };

struct VE_001571F8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001571F8 { char pad0[0x20]; VE_001571F8* unk20; };

struct VE_00157220 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct S_00157220 { char pad0[0x20]; VE_00157220* unk20; };

struct VE_00157710 { s16 unk0; s16 unk2; int (*unk4)(void*, int); };
struct S_00157710 { char pad0[0x8]; VE_00157710* unk8; };

struct VE_00157738 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int); };
struct S_00157738 { char pad0[0x8]; VE_00157738* unk8; };

struct VE_00157760 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int); };
struct S_00157760 { char pad0[0x8]; VE_00157760* unk8; };

struct VE_00157788 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_00157788 { char pad0[0x8]; VE_00157788* unk8; };

extern "C" {
void func_0030B550(char*, const char*, const char*);
extern char D_00369D40[];
extern char D_0033CD90[];
int strlen(char*);
u32 CrcFromPathLowercase(char*);
void func_00182E50(int, int);
extern int D_00369CDC;
void func_00183460(float);
void func_00183520(void);
extern float D_00373260;
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_001834E0(void);
void func_00157400(void);
extern int D_00369CD8;
void func_00183498(void);
void func_00183678(void);
void func_00157420(int, int);
extern u8 D_0033CE40[];
}

struct S_00157248 { char pad0[0x18]; int unk18; };

struct S_001571F0 { char pad0[0x4]; int unk4; };
struct S_00157258 { int unk0; };
struct S_00157260 { int unk0; };

struct VE_157100 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct VF_157100 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct V_157100 { char pad0[0x10]; VE_157100 unk10; char pad18[0x30]; VF_157100 unk48; };
struct S_157100 { char pad0[0x20]; V_157100* unk20; };

extern "C" int func_00157100(S_157100* self) {
    int r = self->unk20->unk10.unk4((char*)self + self->unk20->unk10.unk0);
    self->unk20->unk48.unk4((char*)self + self->unk20->unk48.unk0, 1, 0);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157160);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157168);

struct V_157190 { char pad0[0x20]; VE_157100 unk20; char pad28[0x20]; VF_157100 unk48; };
struct S_157190 { char pad0[0x20]; V_157190* unk20; };

extern "C" int func_00157190(S_157190* self) {
    int r = self->unk20->unk20.unk4((char*)self + self->unk20->unk20.unk0);
    self->unk20->unk48.unk4((char*)self + self->unk20->unk48.unk0, 0, 1);
    return r;
}

extern "C" void func_001571F0(S_001571F0* self, int v) {
    self->unk4 = v;
}

extern "C" void func_001571F8(S_001571F8* self, int a1) {
    VE_001571F8* e = &self->unk20[10];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" void func_00157220(S_00157220* self, int a1, int a2) {
    VE_00157220* e = &self->unk20[11];
    e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157248(S_00157248* self, int v) {
    self->unk18 = v;
    return 1;
}

extern "C" void func_00157258(S_00157258* self, int v) {
    self->unk0 = v;
}

extern "C" int func_00157260(S_00157260* self) {
    return self->unk0;
}

extern "C" int func_00157268(void) {
    return 0;
}

extern "C" int func_00157270(void) {
    return 0;
}

extern "C" int func_00157278(void) {
    return 0;
}

struct S157280 { u8 unk0; u8 unk1; u8 unk2; u8 unk3; };

extern "C" S157280* func_00157280(S157280* self) {
    self->unk0 = 0;
    self->unk1 = 0;
    self->unk2 = 0;
    self->unk3 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157298);

extern "C" S157280* func_001572D0(S157280* self) {
    self->unk0 = 0;
    self->unk1 = 0;
    self->unk2 = 0;
    self->unk3 = 0;
    return self;
}

extern "C" void func_001572E8(void) {
}

extern "C" void func_001572F0(void) {
}

extern "C" void func_001572F8(void) {
}

extern "C" int func_00157300(void) {
    return 0;
}

extern "C" int func_00157308(void) {
    return 0;
}

extern "C" void func_00157310(void) {
}

GP_DATA(D_00369CD8);
extern "C" void func_00157318(int a, int b) {
    func_00157400();
    func_00182E50(a, b);
    if (!(b & 3)) {
        D_00369CDC = 1;
    } else {
        D_00369CDC = 0;
    }
    D_00369CD8 = 1;
}

extern "C" void func_00157378(float f) {
    if (!(f <= 0.0f)) {
        D_00373260 = f;
        func_00183520();
        func_00183460(f);
    }
}

extern "C" void func_001573B8(void) {
    func_00183498();
}

GP_DATA(D_00369CD8);
extern "C" void func_001573D8(void) {
    func_001834E0();
    func_00157400();
    D_00369CD8 = 0;
}

extern "C" void func_00157400(void) {
    func_00183678();
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157420);

extern "C" void func_001574A0(void) {
    func_00157420(1, 0xFFFF);
}

extern "C" u32 func_001574C0(char* s) {
    int n = strlen(s);
    if (n > 0 && s[n - 1] != '\\' && s[n - 1] != '/') {
        while (--n > 0 && s[n - 1] != '\\' && s[n - 1] != '/') {
        }
    }
    return CrcFromPathLowercase(s + n);
}

extern "C" S_00157538* func_00157538(S_00157538* self) {
    self->unk8 = D_0033CE40;
    self->unk4 = *(u16*)&self->unk4;
    return self;
}

extern "C" S_00157558* func_00157558(S_00157558* self, S_00157558* o) {
    self->unk8 = D_0033CE40;
    self->unk0 = o->unk0;
    self->unk4 = o->unk4;
    return self;
}

struct S157580 { char pad0[8]; void* unk8; };

extern "C" void func_00157580(S157580* self, int flags) {
    self->unk8 = D_0033CE40;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

struct VE157 { s16 delta; s16 unk2; int (*fn)(void*, char*, int, int); };
struct V157 { char pad0[0x28]; VE157 unk28; };
struct S1575C0 { u32 unk0; char pad4[4]; V157* unk8; };

extern "C" int func_001575C0(S1575C0* self, char* name, int a, int b) {
    char buf[0x200];
    func_0030B550(buf, D_00369D40, name);
    if (a) {
        if (name[0] == '.' && name[1] == '.' && name[2] == '/') {
            func_0030B550(buf, D_00369D40, name + 3);
        } else {
            func_0030B550(buf, D_0033CD90, name);
        }
    }
    u32 h = func_001574C0(buf);
    V157* v = self->unk8;
    self->unk0 = h;
    return v->unk28.fn((char*)self + v->unk28.delta, buf, a, b);
}

struct VE_1576A8 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int, int); };
struct S_1576A8 { int unk0; int unk4; VE_1576A8* unk8; };

extern "C" void func_001576A8(S_1576A8* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    self->unk0 = a3;
    VE_1576A8* e = &self->unk8[6];
    e->unk4((char*)self + e->unk0, a1, a2, a4, a5, a6);
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001576E0);

extern "C" int func_00157710(S_00157710* self, int a1) {
    VE_00157710* e = &self->unk8[8];
    return e->unk4((char*)self + e->unk0, a1);
}

extern "C" int func_00157738(S_00157738* self, int a1, int a2) {
    VE_00157738* e = &self->unk8[12];
    return e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157760(S_00157760* self, int a1, int a2) {
    VE_00157760* e = &self->unk8[13];
    return e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" int func_00157788(S_00157788* self) {
    VE_00157788* e = &self->unk8[14];
    return e->unk4((char*)self + e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_001577B0);

struct S_001577B8 { char pad0[8]; char* unk8; };
extern "C" void func_00159AB8(int, int, int, int, int, int, int);
static inline int VC0_001577B8(S_001577B8* o, int off) {
    char* vt = o->unk8;
    short d = *(short*)(vt + off);
    int (*f)(void*) = *(int (**)(void*))(vt + off + 4);
    return f((char*)o + d);
}
extern "C" int func_001577B8(S_001577B8* a, S_001577B8* b, int c) {
    int r0 = VC0_001577B8(b, 0x20);
    int r1 = VC0_001577B8(b, 0xD0);
    int r2 = VC0_001577B8(b, 0xD8);
    int r3 = VC0_001577B8(a, 0x18);
    int r4 = VC0_001577B8(a, 0xD0);
    int r5 = VC0_001577B8(a, 0xD8);
    func_00159AB8(r0, r1, r2, r3, r4, r5, 0x20);
    if (c) {
        if ((u32)VC0_001577B8(a, 0xE0) < 9) {
            char* vt = a->unk8;
            short d = *(short*)(vt + 0x120);
            int (*f)(void*, void*, int) = *(int (**)(void*, void*, int))(vt + 0x124);
            f((char*)a + d, b, c);
        }
    }
    return 1;
}

struct S_00157908 { char pad0[8]; char* unk8; };
extern "C" {
void func_00119490(int, int);
void func_001194B8(int);
int func_00119610(int, int);
void func_00159E08(int, int, int, int, int, float, float);
void func_0030A2F4(int, int, int);
void* memset(void*, int, unsigned int);
void* Heap_Alloc(int, int, int, int);
void Heap_Free(int, void*);
}
static inline int VC0_00157908(S_00157908* o, int off) {
    char* vt = o->unk8;
    short d = *(short*)(vt + off);
    int (*f)(void*) = *(int (**)(void*))(vt + off + 4);
    return f((char*)o + d);
}
extern "C" int func_00157908(S_00157908* self, float a, float b) {
    int w = VC0_00157908(self, 0xD0);
    int h = VC0_00157908(self, 0xD8);
    int heap = D_00368A38[0];
    func_00119490(heap, func_00119610(heap, 0));
    int size = w * h * 4;
    void* buf = Heap_Alloc(D_00368A38[0], size, 1, 0);
    memset(buf, 0, size);
    func_001194B8(D_00368A38[0]);
    func_00159E08(VC0_00157908(self, 0x18), w, h, (int)buf, 0x20, a, b);
    func_0030A2F4(VC0_00157908(self, 0x18), (int)buf, size);
    if (buf) {
        Heap_Free(D_00368A38[0], buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00157A58);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158070);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158578);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158760);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158768);

INCLUDE_ASM("asm/nonmatchings/game/t_157100", func_00158A30);
