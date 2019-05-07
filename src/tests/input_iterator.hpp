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


/* This class is essentially just a wrapper around another iterator.
 * As such, we'll just perform some basic sanity checks to make sure
 * we haven't made silly logical errors */

TEMPLATE_TEST_CASE("input_iterator: equality is sane", "[input_iterator]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    using vec_iter_type = typename vec_type::iterator;

    vec_type vec = {1, 2, 3};

    bit::input_iterator<vec_iter_type> in_iter_beg(vec.begin());
    bit::input_iterator<vec_iter_type> in_iter_end(vec.end());

    REQUIRE(in_iter_beg != in_iter_end);

    bit::input_iterator<vec_iter_type> in_iter_beg2(vec.begin());
    REQUIRE(in_iter_beg == in_iter_beg2);
}

TEMPLATE_TEST_CASE("input_iterator: dereference is sane", "[input_iterator]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    using vec_iter_type = typename vec_type::iterator;

    vec_type vec = {1, 2, 3}; 

    vec_iter_type beg = vec.begin();
    vec_iter_type end = vec.end();

    bit::input_iterator<vec_iter_type> in_iter_beg(beg);
    bit::input_iterator<vec_iter_type> in_iter_end(end);

    REQUIRE(*in_iter_beg == *beg);
    REQUIRE(*in_iter_end == *end);
}

TEMPLATE_TEST_CASE("input_iterator: arrow operator is sane", "[input_iterator]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    using vec_iter_type = typename vec_type::iterator;

    vec_type vec = {1, 2, 3};

    vec_iter_type beg = vec.begin(); 
    vec_iter_type end = vec.end();

    bit::input_iterator<vec_iter_type> in_iter_beg(beg);
    bit::input_iterator<vec_iter_type> in_iter_end(end);

    REQUIRE(in_iter_beg.operator->() == beg.operator->()); 
    REQUIRE((++in_iter_beg).operator->() == (++beg).operator->());
    REQUIRE((++in_iter_end).operator->() == (++end).operator->());
}

TEMPLATE_TEST_CASE("input_iterator: prefix increment is sane", "[input_iterator]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    using vec_iter_type = typename vec_type::iterator;

    vec_type vec = {1, 2, 3};

    vec_iter_type beg = vec.begin();
    bit::input_iterator<vec_iter_type> in_iter_beg(beg);

    vec_iter_type& beg_plus_one = ++beg;

    bit::input_iterator<vec_iter_type>& in_iter_beg_plus_one = ++in_iter_beg;

    REQUIRE(*in_iter_beg_plus_one == 2);
    REQUIRE(*beg_plus_one == *in_iter_beg_plus_one);
}

TEMPLATE_TEST_CASE("input_iterator: postfix increment is sane", "[input_iterator]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    using vec_iter_type = typename vec_type::iterator;

    vec_type vec = {1, 2, 3};

    vec_iter_type beg = vec.begin();
    bit::input_iterator<vec_iter_type> in_iter_beg(beg);

    vec_iter_type beg_copy = beg++;

    bit::input_iterator<vec_iter_type> in_iter_beg_copy = in_iter_beg++; 

    REQUIRE(*in_iter_beg_copy == *beg_copy);
    REQUIRE(*beg == *in_iter_beg);
}

#endif
