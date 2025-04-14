/**
 * author:  _Berlin_
 * description: seed generator
 */

 #pragma once

 #include <chrono>

namespace berlin_internal {
  // Non-deterministic seed using high-precision clock
  inline uint64_t time_seed() {
    uint64_t now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    now ^= 0x9e3779b97f4a7c15ULL; // hash-like scramble
    now ^= now << 17;
    now ^= now >> 29;
    now ^= now << 41;
    return now;
  }

  // Fixed value seed for deterministic debugging
  constexpr uint64_t fixed_seed() {
    return 135792468013579ULL;
  }

  // Seed selector based on debug flags
  inline uint64_t get_seed() {
    #if defined(BERLIN_LOCAL) && !defined(USE_RANDOM_SEED)
    return fixed_seed();
    #else
    return time_seed();
    #endif
  }
}