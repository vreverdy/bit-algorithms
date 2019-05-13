// =========================== PARTIAL SORT COPY =========================== //
// Project: The Experimental Bit Algorithms Library
// Name: partial_sort_copy.hpp
// Description: bit_iterator overloads for std::partial_sort_copy
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTIAL_SORT_COPY_HPP_INCLUDED
#define _PARTIAL_SORT_COPY_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //

  

// Status: to do
template <class InputIt, class RandomIt>
constexpr bit_iterator<RandomIt> partial_sort_copy(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<RandomIt> d_first,
    bit_iterator<RandomIt> d_last) {
    (first, last, d_last);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt, class RandomIt>
bit_iterator<RandomIt> partial_sort_copy(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    bit_iterator<RandomIt> d_first, bit_iterator<RandomIt> d_last) {
    (policy, first, last, d_last);
    return d_first;
}

// Status: on hold
template <class InputIt, class RandomIt, class Compare>
constexpr bit_iterator<RandomIt> partial_sort_copy(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<RandomIt> d_first,
    bit_iterator<RandomIt> d_last, Compare comp) {
    (first, last, d_last, comp);
    return d_first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class RandomIt, class Compare>
bit_iterator<RandomIt> partial_sort_copy(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    bit_iterator<RandomIt> d_first, bit_iterator<RandomIt> d_last, Compare comp) {
    (policy, first, last, d_last, comp);
    return d_first;
}
    

// ========================================================================== //
} // namespace bit

#endif // _PARTIAL_SORT_COPY_HPP_INCLUDED
// ========================================================================== //
