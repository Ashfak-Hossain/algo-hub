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

  // [0.0, 1.0)
  inline double rand01() {
    return static_cast<double>(rng()) * 5.42101086242752217004e-20; // 1 / 2^64
  }

  // random integer in [l, r]
  template <typename T>
  T randint(T l, T r) {
    static_assert(std::is_integral_v<T>, "randint requires integral types");
    assert(l <= r);
    return l + T(rng() % uint64_t(r - l + 1));
  }

  // random integer in [l, r)
  template <typename T>
  T randrange(T l, T r) {
    static_assert(std::is_integral_v<T>, "randrange requires integral types");
    assert(l < r);
    return l + T(rng() % uint64_t(r - l));
  }

  // real in [l, r)
  template <typename T>
  T randreal(T l, T r) {
    static_assert(std::is_floating_point_v<T>, "randreal requires floating-point types");
    assert(l < r);
    return l + rand01() * (r - l);
  }

  // generate vector of n random integers in [l, r]
  template <typename T>
  vector<T> randvec(int n, T l, T r) {
    static_assert(std::is_integral_v<T>, "randvec requires integral types");
    assert(n >= 0 && l <= r);
    vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = randint(l, r);
    return res;
  }

  // n distinct values in [l, r)
  template <typename T>
  vector<T> randset(T l, T r, int64_t n) {
    static_assert(std::is_integral_v<T>, "randset requires integral types");
    assert(n <= r - l);
    std::unordered_set<T> s;
    vector<T> res;
    while (int(res.size()) < n) {
      T x = randrange(l, r);
      if (!s.count(x)) s.insert(x), res.push_back(x);
    }
    std::sort(res.begin(), res.end());
    return res;
  }

  // shuffle vector in place
  template <typename T>
  void randshuffle(vector<T>& v) {
    const size_t n = v.size();
    for (size_t i = 1; i < n; i++) {
      auto j = randint<size_t>(0, i);
      std::swap(v[i], v[j]);
    }
  }
}

using berlin_rand::rng;
using berlin_rand::randint;
using berlin_rand::randrange;
using berlin_rand::randreal;
using berlin_rand::randset;
using berlin_rand::randshuffle;
using berlin_rand::randvec;