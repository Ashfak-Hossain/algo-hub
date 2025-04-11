cmake_minimum_required(VERSION 3.14)
project(algo-hub)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include paths
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/test)

# Collect core framework
file(GLOB_RECURSE CORE_TEST_SRCS test/core/*.cpp)

# Collect unit and stress test cases
file(GLOB_RECURSE UNIT_TESTS test/unit/*.cpp)
file(GLOB_RECURSE STRESS_TESTS test/stress/*.cpp)

# Build unit test runner
add_executable(unit_tests ${CORE_TEST_SRCS} ${UNIT_TESTS} test/main.cpp)
add_executable(stress_tests ${CORE_TEST_SRCS} ${STRESS_TESTS} test/main.cpp)