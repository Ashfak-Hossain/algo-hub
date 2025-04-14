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
      string input = "aaabbc";
      vector<pair<char, int>> expected = {{'a', 3}, {'b', 2}, {'c', 1}};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 1: {
      vector<int> input = {1, 1, 2, 3, 3};
      vector<pair<int, int>> expected = {{1, 2}, {2, 1}, {3, 2}};
      check(run_length_encoding<int>(input), expected);
      break;
    }
    case 2: {
      deque<char> input = {'a', 'a', 'b', 'b'};
      vector<pair<char, int>> expected = {{'a', 2}, {'b', 2}};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 3: {
      string input = "";
      vector<pair<char, int>> expected = {};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 4: {
      vector<int> input = {42};
      vector<pair<int, int>> expected = {{42, 1}};
      check(run_length_encoding<int>(input), expected);
      break;
    }
    case 5: {
      string input = "abcdef";
      vector<pair<char, int>> expected = {{'a', 1}, {'b', 1}, {'c', 1},
                                          {'d', 1}, {'e', 1}, {'f', 1}};
      check(run_length_encoding<char>(input), expected);
      break;
    }
    case 6: {
      vector<int> input = {7, 7, 7, 7};
      vector<pair<int, int>> expected = {{7, 4}};
      check(run_length_encoding<int>(input), expected);
      break;
    }
    default:
      break;
    }
  }

  int getCaseCount() const override { return 7; }
};

BERLIN_REGISTER_TEST(TestRunLengthEncoding);