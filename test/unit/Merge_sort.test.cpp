#include "../../include/sorting/Merge_sort.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"
#include "../../include/utils/random.h"

#include <vector>
#include <algorithm>
#include <random>

class TestMergeSort : public BerlinTestBase {
public:
  TestMergeSort() : BerlinTestBase("TestMergeSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        std::vector<int> arr = {5, 3, 8, 6, 2};
        std::vector<int> expected = {2, 3, 5, 6, 8};
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 1: {
        std::vector<int> arr = {1};
        std::vector<int> expected = {1};
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 2: {
        std::vector<int> arr = {10, 10, 10};
        std::vector<int> expected = {10, 10, 10};
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 3: {
        std::vector<int> arr = {-3, -1, -2, 0, 2};
        std::vector<int> expected = {-3, -2, -1, 0, 2};
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 4: {
        std::vector<int> arr = {};
        std::vector<int> expected = {};
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 5: {
        auto arr = berlin_rand::randvec<int>(100, -1000, 1000);
        auto expected = arr;
        std::sort(expected.begin(), expected.end());
        merge_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 6; }
};

BERLIN_REGISTER_TEST(TestMergeSort);
