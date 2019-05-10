// ============================== REMOVE COPY ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: remove_copy.hpp
// Description: bit_iterator overloads for std::remove_copy, std::remove_copy_if
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _REMOVE_COPY_HPP_INCLUDED
#define _REMOVE_COPY_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// Status: to do
template <class InputIt, class OutputIt>
constexpr bit_iterator<OutputIt> remove_copy(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first, bit_value value) {
    (first, last, value);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> remove_copy(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> d_first, bit_value value) {
    (policy, first, last, value);
    return d_first;
}

// Status: complete
template <class InputIt, class OutputIt, class UnaryPredicate>
constexpr bit_iterator<OutputIt> remove_copy_if(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first,
    UnaryPredicate p) {
    return std::remove_copy_if(first, last, d_first, p);
}

// Status: complete
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class UnaryPredicate> bit_iterator<ForwardIt2> remove_copy_if(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first, 
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first,
    UnaryPredicate p) {
    return std::remove_copy_if(std::forward<ExecutionPolicy>(policy), first,
        last, d_first, p);
}

// ========================================================================== //
} // namespace bit

#endif // _REMOVE_COPY_HPP_INCLUDED
// ========================================================================== //
