/**
* author: _Berlin_
 * Description: Test suite for binpow and binpow_mod
 * Purpose: Verify correctness across small and large values
 */

#include "../../include/number_theory/binpow.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    // No modulo
    assert(binpow(2, 0) == 1);
    assert(binpow(5, 1) == 5);
    assert(binpow(3, 3) == 27);
    assert(binpow(10, 5) == 100000);

    // Large exponents
    cout << "2^60 = " << binpow(2LL, 60) << "\n";
    cout << "3^30 = " << binpow(3LL, 30) << "\n";

    // With modulo
    constexpr int mod = 1e9 + 7;
    assert(binpow_mod(2, 0, mod) == 1);
    assert(binpow_mod(0, 0, mod) == 1); 
    assert(binpow_mod(2, 10, mod) == 1024);
    assert(binpow_mod(5, 3, mod) == 125);
    assert(binpow_mod(3, 0, mod) == 1);
    assert(binpow_mod(1e9, 0, mod) == 1);

    // Large exponent mod test
    cout << "2^1000000000 % mod = " << binpow_mod(2, 1000000000, mod) << "\n";
    cout << "10^18 % mod = " << binpow_mod(10, 18, mod) << "\n";

    cout << "All binpow tests passed\n";
}