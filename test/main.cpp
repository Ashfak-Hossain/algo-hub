#include "core/BerlinTestManager.h"

# include <iostream>

using std::cerr;

int main(const int argc, char** argv) {
  auto* manager = BerlinTestManager::getInstance();

  if (argc == 2 && string(argv[1]) == "--list") {
    cerr << " Registered Tests:\n";
    for (const auto& name : manager->getRegisteredTestNames()) {
      cerr << " - " << name << "\n";
    }
    return 0;
  }

  if (argc >= 2) {
    for (int i = 1; i < argc; ++i) {
      manager->runTest(argv[i]);
    }
  } else {
    manager->runAll();
  }

  manager->printStats();

  return 0;
}