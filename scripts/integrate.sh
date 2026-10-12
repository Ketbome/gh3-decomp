#!/bin/sh
# Verifies the committed HEAD in a separate worktree (so workers' asm/ and build/ are untouched) and, if the rebuilt
# executable is byte-identical, pushes it. Usage: scripts/integrate.sh [worktree dir]
set -e
cd "$(dirname "$0")/.."
ROOT=$PWD
WT=${1:-${TMPDIR:-/tmp}/gh3-integrate}
REV=$(git rev-parse HEAD)
rm -rf "$WT"
git worktree prune
git worktree add -q --detach "$WT" "$REV"
cd "$WT"
mkdir -p disc
ln -s "$ROOT/disc/SLUS_216.72" disc/SLUS_216.72
ln -s "$ROOT/tools" tools
ln -s "$ROOT/.venv" .venv
.venv/bin/python configure.py > /dev/null
.venv/bin/python scripts/sync_src.py | tail -1
ninja -j4 > ninja.log 2>&1 || { tail -20 ninja.log; exit 1; }
.venv/bin/python scripts/progress.py
cd "$ROOT"
git worktree remove --force "$WT"
git push -q origin "$REV:main"
echo "pushed $REV"
