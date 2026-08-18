#!/bin/bash

set -e

# the prefix must contains:
# usr/
# usr/include/
# usr/lib/
PREFIX="$1"

mkdir -p "$PREFIX"/usr/include/Melon/

cp -v -r Include/* "$PREFIX"/usr/include/Melon/
cp -v Build/libmelon.a "$PREFIX"/usr/lib/libmelon.a