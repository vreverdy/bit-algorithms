// ================================ DESTROY ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: destroy.hpp
// Description: bit_iterator overloads for std::destroy
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _DESTROY_HPP_INCLUDED
#define _DESTROY_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

// TODO
template <class ForwardIt>
void destroy(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (first, last);
}

// TODO
template <class ExecutionPolicy, class ForwardIt>
void destroy(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (policy, first, last);
}

// ========================================================================== //
} // namespace bit

#endif // _DESTROY_HPP_INCLUDED
// ========================================================================== //
