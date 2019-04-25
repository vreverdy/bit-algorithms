// ============================= MISMATCH TESTS ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: mismatch.hpp
// Description: tests for mismatch algorithm bit iterator overloads 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MISMATCH_TESTS_HPP_INCLUDED
#define _MISMATCH_TESTS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_utils.hpp"
// Third party libraries
#include "catch2.hpp"

using bit::bit_iterator;

TEMPLATE_TEST_CASE("Single number", "[mismatch]", unsigned short, unsigned int, 
    unsigned long, unsigned long long) {
    using num_type = TestType;
    num_type n1 = 4;
    num_type n2 = 8;

    bit_iterator<num_type*> n1_beg(&n1, 0);
    bit_iterator<num_type*> n2_beg(&n2, 0);

    bit_iterator<num_type*> n1_end(&n1 + 1, 0);
    bit_iterator<num_type*> n2_end(&n2 + 1, 0);

    auto p = mismatch(n1_beg, n1_end, n2_beg, n2_end);

    REQUIRE(p.first.position() == 2);
}

TEMPLATE_TEST_CASE("Vector", "[mismatch]", unsigned short, unsigned int,
    unsigned long, unsigned long long) {
  
    using vec_type = std::vector<TestType>;

    vec_type vec1 = {2, 3, 4, 5};
    vec_type vec2 = {2, 3, 5, 4};
    
    bit_iterator<typename vec_type::iterator> b1(vec1.begin(), 0);
    bit_iterator<typename vec_type::iterator> b2(vec2.begin(), 0);
    bit_iterator<typename vec_type::iterator> e1(vec1.end(), 0);
    bit_iterator<typename vec_type::iterator> e2(vec2.end(), 0);

    bit_iterator<typename vec_type::iterator> expected1(vec1.begin() + 2, 0);
    bit_iterator<typename vec_type::iterator> expected2(vec2.begin() + 2, 0);

    auto p = mismatch(b1, e1, b2, e2); 
     
    REQUIRE(expected1.position() == p.first.position());
    REQUIRE(*expected1 == *(p.first));
    REQUIRE(expected2.position() == p.second.position());
    REQUIRE(*expected2 == *(p.second));
}

TEMPLATE_TEST_CASE("Misaligned vector works", "[mismatch]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_type = std::vector<TestType>;
    
    vec_type vec1 = {80, 24, 890}; // 890 =   001101111010
    vec_type vec2 = {80, 24, 3116}; // 3116 = 110000101100 

    using biter = bit::bit_iterator<typename vec_type::iterator>;

    biter vec1_begin(vec1.begin());
    biter vec1_end(vec1.end());
    biter vec2_begin(vec2.begin());
    biter vec2_end(vec2.end());

    auto res = bit::mismatch(vec1_begin, vec1_end, vec2_begin, vec2_end);

    REQUIRE(res.first.position() == 1);
    REQUIRE(res.second.position() == 1);

    REQUIRE(*(res.first.base()) == 890);
    REQUIRE(*(res.second.base()) == 3116);
}

// ========================================================================== //
#endif // _MISMATCH_TESTS_HPP_INCLUDED
// ========================================================================== //

