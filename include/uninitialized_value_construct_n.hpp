// =================== UNINITIALIZED VALUE CONSTRUCT N =================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_value_construct_n.hpp
// Description: bit_iterator overloads for std::uninitialized_value_construct_n
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_VALUE_CONSTRUCT_N_HPP_INCLUDED
#define _UNINITIALIZED_VALUE_CONSTRUCT_N_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt, class Size>
bit_iterator<ForwardIt> uninitialized_value_construct_n(
    bit_iterator<ForwardIt> first, Size n) {
    (n);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class Size>
bit_iterator<ForwardIt> uninitialized_value_construct_n(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, Size n) {
    (policy, n);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_VALUE_CONSTRUCT_N_HPP_INCLUDED
// ========================================================================== //
