// =============================== FUNCTIONAL =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            concepts.hpp
// Description:     Bit related concepts
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _CONCEPTS_HPP_INCLUDED
#define _CONCEPTS_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
// Project sources
#include "bit_algorithm_details.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



/* ********************************** BIT *********************************** */
// Bit concept definition
template <class T>
concept bool Bit = is_bit_v<T>;
/* ************************************************************************** */



// ========================================================================== //
// namespace bit
#endif // _CONCEPTS_HPP_INCLUDED
// ========================================================================== //
