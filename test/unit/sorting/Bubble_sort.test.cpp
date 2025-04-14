#include "sorting/Bubble_sort.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

#include <vector>

using std::vector;

class TestBubbleSort final : public BerlinTestBase {
public:
  TestBubbleSort() : BerlinTestBase("TestBubbleSort") {}

  void run(const int id) override {
    switch (id) {
    case 0: {
      vector arr = {5, 3, 8, 6, 2};
      const vector expected = {2, 3, 5, 6, 8};
      bubble_sort(arr.begin(), arr.end());
      check(arr, expected);
      break;
    }
    case 1: {
      vector arr = {1};
      const vector expected = {1};
      bubble_sort(arr.begin(), arr.end());
      check(arr, expected);
      break;
    }
    case 2: {
      vector arr = {10, 10, 10};
      vector expected = {10, 10, 10};
      bubble_sort(arr.begin(), arr.end());
      check(arr, expected);
      break;
    }
    case 3: {
      vector arr = {-3, -1, -2, 0, 2};
      vector expected = {-3, -2, -1, 0, 2};
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
    default:;
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestBubbleSort);