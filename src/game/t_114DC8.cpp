// cflags: -funroll-loops
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
int strlen(char*);
char* strcpy(char*, char*);
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
void Heap_Free(int, int);
extern int D_00368A38;
struct H_00116410 { char pad0[0x1E0]; int unk1E0; };
extern H_00116410* D_00368A38_p __asm__("D_00368A38");
extern char* D_00370EE0;
void func_00119490(void*, int);
void func_001194B8(int);
void func_0011A558(u32, int, int);
void func_0011A568(void);
void* operator_new(u32);
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

extern "C" {
int func_00119610(int, int);
void* Heap_Alloc_p(int, int, int, int) __asm__("Heap_Alloc");
}

extern "C" void func_00115170(void) {
    int h = D_00368A38;
    func_00119490((void*)h, func_00119610(h, 0));
    D_00372AA0 = (int)Heap_Alloc_p(D_00368A38, 0x1011, 1, 0);
    D_00372AA4 = (int)Heap_Alloc_p(D_00368A38, 0x4004, 1, 0);
    D_00372AA8 = (int)Heap_Alloc_p(D_00368A38, 0x4404, 1, 0);
    D_00372AAC = (int)Heap_Alloc_p(D_00368A38, 0x4004, 1, 0);
    func_001194B8(D_00368A38);
    for (int i = 0x1001; i < 0x1101; i++) {
        ((int*)D_00372AA8)[i] = 0x1000;
    }
    for (int i = 0; i < 0x1000; i++) {
        ((int*)D_00372AAC)[i] = 0x1000;
    }
}

extern "C" void func_001153C8(void) {
    if (D_00372AAC) Heap_Free(D_00368A38, D_00372AAC);
    if (D_00372AA8) Heap_Free(D_00368A38, D_00372AA8);
    if (D_00372AA4) Heap_Free(D_00368A38, D_00372AA4);
    if (D_00372AA0) Heap_Free(D_00368A38, D_00372AA0);
}

extern "C" void func_00115438(int);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00115438);

#define LSON ((int*)D_00372AA4)
#define RSON ((int*)D_00372AA8)
#define DAD ((int*)D_00372AAC)

extern "C" void func_00115660(int p) {
    int q;
    if (DAD[p] == 0x1000) {
        return;
    }
    if (RSON[p] == 0x1000) {
        q = LSON[p];
    } else if (LSON[p] == 0x1000) {
        q = RSON[p];
    } else {
        q = LSON[p];
        if (RSON[q] != 0x1000) {
            do {
                q = RSON[q];
            } while (RSON[q] != 0x1000);
            RSON[DAD[q]] = LSON[q];
            DAD[LSON[q]] = DAD[q];
            LSON[q] = LSON[p];
            DAD[LSON[p]] = q;
        }
        RSON[q] = RSON[p];
        DAD[RSON[p]] = q;
    }
    DAD[q] = DAD[p];
    if (RSON[DAD[p]] == p) {
        RSON[DAD[p]] = q;
    } else {
        LSON[DAD[p]] = q;
    }
    DAD[p] = 0x1000;
}

extern long D_00368500;
extern long D_00368508;
extern long D_00368510;
extern int D_00372A98;
extern int D_00372A9C;

GP_DATA(D_00368500);
GP_DATA(D_00368508);
GP_DATA(D_00368510);
extern "C" int func_00115850(char* in, unsigned char* out, int inlen) {
    int i, c, len, r, s, last_match_length, code_buf_ptr;
    unsigned char code_buf[17], mask;
    D_00368500 = 0;
    D_00368508 = 0;
    code_buf_ptr = mask = 1;
    D_00368510 = 0;
    func_00115170();
    code_buf[0] = 0;
    s = 0;
    r = 0xFEE;
    for (i = s; i < r; i++) {
        ((unsigned char*)D_00372AA0)[i] = ' ';
    }
    for (len = 0; len < 18 && inlen != 0; len++) {
        c = *in++;
        inlen--;
        ((unsigned char*)D_00372AA0)[r + len] = c;
    }
    if ((D_00368500 = len) == 0) {
        func_001153C8();
        return 0;
    }
    for (i = 1; i <= 18; i++) {
        func_00115438(r - i);
    }
    func_00115438(r);
    do {
        if (D_00372A9C > len) {
            D_00372A9C = len;
        }
        if (D_00372A9C <= 2) {
            D_00372A9C = 1;
            code_buf[0] |= mask;
            code_buf[code_buf_ptr++] = ((unsigned char*)D_00372AA0)[r];
        } else {
            code_buf[code_buf_ptr++] = (unsigned char)D_00372A98;
            code_buf[code_buf_ptr++] = (unsigned char)(((D_00372A98 >> 4) & 0xF0) | (D_00372A9C - 3));
        }
        if ((mask <<= 1) == 0) {
            for (i = 0; i < code_buf_ptr; i++) {
                *out++ = code_buf[i];
            }
            D_00368508 += code_buf_ptr;
            code_buf[0] = 0;
            code_buf_ptr = mask = 1;
        }
        last_match_length = D_00372A9C;
        for (i = 0; i < last_match_length && inlen != 0; i++) {
            c = *in++;
            inlen--;
            func_00115660(s);
            ((unsigned char*)D_00372AA0)[s] = c;
            if (s < 17) {
                ((unsigned char*)D_00372AA0)[s + 0x1000] = c;
            }
            s = (s + 1) & 0xFFF;
            r = (r + 1) & 0xFFF;
            func_00115438(r);
        }
        D_00368500 += i;
        while (i++ < last_match_length) {
            func_00115660(s);
            s = (s + 1) & 0xFFF;
            r = (r + 1) & 0xFFF;
            if (--len) {
                func_00115438(r);
            }
        }
    } while (len > 0);
    if (code_buf_ptr > 1) {
        for (i = 0; i < code_buf_ptr; i++) {
            *out++ = code_buf[i];
        }
        D_00368508 += code_buf_ptr;
    }
    func_001153C8();
    return (int)D_00368508;
}

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
    N_00116410* o = (N_00116410*)operator_new(0x24);
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
        Heap_Free(D_00368A38, (int)self);
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

