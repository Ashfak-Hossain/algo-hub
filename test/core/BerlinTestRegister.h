#pragma once

#include "BerlinTestWrapper.h"

#define BERLIN_REGISTER_TEST(TestClass) BerlinTestWrapper* _berlin_test_##TestClass = new BerlinTestWrapper(new TestClass());