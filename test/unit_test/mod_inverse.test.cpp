/**
 * author: _Berlin_
 * Description: Test file for modular inverse using Fermat's Theorem
 */

#include "../../include/number_theory/mod_inverse.h"
#include "../../include/number_theory/mod_arithmetic.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  const int MOD = 1e9 + 7;

  // a * mod_inv(a) % m = 1 (if a and m are coprime and m is prime)
  for (int i = 1; i <= 100; i++) {
    int inv = mod_inv_fermat(i, MOD);
    assert(mod_mul(i, inv, MOD) == 1);
  }

  cout << "All Fermat modular inverse tests passed\n";
}