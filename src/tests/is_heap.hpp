// ============================= IS HEAP TESTS ============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            find.hpp
// Description:     Tests for is_heap algorithms for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_HEAP_TESTS_HPP_INCLUDED
#define _IS_HEAP_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("is_heap: is correct for trivial single word cases", "[is_heap]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 1;

    bit::bit_iterator<TestType*> first1(&t, 0);
    bit::bit_iterator<TestType*> last1(&t + 1, 0);

    REQUIRE(bit::is_heap(first1, last1) == std::is_heap(first1, last1));

    t = static_cast<TestType>(-1);
    bit::bit_iterator<TestType*> first2(&t, 0);
    bit::bit_iterator<TestType*> last2(&t + 1, 0);

    REQUIRE(bit::is_heap(first2, last2) == std::is_heap(first2, last2));
}

#endif
