/**
  * author:  _Berlin_
  * Description: 
  * Verification:
  * Source: modmul - https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h
**/

#pragma once

#include "binpow.h"

using namespace std;

using ull = unsigned long long;

// (a + b) % m
auto mod_add = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m + b % m + m) % m;
};

// (a - b) % m
auto mod_sub = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m - b % m + m) % m;
};

// (a * b) % m using direct multiplication (safe for small values)
auto mod_mul = [](int64_t a, int64_t b, int m) -> int64_t {
  return (a % m * b % m) % m;
};

// (a * b) % m using binary method to prevent overflow (O(log b))
auto modMul = [] (int64_t a, int64_t b, int64_t m) -> int64_t {
  int64_t result = 0;
  a %= m;
  while (b > 0) {
    if (b & 1) (result += a) %= m;
    a = (2 * a) % m;
    b >>= 1;
  }
  return result;
};

// (a * b) % m using floating-point trick (fast, ~2x faster than __int128)
auto modmul = [] (ull a, ull b, ull mod) -> int64_t {
  int64_t res = a * b - mod * ull(1.L / mod * a * b);
  if (res < 0) res += mod;
  if (res >= (int64_t)mod) res -= mod;
  return res;
};

// (a / b) % m using Fermat's little theorem (b must be coprime to m)
auto mod_div = [](int64_t a, int64_t b, int m) -> int64_t {
  return mod_mul(a, binpow_mod(b, m - 2, m), m);
};