// ============================== ROTATE COPY ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: rotate_copy.hpp
// Description: bit_iterator overloads for std::rotate_copy
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ROTATE_COPY_HPP_INCLUDED
#define _ROTATE_COPY_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt, class OutputIt>
constexpr bit_iterator<OutputIt> rotate_copy(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> n_first, bit_iterator<ForwardIt> last,
    bit_iterator<OutputIt> d_first) {
    (first, n_first, last);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> rotate_copy(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> n_first,
    bit_iterator<ForwardIt1> last, bit_iterator<ForwardIt2> d_first) {
    (policy, first, n_first, last);
    return d_first; 
}


// ========================================================================== //
} // namespace bit

#endif // _ROTATE_COPY_HPP_INCLUDED
// ========================================================================== //
