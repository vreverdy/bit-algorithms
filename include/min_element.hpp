// ============================== MIN ELEMENT ============================== //
// Project:     The Experimental Bit Algorithms Library
// Name:        min_element.hpp
// Description: bit_iterator overloads for std::min_element
// Creator:     Vincent Reverdy
// Contributor(s): Collin Gress [2019] 
// License:     BSD 3-Clause License
// ========================================================================== //
#ifndef _MIN_ELEMENT_HPP_INCLUDED
#define _MIN_ELEMENT_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// Status: complete 
template <class ForwardIt>
constexpr bit_iterator<ForwardIt> min_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {

    using word_type = typename bit_iterator<ForwardIt>::word_type;
    constexpr std::size_t num_digits = binary_digits<word_type>::value;

    ForwardIt word_cursor = first.base();
    word_type mask;
    word_type all_ones = _all_ones();

    // handle case ^1101^0101 and 1^101^0101
    if (!_is_aligned_lsb(first)) {
        std::size_t start_position = first.position();

        // 1^101^0101
        if (last.base() == word_cursor) {
            mask = _shift_towards_lsb(all_ones, num_digits - start_position); 
            mask |= _shift_towards_msb(all_ones, last.position());
            // fill bits outside of [first, last) with 1s
            word_type masked_first_word = *word_cursor | mask;
            if (masked_first_word < all_ones) {
                std::size_t first_unset_bit_position = _tzcnt<word_type>(~masked_first_word);
                return first + (first_unset_bit_position - start_position);
            }
            return first; // no zeros in range
        }

        mask = _shift_towards_lsb(all_ones, num_digits - start_position);
        word_type masked_first_word = *word_cursor | mask; 

        if (masked_first_word < all_ones) {
            std::size_t first_unset_bit_position = _tzcnt<word_type>(~masked_first_word);
            return first + (first_unset_bit_position - start_position); 
        }

        ++word_cursor;
    }

    while (word_cursor != last.base()) {
        word_type cur_word = *word_cursor;
        if (cur_word < all_ones) {
            std::size_t cur_unset_bit_position = _tzcnt<word_type>(~cur_word);
            return bit_iterator(word_cursor, cur_unset_bit_position);
        }
        ++word_cursor;
    }

    if (last.position() == 0) {
        return first;
    }

    mask = _shift_towards_msb(all_ones, last.position());
    word_type masked_last_word = *word_cursor | mask; 

    if (masked_last_word < all_ones) {
      std::size_t last_set_bit_position = _tzcnt<word_type>(~masked_last_word);
      return bit_iterator(word_cursor, last_set_bit_position);
    }

    return first;
}

// Status: to do 
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> min_element(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, last);
    return first;
}

// Status: on hold 
template <class ForwardIt, class Compare>
constexpr bit_iterator<ForwardIt> min_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (last, comp);
    return first;
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt, class Compare>
bit_iterator<ForwardIt> min_element(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, Compare comp) {
    (policy, last, comp);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _MIN_ELEMENT_HPP_INCLUDED
// ========================================================================== //
