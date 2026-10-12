#include "common.h"

struct S_00138958 { char pad0[0x4]; int unk4; };
struct S_00138960 { char pad0[0x4]; int unk4; };
struct S_00139580 { char pad0[0x1B8]; float unk1B8; };
struct S_00139588 { char pad0[0x1BC]; float unk1BC; };

struct S_001395C0 { char pad0[0x1E0]; float unk1E0; float unk1E4; };

struct S_001389F0 { char pad0[0x4560]; char unk4560; };

extern "C" {
extern int D_003694D0;
void func_0030A970(char*);
void func_00138850(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00137C98);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00137E30);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00137EB0);

extern "C" void func_00137F30(int v) {
    D_003694D0 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00137F38);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138010);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001384B0);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001384F0);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138790);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138850);

extern "C" void func_001388E8(void) {
    func_00138850(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138908);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138950);

extern "C" int func_00138958(S_00138958* self) {
    return self->unk4;
}

extern "C" void func_00138960(S_00138960* self, int v) {
    self->unk4 = v;
}

extern "C" char* func_00138968(char* p) {
    return p + 0x40;
}

extern "C" int func_00138970(void) {
    return 17696;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138978);

extern "C" void func_001389F0(S_001389F0* self) {
    func_0030A970(&self->unk4560);
}

extern "C" char* func_00138A10(char* p) {
    return p + 0x4560;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138A18);

extern "C" void func_00138B00(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138B08);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138B18);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138D98);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138E60);

extern "C" void func_00138E68(void) {
}

extern "C" void func_00138E70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138E78);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138F18);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139420);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139510);

extern "C" float func_00139580(S_00139580* self) {
    return self->unk1B8;
}

extern "C" float func_00139588(S_00139588* self) {
    return self->unk1BC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139590);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001395A8);

extern "C" void func_001395C0(S_001395C0* self, float* a, float* b) {
    *a = self->unk1E0;
    *b = self->unk1E4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001395D8);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001396D0);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001397A8);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139840);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139960);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139C18);
