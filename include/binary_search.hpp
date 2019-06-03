// ============================= BINARY SEARCH ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: binary_search.hpp
// Description: bit_iterator overloads for std::binary_search
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _BINARY_SEARCH_HPP_INCLUDED
#define _BINARY_SEARCH_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do 
template <class ForwardIt, class T>
constexpr bool binary_search(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last, const T& value) {
    (first, last, value);
    return true;
}

// Status: on hold 
template <class ForwardIt, class T, class Compare>
constexpr bool binary_search(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const T& value, Compare comp) {
    (first, last, value, comp);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _BINARY_SEARCH_HPP_INCLUDED
// ========================================================================== //
