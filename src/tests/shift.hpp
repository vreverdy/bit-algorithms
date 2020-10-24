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
TEMPLATE_PRODUCT_TEST_CASE("Shift: left_shift- multi word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 200;
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
    
    // All aligned, small shift
    auto bret = bit::shift_left(bfirst1_t, blast1_t, 3);
    auto bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, 3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // First unaligned, >word shift
    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    bret = bit::shift_left(bfirst1_t, blast1_t, digits+3);
    bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, digits+3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    // Last unaligned, > word shift
    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    bret = bit::shift_left(bfirst1, blast1_t, digits*3);
    bool_ret = bit::word_shift_left(bool_first1, bool_last1_t, digits*3);
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));

    // Both unaligned, > word shift
    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2);
    std::advance(bool_last1_t, digits-2);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2);
    std::advance(blast1_t, digits-2);
    bret = bit::shift_left(bfirst1_t, blast1_t, digits*3);
    bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Shift: left_shift- single word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 200;
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

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 1);
    std::advance(bool_last1_t, digits-1);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 1);
    std::advance(blast1_t, digits-1);

    auto bret = bit::shift_left(bfirst1_t, blast1_t, 3);
    auto bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, 3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
    
    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, digits+3);
    std::advance(bool_last1_t, 2*digits-3);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, digits+3);
    std::advance(blast1_t, 2*digits-3);
    bret = bit::shift_left(bfirst1_t, blast1_t, 1);
    bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, 1);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2*digits+3);
    std::advance(bool_last1_t, 3*digits-3);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2*digits+3);
    std::advance(blast1_t, 3*digits-3);
    bret = bit::shift_left(bfirst1_t, blast1_t, digits-6);
    bool_ret = bit::word_shift_left(bool_first1_t, bool_last1_t, digits-6);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}


TEMPLATE_PRODUCT_TEST_CASE("Shift: right_shift", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 200;
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

    auto bret = bit::shift_right(bfirst1_t, blast1_t, 5);
    auto bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, 5);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
    bret = bit::shift_right(bfirst1_t, blast1_t, 10*digits + 5);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, 10*digits + 5);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    std::advance(bfirst1_t, digits+1);
    std::advance(bool_first1_t, digits+1);
    bret = bit::shift_right(bfirst1_t, blast1_t, digits+7);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, digits+7);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (4)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (4)*digits-digits/2);
    bret = bit::shift_right(bfirst1_t, blast1_t, digits);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, digits);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2*digits+2);
    std::advance(bool_last1_t, 3*digits-2);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2*digits+2);
    std::advance(blast1_t, 3*digits-2);
    bret = bit::shift_right(bfirst1_t, blast1_t, digits*3);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, digits*3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Shift: right_shift- single word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 200;
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

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 1);
    std::advance(bool_last1_t, digits-1);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 1);
    std::advance(blast1_t, digits-1);
    auto bret = bit::shift_right(bfirst1_t, blast1_t, 3);
    auto bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, 3);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
    
    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, digits+3);
    std::advance(bool_last1_t, 2*digits-3);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, digits+3);
    std::advance(blast1_t, 2*digits-3);
    bret = bit::shift_right(bfirst1_t, blast1_t, 1);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, 1);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2*digits+3);
    std::advance(bool_last1_t, 3*digits-3);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2*digits+3);
    std::advance(blast1_t, 3*digits-3);
    bret = bit::shift_right(bfirst1_t, blast1_t, digits-6);
    bool_ret = bit::word_shift_right(bool_first1_t, bool_last1_t, digits-6);
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::distance(bfirst1, bret) == std::distance(bool_first1, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SHIFT_TESTS_HPP_INCLUDED
// ========================================================================== //
