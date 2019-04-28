// =============================== SHIFT LEFT =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: shift_left.hpp
// Description: bit_iterator overloads for std::shift_left
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SHIFT_LEFT_HPP_INCLUDED
#define _SHIFT_LEFT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //
template <class ForwardIt>
bit_iterator<ForwardIt> shift_left(bit_iterator<ForwardIt> first,
                                   bit_iterator<ForwardIt> last,
                                   typename bit_iterator<ForwardIt>::difference_type n
)
{
    // Assertions
     _assert_range_viability(first, last); 

    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using size_type = typename bit_iterator<ForwardIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;

    // Initialization
    size_type word_shifts = n / digits; 
    size_type remaining_bitshifts = n - digits*(word_shifts);
    const bool is_first_aligned = first.position() == 0;
    const bool is_last_aligned = last.position() == 0;
    auto d = distance(first, last);
    if (n <= 0 || n >= d) return first;
    auto first_value = *first.base();
    auto last_value = !is_last_aligned ? *last.base() : 0;

    // Shift words to the left using std::shift 
    auto new_last_base = word_shift_left(first.base(), 
                                         std::next(last.base(), 
                                                   !is_last_aligned
                                                   ),
                                         word_shifts
    );
    last = bit_iterator<ForwardIt>(new_last_base, last.position());
    bit_iterator<ForwardIt> d_last;
    // Shift bit sequence to the left 
    // TODO inconsistent with vincent's description of l/r sequence shifting
    if (remaining_bitshifts) {
        auto it = first.base();
        // Don't take anything from the last.base()
        for (; std::next(it) != last.base(); ++it) {
            *it = _shrd<word_type>(*it, *std::next(it), remaining_bitshifts);
        }
        // For the penultimate word, 
        // take only the last.position() LSB digits from last_value
        *it = _shrd<word_type>(*it, 
                               last_value & ((1 << last.position()) - 1), 
                               remaining_bitshifts);
        // If last word is aligned, then we have nothing left to shift, 
        // and the end of the resulting range is at 
        // position=digits-remaining_bitshifts
        if (is_last_aligned) {
            d_last = bit_iterator<ForwardIt>(it, digits-remaining_bitshifts);
        } else { // Otherwise, last word is not aligned and needs to be shifted
            *it = (*it & ((1 << last.position()) -1)) >> remaining_bitshifts;
            if (remaining_bitshifts > last.position()) 
            {
                d_last = bit_iterator<ForwardIt>(it++, 
                            digits-(remaining_bitshifts - last.position())); 
            } else {
                d_last = bit_iterator<ForwardIt>(++it, 
                            last.position() - remaining_bitshifts);
            }
        }
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
    return d_last;
}

// ========================================================================== //
} // namespace bit

#endif // _SHIFT_LEFT_HPP_INCLUDED
// ========================================================================== //
