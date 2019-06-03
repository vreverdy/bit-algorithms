// ================================= ROTATE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: rotate.hpp
// Description: bit_iterator overloads for std::rotate
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _ROTATE_HPP_INCLUDED
#define _ROTATE_HPP_INCLUDED
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
#include "../ext/bit/bit.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //

// Helper function for rotate with RAIs. For some reason, the GCC 
// implementation does something way more complicated. I'm assuming the issue
// is that the algorithm below performs two writes per position, and we can do 
// better.
//
template <class RandomAccessIt>
bit_iterator<RandomAccessIt> __rotate(
   bit_iterator<RandomAccessIt> first, 
   bit_iterator<RandomAccessIt> n_first,
   bit_iterator<RandomAccessIt> last,
   std::random_access_iterator_tag
) {
    std::reverse(first, n_first);
    std::reverse(n_first, last);
    std::reverse(first, last);
    return first + (last-n_first);
}

template <class ForwardIt>
bit_iterator<ForwardIt> rotate(
   bit_iterator<ForwardIt> first, 
   bit_iterator<ForwardIt> n_first,
   bit_iterator<ForwardIt> last
) {
    return __rotate(
            first, 
            n_first, 
            last, 
            typename std::iterator_traits<ForwardIt>::iterator_category()
    );
}

// ========================================================================== //
} // namespace bit
#endif // _ROTATE_HPP_INCLUDED
// ========================================================================== //
