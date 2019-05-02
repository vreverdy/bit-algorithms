// ================================= MERGE ================================= //
// Project: The Experimental Bit Algorithms Library
// Name: merge.hpp
// Description: bit_iterator overloads for std::merge
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _MERGE_HPP_INCLUDED
#define _MERGE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class InputIt1, class InputIt2, class OutputIt>
constexpr bit_iterator<OutputIt> merge(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2, bit_iterator<OutputIt> d_first) {
    (first1, last1, first2, last2);
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2, 
    class ForwardIt3> bit_iterator<ForwardIt3> merge(ExecutionPolicy&& policy, 
    bit_iterator<ForwardIt1> first1, bit_iterator<ForwardIt1> last1,
    bit_iterator<ForwardIt2> first2, bit_iterator<ForwardIt2> last2,
    bit_iterator<ForwardIt3> first3) {
    (policy, first1, last1, first2, last2);
    return first3;
}

// TODO
template <class InputIt1, class InputIt2, class OutputIt, class Compare>
constexpr bit_iterator<OutputIt> merge(bit_iterator<InputIt1> first1,
    bit_iterator<InputIt1> last1, bit_iterator<InputIt2> first2,
    bit_iterator<InputIt2> last2, bit_iterator<OutputIt> d_first,
    Compare comp) {
    (first1, last1, first2, last2, comp);
    return d_first;
}

// TODO
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
    class ForwardIt3, class Compare> bit_iterator<ForwardIt3> merge(
    ExecutionPolicy&& policy, bit_iterator<ForwardIt1> first1,
    bit_iterator<ForwardIt1> last1, bit_iterator<ForwardIt2> first2,
    bit_iterator<ForwardIt2> last2, bit_iterator<ForwardIt3> d_first,
    Compare comp) {
    (policy, first1, last1, first2, last2, comp);
    return d_first;
}
// ========================================================================== //
} // namespace bit

#endif // _MERGE_HPP_INCLUDED
// ========================================================================== //
