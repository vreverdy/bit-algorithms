// ======================== LEXICOGRAPHICAL COMPARE ======================== //
// Project: The Experimental Bit Algorithms Library
// Name: lexicographical_compare.hpp
// Description: bit_iterator overloads for std::lexicographical_compare
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _LEXICOGRAPHICAL_COMPARE_HPP_INCLUDED
#define _LEXICOGRAPHICAL_COMPARE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt1, class InputIt2>
constexpr bool lexicographical_compare(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2) {
    (first1, last1, first2, last2); 
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bool lexicographical_compare(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2, bit_iterator<ForwardIt2> last2) {
    (policy, first1, last1, first2, last2);
    return true;
}

// TODO
template <class InputIt1, class InputIt2, class Compare>
constexpr bool lexicographical_compare(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2, Compare comp) {
    (first1, last1, first2, last2, comp); 
    return true;
} 

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class Compare> bool lexicographical_compare(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2, bit_iterator<ForwardIt2> last2,
    Compare comp) {
    (policy, first1, last1, first2, last2, comp);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _LEXICOGRAPHICAL_COMPARE_HPP_INCLUDED
// ========================================================================== //
