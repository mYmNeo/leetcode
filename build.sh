#!/bin/sh
BIN=$(echo "$1"|cut -d'.' -f1)
if [[ $2 = build ]];then
    clang++ -x c++ -std=c++11 -o ${BIN}.o -O3 -c ${BIN}.cc
    clang++ -x c++ -std=c++11 -o main.o -O3 -c main.cc
    clang++ -o ${BIN} *.o
elif [[ $2 = clean ]];then
    rm -rf *.o
    rm -rf ${BIN}
fi
