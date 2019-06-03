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
    auto it1 = first1.base();
    auto it2 = first2.base();
    
    if constexpr (digits1 == digits2) {
        // All bits in first1 range are in 1 word
        if (std::next(it1, is_last1_aligned) == last1.base()) {
            size_type1 digits_to_copy = is_last1_aligned ? 
                digits1 - first1.position()
                : 
                last1.position() - first1.position()
            ;// Not really sure what proper formatting here is.
            if (first1.position() >= first2.position()) {
                _bitexch(
                        it1, 
                        it2, 
                        first1.position(), 
                        first2.position(),
                        digits_to_copy
                );
            } else {
                size_type1 partial_digits_to_copy = std::max(
                        digits_to_copy,
                        digits2 - first2.position()
                );
                _bitexch(
                        it1, 
                        it2, 
                        first1.position(), 
                        first2.position(),
                        partial_digits_to_copy
                );
                if (digits_to_copy > partial_digits_to_copy) {
                    _bitexch(
                            it1, 
                            ++it2, 
                            first1.position() + partial_digits_to_copy, 
                            0,
                            digits_to_copy - partial_digits_to_copy
                    );
                }
            }
            return first2 + digits_to_copy;

        // first1 range spans multiple words, 
        // but both ranges have same alignment    
        } else if (first1.position() == first2.position()) {
            _bitexch(*it1++, *it2++, first1.position());
            while (std::next(it1, is_last1_aligned) != last1.base()) {
                std::swap(*it1++, *it2++);
            }
            if (!is_last1_aligned) {
                _bitexch(*it1, *it2, last1.position());
            }
            return bit_iterator<ForwardIt1>(it2, last1.position());

        // first1 range spans mutliple words and is not aligned with first2
        } else {
            // 1. Align first1
            size_type1 digits_to_copy = digits1 - first1.position();
            if (first1.position() >= first2.position()) {
                _bitexch(
                        it1, 
                        it2, 
                        first1.position(), 
                        first2.position(),
                        digits_to_copy
                );
            } else {
                size_type1 partial_digits_to_copy = digits2 - first2.position();
                _bitexch(
                        it1, 
                        it2++, 
                        first1.position(), 
                        first2.position(),
                        partial_digits_to_copy
                );
                _bitexch(
                        it1++, 
                        it2, 
                        first1.position() + partial_digits_to_copy, 
                        0,
                        digits_to_copy - partial_digits_to_copy
                );
                first2 += digits_to_copy;
            }
            digits_to_copy = digits2 - first2.position();
            // 2. Exchange full words
            while (std::next(it1, is_last1_aligned) != last1.base()) {
                _bitexch(
                        it1,
                        it2++,
                        0,
                        first2.position(),
                        digits_to_copy
                );
                _bitexch(
                        it1++,
                        it2,
                        digits_to_copy,
                        0,
                        digits1 - digits_to_copy
                );
            }
            // Exchange last partial words
            if (!is_last1_aligned) {
                size_type2 partial_digits_to_copy = digits2 - first2.position();
                if (last1.position() <= partial_digits_to_copy) {
                    _bitexch(
                            it1,
                            it2,
                            0,
                            first2.position(),
                            last1.position()
                    );
                    return bit_iterator(it2, first2.position() + last1.position());
                } else {
                    _bitexch(
                            it1,
                            it2++,
                            0,
                            first2.position(),
                            partial_digits_to_copy
                    );
                    _bitexch(
                            it1,
                            it2,
                            partial_digits_to_copy,
                            0,
                            last1.position() - partial_digits_to_copy
                    );
                    return bit_iterator(it2, last1.position() - partial_digits_to_copy);
                }
            }
            return bit_iterator(it2, digits1 - digits_to_copy);
        }
    }
}

// ========================================================================== //
} // namespace bit
#endif // _SWAP_RANGES_HPP_INCLUDED
// ========================================================================== //
