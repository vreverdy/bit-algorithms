// ============================ STABLE PARTITION ============================ //
// Project: The Experimental Bit Algorithms Library
// Name: stable_partition.hpp
// Description: bit_iterator overloads for std::stable_partition
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _STABLE_PARTITION_HPP_INCLUDED
#define _STABLE_PARTITION_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: on hold
template <class BidirIt, class UnaryPredicate>
bit_iterator<BidirIt> stable_partition(bit_iterator<BidirIt> first,
    bit_iterator<BidirIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class BidirIt, class UnaryPredicate>
bit_iterator<BidirIt> stable_partition(ExecutionPolicy&& policy,
    bit_iterator<BidirIt> first, bit_iterator<BidirIt> last, UnaryPredicate p) {
    (policy, first, last, p); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _STABLE_PARTITION_HPP_INCLUDED
// ========================================================================== //
