
#include <ethash/keccak.hpp>
#include <ethash/ethash.hpp>

#include <array>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <type_traits>

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
    const int epoch_number = 212;
    static const std::uint8_t header[] = {
             0xcf, 0x0a, 0x1b, 0xae, 0xa1, 0xae, 0x2a, 0x89
            ,0x1e, 0x40, 0x4d, 0x06, 0x62, 0x59, 0x02, 0x59
            ,0xed, 0xde, 0x81, 0xa1, 0x7a, 0xfa, 0x68, 0x74
            ,0x18, 0xe2, 0xea, 0x03, 0x3b, 0xe5, 0xfa, 0x4b
    };
    static_assert(sizeof(header) == 32);
    static const std::uint64_t nonce = 1654938163419715916;

//    ethash::hash256 h256 = ethash::keccak256(nullptr, 0);
//    assert(toHex(h256) == "c5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470");
//
//    ethash::hash512 h512 = ethash::keccak512(nullptr, 0);
//    assert(toHex(h512) == "0eab42de4c3ceb9235fc91acffe746b29c29a8c366b7c60e4e67c466f36a4304c00fa9caf9d87976ba469bcbe06713b435f091ef2769fb160cdab33d3670680e");

//    static constexpr size_t context_alloc_size = sizeof(ethash::hash512);
//
//    const int light_cache_num_items = ethash::calculate_light_cache_num_items(epoch_number);
//    const size_t light_cache_size = ethash::get_light_cache_size(light_cache_num_items);
//    const size_t alloc_size = context_alloc_size + light_cache_size;
//
//    char* const alloc_data = static_cast<char*>(std::malloc(alloc_size));
//    if (!alloc_data) {
//        std::cout << "error!" << std::endl;
//
//        return EXIT_FAILURE;
//    }
//
//    ethash::hash512 *light_cache = reinterpret_cast<ethash::hash512*>(alloc_data + context_alloc_size);
//
//    const ethash::hash256 epoch_seed = ethash::calculate_epoch_seed(epoch_number);
//    ethash::build_light_cache(light_cache, light_cache_num_items, epoch_seed);

//    ethash::epoch_context_ptr epoch_ctx = ethash::create_epoch_context(epoch_number);
//    const ethash::hash1024 di = ethash::calculate_dataset_item(*epoch_ctx, 0u);

    ethash::hash256 header_hash = ethash::hash256_from_bytes(header);
    ethash::epoch_context ctx = ethash::get_global_epoch_context(epoch_number);
    auto res = ethash::hash(ctx, header_hash, nonce);

    std::cout << toHex(res.mix_hash) << std::endl;
    std::cout << toHex(res.final_hash) << std::endl;

    std::cout << "done!" << std::endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************/
