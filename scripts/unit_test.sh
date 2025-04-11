#!/bin/bash

# Exit immediately if a command fails
set -e

# Navigate to the project root directory
cd "$(dirname "$0")/.." || exit 1

# Create build directory if it doesn't exist
mkdir -p build

# Build the project using CMake
echo -e "\033[1;34m Building unit tests...\033[0m"
cmake -S . -B build > /dev/null
cmake --build build --target unit_tests > /dev/null

# Run the unit tests with any args (like test name)
if [ $# -eq 0 ]; then
  echo -e "\033[1;32m Running ALL unit tests...\033[0m"
  ./build/unit_tests
else
  echo -e "\033[1;36m Running test: $1\033[0m"
  ./build/unit_tests "$1" || {
    echo -e "\033[1;31m Test \"$1\" not found.\033[0m"
    echo -e "\033[1;33m To see available tests, run: \033[0m./build/unit_tests --list"
    exit 1
  }
fi