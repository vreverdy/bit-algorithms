// ========================== PADDED READ TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            padded_read.hpp
// Description:     Tests for _padded_read utility function 
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PADDED_READ_TESTS_HPP_INCLUDED
#define _PADDED_READ_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
#include <iostream>
// Project sources
#include "catch2.hpp"
#include "bit.hpp"
#include "test_utils.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// --------------------------- Padded Read Tests ---------------------------- //
TEMPLATE_TEST_CASE("padded read: correctly reads a full word", "[padded_read]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = -1;
    bit::bit_iterator<TestType*> beg(&t);
    bit::bit_iterator<TestType*> end(&t + 1);

    TestType read = bit::_padded_read(beg, end, bit::bit0); 

    CHECK(read == t);
}

TEMPLATE_TEST_CASE("padded read: correctly reads partial word ranges", 
    "[padded_read]", unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = -1;
    constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;

    bit::bit_iterator<TestType*> beg(&t);
    bit::bit_iterator<TestType*> half(&t, num_digits / 2);

    TestType read = bit::_padded_read(beg, half, bit::bit0);

    REQUIRE(read == std::pow(2, num_digits / 2) - 1);

    read = bit::_padded_read(beg, half, bit::bit1);

    REQUIRE(read == static_cast<TestType>(-1));

    bit::bit_iterator<TestType*> end(&t + 1); 
    read = bit::_padded_read(half, end, bit::bit0);

    REQUIRE(read == bit::_shift_towards_msb(static_cast<TestType>(-1), num_digits / 2));
}

TEMPLATE_TEST_CASE("padded read: does not read outside of the word pointed to \
    by the first iterator", "[padded_read]", unsigned short, unsigned int,
    unsigned long, unsigned long long) {

    std::vector<TestType> vec = {0, static_cast<TestType>(-1)};
    using bit_iter_t = bit::bit_iterator<typename decltype(vec)::iterator>;
    constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;

    bit_iter_t first(vec.begin(), num_digits - 2); 
    bit_iter_t last(vec.begin() + 1, 4);

    TestType read = bit::_padded_read(first, last, bit::bit0);

    REQUIRE(read == 0);

    vec = {static_cast<TestType>(-1), 0};

    read = bit::_padded_read(first, last, bit::bit0);
    REQUIRE(read == bit::_shift_towards_msb(static_cast<TestType>(-1), 
          num_digits - 2));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _PADDED_READ_TESTS_HPP_INCLUDED
// ========================================================================== //
