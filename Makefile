.DEFAULT_GOAL = tests

# compiler configuration
CXX = clang++
CXX_STANDARD = c++2a
WARNING_FLAGS = -pedantic -Wall -Wextra
DEBUG_FLAGS = -O0 -g
OPTIMIZED_FLAGS = -O3 -g -DNDEBUG -march=native -mtune=native
TEST_FLAGS = ${WARNING_FLAGS} ${DEBUG_FLAGS}
BENCHMARK_FLAGS = ${WARNING_FLAGS} ${OPTIMIZED_FLAGS}
EXAMPLE_FLAGS = ${WARNING_FLAGS} ${OPTIMIZED_FLAGS}

# directories
BUILD_DIR = build
TEST_DIR = src/tests
EXAMPLE_DIR = src/examples

# source code
BIT_HEADERS = $(wildcard ext/bit/*.hpp)
BIT_ALGORITHM_HEADERS = $(wildcard include/*.hpp)
TEST_SRCS = ${TEST_DIR}/test_root.cc ${TEST_DIR}/count.hpp ${TEST_DIR}/reverse.hpp ${TEST_DIR}/test_utils.hpp

INCLUDES = -I${PWD}/ext -I${PWD}/ext/bit -I${PWD}/include

# tests
TEST_OBJS = ${BUILD_DIR}/test_main.o ${BUILD_DIR}/test_root.o
${BUILD_DIR}/test_main.o: ext/catch2.hpp ${TEST_DIR}/test_main.cc 
	mkdir -p ${BUILD_DIR}
	${CXX} -std=${CXX_STANDARD} ${TEST_FLAGS} ${INCLUDES} ${TEST_DIR}/test_main.cc -c -o $@
${BUILD_DIR}/test_root.o: ext/catch2.hpp ${BIT_HEADERS} ${BIT_ALGORITHM_HEADERS} ${TEST_SRCS} 
	mkdir -p ${BUILD_DIR}
	${CXX} -std=${CXX_STANDARD} ${TEST_FLAGS} ${INCLUDES} ${TEST_DIR}/test_root.cc -c -o $@ 
tests: ${TEST_OBJS}
	mkdir -p ${BUILD_DIR}
	${CXX} ${TEST_OBJS} -o ${BUILD_DIR}/tests 

# run tests
test: tests
	./${BUILD_DIR}/tests

# examples
ex1.o: ${EXAMPLE_DIR}/ex1.cc ${BIT_HEADERS} ${BIT_ALGORITHM_HEADERS} 
	mkdir -p ${BUILD_DIR}
	${CXX} -std=${CXX_STANDARD} ${EXAMPLE_FLAGS} ${INCLUDES} ${EXAMPLE_DIR}/ex1.cc -c -o $@ 
ex1: ex1.o
	${CXX} $< -o ${BUILD_DIR}/$@

examples: ex1

# documentation
.PHONY: docs
docs:
	doxygen doxygen.cfg

# cleanup
.PHONY: clean
clean:
	rm -rf build 
