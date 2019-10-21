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

// TODO Not optimized
template <class InputIt1, class InputIt2>
constexpr std::pair<bit_iterator<InputIt1>, bit_iterator<InputIt2>> mismatch(
    bit_iterator<InputIt1> first1, bit_iterator<InputIt1> last1,
    bit_iterator<InputIt2> first2
) {
    // Assertions
     _assert_range_viability(first1, last1); 

    // Types and constants
    using word_type1 = typename bit_iterator<InputIt1>::word_type;
    using word_type2 = typename bit_iterator<InputIt2>::word_type;
    using size_type1 = typename bit_iterator<InputIt1>::size_type;
    using size_type2 = typename bit_iterator<InputIt2>::size_type;
    constexpr size_type1 digits1 = binary_digits<word_type1>::value;
    constexpr size_type2 digits2 = binary_digits<word_type2>::value;

    // Different word types ):
    if constexpr (digits1 != digits2) {
        return std::mismatch(first1, last1, first2);
    }

    // Same word types word types (:
    using word_type = word_type1; 
    constexpr size_type1 digits = digits1; 

    if (is_within<digits>(first1, last1)) {
        word_type m = distance(first1, last1); 
        word_type mask = static_cast<word_type>(-1) 
                        >> (digits - distance(first1, last1));
        word_type range1 = get_word(first1, m) & mask;
        word_type range2 = get_word(first2, m) & mask;
        word_type adv = std::min(m, _tzcnt(static_cast<word_type>(range1 ^ range2)));
        return std::make_pair(
                next(first1, adv),
                next(first2, adv)
        );
    }
    if (first1.position() != 0) {
        word_type range1 = *first1.base() >> first1.position();
        word_type range2 = get_word<word_type>(first2, digits) 
            & static_cast<word_type>(
                    static_cast<word_type>(-1) >> first1.position()
        );
        word_type adv = std::min<word_type>(
                digits - first1.position(), 
                _tzcnt(static_cast<word_type>(range1 ^ range2))
        );
        if (adv < (digits - first1.position())) {
            return std::make_pair(
                    next(first1, adv), 
                    next(first2, adv)
            );
        }
        advance(first1, adv);
        advance(first2, adv);
    }  
    while (first1.base() !=  last1.base()) {
        word_type range2 = get_word(first2, digits);
        word_type adv = _tzcnt<word_type>(*first1.base() ^ range2);
        advance(first1, adv);
        advance(first2, adv);
        if (adv < digits) {
            return std::make_pair(first1, first2); 
        }
    }
    if (last1.position() != 0) {
        word_type mask = static_cast<word_type>(
                (static_cast<word_type>(1) << last1.position()) - 1
        );
        word_type range1 = *first1.base();
        word_type range2 = get_word(first2, last1.position());
        word_type adv = std::min<word_type>(
                _tzcnt<word_type>(static_cast<word_type>(range1 ^ range2) & mask),
                last1.position()
        );
        advance(first1, adv);
        advance(first2, adv);
    }
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
