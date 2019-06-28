// ================================= ROTATE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: rotate.hpp
// Description: bit_iterator overloads for std::rotate
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _ROTATE_HPP_INCLUDED
#define _ROTATE_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
#include <list>
#include <forward_list>
// Project sources
#include "../ext/bit/bit.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //

template <class BidIt>
bit_iterator<BidIt> __rotate_via_reverse(
   bit_iterator<BidIt> first, 
   bit_iterator<BidIt> n_first,
   bit_iterator<BidIt> last,
   std::bidirectional_iterator_tag
) {
    bit::reverse(first, n_first);
    bit::reverse(n_first, last);
    bit::reverse(first, last);
    return first + std::distance(n_first, last);
}

template <class ForwardIt>
bit_iterator<ForwardIt> __rotate_via_copy_begin(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last
) {
    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using size_type = typename bit_iterator<ForwardIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;

    size_type k = distance(first, n_first);
    word_type copy_arr[3]; 
    copy_arr[0] = *first.base();
    ForwardIt it = ++first.base();
    short unsigned int pos = 1;
    short int bits_left_to_copy = k - (digits - first.position());
    while (bits_left_to_copy > 0) {
        copy_arr[pos++] = *it++;
        bits_left_to_copy -= digits;
    }
    bit_iterator<ForwardIt> ret = shift_left(first, last, k);
    std::copy(
        bit_iterator<word_type*>(copy_arr, first.position()), 
        bit_iterator<word_type*>(
                copy_arr, 
                first.position()
        ) + k,
        ret
    );
    return ret;
}

template <class ForwardIt>
bit_iterator<ForwardIt> __rotate_via_copy_end(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last
) {
    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using size_type = typename bit_iterator<ForwardIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;

    size_type k = distance(n_first, last);
    word_type copy_arr[3]; 
    copy_arr[0] = *n_first.base();
    ForwardIt it = ++n_first.base();
    short unsigned int pos = 1;
    short int bits_left_to_copy = k - (digits - n_first.position());
    while (bits_left_to_copy > 0) {
        copy_arr[pos++] = *it++;
        bits_left_to_copy -= digits;
    }
    bit_iterator<ForwardIt> ret = shift_right(first, last, k);
    std::copy(
        bit_iterator<word_type*>(copy_arr, n_first.position()), 
        bit_iterator<word_type*>(
                copy_arr, 
                n_first.position()
        ) + k,
        first
    );
    return ret;
}

template <class ForwardIt>
bit_iterator<ForwardIt> __rotate_via_raw(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last,
   std::forward_iterator_tag
) {
    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using difference_type = typename ForwardIt::difference_type;
    constexpr difference_type digits = binary_digits<word_type>::value;

    // Initialization
    bit_iterator<ForwardIt> first2 = n_first;
    ForwardIt it = std::next(first.base());

    // 1. Swap the first (last - n_first) bits to the correct position
    // CORRESPONDING GCC CODE:
    //  do {
    //      std::iter_swap(first, first2);
    //      ++first;
    //      ++first2;
    //      if (first == n_first)
    //          n_first = first2;
    //  } while (first2 != last);
    
    // 1a. Align first so that we are swapping a whole word
    first2 = std::swap_ranges(
            first,
            bit_iterator<ForwardIt>(it),
            first2
    );
    first = bit_iterator<ForwardIt>(it);

    // 1b. Swap chunks of size [digits] at a time, until no chunks remain.
    while (distance(first2, last) >= digits) {
        // Note 1b. If we swap past n_first, we need to update its location.
        if (distance(first, n_first) < digits) 
            n_first = first2 + distance(first, n_first);
        first2 = swap_ranges(
                first,
                first + digits,
                first2
        );
        first = bit_iterator<ForwardIt>(++it);
    }
    // 1c. Swap remaining chunk (which must be smaller than [digits]
    difference_type remainder = distance(first2, last);
    if (distance(first, n_first) <= remainder)
        n_first = first2 + distance(first, n_first);
    first2 = std::swap_ranges(
            first,
            first + remainder,
            first2
    );
    first += remainder;

    bit_iterator<ForwardIt> ret = first;
    first2 = n_first;

    // 2. At this point, positions first...first+(distance(n_first, last))
    // are correct. The subproblem is to now rotate on the current 
    // first, n_first, last
    //
    // We use the same strategy as above, with the change that now
    // when we encounter first2 == last in the loop, we set first2
    // to n_first. 
    //
    // 2a. See if we can use our rotates that simply copy and shift
    if (distance(first, n_first) <= 2*digits) {
        __rotate_via_copy_begin(first, n_first, last);
    } else if (distance(n_first, last) <= 2*digits) {
        __rotate_via_copy_end(first, n_first, last);
    } else {
        // 2b. Align the first iterator and use the same strategy as in 1b.
        // TODO instead of copying whole words every time as in 1b, we only
        // swap up to n_first or last, whichever occurs. This is because 
        // n_first and last can be in the same word. In order to avoid the
        // bookkeeping involved with updating both via one swap_ranges call, 
        // I've decided to just swap chunks that don't overlap with 
        // n_first or last (they can only start with n_first or last).
        // This may be slower, since we're not always doing full word swaps
        // anymore.
        //
        // CORRESPONDING GCC CODE:
        //  while (first2 != last) {
        //      std::iter_swap(first, first2);
        //      ++first;
        //      ++first2;
        //      if (first == n_first)
        //          n_first = first2;
        //      else if (first2 == last)
        //          first2 = n_first;
        //  }
        it = std::next(first.base());
        first2 = std::swap_ranges(
                first,
                bit_iterator<ForwardIt>(it),
                first2
        );
        first = bit_iterator<ForwardIt>(it);
        while (first2 != last) {
            if (distance(first, n_first) < digits) {
                if (distance(first2, last) < distance(first, n_first)) { 
                    // We reach the last iterator
                    remainder = distance(first2, last);
                    first2 = std::swap_ranges(
                            first,
                            first + distance(first2, last),
                            first2
                    );
                    first += remainder;
                    first2 = n_first;
                } else {
                    // We reach the n_first iterator
                    first2 = std::swap_ranges(
                            first,
                            first + distance(first, n_first),
                            first2
                    );
                    first += distance(first, n_first);
                    n_first = first2;
                }
            }
            else if (distance(first2, last) < digits) {
                // We reach the n_first iterator
                remainder = distance(first2, last);
                first2 = std::swap_ranges(
                        first,
                        first + distance(first2, last),
                        first2
                );
                first += remainder;
                first2 = n_first;
            }
            else {
                first2 = swap_ranges(
                        first,
                        first + digits,
                        first2
                );
                first = bit_iterator<ForwardIt>(++it);
            }
        }
    }
    return ret;
}

