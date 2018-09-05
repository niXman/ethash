cmake_minimum_required(VERSION 2.8)
project(ethash)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(ethash
    lib/ethash/keccak.c
    lib/ethash/keccakf1600.c
    lib/ethash/primes.c
    lib/ethash/ethash.cpp
    main.cpp)
