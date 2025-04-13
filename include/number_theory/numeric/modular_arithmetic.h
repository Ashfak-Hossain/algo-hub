/**
 * author:  _Berlin_
 * Description: Modular arithmetic operations (addition, subtraction, multiplication, division).
 * Complexity: O(1) for addition, subtraction, and multiplication. O(log m) for division.
 * Source: modmul - https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h
**/

#pragma once

#include "binpow.h"

// (a + b) % m
template <typename T>
T mod_add(T a, T b, T m) {
  return (a % m + b % m + m) % m;
}

// (a - b) % m
template <typename T>
T mod_sub(T a, T b, T m) {
  return (a % m - b % m + m) % m;
}

// (a * b) % m using direct multiplication (safe for small values)
template <typename T>
T mod_mul(T a, T b, T m) {
  return (a % m * b % m) % m;
}

// (a * b) % m using binary method to prevent overflow (O(log b))
template <typename T>
T mod_mul_bin(T a, T b, T m) {
  T result = 0;
  a %= m;
  while (b > 0) {
    if (b & 1) (result += a) %= m;
    a = (2 * a) % m;
    b >>= 1;
  }
  return result;
}

// (a * b) % m using __int128 (for large values, requires compiler support)
template <typename T>
T mod_mul128(T a, T b, T m) {
#ifdef __SIZEOF_INT128__
  return static_cast<T>((__int128)a * b % m);
#else
  static_assert(sizeof(T) < 8, "mod_mul128 requires __int128 support on this platform.");
  return T(); // fallback
#endif
}

// (a * b) % m using floating-point trick (fast, ~2x faster than __int128)
template <typename T>
T mod_mul_fp(T a, T b, T m) {
  long double res = static_cast<long double>(a) * b - m * static_cast<long double>(1.L / m * a * b);
  T result = static_cast<T>(res);
  if (result < 0) result += m;
  if (result >= m) result -= m;
  return result;
}

// (a / b) % m using Fermat's little theorem (b must be coprime to m)
template <typename T>
T mod_div(T a, T b, T m) {
  return mod_mul(a, binpow_mod(b, m - 2, m), m);
}