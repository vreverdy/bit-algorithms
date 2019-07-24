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

    // Out of range cases
    if (n <= 0) return first;
    else if (n >= d) return last;

    // Single word case
    if (first.base() == last.base()) {
        *first.base() = _bitblend<word_type>(
                *first.base(),
                (
                    *first.base() & (
                        static_cast<word_type>(-1) << first.position()
                    )
                ) << n,
                first.position(),
                last.position() - first.position()
        );
        return bit_iterator<ForwardIt>(
                first.base(), 
                first.position() +  n
        );
    }

    // Multiple word case
    word_type first_value = *first.base();
    word_type last_value = !is_last_aligned ? *last.base() : 0;
    word_type mask = is_first_aligned ? 
        static_cast<word_type>(-1)
        : 
        static_cast<word_type>(
                (static_cast<word_type>(1) << (digits - first.position())) - 1
        ) << first.position();
    *first.base() = *first.base() & mask;
    // Shift words to the right
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
    std::advance(d_first, remaining_bitshifts);
    return d_first;
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

    // Out of range cases
    if (n <= 0) return last;
    if (n >= d) return first;


    // Single word case
    if (first.base() == last.base()) {
        *first.base() = _bitblend<word_type>(
                *first.base(),
                ((
                    *first.base() & (
                        static_cast<word_type>(-1) >> (
                            digits - last.position()
                        )
                    )
                )) >> n,
                first.position(),
                last.position() - first.position()
        );
        return bit_iterator<ForwardIt>(
                first.base(), 
                first.position() + d - n
        );
    }

    word_type first_value = *first.base();
    word_type last_value = !is_last_aligned ? *last.base() : 0;

    // Shift words to the left using std::shift 
    // Mask out-of-range bits so that we don't incorporate them
    if (!is_last_aligned) {
        *last.base() &= (static_cast<word_type>(1) << last.position()) - 1; 
    }
    ForwardIt new_last_base = word_shift_left(first.base(), 
                                    last.base(),
                                    word_shifts
    );
    if (!is_last_aligned) {
        *new_last_base = *last.base();
    }
    // Shift bit sequence to the lsb 
    if (remaining_bitshifts) {
        ForwardIt it = first.base();
        // _shrd all words except the last
        for (; std::next(it, is_last_aligned) != new_last_base; ++it) {
            *it = _shrd<word_type>(*it, *std::next(it), remaining_bitshifts);
            //latent_it = it;
        }
        // For the last word simpy right shift
        *it >>= remaining_bitshifts;
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
    //TODO is this more or less inefficient than having a latent iterator?
    bit_iterator<ForwardIt> d_last = next(first, d-n);
    return d_last;
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _SHIFT_HPP_INCLUDED
// ========================================================================== //
