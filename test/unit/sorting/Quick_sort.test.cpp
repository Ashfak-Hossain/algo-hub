#include "sorting/Quick_sort.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"
#include "utils/random.h"

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class TestQuickSort final : public BerlinTestBase {
public:
  TestQuickSort() : BerlinTestBase("TestQuickSort") {}

  void run(const int id) override {
    switch (id) {
      case 0: {
        vector<int> arr = {5, 3, 8, 6, 2};
        vector<int> expected = {2, 3, 5, 6, 8};
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 1: {
        vector<int> arr = {1};
        vector<int> expected = {1};
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 2: {
        vector<int> arr = {10, 10, 10};
        vector<int> expected = {10, 10, 10};
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 3: {
        vector<int> arr = {-3, -1, -2, 0, 2};
        vector<int> expected = {-3, -2, -1, 0, 2};
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 4: {
        vector<int> arr = {};
        vector<int> expected = {};
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 5: {
        auto arr = berlin_rand::randvec<int>(100, -1000, 1000);
        auto expected = arr;
        sort(expected.begin(), expected.end());
        quick_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      default: ;
    }
  }

  int getCaseCount() const override { return 6; }
};

BERLIN_REGISTER_TEST(TestQuickSort);
