# --- Makefile for algo-hub CP Toolkit ---

# Project name
PROJECT_NAME = algo-hub

# C++ flags for compiling
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wfloat-conversion -Werror -fsanitize=address -fsanitize=undefined -g -O2

# The default target (when you run 'make' without arguments)
.DEFAULT_GOAL := build

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

# Rebuild the project (clean + build)
rebuild: clean build

# List all available unit tests
list_tests:
	@echo "Listing all tests..."
	@./build/unit_tests --list

# Run a specific test
run_utest:
	@echo "Running unit test: $(TEST_NAME)"
	@./scripts/unit_test.sh $(TEST_NAME)
	@echo "Test $(TEST_NAME) completed."
	
# create a algorithm module
new_module:
	@echo "Creating new module..."
	@python3 scripts/create_module.py $(CATEGORY) $(ALGO)

# Help message for Makefile commands
help:
	@echo "Usage: make <target>"
	@echo ""
	@echo "Targets:"
	@echo "  unit_tests     - Build and run unit tests"
	@echo "  stress_tests   - Build and run stress tests"
	@echo "  build          - Configure and compile the project"
	@echo "  rebuild        - Clean and build the project"
	@echo "  new_module     - Create a new algorithm module"
	@echo "  clean          - Remove build files"
	@echo "  list_tests     - List all registered tests"
	@echo "  run_test       - Run a specific test (set TEST_NAME)"
	@echo "  quick          - Compile and run a single file (use FILE=path)"
	@echo "  help           - Display this help message"

# Quick compile a single file
quick:
	@echo "Quick compiling $(FILE)..."
	@g++ $(CXXFLAGS) -o quick.out $(FILE) && ./quick.out