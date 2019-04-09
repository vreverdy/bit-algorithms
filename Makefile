.DEFAULT_GOAL = tests

# compiler configuration
CXX = clang++
CXX_STANDARD = c++2a

ifeq ($(CXX), clang++)
  ERR_LIMIT = -ferror-limit=1  
else
  ERR_LIMIT = -fmax-errors=1
endif

WARNING_FLAGS = -pedantic -Wall -Wextra
DEBUG_FLAGS = -O0 -g -fno-omit-frame-pointer
OPTIMIZED_FLAGS = -O3 -g -DNDEBUG -march=native -mtune=native
TEST_FLAGS = ${ERR_LIMIT} ${WARNING_FLAGS} ${DEBUG_FLAGS}
BENCHMARK_FLAGS = ${ERR_LIMIT} ${WARNING_FLAGS} ${OPTIMIZED_FLAGS}
EXAMPLE_FLAGS = ${ERR_LIMIT} ${WARNING_FLAGS} ${OPTIMIZED_FLAGS}

# directories
BUILD_DIR = build
TEST_DIR = src/tests
EXAMPLE_DIR = src/examples

# source code
BIT_HEADERS = $(wildcard ext/bit/*.hpp)
BIT_ALGORITHM_HEADERS = $(wildcard include/*.hpp)
TEST_HEADERS = $(wildcard ${TEST_DIR}/*.hpp)
TEST_SRCS = ${TEST_DIR}/test_root.cc ${TEST_HEADERS} 

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
EXAMPLES = $(notdir $(patsubst %.cc,%, $(wildcard ${EXAMPLE_DIR}/ex*)))
EXAMPLE_OBJS = $(addprefix ${BUILD_DIR}/,$(EXAMPLES:=.o))

${BUILD_DIR}/ex%.o: ${EXAMPLE_DIR}/ex%.cc ${BIT_HEADERS} ${BIT_ALGORITHM_HEADERS}
	mkdir -p ${BUILD_DIR}
	${CXX} -std=${CXX_STANDARD} ${DEBUG_FLAGS} ${INCLUDES} $< -c -o $@

$(EXAMPLES): ex%: ${BUILD_DIR}/ex%.o 
	${CXX} $< -o ${BUILD_DIR}/$@



examples: ${EXAMPLES}

# documentation
.PHONY: docs
docs:
	doxygen Doxyfile

# cleanup
.PHONY: clean
clean:
	rm -rf build 
