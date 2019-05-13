// ============================= MINMAX ELEMENT ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: minmax_element.hpp
// Description: bit_iterator overloads for std::minmax_element
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MINMAX_ELEMENT_HPP_INCLUDED
#define _MINMAX_ELEMENT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt>
constexpr std::pair<bit_iterator<ForwardIt>, bit_iterator<ForwardIt>>
minmax_element(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    return std::make_pair(first, last);
}

// TODO
template <class ExecutionPolicy, class ForwardIt>
std::pair<bit_iterator<ForwardIt>, bit_iterator<ForwardIt>> minmax_element (
    ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (policy);
    return std::make_pair(first, last);
}

// TODO
template <class ForwardIt, class Compare>
constexpr std::pair<bit_iterator<ForwardIt>, bit_iterator<ForwardIt>>
    minmax_element(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    Compare comp) {
    (comp);
    return std::make_pair(first, last);
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class Compare>
std::pair<bit_iterator<ForwardIt>, bit_iterator<ForwardIt>> minmax_element (
    ExecutionPolicy&& policy, bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last, Compare comp) {
    (policy, comp); 
    return std::make_pair(first, last);
}

// ========================================================================== //
} // namespace bit

#endif // _MINMAX_ELEMENT_HPP_INCLUDED
// ========================================================================== //