extern "C" int func_00116748(int x) {
    switch (x) {
    case 0: return 0x30;
    case 1: return 0x31;
    case 2: return 0x32;
    case 3: return 0x33;
    case 4: return 0x34;
    case 5: return 0x35;
    case 6: return 0x36;
    case 7: return 0x37;
    case 8: return 0x38;
    case 9: return 0x39;
    }
    return 0;
}

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
    la = strlen(a);
    lb = strlen(b);
    if (la < lb) return 0;
    strcpy(buf, a);
    buf[lb] = 0;
    return func_0030E650(buf, b) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116878);

INCLUDE_ASM("asm/nonmatchings/game/t_114DC8", func_00116B20);

extern "C" {
void func_00116E48(u8*);
void func_00122AC8(int, char**);
int func_00116B20_a(u8*, int, char**) __asm__("func_00116B20");
char* func_00116878_a(u8*, int, char**) __asm__("func_00116878");
int strcmp(char*, u8*);
void func_0030B550(char*, u8*);
extern u8 D_003686F0[];
extern u8 D_00368780[];
extern u8 D_00368788[];
extern u8 D_00368790[];
extern u8 D_003382A0[];
extern u8 D_003382B0[];
extern u8 D_003382C0[];
extern u8 D_003382D0[];
extern u8 D_003687A0[];
extern u8 D_003687A8[];
extern u8 D_003687B0[];
extern u8 D_003687B8[];
extern u8 D_00368798[];
extern char D_00375208[];
extern char D_00375288[];
extern int D_00368748;
extern int D_0036874C;
extern int D_00368744;
extern int D_00368750;
extern int D_0036876C;
}

GP_DATA(D_00368748);
GP_DATA(D_0036874C);
GP_DATA(D_0036876C);
extern "C" void func_00116C60(int argc, char** argv) {
    func_00116E48(D_003686F0);
    func_00122AC8(argc, argv);
    if (func_00116B20_a(D_00368780, argc, argv) != 0) {
        D_00368748 = 1;
    }
    if (func_00116B20_a(D_00368788, argc, argv) != 0) {
        D_00368748 = 0;
    }
    if (func_00116B20_a(D_00368790, argc, argv) != 0) {
        D_0036874C = 1;
    }
    if (func_00116B20_a(D_003382A0, argc, argv) != 0) {
        D_00368744 = 0;
    }
    if (func_00116B20_a(D_003382B0, argc, argv) != 0) {
        D_00368750 = 1;
        if (argc >= 3) {
            strcpy(D_00375208, argv[2]);
            if (argc >= 4) {
                strcpy(D_00375288, argv[3]);
            } else {
                func_0030B550(D_00375288, D_00368798);
            }
        }
    }
    if (func_00116B20_a(D_003382C0, argc, argv) != 0) {
        D_00368750 = 0;
    }
    if (func_00116B20_a(D_003687A0, argc, argv) != 0) {
        D_00368768 = 0;
    }
    if (func_00116B20_a(D_003687A8, argc, argv) != 0) {
        D_00368768 = 1;
    }
    char* v = func_00116878_a(D_003382D0, argc, argv);
    if (v != 0) {
        if (strcmp(v, D_003687B0) == 0) {
            D_0036876C = 0x32;
        }
        if (strcmp(v, D_003687B8) == 0) {
            D_0036876C = 0x3C;
        }
    }
}
