// ================================ POP HEAD ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: pop_head.hpp
// Description: bit_iterator overloads for std::pop_head
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _POP_HEAD_HPP_INCLUDED
#define _POP_HEAD_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class RandomIt>
constexpr void pop_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    (first, last);
}

// Status: on hold
template <class RandomIt, class Compare>
constexpr void pop_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last,
    Compare comp) {
    (first, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _POP_HEAD_HPP_INCLUDED
// ========================================================================== //
