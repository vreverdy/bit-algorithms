#ifndef BA_FILL
#define BA_FILL

#include "alg_utils.hpp"

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

}

#endif
