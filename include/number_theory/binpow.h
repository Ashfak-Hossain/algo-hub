/**
  * author:  _Berlin_
  * Description: binary exponentiation with mod and without mod in O(log b)
  * Verification: https://cses.fi/problemset/task/1712/
**/

#pragma once

#include <cstdint>

using namespace std;

// a^b without modulo
inline auto binpow = [](int64_t a, int64_t b) -> int64_t {
  int64_t res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
};

// a^b % m
inline auto binpow_mod = [](int64_t a, int64_t b, int m) -> int64_t {
  int64_t res = 1;
  a %= m;
  while (b) {
    if (b & 1) (res *= a) %= m;
    (a *= a) %= m;
    b >>= 1;
  }
  return res;
};