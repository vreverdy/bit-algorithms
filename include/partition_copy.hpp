// ============================= PARTITION COPY ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: partition_copy.hpp
// Description: bit_iterator overloads for std::partition_copy
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTITION_COPY_HPP_INCLUDED
#define _PARTITION_COPY_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //


// Status: on hold 
template <class InputIt, class OutputIt1, class OutputIt2, class UnaryPredicate>
constexpr std::pair<bit_iterator<OutputIt1>, bit_iterator<OutputIt2>>
    partition_copy(bit_iterator<InputIt> first, bit_iterator<InputIt> last,
    bit_iterator<OutputIt1> d_first_true, bit_iterator<OutputIt2> d_first_false,
    UnaryPredicate p) {
    (first, last, p);
    return std::make_pair(d_first_true, d_first_false);
}

// ========================================================================== //
} // namespace bit

#endif // _PARTITION_COPY_HPP_INCLUDED
// ========================================================================== //
