#include "../../include/sorting/Counting_sort.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include "../../include/utils/random.h"

class TestCountingSort : public BerlinTestBase {
  public:
    TestCountingSort() : BerlinTestBase("TestCountingSort") {} 

  void run(int id) override {
    using std::vector;
    switch (id) {
      case 0: {
        vector<unsigned> input = {4, 2, 2, 8, 3, 3, 1};
        auto expected = input;
        std::sort(expected.begin(), expected.end());
        auto result = counting_sort(input);
        check(result, expected);
        break;
      }
      case 1: {
        vector<unsigned> input = {5, 5, 5, 5};
        auto expected = input;
        std::sort(expected.begin(), expected.end());
        auto result = counting_sort(input);
        check(result, expected);
        break;
      }
      case 2: {
        vector<unsigned> input = {};
        auto result = counting_sort(input);
        check(result, input);
        break;
      }
      case 3: {
        vector<unsigned> input = {100, 50, 75, 25, 0};
        auto expected = input;
        std::sort(expected.begin(), expected.end());
        auto result = counting_sort(input);
        check(result, expected);
        break;
      }
      case 4: {
        vector<unsigned> input = randvec<unsigned>(1000, 0, 500);
        auto expected = input;
        std::sort(expected.begin(), expected.end());
        auto result = counting_sort(input);
        check(result, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestCountingSort);
