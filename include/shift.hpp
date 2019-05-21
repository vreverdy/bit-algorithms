// ================================ SHIFT ================================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            shift.hpp
// Description:     Implementation of shift_left and shift_right 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _SHIFT_HPP_INCLUDED
#define _SHIFT_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// --------------------------- Shift Algorithms ----------------------------- //
template <class ForwardIt>
bit_iterator<ForwardIt> shift_right(bit_iterator<ForwardIt> first,
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
    word_type first_value = *first.base();
    word_type last_value = !is_last_aligned ? *last.base() : 0;
    word_type mask = is_first_aligned ? 
        static_cast<word_type>(-1)
        : 
        static_cast<word_type>(
                (static_cast<word_type>(1) << (digits - first.position())) - 1
        ) << first.position();
    *first.base() = *first.base() & mask;
    ForwardIt it = word_shift_right(first.base(), 
                               std::next(last.base(), 
                                         !is_last_aligned
                                         ),
                               word_shifts
    );
    bit_iterator<ForwardIt> d_first(it, first.position());
    // Shift bit sequence to the msb 
    if (remaining_bitshifts) {
        word_type temp_1 = *it;
        word_type temp_2;
        *it = *it << remaining_bitshifts;
        it++;
        //TODO probably a way to do this with 1 temp or
        // at least no value swapping
        for (; it != std::next(last.base(), !is_last_aligned); ++it) {
            temp_2 = *it;
            *it = _shld<word_type>(*it, temp_1, remaining_bitshifts);
            temp_1 = temp_2; 
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
    std::advance(first, remaining_bitshifts);
    return first;
}

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
    word_type first_value = *first.base();
    word_type last_value = !is_last_aligned ? *last.base() : 0;

    // Shift words to the left using std::shift 
    ForwardIt new_last_base = word_shift_left(first.base(), 
                                         last.base(), 
                                         word_shifts
    );
    // Mask out-of-range bits so that we don't incorporate them
    if (!is_last_aligned) {
        *new_last_base &= (static_cast<word_type>(1) << last.position()) - 1; 
    }
    bit_iterator<ForwardIt> d_last(new_last_base, last.position());
    // Shift bit sequence to the lsb 
    if (remaining_bitshifts) {
        ForwardIt it = first.base();
        // Desired last iterator may be one before the current last 
        // so we need to keep track of the penultimate iterator.
        ForwardIt latent_it = it;
        // _shrd all words except the last
        for (; std::next(it, is_last_aligned) != new_last_base; ++it) {
            *it = _shrd<word_type>(*it, *std::next(it), remaining_bitshifts);
            latent_it = it;
        }
        // For the last word simpy right shift
        *it >>= remaining_bitshifts;

        if (is_last_aligned) {
            d_last = bit_iterator<ForwardIt>(it, digits-remaining_bitshifts);
        } else { // Otherwise, last word may be the word before new_last_word
            if (remaining_bitshifts > last.position()) 
            {
                d_last = bit_iterator<ForwardIt>(latent_it, 
                            digits-(remaining_bitshifts - last.position())); 
            } else {
                d_last = bit_iterator<ForwardIt>(it, 
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
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _SHIFT_HPP_INCLUDED
// ========================================================================== //
