// ================================= FILL =================================== //
// Project: The Experimental Bit Algorithms Library
// Name: fill.hpp
// Description: bit_iterator overloads for std::fill 
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FILL_HPP_INCLUDED
#define _FILL_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "bit_algorithm_details.hpp"
// Third-party libraries
// Miscellaneous

namespace bit {

template <class ForwardIt>
void fill(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, 
    bit::bit_value bv) {
    bit_iterator<ForwardIt> cur = first;

    using word_type = typename bit_iterator<ForwardIt>::word_type;
    constexpr std::size_t num_digits = bit::binary_digits<word_type>::value;

    while (cur != last) {
        if (last - cur >= num_digits) { // at least a full word remains
            if (bv == bit1) {
                *(cur.base()) = -1;
            } else {
                *(cur.base()) = 0;
            }
        } else {
            set_in_range(cur, last - 1, cur.base(), bv);
            cur = last;
        }
    }
}

// TODO
template <class ExecutionPolicy, class ForwardIt>
void fill(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, const bit_value& bv) {
    (policy, first, last, bv);
}


// ========================================================================== //
} // namespace bit

#endif // _FILL_HPP_INCLUDED
// ========================================================================== //
