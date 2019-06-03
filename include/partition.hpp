// =============================== PARTITION =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: partition.hpp
// Description: bit_iterator overloads for std::partition
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTITION_HPP_INCLUDED
#define _PARTITION_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> partiion(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> partition(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    UnaryPredicate p) {
    (policy, last, p);
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _PARTITION_HPP_INCLUDED
// ========================================================================== //
