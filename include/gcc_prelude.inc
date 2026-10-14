# Prepended to ee-gcc's assembly output so the modern gas encodes it the way SN's assembler did.

# Register moves were 64-bit.
.macro move dst, src
    daddu \dst, \src, $0
.endm

# The R5900's only float-to-int conversion truncates, and SN's assembler took the name `cvt.w.s` for it. The
# modern gas only knows it as `trunc.w.s` (same encoding).
.macro cvt.w.s dst, src
    trunc.w.s \dst, \src
.endm

# `li.d` into an integer register (a `double` constant for the soft-float library): gas refuses the mnemonic for the
# r5900; SN's assembler encoded it like `dli` of the constant's bits. Assembled as mips3, gas does the same.
.macro __gp_lid
    .macro li.d reg, value
        .purgem li.d
        .set push
        .set mips3
        li.d \reg, \value
        .set pop
        __gp_lid
    .endm
.endm
__gp_lid

# Hazard nops. For the R5900 (MIPS III) the modern gas keeps one instruction between mfc1 and the next use of its
# register, inserting a nop where the compiler left none; SN's assembler did not. It did keep the nop after mtc1 and
# between an FPU compare and bc1t/bc1f, so only mfc1 is wrapped (measured over ~3,900 matched functions). gas decides the nop while assembling the next
# instruction, from what it remembers of the previous one; an empty data directive under `.set mips64` makes it settle
# early on "no nop". (Approach from the BT3-Decompiled project's gcc_prelude.inc, CC0.)
.macro __gp_forget
    .set push
    .set mips64
    .fill 0
    .set pop
.endm

.macro __gp_hazard mnem
    .macro \mnem operands:vararg
        .purgem \mnem
        \mnem \operands
        __gp_forget
        __gp_hazard \mnem
    .endm
.endm

.irp mnem, mfc1
    __gp_hazard \mnem
.endr

# `sqrt.s fd, ft`: the R5900 takes the operand from the ft field (bits 16-20); the modern gas puts it in fs (bits
# 11-15) even for this CPU. (Same fix as the BT3-Decompiled project's prelude, CC0.)
.macro __gp_regnum sym, reg
    .set \sym, 99
    .irp n, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
        .ifc \reg,$f\n
            .set \sym, \n
        .endif
    .endr
.endm

.macro sqrt.s fd, ft
    __gp_regnum .L__gp_fd, \fd
    __gp_regnum .L__gp_ft, \ft
    .if (.L__gp_fd > 31) || (.L__gp_ft > 31)
        .error "gcc_prelude.inc: sqrt.s \fd, \ft: operands must be written $fN"
    .endif
    .word 0x46000004 | (.L__gp_ft << 16) | (.L__gp_fd << 6)
.endm
