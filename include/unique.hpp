// ================================= UNIQUE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: unique.hpp
// Description: bit_iterator overloads for std::unique
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _UNIQUE_HPP_INCLUDED
#define _UNIQUE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt>
constexpr bit_iterator<ForwardIt> unique(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (last);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> unique(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, last);
    return first;
}

// Status: on hold 
template <class ForwardIt, class BinaryPredicate>
constexpr bit_iterator<ForwardIt> unique(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, BinaryPredicate p) {
    (last, p);
    return first;
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt, class BinaryPredicate>
bit_iterator<ForwardIt> unique(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    BinaryPredicate p) {
    (policy, last, p);
    return first;
}


// ========================================================================== //
} // namespace bit

#endif // _UNIQUE_HPP_INCLUDED
// ========================================================================== //
