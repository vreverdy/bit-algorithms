// =============================== DESTROY N =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: destroy_n.hpp
// Description: bit_iterator overloads for std::destroy_n
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _DESTROY_N_HPP_INCLUDED
#define _DESTROY_N_HPP_INCLUDED
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
bit_iterator<ForwardIt> destroy_n(bit_iterator<ForwardIt> first, Size n) {
    (n); 
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class Size>
bit_iterator<ForwardIt> destroy_n(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, Size n) {
    (policy, n); 
    return first; 
}

// ========================================================================== //
} // namespace bit

#endif // _DESTROY_N_HPP_INCLUDED
// ========================================================================== //
