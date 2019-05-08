// =============================== IS SORTED =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: is_sorted.hpp
// Description: bit_iterator overloads for std::is_sorted
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_SORTED_HPP_INCLUDED
#define _IS_SORTED_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt>
constexpr bool is_sorted(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last) {

    using word_type = typename bit_iterator<ForwardIt>::word_type;
    std::size_t num_digits = binary_digits<word_type>::value;
    
    bit_iterator<ForwardIt> cursor = first;
    bool has_seen_1 = false;

    while (cursor != last) {
        std::size_t bits_to_read = std::min(static_cast<std::size_t>(last - cursor), 
            binary_digits<word_type>::value);

        word_type cur = get_word(cursor, bits_to_read); 

        std::size_t leading_zero_ct = _tzcnt(cur);

        if (has_seen_1) {
            if (leading_zero_ct > 0) {
                return false;
            }        
        } else {
            if (leading_zero_ct < num_digits) {
                has_seen_1 = true;    

                if ((cur >> leading_zero_ct) != 
                    (static_cast<word_type>(-1) >> leading_zero_ct)) {
                    return false;
                } 
            }
        }
        std::advance(cursor, bits_to_read);
    }

    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt>
bool is_sorted(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (policy, first, last);
    return true;
}

// TODO
template <class ForwardIt, class Compare>
constexpr bool is_sorted(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (first, last, comp);
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class Compare>
bool is_sorted(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Compare comp) {
    (policy, first, last, comp);
    return true;
}


// ========================================================================== //
} // namespace bit

#endif // _IS_SORTED_HPP_INCLUDED
// ========================================================================== //
