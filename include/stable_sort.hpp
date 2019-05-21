// ============================== STABLE SORT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: stable_sort.hpp
// Description: bit_iterator overloads for std::stable_sort
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _STABLE_SORT_HPP_INCLUDED
#define _STABLE_SORT_HPP_INCLUDED
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
void stable_sort(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    (first, last);
}

// Status: to do
template <class ExecutionPolicy, class RandomIt>
void stable_sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last) {
    (policy, first, last); 
}

// Status: on hold
template <class RandomIt, class Compare>
void stable_sort(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last,
    Compare comp) {
    (first, last, comp);
}

// Status: on hold
template <class ExecutionPolicy, class RandomIt, class Compare>
void stable_sort(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last, Compare comp) {
    (policy, first, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _STABLE_SORT_HPP_INCLUDED
// ========================================================================== //
