/**
 *  author: _Berlin_
 *  Description: Tests for modular arithmetic functions (mod_add, mod_mul, modMul, modmul)
**/

#include "../../include/number_theory/mod_arithmetic.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    constexpr int M = 1e9 + 7;

    // mod_add
    assert(mod_add(10, 20, M) == 30);
    assert(mod_add(-5, 5, M) == 0);
    assert(mod_add(1e9, 1e9, M) == static_cast<int64_t>(2e9) % M);

    // mod_sub
    assert(mod_sub(10, 20, M) == (10 - 20 + M) % M);
    assert(mod_sub(0, 1, M) == M - 1);
    assert(mod_sub(5, 5, M) == 0);

    // mod_mul
    assert(mod_mul(10, 20, M) == 200);
    assert(mod_mul(1e9, 3, M) == (static_cast<int64_t>(1e9) * 3) % M);

    // modMul (binary method)
    assert(modMul(1e9, 1e9, M) == (static_cast<int64_t>(1e9) * static_cast<int64_t>(1e9) % M));

    // modmul (floating-point trick)
    assert(modmul(1e9, 1e9, M) == (static_cast<int64_t>(1e9) * static_cast<int64_t>(1e9) % M));

    // cross test: all should match
    for (int i = 1; i <= 1000000000; i *= 10) {
      for (int j = 1; j <= 1000000000; j *= 10) {
        const int64_t naive = mod_mul(i, j, M);
        const int64_t bin = modMul(i, j, M);
        const int64_t fpt = modmul(i, j, M);
        assert(naive == bin);
        assert(bin == fpt);
      }
    }

    // Test a/b % m = (a * b⁻¹) % m
    for (int a = 1; a <= 10; ++a) 
      {for (int b = 1; b <= 10; ++b) {
        if (b != 0) {
          const int result = mod_div(a, b, M);
          assert(mod_mul(result, b, M) == a % M);
        }
      }
    }

    cout << "All mod_arithmetic tests passed\n";
}