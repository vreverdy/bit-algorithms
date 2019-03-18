#pragma once

#include "bit.hpp"

namespace bit {

template <class InputIt, class AssignmentType>
bit_iterator<InputIt> assign(bit_iterator<InputIt> first,
                             AssignmentType input_word,
                             AssignmentType input_mask
)
{
    using native_word_type = typename bit_iterator<InputIt>::word_type;
    using size_type = typename bit_iterator<InputIt>::size_type;
    constexpr size_type native_digits = binary_digits<native_word_type>::value; 
    constexpr size_type assignment_digits = binary_digits<AssignmentType>::value; 
    native_word_type* it = first.base();
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
        if (_popcnt(current_mask) == _popcnt(input_mask)) {
            return first + _popcnt(input_mask);
        }
    }
    // For native_word_type #i, we want to assign [input_word[offset+i*native_digits], input_word[offset+(i+1)*native_digits)
    // Which means the last bit we care about is at index = offset+(i+1)*native_digits - 1
    // Therefore at each step we need to right shift input_word by shift = assignment_digits - (offset+(i+1)*native_digits)\
    // If shift < 0, then we actually have to left shift by shift, not right.
    oversized = native_digits < assignment_digits;
    //shift_size =  (assignment_digits - native_digits)*oversized;
    unsigned int current_idx = 0;
    do {
        shift_size = (assignment_digits - (offset + (current_idx+1)*native_digits));
        if (shift_size < 0) {
            current_assignment = input_word << shift_size; 
            current_mask = input_mask << shift_size;
        } else {
            current_assignment = input_word >> shift_size; 
            current_mask = input_mask >> shift_size;
        } 
        *it = _bitblend(*it,
                        current_assignment,
                        current_mask
        );
        ++it;
        ++current_idx;
    } while (shift_size > 0 || it == first.base()); 
    return first + _popcnt(input_word);
}

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

    // Copy within word
    in_word_type current_word = *first.base();
    in_word_type current_mask = -1;
    bit_iterator<OutputIt> d_first_ret = d_first; 

    // Assign suffix of first word in range if not aligned
    if (first.position() != 0) {
        current_mask >>= first.position();
        current_word >>= first.position();
    }
    if (std::next(first.base(), is_last_aligned) == last.base()) { // Copy within same word
        current_mask >>= (in_digits - last.position())*(!is_last_aligned); 
        return assign(d_first, current_word, current_mask); 
    }
    d_first_ret = assign(d_first, current_word, current_mask); 
    InputIt it = std::next(first.base());

    // Assign all full words
    for (; it != last.base(); it++){
        current_word = *it;
        current_mask = -1;
        d_first_ret = assign(d_first_ret, current_word, current_mask);
    }
    // Assign the last partial word in the range. 
    if (!is_last_aligned) {
        current_word = *it;
        current_mask = -1 >> (in_digits - last.position());
        d_first_ret = assign(d_first_ret, current_word, current_mask);
    }
    return d_first_ret;
    
}

}
