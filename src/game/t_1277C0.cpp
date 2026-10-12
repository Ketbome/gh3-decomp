#include "common.h"

struct S_00127818 { float unk0; };
struct S_00127820 { char pad0[0x4]; float unk4; };
struct S_00127828 { char pad0[0x8]; float unk8; };
struct S_00127830 { char pad0[0xC]; float unkC; };
struct S_00127940 { char pad0[0x8]; int unk8; };
struct S_001288F0 { char pad0[0xC]; float unkC; };

struct S_00128A80 { char pad0[0x404]; s16 unk404; };
struct S_00129070 { char pad0[0x480]; int unk480; };

struct S_00127838 { int unk0; int unk4; int unk8; void* unkC; };

extern "C" {
extern int D_003690EC;
extern u8 D_003398C8[];
void func_0012A048(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001277C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001277F8);

extern "C" void func_00127818(S_00127818* self, float v) {
    self->unk0 = v;
}

extern "C" void func_00127820(S_00127820* self, float v) {
    self->unk4 = v;
}

extern "C" void func_00127828(S_00127828* self, float v) {
    self->unk8 = v;
}

extern "C" void func_00127830(S_00127830* self, float v) {
    self->unkC = v;
}

extern "C" S_00127838* func_00127838(S_00127838* self, int a, int b) {
    self->unkC = D_003398C8;
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127858);

extern "C" void func_00127940(S_00127940* self, int v) {
    self->unk8 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127948);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001279A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001279F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127A60);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127AB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127B10);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128098);

extern "C" int func_001280D8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001280E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128160);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001281C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128220);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128338);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001283A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001283F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128460);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001284B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128528);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001287F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001288B0);

extern "C" void func_001288F0(S_001288F0* self, float v) {
    self->unkC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001288F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128940);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128980);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001289C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128A00);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128A40);

extern "C" S_00128A80* func_00128A80(S_00128A80* self) {
    self->unk404 = 0;
    return self;
}

extern "C" void func_00128A90(void* self, int flags) {
    if (flags & 1) func_0012A048(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128AB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128B08);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128B40);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128D48);

extern "C" void func_00128F40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128F48);

extern "C" int func_00129070(S_00129070* self) {
    return self->unk480 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129080);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001290C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129138);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129148);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001291E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001292D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129350);

extern "C" int func_00129390(void) {
    return D_003690EC;
}

extern "C" void func_00129398(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001293A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001294B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001294C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129710);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001297B8);
