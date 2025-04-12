#include "../../include/number_theory/modular_arithmetic.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

class TestModularArithmetic final : public BerlinTestBase {
public:
  TestModularArithmetic() : BerlinTestBase("TestModularArithmetic") {}

  void run(int id) override {
    constexpr int mod = 1'000'000'007;
    constexpr int64_t big = 1'000'000'006LL;

    switch (id) {
      // mod_add
      case 0: check(mod_add(5, 7, mod), int64_t(12)); break;
      case 1: check(mod_add(-5, 7, mod), int64_t((mod + 2) % mod)); break;
      case 2: check(mod_add(mod - 1, 1, mod), int64_t(0)); break;

      // mod_sub
      case 3: check(mod_sub(10, 7, mod), int64_t(3)); break;
      case 4: check(mod_sub(7, 10, mod), int64_t((mod - 3) % mod)); break;
      case 5: check(mod_sub(0, 1, mod), int64_t(mod - 1)); break;

      // mod_mul
      case 6: check(mod_mul(123, 456, mod), (123LL * 456LL) % mod); break;
      case 7: check(mod_mul(big, big, mod), (big % mod * big % mod) % mod); break;

      // modMul (binary method)
      case 8: check(modMul(big, big, mod), (big % mod * big % mod) % mod); break;
      case 9: check(modMul(0, big, mod), int64_t(0)); break;

      // modmul (floating point trick)
      case 10: check(modmul(big, big, mod), (big % mod * big % mod) % mod); break;
      case 11: check(modmul(1e18, 2, mod), int64_t(((__int128)1e18 * 2) % mod)); break;

      // mod_mul128 (__int128 method)
      case 12: check(mod_mul128(big, big, mod), int64_t(((__int128)big * big) % mod)); break;
      case 13: check(mod_mul128(0, big, mod), int64_t(0)); break;

      // mod_div (modular division using Fermat's inverse)
      case 14: check(mod_div(100, 25, mod), mod_mul(100, binpow_mod(25, mod - 2, mod), mod)); break;
      case 15: check(mod_div(big, big, mod), int64_t(1)); break;

      default: ;
    }
  }

  int getCaseCount() const override { return 16; }
};

BERLIN_REGISTER_TEST(TestModularArithmetic);