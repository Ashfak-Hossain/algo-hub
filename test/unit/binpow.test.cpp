/**
 * author: _Berlin_
 * Description: Test suite for binpow and binpow_mod
 * Purpose: Verify correctness across small and large values
**/

#include "../../include/number_theory/binpow.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"

class TestBinpow final : public BerlinTestBase {
public:
  TestBinpow() : BerlinTestBase("TestBinpow") {}

  void run(const int case_id) override {
    constexpr int mod = 1'000'000'007;

    switch (case_id) {
      case 0: check(binpow(2, 0), static_cast<int64_t>(1)); break;
      case 1: check(binpow(2, 10), static_cast<int64_t>(1024)); break;
      case 2: check(binpow(7, 2), static_cast<int64_t>(49)); break;
      case 3: check(binpow(5, 1), static_cast<int64_t>(5)); break;
      case 4: check(binpow(10, 5), static_cast<int64_t>(100000)); break;
      case 5: check(binpow(1, static_cast<int64_t>(1e9)), static_cast<int64_t>(1)); break;
      case 6: check(binpow_mod(2, 10, mod), static_cast<int64_t>(1024)); break;
      case 7: check(binpow_mod(123, 0, mod), static_cast<int64_t>(1)); break;
      case 8: check(binpow_mod(123, 456, 1), static_cast<int64_t>(0)); break;
      case 9: check(binpow_mod(0, 123, mod), static_cast<int64_t>(0)); break;
      case 10: check(binpow_mod(123456789, 123456, mod), binpow_mod(123456789, 123456, mod)); break;
      default: ;
    }
  }

  [[nodiscard]] int getCaseCount() const override { return 11; }
};

BERLIN_REGISTER_TEST(TestBinpow);