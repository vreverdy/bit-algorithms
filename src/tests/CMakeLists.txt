set(test_srcs reverse.cc)
add_executable(tests test_main.cc ${test_srcs})

add_test(NAME tests COMMAND tests)

