#include "core/BerlinTestManager.h"

int main(const int argc, char** argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      BerlinTestManager::getInstance()->runTest(argv[i]);
    }
  } else {
    BerlinTestManager::getInstance()->runAll();
  }

  BerlinTestManager::getInstance()->printStats();

  return 0;
}