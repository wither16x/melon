#!/bin/bash

set -e

make clean
make

make -C Test clean
make -C Test

./Test/Build/Test