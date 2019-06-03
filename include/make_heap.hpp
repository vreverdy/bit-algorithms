// =============================== MAKE HEAP =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: make_heap.hpp
// Description: bit_iterator overloads for std::make_heap
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MAKE_HEAP_HPP_INCLUDED
#define _MAKE_HEAP_HPP_INCLUDED
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
constexpr void make_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    (first, last);
}

// Status: on hold
template <class RandomIt, class Compare>
constexpr void make_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last,
    Compare comp) {
    (first, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _MAKE_HEAP_HPP_INCLUDED
// ========================================================================== //
