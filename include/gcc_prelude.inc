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
