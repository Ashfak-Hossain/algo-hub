#pragma once

#include "BerlinTestWrapper.h"

// Macro to register a test case automatically at startup
#define BERLIN_REGISTER_TEST(TestClass) \
  BerlinTestWrapper* _berlin_test_##TestClass = new BerlinTestWrapper(new TestClass());