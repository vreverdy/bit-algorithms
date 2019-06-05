// ========================== MAX ELEMENT TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            max_element.hpp
// Description:     Tests for max_element function overloads for bits 
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _MAX_ELEMENT_TESTS_HPP_INCLUDED
#define _MAX_ELEMENT_TESTS_HPP_INCLUDED
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



// --------------------------- Max Element Tests ---------------------------- //

TEMPLATE_TEST_CASE("max_element: handles single word cases", "[max_element]",
  unsigned short, unsigned int, unsigned long, unsigned long long) {

  TestType t = 256;

  bit::bit_iterator<TestType*> beg(&t, 0);
  bit::bit_iterator<TestType*> end(&t + 1, 0);

  bit::bit_iterator<TestType*> max_elem = bit::max_element(beg, end);

  REQUIRE(*max_elem == bit::bit1);
  REQUIRE(max_elem.position() == 8);
  t = 0;
  max_elem = bit::max_element(beg, end);

  REQUIRE(*max_elem == bit::bit0);
  REQUIRE(max_elem.position() == 0);

  t = 4;
  bit::bit_iterator<TestType*> beg_plus_2(&t, 2);

  max_elem = bit::max_element(beg, beg_plus_2);

  REQUIRE(*max_elem == bit::bit0);
  REQUIRE(max_elem.position() == 0);

  t = -1;
  max_elem = bit::max_element(beg, end);
  REQUIRE(*max_elem == bit::bit1);
  REQUIRE(max_elem.position() == 0);

  constexpr std::size_t num_digits = bit::binary_digits<TestType>::value;

  t = bit::_shift_towards_msb(static_cast<TestType>(-1), num_digits / 2); 

  max_elem = bit::max_element(beg_plus_2, end);
  REQUIRE(*max_elem == bit::bit1);
  REQUIRE(max_elem.position() == num_digits / 2);

  t = 3; 
  max_elem = bit::max_element(beg, beg_plus_2);
  REQUIRE(*max_elem == bit::bit1);
  REQUIRE(max_elem.position() == 0);
}

TEMPLATE_PRODUCT_TEST_CASE("max_element: handles multi word cases", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long)) {
    using container_type = TestType;
    using cont_iter_type = typename container_type::iterator;

    container_type cont = {8, 16, 32};

    bit::bit_iterator<cont_iter_type> beg(cont.begin());
    bit::bit_iterator<cont_iter_type> end(cont.end());

    auto it = bit::max_element(beg, end);
    REQUIRE(*it == bit::bit1);
    REQUIRE(it.position() == 3);

    constexpr std::size_t num_digits = 
        bit::binary_digits<typename TestType::value_type>::value;

    bit::bit_iterator<cont_iter_type> half_through_first(cont.begin(), 
        num_digits / 2);

    it = bit::max_element(half_through_first, end);

    REQUIRE(it.position() == 4);

    bit::bit_iterator<cont_iter_type> begin_second(std::next(cont.begin()));

    it = bit::max_element(half_through_first, begin_second);
    REQUIRE(*it == bit::bit0);
    REQUIRE(it.position() == half_through_first.position()); 

    cont.front() = -1;

    it = bit::max_element(beg, begin_second);
    REQUIRE(*it == bit::bit1);
    REQUIRE(it.position() == 0); 
}

// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _MAX_ELEMENT_TESTS_HPP_INCLUDED
// ========================================================================== //
