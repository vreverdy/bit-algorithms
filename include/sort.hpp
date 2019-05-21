// ================================== SORT ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: sort.hpp
// Description: bit_iterator overloads for std::sort
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SORT_HPP_INCLUDED
#define _SORT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class RandomIt>
constexpr void sort(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    (first, last);
}

// Status: to do
template <class ExecutionPolicy, class RandomIt>
void sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last) {
    (policy, first, last);
}

// Status: on hold
template <class RandomIt, class Compare>
constexpr void sort(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last,
    Compare comp) {
    (first, last, comp);
}

// Status: on hold
template <class ExecutionPolicy, class RandomIt, class Compare>
void sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last, Compare comp) {
    (policy, first, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _SORT_HPP_INCLUDED
// ========================================================================== //
