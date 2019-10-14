// ============================= MISMATCH TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            mismatch.hpp
// Description:     tests for mismatch algorithm bit iterator overloads 
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
//                  Bryce Kille [2019] 
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _MISMATCH_TESTS_HPP_INCLUDED
#define _MISMATCH_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// ----------------------------- Mismatch Tests ----------------------------- //
TEMPLATE_PRODUCT_TEST_CASE("mismatch: multiple_word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 6;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type>
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

    auto bret = bit::mismatch(
            bfirst1, 
            blast1,
            bfirst2
    );
    auto bool_ret = std::mismatch(
            bool_first1, 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            blast1,
            bfirst2
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            bool_last1, 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            bfirst2
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            bfirst1, 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::mismatch(
            bool_first1, 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            blast1,
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            bool_last1, 
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            std::next(bfirst1, (container_size - 1)*digits - (digits/3)),
            std::next(bfirst2, digits - 1)
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            std::next(bool_first1, (container_size - 1)*digits - (digits/3)),
            std::next(bool_first2, digits - 1)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));
}

TEMPLATE_PRODUCT_TEST_CASE("mismatch: single_word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long, unsigned long long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 3;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = make_random_container<container_type>
                                     (container_size); //, 0, 0);
    container_type bitcont2 = make_random_container<container_type>
                                     (container_size); //, std::numeric_limits<num_type>::max(),
                                      //std::numeric_limits<num_type>::max());
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto boolcont2 = bitcont_to_boolcont(bitcont2);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto bfirst2 = bit::bit_iterator<decltype(std::begin(bitcont2))>(std::begin(bitcont2));
    auto blast2 = bit::bit_iterator<decltype(std::end(bitcont2))>(std::end(bitcont2));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_first2 = std::begin(boolcont2);
    auto bool_last2 = std::end(boolcont2);

    auto bret = bit::mismatch(
            bfirst1, 
            std::next(bfirst1, digits),
            bfirst2
    );
    auto bool_ret = std::mismatch(
            bool_first1, 
            std::next(bool_first1, digits),
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            std::next(bfirst1, 9 + digits), 
            bfirst2
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            std::next(bool_first1, 9 + digits), 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            std::next(bfirst1, 5 + digits), 
            bfirst2
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            std::next(bool_first1, 5 + digits), 
            bool_first2
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));

    bret = bit::mismatch(
            std::next(bfirst1, 9), 
            std::next(bfirst1, 5 + digits), 
            std::next(bfirst2, 3)
    );
    bool_ret = std::mismatch(
            std::next(bool_first1, 9), 
            std::next(bool_first1, 5 + digits), 
            std::next(bool_first2, 3)
    );
    REQUIRE(std::equal(bool_first2, bool_last2, bfirst2, blast2, comparator));
    REQUIRE(std::distance(bfirst1, bret.first) == std::distance(bool_first1, bool_ret.first));
    REQUIRE(std::distance(bfirst2, bret.second) == std::distance(bool_first2, bool_ret.second));
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _MISMATCH_TESTS_HPP_INCLUDED
// ========================================================================== //

