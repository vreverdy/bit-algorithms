// ========================== ADJACENT DIFFERENCE ========================== //
// Project: The Experimental Bit Algorithms Library
// Name: adjacent_difference.hpp
// Description: bit_iterator overloads for std::adjacent_difference
// Creator: Vincent Reverdy
// Contributor(s): Vincent Reverdy [2019]
//                 Collin Gress [2019]
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ADJACENT_DIFFERENCE_HPP
#define _ADJACENT_DIFFERENCE_HPP

namespace bit {

// TODO
template <class WrappedIt, class OutputIt>
OutputIt adjacent_difference(bit_iterator<WrappedIt> first, 
    bit_iterator<WrappedIt> last, OutputIt d_first) {

    first;
    last;
    d_first;

    return d_first;
}  

// TODO
template <class ExecutionPolicy, class WrappedIt, class ForwardIt>
ForwardIt adjacent_difference(ExecutionPolicy&& policy, 
    bit_iterator<WrappedIt> first, bit_iterator<WrappedIt> last,
    ForwardIt d_first) {

    policy;
    first;
    last;
    d_first;

    return d_first;
}

// TODO
template <class WrappedIt, class OutputIt, class BinaryOperation>
constexpr OutputIt adjacent_difference(bit_iterator<WrappedIt> first,
    bit_iterator<WrappedIt> last, OutputIt d_first, BinaryOperation op) {

    first;
    last;
    d_first;
    op;

    return d_first; 
}

// TODO
template <class ExecutionPolicy, class WrappedIt, class ForwardIt,
          class BinaryOperation>
ForwardIt adjacent_difference(ExecutionPolicy&& policy,
    bit_iterator<WrappedIt> first, bit_iterator<WrappedIt> last,
    ForwardIt d_first, BinaryOperation op) {

    policy;
    first;
    last;
    d_first;
    op;

    return d_first;
}


} // namespace bit

#endif // _ADJACENT_DIFFERENCE_HPP
