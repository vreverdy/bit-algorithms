// ============================= IS PARTITIONED ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: is_partitioned.hpp
// Description: bit_iterator overloads for std::is_partitioned
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IS_PARTITIONED_HPP_INCLUDED
#define _IS_PARTITIONED_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class UnaryPredicate>
constexpr bool is_partitioned(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, UnaryPredicate p) {
    (first, last, p);
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bool is_partitioned(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (policy, first, last, p);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _IS_PARTITIONED_HPP_INCLUDED
// ========================================================================== //
