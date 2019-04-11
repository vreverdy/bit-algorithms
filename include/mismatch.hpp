#pragma once

#include <iostream>

namespace bit {

template <class WrappedIter1, class WrappedIter2>
std::pair<bit_iterator<WrappedIter1>, bit_iterator<WrappedIter2>> mismatch(
   bit_iterator<WrappedIter1> in1_beg, bit_iterator<WrappedIter1> in1_end,
   bit_iterator<WrappedIter2> in2_beg, bit_iterator<WrappedIter2> in2_end
) {

  using word1_type = typename bit_iterator<WrappedIter1>::word_type;
  using word2_type = typename bit_iterator<WrappedIter2>::word_type;

  constexpr std::size_t num_digits1 = bit::binary_digits<word1_type>::value;
  constexpr std::size_t num_digits2 = bit::binary_digits<word2_type>::value;

  using word_type = typename std::conditional<num_digits1 < num_digits2, word1_type, word2_type>::type;

  bit_iterator<WrappedIter1> in1 = in1_beg;
  auto in2 = in2_beg;

  auto xd = bit::fetch_word<decltype(in1), word_type>(in1);

  return std::make_pair(in1, in2);
}  

}
