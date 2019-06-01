// =============================== SEARCH =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: search.hpp
// Description: bit_iterator overloads for std::search
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SEARCH_HPP_INCLUDED
#define _SEARCH_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
#include <iostream>
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt1, class ForwardIt2>
constexpr bit_iterator<ForwardIt1> search(bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> s_first,
    bit_iterator<ForwardIt2> s_last) {
    (last, s_first, s_last);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt1> search(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> s_first, bit_iterator<ForwardIt2> s_last) {
    (policy, last, s_first, s_last);
    return first; 
}

// Status: on hold
template <class ForwardIt1, class ForwardIt2, class BinaryPredicate>
constexpr bit_iterator<ForwardIt1> search(bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> s_first,
    bit_iterator<ForwardIt2> s_last, BinaryPredicate p) {
    (last, s_first, s_last, p);
    return first;
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2, 
         class BinaryPredicate> bit_iterator<ForwardIt1> search(
         ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first,
         bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> s_first,
         bit_iterator<ForwardIt2> s_last, BinaryPredicate p) {
    (policy, last, s_first, s_last, p);
    return first; 
}
         
// Status: complete
template <class ForwardIt, class Searcher>
constexpr bit_iterator<ForwardIt> search(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const Searcher& searcher) {
    (last, searcher);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _SEARCH_HPP_INCLUDED
// ========================================================================== //
