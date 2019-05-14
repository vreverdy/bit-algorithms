// ========================== UNINITIALIZED COPY N ========================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_copy_n.hpp
// Description: bit_iterator overloads for std::uninitialized_copy_n
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_COPY_N_HPP_INCLUDED
#define _UNINITIALIZED_COPY_N_HPP_INCLUDED
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
bit_iterator<ForwardIt> uninitialized_copy_n(bit_iterator<InputIt> first,
    Size count, bit_iterator<ForwardIt> d_first) {
    (first, count);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class InputIt, class Size, class ForwardIt>
bit_iterator<ForwardIt> uninitialized_copy_n(ExecutionPolicy&& policy,
    bit_iterator<InputIt> first, Size count, bit_iterator<ForwardIt> d_first) {
    (policy, first, count);
    return d_first;
}

// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_COPY_N_HPP_INCLUDED
// ========================================================================== //
