#!/bin/bash
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -c ./src/*.c -I/inc
gcc -o app.exe *.o
