
#include <ethash/keccak.hpp>

int main() {
	ethash::hash256 h = ethash::keccak256(nullptr, 0);
}
