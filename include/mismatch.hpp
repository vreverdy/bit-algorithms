#pragma once

#include <iostream>

namespace bit {

  template <class WrappedIter1, class WrappedIter2>
  std::pair<bit_iterator<WrappedIter1>, bit_iterator<WrappedIter2>> mismatch(
     bit_iterator<WrappedIter1> in1_beg, bit_iterator<WrappedIter1> in1_end,
     bit_iterator<WrappedIter2> in2_beg, bit_iterator<WrappedIter2> in2_end
  ) {

    auto in1 = in1_beg;
    auto in2 = in2_beg;

    while (*in1 == *in2 && in1 != in1_end && in2 != in2_end) {
      ++in1;
      ++in2;
    }

    return std::make_pair(in1, in2);
  }  

}
