cmake_minimum_required(VERSION 3.10)

# set the project name
project(Bit-Algorithms VERSION 0.1)

# set output directory of builds
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_BENCHMARKS "Build Google Bechmarks" ON)

# specify global compiler flags
add_compile_options(-std=c++17 -march=native -pedantic -Wall -Wextra)

# add the tests executable
add_executable(tests src/tests/test_main.cc src/tests/test_root.cc)

# configure benchmarks
if (BUILD_BENCHMARKS)
    add_executable(benchmarks src/benchmarks/benchmark_main.cc)
    target_compile_options(benchmarks PUBLIC -O3 -DNDEBUG -mtune=native)
    find_package(benchmark)
    target_link_libraries(benchmarks benchmark::benchmark)
    target_include_directories(benchmarks PRIVATE ./ext/libsimdpp ./include ./ext/libsimdpp ./ext/bit)
    install(TARGETS benchmarks DESTINATION .)
endif()

# specify the C++ standard
set_property(GLOBAL PROPERTY CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED true)

# specify global include directories
include_directories(./ext/libsimdpp ./include ./ext/libsimdpp ./ext/bit)

# specify test-specific flags
target_compile_options(tests PUBLIC -O0 -g -fno-omit-frame-pointer -pg)

# specify test-specific libraries
target_include_directories(tests PRIVATE ./ext/catch)

install(TARGETS tests DESTINATION .)
