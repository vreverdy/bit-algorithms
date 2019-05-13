// ============================== SHIFT RIGHT ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: shift_right.hpp
// Description: bit_iterator overloads for std::shift_right
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SHIFT_RIGHT_HPP_INCLUDED
#define _SHIFT_RIGHT_HPP_INCLUDED
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
constexpr bit_iterator<ForwardIt> shift_right(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, typename bit_iterator<ForwardIt>::difference_type n) {
    (last, n);
    return first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> shift_right(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    typename bit_iterator<ForwardIt>::difference_type n) {
    (policy, last, n); 
    return first;
}


// ========================================================================== //
} // namespace bit

#endif // _SHIFT_RIGHT_HPP_INCLUDED
// ========================================================================== //
