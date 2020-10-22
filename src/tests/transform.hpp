// ============================ TRANSFORM TESTS ============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            transform.hpp
// Description:     Tests for transform
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _TRANSFORM_TESTS_HPP_INCLUDED
#define _TRANSFORM_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ----------------------------- transform Tests ---------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("transform_word: simple bitwise instruction", 
                           "[template][product]", 
                           (std::vector), 
                           (unsigned char)) {

    using container_type = TestType;
    using word_type = typename container_type::value_type;
    auto container_size = 9;
    auto digits = bit::binary_digits<word_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size);
    container_type bitcont2 = make_random_container<container_type>
                                     (container_size);
    container_type bitcont_d = make_random_container<container_type>
                                     (container_size);
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto boolcont_d = bitcont_to_boolcont(bitcont_d);

    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bfirst_d = bit::bit_iterator<decltype(std::begin(bitcont_d))>(std::begin(bitcont_d));
    auto blast_d = bit::bit_iterator<decltype(std::end(bitcont_d))>(std::end(bitcont_d));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);
    auto bool_first_d = std::begin(boolcont_d);
    auto bool_last_d = std::end(boolcont_d);

    auto and_f = [](const auto left, const auto right) {
        return left & right;
    };

    auto bret = bit::transform(
            bfirst1, 
            blast1,
            bfirst2,
            bfirst_d,
            and_f
    );
    auto bool_ret = std::transform(
            bool_first1, 
            bool_last1, 
            bool_first2,
            bool_first_d,
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1, 2),
            std::next(bfirst1, digits),
            std::next(bfirst2, digits),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1, 2),
            std::next(bool_first1, digits), 
            std::next(bool_first2, digits),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1),
            std::next(bfirst1, digits),
            std::next(bfirst2, digits),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1),
            std::next(bool_first1, digits), 
            std::next(bool_first2, digits),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1),
            std::next(bfirst1, digits - 2),
            std::next(bfirst2, digits),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1),
            std::next(bool_first1, digits - 2), 
            std::next(bool_first2, digits),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1, 2),
            std::next(bfirst1, 5*digits),
            std::next(bfirst2, digits),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1, 2),
            std::next(bool_first1, 5*digits), 
            std::next(bool_first2, digits),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1, 2),
            std::next(bfirst1, 5*digits),
            std::next(bfirst2, digits - 1),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1, 2),
            std::next(bool_first1, 5*digits), 
            std::next(bool_first2, digits - 1),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));

    bret = bit::transform(
            std::next(bfirst1, 2),
            std::next(bfirst1, 5*digits - 1),
            std::next(bfirst2, digits - 1),
            std::next(bfirst_d, digits - 1),
            and_f
    );
    bool_ret = std::transform(
            std::next(bool_first1, 2),
            std::next(bool_first1, 5*digits - 1), 
            std::next(bool_first2, digits - 1),
            std::next(bool_first_d, digits - 1),
            and_f
    );
    REQUIRE(std::equal(bool_first1, bool_last1, bfirst1, blast1, comparator));
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::equal(bool_first_d, bool_last_d, bfirst_d, blast_d, comparator));
    REQUIRE(std::distance(bfirst_d, bret) == std::distance(bool_first_d, bool_ret));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _TRANSFORM_TESTS_HPP_INCLUDED
// ========================================================================== //
