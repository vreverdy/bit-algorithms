// ================================= ROTATE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: rotate.hpp
// Description: bit_iterator overloads for std::rotate
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ROTATE_HPP_INCLUDED
#define _ROTATE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt>
constexpr bit_iterator<ForwardIt> rotate(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> n_first, bit_iterator<ForwardIt> last) {
    (n_first, last);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> rotate(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> n_first,
    bit_iterator<ForwardIt> last) {
    (policy, n_first, last); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _ROTATE_HPP_INCLUDED
// ========================================================================== //
