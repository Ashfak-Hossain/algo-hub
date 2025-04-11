#pragma once

#include <string>
#include <map>

using std::string;
using std::map;

class BerlinTestBase;
class BerlinTestWrapper;

class BerlinTestManager {
public:
  static BerlinTestManager* getInstance();

  // Register a test wrapper
  void registerTest(BerlinTestWrapper* wrapper);

  // Run all tests
  void runAll();

  // Run a specific test by name
  void runTest(const string& name);

  // Print summary
  void printStats() const;

  // Report test failure details
  void reportCheckFailure(const string& got, const string& expected, const string& msg = "");
  void reportFailure(const string& msg = "");

private:
  BerlinTestManager();
  ~BerlinTestManager();

  // Internal function to run a test
  void runTest(BerlinTestWrapper *wrapper);

  map<string, BerlinTestWrapper*> tests;
  int success_count = 0;
  int failure_count = 0;
};