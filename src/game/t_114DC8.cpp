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
extern int D_00368768;
extern int D_00368770;
extern int D_00368534;
extern u32 D_0032A080[];
void func_002F3BD0(void);
void func_002F3B80(void);
u32 func_00115028(const char*);
void func_001165C0(void);
void func_001162B8(void);
void func_00116178(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00114DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115020);

extern "C" u32 func_00115028(const char* s) {
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
    return func_00115028(s);
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001150D8);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115170);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001153C8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001162E8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116410);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001164F8);

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

extern "C" void func_001167C8(int a) {
    if ((D_00368768 ^ 1) == 0) {
        D_00368770 = a;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_001167E0);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116878);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116B20);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116C60);
