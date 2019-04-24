// =============================== copy.hpp ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: copy.hpp
// Description: Implementation of copy, copy_if, copy_n and copy_backward 
// Creator: Bryce Kille
// Contributor: Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _COPY_HPP_INCLUDED
#define _COPY_HPP_INCLUDED
#pragma once
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
// Project sources
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
#include "debug_utils.hpp"
namespace bit {
// ========================================================================== //



// --------------------------- Utility Functions ---------------------------- //
// Left shifts dst by cnt bits, filling the lsbs of dst by the msbs of src
template <class T1, class T2, class SizeT>
constexpr T1 _shld2(T1 dst, T2 src, SizeT cnt) noexcept
{
    static_assert(binary_digits<T1>::value, "");
    static_assert(binary_digits<T2>::value, "");
    constexpr T1 dst_digits = binary_digits<T1>::value;
    constexpr T1 src_digits = binary_digits<T2>::value;


    if (cnt < src_digits) {
        dst = ((dst << cnt) * (cnt < dst_digits)) | ((src >> (src_digits - cnt)));
    } else {
        dst = ((dst << cnt) * (cnt < dst_digits))
            | ((src << (cnt - src_digits))*(cnt < src_digits+src_digits)); 
    }
    return dst;
}

// Get next len bits beginning at start and store them in a word of type T
template <class T, class InputIt>
T get_word(bit_iterator<InputIt> first, T len=binary_digits<T>::value)
{
    using native_word_type = typename bit_iterator<InputIt>::word_type;
    T native_digits = binary_digits<native_word_type>::value; 
    constexpr T ret_digits = binary_digits<T>::value; 
    assert(ret_digits >= len);
    T offset = native_digits - first.position();
    T pos = first.position();
    T ret_word = *first.base() >> first.position();

    // We've already assigned enough bits
    if (len <= offset) { 
        return ret_word;
    } 

    auto it = std::next(first.base());
    len -= offset;
    // Fill up ret_word starting at bit [offset] using it
    while (len > native_digits) {
        ret_word = _bitblend(
                ret_word,      
                (T) (((T) *it) << offset),   
                offset,
                native_digits
        );
        ++it;
        offset += native_digits;
        len -= native_digits;
    }
    // Assign remaining len bits of last word
    ret_word = _bitblend(
            ret_word,            
            (T) (((T) *it) << offset),   
            offset,
            len
    );
    return ret_word;
}
// -------------------------------------------------------------------------- //



// ---------------------------- Copy Algorithms ----------------------------- //
template <class InputIt, class OutputIt>
bit_iterator<OutputIt> copy(bit_iterator<InputIt> first,
                            bit_iterator<InputIt> last,
                            bit_iterator<OutputIt> d_first
)
{
    // Assertions
    _assert_range_viability(first, last);
    if (first == last) return d_first;

    // Types and constants
    using src_word_type = typename bit_iterator<InputIt>::word_type;
    using src_size_type = typename bit_iterator<InputIt>::size_type;
    constexpr src_size_type src_digits = binary_digits<src_word_type>::value;
    using dst_word_type = typename bit_iterator<OutputIt>::word_type;
    using dst_size_type = typename bit_iterator<OutputIt>::size_type;
    constexpr dst_size_type dst_digits = binary_digits<dst_word_type>::value;

    // Initialization
    const bool is_d_first_aligned = d_first.position() == 0;
    src_word_type current_word = *first.base();
    src_word_type current_mask = -1;
    src_size_type total_bits_to_copy = std::distance(first, last);
    auto it = d_first.base();

    // d_first is not aligned. Copy partial word to align it
    if (!is_d_first_aligned) {
        dst_size_type partial_bits_to_copy = std::min(
                total_bits_to_copy,
                dst_digits - d_first.position()
                );
        std::cout << word_to_vec(*it) << std::endl;
        *it = _bitblend(
                *it,
                (dst_word_type) (get_word<dst_word_type>(first, partial_bits_to_copy) 
                  << ((dst_word_type)d_first.position())),
                (dst_word_type) d_first.position(),
                (dst_word_type) partial_bits_to_copy
                );
        total_bits_to_copy -= partial_bits_to_copy;
        std::advance(first, partial_bits_to_copy);
        it++;
    }

    while (total_bits_to_copy >= dst_digits) {
        *it = get_word<dst_word_type>(first, dst_digits);
        total_bits_to_copy -= dst_digits;
        it++; 
        std::advance(first, dst_digits);
    }
    if (total_bits_to_copy) {
        *it = _bitblend(
                *it,
                get_word<dst_word_type>(first, total_bits_to_copy),
                (dst_word_type)((dst_word_type(1) << total_bits_to_copy) - 1)
        );
    }
    return bit::bit_iterator<OutputIt>(it, total_bits_to_copy);
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _COPY_HPP_INCLUDED
// ========================================================================== //
