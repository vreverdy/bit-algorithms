// =============================== ITER SWAP =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: iter_swap.hpp
// Description: bit_iterator overloads for std::iter_swap
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ITER_SWAP_HPP_INCLUDED
#define _ITER_SWAP_HPP_INCLUDED
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
constexpr void iter_swap(bit_iterator<ForwardIt1> a, bit_iterator<ForwardIt2> b) {
    (a, b);
}

// ========================================================================== //
} // namespace bit

#endif // _ITER_SWAP_HPP_INCLUDED
// ========================================================================== //
