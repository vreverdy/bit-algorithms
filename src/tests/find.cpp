// ============================== FIND TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            find.hpp
// Description:     Tests for find, find_if, find_if_not algorithms 
//                  for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FIND_TESTS_HPP_INCLUDED
#define _FIND_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "catch2.hpp"
#include "bit.hpp"
#include "test_utils.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("find: is correct for trivial single word cases", "[find]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 7;
    bit::bit_iterator<TestType*> first(&t, 0);
    bit::bit_iterator<TestType*> last(&t + 1, 0);

    auto pos = bit::find(first, last, bit::bit0); 
    auto pos_expected = std::find(first, last, bit::bit0);

    REQUIRE(pos == pos_expected);
}

TEMPLATE_TEST_CASE("find: finding first set bit works for vectors", "[find]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_t = std::vector<TestType>;
    using vec_iter_t = typename vec_t::iterator;
    
    vec_t vec = {0, 0, 8, 0};

    bit::bit_iterator<vec_iter_t> first(vec.begin());
    bit::bit_iterator<vec_iter_t> last(vec.end());

    auto pos = bit::find(first, last, bit::bit1);
    auto pos_expected = std::find(first, last, bit::bit1);

    REQUIRE(pos == pos_expected);

    vec_t vec2 = {static_cast<TestType>(-1), static_cast<TestType>(-1), 3, 0};
    bit::bit_iterator<vec_iter_t> first2(vec2.begin());
    bit::bit_iterator<vec_iter_t> last2(vec2.end());

    pos = bit::find(first2, last2, bit::bit0);
    pos_expected = std::find(first2, last2, bit::bit0);

    REQUIRE(pos == pos_expected);
}

TEMPLATE_TEST_CASE("find: is ok for virtual/misaligned words", "[find]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_t = std::vector<TestType>;
    using vec_iter_t = typename vec_t::iterator;

    vec_t vec = {7, 0, 8};

    bit::bit_iterator<vec_iter_t> first(vec.begin(), 5);
    bit::bit_iterator<vec_iter_t> last(vec.begin() + 2, 2);

    REQUIRE(bit::find(first, last, bit::bit1) ==
            std::find(first, last, bit::bit1));
}




#endif
