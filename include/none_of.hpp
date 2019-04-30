// ================================ NONE OF ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: none_of.hpp
// Description: bit_iterator overloads for std::none_of
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _NONE_OF_HPP_INCLUDED
#define _NONE_OF_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class UnaryPredicate>
constexpr bool none_of(bit_iterator<InputIt> first, bit_iterator<InputIt> last,
    UnaryPredicate p) {
    (first, last, p); 
    return true;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bool none_of(ExecutionPolicy&& policy, ForwardIt first, ForwardIt last,
    UnaryPredicate p) {
    (policy, first, last, p);
    return true;
}

// ========================================================================== //
} // namespace bit

#endif // _NONE_OF_HPP_INCLUDED
// ========================================================================== //
