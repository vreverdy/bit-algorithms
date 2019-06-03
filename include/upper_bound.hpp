// ============================== UPPER BOUND ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: upper_bound.hpp
// Description: bit_iterator overloads for std::upper_bound
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UPPER_BOUND_HPP_INCLUDED
#define _UPPER_BOUND_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> upper_bound(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const T& value) {
    (last, value); 
    return first;
}

// Status: on hold 
template <class ForwardIt, class T, class Compare>
constexpr bit_iterator<ForwardIt> upper_bound(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const T& value, Compare comp) {
    (last, value, comp); 
    return first;
}


// ========================================================================== //
} // namespace bit

#endif // _UPPER_BOUND_HPP_INCLUDED
// ========================================================================== //
