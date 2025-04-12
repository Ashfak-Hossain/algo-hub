/**
 * author:  _Berlin_
 * Description:
 * Verification:
 * Source: modmul - https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h
**/

#pragma once

#include "binpow.h"

// (a + b) % m
inline auto mod_add = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m + b % m + m) % m;
};

// (a - b) % m
inline auto mod_sub = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m - b % m + m) % m;
};

// (a * b) % m using direct multiplication (safe for small values)
inline auto mod_mul = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m * b % m) % m;
};

// (a * b) % m using binary method to prevent overflow (O(log b))
inline auto modMul = [] (int64_t a, int64_t b, int m) -> int64_t {
  int64_t result = 0;
  a %= m;
  while (b > 0) {
    if (b & 1) (result += a) %= m;
    a = (2 * a) % m;
    b >>= 1;
  }
  return result;
};


// (a * b) % m using __int128
inline auto mod_mul128 = [] (int64_t a, int64_t b, int m) -> int64_t {
  return (int64_t)((__int128)a * b % m);
};

// (a * b) % m using floating-point trick (fast, ~2x faster than __int128)
inline auto modmul = [] (uint64_t a, uint64_t b, int mod) -> int64_t {
  int64_t res = a * b - mod * uint64_t(1.L / mod * a * b);
  if (res < 0) res += mod;
  if (res >= (int64_t)mod) res -= mod;
  return res;
};

// (a / b) % m using Fermat's little theorem (b must be coprime to m)
inline auto mod_div = [](int64_t a, int64_t b, int m) -> int64_t {
  return mod_mul(a, binpow_mod(b, m - 2, m), m);
};