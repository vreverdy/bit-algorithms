// =============================== TRANSFORM =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: transform.hpp
// Description: bit_iterator overloads for std::transform
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _TRANSFORM_HPP_INCLUDED
#define _TRANSFORM_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit.hpp"
// Third-party libraries
#include "xsimd/xsimd.hpp"
#include "xsimd/stl/algorithms.hpp"
#include <iterator>
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: on hold
//template <class InputIt, class OutputIt, class UnaryOperation>
//constexpr bit_iterator<OutputIt> transform(bit_iterator<InputIt> first1,
    //bit_iterator<InputIt> last1, bit_iterator<OutputIt> d_first,
    //UnaryOperation unary_op) {
    //(first1, last1, unary_op);
    //return d_first;
//}

//// Status: on hold
//template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    //class UnaryOperation> bit_iterator<ForwardIt2> transform(ExecutionPolicy&& policy,
    //bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    //bit_iterator<ForwardIt2> d_first, UnaryOperation unary_op) {
    //(policy, first1, last1, unary_op);
    //return d_first;
//}

template <class RandomAccessIt, class BinaryOperation>
constexpr bit_iterator<RandomAccessIt> transform_word(
        bit_iterator<RandomAccessIt> first1,
        bit_iterator<RandomAccessIt> last1, 
        bit_iterator<RandomAccessIt> first2,
        bit_iterator<RandomAccessIt> d_first,
        BinaryOperation binary_op) {
    // Assertions
     _assert_range_viability(first1, last1); 

    // Types and constants
    using word_type    = typename bit_iterator<RandomAccessIt>::word_type;
    using size_type    = typename bit_iterator<RandomAccessIt>::size_type;
    constexpr size_type digits     = binary_digits<word_type>::value;

    if (is_within<digits>(first1, last1)) {
        word_type d = distance(first1, last1);
        write_word<word_type>(
            binary_op(
                get_word(first1, d),
                get_word(first2, d)
            ),
            d_first, 
            d
        );
        return next(d_first, d);
    } 
    
    RandomAccessIt it1    = first1.base();
    if (first1.position() != 0) {
        word_type d = digits - first1.position();
        write_word<word_type>(
            binary_op(
                static_cast<word_type>(*first1.base() >> first1.position()),
                get_word(first2, d)
            ),
            d_first,
            d
        );
        ++it1; 
        advance(first2, d);
        advance(d_first, d);
    }
    
    while (it1 != last1.base()) {
        write_word<word_type>(
            binary_op(
                *it1++,
                get_word<word_type>(first2)
            ),
            d_first,
            (word_type)digits
        );
        advance(d_first, digits);
        advance(first2, digits);
    }

    if (last1.position() != 0) {
        write_word<word_type>(
            binary_op(
                *it1,
                get_word(first2, last1.position())
            ),
            d_first,
            static_cast<word_type>(last1.position())
        );
        advance(d_first, last1.position());
    }
    return d_first;
}

template <class RandomAccessIt, class BinaryOperation>
constexpr bit_iterator<RandomAccessIt> transform(
        bit_iterator<RandomAccessIt> first1,
        bit_iterator<RandomAccessIt> last1, 
        bit_iterator<RandomAccessIt> first2,
        bit_iterator<RandomAccessIt> d_first,
        BinaryOperation binary_op) {
    // Assertions
     _assert_range_viability(first1, last1); 

    // Types and constants
    using word_type    = typename bit_iterator<RandomAccessIt>::word_type;
    using size_type    = typename bit_iterator<RandomAccessIt>::size_type;
    constexpr size_type digits     = binary_digits<word_type>::value;

    bool is_first1_aligned = first1.position() == 0;
    bool is_last1_aligned = last1.position() == 0;
    bool is_first2_aligned = first2.position() == 0;
    bool is_d_first_aligned = d_first.position() == 0;
    
    if (is_first1_aligned && is_first2_aligned && is_d_first_aligned && is_last1_aligned) {
        xsimd::transform(first1.base(), last1.base(), first2.base(), d_first.base(),
               [binary_op](const auto& x, const auto& y) {return binary_op(x, y);}); 
        first1 += std::distance(first1.base(), last1.base()) * digits;
        first2 += std::distance(first1.base(), last1.base()) * digits;
        d_first += std::distance(first1.base(), last1.base()) * digits;
    }
    return d_first; //transform_word(first1, last1, first2, d_first, binary_op);
}

// Status: on hold
//template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2, class ForwardIt3,
    //class BinaryOperation> bit_iterator<ForwardIt3> transform(ExecutionPolicy&& policy,
    //bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    //bit_iterator<ForwardIt2> first2, bit_iterator<ForwardIt3> d_first, 
    //BinaryOperation binary_op) {
    //(policy, first1, last1, first2, binary_op);
    //return d_first;
//}

// ========================================================================== //
} // namespace bit

#endif // _TRANSFORM_HPP_INCLUDED
// ========================================================================== //
