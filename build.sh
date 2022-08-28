#!/usr/bin/env bash

# 1. Create shared library.
gcc -o libvec.so -fpic -shared vec.c
# 2. Compile code that will going to use the library.
gcc -c main.c -o main.o
# 3. Link shared library to your source object.
gcc -o main main.o -lvec -L.
# 4. Set lib path env variable & execute program.
LD_LIBRARY_PATH=. ./main
