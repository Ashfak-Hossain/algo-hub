/**
  * author:  _Berlin_
  * Description: 
  * Verification:
**/

#pragma once

#include "../number_theory/binpow.h"

// Fermat's inverse: a^(m-2) % m, valid when m is prime
auto mod_inv_fermat = [](int64_t a, int m) -> int64_t {
  return binpow_mod(a, m - 2, m);
};