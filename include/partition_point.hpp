// ============================ PARTITION POINT ============================ //
// Project: The Experimental Bit Algorithms Library
// Name: partition_point.hpp
// Description: bit_iterator overloads for std::partition_point
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTITION_POINT_HPP_INCLUDED
#define _PARTITION_POINT_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: on hold
template <class ForwardIt, class UnaryPredicate>
constexpr bit_iterator<ForwardIt> partition_point(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}



// ========================================================================== //
} // namespace bit

#endif // _PARTITION_POINT_HPP_INCLUDED
// ========================================================================== //
