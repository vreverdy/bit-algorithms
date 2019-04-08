// =============================== FILE NAME ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: copy.hpp
// Description: Implementations of copy-related algorithms
// Creator: Bryce Kille
// Contributor: Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _COPY_HPP_INCLUDED
#define _COPY_HPP_INCLUDED
// ========================================================================== //

// ================================ PREAMBLE ================================ //
#pragma once
// Project sources
#include "bit.hpp"
#include "../src/tests/test_utils.hpp"
namespace bit {
// ========================================================================== //

// --------------------------- Utility Functions ---------------------------- //
// Let [i] represent the ith LSB of a word. assign(f, iw, im) will 
// assign iw[i] to *(f+i) iff im[i] == 1
// Essentially it is the same as _bitblend but for unaligned
// words of different sizes
template <class InputIt, class AssignmentType>
void assign(bit_iterator<InputIt> first,
            AssignmentType input_word,
            AssignmentType input_mask
)
{
    using native_word_type = typename bit_iterator<InputIt>::word_type;
    using size_type = typename bit_iterator<InputIt>::size_type;
    constexpr size_type native_digits = binary_digits<native_word_type>::value; 
    constexpr size_type assignment_digits = binary_digits<AssignmentType>::value; 
    auto it = first.base();
    native_word_type current_assignment; 
    native_word_type current_mask;
    bool oversized;
    short int shift_size;
    size_type offset = (native_digits - first.position())*(first.position() != 0);
    // Assign first num_bits from input_word to last num_bits of first.base()
    if (first.position()) {
        oversized = offset < assignment_digits;
        shift_size =  (assignment_digits - offset)*oversized;
        current_assignment = input_word << shift_size; 
        current_mask = input_mask << shift_size;
        *it = _bitblend(*it,
                        current_assignment,
                        current_mask
        );
        it = std::next(it);
        // We have already assigned everything to consider
        if (_popcnt(current_mask) == _popcnt(input_mask)) {
            return;
        }
    }
    // - For native_word_type #i, we want to assign 
    // [input_word[offset+i*native_digits], input_word[offset+(i+1)*native_digits)
    // - Which means the last bit we care about is at 
    // index = offset+(i+1)*native_digits - 1
    // - Therefore at each step we need to left shift input_word 
    // by shift = assignment_digits - (offset+(i+1)*native_digits)
    // If shift < 0, then we actually have to left right by shift, not left.
    oversized = native_digits < assignment_digits;
    unsigned int current_idx = 0;
    do {
        shift_size = (assignment_digits - (offset + (current_idx+1)*native_digits));
        if (shift_size > 0) {
            current_assignment = input_word << shift_size; 
            current_mask = input_mask << shift_size;
        } else {
            current_assignment = input_word >> -shift_size; 
            current_mask = input_mask >> -shift_size;
        } 
        *it = _bitblend(*it,
                        current_assignment,
                        current_mask
        );
        ++it;
        ++current_idx;
    } while (shift_size > 0); 
    // if shift_size > 0, then we still have shift_size bits left to assign
    return;
}
// -------------------------------------------------------------------------- //

// ---------------------------- Copy Algorithms ----------------------------- //
template <class InputIt, class OutputIt>
bit_iterator<OutputIt> copy(bit_iterator<InputIt> first,
                            bit_iterator<InputIt> last,
                            bit_iterator<OutputIt> d_first
)
{
    if (first == last) return d_first;

    // Types and constants
    using in_word_type = typename bit_iterator<InputIt>::word_type;
    using in_size_type = typename bit_iterator<InputIt>::size_type;
    constexpr in_size_type in_digits = binary_digits<in_word_type>::value;
    using out_word_type = typename bit_iterator<OutputIt>::word_type;
    using out_size_type = typename bit_iterator<OutputIt>::size_type;
    constexpr out_size_type out_digits = binary_digits<out_word_type>::value;
    const bool is_last_aligned = last.position() == 0;
    const bool is_first_aligned = first.position() == 0;

    auto d_last = d_first;

    in_word_type current_word = *first.base();
    in_word_type current_mask = -1;

    // Assign suffix of first word in range if not aligned
    if (!is_first_aligned) {
        current_mask >>= first.position();
        current_word >>= first.position();
    }
    // Copy within same word
    if (std::next(first.base(), is_last_aligned) == last.base()) {
        current_mask >>= (in_digits - last.position())*(!is_last_aligned); 
        assign(d_first, current_word, current_mask); 
        std::advance(d_last, last.position() - first.position());
        return d_last;
    }
    // Assign first word
    assign(d_first, current_word, current_mask); 
    std::advance(d_last, in_digits - first.position());
    InputIt it = std::next(first.base());
    // Assign all remaining full words
    for (; it != last.base(); it++){
        current_word = *it;
        current_mask = -1;
        assign(d_last, current_word, current_mask);
        std::advance(d_last, in_digits);
    }
    // Assign the last partial word in the range. 
    if (!is_last_aligned) {
        current_word = *it;
        current_mask = -1 >> (in_digits - last.position());
        assign(d_last, current_word, current_mask);
        std::advance(d_last, last.position());
    }
    return d_last;
}
// -------------------------------------------------------------------------- //

// ========================================================================== //
} // namespace bit
#endif // _COPY_HPP_INCLUDED
// ========================================================================== //
