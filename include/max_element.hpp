// ============================== MAX ELEMENT ============================== //
// Project:        The Experimental Bit Algorithms Library
// Name:           max_element.hpp
// Description:    bit_iterator overloads for std::max_element
// Creator:        Vincent Reverdy 
// Contributor(s): Collin Gress [2019] 
// License:        BSD 3-Clause License
// ========================================================================== //
#ifndef _MAX_ELEMENT_HPP_INCLUDED
#define _MAX_ELEMENT_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> max_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {

    using word_type = typename bit_iterator<ForwardIt>::word_type;
    constexpr std::size_t num_digits = binary_digits<word_type>::value;

    ForwardIt word_cursor = first.base();

    // handle misaligned first word. for example ^00100^101
    if (!_is_aligned_lsb(first)) {

        // if 0 > 1 (version with comparators) we'll need to do this differently
        // maybe use _padded_read?
        word_type shifted_first_word = _shift_towards_lsb(*word_cursor, 
            first.position());

        if (shifted_first_word > 0) {
            std::size_t first_set_bit_position = _tzcnt(shifted_first_word);
            return first + first_set_bit_position;
        } 

        ++word_cursor;
    }

    while (word_cursor != last.base()) {
        word_type cur_word = *word_cursor;
        if (cur_word > 0) {
            std::size_t cur_set_bit_position = _tzcnt(cur_word);
            return bit_iterator(word_cursor, cur_set_bit_position);
        } 
        ++word_cursor;
    }

    if (last.position() == 0) {
        return first;
    }

    // final, incomplete word
    // if 0 > 1 (version with comparators) we'll need to do this differently
    word_type shifted_last_word = _shift_towards_msb(*word_cursor,
        num_digits - last.position()); 

    if (shifted_last_word > 0) {
        word_type last_set_bit_position = _tzcnt(shifted_last_word);
        return bit_iterator(word_cursor, last_set_bit_position 
            - (num_digits - last.position()));
    } 

    return first;
}

// Status: to do 
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> max_element(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, last);
    return first;
}

// Status: on hold
template <class ForwardIt, class Compare>
constexpr bit_iterator<ForwardIt> max_element(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (last, comp);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class Compare>
bit_iterator<ForwardIt> max_element(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, Compare comp) {
    (policy, last, comp);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _MAX_ELEMENT_HPP_INCLUDED
// ========================================================================== //
