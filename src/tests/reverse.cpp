// ============================= REVERSE TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            reverse.hpp
// Description:     Tests for reverse algorithms 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _REVERSE_TESTS_HPP_INCLUDED
#define _REVERSE_TESTS_HPP_INCLUDED
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



// ----------------------------- Reverse Tests ------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("Reverse: single_word", 
                           "[template][product]", 
                           (std::vector, std::list), 
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

    bit::reverse(
        bfirst, 
        std::next(bfirst, 3)
    );
    std::reverse(
        bool_first, 
        std::next(bool_first, 3)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::reverse(
        bfirst, 
        std::next(bfirst, digits)
    );
    std::reverse(
        bool_first, 
        std::next(bool_first, digits)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::reverse(
        std::next(bfirst, 2), 
        std::next(bfirst, digits)
    );
    std::reverse(
        std::next(bool_first, 2), 
        std::next(bool_first, digits)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    bit::reverse(
        std::next(bfirst, 2), 
        std::next(bfirst, digits - 3)
    );
    std::reverse(
        std::next(bool_first, 2), 
        std::next(bool_first, digits - 3)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
}

TEMPLATE_PRODUCT_TEST_CASE("Reverse: STD_multiple_word_main", 
                           "[template][product]", 
                           (std::vector, std::list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont = make_random_container<container_type>
                                     (container_size); 
    auto boolcont = bitcont_to_boolcont(bitcont);
    auto bfirst = bit::bit_iterator<decltype(std::begin(bitcont))>(std::begin(bitcont));
    auto blast = bit::bit_iterator<decltype(std::end(bitcont))>(std::end(bitcont));
    auto bool_first = std::begin(boolcont);
    auto bool_last = std::end(boolcont);

    bit::reverse(
        bfirst,
        blast
    );
    std::reverse(
        bool_first,
        bool_last
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    // f.pos() <= nf.pos() and first is aligned
    bit::reverse(
        std::next(bfirst, 0),
        std::next(bfirst, (container_size-4)*digits-3)
    );
    std::reverse(
        std::next(bool_first, 0), 
        std::next(bool_first, (container_size-4)*digits-3)
     );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    // f.pos() == nf.pos() and last is aligned
    bit::reverse(
        std::next(bfirst, 6),
        std::next(bfirst, (container_size-4)*digits + 6)
    );
    std::reverse(
        std::next(bool_first, 6), 
        std::next(bool_first, (container_size-4)*digits + 6)
    );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));

    // f.pos() <= nf.pos() and first is aligned
    bit::reverse(
        std::next(bfirst, 0),
        std::next(bfirst, (container_size-4)*digits-3)
    );
    std::reverse(
        std::next(bool_first, 0), 
        std::next(bool_first, (container_size-4)*digits-3)
     );
    REQUIRE(std::equal(bool_first, bool_last, bfirst, blast, comparator));
}

// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _REVERSE_TESTS_HPP_INCLUDED
// ========================================================================== //
