// =============================== MISMATCH ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: mismatch.hpp
// Description: bit_iterator overloads for std::mismatch 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MISMATCH_HPP_INCLUDED
#define _MISMATCH_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
#include <iostream>
// Project sources
#include "bit_algorithm_details.hpp"
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt1, class InputIt2>
constexpr std::pair<bit_iterator<InputIt1>, bit_iterator<InputIt2>> mismatch(
    bit_iterator<InputIt1> first1, bit_iterator<InputIt1> last1,
    bit_iterator<InputIt2> first2
) {
    (last1);
    return std::make_pair(first1, first2);
}

/*
// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
std::pair<bit_iterator<ForwardIt1>, bit_iterator<ForwardIt2>> mismatch(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2
) {
    return std::make_pair(first1, first2);
}
*/

// TODO
template <class InputIt1, class InputIt2, class BinaryPredicate>
constexpr std::pair<bit_iterator<InputIt1>, bit_iterator<InputIt2>> mismatch(
    bit_iterator<InputIt1> first1, bit_iterator<InputIt1> last1,
    bit_iterator<InputIt2> first2, BinaryPredicate p
) {
  bool b = p(*first1, *first2); 
  (b, last1);
  return std::make_pair(first1, first2);
}

/*
// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class BinaryPredicate> std::pair<bit_iterator<ForwardIt1>, 
    bit_iterator<ForwardIt2>> mismatch(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2, BinaryPredicate p) {
    bool b = p(*first1, *first2);
    return std::make_pair(first1, first2);
} 
*/

// TODO
template <class InputIt1, class InputIt2>
std::pair<bit_iterator<InputIt1>, bit_iterator<InputIt2>> mismatch(
   bit_iterator<InputIt1> first1, bit_iterator<InputIt1> last1,
   bit_iterator<InputIt2> first2, bit_iterator<InputIt2> last2
) {
    // we'll make reads of the smaller of the two word types. 
    using word1_type = typename bit_iterator<InputIt1>::word_type;
    using word2_type = typename bit_iterator<InputIt2>::word_type;

    constexpr std::size_t num_digits1 = binary_digits<word1_type>::value;
    constexpr std::size_t num_digits2 = binary_digits<word2_type>::value;

    using word_type = typename std::conditional<
      num_digits1 < num_digits2, word1_type, word2_type>::type;

    bit_iterator<InputIt1> in1 = first1;
    bit_iterator<InputIt2> in2 = first2;

    while (true) {
        word_type w1 = get_word(in1, binary_digits<word_type>::value);  
        word_type w2 = get_word(in2, binary_digits<word_type>::value);

        if (w1 != w2) {
            // the two words don't match. let's find the position of the mismatched bits
            while (in1 != last1 && in2 != last2 && *in1 == *in2) {
              ++in1;
              ++in2;
            }
            break;
        } else {
            // the words match. advance the iterators by one word
            std::advance(in1, binary_digits<word_type>::value);
            std::advance(in2, binary_digits<word_type>::value);
        }
    }
    return std::make_pair(in1, in2);
}  

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
std::pair<bit_iterator<ForwardIt1>, bit_iterator<ForwardIt2>> mismatch(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2) {
    (policy, last1, last2);
    return std::make_pair(first1, first2);
} 

// TODO
template <class InputIt1, class InputIt2, class BinaryPredicate>
constexpr std::pair<bit_iterator<InputIt1>, bit_iterator<InputIt2>> mismatch(
    bit_iterator<InputIt1> first1, bit_iterator<InputIt1> last1,
    bit_iterator<InputIt2> first2, bit_iterator<InputIt2> last2,
    BinaryPredicate p) {
    (last1, last2, p);
    return std::make_pair(first1, first2);
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class BinaryPredicate> std::pair<bit_iterator<ForwardIt1>,
    bit_iterator<ForwardIt2>> mismatch(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2, bit_iterator<ForwardIt2> last2,
    BinaryPredicate p) {
    bool b = p(*first1, *first2);
    (b, policy, last1, last2);
    return std::make_pair(first1, first2);
}

// ========================================================================== //
} // namespace bit

#endif // _MISMATCH_HPP_INCLUDED
// ========================================================================== //
