// ============================ ALG UTILS TESTS ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: alg_utils.hpp
// Description: tests for various algorithm utility functions 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ALG_UTILS_TESTS_HPP_INCLUDED
#define _ALG_UTILS_TESTS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_utils.hpp"
// Third-party libraries
#include "catch2.hpp"

TEMPLATE_TEST_CASE("read_word_raw does not read past the guard", "[read_word_raw]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType arr[2]; 
    arr[0] = 3;
    arr[1] = -1;

    constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;

    bit::bit_iterator<TestType*> start_read_pos(&arr[0], num_digits - 2); 
    bit::bit_iterator<TestType*> guard(&arr[1], 0);
    
    TestType raw_word = read_word_raw(start_read_pos, guard); 
    TestType expected = static_cast<TestType>(3) << (num_digits - 2);

    REQUIRE(raw_word == expected);
}

TEMPLATE_TEST_CASE("read_word_raw has no problems reading a full word \
    starting from the 0th bit", "[read_word_raw]", unsigned short, unsigned int,
    unsigned long, unsigned long long) {

    TestType arr[2];
    arr[0] = -1;
    arr[1] = 44;

    bit::bit_iterator<TestType*> read_start(&arr[0], 0);
    bit::bit_iterator<TestType*> guard(&arr[0] + 1, 0);

    TestType raw_word = read_word_raw(read_start, guard);

    REQUIRE(raw_word == static_cast<TestType>(-1));
}

TEMPLATE_TEST_CASE("set_word_raw does not write past the gaurd", "[set_word_raw]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType arr[2];
    arr[0] = 0;
    arr[1] = 0;
    
    constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;

    bit::bit_iterator<TestType*> start_write_pos(&arr[0], num_digits - 2);
    bit::bit_iterator<TestType*> guard(&arr[1], 0);

    bit::write_word_raw(start_write_pos, guard, static_cast<TestType>(-1));

    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 0);
}

TEMPLATE_TEST_CASE("shift_and_merge correctly builds a virtual word from two \
    separate words", "[shift_and_merge]", unsigned short, unsigned int, 
    unsigned long, unsigned long long) {

    TestType w1 = 0;
    TestType w2 = -1;

    constexpr std::size_t position = bit::binary_digits<TestType>::value / 2;

    TestType merged = bit::shift_and_merge(w1, w2, position);
    TestType expected = static_cast<TestType>(-1) >> position;

    REQUIRE(merged == expected);
}

TEMPLATE_TEST_CASE("shift_and_merge is correct from the 0th position",
    "[shift_and_merge]", unsigned short, unsigned int, unsigned long,
    unsigned long long) {

    TestType w1 = static_cast<TestType>(1) 
      << (bit::binary_digits<TestType>::value - 1);
    TestType w2 = static_cast<TestType>(-1);

    TestType merged = bit::shift_and_merge(w1, w2, 0);
    
    REQUIRE(merged == w1);
}

TEMPLATE_TEST_CASE("set_in_range does what you'd expect it to", "[set_in_range]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {
    TestType word = 0;

    bit::bit_iterator<TestType*> begin(&word);
    bit::bit_iterator<TestType*> end(&word, 5);

    set_in_range(begin, end, &word, bit::bit1); 

    REQUIRE(word == 31);

    set_in_range(begin, end, &word, bit::bit0);

    REQUIRE(word == 0);
}
// ========================================================================== //
#endif // _ALG_UTILS_TESTS_HPP_INCLUDED
// ========================================================================== //
