# Minimum CMake Version Required
cmake_minimum_required(VERSION 3.14)

# Project Name and Language
project(algo-hub LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Enable extra compiler warnings and sanitizer tools
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wfloat-conversion -Werror -fsanitize=undefined -fsanitize=address -g -O2")

# Include Directories
# Tell the compiler where to find #include headers
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/test
)

# Collect Source Files
file(GLOB_RECURSE CORE_TEST_SRCS test/core/*.cpp)
file(GLOB_RECURSE UNIT_TESTS test/unit/*.cpp)
file(GLOB_RECURSE STRESS_TESTS test/stress/*.cpp)

# ----------------------
# Unit Tests Target
# ----------------------
add_executable(unit_tests ${CORE_TEST_SRCS} ${UNIT_TESTS} test/main.cpp)
target_compile_options(unit_tests PRIVATE
        -Wall                   # Basic warnings
        -Wextra                 # Extra useful warnings
        -Wpedantic              # Strict standard compliance
        -Wshadow                # Catch shadowed variables
        -Wconversion            # Warn on implicit type conversion
        -Wfloat-conversion      # Warn on float→int or float↔float conversions
        -Wfloat-equal           # Warn on float comparisons using ==
        -Wno-sign-conversion    # Allow signed↔unsigned conversion without warning
        -Werror                 # Treat warnings as errors
        -fsanitize=address
        -fsanitize=undefined
        -g                      # Debug symbols
        -O2                     # Optimization level for testing
)
target_link_options(unit_tests PRIVATE
        -fsanitize=address
        -fsanitize=undefined
)

# -------------------------
# Stress Tests Target
# -------------------------
add_executable(stress_tests ${CORE_TEST_SRCS} ${STRESS_TESTS} test/main.cpp)
target_compile_options(stress_tests PRIVATE
        -Wall
        -Wextra
        -Wshadow
        -Wconversion
        -Wfloat-equal
        -fsanitize=address
        -fsanitize=undefined
        -g
        -O2
)
target_link_options(stress_tests PRIVATE
        -fsanitize=address
        -fsanitize=undefined
)