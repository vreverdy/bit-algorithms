// =============================== REVERSE ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: reverse.hpp
// Description: bit_iterator overloads for std::reverse
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _REVERSE_HPP_INCLUDED
#define _REVERSE_HPP_INCLUDED
// ========================================================================== //


// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit.hpp"
// Third-party libraries

namespace bit {

/**
 * Reverses the order of bits in the range 
 * @param first the beginning of the iteration range
 * @param last the end of the iteration range
 */
template <class BidirIt>
void reverse(
    bit_iterator<BidirIt> first,
    bit_iterator<BidirIt> last
)
{
    // Assertions
    _assert_range_viability(first, last);

    // Types and constants
    using word_type = typename bit_iterator<BidirIt>::word_type;
    using size_type = typename bit_iterator<BidirIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;

    // Initialization
    const bool is_first_aligned = first.position() == 0;
    const bool is_last_aligned = last.position() == 0;
    size_type gap = (digits - last.position()) * !is_last_aligned;
    auto it = first.base();
    word_type first_value = {};
    word_type last_value = {};

    // Reverse when bit iterators are aligned
    if (is_first_aligned && is_last_aligned) {
        std::reverse(first.base(), last.base());
        for (; it !=  last.base(); ++it) {
            *it = _bitswap(*it);
        }
        // Reverse when bit iterators do not belong to the same underlying word
    } else if (first.base() != last.base()) {
        // Save first and last element
        first_value = *first.base();
        last_value = *std::prev(last.base(), is_last_aligned);
        // Reverse the underlying sequence
        std::reverse(first.base(), std::next(last.base(), !is_last_aligned));
        // Shift the underlying sequence to the left
        if (first.position() < gap) {
            it = first.base();
            gap = gap - first.position();
            for (; it != last.base(); ++it) {
                *it = _shld<word_type>(*it, *std::next(it), gap);
            }
            *it <<= gap;
            it = first.base();
            // Shift the underlying sequence to the right
        } else if (first.position() > gap) {
            it = std::prev(last.base(), is_last_aligned);
            gap = first.position() - gap;
            for (; it != first.base(); --it) {
                *it = _shrd<word_type>(*it, *std::prev(it), gap);
            }
            *it >>= gap;
            it = first.base();
        }
        // Bitswap every element of the underlying sequence
        for (; it != std::next(last.base(), !is_last_aligned); ++it) {
            *it = _bitswap(*it);
        }
        // Blend bits of the first element
        if (!is_first_aligned) {
            *first.base() = _bitblend<word_type>(
                    first_value,
                    *first.base(),
                    first.position(),
                    digits - first.position()
            );
        }
        // Blend bits of the last element
        if (!is_last_aligned) {
            *last.base() = _bitblend<word_type>(
                    *last.base(),
                    last_value,
                    last.position(),
                    digits - last.position()
            );
        }
        // Reverse when bit iterators belong to the same underlying word
    } else {
        *it = _bitblend<word_type>(
                *it,
                _bitswap<word_type>(*it >> first.position()) >> gap,
                first.position(),
                last.position() - first.position()
        );
    }
}

// ========================================================================== //
} // namespace bit

#endif // _REVERSE_HPP
// ========================================================================== //
