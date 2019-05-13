// ============================== NTH ELEMENT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: nth_element.hpp
// Description: bit_iterator overloads for std::nth_element
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _NTH_ELEMENT_HPP_INCLUDED
#define _NTH_ELEMENT_HPP_INCLUDED
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
constexpr void nth_element(bit_iterator<RandomIt> first, bit_iterator<RandomIt> nth,
    bit_iterator<RandomIt> last) {
    (first, nth, last);
}

// Status: to do
template <class ExecutionPolicy, class RandomIt>
void nth_element(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> nth, bit_iterator<RandomIt> last) {
    (policy, first, nth, last);
}

// Status: on hold
template <class RandomIt, class Compare>
void nth_element(bit_iterator<RandomIt> first, bit_iterator<RandomIt> nth,
    bit_iterator<RandomIt> last, Compare comp) {
    (first, nth, last, comp);
}


// Status: on hold
template <class ExecutionPolicy, class RandomIt, class Compare>
void nth_element(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> nth, bit_iterator<RandomIt> last, Compare comp) {
    (policy, first, nth, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _NTH_ELEMENT_HPP_INCLUDED
// ========================================================================== //
