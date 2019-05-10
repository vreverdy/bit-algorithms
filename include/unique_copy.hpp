// ============================== UNIQUE COPY ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: unique_copy.hpp
// Description: bit_iterator overloads for std::unique_copy
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNIQUE_COPY_HPP_INCLUDED
#define _UNIQUE_COPY_HPP_INCLUDED
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
constexpr bit_iterator<OutputIt> unique_copy(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first) {
    (first, last);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> unique_copy(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> d_first) {
    (policy, first, last);
    return d_first;
}

// Status: complete
template <class InputIt, class OutputIt, class BinaryPredicate>
constexpr bit_iterator<OutputIt> unique_copy(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first,
    BinaryPredicate p) {
    return std::unique_copy(first, last, d_first, p);
}

// Status: complete
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class BinaryPredicate> bit_iterator<ForwardIt2> unique_copy(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first,
    BinaryPredicate p) {
    return std::unique_copy(std::forward<ExecutionPolicy>(policy), first,
        last, d_first, p);
}


// ========================================================================== //
} // namespace bit

#endif // _UNIQUE_COPY_HPP_INCLUDED
// ========================================================================== //
