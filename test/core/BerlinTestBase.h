#pragma once

#include "BerlinTestManager.h"
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::ostringstream;
using std::pair;
using std::string;
using std::vector;

class BerlinTestFailed {};

class BerlinTestBase {
public:
  explicit BerlinTestBase(string test_name) : name(std::move(test_name)) {}
  virtual ~BerlinTestBase() = default;

  // Subclasses override this to write their test logic
  virtual void run(int case_id) = 0;
  // Can run multiple subcases: override if needed
  [[nodiscard]] virtual int getCaseCount() const { return 1; }
  [[nodiscard]] string getName() const { return name; }

protected:
  // Check if two values are equal
  template <typename T> void check(const T &actual, const T &expected, const string &msg = "") {
    if (actual == expected) return;
    auto *mgr = BerlinTestManager::getInstance();
    mgr->reportCheckFailure(toStr(actual), toStr(expected), msg);
    throw BerlinTestFailed();
  }

  // Fail the test with a message
  void fail(const string &msg = "") {
    BerlinTestManager::getInstance()->reportFailure(msg);
    throw BerlinTestFailed();
  }

private:
  // Convert various types to string
  template <typename T> string toStr(const T &val) {
    ostringstream oss;
    oss.precision(20);
    oss << val;
    return oss.str();
  }

  // for pair
  template <typename T1, typename T2> string toStr(const pair<T1, T2> &p) {
    ostringstream oss;
    oss << "(" << toStr(p.first) << ", " << toStr(p.second) << ")";
    return oss.str();
  }

  // for vector
  template <typename T> string toStr(const vector<T> &vec) {
    ostringstream oss;
    oss << "{ ";
    for (const auto &v : vec) oss << toStr(v) << " ";
    oss << "}";
    return oss.str();
  }

  string name;
};