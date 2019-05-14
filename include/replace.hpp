// ================================ REPLACE ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: replace.hpp
// Description: bit_iterator overloads for std::replace
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _REPLACE_HPP_INCLUDED
#define _REPLACE_HPP_INCLUDED
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
constexpr void replace(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last, bit_value old_value, bit_value new_value) {
    (first, last, old_value, new_value); 
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
void replace(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, bit_value old_value, bit_value new_value) {
    (policy, first, last, old_value, new_value); 
}

// Status: on hold
template <class ForwardIt, class UnaryPredicate>
constexpr void replace_if(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last, UnaryPredicate p, bit_value new_value) {
    (first, last, p, new_value);
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
void replace_if(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p, bit_value new_value) {
    (policy, first, last, p, new_value);
}

// ========================================================================== //
} // namespace bit

#endif // _REPLACE_HPP_INCLUDED
// ========================================================================== //
