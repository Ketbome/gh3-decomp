#include "common.h"

struct S27B_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    u32 key;
    u32 val;
    S27B_Comp *next;
};

extern "C" {
int func_0027CC30(void *, u32, int, void *);
void func_0027F1E0(void *, int, int);
u32 func_001150B8(char *);
int func_0027D188(void *, u32, char **, int);
int func_0027D1F8(void *, u32, int *, int);
int func_0027D268(void *, u32, f32 *, int);
int func_0027D2D8(void *, u32, void *, int);
int func_0027D470(void *, u32, void **, int);
void *func_001D0900(int, int);
void func_0027BDB0(void *, S27B_Comp *, int);
u32 func_002756A8(char *);
void *func_0024D068(int, int);
f32 *func_00275648(void *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027B7D0);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027B800);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027B848);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027BA18);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027BBF8);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027BDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027BF30);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027BFD0);

extern "C" void func_0027C028(void *p, u32 key, char *s) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->next = 0;
    c->val = 0;
    c->type = 3;
    c->val = func_002756A8(s);
    func_0027BDB0(p, c, 0);
}

extern "C" void func_0027C0D0(void *p, u32 key, u32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = val;
    c->next = 0;
    c->type = 0x1A;
    func_0027BDB0(p, c, 0);
}

extern "C" void func_0027C160(void *p, u32 key, u32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = val;
    c->next = 0;
    c->type = 0x1;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C1F0);

extern "C" void func_0027C1F8(void *p, u32 key, f32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = 0;
    c->next = 0;
    *(f32 *)&c->val = val;
    c->type = 2;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C290);

extern "C" void func_0027C448(void *p, u32 key, u32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = val;
    c->next = 0;
    c->type = 0xD;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C4D8);

extern "C" void func_0027C5B0(void *p, u32 key, f32 x, f32 y) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->next = 0;
    c->val = 0;
    c->type = 5;
    f32 *v = func_00275648(func_0024D068(0xC, 1));
    v[1] = x;
    v[2] = y;
    c->val = (u32)v;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C678);

extern "C" void func_0027C740(void *p, u32 key, u32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = val;
    c->next = 0;
    c->type = 0xC;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C7D0);

extern "C" void func_0027C898(void *p, u32 key, u32 val) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->val = val;
    c->next = 0;
    c->type = 0xA;
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027C928);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027CA28);

extern "C" void func_0027CB80(void *p, u32 key, int b) {
    S27B_Comp *c = (S27B_Comp *)func_001D0900(0x10, 1);
    c->b8 = 0;
    c->type = 0;
    c->unk2 = 0;
    c->key = key;
    c->next = 0;
    c->val = 0;
    c->type = 0xD;
    if (b) {
        c->val = 0x0203B372;
    } else {
        c->val = 0xD43297CF;
    }
    func_0027BDB0(p, c, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027CC30);

extern "C" int func_0027CFA8(void *p, char *name, char **out, int req) {
    return func_0027D188(p, func_001150B8(name), out, req);
}

extern "C" int func_0027D000(void *p, char *name, int *out, int req) {
    return func_0027D1F8(p, func_001150B8(name), out, req);
}

extern "C" int func_0027D058(void *p, char *name, f32 *out, int req) {
    return func_0027D268(p, func_001150B8(name), out, req);
}

extern "C" int func_0027D0B0(void *p, char *name, void *out, int req) {
    return func_0027D2D8(p, func_001150B8(name), out, req);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D108);

extern "C" int func_0027D118(void *p, char *name, void **out, int req) {
    return func_0027D470(p, func_001150B8(name), out, req);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D170);

extern "C" int func_0027D188(void *p, u32 key, char * *out, int req) {
    char * v;
    if (func_0027CC30(p, key, 3, &v)) {
        *out = v;
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

extern "C" int func_0027D1F8(void *p, u32 key, int *out, int req) {
    int v;
    if (func_0027CC30(p, key, 1, &v)) {
        *out = v;
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

extern "C" int func_0027D268(void *p, u32 key, f32 *out, int req) {
    f32 v;
    if (func_0027CC30(p, key, 2, &v)) {
        *out = v;
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D2D8);

extern "C" int func_0027D378(void *p, u32 key, f32 *x, f32 *y, int req) {
    f32 *v;
    if (func_0027CC30(p, key, 5, &v)) {
        *x = v[1];
        *y = v[2];
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

extern "C" int func_0027D400(void *p, u32 key, void * *out, int req) {
    void * v;
    if (func_0027CC30(p, key, 10, &v)) {
        *out = v;
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

extern "C" int func_0027D470(void *p, u32 key, void * *out, int req) {
    void * v;
    if (func_0027CC30(p, key, 12, &v)) {
        *out = v;
        return 1;
    }
    if (req) {
        func_0027F1E0(p, 0, 1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D4E0);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D560);

INCLUDE_ASM("asm/nonmatchings/game/t_27B7D0", func_0027D650);
