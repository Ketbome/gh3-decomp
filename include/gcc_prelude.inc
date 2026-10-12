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
