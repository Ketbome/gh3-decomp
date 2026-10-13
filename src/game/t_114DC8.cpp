#include "common.h"

struct S_00116610 { char pad0[0x1C]; void (*unk1C)(void); };

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct SA114_V {
    char pad0[0xC];
    VEntry* unkC;
};

struct SA114_D {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x4];
    int unkC;
    char pad10[0x4];
    int unk14;
};

struct SA114_A {
    char pad0[0x4];
    int unk4;
    void* unk8;
    char padC[0x14];
    SA114_V* unk20;
};

extern "C" {
int func_0030AA88(char*);
char* func_0030A970(char*, char*);
int func_0030E650(char*, char*);
void func_00113FB8(void*);
extern u8 D_00337FE8[];
extern int D_00368768;
extern int D_00368770;
extern int D_00368534;
extern u32 D_0032A080[];
void func_002F3BD0(void);
void func_002F3B80(void);
u32 CrcFromPathLowercase(const char*);
void func_001165C0(void);
void func_001162B8(void);
void func_00116178(int, int);
void func_00119400(int, int);
extern int D_00368A38;
struct H_00116410 { char pad0[0x1E0]; int unk1E0; };
extern H_00116410* D_00368A38_p __asm__("D_00368A38");
extern char* D_00370EE0;
void func_00119490(void*, int);
void func_001194B8(int);
void func_0011A558(u32, int, int);
void func_0011A568(void);
void* func_00113D20(u32);
void* func_00113EA8(void*, int);
void func_00114958(char*, void*);
extern u8 D_00337FC8[];
extern int D_00372AA0;
extern int D_00372AA4;
extern int D_00372AA8;
extern int D_00372AAC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00114DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115020);

extern "C" u32 CrcFromPathLowercase(const char* s) {
    u32 crc;
    char c;
    const char* p;
    if (!s) {
        return 0;
    }
    p = s;
    crc = 0xFFFFFFFF;
    for (c = *p++; c != 0; c = *p++) {
        if (c >= 'A' && c <= 'Z') {
            c += 0x20;
        }
        if (c == '/') {
            c = '\\';
        }
        crc = D_0032A080[(crc ^ c) & 0xFF] ^ ((crc >> 8) & 0xFFFFFF);
    }
    return crc;
}

extern "C" u32 func_001150B8(const char* s) {
    return CrcFromPathLowercase(s);
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001150D8);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115170);

extern "C" void func_001153C8(void) {
    if (D_00372AAC) func_00119400(D_00368A38, D_00372AAC);
    if (D_00372AA8) func_00119400(D_00368A38, D_00372AA8);
    if (D_00372AA4) func_00119400(D_00368A38, D_00372AA4);
    if (D_00372AA0) func_00119400(D_00368A38, D_00372AA0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115438);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115660);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115850);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116170);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116178);

extern "C" void func_00116260(void) {
    func_00116178(1, 0xFFFF);
}

extern "C" void func_00116280(void) {
}

GP_DATA(D_00368534);
extern "C" void func_00116288(void) {
    if (D_00368534 == 0) {
        func_002F3B80();
    }
    D_00368534++;
}

extern "C" void func_001162B8(void) {
    if (--D_00368534 == 0) {
        func_002F3BD0();
    }
}

extern "C" void* func_001162E8(void* self) {
    func_00116280();
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116310);

extern "C" void func_00116340(void) {
    func_001162B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116360);

extern "C" void func_001163B8(SA114_V* o) {
    if (o) {
        VEntry* e = &o->unkC[1];
        ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
    }
}

extern "C" void func_001163F0(void) {
}

extern "C" int func_001163F8(void) {
    return 0;
}

extern "C" void func_00116400(void) {
}

extern "C" void func_00116408(void) {
}

struct C_00116410 { u8 r, g, b, a; };
struct S_00116410 { void* unk0; int unk4; void* unk8; void* unkC; };
struct N_00116410 { char pad0[0x18]; void* unk18; void* unk1C; void* unk20; };
extern "C" void func_00116590(SA114_A*);

extern "C" S_00116410* func_00116410(S_00116410* self) {
    void* d = D_00337FE8;
    void* f = (void*)func_001165C0;
    self->unkC = d;
    self->unk8 = f;
    self->unk0 = 0;
    self->unk4 = 0;
    func_00119490(D_00368A38_p, D_00368A38_p->unk1E0);
    func_0011A558(0xFC26B5B9, 0, 0);
    N_00116410* o = (N_00116410*)func_00113D20(0x24);
    void* fn = (void*)func_00116590;
    func_00113EA8(o, 0);
    o->unk1C = fn;
    o->unk20 = self;
    o->unk18 = D_00337FC8;
    C_00116410 c;
    self->unk0 = o;
    c.r = 0xFF;
    c.g = 0xFF;
    c.b = 0xFF;
    c.a = 0xFF;
    func_0011A568();
    func_001194B8(D_00368A38);
    func_00114958(D_00370EE0 + 0xA0, self->unk0);
    return self;
}

struct VE_1164F8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_1164F8 { char pad0[0x10]; VE_1164F8 unk10; };
struct O_1164F8 { char pad0[0x18]; V_1164F8* unk18; };
struct S_1164F8 { O_1164F8* unk0; char pad4[8]; void* unkC; };

extern "C" void func_001164F8(S_1164F8* self, int flags) {
    self->unkC = D_00337FE8;
    if (self->unk0) {
        func_00113FB8(self->unk0);
        O_1164F8* o = self->unk0;
        if (o) {
            V_1164F8* v = o->unk18;
            v->unk10.unk4((char*)o + v->unk10.unk0, 3);
        }
        self->unk0 = 0;
    }
    if (flags & 1) {
        func_00119400(D_00368A38, (int)self);
    }
}

extern "C" void func_00116578(SA114_A* self, void* cb, int x) {
    self->unk4 = x;
    if (!cb) {
        cb = (void*)func_001165C0;
    }
    self->unk8 = cb;
}

extern "C" void func_00116590(SA114_A* self) {
    SA114_V* o = self->unk20;
    VEntry* e = &o->unkC[3];
    ((void (*)(void*))e->fn)((char*)o + e->delta);
}

extern "C" void func_001165C0(void) {
}

extern "C" void func_001165C8(void) {
    func_00116408();
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001165E8);

extern "C" void func_00116610(S_00116610* self) {
    self->unk1C();
}

extern "C" int func_00116630(void) {
    return 1;
}

extern "C" int func_00116638(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116640);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116660);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116748);

GP_DATA(D_00368768);
extern "C" void func_001167C8(int a) {
    if ((D_00368768 ^ 1) == 0) {
        D_00368770 = a;
    }
}

extern "C" int func_001167E0(char* a, char* b) {
    int la, lb;
    char buf[0x70];
    if (!a || !b) return 0;
    la = func_0030AA88(a);
    lb = func_0030AA88(b);
    if (la < lb) return 0;
    func_0030A970(buf, a);
    buf[lb] = 0;
    return func_0030E650(buf, b) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116878);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116B20);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116C60);
