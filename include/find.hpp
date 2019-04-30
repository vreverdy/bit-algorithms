// ================================== FIND ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: find.hpp
// Description: bit_iterator overloads for std::find, std::find_if, std::find_if_not
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _FIND_HPP_INCLUDED
#define _FIND_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class T>
constexpr bit_iterator<InputIt> find(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, const T& value) {
    (last, value);
    return first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class T>
bit_iterator<ForwardIt> find(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, const T& value) {
    (policy, last, value);
    return first;
}

// TODO
template <class InputIt, class UnaryPredicate>
constexpr bit_iterator<InputIt> find_if(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, UnaryPredicate p) {
    (last, p);
    return first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> find_if(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    UnaryPredicate p) {
    (policy, last, p);
    return first;
}

// TODO
template <class InputIt, class UnaryPredicate>
constexpr bit_iterator<InputIt> find_if_not(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, UnaryPredicate q) {
    (last, q);
    return first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt, class UnaryPredicate>
bit_iterator<ForwardIt> find_if_not(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    UnaryPredicate q) {
    (policy, last, q); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _FIND_HPP_INCLUDED
// ========================================================================== //
