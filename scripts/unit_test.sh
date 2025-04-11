#!/bin/bash

# Exit immediately if a command fails
set -e

# Navigate to the project root directory
cd "$(dirname "$0")/.." || exit 1

# Create build directory if it doesn't exist
mkdir -p build

# Build the project using CMake
echo "Building unit tests..."
cmake -S . -B build > /dev/null
cmake --build build --target unit_tests

# Run the unit tests with any args (like test name)
echo "Running unit tests..."
./build/unit_tests "$@"