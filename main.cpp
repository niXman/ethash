
#include <ethash/keccak.hpp>

int main() {
	ethash::hash256 h = ethash::keccak256(nullptr, 0);
}

// g++ -std=c++11 -I../include ../lib/ethash/keccakf1600.c ../lib/ethash/keccak.c main.cpp -otest
