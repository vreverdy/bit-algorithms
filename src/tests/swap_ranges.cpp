// =========================== SWAP_RANGES TESTS ============================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            swap_ranges.hpp
// Description:     Tests for shift_left and shift_right algorithms 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _SWAP_RANGES_TESTS_HPP_INCLUDED
#define _SWAP_RANGES_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "catch2.hpp"
#include "bit.hpp"
#include "test_utils.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// --------------------------- swap_ranges Tests ---------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: single word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, unsigned int,
                            unsigned long)) {
    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;

    std::advance(bfirst1_t, digits);
    std::advance(bool_first1_t, digits);
    auto bret = bit::swap_ranges(bfirst1, bfirst1_t, bfirst2);
    auto bool_ret = std::swap_ranges(bool_first1, bool_first1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    blast1_t = std::next(bfirst1, digits-2);
    bool_last1_t = std::next(bool_first1, digits-2);
    bret = bit::swap_ranges(bfirst1, blast1_t, bfirst2);
    bool_ret = std::swap_ranges(bool_first1, bool_last1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, 3);
    bool_first1_t = std::next(bool_first1, 3);
    blast1_t = std::next(bfirst1, digits-2);
    bool_last1_t = std::next(bool_first1, digits-2);
    bfirst2_t = std::next(bfirst1, 7);
    bool_first2_t = std::next(bool_first1, 7);
    bret = bit::swap_ranges(bfirst1, blast1_t, bfirst2);
    bool_ret = std::swap_ranges(bool_first1, bool_last1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: multiple words aligned", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, unsigned int,
                            unsigned long)) {
    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;

    blast1_t = std::next(bfirst1, digits*2);
    bool_last1_t = std::next(bool_first1, digits*2);
    auto bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    auto bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, 3);
    bool_first1_t = std::next(bool_first1, 3);
    bfirst2_t = std::next(bfirst2, 3);
    bool_first2_t = std::next(bool_first2, 3);
    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, digits-1);
    bool_first1_t = std::next(bool_first1, digits-1);
    bfirst2_t = std::next(bfirst2, digits-1);
    bool_first2_t = std::next(bool_first2, digits-1);
    blast1_t = std::next(bfirst1, digits*4+1);
    bool_last1_t = std::next(bool_first1, digits*4+1);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: multiple words unaligned", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, unsigned int,
                            unsigned long)) {
    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first1_t = bool_first1;
    auto bool_first2_t = bool_first2;
    auto bfirst1_t = bfirst1;
    auto bfirst2_t = bfirst2;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;

    blast1_t = std::next(bfirst1, digits*2);
    bool_last1_t = std::next(bool_first1, digits*2);
    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    bfirst2_t = std::next(bfirst2, 3);
    bool_first2_t = std::next(bool_first2, 3);
    auto bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    auto bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bfirst1_t = std::next(bfirst1, 4);
    bool_first1_t = std::next(bool_first1, 4);
    bfirst2_t = std::next(bfirst2, 3);
    bool_first2_t = std::next(bool_first2, 3);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, digits-1);
    bool_first1_t = std::next(bool_first1, digits-1);
    bfirst2_t = std::next(bfirst2, digits-2);
    bool_first2_t = std::next(bool_first2, digits-2);
    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));

    bfirst1_t = std::next(bfirst1, digits-2);
    bool_first1_t = std::next(bool_first1, digits-2);
    bfirst2_t = std::next(bfirst2, digits-1);
    bool_first2_t = std::next(bool_first2, digits-1);
    blast1_t = std::next(bfirst1, digits*4+1);
    bool_last1_t = std::next(bool_first1, digits*4+1);
    bret = bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    bool_ret = std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst2, bret) == std::distance(bool_first2, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: multiple words unaligned same container", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, unsigned int,
                            unsigned long)) {
    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 7;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);

    auto bret = bit::swap_ranges(
            bfirst1, 
            std::next(bfirst1, digits), 
            std::next(bfirst1, digits+4)
    );
    auto bool_ret = std::swap_ranges(
            bool_first1, 
            std::next(bool_first1, digits), 
            std::next(bool_first1, digits+4)
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
    
    bret = bit::swap_ranges(
            bfirst1, 
            std::next(bfirst1, 4), 
            std::next(bfirst1, 4)
    );
    bool_ret = std::swap_ranges(
            bool_first1, 
            std::next(bool_first1, 4), 
            std::next(bool_first1, 4)
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bret = bit::swap_ranges(
            std::next(bfirst1, digits-3), 
            std::next(bfirst1, digits+3), 
            std::next(bfirst1, digits+4)
    );
    bool_ret = std::swap_ranges(
            std::next(bool_first1, digits-3), 
            std::next(bool_first1, digits+3), 
            std::next(bool_first1, digits+4)
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SWAP_RANGES_TESTS_HPP_INCLUDED
// ========================================================================== //
