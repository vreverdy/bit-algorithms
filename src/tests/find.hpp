// ============================== FIND TESTS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            find.hpp
// Description:     Tests for find, find_if, find_if_not algorithms 
//                  for bit iterators
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FIND_TESTS_HPP_INCLUDED
#define _FIND_TESTS_HPP_INCLUDED
// ========================================================================== //


// =============================== PREAMBLE ================================= //
// C++ standard library
// Project sources
#include "test_root.cc"
#include "bit.hpp"
#include <vector>
// Third-party libraries
// Miscellaneous
// ========================================================================== //

TEMPLATE_TEST_CASE("find: is correct for trivial single word cases", "[find]", 
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    TestType t = 7;
    bit::bit_iterator<TestType*> first(&t, 0);
    bit::bit_iterator<TestType*> last(&t + 1, 0);

    auto pos = bit::find(first, last, bit::bit0); 
    auto pos_expected = std::find(first, last, bit::bit0);

    REQUIRE(pos == pos_expected);
}

TEMPLATE_TEST_CASE("find: finding first set bit works for vectors", "[find]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_t = std::vector<TestType>;
    using vec_iter_t = typename vec_t::iterator;
    
    vec_t vec = {0, 0, 8, 0};

    bit::bit_iterator<vec_iter_t> first(vec.begin());
    bit::bit_iterator<vec_iter_t> last(vec.end());

    auto pos = bit::find(first, last, bit::bit1);
    auto pos_expected = std::find(first, last, bit::bit1);

    REQUIRE(pos == pos_expected);

    vec_t vec2 = {static_cast<TestType>(-1), static_cast<TestType>(-1), 3, 0};
    bit::bit_iterator<vec_iter_t> first2(vec2.begin());
    bit::bit_iterator<vec_iter_t> last2(vec2.end());

    pos = bit::find(first2, last2, bit::bit0);
    pos_expected = std::find(first2, last2, bit::bit0);

    REQUIRE(pos == pos_expected);
}

TEMPLATE_TEST_CASE("find: is ok for virtual/misaligned words", "[find]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    using vec_t = std::vector<TestType>;
    using vec_iter_t = typename vec_t::iterator;

    vec_t vec = {7, 0, 8};

    bit::bit_iterator<vec_iter_t> first(vec.begin(), 5);
    bit::bit_iterator<vec_iter_t> last(vec.begin() + 2, 2);

    REQUIRE(bit::find(first, last, bit::bit1) ==
            std::find(first, last, bit::bit1));
}

TEMPLATE_PRODUCT_TEST_CASE("Find: multi-word", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 1 << 5;
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
    
    auto bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    auto bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    std::advance(bfirst1_t, 3);
    std::advance(bool_first1_t, 3);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    std::advance(bfirst1_t, digits + 1);
    std::advance(bool_first1_t, digits + 1);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_last1_t = bool_first1;
    std::advance(bool_last1_t, (container_size-1)*digits-digits/2);
    blast1_t = bfirst1;
    std::advance(blast1_t, (container_size-1)*digits-digits/2);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_first1_t = bool_first1;
    bool_last1_t = bool_first1;
    std::advance(bool_first1_t, 2);
    std::advance(bool_last1_t, digits-2);
    bfirst1_t = bfirst1;
    blast1_t = bfirst1;
    std::advance(bfirst1_t, 2);
    std::advance(blast1_t, digits-2);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Find: multi-word all 0", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 1 << 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = container_type(container_size, 0); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;
    
    auto bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    auto bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_last1_t = std::next(bool_first1, digits);
    blast1_t = std::next(bfirst1, digits);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_last1_t = std::next(bool_first1, digits + 1);
    blast1_t = std::next(bfirst1, digits + 1);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
}

TEMPLATE_PRODUCT_TEST_CASE("Find: multi-word all 1", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned char, unsigned short, 
                            unsigned int, unsigned long)) {

    using container_type = TestType;
    using num_type = typename container_type::value_type;
    auto container_size = 1 << 5;
    auto digits = bit::binary_digits<num_type>::value;
    container_type bitcont1 = container_type(container_size, static_cast<num_type>(-1)); 
    auto boolcont1 = bitcont_to_boolcont(bitcont1);
    auto bfirst1 = bit::bit_iterator<decltype(std::begin(bitcont1))>(std::begin(bitcont1));
    auto blast1 = bit::bit_iterator<decltype(std::end(bitcont1))>(std::end(bitcont1));
    auto bool_first1 = std::begin(boolcont1);
    auto bool_last1 = std::end(boolcont1);
    auto bool_first1_t = bool_first1;
    auto bfirst1_t = bfirst1;
    auto bool_last1_t = bool_last1;
    auto blast1_t = blast1;
    
    auto bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    auto bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_last1_t = std::next(bool_first1, digits);
    blast1_t = std::next(bfirst1, digits);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));

    bool_last1_t = std::next(bool_first1, digits + 1);
    blast1_t = std::next(bfirst1, digits + 1);
    bret = bit::find(bfirst1_t, blast1_t, bit::bit1);
    bool_ret = std::find(bool_first1_t, bool_last1_t, true);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
    bret = bit::find(bfirst1_t, blast1_t, bit::bit0);
    bool_ret = std::find(bool_first1_t, bool_last1_t, false);
    REQUIRE(std::distance(bfirst1_t, bret) == std::distance(bool_first1_t, bool_ret));
}


#endif
