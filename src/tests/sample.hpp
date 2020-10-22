// ============================== SAMPLE TESTS ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: sample.hpp
// Description: tests for sample algorithm bit iterator overloads 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SAMPLE_TESTS_HPP_INCLUDED
#define _SAMPLE_TESTS_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// Project sources
// Third party libraries
#include "catch2.hpp"

TEMPLATE_TEST_CASE("Sampling bits of single number produces correct number of \
    bit samples", "[sample]", unsigned short, unsigned int, unsigned long, 
    unsigned long long) {

    TestType t = 255;

    bit::bit_iterator<TestType*> beg(&t, 0);
    bit::bit_iterator<TestType*> end(&t + 1, 0);

    std::vector<bit::bit_value> out; 

    std::size_t num_samples = 8;

    std::sample(beg, end, std::back_inserter(out), num_samples, 
        std::mt19937{std::random_device{}()});

    REQUIRE(out.size() == num_samples);
}

TEMPLATE_TEST_CASE("Sampling bits of number where all bits set only returns 1s", 
    "[sample]", unsigned short, unsigned int, unsigned long, unsigned long long) {
    TestType t = -1;  

    bit::bit_iterator<TestType*> beg(&t, 0);
    bit::bit_iterator<TestType*> end(&t + 1, 0);

    std::vector<bit::bit_value> out;

    std::size_t num_samples = 15;
    
    std::sample(beg, end, std::back_inserter(out), num_samples, 
        std::mt19937{std::random_device{}()});

    REQUIRE(std::all_of(out.begin(), out.end(), 
          [](bit::bit_value bv) { return bv == bit::bit1; })); 
}

// ========================================================================== //
#endif // _SAMPLE_TESTS_HPP_INCLUDED
// ========================================================================== //
