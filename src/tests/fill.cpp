// ============================== FILL TESTS ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            fill.hpp
// Description:     Tests for fill algorithms 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _FILL_TESTS_HPP_INCLUDED
#define _FILL_TESTS_HPP_INCLUDED
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



// ------------------------------ Fill Tests -------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("fill: single_word", 
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

    bit::fill(
            bfirst, 
            std::next(bfirst, digits), 
            bit::bit1
    );
    std::fill(
            bool_first, 
            std::next(bool_first, digits), 
            1
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::fill(
            bfirst, 
            std::next(bfirst, 3), 
            bit::bit0
    );
    std::fill(
            bool_first, 
            std::next(bool_first, 3), 
            0
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::fill(
            std::next(bfirst, 3), 
            std::next(bfirst, digits),
            bit::bit1
    );
    std::fill(
            std::next(bool_first, 3), 
            std::next(bool_first, digits),
            1
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::fill(
            std::next(bfirst, 3 + digits*(container_size - 1)), 
            blast,
            bit::bit1
    );
    std::fill(
            std::next(bool_first, 3 + digits*(container_size - 1)), 
            bool_last,
            1
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

}

TEMPLATE_PRODUCT_TEST_CASE("fill: multiple_word_subcases", 
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

    bit::fill(
            bfirst, 
            std::next(bfirst, container_size*digits), 
            bit::bit1
    );
    std::fill(
            bool_first, 
            std::next(bool_first, container_size*digits), 
            1
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::fill(
            bfirst, 
            std::next(bfirst, digits + 3), 
            bit::bit0
    );
    std::fill(
            bool_first, 
            std::next(bool_first, digits + 3), 
            0
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::fill(
            std::next(bfirst, 3), 
            std::next(bfirst, container_size*digits - 6),
            bit::bit1
    );
    std::fill(
            std::next(bool_first, 3), 
            std::next(bool_first, container_size*digits - 6),
            1
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _FILL_TESTS_HPP_INCLUDED
// ========================================================================== //
