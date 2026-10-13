#include "common.h"

struct S_0014C7C0 { int unk0; int unk4; int unk8; };

struct N_14C { char pad0[0x4]; int unk4; char pad8[0x4]; N_14C* unkC; };

extern "C" {
void func_00119490(int, int);
void func_001194B8(int);
int func_00119500(int);
int func_00119610(int, int);
int func_0011A380(int);
void func_0011AD80(int, int);
void func_0011AEB0(int);
extern int D_00368A38;
struct HE_14CF50 { int unk0; int unk4; HE_14CF50* unk8; };
struct HT_14CF50 { int unk0; HE_14CF50* unk4; char pad8[0xD]; u8 unk15; };
extern HT_14CF50 D_003781A0;
void func_0030B550_v(char*, const char*, ...) __asm__("func_0030B550");
int func_0014F130(void);
extern char D_0033C360[];
extern char D_003699F8[];
extern char D_00369A80[];
int func_0027DF00(int, int);
int func_00181EE0(int, int, int, int, int);
void func_0014E5D8(int, int, int, int, int);
int func_0028DAB8(int);
void func_00150520(void*, void*);
void func_0011A558(u32, int, int);
void func_0011A568(void);
void* operator_new(u32);
extern char D_0033C388[];
struct L_0014E5D8 { char pad0[8]; int unk8; char padC[4]; L_0014E5D8* unk10; };
extern L_0014E5D8 D_003781F8;
void func_0016E170(void);
void func_0016D4B8(void);
void func_00181C80(void);
u32 CrcFromPathLowercase(const char*);
int func_0014CD98(u32, int);
extern S_0014C7C0 D_003781E8;
int func_00113770(const char*, int);
extern s8 D_004159C8[];
void func_0027D188(void*, int, int*, int);
void func_001535E8(int);
extern S_0014C7C0 D_003781C0[];
void func_0014C7E0(S_0014C7C0*, int);
extern N_14C* D_00378204;
void func_00150190(int);
int func_0030E720(const char*, const char*);
void func_0030B550(char*, const char*, const char*);
extern char D_003699E8[];
extern char D_003699F0[];
extern char D_0033C238[];
extern int D_00372B48;
void func_00182930(void);
void func_00182940(void);
void func_00181C38(void);
void func_00181C58(void);
void func_0014C740(int, int);
void func_0014C560(void*, int, int);
extern u8 D_00377FC0[];
void func_0014DA60(int, int);
void func_0014D010(void);
}

extern "C" void func_0014C740(int a, int b) {
    if (b == 0xFFFF && a) {
        func_0014C560(D_00377FC0, 8, 0);
        for (int i = 0x7F; i != -1; i -= 0x20) {
        }
    }
}

extern "C" void func_0014C7A0(void) {
    func_0014C740(1, 0xFFFF);
}

extern "C" S_0014C7C0* func_0014C7C0(S_0014C7C0* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C7D8);

extern "C" void func_0014C7E0(S_0014C7C0* self, int a) {
    int h = D_00368A38;
    func_00119490(h, func_00119610(h, 1));
    func_0011AD80(func_00119500(D_00368A38), 0x20);
    self->unk4 = func_0011A380(a);
    func_0011AEB0(func_00119500(D_00368A38));
    func_001194B8(D_00368A38);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C870);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C948);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014CC88);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014CD98);

extern "C" int func_0014CF18(const char* name, int x) {
    return func_0014CD98(CrcFromPathLowercase(name), x);
}

extern "C" void func_0014CF48(int v) {
    D_00372B48 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014CF50);

extern "C" int func_0014CFD8(const char* name) {
    return D_004159C8[func_00113770(name, 0)];
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D010);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D068);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D070);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", CFunc_SetFontProperties);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D678);

extern "C" int CFunc_SetFontNonProportionalNumbers(void* params) {
    int x;
    func_0027D188(params, 0, &x, 0);
    func_001535E8(func_0014CF18((const char*)x, 1));
    return 1;
}

extern "C" int CFunc_AllocateDecompressedFontBuffers(void) {
    func_0014D010();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", CFunc_DecompressFonts);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D788);

extern "C" void func_0014D790(S_0014C7C0* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S_0014C7C0* func_0014D7A0(S_0014C7C0* self) {
    func_0014D790(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D7C8);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014D880);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DA60);

extern "C" void func_0014DB10(void) {
    func_0014DA60(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DB30);

extern "C" float func_0014DC38(int i) {
    return (float)i * 0.016666668f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DC58);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DC60);

extern "C" int func_0014DDB0(int* out, int s) {
    *out = 0;
    if (func_0027DF00(s, 0x4F792E6C)) {
        *out = 1;
    } else if (func_0027DF00(s, 0x3153E314)) {
        *out = 2;
    } else if (func_0027DF00(s, 0x6D941203)) {
        *out = 3;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DE30);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E090);

extern "C" void func_0014E098(const char* s, char* out) {
    if (func_0030E720(s, D_003699E8) || func_0030E720(s, D_003699F0)) {
        func_0030B550(out, D_0033C238, s);
    }
}

extern "C" S_0014C7C0* func_0014E100(S_0014C7C0* self) {
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E110);

extern "C" void func_0014E118(int a, int b) {
    if (b == 0xFFFF && a) {
        func_0014E100(&D_003781E8);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E148);

extern "C" void func_0014E170(void) {
}

extern "C" void func_0014E178(void) {
    func_00182930();
}

extern "C" void func_0014E198(void) {
    func_00182940();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E290);

extern "C" void func_0014E470(void) {
    func_00181C38();
}

extern "C" void func_0014E490(void) {
    func_00181C58();
}

extern "C" void func_0014E4B0(void) {
    func_0016E170();
    func_0016D4B8();
    func_00181C80();
}

extern "C" void func_0014E4E0(char* out, int a, int c) {
    char* fmt = D_0033C360;
    char* t;
    if (c) {
        t = D_00369A80;
    } else {
        t = D_003699F8;
    }
    func_0030B550_v(out, fmt, a, a, t, func_0014F130());
}

extern "C" int func_0014E560(int a, int b, int c, int d, int e, int f, int g) {
    int r = func_00181EE0(b, c, d, e, f);
    func_0014E5D8(r, a, c, 0, g);
    return r;
}

struct O_0014E5D8 { char pad0[4]; int unk4; int unk8; };
struct N_0014E5D8 { char pad0[4]; void* unk4; int unk8; N_0014E5D8* unkC; N_0014E5D8* unk10; void* unk14; };

extern "C" void func_0014E5D8(int p, int a, int b, int c, int d) {
    O_0014E5D8* self = (O_0014E5D8*)p;
    char buf[0x80];
    func_0014E4E0(buf, a, d);
    self->unk4 = func_0028DAB8(a);
    self->unk8 = b;
    if (c == 0) func_00150520(self, buf);
    func_0011A558(0xEC4365D2, 0, 0);
    N_0014E5D8* n = (N_0014E5D8*)operator_new(0x18);
    n->unk4 = self;
    n->unkC = n;
    n->unk10 = n;
    n->unk14 = D_0033C388;
    n->unk8 = 0;
    N_0014E5D8* l = (N_0014E5D8*)&D_003781F8;
    N_0014E5D8* t = l->unk10;
    n->unkC = l;
    n->unk10 = t;
    l->unk10->unkC = n;
    l->unk10 = n;
    func_0011A568();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E708);
