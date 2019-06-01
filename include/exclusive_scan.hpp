// ============================= EXCLUSIVE SCAN ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: exclusive_scan.hpp
// Description: bit_iterator overloads for std::exclusive_scan
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _EXCLUSIVE_SCAN_HPP_INCLUDED
#define _EXCLUSIVE_SCAN_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: will not implement?
template <class InputIt, class OutputIt, class T>
bit_iterator<OutputIt> exclusive_scan(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first, T init) {
    (first, last, init);
    return d_first;
}

// Status: will not implement?
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2, class T>
bit_iterator<ForwardIt2> exclusive_scan(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> d_first, T init) {
    (policy, first, last, init); 
    return d_first;
}

// Status: on hold
template <class InputIt, class OutputIt, class T, class BinaryOperation>
bit_iterator<OutputIt> exclusive_scan(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first, T init,
    BinaryOperation binary_op) {
    (first, last, init, binary_op);
    return d_first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2, class T,
    class BinaryOperation> bit_iterator<ForwardIt2> exclusive_scan(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first, T init,
    BinaryOperation binary_op) {
    (policy, first, last, d_first, init, binary_op); 
    return d_first;
}

// ========================================================================== //
} // namespace bit

#endif // _EXCLUSIVE_SCAN_HPP_INCLUDED
// ========================================================================== //
