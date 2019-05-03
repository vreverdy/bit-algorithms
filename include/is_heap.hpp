// ================================ IS HEAP ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: is_heap.hpp
// Description: bit_iterator overloads for std::is_heap
// Creator: Vincent Reverdy
// Contributor(s): Collin Gress [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_HEAP_HPP_INCLUDED
#define _IS_HEAP_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

template <class RandomIt>
constexpr bool is_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last) {
    if (first.base() == last.base()) {
        // even numbers cannot be heap
        if (*first.base() % 2 == 0 && *first.base() > 0) {
            return false;
        }
    }
    return std::is_heap(first, last);
}

template <class ExecutionPolicy, class RandomIt>
bool is_heap(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last) {
    return std::is_heap(std::forward<ExecutionPolicy>(policy), first, last);
}

template <class RandomIt, class Compare>
constexpr bool is_heap(bit_iterator<RandomIt> first, bit_iterator<RandomIt> last,
    Compare comp) {
    return std::is_heap(first, last, comp);
}

template <class ExecutionPolicy, class RandomIt, class Compare>
bool is_heap(ExecutionPolicy&& policy, bit_iterator<RandomIt> first,
    bit_iterator<RandomIt> last, Compare comp) {
    return std::is_heap(std::forward<ExecutionPolicy>(policy), first, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _IS_HEAP_HPP_INCLUDED
// ========================================================================== //
