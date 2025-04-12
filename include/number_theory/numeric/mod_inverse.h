/**
  * author:  _Berlin_
  * Description: Fermat's modular inverse: a^(m-2) % m, valid when m is prime.
  * Verification: 
  * Complexity: O(log m) using binary exponentiation.
**/

#pragma once

#include "binpow.h"

// Fermat's inverse: a^(m-2) % m, valid when m is prime
template <typename T>
T mod_inv_fermat(T a, T mod) {
  static_assert(std::is_integral<T>::value);
  return binpow_mod(a, mod - 2, mod);
}