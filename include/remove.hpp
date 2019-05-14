// ================================= REMOVE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: remove.hpp
// Description: bit_iterator overloads for std::remove, std::remove_if
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _REMOVE_HPP_INCLUDED
#define _REMOVE_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> remove(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, bit_value value) {
    (last, value);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class T>
bit_iterator<ForwardIt> remove(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, bit_value value) {
    (policy, last, value);
    return first;
}

// Status: on hold
template <class ForwardIt, class UnaryPredicate>
constexpr bit_iterator<ForwardIt> remove_if(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> remove_if(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (policy, last, p);
    return first;
} 

// ========================================================================== //
} // namespace bit

#endif // _REMOVE_HPP_INCLUDED
// ========================================================================== //
