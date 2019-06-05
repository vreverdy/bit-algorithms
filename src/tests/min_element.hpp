// ========================== MAX ELEMENT TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            min_element.hpp
// Description:     Tests for min_element function overloads for bits 
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _MIN_ELEMENT_TESTS_HPP_INCLUDED
#define _MIN_ELEMENT_TESTS_HPP_INCLUDED
// ========================================================================== //



// =============================== PREAMBLE ================================= //
// C++ standard library
#include <iostream>
// Project sources
#include "test_root.cc"
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
// ========================================================================== //



// --------------------------- Min Element Tests ---------------------------- //

TEMPLATE_TEST_CASE("min_element: handles single word cases", "[min_element]",
    unsigned short, unsigned int, unsigned long, unsigned long long) {

    constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;
    constexpr TestType all_ones = bit::_all_ones(); 
    using bit_iterator_t = typename bit::bit_iterator<TestType*>;

    TestType t = all_ones;
    bit_iterator_t beg(&t);
    bit_iterator_t end(&t + 1);

    bit_iterator_t it = bit::min_element(beg, end);
    REQUIRE(*it == bit::bit1);
    REQUIRE(it == beg);

    t = 0;
    it = bit::min_element(beg, end);
    REQUIRE(*it == bit::bit0);
    REQUIRE(it == beg);

    t = ~128;
    it = bit::min_element(beg, end);
    REQUIRE(it.position() == 7);
}

TEMPLATE_PRODUCT_TEST_CASE("min_element: handles multi word cases", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long)) {
    using container_type = TestType;
    using cont_iter_type = typename container_type::iterator;
    using bit_iter_type = typename bit::bit_iterator<cont_iter_type>;
    using word_type = typename TestType::value_type;

    word_type all_ones = bit::_all_ones();
    std::size_t num_digits = bit::binary_digits<word_type>::value;

    container_type cont = {all_ones, static_cast<word_type>(~128), all_ones};

    bit_iter_type beg(cont.begin());
    bit_iter_type end(cont.end());

    bit_iter_type it = bit::min_element(beg, end);
    REQUIRE(it.position() == 7);
    REQUIRE(*std::next(it) == bit::bit1);
    REQUIRE(it.base() == std::next(cont.begin()));

    cont = {0, 0, 0};
    it = bit::min_element(beg, end);
    REQUIRE(it.position() == 0);
    REQUIRE(it.base() == beg.base());

    cont = {all_ones, all_ones, bit::_shift_towards_lsb(all_ones, 1)};
    it = bit::min_element(beg, end);
    REQUIRE(it.position() == num_digits - 1);
    REQUIRE(it.base() == std::next(beg.base(), 2));

    bit_iter_type mid_last(std::next(cont.begin(), 2), num_digits / 2);
    it = bit::min_element(mid_last, end);
    REQUIRE(it.position() == num_digits - 1);

    cont = {all_ones, all_ones, 0};
    bit_iter_type mid_second(std::next(cont.begin()), num_digits / 2);
    it = bit::min_element(mid_second, end);
    REQUIRE(it.position() == 0);
    REQUIRE(std::next(mid_second.base()) == it.base());

    cont = {all_ones, all_ones, all_ones};
    it = bit::min_element(mid_second, end);
    REQUIRE(it.position() == num_digits / 2);

    cont = {bit::_shift_towards_msb(all_ones, 7), all_ones, all_ones};
    bit_iter_type pos_9_first(cont.begin(), 9);
    it = bit::min_element(pos_9_first, end);
    REQUIRE(it.position() == 9);
}

// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _MIN_ELEMENT_TESTS_HPP_INCLUDED
// ========================================================================== //
