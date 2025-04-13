#include "BerlinTestManager.h"
#include "core/BerlinTestBase.h"
#include "BerlinTestWrapper.h"

#include <iostream>
#include <algorithm>

using std::string;
using std::cerr;
using std::vector;

BerlinTestManager::BerlinTestManager() = default;
BerlinTestManager::~BerlinTestManager() {
  for (auto& [_, wrapper] : tests)
    delete wrapper;
  tests.clear();
}

BerlinTestManager* BerlinTestManager::getInstance() {
  static BerlinTestManager instance;
  return &instance;
}

void BerlinTestManager::registerTest(BerlinTestWrapper* wrapper) {
  if (!wrapper || !wrapper->getTest()) return;

  const string name = wrapper->getTest()->getName();
  tests[name] = wrapper;
}

void BerlinTestManager::reportCheckFailure(const string& got, const string& expected, const string& msg) {
  cerr << "\nTest failed\n";
  cerr << "   Expected: " << expected << "\n";
  cerr << "   Got:      " << got << "\n";
  if (!msg.empty()) cerr << "   Message:  " << msg << "\n";
  cerr.flush();
}

void BerlinTestManager::reportFailure(const string& msg) {
  cerr << "\nTest failed\n";
  if (!msg.empty()) cerr << "   Message: " << msg << "\n";
  cerr.flush();
}

void BerlinTestManager::runAll() {
  for (const auto& [name, wrapper] : tests) {
    runTest(wrapper);
  }
}

void BerlinTestManager::runTest(const string& name) {
  const auto it = tests.find(name);
  if (it == tests.end()) {
    cerr << "Test \"" << name << "\" not found.\n";
    return;
  }
  runTest(it->second);
}

void BerlinTestManager::runTest(const BerlinTestWrapper* wrapper) {
  auto* test = wrapper->getTest();
  const string name = test->getName();
  const int count = test->getCaseCount();

  for (int i = 0; i < count; ++i) {
    cerr << "Running [" << name << "] case " << i + 1 << "/" << count << "... ";
    cerr.flush();

    try {
      test->run(i);
      ++success_count;
      cerr << "Passed\n";
    } catch (BerlinTestFailed&) {
      ++failure_count;
    } catch (const std::exception& e) {
      ++failure_count;
      cerr << "\nException: " << e.what() << "\n";
    } catch (...) {
      ++failure_count;
      cerr << "\nUnknown exception thrown\n";
    }
  }
}

void BerlinTestManager::printStats() const {
  cerr << "\nTest Summary:\n";
  cerr << "   Passed : " << success_count << "\n";
  cerr << "   Failed : " << failure_count << "\n";
  cerr << "   Total  : " << success_count + failure_count << "\n\n";
  cerr.flush();
}

vector<string> BerlinTestManager::getRegisteredTestNames() const {
  vector<string> names;
  for (const auto& [name, _] : tests) {
    names.push_back(name);
  }
  std::sort(names.begin(), names.end());
  return names;
}