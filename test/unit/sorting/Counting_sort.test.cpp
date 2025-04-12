#include "sorting/Counting_sort.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"
#include "utils/random.h"

#include <vector>
#include <algorithm>

using std::vector;

class TestCountingSort : public BerlinTestBase {
public:
  TestCountingSort() : BerlinTestBase("TestCountingSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        vector<int> arr = {5, 3, 8, 6, 2};
        vector<int> expected = {2, 3, 5, 6, 8};
        counting_sort(arr, 2, 8);
        check(arr, expected);
        break;
      }
      case 1: {
        vector<int> arr = {1};
        vector<int> expected = {1};
        counting_sort(arr, 1, 1);
        check(arr, expected);
        break;
      }
      case 2: {
        vector<int> arr = {10, 10, 10};
        vector<int> expected = {10, 10, 10};
        counting_sort(arr, 10, 10);
        check(arr, expected);
        break;
      }
      case 3: {
        vector<int> arr = {-3, -1, -2, 0, 2};
        vector<int> expected = {-3, -2, -1, 0, 2};
        counting_sort(arr, -3, 2);
        check(arr, expected);
        break;
      }
      case 4: {
        vector<int> arr = {};
        vector<int> expected = {};
        counting_sort(arr, 0, 0);
        check(arr, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestCountingSort);
