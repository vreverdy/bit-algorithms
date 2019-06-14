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

// Just used for testing which rotate method is best
enum Method {REVERSE, STD, CPYPASTE};

// Helper function for rotate with RAIs. For some reason, the GCC 
// implementation does something way more complicated. I'm assuming the issue
// is that the algorithm below performs two writes per position, and we can do 
// better.
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
    std::forward_list<word_type> copy_list { *first.base() };
    short int bits_left_to_copy = k - (digits - first.position());
    using iterator_type = decltype(copy_list.begin());
    iterator_type pos = copy_list.begin();
    ForwardIt it = ++first.base();
    while (bits_left_to_copy > 0) {
        copy_list.insert_after(pos++, *(it++));  
        bits_left_to_copy -= digits;
    }
    bit_iterator<ForwardIt> ret = shift_left(first, last, k);
    std::copy(
        bit_iterator<iterator_type>(copy_list.begin(), first.position()), 
        bit_iterator<iterator_type>(
                copy_list.begin(), 
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
    std::forward_list<word_type> copy_list { *n_first.base() };
    short int bits_left_to_copy = k - (digits - n_first.position());
    using iterator_type = decltype(copy_list.begin());
    iterator_type pos = copy_list.begin();
    ForwardIt it = ++n_first.base();
    while (bits_left_to_copy > 0) {
        copy_list.insert_after(pos++, *(it++));  
        bits_left_to_copy -= digits;
    }
    bit_iterator<ForwardIt> ret = shift_right(first, last, k);
    copy(
        bit_iterator<iterator_type>(copy_list.begin(), n_first.position()), 
        bit_iterator<iterator_type>(
                copy_list.begin(), 
                n_first.position()
        ) + k,
        first
    );
    return ret;
}

template <class ForwardIt>
bit_iterator<ForwardIt> __rotate_via_std(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last
) {
    // Types and constants
    using word_type = typename bit_iterator<ForwardIt>::word_type;
    using size_type = typename bit_iterator<ForwardIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;


    // Initialization
    const bool is_first_aligned = first.position() == 0;
    const bool is_n_first_aligned = n_first.position() == 0;
    const bool is_last_aligned = last.position() == 0;

    bit_iterator<ForwardIt> ret;

    // Aligned case
    if (is_first_aligned && is_last_aligned) {
        // Rotate full words
        ret = bit_iterator<ForwardIt>(
                 std::rotate(first.base(), n_first.base(), last.base())
        );
        // Align n_first to first.position()
        if (!is_n_first_aligned) {
            word_type temp = *first.base();
            ret = shift_left(first, ret, n_first.position());
            bit_iterator<ForwardIt> new_last(
                    shift_left(ret, last, n_first.position())
            );
            *new_last.base() = _bitblend<word_type>(
                    *new_last.base(),
                    temp << new_last.position(),
                    static_cast<word_type>(-1) << new_last.position()
            );
        }
    } else {
        // Shiftable subcases
        // TODO do these help or hurt efficiency? 
        // TODO does the algorithm work without these cases?
        size_type k = std::distance(first, n_first);
        if (k <= 2 * digits) 
            return __rotate_via_copy_begin(first, n_first, last);
        size_type p = std::distance(n_first, last);
        if (p <= 2 * digits) 
            return __rotate_via_copy_end(first, n_first, last);
       
        // Rotate full words
        ForwardIt first_full_word = std::next(first.base(), !is_first_aligned);
        ForwardIt new_last = std::rotate(
                first_full_word, 
                n_first.base(), 
                last.base()
        );

        // Rotate results to construct final result
        // TODO better description here
        bit_iterator<ForwardIt> new_last_bit(new_last);
        ret = __rotate_via_copy_begin(
                first, 
                bit_iterator<ForwardIt>(first_full_word, n_first.position()),
                new_last_bit
        );
        __rotate_via_copy_begin(
                ret + (digits - first.position()),
                new_last_bit,
                bit_iterator<ForwardIt>(last.base())
        );
        ret = __rotate_via_copy_end(
                ret,
                bit_iterator<ForwardIt>(last.base()),
                last
        );
    }
    return ret;
}

template <class ForwardIt>
bit_iterator<ForwardIt> rotate(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last,
   Method method=REVERSE
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
    size_type k = std::distance(first, n_first);
    size_type p = std::distance(n_first, last);

    // Single word and half-range subcases 
    // TODO perhaps this would be better in the __rotate_via* functions?
    if (k <= digits) {
        word_type temp = get_word(first, k);
        bit_iterator<ForwardIt> new_last = shift_left(first, last, k);
        write_word<word_type, ForwardIt>(temp, new_last, static_cast<word_type>(k));
        return new_last;
    } else if (p <= digits) {
        word_type temp = get_word(n_first, p);
        auto new_last = shift_right(first, last, p);
        write_word(temp, first, static_cast<word_type>(p));
        return new_last;
    } else if (k == p) {
        swap_ranges(first, n_first, n_first);
        return n_first;
    }

    if (method == REVERSE) {
        return __rotate_via_reverse(
                first, 
                n_first, 
                last, 
                typename std::iterator_traits<ForwardIt>::iterator_category()
        );
    }
    if (method == STD) {
        return __rotate_via_std(
                first, 
                n_first, 
                last
        );
    }
    return first;
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
