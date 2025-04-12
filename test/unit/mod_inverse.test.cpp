#include "../../include/number_theory/mod_inverse.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

class TestModInverse : public BerlinTestBase {
public:
  TestModInverse() : BerlinTestBase("TestModInverse") {}

  void run(int id) override {
    constexpr int mod = 1'000'000'007;

    switch (id) {
      case 0: check(mod_inv_fermat(2, mod), int64_t(500000004)); break;
      case 1: check(mod_inv_fermat(4, mod), int64_t(250000002)); break;
      case 2: check(mod_inv_fermat(5, mod), int64_t(400000003)); break;
      case 3: check(mod_inv_fermat(123456789, mod), binpow_mod(123456789, mod - 2, mod)); break;
      case 4: check(mod_inv_fermat(1, mod), int64_t(1)); break;
      case 5: check(mod_inv_fermat(mod - 1, mod), int64_t(mod - 1)); break;
    }
  }

  int getCaseCount() const override { return 6; }
};

BERLIN_REGISTER_TEST(TestModInverse);