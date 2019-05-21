// ========================== UNINITIALIZED FILL N ========================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_fill_n.hpp
// Description: bit_iterator overloads for std::uninitialized_fill_n
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_FILL_N_HPP_INCLUDED
#define _UNINITIALIZED_FILL_N_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt, class Size, class T>
bit_iterator<ForwardIt> uninitialized_fill_n(bit_iterator<ForwardIt> first, 
    Size count, bit_value value) {
    (count, value);    
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class Size, class T>
bit_iterator<ForwardIt> uninitialized_fill_n(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, Size count, bit_value value) {
    (policy, count, value); 
    return first;
}


// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_FILL_N_HPP_INCLUDED
// ========================================================================== //
