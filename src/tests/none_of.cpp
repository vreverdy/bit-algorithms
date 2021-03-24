// ============================== NONE OF TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            none_of.hpp
// Description:     Tests for none_of algorithm for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _NONE_OF_TESTS_HPP_INCLUDED
#define _NONE_OF_TESTS_HPP_INCLUDED
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

TEMPLATE_TEST_CASE("none_of: is correct for trivial single word cases", "[none_of]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 0;
    bit::bit_iterator<TestType*> first(&t, 0);
    bit::bit_iterator<TestType*> last(&t + 1, 0);

    auto predicate = [](bit::bit_value bv) { return bv == bit::bit1; };

    REQUIRE(bit::none_of(first, last, predicate) 
        == std::none_of(first, last, predicate));
}

#endif
