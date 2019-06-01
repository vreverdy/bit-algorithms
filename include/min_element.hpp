// ============================== MIN ELEMENT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: min_element.hpp
// Description: bit_iterator overloads for std::min_element
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MIN_ELEMENT_HPP_INCLUDED
#define _MIN_ELEMENT_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> min_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (last);
    return first;
}

// Status: to do 
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> min_element(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, last);
    return first;
}

// Status: on hold 
template <class ForwardIt, class Compare>
constexpr bit_iterator<ForwardIt> min_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (last, comp);
    return first;
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt, class Compare>
bit_iterator<ForwardIt> min_element(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, Compare comp) {
    (policy, last, comp);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _MIN_ELEMENT_HPP_INCLUDED
// ========================================================================== //
