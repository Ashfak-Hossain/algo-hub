#include "number_theory/numeric/binpow.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

class TestBinpow final : public BerlinTestBase {
public:
  TestBinpow() : BerlinTestBase("TestBinpow") {}

  void run(const int case_id) override {
    constexpr int mod = 1'000'000'007;

    switch (case_id) {
    case 0:
      check(binpow<int64_t>(2, 0), int64_t(1)); // 2^0 = 1
      break;
    case 1:
      check(binpow<int64_t>(2, 10), int64_t(1024)); // 2^10 = 1024
      break;
    case 2:
      check(binpow<int64_t>(7, 2), int64_t(49)); // 7^2 = 49
      break;
    case 3:
      check(binpow<int64_t>(5, 1), int64_t(5)); // 5^1 = 5
      break;
    case 4:
      check(binpow<int64_t>(10, 5), int64_t(100000)); // 10^5 = 100000
      break;
    case 5:
      check(binpow<int64_t>(1, 1'000'000'000), int64_t(1)); // 1^n = 1
      break;
    case 6:
      check(binpow_mod<int64_t>(2, 10, mod), int64_t(1024)); // (2^10) % mod = 1024
      break;
    case 7:
      check(binpow_mod<int64_t>(123, 0, mod), int64_t(1)); // (123^0) % mod = 1
      break;
    case 8:
      check(binpow_mod<int64_t>(123, 456, 1), int64_t(0)); // (123^456) % 1 = 0
      break;
    case 9:
      check(binpow_mod<int64_t>(0, 123, mod), int64_t(0)); // (0^123) % mod = 0
      break;
    default:;
    }
  }

  int getCaseCount() const override { return 10; }
};

BERLIN_REGISTER_TEST(TestBinpow);