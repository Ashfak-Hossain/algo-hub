#include "number_theory/numeric/mod_inverse.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"
#include "number_theory/primality/is_prime.h"
#include "utils/random.h"

#include <iostream>
#include <numeric>

using std::gcd;
using std::to_string;

class TestModInverse final : public BerlinTestBase {
public:
  TestModInverse() : BerlinTestBase("TestModInverse") {}

  void run(const int case_id) override {
    constexpr int64_t mod = 1'000'000'007; // Prime modulus
    constexpr int64_t non_prime_mod = 1'000'000'006;

    switch (case_id) {
    case 0:
      check(mod_inv_fermat<int64_t>(1, mod), int64_t(1));
      break;
    case 1:
      check(mod_inv_fermat<int64_t>(2, mod), int64_t(500000004));
      break;
    case 2:
      check(mod_inv_fermat<int64_t>(10, mod), int64_t(700000005));
      break;
    case 3: {
      // Test with a non-prime modulus - should throw or return 0
      int64_t a = 123456789;
      try {
        int64_t result = mod_inv_fermat<int64_t>(a, non_prime_mod);
        check(result, int64_t(0), "Expected failure for non-prime modulus");
      } catch (const std::exception &) {
        check(true, true); // Test passes if exception is thrown
      }
      break;
    }
    case 4: {
      // Randomized test for modular inverse
      for (int i = 0; i < 5; i++) {
        int64_t a = randint<int64_t>(1, mod - 1);
        if (gcd(a, mod) != 1) continue; // Skip if not coprime
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1),
              "Random test failed for a = " + to_string(a) + ", inv = " + to_string(inv));
      }
      break;
    }
    case 5: {
      // Test mod-1
      int64_t result = mod_inv_fermat<int64_t>(mod - 1, mod);
      check(result, int64_t(mod - 1));
      check((result * (mod - 1)) % mod, int64_t(1));
      break;
    }
    case 6: {
      // Test with 0 - should throw or return 0
      try {
        int64_t result = mod_inv_fermat<int64_t>(0, mod);
        check(result, int64_t(0), "Expected failure for input 0");
      } catch (const std::exception &) {
        check(true, true); // Test passes if exception is thrown
      }
      break;
    }
    default:
      break;
    }
  }

  [[nodiscard]] int getCaseCount() const override { return 7; }
};

BERLIN_REGISTER_TEST(TestModInverse);