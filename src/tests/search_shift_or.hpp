// ============================== SEARCH TESTS ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: search_shift_or.hpp
// Description: tests for search algorithm bit iterator overloads 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Bryce Kille
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SEARCH_SHIFT_OR_TESTS_HPP_INCLUDED
#define _SEARCH_SHIFT_OR_TESTS_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ----------------------------- SEARCH Tests ------------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: single_word pattern or smaller", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    auto bret = bit::search_shift_or(
            bfirst_txt, 
            blast_txt, 
            std::next(bfirst_txt, 4*digits+2),
            std::next(bfirst_txt, 5*digits-1)
    );
    auto bool_ret = std::search(
            bool_first_txt, 
            bool_last_txt, 
            std::next(bool_first_txt, 4*digits+2),
            std::next(bool_first_txt, 5*digits-1)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 4*digits + 1),
        std::next(bfirst_txt, 5*digits + 1)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 4*digits + 1),
        std::next(bool_first_txt, 5*digits + 1)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 4*digits),
        std::next(bfirst_txt, 5*digits - 3)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 4*digits),
        std::next(bool_first_txt, 5*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 4*digits + 3),
        std::next(bfirst_txt, 5*digits)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 4*digits + 3),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 4*digits + 3),
        std::next(bfirst_txt, 5*digits - 3)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 4*digits + 3),
        std::next(bool_first_txt, 5*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: multiple_word pattern | text aligned", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    // Aligned
    auto bret = bit::search_shift_or(
            bfirst_txt, 
            blast_txt, 
            std::next(bfirst_txt, 3*digits),
            std::next(bfirst_txt, 5*digits)
    );
    auto bool_ret = std::search(
            bool_first_txt, 
            bool_last_txt, 
            std::next(bool_first_txt, 3*digits),
            std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    //Text aligned | Pattern unaligned
    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 3*digits),
        std::next(bfirst_txt, 5*digits - 3)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 3*digits),
        std::next(bool_first_txt, 5*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 3*digits + 3),
        std::next(bfirst_txt, 5*digits)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 3*digits + 3),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        bfirst_txt, 
        blast_txt, 
        std::next(bfirst_txt, 3*digits + 3),
        std::next(bfirst_txt, 5*digits - 3)
    );
    bool_ret = std::search(
        bool_first_txt, 
        bool_last_txt, 
        std::next(bool_first_txt, 3*digits + 3),
        std::next(bool_first_txt, 5*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: multiple_word pattern | pattern aligned", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    //Text unaligned | Pattern aligned
    auto bret = bit::search_shift_or(
        bfirst_txt, 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 3*digits),
        std::next(bfirst_txt, 5*digits)
    );
    auto bool_ret = std::search(
        bool_first_txt, 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 3*digits),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        blast_txt, 
        std::next(bfirst_txt, 3*digits),
        std::next(bfirst_txt, 5*digits)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        bool_last_txt, 
        std::next(bool_first_txt, 3*digits),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 3*digits),
        std::next(bfirst_txt, 5*digits)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 3*digits),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: multiple_word pattern | unaligned", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    auto bret = bit::search_shift_or(
        bfirst_txt, 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 3*digits + 2),
        std::next(bfirst_txt, 5*digits)
    );
    auto bool_ret = std::search(
        bool_first_txt, 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 3*digits + 2),
        std::next(bool_first_txt, 5*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        blast_txt, 
        std::next(bfirst_txt, 3*digits + 2),
        std::next(bfirst_txt, 6*digits - 3)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        bool_last_txt, 
        std::next(bool_first_txt, 3*digits + 2),
        std::next(bool_first_txt, 6*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 3*digits + 4),
        std::next(bfirst_txt, 5*digits - 6)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 3*digits + 4),
        std::next(bool_first_txt, 5*digits - 6)
    );

    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: many_word pattern | unaligned", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 100;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    auto bret = bit::search_shift_or(
        bfirst_txt, 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 30*digits + 2),
        std::next(bfirst_txt, 40*digits)
    );
    auto bool_ret = std::search(
        bool_first_txt, 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 30*digits + 2),
        std::next(bool_first_txt, 40*digits)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        blast_txt, 
        std::next(bfirst_txt, 30*digits + 2),
        std::next(bfirst_txt, 40*digits - 3)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        bool_last_txt, 
        std::next(bool_first_txt, 30*digits + 2),
        std::next(bool_first_txt, 40*digits - 3)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
        std::next(bfirst_txt, 3), 
        std::next(bfirst_txt, container_size*digits - 3), 
        std::next(bfirst_txt, 30*digits + 4),
        std::next(bfirst_txt, 40*digits - 6)
    );
    bool_ret = std::search(
        std::next(bool_first_txt, 3), 
        std::next(bool_first_txt, container_size*digits - 3), 
        std::next(bool_first_txt, 30*digits + 4),
        std::next(bool_first_txt, 50*digits - 6)
    );

    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("search_shift_or: single_word pattern or smaller at ends", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 10;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bit_txt = make_random_container<container_type>
                                     (container_size); 
    auto bool_txt = bitcont_to_boolcont(bit_txt);
    auto bfirst_txt = bit::bit_iterator<decltype(std::begin(bit_txt))>(std::begin(bit_txt));
    auto blast_txt = bit::bit_iterator<decltype(std::end(bit_txt))>(std::end(bit_txt));
    auto bool_first_txt = std::begin(bool_txt);
    auto bool_last_txt = std::end(bool_txt);

    auto bret = bit::search_shift_or(
            bfirst_txt, 
            blast_txt, 
            std::next(bfirst_txt, 10*digits-5),
            std::next(bfirst_txt, 10*digits-4)
    );
    auto bool_ret = std::search(
            bool_first_txt, 
            bool_last_txt, 
            std::next(bool_first_txt, 10*digits-5),
            std::next(bool_first_txt, 10*digits-4)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
            bfirst_txt, 
            blast_txt, 
            std::next(bfirst_txt, 0),
            std::next(bfirst_txt, 4)
    );
    bool_ret = std::search(
            bool_first_txt, 
            bool_last_txt, 
            std::next(bool_first_txt, 0),
            std::next(bool_first_txt, 4)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
            bfirst_txt + 2, 
            blast_txt - 2, 
            std::next(bfirst_txt, 0),
            std::next(bfirst_txt, 4)
    );
    bool_ret = std::search(
            bool_first_txt + 2, 
            bool_last_txt - 2, 
            std::next(bool_first_txt, 0),
            std::next(bool_first_txt, 4)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
            bfirst_txt + 2, 
            blast_txt - 2, 
            std::next(bfirst_txt, 2),
            std::next(bfirst_txt, 4)
    );
    bool_ret = std::search(
            bool_first_txt + 2, 
            bool_last_txt - 2, 
            std::next(bool_first_txt, 2),
            std::next(bool_first_txt, 4)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));

    bret = bit::search_shift_or(
            bfirst_txt + 2, 
            bfirst_txt + 6, 
            std::next(bfirst_txt, 2),
            std::next(bfirst_txt, 6)
    );
    bool_ret = std::search(
            bool_first_txt + 2, 
            bool_first_txt + 6, 
            std::next(bool_first_txt, 2),
            std::next(bool_first_txt, 6)
    );
    REQUIRE(std::equal(bool_first_txt, bool_last_txt, bfirst_txt, blast_txt, comparator));
    REQUIRE(std::distance(bfirst_txt, bret) == std::distance(bool_first_txt, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _SEARCH_SHIFT_OR_TESTS_HPP_INCLUDED
// ========================================================================== //
