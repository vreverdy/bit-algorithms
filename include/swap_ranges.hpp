// ============================== SWAP RANGES ============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            swap_ranges.hpp
// Description:     bit_iterator overloads for std::swap_ranges
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _SWAP_RANGES_HPP_INCLUDED
#define _SWAP_RANGES_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "../ext/bit/bit.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //

template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges(
        bit_iterator<ForwardIt1> first1, 
        bit_iterator<ForwardIt1> last1,
        bit_iterator<ForwardIt2> first2) 
{
    // Assertions
    _assert_range_viability(first1, last1);

    // Types and constants
    using word_type1 = typename bit_iterator<ForwardIt1>::word_type;
    using word_type2 = typename bit_iterator<ForwardIt2>::word_type;
    using size_type1 = typename bit_iterator<ForwardIt1>::size_type;
    using size_type2 = typename bit_iterator<ForwardIt2>::size_type;
    constexpr size_type1 digits1 = binary_digits<word_type1>::value;
    constexpr size_type2 digits2 = binary_digits<word_type2>::value;

    // Initialization
    const bool is_first1_aligned = first1.position() == 0;
    const bool is_last1_aligned = last1.position() == 0;
    const bool is_first2_aligned = first2.position() == 0;
    //auto it = d_first.base();
    
    if constexpr (digits1 == digits2) {
        if (is_first1_aligned && is_first2_aligned) {

        } else if (first1.position() == first2.position()) {
            
        }
    }
    if (!is_first1_aligned) {
        if (std::next(first1.base(), is_last1_aligned) == last1.base()) {
            // TODO should we wuse something faster than distance?
            size_type1 total_bits_to_copy = std::distance(first1, last1); 
            
            // TODO We have two options, we can 
            // 1. Create a temporary variable for swapping
            // 2. Use ^ to swap with no temporary variable, but then we will
            //      need to restore the out of range bits as well.
        }
    }


}

// ========================================================================== //
} // namespace bit
#endif // _SWAP_RANGES_HPP_INCLUDED
// ========================================================================== //
