# Prepended to ee-gcc's assembly output so the modern gas encodes it the way SN's assembler did.

# Register moves were 64-bit.
.macro move dst, src
    daddu \dst, \src, $0
.endm
