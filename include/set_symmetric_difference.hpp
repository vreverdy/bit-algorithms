// ======================== SET SYMMETRIC DIFFERENCE ======================== //
// Project: The Experimental Bit Algorithms Library
// Name: set_symmetric_difference.hpp
// Description: bit_iterator overloads for std::set_symmetric_difference
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
#define _SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class InputIt1, class InputIt2, class OutputIt>
constexpr bit_iterator<OutputIt> set_symmetric_distance(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2, bit_iterator<OutputIt> d_first) {
    (first1, last1, first2, last2);
    return d_first;
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class ForwardIt3> bit_iterator<ForwardIt3> set_symmetric_distance(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2, bit_iterator<ForwardIt3> d_first) {
    (policy, first1, last1, first2, last2);
    return d_first;
}

// Status: on hold
template <class InputIt1, class InputIt2, class OutputIt, class Compare>
constexpr bit_iterator<OutputIt> set_symmetric_distance(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2, OutputIt d_first, Compare comp) {
    (first1, last1, first2, last2, comp);
    return d_first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class ForwardIt3, class Compare> bit_iterator<ForwardIt3> set_symmetric_distance(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2, bit_iterator<ForwardIt3> d_first,
    Compare comp) {
    (policy, first1, last1, first2, last2, comp);
    return d_first;
}

// ========================================================================== //
} // namespace bit

#endif // _SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
// ========================================================================== //
