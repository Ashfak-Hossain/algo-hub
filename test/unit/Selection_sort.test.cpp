#include "../../include/sorting/Selection_sort.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"
#include "../../include/utils/random.h"

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class TestSelectionSort : public BerlinTestBase {
public:
  TestSelectionSort() : BerlinTestBase("TestSelectionSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        vector<int> arr = {5, 3, 8, 6, 2};
        vector<int> expected = {2, 3, 5, 6, 8};
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 1: {
        vector<int> arr = {1};
        vector<int> expected = {1};
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 2: {
        vector<int> arr = {10, 10, 10};
        vector<int> expected = {10, 10, 10};
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 3: {
        vector<int> arr = {-3, -1, -2, 0, 2};
        vector<int> expected = {-3, -2, -1, 0, 2};
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 4: {
        vector<int> arr = {};
        vector<int> expected = {};
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 5: {
        auto arr = berlin_rand::randvec<int>(100, -1000, 1000);
        auto expected = arr;
        sort(expected.begin(), expected.end());
        selection_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 6; }
};

BERLIN_REGISTER_TEST(TestSelectionSort);
