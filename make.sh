#!/bin/sh
g++ -I./Library/ -I./include/ FegeyaList.cpp -std=c++17 -o lsf
./lsf --h
