#pragma once

#include <string>
#include <map>
#include <vector>

using std::string;

class BerlinTestBase;
class BerlinTestWrapper;

class BerlinTestManager {
public:
  static BerlinTestManager* getInstance();

  void registerTest(BerlinTestWrapper* wrapper);
  void runAll();
  void runTest(const string& name);
  void printStats() const;
  void reportCheckFailure(const string& got, const string& expected, const string& msg = "");
  void reportFailure(const string& msg = "");

  std::vector<string> getRegisteredTestNames() const;

private:
  BerlinTestManager();
  ~BerlinTestManager();

  // Internal function to run a test
  void runTest(const BerlinTestWrapper *wrapper);

  std::map<string, BerlinTestWrapper*> tests;
  int success_count = 0;
  int failure_count = 0;
};