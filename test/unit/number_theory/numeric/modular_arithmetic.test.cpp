#include "number_theory/numeric/modular_arithmetic.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

class TestModularArithmetic final : public BerlinTestBase {
public:
  TestModularArithmetic() : BerlinTestBase("TestModularArithmetic") {}

  void run(const int id) override {
    constexpr int64_t mod = 1'000'000'007;

    switch (id) {
    // mod_add
    case 0:
      check(mod_add<int64_t>(5, 7, mod), int64_t(12)); // Simple addition
      break;

    // mod_sub
    case 1:
      check(mod_sub<int64_t>(10, 7, mod), int64_t(3)); // Simple subtraction
      break;

    // mod_mul
    case 2:
      check(mod_mul<int64_t>(123, 456, mod),
            int64_t((123LL * 456LL) % mod)); // Simple multiplication
      break;

    // mod_div
    case 3:
      check(mod_div<int64_t>(100, 25, mod),
            mod_mul<int64_t>(100, binpow_mod<int64_t>(25, mod - 2, mod),
                             mod)); // Division using modular inverse
      break;

    // Edge case: mod_add with zero
    case 4:
      check(mod_add<int64_t>(0, 0, mod), int64_t(0)); // Addition with zero
      break;

    default:;
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestModularArithmetic);