/**
 * author: _Berlin_
 * Description: Unit tests for bubble sort using randomized and static vectors.
 **/

#include "../../include/sorting/Bubble_sort.h"
#include "../core/BerlinTestBase.h"
#include "../core/BerlinTestRegister.h"
#include "../../include/utils/random.h"

#include <vector>
#include <algorithm>

using namespace std;

class TestBubbleSort : public BerlinTestBase {
public:
  TestBubbleSort() : BerlinTestBase("TestBubbleSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        vector<int64_t> a = {3, 1, 4, 5, 2};
        vector<int64_t> expected = {1, 2, 3, 4, 5};
        bubble_sort(a);
        check(a, expected);
        break;
      }
      case 1: {
        vector<int64_t> a = {42};
        vector<int64_t> expected = {42};
        bubble_sort(a);
        check(a, expected);
        break;
      }
      case 2: {
        vector<int64_t> a = {7, 7, 7, 7, 7};
        vector<int64_t> expected = {7, 7, 7, 7, 7};
        bubble_sort(a);
        check(a, expected);
        break;
      }
      case 3: {
        auto a = berlin_rand::randvec(100, -1e5, 1e5);
        auto expected = a;
        sort(expected.begin(), expected.end());
        bubble_sort(a);
        check(a, expected);
        break;
      }
      case 4: {
        auto a = berlin_rand::randvec(200, -1e9, 1e9);
        auto expected = a;
        sort(expected.begin(), expected.end());
        bubble_sort(a);
        check(a, expected);
        break;
      }
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestBubbleSort);