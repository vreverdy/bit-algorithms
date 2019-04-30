// ============================= INCLUSIVE SCAN ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: inclusive_scan.hpp
// Description: bit_iterator overloads for std::inclusive_scan
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _INCLUSIVE_SCAN_HPP_INCLUDED
#define _INCLUSIVE_SCAN_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class OutputIt>
bit_iterator<OutputIt> inclusive_scan(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first) {
    (first, last);
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> inclusive_scan(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> d_first) {
    (policy, first, last);
    return d_first;
}

// TODO
template <class InputIt, class OutputIt, class BinaryOperation>
bit_iterator<OutputIt> inclusive_scan(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first,
    BinaryOperation binary_op) {
    (first, last, binary_op);
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class BinaryOperation> bit_iterator<ForwardIt2> inclusive_scan (
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first,
    BinaryOperation binary_op) {
    (policy, first, last, binary_op); 
    return d_first; 
}

// TODO
template <class InputIt, class OutputIt, class BinaryOperation, class T>
bit_iterator<OutputIt> inclusive_scan(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first,
    BinaryOperation binary_op, T init) {
    (first, last, binary_op, init); 
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class BinaryOperation, class T> bit_iterator<ForwardIt2> inclusive_scan (
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first,
    BinaryOperation binary_op, T init) {
    (policy, first, last, binary_op, init); 
    return d_first;
}

// ========================================================================== //
} // namespace bit

#endif // _INCLUSIVE_SCAN_HPP_INCLUDED
// ========================================================================== //
