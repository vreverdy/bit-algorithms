// ============================== SWAP RANGES ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: swap_ranges.hpp
// Description: bit_iterator overloads for std::swap_ranges
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SWAP_RANGES_HPP_INCLUDED
#define _SWAP_RANGES_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //


// Status: to do
template <class ForwardIt1, class ForwardIt2>
constexpr bit_iterator<ForwardIt2> swap_ranges(bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2) {
    (first1, last1); 
    return first2;
} 

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2>
bit_iterator<ForwardIt2> swap_ranges(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2) {
    (policy, first1, last1);
    return first2;
}

// ========================================================================== //
} // namespace bit

#endif // _SWAP_RANGES_HPP_INCLUDED
// ========================================================================== //
