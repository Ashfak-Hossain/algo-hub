/**
 * author:  _Berlin_
 * Description: Modular inverse functions.
 * 1. Fermat's inverse: a^(m-2) % m, valid when m is ** prime **
 * 2. EEA (Extended Euclidean Algorithm): a * x + b * y = gcd(a, b)
 * 3. Eulers theorem: a^(phi(m)-1) % m, valid when gcd(a, m) = 1
 * Complexity: O(log m) for both methods.
 *
 * Usage:
 *   - mod_inv_fermat(a, m) for Fermat's inverse when m is prime.
 *   - mod_inv_eea(a, m) for EEA inverse when m is not necessarily prime.
 **/

#pragma once

#include "binpow.h"

#include <cstdint>
#include <functional>
#include <type_traits>

using std::function;
using std::is_integral_v;

// Fermat's inverse: a^(m-2) % m, valid when m is ** prime **
template <typename T> T mod_inv_fermat(T a, T mod) {
  static_assert(is_integral_v<T>);
  return binpow_mod(a, mod - 2, mod);
}

// EEA (Extended Euclidean Algorithm) for modular inverse //! not tested yet
// a * x + b * y = gcd(a, b)
template <typename T> T mod_inv_eea_rec(T a, T m) {
  static_assert(is_integral_v<T>);
  T x = 0, y = 0;
  auto extEuclid = [&](T a, T b, T &x, T &y) -> T {
    std::function<T(T, T, T &, T &)> recurse = [&](T a, T b, T &x, T &y) -> T {
      if (b == 0) return x = 1, y = 0, a;
      T g = recurse(b, a % b, x, y);
      T newX = y;
      T newY = x - (a / b) * y;
      x = newX, y = newY;
      return g;
    };
    return recurse(a, b, x, y);
  };
  T g = extEuclid(a, m, x, y);
  if (g != 1) return -1;  // Inverse doesn't exist
  return (x % m + m) % m; // Make sure result is positive
}

// Eulers theorem: a^(phi(m)-1) % m, valid when gcd(a, m) = 1 //! not tested, phi not implemented
template <typename T> T mod_inv_euler(T a, T m) {
  static_assert(is_integral_v<T>);
  return binpow_mod(a, phi(m) - 1, m);
}

// range modular inverse (1..n) modulo m //! not completed