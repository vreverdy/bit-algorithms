// ================================= FILL =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: fill.hpp
// Description: bit_iterator overloads for std::fill 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FILL_HPP_INCLUDED
#define _FILL_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit_algorithm_details.hpp"
// Third-party libraries

namespace bit {

template <class WrappedIter>
void fill(bit_iterator<WrappedIter> first, bit_iterator<WrappedIter> last, 
    bit::bit_value bv) {
  bit_iterator<WrappedIter> cur = first;

  using word_type = typename bit_iterator<WrappedIter>::word_type;
  constexpr std::size_t num_digits = bit::binary_digits<word_type>::value;

  while (cur != last) {
    bit::range_type rt = bit::get_range_type(cur, last - 1);
    if (rt == bit::range_type::FULL) {
      if (bv == bit::bit1) {
        *(cur.base()) = -1;
      } else {
        *(cur.base()) = 0;
      }
      std::advance(cur, num_digits);
    } else if (rt == bit::range_type::POINT) {
      *cur = bv;
      ++cur;
    } else {
      bit::set_in_range(cur, last - 1, cur.base(), bv);
      cur = last;
    } 
  }
}

// ========================================================================== //
} // namespace bit

#endif // _FILL_HPP_INCLUDED
// ========================================================================== //
