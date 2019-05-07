// ============================== ANY OF TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            any_of.hpp
// Description:     Tests for all_of algorithm for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INPUT_ITERATOR_TESTS_HPP_INCLUDED
#define _INPUT_ITERATOR_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("input_iteratorrr", "[input_iteratorrr]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<int>;
    using vec_iter_type = vec_type::iterator;

    std::vector<int> vec = {1, 2, 3};

    bit::input_iterator<vec_iter_type> in_iter_beg(vec.begin());
    bit::input_iterator<vec_iter_type> in_iter_end(vec.end());

    REQUIRE(in_iter_beg != in_iter_end);
}

#endif
