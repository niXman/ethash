#!/bin/bash

g++ -std=c++11 -Iinclude lib/ethash/keccakf1600.c lib/ethash/keccak.c main.cpp -otest
