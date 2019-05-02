// ============================== ALL OF TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            all_of.hpp
// Description:     Tests for all_of algorithm for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ALL_OF_TESTS_HPP_INCLUDED
#define _ALL_OF_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("all_of: is correct for trivial single word cases", "[all_of]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 0;
    bit_iterator<TestType*> first(&t, 0);
    bit_iterator<TestType*> last(&t + 1, 0);

    auto predicate = [](bit::bit_value bv) { return bv == bit::bit0; };

    REQUIRE(bit::all_of(first, last, predicate) 
        == std::all_of(first, last, predicate));
}

#endif
