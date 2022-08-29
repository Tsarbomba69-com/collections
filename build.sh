#!/usr/bin/env bash

#----------------------------
# BUILD SHARED LIBRARY
#----------------------------
# 1. Create shared library.
gcc -Wall -Wextra -Werror -fdiagnostics-color=always -ggdb -o libvec.so -fpic -shared vec.c
# 2. Compile code that will going to use the library.
gcc -c main.c -o main.o
# 3. Link shared library to your source object.
gcc -o main main.o -lvec -L.
# 3.1. Delete object file (optional)
rm main.o
# 4. Set lib path env variable & execute program.
LD_LIBRARY_PATH=. ./main
#----------------------------

#----------------------------
# BUILD STATIC LIBRARY
#----------------------------
# # 1. Create static library.
# gcc -Wall -Wextra -Werror -fdiagnostics-color=always -ggdb -o vec.o -c vec.c
# # 2. Compile code that will going to use the library.
# ar -rcs vec.a vec.o
# # 2. Compile code that will going to use the library.
# gcc -c main.c -o _main.o
# # 3. Link shared library to your source object.
# gcc main.c -L. -lvec -o _main
