#include "common.h"

struct S22D {
    char pad0[0x40];
    int unk40;
    char pad44[0x4C];
    int unk90;
    int unk94;
};

extern "C" {
extern int D_0036F8D0;
extern u8 D_0036F8F0[];
extern u8 D_00353620[];
extern u8 D_0036F9A0[];
extern u8 D_00353980[];
extern u8 D_00353B30[];
extern u8 D_0036FA88[];
extern u8 D_0036FAD8[];
extern u8 D_00354030[];
void func_002253A8(int, void*);
int func_0022BD90(char*);
int func_0022C110(void*);
int func_0022BE60_3(char*, int, int) __asm__("func_0022BE60");
void func_0015FA58(int);
void func_0015B920(int);
void func_0015AE68(int);
void func_002886F8(int);
void func_0014ED00(int, int);
void func_001628B8(int);
int func_0015FA38(int);
int func_0015B8E8(int, int, int, int, int, int, int);
int func_0015AD38(int, int, int, int, int, int, int);
int func_0022BCE0(void*, int, int, int, int, int);
void func_00162478(int, int);
int func_0014EC58(int, int, int, int, int, int, int);
int strcpy(int, int);
int func_00162920(void*, int);
void func_0022BBB0(void*, void*, int, int, int, int);
void func_0015B7B0(void*, int);
int* func_0014C870(int, int, int, int, int, int, int, int);
void* operator_new(u32);
int func_00133F80(void*);
int func_00133FE0(int, int, int, int);
void func_00134280(int, int);
int func_0014F130(void);
int func_0030B550(int, void*, int, int);
extern u8 D_0036FB28[];
}

struct VE22D {
    s16 delta;
    s16 unk2;
    void* fn;
};

#define VCALL22D(o, vp, off, T) ((T)((VE22D*)(*(char**)((char*)(o) + (vp)) + (off)))->fn)
#define VADJ22D(o, vp, off) ((char*)(o) + ((VE22D*)(*(char**)((char*)(o) + (vp)) + (off)))->delta)

extern "C" void* func_0022DD98(void) {
    return D_0036F8F0;
}

extern "C" int func_0022DDA8(void) {
    return 0xE;
}

extern "C" void func_0022DDB0(int v) {
    if (v) {
        D_0036F8D0 = 1;
    } else {
        D_0036F8D0 = 0;
    }
}

extern "C" void func_0022DDF0(void);

extern "C" void* func_0022DDC8(void* p) {
    func_0022DDF0();
    return p;
}

extern "C" void func_0022DDF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DDF8);

extern "C" int func_0022DE20(void) {
    return 0x90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022DE28);

extern "C" void func_0022DEE8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" int func_0022DF70(char* p, int a1, int a2) {
    int t = func_00133F80(operator_new(0x14));
    if (!func_00133FE0(t, a1, a2, 1)) return 0;
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, t);
    func_00134280(t, *(int*)p);
    return func_0022BE60_3(p, a1, a2);
}

extern "C" void func_0022E020(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    char* o = (char*)((int (*)(char*))e->fn)(p + e->delta);
    if (o) {
        VE22D* g = (VE22D*)(*(char**)(o + 0x10) + 8);
        ((void (*)(char*, int))g->fn)(o + g->delta, 3);
    }
    func_0022BD90(p);
}

extern "C" void* func_0022E080(void) {
    return D_00353620;
}

extern "C" int func_0022E090(void) {
    return 7;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E098);

extern "C" {
int func_0014EBE8(int, void*);
void func_00113528(void*);
int func_0030B550_5(void*, void*, void*, void*, int) __asm__("func_0030B550");
extern u8 D_003537D0[];
extern u8 D_0036F990[];
extern u8 D_0036F998[];
}

extern "C" void func_0022E0C0(char *o, int a1, int a2, int a3, int a4, int a5)
{
  char buf[0x100];
  char buf2[0x100];
  VE22D *e = (VE22D *) ((*((char **) (o + 0x34))) + 0x78);
  ((void (*)(char *, int, int)) e->fn)(o + e->delta, a4, a5);
  int r = func_0014EBE8(a1, buf);
  func_00113528(buf);
  char *b2 = buf2;
  u8 *fmt = D_003537D0;
  u8 *s = (r) ? (D_0036F990) : (D_0036F998);
  int k = func_0014F130();
  func_0030B550_5(b2, fmt, buf, s, k);
  *((int *) ((*((char **) (o + 0x18))) + 0x94)) = r;
  func_0022BBB0(o, buf2, a2, a3, a4, a5);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E1D0);

extern "C" void func_0022E270(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E2F8);

extern "C" void func_0022E428(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x10);
        func_0014ED00(((int (*)(char*))f->fn)(p + f->delta), 0);
    }
    func_0022BD90(p);
}

extern "C" void* func_0022E490(void) {
    return D_0036F9A0;
}

