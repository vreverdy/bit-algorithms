// =============================== ACCUMULATE =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: accumulate.hpp
// Description: bit_iterator overloads for std::accumulate
// Creator: Vincent Reverdy
// Contributor(s): Collin Gress [2019] 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ACCUMULATE_HPP_INCLUDED
#define _ACCUMULATE_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {

/* [Will not implement] 
 * After some discussion, we think the following method should be left unimplemented.
 * This is due to the fact that normal numeric types are not exactly comparable to 
 * bit values. It doesn't really make sense to allow the addition of type T
 * and bit::bit_value. If a user wants to use accumulate for bit iterators, 
 * they should use the other overload of accumulate which allows them to pass a
 * binary operation which is capable of doing arithmetic between bit::bit_value and T.
 * Alternatively, they can use bit::count (when accumulating via addition)
 
template <class InputIt, class T>
T accumulate(bit_iterator<InputIt> first, bit_iterator<InputIt> last, T init) {
    return bit::count(first, last, bit1) + init; 
}

*/

// TODO
template <class InputIt, class T, class BinaryOperation>
T accumulate(bit_iterator<InputIt> first, bit_iterator<InputIt> last, T init,
    BinaryOperation op) {
    (first, last, op);
    return init;
}

// ========================================================================== //
} // namespace bit

#endif // _ACCUMULATE_HPP_INCLUDED
// ========================================================================== //
