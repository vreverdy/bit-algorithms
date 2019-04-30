// =============================== IS SORTED =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: is_sorted.hpp
// Description: bit_iterator overloads for std::is_sorted
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_SORTED_HPP_INCLUDED
#define _IS_SORTED_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt>
constexpr bool is_sorted(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last) {
    (first, last); 
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt>
bool is_sorted(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (policy, first, last);
    return true;
}

// TODO
template <class ForwardIt, class Compare>
constexpr bool is_sorted(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (first, last, comp);
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class Compare>
bool is_sorted(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (policy, first, last, comp);
    return true;
}


// ========================================================================== //
} // namespace bit

#endif // _IS_SORTED_HPP_INCLUDED
// ========================================================================== //
