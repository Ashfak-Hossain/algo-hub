#include "../../include/number_theory/modular_arithmetic.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

class TestModular_arithmetic final : public BerlinTestBase {
public:
  TestModular_arithmetic() : BerlinTestBase("TestModular_arithmetic") {}

  void run(int id) override {
    constexpr int mod = 1'000'000'007;

    int64_t x = 1'000'000'006LL;

    switch (id) {
      case 0: check(mod_add(5, 7, mod), static_cast<int64_t>(12)); break;
      case 1: check(mod_add(-5, 7, mod), static_cast<int64_t>(mod + 2) % mod); break;
      case 2: check(mod_sub(10, 7, mod), static_cast<int64_t>(3)); break;
      case 3: check(mod_sub(7, 10, mod), static_cast<int64_t>(mod - 3) % mod); break;
      case 4: check(mod_mul(123, 456, mod), (123LL * 456LL) % mod); break;
      case 5: check(modMul(x, x, mod), 1LL * x % mod * (x % mod) % mod); break;
      case 6: check(modmul(x, x, mod), 1LL * x % mod * (x % mod) % mod); break;
      case 7: check(mod_div(100, 25, mod), mod_mul(100, binpow_mod(25, mod - 2, mod), mod)); break;
      default: ;
    }
  }

  int getCaseCount() const override { return 8; }
};

BERLIN_REGISTER_TEST(TestModular_arithmetic);