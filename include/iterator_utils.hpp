// ========================== iterator_utils.hpp ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: iterator_utils.hpp
// Description: Implementation of iterator-related utilities not present in 
// 		algorithms header.
// Creator: Bryce Kille
// Contributor: Bryce Kille [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ITERATOR_UTILS_HPP_INCLUDED
#define _ITERATOR_UTILS_HPP_INCLUDED
#pragma once
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
// Project sources
#include "bit.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// -------------------------- Iterator Algorithms --------------------------- //
// Returns the number of increments needed to get to last from first. 
// May be negative if last comes before first (Only when input is RAI)
template <class InputIt>
typename bit_iterator<InputIt>::difference_type distance(bit_iterator<InputIt> first,
                                                         bit_iterator<InputIt> last
)
{
    //_assert_range_viability(first, last); 
    //TODO should _assert_range_viability work for reverse ranges as well?
    using word_type = typename bit_iterator<InputIt>::word_type;
    using size_type = typename bit_iterator<InputIt>::size_type;
    constexpr size_type digits = binary_digits<word_type>::value;
    return std::distance(first.base(), last.base())*digits 
           + (last.position() - first.position());
}

// Increments the iterator n times. (If n is negative, the iterator is decremented n times)
template <class InputIt, class Distance>
void advance(bit_iterator<InputIt>& first,
             Distance n
)
{
    first += n;    
}
// -------------------------------------------------------------------------- //



// ========================================================================== //
} // namespace bit
#endif // _ITERATOR_UTILS_HPP_INCLUDED
// ========================================================================== //
