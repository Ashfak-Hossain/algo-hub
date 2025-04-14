#include "sorting/Insertion_sort.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

#include <vector>
#include <list>

using std::vector;
using std::list;

class TestInsertionSort final : public BerlinTestBase {
public:
  TestInsertionSort() : BerlinTestBase("TestInsertionSort") {}

  void run(int id) override {
    switch (id) {
      case 0: {
        vector<int> arr = {9, 7, 5, 3, 1};
        vector<int> expected = {1, 3, 5, 7, 9};
        insertion_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 1: {
        list<int> arr = {10, 20, 15, 5};
        list<int> expected = {5, 10, 15, 20};
        insertion_sort(arr.begin(), arr.end());
        check(vector<int>(arr.begin(), arr.end()), vector<int>(expected.begin(), expected.end()));
        break;
      }
      case 2: {
        vector<int> arr = {1, 2, 3, 4, 5};
        vector<int> expected = {1, 2, 3, 4, 5};
        insertion_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 3: {
        vector<int> arr = {-5, -10, 0, 5, 10};
        vector<int> expected = {-10, -5, 0, 5, 10};
        insertion_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      case 4: {
        vector<int> arr = {};
        vector<int> expected = {};
        insertion_sort(arr.begin(), arr.end());
        check(arr, expected);
        break;
      }
      default: ;
    }
  }

  int getCaseCount() const override { return 5; }
};

BERLIN_REGISTER_TEST(TestInsertionSort);