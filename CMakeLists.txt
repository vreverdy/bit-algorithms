cmake_minimum_required(VERSION 3.10)

# set the project name
project(Bit-Algorithms VERSION 0.1)

# set output directory of builds
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# specify global compiler flags
add_compile_options(-std=c++2a -march=native -pedantic -Wall -Wextra)

# add the executable
add_executable(tests src/tests/test_main.cc src/tests/test_root.cc)
add_executable(benchmarks src/benchmarks/benchmark_main.cc)

# specify the C++ standard
set_property(GLOBAL PROPERTY CXX_STANDARD 20)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED true)

# specify target-specific flags
target_compile_options(tests PUBLIC -O0 -g -fno-omit-frame-pointer -pg)
target_compile_options(benchmarks PUBLIC -O3 -DNDEBUG -mtune=native)


#include libraries 
find_package(benchmark REQUIRED)
target_link_libraries(benchmarks benchmark::benchmark)
target_include_directories(tests PRIVATE ./ext/libsimdpp ./include ./ext/catch ./ext/libsimdpp ./ext/bit)
target_include_directories(benchmarks PRIVATE ./ext/libsimdpp ./include ./ext/libsimdpp ./ext/bit)

install(TARGETS tests DESTINATION .)
install(TARGETS benchmarks DESTINATION .)
