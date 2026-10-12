#!/bin/sh
# Downloads the build tools into tools/ and creates the Python venv with splat.
# Needs: curl, tar, python3 (3.9+). macOS (arm64) or Linux (x86-64).
set -e
cd "$(dirname "$0")/.."

BINUTILS_VER=v0.10
WIBO_VER=1.2.0
COMPILER=ee-gcc2.95.3-136

case "$(uname -s)" in
    Darwin) binutils=binutils-mips-ps2-decompals-macos-arm64.tar.gz; wibo=wibo-macos ;;
    Linux) binutils=binutils-mips-ps2-decompals-linux-x86-64.tar.gz; wibo=wibo-i686 ;;
    *) echo "unsupported host: $(uname -s)"; exit 1 ;;
esac

mkdir -p tools/binutils tools/wibo tools/compilers tools/bin

curl -sSfL "https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/$BINUTILS_VER/$binutils" \
    | tar xz -C tools/binutils
for t in as ld objcopy objdump nm ar readelf strip; do
    ln -sf "../binutils/mips-ps2-decompals-$t" "tools/bin/mips-linux-gnu-$t"
done

curl -sSfL -o "tools/wibo/$wibo" "https://github.com/decompals/wibo/releases/download/$WIBO_VER/$wibo"
chmod +x "tools/wibo/$wibo"

curl -sSfL "https://github.com/decompme/compilers/releases/download/compilers/ps2_compilers.tar.xz" \
    | tar xJ -C tools/compilers "$COMPILER"

python3 -m venv .venv
.venv/bin/pip install -q "splat64[mips]"

echo "tools ready: .venv/bin/python configure.py && ninja"
