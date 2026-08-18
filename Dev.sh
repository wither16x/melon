#!/bin/bash

set -e

make clean
make

make -C Test clean
make -C Test

./Test/Build/Test

read -p "Press ENTER to generate docs"

doxygen Doxyfile
./SetupDocs.sh