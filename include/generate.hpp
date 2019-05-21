// ================================ GENERATE ================================ //
// Project: The Experimental Bit Algorithms Library
// Name: generate.hpp
// Description: bit_iterator overloads for std::generate
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _GENERATE_HPP_INCLUDED
#define _GENERATE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: on hold
template <class ForwardIt, class Generator>
constexpr void generate(bit_iterator<ForwardIt> first, 
    bit_iterator<ForwardIt> last, Generator g) {
    (first, last, g);
}

// Status: on hold 
template <class ExecutionPolicy, class ForwardIt, class Generator>
void generate(ExecutionPolicy&& policy, bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, Generator g) {
    (policy, first, last, g);
}


// ========================================================================== //
} // namespace bit

#endif // _GENERATE_HPP_INCLUDED
// ========================================================================== //
