/**
 * author:  _Berlin_
 * Description: Binary exponentiation with and without modulo in O(log b).
 * Supports generic numeric types using templates.
 * Usage:
 *  - binpow(a, b) for a^b
 *  - binpow_mod(a, b, m) for a^b % m
 * Time complexity: O(log b)
 * Space complexity: O(1)
 * Verification: https://cses.fi/problemset/result/12609808/
 **/

#pragma once

#include <type_traits>

// a^b without modulo
template <typename T> T binpow(T a, T b) {
  static_assert(std::is_arithmetic_v<T>);
  T res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

// a^b % m
template <typename T> T binpow_mod(T a, T b, T m) {
  static_assert(std::is_integral_v<T>);
  T res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) (res *= a) %= m;
    (a *= a) %= m;
    b >>= 1;
  }
  return res;
}