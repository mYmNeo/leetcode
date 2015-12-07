#!/usr/bin/env bash
BIN=$(basename "$1"|cut -d'.' -f1)
if [[ $2 = build ]]; then :
    clang++ -x c++ -std=c++11 -o ${BIN}.o -g -O0 -c $1
    clang++ -x c++ -std=c++11 -o main.o -g -O0 -c main.cc
    clang++ -o ${BIN} main.o ${BIN}.o
elif [[ $2 = clean ]]; then :
    rm -rf *.o
    rm -rf ${BIN}
fi
