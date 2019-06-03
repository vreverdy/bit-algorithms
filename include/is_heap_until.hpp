// ============================= IS HEAP UNTIL ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: is_heap_until.hpp
// Description: bit_iterator overloads for std::is_heap_until
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_HEAP_UNTIL_HPP_INCLUDED
#define _IS_HEAP_UNTIL_HPP_INCLUDED
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
constexpr bit_iterator<RandomIt> is_heap_until(bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last) {
    (last);
    return first;
}

// Status: to do 
template <class ExecutionPolicy, class RandomIt>
bit_iterator<RandomIt> is_heap_until(ExecutionPolicy&& policy,
    bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    (policy, last);
    return first;
}

// Status: on hold
template <class RandomIt, class Compare>
constexpr bit_iterator<RandomIt> is_heap_until(bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last, Compare comp) {
    (last, comp);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class RandomIt, class Compare>
bit_iterator<RandomIt> is_heap_until(ExecutionPolicy&& policy,
    bit_iterator<RandomIt> first, bit_iterator<RandomIt> last, Compare comp) {
    (policy, last, comp);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _IS_HEAP_UNTIL_HPP_INCLUDED
// ========================================================================== //
