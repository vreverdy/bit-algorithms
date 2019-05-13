// ============================== LOWER BOUND ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: lower_bound.hpp
// Description: bit_iterator overloads for std::lower_bound
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _LOWER_BOUND_HPP_INCLUDED
#define _LOWER_BOUND_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt, class T>
constexpr bit_iterator<ForwardIt> lower_bound(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const T& value) {
    (last, value); 
    return first;
}

// TODO
template <class ForwardIt, class T, class Compare>
constexpr bit_iterator<ForwardIt> lower_bound(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const T& value, Compare comp) {
    (last, value, comp); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _LOWER_BOUND_HPP_INCLUDED
// ========================================================================== //