template <class ForwardIt>
bit_iterator<ForwardIt> rotate(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last
) {
    // Assertions
    _assert_range_viability(first, last);
    if (first == n_first) return n_first;

    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using size_type = typename bit_iterator<ForwardIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;

    // Initialization
    const bool is_first_aligned = first.position() == 0;
    //const bool is_n_first_aligned = n_first.position() == 0;
    const bool is_last_aligned = last.position() == 0;

    // Within the same word
    if (std::next(first.base(), is_last_aligned) == last.base()) {
        if (is_first_aligned && is_last_aligned) {
            *first.base() = 
                (*first.base() >> n_first.position())
                | 
                (*first.base() << (digits - n_first.position()));
            return std::next(first, digits - n_first.position());
        } else {
            size_type last_pos = is_last_aligned ? digits : last.position();
            size_type k = n_first.position() - first.position();
            size_type p = last_pos - n_first.position();
            size_type d = last_pos - first.position();
            
            word_type mask = ((1 << d) - 1) << first.position();
            word_type rotated = *first.base() & mask;
            rotated = (rotated << k) | (rotated >> p);
            *first.base() = _bitblend<word_type>(
                *first.base(),
                rotated,
                first.position(),
                d
            );
            return std::next(first, p);
        }
    }

    // Single word subcases 
    if (is_within(first, n_first, digits)) {
        size_type k = std::distance(first, n_first);
        word_type temp = get_word(first, k);
        bit_iterator<ForwardIt> new_last = shift_left(first, last, k);
        write_word<word_type, ForwardIt>(temp, new_last, static_cast<word_type>(k));
        return new_last;
    } else if (is_within(n_first, last, digits)) {
        size_type p = std::distance(n_first, last);
        word_type temp = get_word(n_first, p);
        auto new_last = shift_right(first, last, p);
        write_word(temp, first, static_cast<word_type>(p));
        return new_last;
    }
    return __rotate_via_raw(
            first, 
            n_first, 
            last,
            std::__iterator_category(first.base())
    );
}


// Status: to do
//template <class ForwardIt>
//constexpr bit_iterator<ForwardIt> rotate(bit_iterator<ForwardIt> first,
    //bit_iterator<ForwardIt> n_first, bit_iterator<ForwardIt> last) {
    //(n_first, last);
    //return first;
//}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> rotate(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> n_first,
    bit_iterator<ForwardIt> last) {
    (policy, n_first, last); 
    return first;
}

// ========================================================================== //
} // namespace bit
#endif // _ROTATE_HPP_INCLUDED
// ========================================================================== //
