#pragma once

#include "BerlinTestBase.h"
#include "BerlinTestManager.h"

class BerlinTestWrapper {
public:
  explicit BerlinTestWrapper(BerlinTestBase* test) : test_ptr(test) {
    BerlinTestManager::getInstance()->registerTest(this);
  }

  ~BerlinTestWrapper() {
    delete test_ptr;
  }

  [[nodiscard]] BerlinTestBase* getTest() const {
    return test_ptr;
  }

private:
  BerlinTestBase* test_ptr;
};