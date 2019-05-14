// ============================== SHIFT TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            shift.hpp
// Description:     Tests for shift_left and shift_right algorithms 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _SHIFT_TESTS_HPP_INCLUDED
#define _SHIFT_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ------------------------------ Shift Tests ------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("Shift: left_shift", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, 
                            unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;
    bit::shift_left(bfirst1_t, blast1_t, 3);
    bit::word_shift_left(bool_first1_t, bool_last1_t, 3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    bit::shift_left(bfirst1_t, blast1_t, digits+3);
    bit::word_shift_left(bool_first1_t, bool_last1_t, digits+3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    bit::shift_left(bfirst1_t, blast1_t, digits*3);
    bit::word_shift_left(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2);
    std::advance(bool_last1_t, digits-2);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2);
    std::advance(blast1_t, digits-2);
    bit::shift_left(bfirst1_t, blast1_t, digits*3);
    bit::word_shift_left(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}



TEMPLATE_PRODUCT_TEST_CASE("Shift: right_shift", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, 
                            unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;
    bit::shift_right(bfirst1_t, blast1_t, 5);
    bit::word_shift_right(bool_first1_t, bool_last1_t, 5);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    std::advance(bfirst1_t, digits+1);
    std::advance(bool_first1_t, digits+1);
    bit::shift_right(bfirst1_t, blast1_t, digits+7);
    bit::word_shift_right(bool_first1_t, bool_last1_t, digits+7);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    bit::shift_right(bfirst1_t, blast1_t, digits);
    bit::word_shift_right(bool_first1_t, bool_last1_t, digits);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2*digits+2);
    std::advance(bool_last1_t, 3*digits-2);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2*digits+2);
    std::advance(blast1_t, 3*digits-2);
    bit::shift_right(bfirst1_t, blast1_t, digits*3);
    bit::word_shift_right(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SHIFT_TESTS_HPP_INCLUDED
// ========================================================================== //
