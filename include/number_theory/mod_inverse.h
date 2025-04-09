/**
  * author:  _Berlin_
  * Description: 
  * Verification:
**/

#pragma once

#include <bits/stdc++.h>
#include "../number_theory/binpow.h"

using namespace std;

// Fermat's inverse: a^(m-2) % m, valid when m is prime
auto mod_inv_fermat = [](int64_t a, int64_t m) -> int64_t {
  return binpow_mod(a, m - 2, m);
};