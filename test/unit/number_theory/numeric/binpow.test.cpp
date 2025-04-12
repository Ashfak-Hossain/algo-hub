#include "number_theory/numeric/binpow.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

class TestBinpow final : public BerlinTestBase {
public:
  TestBinpow() : BerlinTestBase("TestBinpow") {}

  void run(const int case_id) override {
    constexpr int mod = 1'000'000'007;

    switch (case_id) {
      case 0: check((int64_t)binpow(2, 0), (int64_t)(1)); break;
      case 1: check((int64_t)binpow(2, 10), (int64_t)(1024)); break;
      case 2: check((int64_t)binpow(7, 2), (int64_t)(49)); break;
      case 3: check((int64_t)binpow(5, 1), (int64_t)(5)); break;
      case 4: check((int64_t)binpow(10, 5), (int64_t)(100000)); break;
      case 5: check((int64_t)binpow(1, (1000000000)), (int64_t)(1)); break;
      case 6: check(binpow_mod((int64_t)2, (int64_t)10, (int64_t)mod), (int64_t)(1024)); break;
      case 7: check(binpow_mod((int64_t)123, (int64_t)0, (int64_t)mod), (int64_t)(1)); break;
      case 8: check(binpow_mod((int64_t)123, (int64_t)456, (int64_t)1), (int64_t)(0)); break;
      case 9: check(binpow_mod((int64_t)0, (int64_t)123, (int64_t)mod), (int64_t)(0)); break;
      case 10: check(binpow_mod((int64_t)123456789, (int64_t)123456, (int64_t)mod), binpow_mod((int64_t)123456789, (int64_t)123456, (int64_t)mod)); break;
      default: ;
    }
  }

  int getCaseCount() const override { return 11; }
};

BERLIN_REGISTER_TEST(TestBinpow);