#!/bin/bash

set -e

# the prefix must contains:
# usr/
# usr/include/
# usr/lib/
PREFIX="$1"

mkdir -p "$PREFIX"/usr/include/Melon/

cp -v Include/*.hpp "$PREFIX"/usr/include/Melon/
cp -v Build/melon.a* "$PREFIX"/usr/lib/