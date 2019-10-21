// ============================== FOR EACH TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            for_each.hpp
// Description:     Tests for for_each algorithm for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FOR_EACH_TESTS_HPP_INCLUDED
#define _FOR_EACH_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("for_each: is correct for trivial single word cases", "[for_each]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 0;
    bit::bit_iterator<TestType*> first(&t, 0);
    bit::bit_iterator<TestType*> last(&t + 1, 0);

    auto lambda = [](bit::bit_reference<TestType> br) { br = bit::bit1; }; 

    TestType expected_t = 0;
    bit::bit_iterator<TestType*> expected_first(&expected_t, 0);
    bit::bit_iterator<TestType*> expected_last(&expected_t + 1, 0);

    bit::for_each(first, last, lambda);
    std::for_each(expected_first, expected_last, lambda);

    REQUIRE(t == expected_t);
}

#endif
