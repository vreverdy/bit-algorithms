// =============================== SAMPLE =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: sample.hpp
// Description: bit_iterator overloads for std::sample
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SAMPLE_HPP_INCLUDED
#define _SAMPLE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
#include <iostream>
#include <algorithm>
#include <vector>
// Project sources
// Third-party libraries

namespace bit {

template <class WrappedIterator, class SampleIterator, class Distance, class URBG>
SampleIterator sample(bit_iterator<WrappedIterator> first, bit_iterator<WrappedIterator> last,
    SampleIterator out, Distance n, URBG&& g) {

  // create a vector of indices of bit positions
  std::vector<std::size_t> indices(std::distance(first, last)); 
  std::iota(indices.begin(), indices.end(), 0);

  // sample n indices
  std::vector<std::size_t> choices;
  std::sample(indices.begin(), indices.end(), 
      std::back_inserter(choices), n, std::forward<URBG>(g)); 

  // get the n bits
  for (auto& e : choices) {
    std::cout << "choice: " << e << "\n";

    out = *(first + e);
  }

  return out;
}

// ========================================================================== //
} // namespace bit

#endif // _SAMPLE_HPP_INCLUDED
// ========================================================================== //
