// =============================== MISMATCH ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: mismatch.hpp
// Description: bit_iterator overloads for std::mismatch 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MISMATCH_HPP
#define _MISMATCH_HPP

// C++ standard library
#include <iostream>
// Project sources
#include "alg_utils.hpp"

namespace bit {

template <class WrappedIter1, class WrappedIter2>
std::pair<bit_iterator<WrappedIter1>, bit_iterator<WrappedIter2>> mismatch(
   bit_iterator<WrappedIter1> in1_beg, bit_iterator<WrappedIter1> in1_end,
   bit_iterator<WrappedIter2> in2_beg, bit_iterator<WrappedIter2> in2_end
) {

  // we'll make reads of the smaller of the two word types. 
  using word1_type = typename bit_iterator<WrappedIter1>::word_type;
  using word2_type = typename bit_iterator<WrappedIter2>::word_type;

  constexpr std::size_t num_digits1 = bit::binary_digits<word1_type>::value;
  constexpr std::size_t num_digits2 = bit::binary_digits<word2_type>::value;

  using word_type = typename std::conditional<
    num_digits1 < num_digits2, word1_type, word2_type>::type;

  bit_iterator<WrappedIter1> in1 = in1_beg;
  bit_iterator<WrappedIter2> in2 = in2_beg;

  while (true) {
    word_type w1 = bit::read_word_raw<bit_iterator<WrappedIter1>, word_type>(in1, in1_end); 
    word_type w2 = bit::read_word_raw<bit_iterator<WrappedIter2>, word_type>(in2, in2_end);

    exit(1);

    if (w1 != w2) {
      // the two words don't match. let's find the position of the mismatched bits
      while (in1 != in1_end && in2 != in2_end && *in1 == *in2) {
        ++in1;
        ++in2;
      }
      break;
    } else {
      // the words match. advance the iterators by one word
      std::advance(in1, bit::binary_digits<word_type>::value);
      std::advance(in2, bit::binary_digits<word_type>::value);
    }
  }

  return std::make_pair(in1, in2);
}  

} // namespace bit

#endif // _MISMATCH_HPP
