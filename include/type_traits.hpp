// ============================== TYPE TRAITS =============================== //
// Project:         The Experimental Bit Algorithms Library
// Name:            type_traits.hpp
// Description:     Type traits for bits
// Creator:         Vincent Reverdy
// Contributor(s):  Vincent Reverdy [2019]
// License:         BSD 3-Clause License
// ========================================================================== //
#ifndef _TYPE_TRAITS_HPP_INCLUDED
#define _TYPE_TRAITS_HPP_INCLUDED
// ========================================================================== //



// ================================ PREAMBLE ================================ //
// C++ standard library
// Project sources
#include "bit_algorithm_details.hpp"
// Third-party libraries
// Miscellaneous
namespace bit {
// ========================================================================== //



/* *********************************** BIT ********************************** */
// Bit structure definition
struct bit
{
};
/* ************************************************************************** */



/* ********************************* IS BIT ********************************* */
// Is bit structure definition
template <class T>
struct is_bit
: std::false_type
{
};

// Is bit structure specialization: bit
template <>
struct is_bit<::bit::bit>
: std::true_type
{
};

// Is bit structure specialization: bit value
template <>
struct is_bit<bit_value>
: std::true_type
{
};

// Is bit structure specialization: bit reference
template <class WordType>
struct is_bit<bit_reference<WordType>>
: std::true_type
{
};

// Is bit value template definition
template <class T>
inline constexpr bool is_bit_v = is_bit<T>::value;
/* ************************************************************************** */



// ========================================================================== //
} // namespace bit
#endif // _TYPE_TRAITS_HPP_INCLUDED
// ========================================================================== //

