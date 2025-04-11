#pragma once

#include "BerlinTestManager.h"
#include <string>
#include <sstream>
#include <vector>

using std::string;

class BerlinTestFailed {};

class BerlinTestBase {
public:
  explicit BerlinTestBase(const string& test_name) : name(test_name) {}
  virtual ~BerlinTestBase() {}

  // Subclasses override this to write their test logic
  virtual void run(int case_id) = 0;

  // Can run multiple subcases: override if needed
  virtual int getCaseCount() const { return 1; }

  string getName() const { return name; }

protected:
  // Check if two values are equal
  template <typename T>
  void check(const T& actual, const T& expected, const string& msg = "") {
    if (actual == expected) return;

    auto* mgr = BerlinTestManager::getInstance();
    mgr->reportCheckFailure(toStr(actual), toStr(expected), msg);
    throw BerlinTestFailed();
  }

  // Fail the test with a message
  void fail(const string& msg = "") {
    BerlinTestManager::getInstance()->reportFailure(msg);
    throw BerlinTestFailed();
  }

private:
  // Convert values to string for debugging
  template <typename T>
  string toStr(const T& val) {
    std::ostringstream oss;
    oss.precision(20);
    oss << val;
    return oss.str();
  }

  template <typename T>
  string toStr(const std::vector<T>& vec) {
    std::ostringstream oss;
    oss << "{ ";
    for (auto& v : vec) oss << toStr(v) << " ";
    oss << "}";
    return oss.str();
  }

  string name;
};