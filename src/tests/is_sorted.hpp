// ============================= IS SORTED TESTS ============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            find.hpp
// Description:     Tests for is_sorted algorithms for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_SORTED_TESTS_HPP_INCLUDED
#define _IS_SORTED_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("is_sorted: is correct for trivial single word cases", 
    "[is_sorted]", unsigned short, unsigned int, unsigned long, unsigned long long) {


    TestType t = static_cast<TestType>(-1); 
    
    bit::bit_iterator<TestType*> first1(&t, 0);
    bit::bit_iterator<TestType*> last1(&t + 1, 0);

    REQUIRE(bit::is_sorted(first1, last1) == std::is_sorted(first1, last1));

    t = 0;

    bit::bit_iterator<TestType*> first2(&t, 0);
    bit::bit_iterator<TestType*> last2(&t + 1, 0);

    REQUIRE(bit::is_sorted(first2, last2) == std::is_sorted(first2, last2));

    t = 5555;

    bit::bit_iterator<TestType*> first3(&t, 0);
    bit::bit_iterator<TestType*> last3(&t + 1, 0);

    REQUIRE(bit::is_sorted(first3, last3) == std::is_sorted(first3, last3));

    t = static_cast<TestType>(static_cast<TestType>(-1) << 6);

    bit::bit_iterator<TestType*> first4(&t, 0);
    bit::bit_iterator<TestType*> last4(&t + 1, 0);

    REQUIRE(bit::is_sorted(first4, last4) == std::is_sorted(first4, last4));
}

TEMPLATE_TEST_CASE("is_sorted: is correct for multi word containers",
    "[is_sorted]", unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_t = std::vector<TestType>;
    using vec_iter_t = typename std::vector<TestType>::iterator;

    vec_t vec = {0, 0, 8, static_cast<TestType>(-1)};

    bit::bit_iterator<vec_iter_t> first(vec.begin());
    bit::bit_iterator<vec_iter_t> last(vec.end());

    REQUIRE(bit::is_sorted(first, last) == std::is_sorted(first, last));

    vec = {static_cast<TestType>(-1), 0, static_cast<TestType>(-1)};

    bit::bit_iterator<vec_iter_t> first1(vec.begin());
    bit::bit_iterator<vec_iter_t> last1(vec.end());

    REQUIRE(bit::is_sorted(first1, last1) == std::is_sorted(first1, last1));
} 


#endif
