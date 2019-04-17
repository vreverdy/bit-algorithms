#ifndef BA_SEARCH
#define BA_SEARCH

#include <iostream>

namespace bit {

template <class WrappedIter1, class WrappedIter2>
bit_iterator<WrappedIter1> search(bit_iterator<WrappedIter1> first, bit_iterator<WrappedIter1> last,
   bit_iterator<WrappedIter2> s_first, bit_iterator<WrappedIter2> s_last) {
  return first;
} 

}

#endif
