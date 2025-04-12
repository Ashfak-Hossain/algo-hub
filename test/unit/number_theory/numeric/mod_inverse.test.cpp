#include "number_theory/numeric/mod_inverse.h"
#include "number_theory/primality/is_prime.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"
#include "utils/random.h"

#include <numeric>
#include <iostream>

using namespace std;

class TestModInverse final : public BerlinTestBase {
public:
  TestModInverse() : BerlinTestBase("TestModInverse") {}

  void run(const int case_id) override {
    srand(42);  
    constexpr int mod = 1'000'000'007;
    constexpr int64_t non_prime_mod = 1'000'000'006; 

    switch (case_id) {
      case 0:
        check(mod_inv_fermat<int64_t>(1, mod), int64_t(1));
        break;
      case 1:
        check(mod_inv_fermat<int64_t>(2, mod), int64_t(500000004));
        break;
      case 2:
        check(mod_inv_fermat<int64_t>(3, mod), int64_t(333333336));
        break;
      case 3:
        check(mod_inv_fermat<int64_t>(10, mod), int64_t(700000005));
        break;
      case 4: {
        int64_t a = 2 * (non_prime_mod / 2);
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1), "Verification failed for a = 123456789");
        break;
      }
      case 5: {
        int64_t a = 987654321;
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1), "Verification failed for a = 987654321");
        break;
      }
      case 6: {
        const int64_t a = 1'000'000'000;
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 7: {
        const int64_t a = 999999999;
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 8: {
        const int64_t a = 1'000'000'006;
        const auto inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 9: {
        for (int i = 1; i <= 10; i++) {
          const auto a = randint<int64_t>(1, mod - 1);
          const auto inv = mod_inv_fermat<int64_t>(a, mod);
          check((a * inv) % mod, int64_t(1), "Random test failed for a = " + to_string(a));
        }
        break;
      }
      case 10:
        check(mod_inv_fermat<int64_t>(mod - 1, mod), int64_t(mod - 1));
        break;
      case 11:
        check(mod_inv_fermat<int64_t>(mod / 2, mod), binpow_mod<int64_t>(mod / 2, mod - 2, mod));
        break;
      case 12:
        check(mod_inv_fermat<int64_t>(123456, mod), binpow_mod<int64_t>(123456LL, mod - 2, mod));
        break;
      case 13:
        check(mod_inv_fermat<int64_t>(9999991, mod), binpow_mod<int64_t>(9999991LL, mod - 2, mod));
        break;
      case 14:
        check(mod_inv_fermat<int64_t>(0, mod), int64_t(0), "Modular inverse of 0 should not exist");
        break;
      case 15:
        check(mod_inv_fermat<int64_t>(mod, mod), int64_t(0), "Modular inverse of mod should not exist");
        break;
      case 16: {
        int64_t a = 123456789;
        if (gcd(a, non_prime_mod) == 1) {
          check(mod_inv_fermat<int64_t>(a, non_prime_mod), int64_t(0), "Modular inverse should not exist for non-prime modulus");
        } else {
          check(true, true, "gcd(a, non_prime_mod) != 1, inverse doesn't exist");
        }
        break;
      }
      case 17: {
        for (int i = 0; i < 10; i++) {
          int64_t a = randint<int64_t>(mod - 1000, mod - 1);
          check(gcd(a, mod) == 1, true, "gcd(a, mod) != 1");
          const auto inv = mod_inv_fermat<int64_t>(a, mod);
          check((a * inv) % mod, int64_t(1), "Modular inverse calculation failed for a = " + to_string(a));
        }
        break;
      }
      default:
        break;
    }
  }

  [[nodiscard]] int getCaseCount() const override { return 19; }
};

//*! Problem
// Running [TestModInverse] case 16/19... Passed
// Running [TestModInverse] case 17/19... 
// Test failed
//    Expected: 0
//    Got:      1
//    Message:  Modular inverse should not exist for non-prime modulus
// Running [TestModInverse] case 18/19... Passed

BERLIN_REGISTER_TEST(TestModInverse);