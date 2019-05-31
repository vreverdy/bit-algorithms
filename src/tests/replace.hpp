// ========================== REPLACE TESTS ============================= //
// Project:         The Experimental Bit Algorithms Library
// Name:            replace.hpp
// Description:     Tests for replace function overloads for bits 
// Creator:         Vincent Reverdy
// Contributor(s):  Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _REPLACE_TESTS_HPP_INCLUDED
#define _REPLACE_TESTS_HPP_INCLUDED
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



// --------------------------- Replace Tests ---------------------------- //

TEMPLATE_TEST_CASE("replace: handles single word cases", "[replace]",
  unsigned short/*, unsigned int, unsigned long, unsigned long long*/) {

  TestType t = 0;
  TestType all_ones = bit::_all_ones();

  std::cout << "l38 test..." << std::endl;

  bit::bit_iterator<TestType*> beg(&t, 0);
  bit::bit_iterator<TestType*> end(&t + 1, 0);
  bit::replace(beg, end, bit::bit0, bit::bit1);
  REQUIRE(t == all_ones);

  bit::replace(beg, end, bit::bit1, bit::bit0);
  REQUIRE(t == 0);

  bit::bit_iterator<TestType*> beg_plus_four(&t, 4); 
  bit::replace(beg, beg_plus_four, bit::bit0, bit::bit1); 
  REQUIRE(t == 15);

  t = 0;
  bit::replace(beg_plus_four, end, bit::bit0, bit::bit1);
  REQUIRE(t == bit::_shift_towards_msb(all_ones, 4)); 

  t = static_cast<TestType>(-1);
  bit::replace(beg_plus_four, end, bit::bit1, bit::bit0);
  REQUIRE(t == 15);

  t = 0;
  bit::bit_iterator<TestType*> beg_plus_seven(&t, 7);
  bit::replace(beg_plus_four, beg_plus_seven, bit::bit0, bit::bit1);
  REQUIRE(t == 112);

  t = static_cast<TestType>(-1);
  bit::replace(beg_plus_four, beg_plus_seven, bit::bit1, bit::bit0);
  REQUIRE(t == static_cast<TestType>(all_ones ^ 112));
}

TEMPLATE_PRODUCT_TEST_CASE("replace: handles multi word cases", 
                           "[template][product]", 
                           (std::vector, std::list, std::forward_list), 
                           (unsigned short, unsigned int, unsigned long)) {
    using container_type = TestType;
    using cont_iter_type = typename container_type::iterator;
    using word_type = typename container_type::value_type;

    constexpr word_type all_ones = bit::_all_ones();

    container_type cont = {0, 0, 0};

    bit_iterator first(cont.begin());
    bit_iterator second(std::next(cont.begin()));
    bit_iterator third(std::next(cont.begin(), 2));
    bit_iterator last(cont.end());

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << "about to replace" << std::endl;

    bit::replace(first, last, bit::bit0, bit::bit1);

    std::cout << "finished replacement" << std::endl;

    REQUIRE(cont.front() == all_ones);
}

// -------------------------------------------------------------------------- //



// ========================================================================== //
#endif // _REPLACE_TESTS_HPP_INCLUDED
// ========================================================================== //
