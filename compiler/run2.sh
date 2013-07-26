#!/bin/sh
make
./compiler in54 out.s
gcc -o out out.s
./out