extern "C" int func_0022E4A0(void) {
    return 8;
}

extern "C" void func_0022E4D0(S22D*);

extern "C" S22D* func_0022E4A8(S22D* p) {
    func_0022E4D0(p);
    return p;
}

extern "C" void func_0022E4D0(S22D* self) {
    self->unk90 = 0;
    self->unk94 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E4E0);

extern "C" int func_0022E508(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E510);

extern "C" void func_0022E5C0(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022E648(char* p, int a1, int a2) {
    char* o = (char*)func_0022C110(p);
    VE22D* e = (VE22D*)(*(char**)(o + 0x34) + 0x10);
    char* r = (char*)((int (*)(char*))e->fn)(o + e->delta);
    func_00162478((int)r, a1);
    VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((int (*)(char*, int))f->fn)(p + f->delta, *(int*)(r + 0x8C));
    func_0022BE60_3(p, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E6D8);

extern "C" void func_0022E810(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        char* o = (char*)func_0022C110(p);
        VE22D* f = (VE22D*)(*(char**)(o + 0x34) + 0x10);
        func_001628B8(((int (*)(char*))f->fn)(o + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022E878(void) {
    return D_00353980;
}

extern "C" int func_0022E888(void) {
    return 9;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E890);

extern "C" int func_0022E8B8(void) {
    return 0x94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022E8C0);

extern "C" void func_0022E980(char* p, int a1, int a2) {
    register int r1 asm("$17") = a1;
    register int r2 asm("$18") = a2;
    int w = func_0015FA38(*(int*)p);
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, w);
    func_0022BE60_3(p, r1, r2);
}

extern "C" void func_0022E9E8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EA70);

extern "C" void func_0022EB68(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x10);
        func_0015FA58(((int (*)(char*))f->fn)(p + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022EBC8(void) {
    return D_00353B30;
}

extern "C" int func_0022EBD8(void) {
    return 0xA;
}

extern "C" void func_0022EBE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EBE8);

extern "C" int func_0022EC10(void) {
    return 0x90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EC18);

extern "C" void func_0022ECC8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022ED50(char* p, int a1, int a2) {
    char* q = *(char**)(p + 0x18);
    int w = func_0015B8E8(*(int*)p, a1, a2, *(int*)(q + 0x90), *(int*)(q + 0x94), *(int*)(q + 0x98), *(int*)(q + 0x9C));
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, w);
    func_0022BE60_3(p, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EDD0);

extern "C" void func_0022EF38(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x10);
        func_0015B920(((int (*)(char*))f->fn)(p + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022EF98(void) {
    return D_0036FA88;
}

extern "C" int func_0022EFA8(void) {
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EFB0);

extern "C" int func_0022EFD8(void) {
    return 0xA0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022EFE0);

extern "C" void func_0022F098(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022F120(char* p, int a1, int a2) {
    char* q = *(char**)(p + 0x18);
    int w = func_0015AD38(a1, a2, *(int*)p, *(int*)(q + 0x90), *(int*)(q + 0x94), 0, 0);
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, w);
    func_0022BE60_3(p, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F1A8);

extern "C" void func_0022F2F8(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x10);
        func_0015AE68(((int (*)(char*))f->fn)(p + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022F358(void) {
    return D_0036FAD8;
}

extern "C" int func_0022F368(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F370);

extern "C" int func_0022F398(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F3A0);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F3D0);

extern "C" void func_0022F588(char* p, int a1, int a2, int a3, int a4, int a5) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x78);
    ((void (*)(char*, int, int))e->fn)(p + e->delta, a4, a5);
    int t = *(int*)(p + 0x18);
    func_0030B550(t, D_0036FB28, a1, func_0014F130());
    func_0022BBB0(p, *(void**)(p + 0x18), a2, a3, a4, a5);
}

extern "C" void func_0022F650(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022F7D8);

extern "C" void func_0022F9A8(char* p) {
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x10);
        func_002886F8(((int (*)(char*))f->fn)(p + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022FA08(void) {
    return D_00354030;
}

extern "C" int func_0022FA18(S22D* self) {
    return !self->unk40 ? 0xC : 0xD;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FA30);

extern "C" int func_0022FA58(void) {
    return 0x98;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FA60);

extern "C" void func_0022FB30(char* p, int a1, int a2) {
    char* q = *(char**)(p + 0x18);
    int* r = func_0014C870(*(int*)p, a1, a2, *(int*)(q + 0x90), *(int*)(q + 0x94), *(int*)(q + 0x98), *(int*)(q + 0x9C), *(int*)(q + 0xA0));
    *r = *(int*)p;
    VE22D* e = (VE22D*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int*))e->fn)(p + e->delta, r);
    func_0022BE60_3(p, a1, a2);
}

extern "C" void func_0022FBB8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22D* f = (VE22D*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22DD98", func_0022FC40);
