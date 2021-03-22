// ============================ BIT UTILS TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            bit_details.hpp
// Description:     tests for various bit utility functions 
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
//                  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _BIT_UTILS_TESTS_HPP_INCLUDED
#define _BIT_UTILS_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit.hpp"
#include "test_utils.hpp"
// Third-party libraries
#include "catch2.hpp"
// ========================================================================== //



// ------------------------------ BIT TESTS --------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("bit_exch", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned short, unsigned int,
                            unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 2;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);

    // 1st overload (on first half of word)
    bit::_bitexch(*bfirst1.base(), *(bfirst1.base()+1),  
            static_cast<num_type>(
                static_cast<num_type>( 
                    static_cast<num_type>(1) << 8) 
            - 1)
    );
    std::swap_ranges(bool_first1, bool_first1+8, bool_first1+digits);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // 1st overload (on part of word)
    bit::_bitexch(*bfirst1.base(), *(bfirst1.base()+1),  
            static_cast<num_type>(
                static_cast<num_type>(
                    static_cast<num_type>( 
                        static_cast<num_type>(1) << 8) 
                - 1)
            << 3)
    );
    std::swap_ranges(bool_first1+3, bool_first1+11, bool_first1+digits+3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // 2nd overload (start position and length)
    unsigned int start0 = 4;
    unsigned int len = 5;
    bit::_bitexch(*bfirst1.base(), *(bfirst1.base()+1),  
            static_cast<num_type>(start0),
            static_cast<num_type>(len)
    );
    std::swap_ranges(bool_first1+start0, bool_first1+start0+len, bool_first1+digits+start0);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // start0 == start1
    unsigned int start1 = 4;
    len = 5;
    bit::_bitexch(
            *bfirst1.base(), 
            *(bfirst1.base()+1),  
            static_cast<num_type>(start0),
            static_cast<num_type>(start1),
            static_cast<num_type>(len)
    );
    std::swap_ranges(
            bool_first1+start0, 
            bool_first1+start0+len, 
            bool_first1+digits+start1
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // start0 > start1
    start0 += 2; 
    bit::_bitexch(
            *bfirst1.base(), 
            *(bfirst1.base()+1),  
            static_cast<num_type>(start0),
            static_cast<num_type>(start1),
            static_cast<num_type>(len)
    );
    std::swap_ranges(
            bool_first1+start0, 
            bool_first1+start0+len, 
            bool_first1+digits+start1
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // start0 < start1
    start1 += 4; 
    bit::_bitexch(
            *bfirst1.base(), 
            *(bfirst1.base()+1),  
            static_cast<num_type>(start0),
            static_cast<num_type>(start1),
            static_cast<num_type>(len)
    );
    std::swap_ranges(
            bool_first1+start0, 
            bool_first1+start0+len, 
            bool_first1+digits+start1
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // Same word
    start0 = 0;
    start1 = digits/2; 
    len = digits/2;
    bit::_bitexch(
            *bfirst1.base(), 
            *bfirst1.base(),  
            static_cast<num_type>(start0),
            static_cast<num_type>(start1),
            static_cast<num_type>(len)
    );
    std::swap_ranges(
            bool_first1+start0, 
            bool_first1+start0+len, 
            bool_first1+start1
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _BIT_UTILS_TESTS_HPP_INCLUDED
// ========================================================================== //
