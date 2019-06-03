// ========================== UNINITIALIZED MOVE N ========================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_move_n.hpp
// Description: bit_iterator overloads for std::uninitialized_move_n
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_MOVE_N_HPP_INCLUDED
#define _UNINITIALIZED_MOVE_N_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class InputIt, class Size, class ForwardIt>
std::pair<bit_iterator<InputIt>, bit_iterator<ForwardIt>> uninitialized_move_n(
    bit_iterator<InputIt> first, Size count, bit_iterator<ForwardIt> d_first) {
    (count);
    return std::make_pair(first, d_first);
}

// Status: to do
template <class ExecutionPolicy, class InputIt, class Size, class ForwardIt>
std::pair<bit_iterator<InputIt>, bit_iterator<ForwardIt>> uninitialized_move_n(
    ExecutionPolicy&& policy, bit_iterator<InputIt> first, Size count,
    bit_iterator<ForwardIt> d_first) {
    (policy, count);
    return std::make_pair(first, d_first);
}


// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_MOVE_N_HPP_INCLUDED
// ========================================================================== //
