#!/bin/sh
# Finishes a file: GP_DATA and padding fixes, every C/C++ function must MATCH, then commits the file and the worklog.
# Usage: scripts/done.sh <file> <worklog> "<commit message>"
cd "$(dirname "$0")/.." || exit 1
file=$1; log=$2; msg=$3
.venv/bin/python scripts/fix_gp_data.py "$file" > /dev/null
.venv/bin/python scripts/fix_padding.py "$file" > /dev/null
out=$(.venv/bin/python scripts/fcheck.py "$file" --all 2>&1)
if echo "$out" | grep -v ": MATCH$" | grep -q .; then
    echo "NOT COMMITTED: something does not match or does not compile:"
    echo "$out" | grep -v ": MATCH$" | head -20
    exit 1
fi
echo "$out" | grep -c ": MATCH$" | sed 's/$/ functions match/'
for i in 1 2 3 4 5 6; do
    git add "$file" "$log" && git commit -q -m "$msg" && { git log --oneline -1; exit 0; }
    sleep 3
done
echo "commit failed"; exit 1
