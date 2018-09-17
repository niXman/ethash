
#include <ethash/keccak.hpp>
#include <ethash/ethash.hpp>

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

    const int epoch_number = 208;

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

    static const std::uint8_t header[] = {};
    static const std::uint64_t nonce = 0;

    ethash::epoch_context ctx = ethash::get_global_epoch_context(epoch_number);
    ethash::hash256 header_hash = ethash::hash256_from_bytes(header);
    ethash::result res = ethash::hash(ctx, header_hash, nonce);

    std::cout << "done!" << std::endl;

    return EXIT_SUCCESS;
}

/*****************************************************************************/
