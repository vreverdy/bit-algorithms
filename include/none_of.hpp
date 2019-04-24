// ================================ NONE OF ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: none_of.hpp
// Description: bit_iterator overloads for std::none_of
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _NONE_OF_HPP
#define _NONE_OF_HPP

namespace bit {

// TODO
template <class WrappedIt, class UnaryPredicate>
constexpr bool none_of(bit_iterator<WrappedIt> first, bit_iterator<WrappedIt> last,
    UnaryPredicate p) {

    first;
    last;
    p;

    return true;
}

// TODO
template <class ExecutionPolicy, class WrappedIt, class UnaryPredicate>
bool none_of(ExecutionPolicy&& policy, bit_iterator<WrappedIt> first,
    bit_iterator<WrappedIt> last, UnaryPredicate p) {
    
    policy;
    first;
    last;
    p;

    return true; 
}


} // namespace bit

#endif // _NONE_OF_HPP
