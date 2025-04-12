#include "number_theory/numeric/mod_inverse.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"
#include "utils/random.h" 


class TestModInverse final : public BerlinTestBase {
public:
  TestModInverse() : BerlinTestBase("TestModInverse") {}

  void run(const int case_id) override {
    constexpr int mod = 1'000'000'007;

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
        int64_t a = 123456789;
        int64_t inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1), "Verification failed for a = 123456789");
        break;
      }
      case 5: {
        int64_t a = 987654321;
        int64_t inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1), "Verification failed for a = 987654321");
        break;
      }
      case 6: {
        int64_t a = 1000000000;
        int64_t inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 7: {
        int64_t a = 999999999;
        int64_t inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 8: {
        int64_t a = 1'000'000'006;
        int64_t inv = mod_inv_fermat<int64_t>(a, mod);
        check((a * inv) % mod, int64_t(1));
        break;
      }
      case 9: {
        for (int i = 1; i <= 10; i++) {
          int64_t a = randint<int64_t>(1, mod - 1);
          int64_t inv = mod_inv_fermat<int64_t>(a, mod);
          check((a * inv) % mod, int64_t(1), "Random test failed for a = " + std::to_string(a));
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
        constexpr int64_t non_prime_mod = 1'000'000'006; // Non-prime modulus
        int64_t a = 123456789;
        check(mod_inv_fermat<int64_t>(a, non_prime_mod), int64_t(0), "Modular inverse should not exist for non-prime modulus");
        break;
      }
      case 17: {
        //! Here i have to check if i is prime or not
        for (int i = 0; i < 10; i++) {
          int64_t a = randint<int64_t>(mod - 1000, mod - 1);
          int64_t inv = mod_inv_fermat<int64_t>(a, mod);
          check((a * inv) % mod, int64_t(1), "Random large test failed for a = " + std::to_string(a));
        }
        break;
      }
      default: ;
    }
  }

  int getCaseCount() const override { return 20; }
};

BERLIN_REGISTER_TEST(TestModInverse);