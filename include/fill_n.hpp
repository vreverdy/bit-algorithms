// ================================ FILL N ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: fill_n.hpp
// Description: bit_iterator overloads for std::fill_n
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FILL_N_HPP
#define _FILL_N_HPP

namespace bit {

template <class WrappedIter, class Size>
void fill_n(bit_iterator<WrappedIter> first, Size count, bit::bit_value bv) {
  bit_iterator<WrappedIter> last = first + count;
  bit::fill(first, last, bv); 
}

} // namespace bit

#endif // _FILL_N_HPP
