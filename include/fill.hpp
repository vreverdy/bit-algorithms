#include <iostream>
#pragma once

namespace bit {

template <class BitIter> 
bool in_same_word(BitIter first, BitIter last) {
  return first.base() == last.base();
}

template <class BitIter>
void set_in_range(BitIter begin, BitIter end, typename BitIter::iterator_type base, bit::bit_value bv) {
  constexpr std::size_t num_digits = bit::binary_digits<typename BitIter::word_type>::value;

  using word_type = typename BitIter::word_type;

  std::size_t low = begin.position();
  std::size_t high = end.position();

  word_type mask = static_cast<word_type>(1) << (high - low);
  mask <<= 1;
  mask--;
  mask <<= low;

  if (bv == bit::bit1) {
    *base |= mask;
  } else {
    word_type tmp = *base & mask;
    *base ^= tmp;
  }
} 

template <class WrappedIter>
void fill(bit_iterator<WrappedIter> first, bit_iterator<WrappedIter> last, bit::bit_value bv) {
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
      set_in_range(cur, last - 1, cur.base(), bv);
      cur = last;
    } 
  }
}


}
