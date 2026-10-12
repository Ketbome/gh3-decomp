#include "common.h"

extern "C" {

void func_002001E8(int, int);
void* func_00113D20(u32 size);
void* func_00200380(void* self);
void func_00276D48(u32 key, void* data, int size);
extern u8 D_0038F928[];

void func_00200308(void) {
    func_002001E8(1, 0xFFFF);
}

void* func_00200328(void) {
    return func_00200380(func_00113D20(0x2B0));
}

void func_00200350(void) {
    func_00276D48(0x0A015E17, D_0038F928, 0x10);
}

}
