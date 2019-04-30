// =============================== ACCUMULATE =============================== //
// Project: The Experimental Bit Algorithms Library
// Name: accumulate.hpp
// Description: bit_iterator overloads for std::accumulate
// Creator: Vincent Reverdy
// Contributor(s): 
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

// TODO
template <class InputIt, class T>
T accumulate(bit_iterator<InputIt> first, bit_iterator<InputIt> last, T init) {
    (first, last);
    return init;
}

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
