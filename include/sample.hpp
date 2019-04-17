#ifndef BA_SAMPLE
#define BA_SAMPLE

#include <iostream>
#include <algorithm>
#include <vector>

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

}

#endif
