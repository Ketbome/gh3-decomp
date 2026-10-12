#include "common.h"

struct S_0014C7C0 { int unk0; int unk4; int unk8; };

struct N_14C { char pad0[0x4]; int unk4; char pad8[0x4]; N_14C* unkC; };

extern "C" {
void func_0016E170(void);
void func_0016D4B8(void);
void func_00181C80(void);
u32 func_00115028(const char*);
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
void func_0014DA60(int, int);
void func_0014D010(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C740);

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

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C870);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014C948);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014CC88);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014CD98);

extern "C" int func_0014CF18(const char* name, int x) {
    return func_0014CD98(func_00115028(name), x);
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

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014DDB0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E4E0);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E560);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E5D8);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_14C740", func_0014E708);
