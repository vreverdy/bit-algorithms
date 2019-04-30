// ================================= ANY OF ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: any_of.hpp
// Description: bit_iterator overloads for std::any_of
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ANY_OF_HPP_INCLUDED
#define _ANY_OF_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class UnaryPredicate>
constexpr bool any_of(bit_iterator<InputIt> first, bit_iterator<InputIt> last,
    UnaryPredicate p) {
    (first, last, p);
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
constexpr bool any_of(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, UnaryPredicate p) {
    (policy, first, last, p);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _ANY_OF_HPP_INCLUDED
// ========================================================================== //
