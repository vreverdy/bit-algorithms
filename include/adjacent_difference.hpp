// ========================== ADJACENT DIFFERENCE ========================== //
// Project: The Experimental Bit Algorithms Library
// Name: adjacent_difference.hpp
// Description: bit_iterator overloads for std::adjacent_difference
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ADJACENT_DIFFERENCE_HPP_INCLUDED
#define _ADJACENT_DIFFERENCE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt, class OutputIt>
constexpr OutputIt adjacent_difference(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, OutputIt d_first) {
    (first, last);
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> adjacent_difference(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first, bit_iterator<ForwardIt1> last,
    bit_iterator<ForwardIt2> d_first) {
    (policy, first, last);
    return d_first; 
}

// ========================================================================== //
} // namespace bit

#endif // _ADJACENT_DIFFERENCE_HPP_INCLUDED
// ========================================================================== //
