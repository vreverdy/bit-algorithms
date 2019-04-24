// ============================= ADJACENT FIND ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: adjacent_find.hpp
// Description: bit_iterator overloads for std::adjacent_find
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ADJACENT_FIND_HPP
#define _ADJACENT_FIND_HPP

namespace bit {

// TODO
template <class WrappedIt>
constexpr bit_iterator<WrappedIt> adjacent_find(WrappedIt first, WrappedIt last) {

    first;
    last;

    return first;
}

// TODO
template <class ExecutionPolicy, class WrappedIt>
bit_iterator<WrappedIt> adjacent_find(ExecutionPolicy&& policy,
    bit_iterator<WrappedIt> first, bit_iterator<WrappedIt> last) {

    policy;
    first;
    last;

    return first;
}

// TODO
template <class WrappedIt, class BinaryPredicate>
constexpr bit_iterator<WrappedIt> adjacent_find(bit_iterator<WrappedIt> first,
    bit_iterator<WrappedIt> last, BinaryPredicate p) {

    first;
    last;
    p;

    return first;
}

// TODO
template <class ExecutionPolicy, class WrappedIt, class BinaryPredicate>
bit_iterator<WrappedIt> adjacent_find(ExecutionPolicy&& policy,
    bit_iterator<WrappedIt> first, bit_iterator<WrappedIt> last,
    BinaryPredicate p) {

    policy;
    first;
    last;
    p;

    return first; 
}

} // namespace bit

#endif // _ADJACENT_FIND_HPP
