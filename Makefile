# --- Makefile for algo-hub CP Toolkit ---

# Project name
PROJECT_NAME = algo-hub

# C++ flags for compiling
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wfloat-conversion -Werror -fsanitize=address -fsanitize=undefined -g -O2

# The default target (when you run 'make' without arguments)
.DEFAULT_GOAL := rebuild

# The 'unit_tests' target: Builds and runs unit tests
unit_tests: build
	@echo "Running unit tests..."
	@./build/unit_tests

# The 'stress_tests' target: Builds and runs stress tests
stress_tests: build
	@echo "Running stress tests..."
	@./build/stress_tests

# The 'build' target: Configures the project and compiles the code
build:
	@echo "Building project..."
	@cmake -S . -B build
	@cmake --build build

# Clean up build files (use 'make clean' to remove build files)
clean:
	@echo "Cleaning up build files..."
	@rm -rf build/

# List all available unit tests
list_tests:
	@echo "Listing all tests..."
	@./build/unit_tests --list

# Run a specific test
run_test:
	@echo "Running specified test: $(TEST_NAME)"
	@./build/unit_tests $(TEST_NAME)

# create a algorithm module
create_module:
	@echo "Creating new module..."
	@python3 scripts/create_module.py $(CATEGORY) $(ALGO)

# Rebuild the project (clean + build)
rebuild: clean build

# Help message for Makefile commands
help:
	@echo "Usage: make <target>"
	@echo ""
	@echo "Targets:"
	@echo "  unit_tests     - Build and run unit tests"
	@echo "  stress_tests   - Build and run stress tests"
	@echo "  build          - Configure and compile the project"
	@echo "  clean          - Remove build files"
	@echo "  list_tests     - List all registered tests"
	@echo "  run_test       - Run a specific test (set TEST_NAME)"
	@echo "  help           - Display this help message"