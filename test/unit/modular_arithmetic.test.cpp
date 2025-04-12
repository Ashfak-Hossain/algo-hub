#include "../../include/number_theory/numeric/modular_arithmetic.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

class TestModularArithmetic final : public BerlinTestBase {
public:
  TestModularArithmetic() : BerlinTestBase("TestModularArithmetic") {}

  void run(int id) override {
    constexpr int64_t mod = 1'000'000'007;
    constexpr int64_t big = 1'000'000'006LL; // Close to mod

    switch (id) {
      // mod_add
      case 0: check(mod_add<int64_t>(5, 7, mod), int64_t(12)); break;
      case 1: check(mod_add<int64_t>(-5, 7, mod), int64_t(2)); break;
      case 2: check(mod_add<int64_t>(mod - 1, 1, mod), int64_t(0)); break;
      case 3: check(mod_add<int64_t>(big, big, mod), (big + big) % mod); break;

      // mod_sub
      case 4: check(mod_sub<int64_t>(10, 7, mod), int64_t(3)); break;
      case 5: check(mod_sub<int64_t>(7, 10, mod), int64_t(mod - 3)); break;
      case 6: check(mod_sub<int64_t>(0, 1, mod), int64_t(mod - 1)); break;
      case 7: check(mod_sub<int64_t>(big, big, mod), int64_t(0)); break;

      // mod_mul
      case 8: check(mod_mul<int64_t>(123, 456, mod), (123LL * 456LL) % mod); break;
      case 9: check(mod_mul<int64_t>(big, big, mod), (big % mod * big % mod) % mod); break;
      case 10: check(mod_mul<int64_t>(0, big, mod), int64_t(0)); break;

      // mod_mul_binary
      case 11: check(mod_mul_bin<int64_t>(big, big, mod), (big % mod * big % mod) % mod); break;
      case 12: check(mod_mul_bin<int64_t>(0, big, mod), int64_t(0)); break;

      // mod_mul_fp
      case 13: check(mod_mul_fp<int64_t>(big, big, mod), (big % mod * big % mod) % mod); break;
      case 14: check(mod_mul_fp<int64_t>(1e18, 2, mod), int64_t(((__int128)1e18 * 2) % mod)); break;

      // mod_mul128
      case 15: check(mod_mul128<int64_t>(big, big, mod), int64_t(((__int128)big * big) % mod)); break;
      case 16: check(mod_mul128<int64_t>(0, big, mod), int64_t(0)); break;

      // mod_div
      case 17: check(mod_div<int64_t>(100, 25, mod), mod_mul<int64_t>(100, binpow_mod<int64_t>(25, mod - 2, mod), mod)); break;
      case 18: check(mod_div<int64_t>(big, big, mod), int64_t(1)); break;

      // Edge cases
      case 19: check(mod_add<int64_t>(0, 0, mod), int64_t(0)); break;
      case 20: check(mod_sub<int64_t>(0, 0, mod), int64_t(0)); break;
      case 21: check(mod_mul<int64_t>(0, 0, mod), int64_t(0)); break;
      case 22: check(mod_div<int64_t>(1, 1, mod), int64_t(1)); break;

      default: ;
    }
  }

  int getCaseCount() const override { return 23; }
};

BERLIN_REGISTER_TEST(TestModularArithmetic);