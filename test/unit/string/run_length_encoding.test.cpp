#include "string/run_length_encoding.h"
#include "core/BerlinTestBase.h"
#include "core/BerlinTestRegister.h"

#include <deque>
#include <string>
#include <vector>

class TestRunLengthEncoding final : public BerlinTestBase {
public:
  TestRunLengthEncoding() : BerlinTestBase("TestRunLengthEncoding") {}

  void run(const int case_id) override {
    using std::deque;
    using std::pair;
    using std::string;
    using std::vector;

    switch (case_id) {
    case 0: {
      // Test with a string
      string input = "aaabbc";
      vector<pair<char, int>> expected = {{'a', 3}, {'b', 2}, {'c', 1}};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 1: {
      // Test with a vector of integers
      vector<int> input = {1, 1, 2, 3, 3};
      vector<pair<int, int>> expected = {{1, 2}, {2, 1}, {3, 2}};
      check(run_length_encoding<int>(input), expected);
      break;
    }
    case 2: {
      // Test with an empty input
      string input = "";
      vector<pair<char, int>> expected = {};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 3: {
      // Test with all unique elements
      string input = "abcdef";
      vector<pair<char, int>> expected = {{'a', 1}, {'b', 1}, {'c', 1},
                                          {'d', 1}, {'e', 1}, {'f', 1}};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    default:
      break;
    }
  }

  int getCaseCount() const override { return 4; }
};

BERLIN_REGISTER_TEST(TestRunLengthEncoding);