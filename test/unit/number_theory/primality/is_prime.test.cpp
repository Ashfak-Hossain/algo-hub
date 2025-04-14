#include "number_theory/primality/is_prime.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

class TestIsPrime final : public BerlinTestBase {
public:
  TestIsPrime() : BerlinTestBase("TestIsPrime") {}

  void run(const int id) override {
    switch (id) {
    case 0:
      check(is_prime(1), false);
      break;
    case 1:
      check(is_prime(2), true);
      break;
    case 2:
      check(is_prime(3), true);
      break;
    case 3:
      check(is_prime(4), false);
      break;
    case 4:
      check(is_prime(5), true);
      break;
    case 5:
      check(is_prime(17), true);
      break;
    case 6:
      check(is_prime(1'000'000), false);
      break;
    default:;
    }
  }

  int getCaseCount() const override { return 7; }
};

BERLIN_REGISTER_TEST(TestIsPrime);
