#!/bin/sh
make
./compiler in53 out.s
gcc -o out out.s
./out
