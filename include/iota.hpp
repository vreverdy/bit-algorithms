// ================================== IOTA ================================== //
// Project: The Experimental Bit Algorithms Library
// Name: iota.hpp
// Description: bit_iterator overloads for std::iota
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _IOTA_HPP_INCLUDED
#define _IOTA_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt, class T>
void iota(bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last, T value) {
    (first, last, value);
}

// ========================================================================== //
} // namespace bit

#endif // _IOTA_HPP_INCLUDED
// ========================================================================== //
