// =========================== UNINITIALIZED FILL =========================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_fill.hpp
// Description: bit_iterator overloads for std::uninitialized_fill
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_FILL_HPP_INCLUDED
#define _UNINITIALIZED_FILL_HPP_INCLUDED
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
void uninitialized_fill(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    bit_value value) {
    (first, last, value);    
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class T>
void uninitialized_fill(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, bit_value value) {
    (policy, first, last, value);
}


// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_FILL_HPP_INCLUDED
// ========================================================================== //
