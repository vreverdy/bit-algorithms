// ============================ NEXT PERMUTATION ============================ //
// Project: The Experimental Bit Algorithms Library
// Name: next_permutation.hpp
// Description: bit_iterator overloads for std::next_permutation
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _NEXT_PERMUTATION_HPP_INCLUDED
#define _NEXT_PERMUTATION_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class BidirIt>
constexpr bool next_permutation(
        bit_iterator<BidirIt> first, 
        bit_iterator<BidirIt> last) {
    // Assertions
    _assert_range_viability(first, last);

    // Types and constants
    using word_type = typename bit_iterator<BidirIt>::word_type;
    using difference_type = typename bit_iterator<BidirIt>::difference_type;
    constexpr difference_type digits = binary_digits<word_type>::value;
    const word_type ones_mask = static_cast<word_type>(-1);

    // Deal with the case when there is no lexicographically larger permutation
    if (std::is_partitioned(first, last, [](const bit_value v) {
                return v;
            }
       )
    ) {
        auto first_zero_it = find(first, last, bit0);
        fill(first, first_zero_it, bit0);
        fill(last - distance(first, first_zero_it), last, bit1);
        return true;
    }


    if (is_within<digits>(first, last)) {
        difference_type m = distance(first, last);
        
        //Get relevant range, and set bits outside of the range to 0 
        word_type v = get_word<word_type>(first, m)
            & (ones_mask >> (digits - m));

        // Set all leading (least significant) 0s to 1s
        word_type t = v | ~(ones_mask >> _lzcnt(v));

        if (t == ones_mask) {
            std::cout << "cycle\n";
            write_word<word_type>(ones_mask >> ((digits - m) + _tzcnt(v)), first, m);
            return true;
        }

        word_type w = (t+1) | static_cast<word_type>(
                (static_cast<word_type>(~t & -~t) - 1) 
                >> (_tzcnt(v) + 1)
        );
        std::cout << w << std::endl;
        write_word<word_type>(w, first, m);
    }

    return false;
}

// Status: on hold
template <class BidirIt, class Compare>
constexpr bool next_permutation(bit_iterator<BidirIt> first, 
    bit_iterator<BidirIt> last, Compare comp) {
    (first, last, comp);
    return true;
} 

// ========================================================================== //
} // namespace bit

#endif // _NEXT_PERMUTATION_HPP_INCLUDED
// ========================================================================== //
