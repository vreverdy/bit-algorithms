// ============================ REPLACE TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            replace.hpp
// Description:     Tests for replace
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _REPLACE_TESTS_HPP_INCLUDED
#define _REPLACE_TESTS_HPP_INCLUDED
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



// ---------------------------- REPLACE Tests ----------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("Replace: single_word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 4;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto boolcont = bitcont_to_boolcont(bitcont);
    auto bfirst = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto blast = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto bool_first = std::begin(boolcont);
    auto bool_last = std::end(boolcont);

    bit::replace(
        bfirst, 
        std::next(bfirst, 3), 
        bit::bit0,
        bit::bit1
    );
    std::replace(
        bool_first, 
        std::next(bool_first, 3), 
        false,
        true
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::replace(
        std::next(bfirst, digits - 3), 
        std::next(bfirst, digits + 3), 
        bit::bit0,
        bit::bit1
    );
    std::replace(
        std::next(bool_first, digits - 3), 
        std::next(bool_first, digits + 3), 
        false,
        true
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::replace(
        std::next(bfirst, 3), 
        std::next(bfirst, digits - 4), 
        bit::bit0,
        bit::bit1
    );
    std::replace(
        std::next(bool_first, 3), 
        std::next(bool_first, digits - 4), 
        false,
        true
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
}

TEMPLATE_PRODUCT_TEST_CASE("Replace: multi_word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 8;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto boolcont = bitcont_to_boolcont(bitcont);
    auto bfirst = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto blast = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto bool_first = std::begin(boolcont);
    auto bool_last = std::end(boolcont);

    bit::replace(
        bfirst, 
        std::next(bfirst, 3*digits), 
        bit::bit0,
        bit::bit1
    );
    std::replace(
        bool_first, 
        std::next(bool_first, 3*digits), 
        false,
        true
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::replace(
        std::next(bfirst, digits + 3), 
        std::next(bfirst, 4*digits - 4), 
        bit::bit1,
        bit::bit0
    );
    std::replace(
        std::next(bool_first, digits + 3), 
        std::next(bool_first, 4*digits - 4), 
        true,
        false
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::replace(
        std::next(bfirst, digits - 1), 
        std::next(bfirst, container_size*digits - 1), 
        bit::bit0,
        bit::bit1
    );
    std::replace(
        std::next(bool_first, digits - 1), 
        std::next(bool_first, container_size*digits - 1), 
        false,
        true
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _REPLACE_TESTS_HPP_INCLUDED
// ========================================================================== //
