#!/usr/bin/env bash

set -xe

#----------------------------
# BUILD SHARED LIBRARY
#----------------------------
# # 1. Compile files for shared library.
# # gcc -Wall -Wextra -Werror -fdiagnostics-color=always -ggdb -o libvec.so -fpic -shared vec.c
# gcc -Wall -Wextra -fdiagnostics-color=always -ggdb -o libvec.so -fpic -shared vec.c
# gcc -Wall -Wextra -fdiagnostics-color=always -ggdb -o libhashmap.so -fpic -shared hashmap.c
# 2. Compile code that will use the library.
# gcc -c main.c -o main.o
# # 3. Link shared libraries to your source object.
# gcc -o main main.o -lvec -lhashmap -L.
# # 3.1. Delete object files (optional)
# rm *.o 
# # 4. Set lib path env variable & execute program.
# LD_LIBRARY_PATH=. ./main
#----------------------------

#----------------------------
# BUILD STATIC LIBRARY
#----------------------------
# 1. Compile files for static library.
gcc -Wall -Wextra -fdiagnostics-color=always -ggdb -o vec.o -c vec.c
gcc -Wall -Wextra -fdiagnostics-color=always -ggdb -o hashmap.o -c hashmap.c
# 2. Generate static library from object file.
ar -rcs vec.a vec.o
ar -rcs hashmap.a hashmap.o
# 2. Compile code that will use the library.
gcc -c main.c -o main.o
# 3. Link static libraries to your source object.
gcc -o main main.o -l:vec.a -l:hashmap.a -L.
# 3.1. Delete object files (optional)
rm *.o 
# Execute program
./main