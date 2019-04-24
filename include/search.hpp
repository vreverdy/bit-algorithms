// =============================== SEARCH =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: search.hpp
// Description: bit_iterator overloads for std::search
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SEARCH_HPP
#define _SEARCH_HPP

// C++ standard library
#include <iostream>

namespace bit {

template <class WrappedIter1, class WrappedIter2>
bit_iterator<WrappedIter1> search(bit_iterator<WrappedIter1> first, bit_iterator<WrappedIter1> last,
   bit_iterator<WrappedIter2> s_first, bit_iterator<WrappedIter2> s_last) {
  return first;
} 

} // namespace bit

#endif // _SEARCH_HPP
