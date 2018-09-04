
#include <ethash/keccak.hpp>

#include <string>
#include <iostream>

#include <cassert>

/*****************************************************************************/

template<typename Hash>
inline std::string toHex(const Hash& h) {
    static const char *hex_chars = "0123456789abcdef";
    std::string str;
    str.reserve(sizeof(h) * 2);

    for (auto b: h.bytes) {
        str.push_back(hex_chars[uint8_t(b) >> 4]);
        str.push_back(hex_chars[uint8_t(b) & 0xf]);
    }

    return str;
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

int main() {
    ethash::hash256 h256 = ethash::keccak256(nullptr, 0);
    assert(toHex(h256) == "c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470");

    ethash::hash512 h512 = ethash::keccak512(nullptr, 0);
    assert(toHex(h512) == "0eab42de4c3ceb9235fc91acffe746b29c29a8c366b7c60e4e67c466f36a4304c00fa9caf9d87976ba469bcbe06713b435f091ef2769fb160cdab33d3670680e");


    std::cout << "done!" << std::endl;
}

/*****************************************************************************/
