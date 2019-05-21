// ==================== UNINITIALIZED VALUE CONSTRUCT ==================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_value_construct.hpp
// Description: bit_iterator overloads for std::uninitialized_value_construct
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_VALUE_CONSTRUCT_HPP_INCLUDED
#define _UNINITIALIZED_VALUE_CONSTRUCT_HPP_INCLUDED
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
void uninitialized_value_construct(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (first, last); 
} 

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
void uninitialized_value_construct(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, first, last);
}


// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_VALUE_CONSTRUCT_HPP_INCLUDED
// ========================================================================== //
