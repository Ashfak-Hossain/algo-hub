#include "../../include/sorting/Bubble_sort.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"
#include "../../include/utils/random.h"

#include <vector>
#include <algorithm>

using std::vector;

class TestBubbleSort : public BerlinTestBase {
public:
  TestBubbleSort() : BerlinTestBase("TestBubbleSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        vector<int> arr = {5, 3, 8, 6, 2};
        vector<int> expected = {2, 3, 5, 6, 8};
        bubble_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 1: {
        vector<int> arr = {1};
        vector<int> expected = {1};
        bubble_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 2: {
        vector<int> arr = {10, 10, 10};
        vector<int> expected = {10, 10, 10};
        bubble_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 3: {
        vector<int> arr = {-3, -1, -2, 0, 2};
        vector<int> expected = {-3, -2, -1, 0, 2};
        bubble_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 4: {
        vector<int> arr = {};
        vector<int> expected = {};
        bubble_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestBubbleSort);