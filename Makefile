# --- Makefile for algo-hub CP Toolkit ---

# =========== Configuration =========== 
PROJECT_NAME = algo-hub
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wfloat-conversion -Werror -fsanitize=address -fsanitize=undefined -g -O2
BUILD_DIR = build
SRC_DIR = .
UNIT_TEST_SCRIPT = ./scripts/unit_test.sh
STRESS_TEST_SCRIPT = ./scripts/stress_test.sh
.DEFAULT_GOAL := build




# =========== High Level Targets ===========

# Build the full project
build:
	@echo "Building project..."
	@cmake -S $(SRC_DIR) -B $(BUILD_DIR)
	@cmake --build $(BUILD_DIR)

# Clean build artifacts
clean:
	@echo "Cleaning up build files..."
	@rm -rf $(BUILD_DIR)/

# Clean and build from scratch
rebuild: clean build




# ======= TEST TARGETS =======

unit_tests: build
	@echo "Running unit tests..."
	@./$(BUILD_DIR)/unit_tests

stress_tests: build
	@echo "Running stress tests..."
	@./$(BUILD_DIR)/stress_tests

# List all available unit test cases
list_tests:
	@echo "Listing all tests..."
	@./$(BUILD_DIR)/unit_tests --list

# Run a specific unit test
run_utest:
	@echo "Running unit test: $(TEST_NAME)"
	@$(UNIT_TEST_SCRIPT) $(TEST_NAME)
	@echo "Test $(TEST_NAME) completed."




# ======= MODULE GENERATION =======

# Generate new module
new_module:
	@echo "Creating new module..."
	@python3 scripts/create_module.py $(CATEGORY) $(ALGO)




# ======= QUICK COMPILE & RUN =======

# Compile and run a single file quickly (no full rebuild)
quick:
	@echo "Quick compile: $(FILE)"
	@if [ -z "$(FILE)" ]; then \
		echo "Error: FILE variable is not set. Use FILE=... to specify the file to compile."; \
		echo "Example: make quick FILE=path/to/your/file.cpp"; \
		exit 1; \
	fi
	$(CXX) $(CXXFLAGS) -std=c++20 \
		-Iinclude -Itest \
		test/core/BerlinTestManager.cpp test/main.cpp $(FILE) \
		-o quick.out && ./quick.out


# ======= HELP =======

help:
	@echo ""
	@echo "Makefile Commands:"
	@echo ""
	@echo "  build           - Configure and compile the full project"
	@echo "  rebuild         - Clean and recompile the project"
	@echo "  clean           - Remove build directory"
	@echo ""
	@echo "  unit_tests      - Build and run all unit tests"
	@echo "  stress_tests    - Build and run stress tests"
	@echo "  run_utest       - Run a specific test (use TEST_NAME=...)"
	@echo "  list_tests      - List all registered tests"
	@echo ""
	@echo "  new_module      - Create a new algorithm module (CATEGORY=... ALGO=...)"
	@echo ""
	@echo "  quick           - Compile and run a standalone file (use FILE=...)"
	@echo ""
	@echo "  help            - Show this help message"