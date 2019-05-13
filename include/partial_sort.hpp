// ============================== PARTIAL SORT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: partial_sort.hpp
// Description: bit_iterator overloads for std::partial_sort
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTIAL_SORT_HPP_INCLUDED
#define _PARTIAL_SORT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {



// Status: to do
template <class RandomIt>
constexpr void partial_sort(bit_iterator<RandomIt> first, bit_iterator<RandomIt> middle,
    bit_iterator<RandomIt> last) {
    (first, middle, last);
}

// Status: to do
template <class ExecutionPolicy, class RandomIt>
void partial_sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> middle, bit_iterator<RandomIt> last) {
    (policy, first, middle, last);
}

// Status: on hold 
template <class RandomIt, class Compare>
constexpr void partial_sort(bit_iterator<RandomIt> first, 
    bit_iterator<RandomIt> middle, bit_iterator<RandomIt> last, Compare comp) {
    (first, middle, last, comp);
}

// Status: on hold 
template <class ExecutionPolicy, class RandomIt, class Compare>
void partial_sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> middle, bit_iterator<RandomIt> last, Compare comp) {
    (policy, first, middle, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _PARTIAL_SORT_HPP_INCLUDED
// ========================================================================== //
