// ============================= INPLACE MERGE ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: inplace_merge.hpp
// Description: bit_iterator overloads for std::inplace_merge
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INPLACE_MERGE_HPP_INCLUDED
#define _INPLACE_MERGE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class BidirIt>
void inplace_merge(bit_iterator<BidirIt> first, bit_iterator<BidirIt> middle,
    bit_iterator<BidirIt> last) {
    (first, middle, last);
}

// TODO
template <class ExecutionPolicy, class BidirIt>
void inplace_merge(ExecutionPolicy&& policy, bit_iterator<BidirIt> first,
    bit_iterator<BidirIt> middle, bit_iterator<BidirIt> last) {
    (policy, first, middle, last);
}

// TODO
template <class BidirIt, class Compare>
void inplace_merge(bit_iterator<BidirIt> first, bit_iterator<BidirIt> middle,
    bit_iterator<BidirIt> last, Compare comp) {
    (first, middle, last, comp);
}

// TODO
template <class ExecutionPolicy, class BidirIt, class Compare>
void inplace_merge(ExecutionPolicy&& policy, bit_iterator<BidirIt> first,
    bit_iterator<BidirIt> middle, bit_iterator<BidirIt> last, Compare comp) {
    (policy, first, middle, last, comp);
}

// ========================================================================== //
} // namespace bit

#endif // _INPLACE_MERGE_HPP_INCLUDED
// ========================================================================== //
