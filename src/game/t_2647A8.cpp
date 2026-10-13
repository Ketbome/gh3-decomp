#include "common.h"

struct S2647_Script {
    char pad0[0x20];
    int unk20;
};

struct S2647_Node {
    S2647_Node *unk0;
    S2647_Node *unk4;
};

struct S2647_List {
    int unk0;
    S2647_Node head;
};

extern "C" {
int func_001EBFE8(void);
void func_002663F8(int, int);
bool func_0027D870(int, u32, void *, int);
int func_0027D470(int, u32, void *, int);
int func_0027D650(int, u32, void *, int);
void func_0027ACF8(int, u32);
void func_0027C898(int, u32, int);
void func_0027C678(int, u32, int);
int func_00289E08(void *);
void Heap_Free(int, void *);
extern int D_00368748;
extern int D_00368A38;
extern int D_00372E78;
extern int D_00372E7C;
extern char *D_00372E80;
extern int D_0037096C;
extern char D_0039A4A0[];
extern char D_0039A4F0[];
extern S2647_List D_0039ACF0;
void func_0015D1A0(u32, u32);
int func_0015D160(u32);
int func_0015D2E8(u32, int);
void func_0015D2E0(u32);
void func_001EBAE8(u32);
void func_001EBCE0(u32);
void func_001EBC80(u32);
int func_001EBFF0(u32);
void func_001EC818(u32);
void func_001EC8D0(u32);
void func_001EC998(int, u32);
int func_001EC608(u32, int);
void func_0011F4D8(char *, char *, int, int, int);
void func_0030ADA0(char *, int, int);
void func_00264BE8(void);
void func_00266428(void *, int);
void func_001B4A98(u32, u32);
}

extern "C" int CFunc_CreateViewportTextureOverride(int params) {
    u32 c[3];
    c[0] = 0;
    func_0027D870(params, 0x7D99F28D, &c[1], 1);
    u32 a = c[1];
    func_0027D870(params, 0xDA4825BA, &c[2], 1);
    u32 b = c[2];
    func_0027D870(params, 0x01D5FCE4, &c[0], 0);
    func_001B4A98(b, a);
    return 1;
}

extern "C" int CFunc_DestroyViewportTextureOverride(void) {
    return 0;
}

extern "C" int CFunc_AddPrepassViewport(int params) {
    u32 id;
    u32 b;
    func_0027D870(params, 0x9FD29151, &id, 1);
    func_0027D870(params, 0xCC424795, &b, 1);
    func_0015D1A0(id, b);
    return 1;
}

extern "C" int CFunc_PrepassViewportExists(int params) {
    u32 id;
    func_0027D870(params, 0x9FD29151, &id, 1);
    return func_0015D160(id);
}

extern "C" int CFunc_RemovePrepassViewport(int params) {
    u32 id;
    func_0027D870(params, 0x9FD29151, &id, 1);
    if (func_0015D2E8(id, 0)) {
        func_0015D2E0(id);
    }
    return 1;
}

extern "C" int CFunc_AddZoneProfiles(int params) {
    u32 x = 0;
    func_0027D470(params, 0, &x, 1);
    func_001EBAE8(x);
    return 1;
}

extern "C" int CFunc_RemoveZoneProfiles(int params) {
    u32 x = 0;
    func_0027D470(params, 0, &x, 1);
    func_001EBCE0(x);
    return 1;
}

extern "C" int CFunc_SetZoneProfiles(int params) {
    u32 x;
    func_0027D470(params, 0, &x, 1);
    func_001EBC80(x);
    return 1;
}

extern "C" int CFunc_PrintLoadedProfiles(void) {
    func_001EBFE8();
    return 1;
}

extern "C" int CFunc_CreateRandomAppearance(int params, S2647_Script *script) {
    u32 x = 0;
    func_0027D650(params, 0x7EA855F0, &x, 1);
    int r = func_001EBFF0(x);
    func_0027ACF8(script->unk20, 0x7EA855F0);
    func_0027C898(script->unk20, 0x7EA855F0, r);
    return 1;
}

extern "C" int CFunc_AddEditableList(int params) {
    u32 id;
    func_0027D870(params, 0, &id, 1);
    func_001EC818(id);
    return 1;
}

extern "C" int CFunc_RemoveEditableList(int params) {
    u32 id;
    func_0027D870(params, 0, &id, 1);
    func_001EC8D0(id);
    return 1;
}

extern "C" int CFunc_ForEachInEditableList(int params, void *script) {
    int s = func_00289E08(script);
    u32 id;
    func_0027D870(params, 0x62BA3F6A, &id, 1);
    func_001EC998(s, id);
    return 1;
}

extern "C" int CFunc_SelectFrom(int params, S2647_Script *script) {
    u32 x;
    func_0027D470(params, 0x46E55E8F, &x, 1);
    int r = func_001EC608(x, script->unk20);
    if (r) {
        func_0027C678(script->unk20, 0x90436BD9, r);
    }
    return 1;
}

GP_DATA(D_0037096C);
INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264B70);

extern "C" void func_00264BE8(void) {
    if (D_00368748 == 0) {
        int n = D_00372E80 - D_0039A4F0;
        if (n != 0) {
            int x = D_00372E78;
            D_00372E78 = 1;
            func_0011F4D8(D_0039A4A0, D_0039A4F0, n, 1, x);
            D_00372E80 = D_0039A4F0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264C58);

extern "C" void func_00264F60(void) {
    if (D_00368748 == 0) {
        func_00264BE8();
        D_0037096C = 0;
    }
}

extern "C" void func_00264F90(void) {
    S2647_Node *p = D_0039ACF0.head.unk4;
    D_0039ACF0.head.unk4 = &D_0039ACF0.head;
    D_0039ACF0.head.unk0 = &D_0039ACF0.head;
    while (p != &D_0039ACF0.head) {
        S2647_Node *n = p->unk4;
        func_00266428(p + 2, 2);
        Heap_Free(D_00368A38, p);
        p = n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265008);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002650F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265388);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265428);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265580);

extern "C" void func_00265680(void) {
    S2647_Node *p = D_0039ACF0.head.unk4;
    D_0039ACF0.head.unk4 = &D_0039ACF0.head;
    D_0039ACF0.head.unk0 = &D_0039ACF0.head;
    while (p != &D_0039ACF0.head) {
        S2647_Node *n = p->unk4;
        func_00266428(p + 2, 2);
        Heap_Free(D_00368A38, p);
        p = n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_UpdateMaterialProperty);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002663F0);

extern "C" void func_002663F8(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_0039ACF0.head.unk0 = &D_0039ACF0.head;
        D_0039ACF0.head.unk0->unk4 = &D_0039ACF0.head;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00266428);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002664F8);

extern "C" void func_00266600(void) {
    func_002663F8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00266620);

extern "C" int func_00266780(u32 k) {
    switch (k) {
        case 0xEF082878:
            return 0;
        case 0xF221474C:
            return 1;
        case 0x9706104B:
            return 2;
        case 0x0CA64C41:
            return 3;
    }
    return 0;
}
