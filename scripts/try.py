#!/usr/bin/env python3
"""One attempt: adds the GP_DATA lines the file needs, then checks the given functions (fcheck).

Usage: .venv/bin/python scripts/try.py <file> <func> [<func>...]
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = str(ROOT / ".venv" / "bin" / "python")

subprocess.run([PY, str(ROOT / "scripts" / "fix_gp_data.py"), sys.argv[1]], cwd=ROOT, capture_output=True)
sys.exit(subprocess.run([PY, str(ROOT / "scripts" / "fcheck.py")] + sys.argv[1:], cwd=ROOT).returncode)
