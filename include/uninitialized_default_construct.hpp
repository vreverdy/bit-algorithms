// ==================== UNINITIALIZED DEFAULT CONSTRUCT ==================== //
// Project: The Experimental Bit Algorithms Library
// Name: uninitialized_default_construct.hpp
// Description: bit_iterator overloads for std::uninitialized_default_construct
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNINITIALIZED_DEFAULT_CONSTRUCT_HPP_INCLUDED
#define _UNINITIALIZED_DEFAULT_CONSTRUCT_HPP_INCLUDED
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
void uninitialized_default_construct(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (first, last); 
} 

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
void uninitialized_default_construct(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, first, last);
}


// ========================================================================== //
} // namespace bit

#endif // _UNINITIALIZED_DEFAULT_CONSTRUCT_HPP_INCLUDED
// ========================================================================== //
