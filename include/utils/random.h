/**
 * author:  _Berlin_
 * description: Header-only fast RNG utilities for CP
 * includes: rng, randint, randrange, randreal, randset, randshuffle
**/

#pragma once

#include "seed.h"

#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;

namespace berlin_rand {
  // fast 64-bit xor-shift RNG (stateful)
  inline uint64_t& _state() {
    static uint64_t x = berlin_internal::get_seed();
    return x;
  }

  // return random 64-bit unsigned integer
  inline uint64_t rng() {
    auto& x = _state();
    x ^= x << 7;
    x ^= x >> 9;
    return x;
  }

  // random int in [l, r]
  inline int64_t randint(int64_t l, int64_t r) {
    assert(l <= r);
    return l + rng() % uint64_t(r - l + 1);
  }

  // random int in [l, r)
  inline int64_t randrange(int64_t l, int64_t r) {
    assert(l < r);
    return l + rng() % uint64_t(r - l);
  }

  // [0.0, 1.0)
  inline double rand01() {
    return rng() * 5.42101086242752217004e-20; // 1 / 2^64
  }

  // real in [l, r)
  inline double randreal(double l, double r) {
    assert(l < r);
    return l + rand01() * (r - l);
  }

  // n distinct values in [l, r)
  inline vector<int64_t> randset(int64_t l, int64_t r, int64_t n) {
    assert(n <= r - l);
    std::unordered_set<int64_t> s;
    vector<int64_t> res;
    while ((int)res.size() < n) {
      int64_t x = randrange(l, r);
      if (!s.count(x)) s.insert(x), res.push_back(x);
    }
    std::sort(res.begin(), res.end());
    return res;
  }

  // fisher-yates shuffle
  template <typename T>
  void randshuffle(vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 1; i < n; i++) {
      size_t j = randint(0, i);
      std::swap(v[i], v[j]);
    }
  }

  // generate vector of n random ints in [l, r]
  inline vector<int64_t> randvec(int n, int64_t l, int64_t r) {
    assert(n >= 0 && l <= r);
    vector<int64_t> res(n);
    for (int i = 0; i < n; i++)
      res[i] = randint(l, r);
    return res;
  }
}

using berlin_rand::rng;
using berlin_rand::randint;
using berlin_rand::randrange;
using berlin_rand::randreal;
using berlin_rand::randset;
using berlin_rand::randshuffle;