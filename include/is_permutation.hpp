// ============================= IS PERMUTATION ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: is_permutation.hpp
// Description: bit_iterator overloads for std::is_permutation
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_PERMUTATION_HPP_INCLUDED
#define _IS_PERMUTATION_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt1, class ForwardIt2>
constexpr bool is_permutation(bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2) {
    (first1, last1, first2);
    return true;
}

// TODO
template <class ForwardIt1, class ForwardIt2, class BinaryPredicate>
constexpr bool is_permutation(bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    BinaryPredicate p) {
    (first1, last1, first2, p); 
    return true;
}

// TODO
template <class ForwardIt1, class ForwardIt2>
constexpr bool is_permutation(bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2) {
    (first1, last1, first2, last2); 
    return true;
} 

// TODO
template <class ForwardIt1, class ForwardIt2, class BinaryPredicate>
constexpr bool is_permutation(bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2, BinaryPredicate p) {
    (first1, last1, first2, last2, p);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _IS_PERMUTATION_HPP_INCLUDED
// ========================================================================== //
