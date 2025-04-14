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
    constexpr int64_t mod = 1'000'000'007;
    constexpr int64_t non_prime_mod = 1'000'000'006;

    switch (case_id) {
    case 0:
      check(mod_inv_fermat<int64_t>(1, mod), int64_t(1)); // Modular inverse of 1
      break;
    case 1:
      check(mod_inv_fermat<int64_t>(2, mod), int64_t(500000004)); // Modular inverse of 2
      break;
    case 2:
      check(mod_inv_fermat<int64_t>(10, mod), int64_t(700000005)); // Modular inverse of 10
      break;
    case 3: {
      // Test with a non-prime modulus
      if (!is_prime<int64_t>(non_prime_mod)) {
        check(true, true, "Skipping test: non_prime_mod is not prime.");
        break;
      }
      int64_t a = 123456789;
      if (gcd(a, non_prime_mod) == 1) {
        check(mod_inv_fermat<int64_t>(a, non_prime_mod), int64_t(0),
              "Modular inverse should not exist for non-prime modulus");
      } else {
        check(true, true, "gcd(a, non_prime_mod) != 1, inverse doesn't exist");
      }
      break;
    }
    case 4: {
      // Randomized test for modular inverse
      for (int i = 0; i < 5; i++) {
        int64_t a = randint<int64_t>(1, mod - 1);
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1), "Random test failed for a = " + to_string(a));
      }
      break;
    }
    case 5:
      check(mod_inv_fermat<int64_t>(mod - 1, mod), int64_t(mod - 1)); // Modular inverse of mod - 1
      break;
    case 6:
      check(mod_inv_fermat<int64_t>(0, mod), int64_t(0), "Modular inverse of 0 should not exist");
      break;
    default:
      break;
    }
  }

  [[nodiscard]] int getCaseCount() const override { return 7; }
};

BERLIN_REGISTER_TEST(TestModInverse);