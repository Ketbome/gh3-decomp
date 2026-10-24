#!/usr/bin/env python3
"""Writes the progress report in objdiff's JSON format (report version 2), for ByteMatch.

Reads config/functions.txt (written by configure.py) and the INCLUDE_ASM lines of src/, so it runs without the disc
(CI). Same figures as scripts/progress.py: a function in C++ is matched, since the whole executable is verified
byte-identical before every push; one still in INCLUDE_ASM is not. One unit per src/game file.

Usage: scripts/report.py [output] (default build/SLUS_216.72/report.json)
"""

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def measures(funcs, asm):
    total = sum(size for _, _, size in funcs)
    matched = sum(size for name, _, size in funcs if name not in asm)
    count = sum(1 for name, _, _ in funcs if name not in asm)
    pct = 100 * matched / total if total else 100.0
    return {
        "fuzzy_match_percent": pct,
        "total_code": total,
        "matched_code": matched,
        "matched_code_percent": pct,
        "total_functions": len(funcs),
        "matched_functions": count,
        "matched_functions_percent": 100 * count / len(funcs) if funcs else 100.0,
        "complete_code": total if matched == total else 0,
        "complete_code_percent": 100.0 if matched == total else 0.0,
        "total_units": 1,
        "complete_units": 1 if matched == total else 0,
    }


def main():
    out = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "build" / "SLUS_216.72" / "report.json"
    units = {}
    for line in (ROOT / "config" / "functions.txt").read_text().splitlines():
        if line and not line.startswith("#"):
            name, addr, size, unit = line.split()
            units.setdefault(unit, []).append((name, int(addr, 16), int(size, 16)))
    asm = set()
    for src in (ROOT / "src").rglob("*.c*"):
        asm.update(re.findall(r"^INCLUDE_ASM\([^,]+,\s*(\w+)\);", src.read_text(), re.M))

    report_units = []
    for unit, funcs in sorted(units.items()):
        src = next((ROOT / "src" / "game").glob(f"{unit}.c*"))
        m = measures(funcs, asm)
        base = funcs[0][1]
        report_units.append({
            "name": f"game/{unit}",
            "measures": m,
            "functions": [{
                "name": name,
                "size": size,
                "fuzzy_match_percent": 0.0 if name in asm else 100.0,
                "metadata": {"virtual_address": addr},
                "address": addr - base,
            } for name, addr, size in funcs],
            "metadata": {"complete": m["complete_units"] == 1, "source_path": str(src.relative_to(ROOT))},
        })
    top = measures([f for funcs in units.values() for f in funcs], asm)
    top["total_units"] = len(report_units)
    top["complete_units"] = sum(u["measures"]["complete_units"] for u in report_units)
    top["complete_code"] = sum(u["measures"]["complete_code"] for u in report_units)
    top["complete_code_percent"] = 100 * top["complete_code"] / top["total_code"]
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"measures": top, "units": report_units, "version": 2}, indent=1) + "\n")
    print(f"{out}: {top['matched_code_percent']:.2f}% of code, "
          f"{top['matched_functions']} / {top['total_functions']} functions, {top['complete_units']} / {len(report_units)} files complete")


if __name__ == "__main__":
    main()
