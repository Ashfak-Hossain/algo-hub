/**
 * author: _Berlin_
 * Description: Modular arithmetic class for performing operations under a modulus.
 * Usage: Define `mint<MOD, RT>` where MOD is the modulus and RT is the primitive root (optional).
 * Time complexity: O(log MOD) for modular exponentiation and inversion.
 * Space complexity: O(1).
 * Source: benq
 **/

#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>

template <int MOD, int RT = 5> struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; } // Primitive root for FFT

  int v;
  explicit operator int() const { return v; } // Explicit conversion to int
  mint() : v(0) {}
  mint(int64_t _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  // Comparison operators
  bool operator==(const mint &o) const { return v == o.v; }
  friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
  friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
  // Arithmetic operators
  mint &operator+=(const mint &o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  mint &operator-=(const mint &o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  mint &operator*=(const mint &o) {
    v = int((int64_t)v * o.v % MOD);
    return *this;
  }
  mint &operator/=(const mint &o) { return (*this) *= inv(o); }
  // Unary operators
  mint operator-() const { return mint(-v); }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  // Friend functions for arithmetic operations
  friend mint operator+(mint a, const mint &b) { return a += b; }
  friend mint operator-(mint a, const mint &b) { return a -= b; }
  friend mint operator*(mint a, const mint &b) { return a *= b; }
  friend mint operator/(mint a, const mint &b) { return a /= b; }
  // Modular exponentiation
  friend mint pow(mint a, int64_t p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  // Modular inverse
  friend mint inv(const mint &a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
};

// mi result = pow(mi(a), b);