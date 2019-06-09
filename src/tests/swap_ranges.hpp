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
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// --------------------------- swap_ranges Tests ---------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: single word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short)) {
    //, unsigned int, 
                            //unsigned long, unsigned long long)) {
    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type, unsigned short>
                                     (container_size*8); //, std::numeric_limits<num_type>::max(),
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

    std::advance(bfirst1_t, digits);
    std::advance(bool_first1_t, digits);
    bit::swap_ranges(bfirst1, bfirst1_t, bfirst2);
    std::swap_ranges(bool_first1, bool_first1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, 2);
    bool_first1_t = std::next(bool_first1, 2);
    blast1_t = std::next(bfirst1, digits-2);
    bool_last1_t = std::next(bool_first1, digits-2);
    bit::swap_ranges(bfirst1, blast1_t, bfirst2);
    std::swap_ranges(bool_first1, bool_last1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, 3);
    bool_first1_t = std::next(bool_first1, 3);
    blast1_t = std::next(bfirst1, digits-2);
    bool_last1_t = std::next(bool_first1, digits-2);
    bfirst2_t = std::next(bfirst1, 7);
    bool_first2_t = std::next(bool_first1, 7);
    bit::swap_ranges(bfirst1, blast1_t, bfirst2);
    std::swap_ranges(bool_first1, bool_last1_t, bool_first2);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}

TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: multiple words aligned", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short)) {
    //, unsigned int, 
                            //unsigned long, unsigned long long)) {
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
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, 3);
    bool_first1_t = std::next(bool_first1, 3);
    bfirst2_t = std::next(bfirst2, 3);
    bool_first2_t = std::next(bool_first2, 3);
    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, digits-1);
    bool_first1_t = std::next(bool_first1, digits-1);
    bfirst2_t = std::next(bfirst2, digits-1);
    bool_first2_t = std::next(bool_first2, digits-1);
    blast1_t = std::next(bfirst1, digits*4+1);
    bool_last1_t = std::next(bool_first1, digits*4+1);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}

TEMPLATE_PRODUCT_TEST_CASE("swap_ranges: multiple words unaligned", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short)) {
    //, unsigned int, 
                            //unsigned long, unsigned long long)) {
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
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bfirst1_t = std::next(bfirst1, 4);
    bool_first1_t = std::next(bool_first1, 4);
    bfirst2_t = std::next(bfirst2, 3);
    bool_first2_t = std::next(bool_first2, 3);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, digits-1);
    bool_first1_t = std::next(bool_first1, digits-1);
    bfirst2_t = std::next(bfirst2, digits-2);
    bool_first2_t = std::next(bool_first2, digits-2);
    blast1_t = std::next(bfirst1, digits*2-5);
    bool_last1_t = std::next(bool_first1, digits*2-5);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bfirst1_t = std::next(bfirst1, digits-2);
    bool_first1_t = std::next(bool_first1, digits-2);
    bfirst2_t = std::next(bfirst2, digits-1);
    bool_first2_t = std::next(bool_first2, digits-1);
    blast1_t = std::next(bfirst1, digits*4+1);
    bool_last1_t = std::next(bool_first1, digits*4+1);
    bit::swap_ranges(bfirst1_t, blast1_t, bfirst2_t);
    std::swap_ranges(bool_first1_t, bool_last1_t, bool_first2_t);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SWAP_RANGES_TESTS_HPP_INCLUDED
// ========================================================================== //
