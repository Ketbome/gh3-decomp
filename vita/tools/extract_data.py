#!/usr/bin/env python3
"""
Extrai o bloco de dados inicializados do executavel do PS2 para um arquivo que
o port carrega em tempo de execucao.

O que e' copiado
----------------
    ROM  0x22A080 .. 0x272A40     (imagem plana: vram - 0x100000)
    vram 0x32A080 .. 0x372A40     (.data + .rodata + .gcc_except_table + .sdata)

Esse intervalo cobre tudo que o linker original inicializava: strings, tabelas
de salto (`jtbl_*`), constantes float e os ponteiros de vtable. O `.sbss` e o
`.bss` (vram 0x372A80 em diante) nao entram: nascem zerados.

O destino no port e' `gh3_data_arena` (vita/tools/gen_stubs.py), ancorada em
0x0032A080. Copiar o blob para o inicio da arena reproduz os enderecos
originais sem realocacao: `gh3_data_arena + (0x368080 - 0x32A080)` e' o
`D_00368080` original.

Uso (a partir da raiz do clone do gh3-decomp):
    python vita/tools/extract_data.py
    python vita/tools/extract_data.py --rom disc/SLUS_216.72.rom \\
                                      --out build-vita/gh3_data.bin

O arquivo gerado vai para `ux0:data/gh3/gh3_data.bin` no Vita.
"""

import argparse
import hashlib
import pathlib
import sys

# Valores de config/SLUS_216.72.yaml (segmentos "cod").
IMAGE_VRAM = 0x00100000  # endereco do primeiro byte da imagem plana
DATA_START = 0x22A080    # .data
DATA_END = 0x272A40      # fim de .sdata (o .sbss comeca em 0x372A80)
DATA_SIZE = DATA_END - DATA_START

# Alguns simbolos para conferir que o blob e' o certo (enderecos de vram).
CHECKS = [
    (0x0032A080, "inicio de .data"),
    (0x00337800, "inicio de .rodata"),
    (0x00368080, "inicio de .sdata"),
    (0x00368A38, "heap global"),
]


def printable_runs(blob: bytes, minimum: int = 8, limit: int = 3) -> list[str]:
    """Amostra de strings ASCII do blob (sanidade: .rodata tem texto)."""
    out: list[str] = []
    start = None
    for i, byte in enumerate(blob):
        if 0x20 <= byte < 0x7F:
            if start is None:
                start = i
            continue
        if start is not None and i - start >= minimum:
            out.append(blob[start:i].decode("ascii", "replace"))
            if len(out) >= limit:
                return out
        start = None
    return out


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", type=pathlib.Path,
                    default=pathlib.Path("disc/SLUS_216.72.rom"),
                    help="imagem plana do executavel (configure.py gera)")
    ap.add_argument("--out", type=pathlib.Path,
                    default=pathlib.Path("build-vita/gh3_data.bin"))
    ap.add_argument("--start", type=lambda s: int(s, 0), default=DATA_START)
    ap.add_argument("--end", type=lambda s: int(s, 0), default=DATA_END)
    args = ap.parse_args()

    if not args.rom.exists():
        sys.exit(
            f"nao encontrei {args.rom}\n"
            "  rode `python configure.py` na raiz do gh3-decomp para extrair do ISO,\n"
            "  ou aponte --rom para a imagem plana (objcopy -O binary do ELF)")

    size = args.end - args.start
    if size <= 0:
        sys.exit(f"intervalo invalido: 0x{args.start:X}..0x{args.end:X}")

    rom_size = args.rom.stat().st_size
    if args.end > rom_size:
        sys.exit(f"{args.rom} tem 0x{rom_size:X} bytes; "
                 f"0x{args.end:X} esta fora")

    with args.rom.open("rb") as f:
        f.seek(args.start)
        blob = f.read(size)

    if len(blob) != size:
        sys.exit(f"leitura curta: {len(blob)} de {size} bytes")

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes(blob)

    vram_start = args.start + IMAGE_VRAM
    vram_end = args.end + IMAGE_VRAM

    print(f"rom        : {args.rom} (0x{rom_size:X} bytes)")
    print(f"intervalo  : rom 0x{args.start:06X}..0x{args.end:06X}")
    print(f"             vram 0x{vram_start:08X}..0x{vram_end:08X}")
    print(f"saida      : {args.out} ({len(blob)} bytes, "
          f"{len(blob) / 1024:.0f} KiB)")
    print(f"sha1       : {hashlib.sha1(blob).hexdigest()}")

    # Sanidade: o blob tem que ser o .data/.rodata deste executavel.
    for vram, what in CHECKS:
        off = vram - vram_start
        if 0 <= off < len(blob):
            word = int.from_bytes(blob[off:off + 4], "little")
            print(f"  {what:28s} +0x{off:05X} = 0x{word:08X}")

    strings = printable_runs(blob)
    if strings:
        print("  strings em .rodata           "
              + " | ".join(repr(s) for s in strings))
    else:
        print("  AVISO: nenhuma string ASCII no blob; e' o executavel certo?")

    print("\ncoloque em ux0:data/gh3/gh3_data.bin")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
