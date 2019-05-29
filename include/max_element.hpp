// ============================== MAX ELEMENT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: max_element.hpp
// Description: bit_iterator overloads for std::max_element
// Creator: Vincent Reverdy 
// Contributor(s): Collin Gress [2019] 
// License: BSD 3-Clause License
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

    bit_iterator<ForwardIt> cursor = first;

    // handle misaligned first word. for example ^00100^101
    if (!_is_aligned_lsb(cursor)) {
        word_type first_word = _padded_read(cursor, last, bit::bit0);
        if (first_word > 0) {
            std::size_t first_set_bit_position = _tzcnt(first_word);
            return cursor + (first_set_bit_position - cursor.position());
        }

        if (_in_same_word(cursor, last) ||
            _is_one_past_last_bit(last, cursor.base())) {
            return first;
        }

        cursor = bit_iterator(std::next(cursor.base()));
    }

    // full words
    while (!_in_same_word(cursor, last) ||
        _is_one_past_last_bit(last, cursor.base())) {
        word_type cur_word = *(cursor.base());
        if (cur_word > 0) {
            std::size_t cur_set_bit_position = _tzcnt(cur_word);
            return cursor + (cur_set_bit_position - cursor.position());
        }
        cursor = bit_iterator(std::next(cursor.base()));
    }

    if (cursor == last) {
        return first;
    }

    // final, incomplete word
    word_type last_word = _padded_read(cursor, last, bit::bit0);
    if (last_word > 0) {
        word_type last_set_bit_position = _tzcnt(last_word);
        return cursor + (last_set_bit_position - cursor.position());
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
